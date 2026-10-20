#!/usr/bin/env python3
"""fence_search.py: try empty-asm fences, barriers and small statement edits on a near miss.

Two inline asm forms fix scheduling and register near misses that no C rewrite
reaches (see docs/permuter.md, "Empty asm passes"):

  __asm__("" : "+r"(x));      register fence: x keeps its own pseudo (combine can't
                              fold it into a later insn) and its dependency chain
                              gets one link longer, which changes sched1's priority
                              order and so local-alloc's choices. "+f" for floats.
  __asm__ __volatile__("");   barrier: sched1/sched2 move nothing across it, and
                              reorg won't fill a delay slot across it.

The permuter has random passes for both (tools/decomp-permuter-asm-passes.patch).
This script is the exhaustive, line-based version: for each statement line of
the function it tries a fence after every simple assignment, a barrier before
every statement, a do { } while (0) wrap and a swap with the next statement.
Then it tries every pair of the best single edits, because fixes often need two
(func_0038E930 needed a fence and a barrier). Scores are aligned instruction
diffs (tools/permuter_scorer.py) with the function's flags from flags_for().

    python3 tools/fence_search.py scratch/func_0038E930.c
    python3 tools/fence_search.py scratch/f.c func_0038E930 -j4 --out scratch/fs --mode S --as ps2as

Writes the best variants to --out (default scratch/fence_search/<func>/) and
prints them as they are found. Variants that use inline asm need the
`(asm)` commit convention (CONTRIBUTING.md).
"""
import argparse, itertools, os, re, sys, tempfile
import concurrent.futures as cf

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.chdir(ROOT)
import targets  # noqa: E402
import check as tf  # noqa: E402
import permuter_scorer as ps  # noqa: E402

DECL_RE = re.compile(r"^(const\s+|volatile\s+|static\s+|register\s+|unsigned\s+|signed\s+)*"
                     r"(s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|long|int|short|char|void|float|double|"
                     r"struct\s+\w+|union\s+\w+|[A-Z]\w*)\b[\s*]*\w+\s*(\[[^\]]*\]\s*)*(=|;|,)")
ASSIGN_RE = re.compile(r"^(\s*)([A-Za-z_]\w*)\s*(=|\+=|-=|\|=|&=|\^=|<<=|>>=|\*=)\s*[^=].*;\s*$")
FLOAT_TYPES = ("f32", "f64", "float", "double")


class CArgs:
    def __init__(self, a):
        self.toolchain, self.runner = a.toolchain, a.runner
        self.no_context, self.early_extern_sizes, self.ee29 = False, {}, a.ee29


def func_range(lines, func):
    start = next(i for i, l in enumerate(lines)
                 if re.match(r"^[A-Za-z].*\b%s\s*\(" % func, l) and not l.rstrip().endswith(";"))
    end = next(i for i in range(start + 1, len(lines)) if lines[i].startswith("}"))
    return start, end


def var_types(lines, start, end):
    """name -> 'f' or 'r' for locals and parameters declared with a simple type."""
    out = {}
    text = " ".join(lines[start:end])
    for m in re.finditer(r"\b(s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|long|int|short|char|float|double|unsigned)"
                         r"\b([^;(){}]*?)(?=[;)])", text):
        kind = "f" if m.group(1) in FLOAT_TYPES else "r"
        for part in m.group(2).split(","):
            n = re.match(r"\s*\**\s*([A-Za-z_]\w*)", part)
            if n and "[" not in part:
                out[n.group(1)] = kind if "*" not in part else "r"
    for m in re.finditer(r"\b([A-Z]\w*)\s*\*+\s*([A-Za-z_]\w*)", text):   # Struct *p
        out[m.group(2)] = "r"
    return out


def edits(lines, start, end, types, kinds):
    """(tag, line index, kind, payload) single edits; applied by apply()."""
    res = []
    for i in range(start + 1, end):
        l = lines[i]
        st = l.strip()
        ind = re.match(r"^(\s*)", l).group(1)
        is_decl = bool(DECL_RE.match(st))
        nxt = lines[i + 1].strip() if i + 1 < end else ""
        next_is_decl = bool(DECL_RE.match(nxt))
        m = ASSIGN_RE.match(l)
        if "fence" in kinds and not next_is_decl:
            name = m.group(2) if m else None
            if not name and is_decl and "=" in st:
                n = re.match(r".*?\**\s*([A-Za-z_]\w*)\s*=", st)
                name = n.group(1) if n else None
            if name and name in types:
                res.append(("fence_%d_%s" % (i, name), i, "after",
                            '%s__asm__("" : "+%s"(%s));' % (ind, types[name], name)))
        if "barrier" in kinds and not is_decl and st and not st.startswith(("case", "default", "else", "}", "{")):
            if not lines[i - 1].strip().startswith(("case", "default")) and i > start + 1:
                res.append(("barrier_%d" % i, i, "before", "%s__asm__ __volatile__(\"\");" % ind))
        simple = (st.endswith(";") and not is_decl and st.count("{") == st.count("}")
                  and not st.startswith(("return", "break", "continue", "__asm__", "case", "default", "goto")))
        if "dowhile" in kinds and simple:
            res.append(("dowhile_%d" % i, i, "replace", "%sdo { %s } while (0);" % (ind, st)))
        if "swap" in kinds and simple and i + 1 < end:
            st2 = lines[i + 1].strip()
            if (st2.endswith(";") and not DECL_RE.match(st2) and st2.count("{") == st2.count("}")
                    and not st2.startswith(("return", "break", "continue", "case", "goto"))):
                res.append(("swap_%d" % i, i, "swap", None))
    return res


def apply(lines, chosen):
    """Apply edits; line indices refer to the original lines."""
    L = [[l] for l in lines]
    for tag, i, how, text in chosen:
        if how == "after":
            L[i].append(text)
        elif how == "before":
            L[i].insert(0, text)
        elif how == "replace":
            L[i] = [x for x in L[i] if x != lines[i]] + [text]
        elif how == "swap":
            L[i], L[i + 1] = L[i + 1], L[i]
    return "\n".join(x for group in L for x in group)


def conflicts(e1, e2):
    hows = {e1[2], e2[2]}
    if e1[1] == e2[1] and ("replace" in hows or "swap" in hows or e1[2] == e2[2]):
        return True
    for a, b in ((e1, e2), (e2, e1)):
        if a[2] == "swap" and b[1] in (a[1], a[1] + 1):
            return True
    return False


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("func", nargs="?")
    ap.add_argument("-j", type=int, default=os.cpu_count() or 2)
    ap.add_argument("--out")
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--kinds", default="fence,barrier,dowhile,swap")
    ap.add_argument("--pairs", type=int, default=12, help="try all pairs among this many best single edits")
    ap.add_argument("--toolchain", default=tf.DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--ee29", default=None)
    targets.from_argv()
    a = ap.parse_args()
    src = open(a.file).read()
    func = a.func or next(iter(dict.fromkeys(tf.FUNC_DEF_RE.findall(src))), None)
    lines = src.split("\n")
    start, end = func_range(lines, func)
    flags = tf.apply_overrides(tf.flags_for(int(func[5:13], 16)), a.mode, a.asm)
    out = a.out or os.path.join(ROOT, "scratch", "fence_search", func)
    os.makedirs(out, exist_ok=True)
    cargs = CArgs(a)
    tmp = tempfile.mkdtemp(prefix="fence_")

    def score(text, tag):
        p = os.path.join(tmp, tag + ".c")
        open(p, "w").write(text)
        o = tf.compile_c(p, flags, cargs, name=func)
        if not o:
            return None
        try:
            return ps.score(o, func)
        except Exception:
            return None

    base = score(src, "base")
    print(f"{func}: flags {' '.join(flags)}; base {base}", flush=True)
    types = var_types(lines, start, end)
    singles = edits(lines, start, end, types, set(a.kinds.split(",")))
    print(f"{len(singles)} single edits", flush=True)
    results = []
    best = [base if base is not None else 10 ** 9]

    def run(chosen):
        tag = "+".join(c[0] for c in chosen)
        text = apply(lines, chosen)
        n = score(text, re.sub(r"\W", "_", tag)[:80])
        return n, tag, text

    def collect(jobs):
        with cf.ThreadPoolExecutor(a.j) as ex:
            for n, tag, text in ex.map(run, jobs):
                if n is None:
                    continue
                results.append((n, tag, text))
                if n < best[0]:
                    best[0] = n
                    print(f"  {n:4d}  {tag}", flush=True)
                    open(os.path.join(out, f"best_{n}_{re.sub(chr(92) + 'W', '_', tag)[:60]}.c"), "w").write(text)
                if n == 0:
                    return True
        return False

    done = collect([[e] for e in singles])
    if not done and a.pairs > 1:
        ranked = sorted((r for r in results), key=lambda r: r[0])
        keep_tags = []
        for n, tag, _ in ranked:
            if tag not in keep_tags:
                keep_tags.append(tag)
            if len(keep_tags) >= a.pairs:
                break
        top = [e for e in singles if e[0] in keep_tags]
        # also pair each top edit with every other single edit
        pairs = set()
        for e1 in top:
            for e2 in singles:
                if e1 is not e2 and not conflicts(e1, e2):
                    pairs.add(tuple(sorted((e1, e2), key=lambda e: e[0])))
        print(f"{len(pairs)} pairs", flush=True)
        collect([list(p) for p in sorted(pairs)])
    results.sort(key=lambda r: r[0])
    print("best:", ", ".join(f"{n} {tag}" for n, tag, _ in results[:5]))
    print(f"written to {out}")


if __name__ == "__main__":
    main()
