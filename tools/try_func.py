#!/usr/bin/env python3
"""try_func.py: compile a C file and diff its functions against retail.

The fast command-line way to test a match, without localdecomp. It compiles
FILE.c the way tools/build_text.py would compile that address range (flags
from tools/localdecomp_flags.txt, then tools/text_parts.txt), then compares
each function word by word against the retail frontbin.elf in the repo root.
Relocated fields (%hi/%lo halves, $gp offsets, jal targets) are filled in
with the symbols' real addresses (symbol_addrs_resolved.txt, or the address in
a D_/func_ name) and compared in full, so a wrong symbol or two swapped stores
show up. Only relocations against unnamed sections are still masked.

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
  --early-extern-size SYMBOL=SIZE
                     expose a matching compiler-emitted size before first use
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
            bopts.append("-B" + os.environ.get("UYA_PS2AS_PREFIX", os.path.join(toolchain, "ee", "bin", "Ps2Ee")))
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


_REGN = ("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 "
         "s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra").split()
# R5900 (EE) instructions capstone doesn't know: MMI (opcode 0x1C), lq/sq.
# MMI0/1/2/3 are selected by the function field, the operation by bits 6-10.
_MMI = {
    0x08: {0: "paddw", 1: "psubw", 2: "pcgtw", 3: "pmaxw", 4: "paddh", 5: "psubh", 6: "pcgth", 7: "pmaxh",
           8: "paddb", 9: "psubb", 10: "pcgtb", 16: "paddsw", 17: "psubsw", 18: "pextlw", 19: "ppacw",
           20: "paddsh", 21: "psubsh", 22: "pextlh", 23: "ppach", 24: "paddsb", 25: "psubsb", 26: "pextlb",
           27: "ppacb", 30: "pext5", 31: "ppac5"},
    0x28: {1: "pabsw", 2: "pceqw", 3: "pminw", 4: "padsbh", 5: "pabsh", 6: "pceqh", 7: "pminh", 10: "pceqb",
           16: "padduw", 17: "psubuw", 18: "pextuw", 20: "padduh", 21: "psubuh", 22: "pextuh", 24: "paddub",
           25: "psubub", 26: "pextub", 27: "qfsrv"},
    0x09: {0: "pmaddw", 2: "psllvw", 3: "psrlvw", 4: "pmsubw", 8: "pmfhi", 9: "pmflo", 10: "pinth",
           12: "pmultw", 13: "pdivw", 14: "pcpyld", 16: "pmaddh", 17: "phmadh", 18: "pand", 19: "pxor",
           20: "pmsubh", 21: "phmsbh", 26: "pexeh", 27: "prevh", 28: "pmulth", 29: "pdivbw", 30: "pexew",
           31: "prot3w"},
    0x29: {0: "pmadduw", 3: "psravw", 8: "pmthi", 9: "pmtlo", 10: "pinteh", 12: "pmultuw", 13: "pdivuw",
           14: "pcpyud", 18: "por", 19: "pnor", 26: "pexch", 27: "pcpyh", 30: "pexcw"},
}
_MMI_FN = {0x00: "madd", 0x01: "maddu", 0x04: "plzcw", 0x10: "mfhi1", 0x11: "mthi1", 0x12: "mflo1",
           0x13: "mtlo1", 0x18: "mult1", 0x19: "multu1", 0x1A: "div1", 0x1B: "divu1", 0x20: "madd1",
           0x21: "maddu1", 0x30: "pmfhl", 0x31: "pmthl", 0x34: "psllh", 0x36: "psrlh", 0x37: "psrah",
           0x3C: "psllw", 0x3E: "psrlw", 0x3F: "psraw"}


def ee_dis(word):
    """Text for an R5900-only instruction, or None."""
    op, rs, rt, rd = word >> 26, (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31
    r = lambda n: "$" + _REGN[n]
    if op in (0x1E, 0x1F):
        imm = word & 0xFFFF
        imm = imm - 0x10000 if imm & 0x8000 else imm
        return "%s %s, %s(%s)" % ("lq" if op == 0x1E else "sq", r(rt), hex(imm), r(rs))
    if op != 0x1C:
        return None
    fn, sa = word & 0x3F, (word >> 6) & 31
    if fn in _MMI:
        name = _MMI[fn].get(sa)
        return "%s %s, %s, %s" % (name, r(rd), r(rs), r(rt)) if name else None
    name = _MMI_FN.get(fn)
    if name is None:
        return None
    if fn in (0x34, 0x36, 0x37, 0x3C, 0x3E, 0x3F):
        return "%s %s, %s, %d" % (name, r(rd), r(rt), sa)
    return "%s %s, %s, %s" % (name, r(rd), r(rs), r(rt))


def dis(word):
    if word is None:
        return "-"
    if word >> 26 in (0x1C, 0x1E, 0x1F):  # MMI, lq, sq: capstone reads these as other ISAs' opcodes
        ee = ee_dis(word)
        if ee:
            return ee
    ins = list(MD.disasm(struct.pack("<I", word), 0))
    if ins:
        return f"{ins[0].mnemonic} {ins[0].op_str}"
    return f".word 0x{word:08x}"


def text_c_context(name, own_src):
    """(context, source): the declarations the full build puts in front of
    `name` (build_text.function_context), and `own_src` without typedefs the
    context already defines identically."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("build_text", os.path.join(ROOT, "tools", "build_text.py"))
    bt = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(bt)
    parts = bt.read_parts(os.path.join(ROOT, "tools", "text_parts.txt"))
    ctx = bt.function_context(None, parts, name, own_src=own_src)
    return ctx, bt.drop_repeated_typedefs(ctx, own_src)


def early_extern_metadata(text, sizes):
    if sizes is not None and not isinstance(sizes, dict):
        raise ValueError("early extern metadata must be a symbol-to-size dictionary")
    if not sizes:
        return text
    start = re.search(r"^\s*\.ent\s+\S+[^\n]*", text, re.M)
    if not start:
        raise ValueError("early extern metadata needs a compiler function entry")
    require_names = {}
    for symbol, size in sizes.items():
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", symbol) or type(size) is not int or size <= 0:
            raise ValueError("early extern metadata needs an identifier and positive integer size")
        require_names[symbol] = size
    declarations = {}
    pattern = re.compile(r"^\s*\.extern\s+([A-Za-z_][A-Za-z0-9_]*)\s*,\s*(0x[0-9A-Fa-f]+|[0-9]+)\s*(?:#.*)?$")
    for line in text.splitlines():
        match = pattern.fullmatch(line)
        if match:
            symbol, size_text = match.groups()
            size = int(size_text, 16 if size_text.lower().startswith("0x") else 10)
            if symbol in declarations and declarations[symbol] != size:
                raise ValueError("conflicting compiler extern sizes for " + symbol)
            declarations[symbol] = size
    for symbol, size in require_names.items():
        if declarations.get(symbol) != size:
            raise ValueError("missing or different compiler-emitted extern size for " + symbol)
    metadata = "".join(".extern %s, %d\n" % (symbol, size) for symbol, size in require_names.items())
    return text[:start.start()] + metadata + text[start.start():]


def parse_extern_size(value):
    try:
        symbol, size_text = value.split("=", 1)
        size = int(size_text, 0)
    except ValueError:
        raise argparse.ArgumentTypeError("expected SYMBOL=SIZE")
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", symbol) or size <= 0:
        raise argparse.ArgumentTypeError("expected an identifier and positive size")
    return symbol, size


def compile_c(src_path, flags, args, name=None):
    src = open(src_path).read()
    if name and not args.no_context:
        # Compile in the same context as the full build: earlier #defines,
        # prototypes and .extern hints change code generation.
        ctx, src = text_c_context(name, src)
        src = '#line 1 "<source file context>"\n' + ctx + '#line 1 "%s"\n' % src_path + src
    if "common.h" not in src:
        src = '#include "common.h"\n' + src
    tmpdir = tempfile.mkdtemp(prefix="try_func_")
    c_path = os.path.join(tmpdir, "t.c")
    o_path = os.path.join(tmpdir, "t.o")
    open(c_path, "w").write(src)
    gcc = os.path.join(args.toolchain, "bin", "ee-gcc2953.exe")
    s_path = os.path.join(tmpdir, "t.s")
    base = ([args.runner] if args.runner else []) + [gcc, "-I", "include", "-I", "."] + expand(flags, args.toolchain)
    # Without --runner the compiler is base[0], not base[1]: inserting at a fixed
    # index 2 swallowed "-S" as the argument of the preceding "-I" and gcc fell
    # through to the link step (ld: built in linker script:1: parse error).
    head = 2 if args.runner else 1
    cmd = base[:head] + ["-S"] + base[head:] + ["-o", s_path, c_path]
    p = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    if not p.returncode and os.path.exists(s_path):
        # retail's loop padding (tools/asm_filter.py), as in the full build
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        import asm_filter
        assembly = open(s_path, newline="").read()
        try:
            assembly = early_extern_metadata(assembly, getattr(args, "early_extern_sizes", None))
        except ValueError as error:
            print("METADATA ERROR: " + str(error))
            return None
        filtered = asm_filter.filter_asm(assembly)
        open(s_path, "w", newline="").write(filtered)
        cmd = base[:head] + ["-c"] + base[head:] + ["-o", o_path, s_path]
        p2 = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
        p = subprocess.CompletedProcess(cmd, p2.returncode, p.stdout + p2.stdout, p.stderr + p2.stderr)
    if p.returncode or not os.path.exists(o_path):
        print("COMPILE ERROR\n" + " ".join(cmd) + "\n" + (p.stdout + p.stderr)[-3000:])
        if "<source file context>" in p.stdout + p.stderr:
            print("(an error in <source file context> means your file conflicts with an earlier "
                  "declaration in its source file (src/frontbin/); the full build would fail the same way. "
                  "--no-context compiles the file alone.)")
        return None
    return o_path


GP = 0x1DC8B0
_ADDRS = None


def symbol_address(name):
    """Real address of a symbol: symbol_addrs_resolved.txt first, then the
    address encoded in splat-style names (D_/func_/jtbl_ + hex, optional
    _suffix alias). None if unknown."""
    global _ADDRS
    if _ADDRS is None:
        _ADDRS = {}
        p = os.path.join(ROOT, "symbol_addrs_resolved.txt")
        if os.path.exists(p):
            for m in re.finditer(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", open(p).read(), re.M):
                _ADDRS[m.group(1)] = int(m.group(2), 16)
    if name in _ADDRS:
        return _ADDRS[name]
    m = re.match(r"^(?:D|func|jtbl)_([0-9A-Fa-f]{5,8})(?:_\w+)?$", name)
    return int(m.group(1), 16) if m else None


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def resolve_relocations(elf, text):
    """Relocated instructions filled in with the real addresses, so a diff
    compares them fully. Masking them instead (the old behavior) hid real
    differences: two $gp stores swapped with each other differ only in their
    GPREL16 immediates, so a wrong statement order still reported MATCH.

    Returns ({offset: resolved word}, {offset: mask}) where the mask covers
    relocations whose symbol address is unknown (section-relative ones)."""
    resolved, mask = {}, {}
    symtab = list(elf.get_section_by_name(".symtab").iter_symbols())
    relocs = []
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name in (".rel.text", ".rela.text"):
            relocs += list(sec.iter_relocations())
    relocs.sort(key=lambda r: r["r_offset"])
    word = lambda off: struct.unpack("<I", text[off:off + 4])[0]
    pending_hi = []
    for r in relocs:
        off, t = r["r_offset"], r["r_info_type"]
        sym = symtab[r["r_info_sym"]]
        addr = symbol_address(sym.name) if sym.name and sym["st_info"]["type"] != "STT_SECTION" else None
        ins = word(off)
        if addr is None:
            mask[off] = 0xFC000000 if t == 4 else 0xFFFF0000 if t in (5, 6, 7) else 0
            continue
        if t == 4:  # R_MIPS_26
            target = addr + ((ins & 0x3FFFFFF) << 2)
            resolved[off] = (ins & 0xFC000000) | ((target >> 2) & 0x3FFFFFF)
        elif t == 5:  # R_MIPS_HI16, resolved at its LO16
            pending_hi.append((off, sym.name, ins))
        elif t == 6:  # R_MIPS_LO16
            lo = sext16(ins & 0xFFFF)
            for hoff, hname, hins in [h for h in pending_hi if h[1] == sym.name]:
                full = addr + ((hins & 0xFFFF) << 16) + lo
                resolved[hoff] = (hins & 0xFFFF0000) | (((full + 0x8000) >> 16) & 0xFFFF)
            pending_hi = [h for h in pending_hi if h[1] != sym.name]
            resolved[off] = (ins & 0xFFFF0000) | ((addr + lo) & 0xFFFF)
        elif t == 7:  # R_MIPS_GPREL16
            resolved[off] = (ins & 0xFFFF0000) | ((addr + sext16(ins & 0xFFFF) - GP) & 0xFFFF)
        else:
            mask[off] = 0
    for hoff, _, _ in pending_hi:  # HI16 without a LO16: fall back to masking
        mask[hoff] = 0xFFFF0000
    return resolved, mask


def diff_object(o_path, names, retail, quiet):
    elf = ELFFile(open(o_path, "rb"))
    text = elf.get_section_by_name(".text").data()
    resolved, mask = resolve_relocations(elf, text)
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
            if a is not None and off + i * 4 in resolved:
                a = resolved[off + i * 4]
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
    ap.add_argument("--early-extern-size", action="append", type=parse_extern_size, default=[],
                    help="promote a matching compiler-emitted extern size before its first use (SYMBOL=SIZE)")
    ap.add_argument("--all-modes", action="store_true")
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--no-context", action="store_true",
                    help="compile the file alone, without the declarations its source file (src/frontbin/) puts in front of it")
    ap.add_argument("--toolchain", default=DEFAULT_TOOLCHAIN)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--retail", default=os.path.join(ROOT, "frontbin.elf"))
    args = ap.parse_args()
    args.early_extern_sizes = {}
    for symbol, size in args.early_extern_size:
        if symbol in args.early_extern_sizes and args.early_extern_sizes[symbol] != size:
            ap.error("conflicting early extern sizes for " + symbol)
        args.early_extern_sizes[symbol] = size

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
        o = compile_c(args.file, flags, args, names[0])
        if o:
            diff_object(o, names, retail, args.quiet or args.all_modes)


if __name__ == "__main__":
    main()
