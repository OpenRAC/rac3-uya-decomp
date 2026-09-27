#!/usr/bin/env python3
"""try_in_context.py: test a function exactly as the full build compiles it.

try_func.py compiles your file on its own. The real build compiles the
function inside its text_parts.txt range, after every declaration text.c
makes before it. That context can change gcc's output (instruction
scheduling around $gp, see the wiki's known open problems), so a function can
MATCH alone and still break the build. This script puts FILE.c into a copy of
src/text.c in place of the function's INCLUDE_ASM (or its current block),
builds only that function's part the way tools/build_text.py does, and diffs
the function against retail.

    python tools/try_in_context.py scratch/func_003AED08.c
    python tools/try_in_context.py scratch/f.c func_003AED08 --mode N --as ps2as

Same toolchain options as try_func.py (--toolchain / UYA_TOOLCHAIN,
--runner / UYA_RUNNER). --mode/--as override the range's flags for this test
only; if they are needed, add a single-function override to text_parts.txt.
Nothing in the repo is modified.
"""
import argparse, os, re, subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import build_text as bt
import try_func as tf

CFLAGS = ["-I", "include", "-I", ".", "-Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi",
          "-DINCLUDE_ASM_USE_MACRO_INC=1"]


def substitute(text, name, body):
    block = f"/* localdecomp:start {name} */\n{body.strip()}\n/* localdecomp:end {name} */\n"
    pat = re.compile(r'/\* localdecomp:start %s \*/.*?/\* localdecomp:end %s \*/\n?' % (name, name), re.S)
    if pat.search(text):
        return pat.sub(lambda m: block, text, count=1)
    pat = re.compile(r'^INCLUDE_ASM\("[^"]*",\s*%s\);[^\n]*\n(?:INCLUDE_RODATA\([^)]*\);[^\n]*\n)*' % name, re.M)
    if not pat.search(text):
        sys.exit(f"{name}: neither INCLUDE_ASM nor a localdecomp block found in src/text.c")
    return pat.sub(lambda m: block, text, count=1)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("name", nargs="?")
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--toolchain", default=tf.DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--retail", default=os.path.join(ROOT, "frontbin.elf"))
    args = ap.parse_args()

    body = open(args.file).read()
    name = args.name or (tf.FUNC_DEF_RE.findall(body) or [None])[0]
    if not name:
        sys.exit("no func_XXXXXXXX definition found; pass the function name")
    addr = int(name[5:], 16)

    text = substitute(open(os.path.join(ROOT, "src", "text.c"), errors="replace").read(), name, body)
    parts = bt.read_parts(os.path.join(ROOT, "tools", "text_parts.txt"))
    pi = bt.part_index(parts, addr)

    chunks, assigned, pending = bt.split_chunks(text), [], []
    for a, line, b in chunks:
        if a is None:
            pending.append((line, b)); continue
        idx = bt.part_index(parts, a)
        assigned += [(idx, pl, pb) for pl, pb in pending] + [(idx, line, b)]
        pending = []
    out = []
    for i, line, b in assigned:
        if i < pi:
            d = bt.declarations_only(b)
            if d:
                out.append(d + "\n")
        elif i == pi:
            out.append(f'#line {line} "src/text.c"\n{b}')

    flags = tf.apply_overrides(parts[pi][1], args.mode, args.asm)
    print("part 0x%08X flags: %s" % (parts[pi][0], " ".join(flags)))
    cflags = list(CFLAGS)
    if "@ps2as" in flags:
        cflags = [f for f in cflags if not f.startswith("-Wa,")]
    tmp = tempfile.mkdtemp(prefix="ctx_")
    cpath, opath = os.path.join(tmp, "part.c"), os.path.join(tmp, "part.o")
    open(cpath, "w").write("".join(out))
    gcc = os.path.join(args.toolchain, "bin", "ee-gcc2953.exe")
    cmd = ([args.runner] if args.runner else []) + [gcc, "-c"] + cflags + tf.expand(flags, args.toolchain) + ["-o", opath, cpath]
    p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if p.returncode or not os.path.exists(opath):
        errs = [l for l in (p.stdout + p.stderr).splitlines() if "error" in l or ": " in l and "warning" not in l]
        sys.exit("COMPILE ERROR\n" + "\n".join(errs[-15:]))
    tf.diff_object(opath, [name], tf.Retail(args.retail), args.quiet)


if __name__ == "__main__":
    main()
