#!/usr/bin/env python3
"""try_func.py: compile a C file and diff its functions against retail.

The fast command-line way to test a match, without localdecomp. It compiles
FILE.c the way tools/build_text.py would compile that address range (flags
from tools/localdecomp_flags.txt, then tools/text_parts.txt), then compares
each function word by word against the retail frontbin.elf in the repo root.
Relocated fields (the %hi/%lo halves, jal targets) are masked, so
`lui $a0, 0` vs `lui $a0, 0x1e` is not a difference.

    python tools/try_func.py scratch/func_0039BEC0.c
    python tools/try_func.py scratch/f.c func_0039BEC0 --mode S --as ps2as
    python tools/try_func.py scratch/f.c --all-modes

FILE.c is a self-contained snippet: the externs and typedefs it needs, then
one or more functions. `#include "common.h"` is added if missing.

Options:
  --mode S|N         force split addresses (S) or -mno-split-addresses (N)
  --as default|ps2as|newas
                     assembler: bin/ee-as.exe (default), SN Ps2EeAs, ee/bin/as.exe
  --flags "..."      extra compiler flags (appended)
  --all-modes        try S, S+ps2as, N, N+ps2as and print one line each
  --quiet            only print MATCH / N diff lines

Toolchain: --toolchain DIR or env UYA_TOOLCHAIN (default
C:/tools/eegcc_2.95.3_sn_v1.36). On Linux/macOS pass --runner /path/to/wibo
(or env UYA_RUNNER) to run the Windows executables.

Needs: pip install -r tools/requirements.txt (pyelftools, capstone).
"""
import argparse, os, re, struct, subprocess, sys, tempfile

try:
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, CS_MODE_LITTLE_ENDIAN
except ImportError:
    sys.exit("try_func.py needs pyelftools and capstone: pip install -r tools/requirements.txt")

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_TOOLCHAIN = os.environ.get("UYA_TOOLCHAIN", "C:/tools/eegcc_2.95.3_sn_v1.36")
FUNC_DEF_RE = re.compile(
    r'^(?!extern|typedef|static inline)[^\n;]*\b(func_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{', re.M)


def read_table(path, keyed_by_name=False):
    rows = []
    if not os.path.exists(path):
        return rows
    for line in open(path):
        fields = line.split('#', 1)[0].split()
        if len(fields) < 2:
            continue
        if keyed_by_name:
            rows.append((fields[0].lower(), fields[1:]))
        else:
            rows.append((int(fields[0], 16), fields[1:]))
    return rows


def flags_for(addr):
    """Same lookup localdecomp uses: localdecomp_flags.txt, then text_parts.txt."""
    for name, fl in read_table(os.path.join(ROOT, "tools", "localdecomp_flags.txt"), True):
        if name == "func_%08x" % addr:
            return fl
    best = None
    for start, fl in read_table(os.path.join(ROOT, "tools", "text_parts.txt")):
        if addr >= start and (best is None or start >= best[0]):
            best = (start, fl)
    return best[1] if best else ["-O2", "-G8"]


def apply_overrides(flags, mode, asm):
    fl = [f for f in flags if f != "-mno-split-addresses"] if mode else list(flags)
    if mode == "N":
        fl.append("-mno-split-addresses")
    if asm:
        fl = [f for f in fl if f not in ("@ps2as", "@newas")]
        if asm != "default":
            fl.append("@" + asm)
    return fl


def expand(flags, toolchain):
    """Mirror tools/build_text.py: pseudo-flags become -B options placed last
    (gcc uses the last -B), after the default bin/ee- assembler."""
    out, bopts = [], ["-B" + os.path.join(toolchain, "bin", "ee-")]
    for f in flags:
        if f == "@ps2as":
            bopts.append("-B" + os.path.join(toolchain, "ee", "bin", "Ps2Ee"))
            out.append("-DNO_MACRO_INC")
        elif f == "@newas":
            bopts.append("-B" + os.path.join(toolchain, "ee", "bin") + os.sep)
        else:
            out.append(f)
    if any(f == "-DNO_MACRO_INC" for f in out):
        out = [f for f in out if not f.startswith("-Wa,")]  # Ps2EeAs rejects GNU as options
    return out + bopts


class Retail:
    def __init__(self, path):
        if not os.path.exists(path):
            sys.exit(f"{path} not found. Copy your own retail frontbin.elf to the repo root "
                     "(it is gitignored and must never be committed).")
        elf = ELFFile(open(path, "rb"))
        self.segs = [(s["p_vaddr"], s.data()) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]

    def read(self, va, n):
        for base, data in self.segs:
            if base <= va < base + len(data):
                return data[va - base:va - base + n]
        return b""


def retail_size(name, fallback):
    p = os.path.join(ROOT, "asm", "nonmatchings", "text", name + ".s")
    if os.path.exists(p):
        m = re.search(r"nonmatching \w+, (0x[0-9A-Fa-f]+)", open(p, errors="ignore").read())
        if m:
            return int(m.group(1), 16)
    return fallback


MD = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_LITTLE_ENDIAN)


def dis(word):
    if word is None:
        return "-"
    ins = list(MD.disasm(struct.pack("<I", word), 0))
    return f"{ins[0].mnemonic} {ins[0].op_str}" if ins else f".word 0x{word:08x}"


def compile_c(src_path, flags, args):
    src = open(src_path).read()
    if "common.h" not in src:
        src = '#include "common.h"\n' + src
    tmpdir = tempfile.mkdtemp(prefix="try_func_")
    c_path = os.path.join(tmpdir, "t.c")
    o_path = os.path.join(tmpdir, "t.o")
    open(c_path, "w").write(src)
    gcc = os.path.join(args.toolchain, "bin", "ee-gcc2953.exe")
    cmd = ([args.runner] if args.runner else []) + [gcc, "-c", "-I", "include", "-I", "."] \
        + expand(flags, args.toolchain) + ["-o", o_path, c_path]
    p = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    if p.returncode or not os.path.exists(o_path):
        print("COMPILE ERROR\n" + " ".join(cmd) + "\n" + (p.stdout + p.stderr)[-3000:])
        return None
    return o_path


def diff_object(o_path, names, retail, quiet):
    elf = ELFFile(open(o_path, "rb"))
    text = elf.get_section_by_name(".text").data()
    mask = {}
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name in (".rel.text", ".rela.text"):
            for r in sec.iter_relocations():
                t = r["r_info_type"]
                # R_MIPS_26 -> jump target field; HI16/LO16/GPREL16 -> immediate field
                mask[r["r_offset"]] = 0xFC000000 if t == 4 else 0xFFFF0000 if t in (5, 6, 7) else 0
    syms = {s.name: s for s in elf.get_section_by_name(".symtab").iter_symbols()}
    results = {}
    for name in names:
        s = syms.get(name)
        if s is None:
            print(f"{name}: not in object"); results[name] = None; continue
        off, size = s["st_value"], s["st_size"]
        ours = text[off:off + size]
        theirs = retail.read(int(name[5:], 16), retail_size(name, size))
        n = max(len(ours), len(theirs)) // 4
        word = lambda b, i: struct.unpack("<I", b[i * 4:i * 4 + 4])[0] if i * 4 + 4 <= len(b) else None
        diffs, lines = 0, []
        for i in range(n):
            a, b = word(ours, i), word(theirs, i)
            m = mask.get(off + i * 4, 0xFFFFFFFF)
            same = (a is not None and b is not None and (a & m) == (b & m)) \
                or (a in (0, None) and b in (0, None))  # trailing alignment nops
            diffs += not same
            lines.append(("   " if same else "** ") + f"{dis(a):<40}| {dis(b)}")
        results[name] = diffs
        print(f"{name}: " + ("MATCH" if diffs == 0 else f"{diffs} diff"))
        if diffs and not quiet:
            print(f"   {'yours':<40}| retail")
            print("\n".join(lines))
    return results


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("names", nargs="*")
    ap.add_argument("--mode", choices=["S", "N"])
    ap.add_argument("--as", dest="asm", choices=["default", "ps2as", "newas"])
    ap.add_argument("--flags", default="")
    ap.add_argument("--all-modes", action="store_true")
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--toolchain", default=DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--retail", default=os.path.join(ROOT, "frontbin.elf"))
    args = ap.parse_args()

    src = open(args.file).read()
    names = args.names or list(dict.fromkeys(FUNC_DEF_RE.findall(src)))
    if not names:
        sys.exit("no func_XXXXXXXX definitions found; pass the function name")
    retail = Retail(args.retail)
    base = flags_for(int(names[0][5:], 16))
    print("flags:", " ".join(base))

    combos = [(args.mode, args.asm)]
    if args.all_modes:
        combos = [("S", "default"), ("S", "ps2as"), ("N", "default"), ("N", "ps2as")]
    for mode, asm in combos:
        flags = apply_overrides(base, mode, asm) + args.flags.split()
        if args.all_modes:
            print(f"--- mode {mode}, assembler {asm}")
        o = compile_c(args.file, flags, args)
        if o:
            diff_object(o, names, retail, args.quiet or args.all_modes)


if __name__ == "__main__":
    main()
