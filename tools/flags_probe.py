#!/usr/bin/env python3
"""flags_probe.py: find the compile mode and assembler a near-miss draft wants, and record them.

Every tool that compiles a single function (localdecomp, tools/try_func.py,
tools/try_in_context.py, tools/permuter_setup.py) takes its flags from
flags_for(): the target's localdecomp_flags.txt first, then text_parts.txt.
A near miss that needs a single-function override (S/N mode, @ps2as/@newas)
therefore has to be listed in localdecomp_flags.txt, or every tool measures
it with the file's default flags and reports a much worse score.

This script compiles DRAFT in context with each mode (S, N) and assembler
(default, ps2as, newas), scores each object with the aligned scorer
(tools/permuter_scorer.py), prints the table and, with --write, records the
best combination in localdecomp_flags.txt (only when it beats what the table
already gives).

    python3 tools/flags_probe.py scratch/func_003B9730.c func_003B9730
    python3 tools/flags_probe.py scratch/func_003B9730.c func_003B9730 --write
    python3 tools/flags_probe.py --batch drafts.tsv --write      # lines: DRAFT FUNC
"""
import argparse, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.chdir(ROOT)
import targets  # noqa: E402
import check as tf  # noqa: E402
import permuter_scorer as ps  # noqa: E402

MODES = ("S", "N")
ASMS = ("default", "ps2as", "newas")


class _Args:
    def __init__(self, a):
        self.toolchain = a.toolchain
        self.runner = a.runner
        self.no_context = False
        self.early_extern_sizes = {}
        self.ee29 = None


def file_flags(addr):
    """Flags from text_parts.txt alone (the range default, ignoring localdecomp_flags.txt)."""
    t = targets.get()
    best = None
    for start, fl in tf.read_table(t.path("parts")):
        if addr >= start and (best is None or start >= best[0]):
            best = (start, fl)
    return best[1] if best else ["-O2", "-G8"]


def measure(draft, func, flags, cargs):
    o = tf.compile_c(os.path.abspath(draft), flags, cargs, name=func)
    if not o:
        return None
    try:
        return ps.score(o, func)
    except Exception:
        return None


def probe(draft, func, cargs, quiet=False):
    addr = int(func[5:13], 16)
    base = file_flags(addr)
    current = tf.flags_for(addr)
    rows = []
    cur = measure(draft, func, current, cargs)
    for m in MODES:
        for a in ASMS:
            fl = tf.apply_overrides(base, m, a)
            rows.append((measure(draft, func, fl, cargs), m, a, fl))
    if not quiet:
        print(f"{func}: current flags ({' '.join(current)}): {cur}")
        for n, m, a, fl in rows:
            print(f"  {m} {a:8s} {('-' if n is None else n):>5}")
    ok = [r for r in rows if r[0] is not None]
    best = min(ok, key=lambda r: (r[0], r[3] != base)) if ok else None
    return cur, best, base


def write_flags(func, flags, base):
    t = targets.get()
    path = t.path("localdecomp_flags")
    lines = open(path, newline="").read().replace("\r\n", "\n").split("\n") if os.path.exists(path) else []
    crlf = os.path.exists(path) and b"\r\n" in open(path, "rb").read()
    lines = [l for l in lines if not l.startswith(func + " ") and l != func]
    if flags != base:
        while lines and lines[-1] == "":
            lines.pop()
        lines.append(f"{func} {' '.join(flags)}")
        lines.append("")
    text = "\n".join(lines)
    open(path, "w", newline="").write(text.replace("\n", "\r\n") if crlf else text)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("draft", nargs="?")
    ap.add_argument("func", nargs="?")
    ap.add_argument("--batch", help="file with lines: DRAFT FUNC")
    ap.add_argument("--write", action="store_true", help="record the best flags in localdecomp_flags.txt")
    ap.add_argument("--toolchain", default=tf.DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    targets.from_argv()   # --target boot_elf / i5bootn
    a = ap.parse_args()
    cargs = _Args(a)
    jobs = []
    if a.batch:
        for l in open(a.batch):
            p = l.split()
            if len(p) >= 2 and not l.startswith("#"):
                jobs.append((p[0], p[1]))
    elif a.draft and a.func:
        jobs.append((a.draft, a.func))
    else:
        ap.error("give DRAFT FUNC or --batch")
    for draft, func in jobs:
        cur, best, base = probe(draft, func, cargs)
        if best is None:
            print(f"{func}: does not compile in any mode")
            continue
        n, m, asm, fl = best
        print(f"{func}: best {m} {asm} = {n} (current {cur})")
        if a.write and (cur is None or n < cur):
            write_flags(func, fl, base)
            print(f"{func}: wrote {' '.join(fl)}")


if __name__ == "__main__":
    main()
