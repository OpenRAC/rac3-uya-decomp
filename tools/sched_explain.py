#!/usr/bin/env python3
"""sched_explain.py: show why gcc's instruction scheduler put one insn before another.

Most register and order near misses come down to one choice in sched1 (before
register allocation) or sched2 (after): two insns were ready in the same cycle
and gcc 2.95's haifa scheduler picked the other one. It ranks ready insns by,
in order (rank_for_schedule in haifa-sched.c):

  1. priority     longest latency path from the insn to the end of the block
  2. reg weight   (sched1 only) registers the insn sets minus REG_DEAD/REG_UNUSED
                  notes on it; lower wins (it frees registers)
  3. class        relation to the insn scheduled last: independent (or a
                  1-cycle data dependence) beats an anti/output dependence,
                  which beats a multi-cycle data dependence
  4. dependents   more insns depending on it wins
  5. source order the earlier insn (lower LUID) wins

and issues two per cycle (one memory op). This tool compiles the function in
its full-build context with SN cc1's scheduler dumps (-fsched-verbose-5),
replays each cycle and prints every ready list best-first with those five keys,
so the deciding key is visible.

    python3 tools/sched_explain.py scratch/f.c func_0038E930            # every block, sched1
    python3 tools/sched_explain.py scratch/f.c func_0038E930 --pass 2   # sched2 (after reload)
    python3 tools/sched_explain.py scratch/f.c func_0038E930 --block 3
    python3 tools/sched_explain.py scratch/f.c func_0038E930 --why 4 15 # first key that separates them
    python3 tools/sched_explain.py scratch/f.c func_0038E930 --keep scratch/dumps   # keep the dumps

Insns are named by their RTL uid with the scheduler's short text
(`r126=[r119+0x10]`); uids are the same in both passes. Flags come from
flags_for() (localdecomp_flags.txt, then text_parts.txt); --mode/--as override.
"""
import argparse, os, re, shutil, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.chdir(ROOT)
import targets  # noqa: E402
import check as tf  # noqa: E402

CLASS_NAMES = {3: "indep", 2: "anti/out", 1: "data>1"}


def compile_dumps(src_path, func, flags, toolchain, runner, keep):
    src = open(src_path).read()
    ctx, src = tf.text_c_context(func, src)
    src = ctx + src
    if "common.h" not in src:
        src = '#include "common.h"\n' + src
    d = keep or tempfile.mkdtemp(prefix="sched_")
    os.makedirs(d, exist_ok=True)
    c = os.path.join(d, "x.c")
    open(c, "w").write(src)
    gcc = os.path.join(toolchain, "bin", "ee-gcc2953.exe")
    cmd = ([runner] if runner else []) + [gcc, "-S", "-I", os.path.join(ROOT, "include"), "-I", ROOT] \
        + tf.expand(flags, toolchain) + ["-dN", "-dS", "-dR", "-fsched-verbose-5", "-o", "x.s", "x.c"]
    p = subprocess.run(cmd, cwd=d, capture_output=True, text=True)
    if p.returncode:
        sys.exit("compile failed:\n" + p.stdout + p.stderr)
    return d


def rtl_insns(text):
    """uid -> RTL text of each insn in a dump."""
    out = {}
    for m in re.finditer(r"(?ms)^\((?:insn|call_insn|jump_insn) (\d+) .*?(?=^\(|\Z)", text):
        out[int(m.group(1))] = m.group(0)
    return out


def reg_weight(rtl):
    """haifa's find_insn_reg_weight: +1 per top-level SET/CLOBBER, -1 per REG_DEAD/REG_UNUSED note."""
    body = re.sub(r"^\(\w+ \d+ \d+ \d+ ", "", rtl.strip())
    w = 0
    if body.startswith("(set") or body.startswith("(clobber"):
        w += 1
    elif body.startswith("(parallel"):
        depth, i = 0, body.index("[")
        j = i + 1
        while j < len(body):
            ch = body[j]
            if ch == "(":
                if depth == 0 and (body.startswith("(set", j) or body.startswith("(clobber", j)):
                    w += 1
                depth += 1
            elif ch == ")":
                depth -= 1
            elif ch == "]" and depth == 0:
                break
            j += 1
    w -= len(re.findall(r"expr_list:REG_(?:DEAD|UNUSED)", rtl))
    return w


def back_deps(rtl):
    """{pred uid: kind} from an insn's LOG_LINKS as printed after scheduling."""
    out = {}
    for m in re.finditer(r"insn_list(?::(REG_DEP_\w+))? (\d+)", rtl):
        out[int(m.group(2))] = m.group(1) or "data"
    return out


def parse_blocks(text):
    """Blocks in schedule order: dependency table, cycle log, insn texts."""
    blocks = []
    for m in re.finditer(r"(?ms)^;;   -- basic block (\d+) from (\d+) to (\d+) -- (before|after) reload\n(.*?)(?=^;;   -- basic block |\Z)", text):
        bnum, body = int(m.group(1)), m.group(5)
        table = {}
        order = []
        for t in re.finditer(r"(?m)^;;   [ +]\s*(\d+)\s+(-?\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(-?\d+) -\s*(-?\d+)\s+(\S*)\t: ([\d ]*)$", body):
            uid = int(t.group(1))
            table[uid] = dict(prio=int(t.group(5)), cost=int(t.group(6)), unit=t.group(9),
                              deps=[int(x) for x in t.group(10).split()])
            order.append(uid)
        cycles = []
        cur = None
        for line in body.split("\n"):
            r = re.match(r";;\tReady list \(t =\s*(\d+)\):\s*(.*)$", line)
            if r:
                cur = dict(t=int(r.group(1)), ready=[int(x) for x in r.group(2).split()], issued=[])
                cycles.append(cur)
                continue
            s = re.match(r";;\t\t--> scheduling insn <<<(\d+)>>>", line)
            if s and cur is not None:
                cur["issued"].append(int(s.group(1)))
        texts = {}
        vis = re.search(r"(?ms)^;;   =+ scheduling visualization for block \d+\s*\n(.*?)^;;   total time", body)
        if vis:
            for line in vis.group(1).split("\n"):
                if not re.match(r";;\s+\d+\s", line):
                    continue
                k = 15
                while k < len(line):
                    cell = line[k:k + 30]
                    c = re.match(r"(\d+)\s+(.*\S)", cell)
                    if c:
                        texts[int(c.group(1))] = c.group(2).strip()
                    k += 35
        blocks.append(dict(block=bnum, table=table, order=order, cycles=cycles, texts=texts))
    return blocks


def keys(uid, blk, weights, deps_kind, last, use_weight):
    """rank_for_schedule's keys, larger tuple = scheduled first."""
    tb = blk["table"]
    prio = tb[uid]["prio"]
    w = weights.get(uid, 0) if use_weight else 0
    if last is None:
        cls = None
    else:
        kind = deps_kind.get(uid, {}).get(last)
        if kind is None:
            cls = 3
        elif kind == "data":
            cls = 3 if tb.get(last, {}).get("cost", 1) == 1 else 1
        else:
            cls = 2   # anti/output: cost 0 on MIPS (mips_adjust_cost)
    ndeps = len(tb[uid]["deps"])
    luid = blk["order"].index(uid) if uid in blk["order"] else 0
    return dict(prio=prio, weight=w, cls=cls, deps=ndeps, luid=luid,
                sort=(prio, -w, cls or 0, ndeps, -luid))


def why(a, b, ka, kb, use_weight):
    steps = [("priority", "prio", 1)] + ([("reg weight", "weight", -1)] if use_weight else []) + \
        [("class vs last insn", "cls", 1), ("dependents", "deps", 1), ("source order (luid)", "luid", -1)]
    for name, k, sign in steps:
        va, vb = ka[k], kb[k]
        if va is None or vb is None or va == vb:
            continue
        win = a if (va - vb) * sign > 0 else b
        return f"{name}: {a}={va} vs {b}={vb} -> {win} first"
    return "all keys equal"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("func", nargs="?")
    ap.add_argument("--pass", dest="pas", type=int, choices=[1, 2], default=1)
    ap.add_argument("--block", type=int, action="append", help="only this basic block (repeatable)")
    ap.add_argument("--why", nargs=2, type=int, metavar=("UID_A", "UID_B"))
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--keep", help="write the dumps to this folder")
    ap.add_argument("--toolchain", default=tf.DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    targets.from_argv()
    a = ap.parse_args()
    src = open(a.file).read()
    func = a.func or next(iter(dict.fromkeys(tf.FUNC_DEF_RE.findall(src))), None)
    flags = tf.apply_overrides(tf.flags_for(int(func[5:13], 16)), a.mode, a.asm)
    d = compile_dumps(a.file, func, flags, a.toolchain, a.runner, a.keep)
    dump = open(os.path.join(d, "x.c.sched" if a.pas == 1 else "x.c.sched2")).read()
    # only this function's part of the dump
    fm = re.search(r"(?ms)^;; Function %s\n(.*?)(?=^;; Function |\Z)" % re.escape(func), dump)
    dump = fm.group(1) if fm else dump
    pre = open(os.path.join(d, "x.c.regmove")).read()
    pm = re.search(r"(?ms)^;; Function %s\n(.*?)(?=^;; Function |\Z)" % re.escape(func), pre)
    pre = pm.group(1) if pm else pre
    use_weight = a.pas == 1
    weights = {u: reg_weight(r) for u, r in rtl_insns(pre).items()}
    deps_kind = {u: back_deps(r) for u, r in rtl_insns(dump).items()}
    blocks = parse_blocks(dump)
    print(f"{func}  flags: {' '.join(flags)}  pass: sched{a.pas}")
    print("keys: prio" + (" / weight (lower first)" if use_weight else "") + " / class vs last / dependents / luid (lower first)\n")
    last_global = None
    for blk in blocks:
        if a.block and blk["block"] not in a.block:
            continue
        uids = blk["order"]
        if a.why and not (a.why[0] in uids and a.why[1] in uids):
            continue
        print(f"== block {blk['block']} ({len(uids)} insns)")
        last = None
        for cyc in blk["cycles"]:
            ready = list(reversed(cyc["ready"]))   # dump lists worst..best
            if not ready:
                continue
            print(f"  t={cyc['t']:<3} issued: " + ", ".join(f"{u} {blk['texts'].get(u, '')}" for u in cyc["issued"]))
            if a.why:
                if a.why[0] in ready and a.why[1] in ready:
                    ka = keys(a.why[0], blk, weights, deps_kind, last, use_weight)
                    kb = keys(a.why[1], blk, weights, deps_kind, last, use_weight)
                    print(f"         {why(a.why[0], a.why[1], ka, kb, use_weight)}")
            elif len(ready) > 1:
                for u in ready:
                    k = keys(u, blk, weights, deps_kind, last, use_weight)
                    mark = "*" if u in cyc["issued"] else " "
                    cls = CLASS_NAMES.get(k["cls"], "-")
                    wtxt = f" w={k['weight']:+d}" if use_weight else ""
                    print(f"       {mark}{u:5d} p={k['prio']:<3}{wtxt} {cls:8s} deps={k['deps']:<2} luid={k['luid']:<3} {blk['texts'].get(u, '')}")
            if cyc["issued"]:
                last = cyc["issued"][-1]
        print()
    if a.keep:
        print(f"dumps in {d}")
    else:
        shutil.rmtree(d, ignore_errors=True)


if __name__ == "__main__":
    main()
