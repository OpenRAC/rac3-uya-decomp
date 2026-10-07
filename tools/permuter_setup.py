#!/usr/bin/env python3
"""permuter_setup.py: prepare a decomp-permuter directory for one function.

decomp-permuter (https://github.com/simonlindholm/decomp-permuter) randomly
rewrites a C function (reorders statements, adds temps, changes types, swaps
branches...) and keeps any variant whose compiled code is closer to retail.
It is the standard tool for register-allocation and scheduling near misses:
functions whose instructions are right but where gcc picks another register or
order, and no hand rewrite moves it.

    python tools/permuter_setup.py scratch/func_0037DF98.c
    python tools/permuter_setup.py scratch/f.c func_0037DF98 --out nonmatchings
    python tools/permuter_setup.py --target boot_elf scratch/func_00117000.c
    python <permuter>/permuter.py nonmatchings/func_0037DF98 -j4

FILE.c is the same self-contained snippet tools/try_func.py takes (externs,
typedefs, the function), ideally your closest attempt so far. The script
writes nonmatchings/<func>/ (gitignored; nonmatchings/<target>/<func>/ for a
target other than frontbin, see tools/targets.py) with:

  base.c       FILE.c after the declarations the full build puts in front of
               it (build_text.function_context), preprocessed so pycparser can
               read it. This is what the permuter mutates.
  prelude.c    top-level `__asm__(".extern ...")` size hints from the context;
               pycparser can't parse them, so compile.sh puts them back.
  target.o     retail: the function's .s assembled with the same assembler.
  compile.sh   compiles a candidate with the function's real flags
               (the target's localdecomp_flags.txt, then its text_parts.txt),
               through --runner (wibo) on Linux. An @ee29 range compiles
               with Sony's 2.9-ee driver (--ee29 / UYA_EE29, tools/ee29.py).
               base.c is still preprocessed with the host cpp, which lacks
               the EE predefines (__mips__, __R5900__): for libgcc code that
               picks longlong.h's generic C instead of its MIPS asm, so
               check what base.c contains before permuting such a function.
  settings.toml

Needs a host `gcc` (or `cpp`) for preprocessing and mips-linux-gnu-objdump
(binutils-mips-linux-gnu) for the permuter's scoring. On Windows, run it from
WSL: the permuter itself is Linux-only.

When it finds a score 0 variant (output-0-1/source.c), check it with
tools/try_func.py before pasting it into its source file.
"""
import argparse, os, re, shlex, subprocess, sys, tempfile, importlib.util

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402


def load(name):
    spec = importlib.util.spec_from_file_location(name, os.path.join(ROOT, "tools", name + ".py"))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


HINT_RE = re.compile(r'^\s*__asm__\s*\(\s*"\s*\.extern[^"]*"\s*\)\s*;\s*$', re.M)


ATTR_RE = re.compile(r"__attribute__\s*\(\((?:[^()]|\([^()]*\))*\)\)")


def _statements(text):
    """Top-level statements (`typedef ...;`) with brace depth tracking."""
    out, i, n = [], 0, len(text)
    for m in re.finditer(r"(?m)^\s*typedef\b", text):
        if m.start() < i:
            continue
        j, depth = m.start(), 0
        while j < n:
            c = text[j]
            if c in "{(":
                depth += 1
            elif c in "})":
                depth -= 1
            elif c == ";" and depth == 0:
                break
            j += 1
        out.append(text[m.start():j + 1])
        i = j + 1
    return out


def typedef_attributes(text):
    """{typedef name: [attribute, ...]} for every typedef that carries one."""
    res = {}
    for st in _statements(text):
        found = ATTR_RE.findall(st)
        if not found:
            continue
        bare = re.sub(r"\{.*\}", "{}", ATTR_RE.sub("", st), flags=re.S)
        m = re.search(r"(\w+)\s*(\[[^\]]*\]\s*)*;\s*$", bare)
        if m:
            res[m.group(1)] = found
    return res


def reattach(attrs_path, c_path):
    """Put recorded typedef attributes back into a permuter candidate."""
    import json
    attrs = json.load(open(attrs_path))
    if not attrs:
        return
    text = open(c_path).read()
    out, last = [], 0
    for st in _statements(text):
        k = text.index(st, last)
        bare = re.sub(r"\{.*\}", "{}", st, flags=re.S)
        m = re.search(r"(\w+)\s*(\[[^\]]*\]\s*)*;\s*$", bare)
        if m and m.group(1) in attrs and "__attribute__" not in st:
            st2 = st[:-1].rstrip() + " " + " ".join(attrs[m.group(1)]) + ";"
            out.append(text[last:k] + st2)
        else:
            out.append(text[last:k] + st)
        last = k + len(st)
    out.append(text[last:])
    open(c_path, "w").write("".join(out))


def main():
    if len(sys.argv) == 4 and sys.argv[1] == "--reattach":
        return reattach(sys.argv[2], sys.argv[3])
    t = targets.from_argv()   # --target boot_elf
    GP = t.gp
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("name", nargs="?")
    ap.add_argument("--out", default=os.path.join(ROOT, "nonmatchings") if t.name == targets.DEFAULT
                    else os.path.join(ROOT, "nonmatchings", t.name))
    ap.add_argument("--mode", choices=["S", "N"], help="force split (S) or -mno-split-addresses (N)")
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN", "C:/tools/eegcc_2.95.3_sn_v1.36"))
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--ee29", default=None, help="Sony ee-gcc 2.9-ee folder for @ee29 ranges (tools/ee29.py)")
    ap.add_argument("--cpp", default=os.environ.get("CPP_CMD", "gcc -E"))
    ap.add_argument("--no-context", action="store_true")
    args = ap.parse_args()

    tf = load("try_func")
    src = open(args.file).read()
    name = args.name or next(iter(dict.fromkeys(tf.FUNC_DEF_RE.findall(src))), None)
    if not name:
        sys.exit("no func_XXXXXXXX definition found; pass the function name")
    unit = t.unit_for(int(name[5:], 16)) if re.fullmatch(r"func_[0-9A-Fa-f]{8}", name) else None
    asm_path = os.path.join(ROOT, unit.asm_dir if unit else t.units[0].asm_dir, name + ".s")
    if not os.path.exists(asm_path):
        sys.exit(f"{asm_path} not found (is {name} still INCLUDE_ASM?)")

    d = os.path.join(args.out, name)
    os.makedirs(d, exist_ok=True)

    # ---- base.c: context + snippet, preprocessed ----
    ctx = ""
    if not args.no_context:
        ctx, src = tf.text_c_context(name, src)
    hints = HINT_RE.findall(ctx) + HINT_RE.findall(src)
    ctx, src = HINT_RE.sub("", ctx), HINT_RE.sub("", src)
    raw = '#include "common.h"\n' + ctx + "\n" + src
    tmp = tempfile.mkdtemp(prefix="perm_setup_")
    raw_path = os.path.join(tmp, "raw.c")
    open(raw_path, "w").write(raw)
    cmd = shlex.split(args.cpp) + ["-P", "-DM2CTX", "-D__attribute__(x)=", "-D__extension__=",
                                   "-I", os.path.join(ROOT, "include"), "-I", ROOT, raw_path]
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        sys.exit("preprocessing failed:\n" + p.stderr)
    base = p.stdout
    # pycparser can't read __attribute__, so base.c is preprocessed with it
    # defined away. That silently turns `typedef int Q __attribute__((mode(TI)))`
    # into a plain int and drops aligned(16) on vector structs, so the permuter
    # would score different code than the real build. Record each typedef's
    # attributes from an unstripped preprocessing pass; compile.sh puts them back
    # (tools/permuter_setup.py --reattach) before compiling a candidate.
    cmd_full = [c for c in cmd if c not in ("-D__attribute__(x)=",)]
    pf = subprocess.run(cmd_full, capture_output=True, text=True)
    attrs = typedef_attributes(pf.stdout) if not pf.returncode else {}
    import json
    open(os.path.join(d, "attrs.json"), "w").write(json.dumps(attrs, indent=1))
    open(os.path.join(d, "base.c"), "w").write(base)
    open(os.path.join(d, "prelude.c"), "w").write("\n".join(h.strip() for h in hints) + "\n")

    # ---- flags ----
    flags = tf.apply_overrides(tf.flags_for(int(name[5:], 16)), args.mode, args.asm)
    cc_flags = tf.expand(flags, args.toolchain)
    gcc = os.path.join(args.toolchain, "bin", "ee-gcc2953.exe")
    runner = [args.runner] if args.runner else []

    # ---- target.o: the retail .s through the default assembler ----
    tflags = tf.expand([f for f in flags if f not in ("@ps2as", "@newas")], args.toolchain)
    # splat writes some $gp accesses as bare offsets; compiled C always has a
    # GPREL16 relocation there. Rewrite them the way gcc writes them (`lw $r, D_X`,
    # `la $r, D_X` plus `.extern D_X, 4`, which the assembler turns into
    # $gp-relative) so the permuter's scorer sees the same relocation on both sides.
    gp_syms = set()

    def gp_name(off):
        n = "D_%08X" % ((GP + int(off, 16)) & 0xFFFFFFFF)
        gp_syms.add(n)
        return n
    s_text = open(asm_path, errors="replace").read()
    s_text = re.sub(r"\b(addiu|daddiu)(\s+)(\$\w+),\s*\$gp,\s*(-?0x[0-9A-Fa-f]+)\b",
                    lambda m: "la%s%s, %s" % (m.group(2), m.group(3), gp_name(m.group(4))), s_text)
    s_text = re.sub(r"\b(\w+)(\s+)(\$\w+),\s*(-?0x[0-9A-Fa-f]+)\(\$gp\)",
                    lambda m: "%s%s%s, %s" % (m.group(1), m.group(2), m.group(3), gp_name(m.group(4))), s_text)
    s_text = "".join(".extern %s, 4\n" % n for n in sorted(gp_syms)) + s_text
    tdir = os.path.join(tmp, "t")
    os.makedirs(tdir)
    open(os.path.join(tdir, name + ".s"), "w").write(s_text)
    tsrc = os.path.join(tmp, "target.c")
    open(tsrc, "w").write('#include "common.h"\nINCLUDE_ASM("%s", %s);\n' % (tdir.replace("\\", "/"), name))
    tobj = os.path.join(d, "target.o")
    # ee-gcc hands `-o <path>` to the assembler without quoting, so an output path with a space
    # (a repo checked out under "RATCHET DECOMP DIRECTORY") breaks it: assemble in the temp dir, then copy.
    tobj_tmp = os.path.join(tmp, "target_out.o")
    p = subprocess.run(runner + [gcc, "-c", "-I", "include", "-I", ".", "-DINCLUDE_ASM_USE_MACRO_INC=1"]
                       + tflags + ["-o", tobj_tmp, tsrc], capture_output=True, text=True, cwd=ROOT)
    if p.returncode or not os.path.exists(tobj_tmp):
        sys.exit("assembling target failed:\n" + p.stdout + p.stderr)
    import shutil
    shutil.copyfile(tobj_tmp, tobj)

    # ---- compile.sh ----
    q = lambda xs: " ".join(shlex.quote(x) for x in xs)
    if "@ee29" in flags:
        # Sony's 2.9-ee driver writes the assembly (tools/ee29.py), with its own TMP folder
        import ee29
        s_cmd = ('TMP="$TMP" TEMP="$TMP" TMPDIR="$TMP" '
                 + q(ee29.command(args.ee29, args.runner) + ["-S", "-I", "include", "-I", "."]
                     + ee29.compile_flags(flags)))
    else:
        s_cmd = q(runner + [gcc, "-S", "-I", "include", "-I", "."] + cc_flags)
    sh = f"""#!/usr/bin/env bash
# Generated by tools/permuter_setup.py for {name}. Invoked as: compile.sh in.c -o out.o
set -e
DIR="$(cd "$(dirname "${{BASH_SOURCE[0]}}")" && pwd)"
IN="$(cd "$(dirname "$1")" && pwd)/$(basename "$1")"
OUT="$3"; case "$OUT" in /*) ;; *) OUT="$PWD/$OUT";; esac
TMP="$(mktemp -d)"; trap 'rm -rf "$TMP"' EXIT
cat "$DIR/prelude.c" "$IN" > "$TMP/in.c"
cd {shlex.quote(ROOT)}
python3 tools/permuter_setup.py --reattach "$DIR/attrs.json" "$TMP/in.c"
export UYA_TARGET={t.name}
{s_cmd} -o "$TMP/out.s" "$TMP/in.c"
{'' if "@ee29" in flags else 'python3 tools/asm_filter.py "$TMP/out.s"'}
{q(runner + [gcc, "-c", "-I", "include", "-I", "."] + cc_flags)} -o "$TMP/out.o" "$TMP/out.s"
cp "$TMP/out.o" "$OUT"
"""
    sh_path = os.path.join(d, "compile.sh")
    open(sh_path, "w", newline="\n").write(sh)
    os.chmod(sh_path, 0o755)
    open(os.path.join(d, "settings.toml"), "w").write(
        f'func_name = "{name}"\ncompiler_type = "gcc"\n'
        f'objdump_command = "mips-linux-gnu-objdump -drz -m mips:5900"\n')
    print(f"{d}: flags {' '.join(flags)}")
    print(f"next: python3 <decomp-permuter>/permuter.py {d} -j{os.cpu_count() or 2}")


if __name__ == "__main__":
    main()
