#!/usr/bin/env python3
"""try_in_context.py: test a function exactly as the full build compiles it.

try_func.py compiles your file on its own. The real build compiles the
function inside its source file (src/frontbin/), after the file's own
declarations and the earlier functions of the file. That context can change gcc's output (instruction
scheduling around $gp, see the wiki's known open problems), so a function can
MATCH alone and still break the build. This script puts FILE.c into a copy of
the function's source file in place of its INCLUDE_ASM (or its current
block), builds that file (or the slice holding the function, for a file with
mixed flags) the way tools/build_text.py does, and diffs the function
against retail. Then it compiles the rest of that file and every later file
that receives this block's declarations (split_text.py --refresh), which is
where a conflicting declaration shows up; try_func.py can't see that.

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
        sys.exit(f"{name}: neither INCLUDE_ASM nor a localdecomp block found in its source file")
    return pat.sub(lambda m: block, text, count=1)


def main():
    import targets
    t = targets.from_argv()   # --target boot_elf
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("name", nargs="?")
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--no-file-check", action="store_true",
                    help="skip compiling the rest of the file and the later files that get this block's declarations")
    ap.add_argument("--toolchain", default=tf.DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--retail", default=t.path("elf"))
    args = ap.parse_args()

    body = open(args.file).read()
    name = args.name or (tf.FUNC_DEF_RE.findall(body) or [None])[0]
    if not name:
        sys.exit("no func_XXXXXXXX definition found; pass the function name")
    addr = int(name[5:], 16)

    import srcfiles as sf
    import split_text
    files = sf.read_file_list()
    found = sf.find_function(name, files)
    rel = found[0] if found else sf.file_for_address(files, addr)
    text = substitute(sf.read_source(rel), name, body)
    # declarations from other files as `split_text.py --refresh` would set them
    prelude, _, chunks = sf.split_file(text)
    ext = split_text.external_declarations(split_text.earlier_statements(rel, files),
                                           split_text.file_needs(chunks))
    text = split_text.render(ext, chunks, prelude)
    prelude, _, chunks = sf.split_file(text)
    parts = bt.read_parts(__import__("targets").get().path("parts"))
    slices = bt.file_slices(chunks, parts)
    idx = next(i for i, (a, _, b) in enumerate(chunks) if sf.is_own_chunk(b, name))
    k = next(n for n, (_, ids) in enumerate(slices) if idx in ids)
    src = text if len(slices) == 1 else bt.slice_source(rel, prelude, chunks, slices[k][1])

    flags = tf.apply_overrides(slices[k][0], args.mode, args.asm)
    print("%s%s flags: %s" % (rel, "" if len(slices) == 1 else " (slice %d)" % k, " ".join(flags)))
    cflags = list(CFLAGS)
    if "@ps2as" in flags:
        cflags = [f for f in cflags if not f.startswith("-Wa,")]
    tmp = tempfile.mkdtemp(prefix="ctx_")
    cpath, spath, opath = (os.path.join(tmp, "file" + e) for e in (".c", ".s", ".o"))
    open(cpath, "w").write(src)
    gcc = os.path.join(args.toolchain, "bin", "ee-gcc2953.exe")
    base = ([args.runner] if args.runner else []) + [gcc]
    fl = cflags + tf.expand(flags, args.toolchain)
    p = subprocess.run(base + ["-S"] + fl + ["-o", spath, cpath], cwd=ROOT, capture_output=True, text=True)
    if not p.returncode:
        import asm_filter
        st = open(spath, newline="").read()
        open(spath, "w", newline="").write(asm_filter.filter_asm(st))
        p = subprocess.run(base + ["-c"] + fl + ["-o", opath, spath], cwd=ROOT, capture_output=True, text=True)
    if p.returncode or not os.path.exists(opath):
        errs = [l for l in (p.stdout + p.stderr).splitlines() if "error" in l or ": " in l and "warning" not in l]
        sys.exit("COMPILE ERROR\n" + "\n".join(errs[-15:]))
    tf.diff_object(opath, [name], tf.Retail(args.retail), args.quiet)
    if not args.no_file_check:
        check_files(rel, text, files, base, args)


def check_files(rel, text, files, gcc_cmd, args):
    """The diff above only compiles the function's own slice. The full build
    also compiles the file's other slices (later blocks see this block's
    declarations) and, after `split_text.py --refresh`, every later file that
    uses a name this block declares. A clash with any of those passes
    try_func.py and this diff, then stops the build; compile them all here."""
    import shutil
    import srcfiles as sf
    import split_text
    tmp = tempfile.mkdtemp(prefix="ctxtree_")
    try:
        for r, _ in files:
            dst = os.path.join(tmp, r)
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            shutil.copyfile(os.path.join(ROOT, r), dst)
        with open(os.path.join(tmp, rel), "w", newline="\n") as f:
            f.write(text)
        before = {r: sf.read_source(r, tmp) for r, _ in files}
        split_text.refresh(files, tmp)
        check = [rel] + [r for r, _ in files if r != rel and sf.read_source(r, tmp) != before[r]]
        parts = bt.read_parts(__import__("targets").get().path("parts"))
        cflags = [f for f in CFLAGS if not f.startswith("-Wa,")]
        bad = []
        for r in check:
            bad += bt.compile_errors(r, sf.read_source(r, tmp), parts, gcc_cmd, cflags, tmp)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    others = len(check) - 1
    if not bad:
        print("file check: %s%s compile%s with this block" % (
            rel, " and %d later file(s) that get its declarations" % others if others else "", "" if others else "s"))
        return
    print("FILE CHECK FAILED: the full build would not compile with this block:")
    for where, lines in bad:
        print("  " + where)
        for l in lines[:8]:
            print("    " + l)
    print("Fix: match the existing declaration of that name (grep src/frontbin/), or use a per-function "
          "alias (D_XXXXXXXX_<func>) in this block and add it to symbol_addrs_resolved.txt.")
    sys.exit(2)


if __name__ == "__main__":
    main()
