"""Generate objdiff *target* objects for UYA's retail level overlays.

These objects exist only so objdiff/decomp.dev can count each level's real
functions and code size (reported as 0% until a level is decompiled). They
are derived from retail code, so they are NOT committed: they live on the CI
runner at C:\\decomp-refs\\level-targets\\ and the workflow copies them in.

Per overlay:
  1. Read .lit/.text file offsets and vrams from the overlay's own section table.
  2. Declare every jal target inside .text as a function (symbol_addrs.txt).
  3. Run splat 0.50.0 / spimdisasm 1.42.4 with one heuristic disabled: the
     "halt function search" in MipsSectionText._findFunctions_branchChecker.
     Data embedded in the multiplayer menu's .text trips it and would leave
     2.2 MB as a single function. On every other level it never triggers
     (verified: identical output with and without it).
  4. Assemble asm/text.s with GNU binutils (mips-linux-gnu-as -march=r5900).
     Data words that decode as non-EE opcodes (sdc1, sc, ...) are rewritten
     to `.word` using the byte comment spimdisasm writes on the same line.
  5. Verify: every .text word equals retail unless it carries a relocation.
  6. Add the overlay's data: every allocated, non-executable retail section
     (.lit, .data, lvl.*, .bss) under its retail name and size, PROGBITS with
     the exact retail bytes, NOBITS as zero-fill. Merged in with `ld -r`;
     .text, its relocations and the function symbols are unchanged by this.

`--data-only <retail.elf> <out.o>` builds just step 6, for frontbin's data
unit (its code comes from the real build instead).

Usage (Linux, needs splat64==0.50.0, spimdisasm==1.42.4, pyelftools,
binutils-mips-linux-gnu):
    python3 gen_level_targets.py <levels_dir> <out_dir>
    python3 gen_level_targets.py --data-only <retail.elf> <out.o>
where <levels_dir> contains singleplayer/<N_name>/overlay.elf and
multiplayer/<N_name>/overlay.elf (Wrench's unpacked layout).
"""
import glob, hashlib, os, re, runpy, shutil, struct, subprocess, sys
from elftools.elf.elffile import ELFFile

AS = ["mips-linux-gnu-as", "-EL", "-march=r5900", "-mabi=eabi"]
NOHALT = '''
import runpy, sys
from spimdisasm.mips.sections import MipsSectionText as m
_o = m.SectionText._findFunctions_branchChecker
def _p(self, *a, **k):
    f, _ = _o(self, *a, **k)
    return f, False
m.SectionText._findFunctions_branchChecker = _p
sys.argv = ["splat"] + sys.argv[1:]
runpy.run_module("splat", run_name="__main__")
'''
LINE = re.compile(r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/)\s*.*$")

SHF_WRITE, SHF_ALLOC, SHF_EXEC = 0x1, 0x2, 0x4

def data_sections(elf_path):
    out = []
    for s in ELFFile(open(elf_path, "rb")).iter_sections():
        f = s["sh_flags"]
        if (f & SHF_ALLOC) and not (f & SHF_EXEC) and s["sh_size"]:
            out.append((s.name, s["sh_type"], s["sh_offset"], s["sh_size"], bool(f & SHF_WRITE), max(s["sh_addralign"], 1)))
    return out

def build_data_obj(elf_path, out_obj):
    lines = []
    for name, typ, off, size, writable, align in data_sections(elf_path):
        fl = "aw" if writable else "a"
        if typ == "SHT_NOBITS":
            lines += [f'.section {name}, "{fl}", @nobits', f".balign {align}", f".space {size:#x}"]
        else:
            lines += [f'.section {name}, "{fl}", @progbits', f".balign {align}",
                      f'.incbin "{os.path.abspath(elf_path)}", {off:#x}, {size:#x}']
    src = out_obj + ".s"
    open(src, "w").write("\n".join(lines) + "\n")
    subprocess.run(AS + ["--no-pad-sections", src, "-o", out_obj], check=True)
    os.unlink(src)

def verify_data(retail_elf, obj):
    raw = open(retail_elf, "rb").read(); o = ELFFile(open(obj, "rb")); bad = []
    for name, typ, off, size, _, _ in data_sections(retail_elf):
        s = o.get_section_by_name(name)
        if s is None or s["sh_size"] != size:
            bad.append(name)
        elif typ != "SHT_NOBITS" and s.data() != raw[off:off + size]:
            bad.append(name)
    return bad

def build(elf_path, work, out_obj):
    shutil.rmtree(work, ignore_errors=True); os.makedirs(work)
    shutil.copy(elf_path, os.path.join(work, "overlay.elf"))
    raw = open(elf_path, "rb").read()
    e = ELFFile(open(elf_path, "rb"))
    lit, text = e.get_section_by_name(".lit"), e.get_section_by_name(".text")
    t_off, t_va, t_sz = text["sh_offset"], text["sh_addr"], text["sh_size"]
    targets = set()
    for i in range(0, t_sz, 4):
        w = struct.unpack_from("<I", raw, t_off + i)[0]
        if w >> 26 == 3:
            a = ((t_va + i + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if t_va <= a < t_va + t_sz:
                targets.add(a)
    open(os.path.join(work, "symbol_addrs.txt"), "w").write(
        "".join(f"func_{a:08X} = 0x{a:08X}; // type:func\n" for a in sorted(targets)))
    open(os.path.join(work, "nohalt.py"), "w").write(NOHALT)
    open(os.path.join(work, "overlay.splat.yaml"), "w").write(f"""name: overlay
sha1: {hashlib.sha1(raw).hexdigest()}
options:
  basename: overlay
  target_path: overlay.elf
  base_path: .
  build_path: build
  asm_path: asm
  src_path: src
  ld_script_path: overlay.splat.ld
  compiler: EEGCC
  platform: ps2
  gp_value: 0x001DC8B0
  asm_function_macro: glabel
  asm_data_macro: dlabel
  generate_asm_macros_files: True
  symbol_addrs_path: [symbol_addrs.txt]
segments:
  - {{name: header, type: bin, start: 0x0, vram: 0x0}}
  - {{name: pre_text, type: bin, start: {lit['sh_offset']:#x}, vram: {lit['sh_addr']:#x}}}
  - name: text
    type: code
    start: {t_off:#x}
    vram: {t_va:#x}
    subsegments:
      - [{t_off:#x}, asm, text]
  - {{name: tail, type: bin, start: {t_off + t_sz:#x}}}
  - [{len(raw):#x}]
""")
    subprocess.run([sys.executable, "nohalt.py", "split", "overlay.splat.yaml"], cwd=work, check=True, capture_output=True)
    cmd = AS + ["-I", "include", "asm/text.s", "-o", os.path.abspath(out_obj)]
    for _ in range(5):
        r = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
        errs = sorted({int(m.group(1)) for m in re.finditer(r"asm/text\.s:(\d+): Error", r.stderr)})
        if not errs:
            break
        p = os.path.join(work, "asm", "text.s"); lines = open(p).read().split("\n")
        for ln in errs:
            m = LINE.match(lines[ln - 1])
            if not m:
                raise RuntimeError(f"cannot rewrite line {ln}: {lines[ln-1]}")
            lines[ln - 1] = f"{m.group(1)} .word 0x{int.from_bytes(bytes.fromhex(m.group(2)), 'little'):08X}"
        open(p, "w").write("\n".join(lines))
    if r.returncode != 0:
        raise RuntimeError(r.stderr[-2000:])
    o = ELFFile(open(out_obj, "rb")); ob = o.get_section_by_name(".text").data()
    relocs = {x["r_offset"] for x in o.get_section_by_name(".rel.text").iter_relocations()}
    rb = raw[t_off:t_off + t_sz]
    bad = sum(1 for i in range(0, len(rb) - 3, 4) if ob[i:i+4] != rb[i:i+4] and i not in relocs)
    nfunc = sum(1 for s in o.get_section_by_name(".symtab").iter_symbols() if s["st_info"]["type"] == "STT_FUNC")
    code_obj, data_obj = out_obj + ".code.o", out_obj + ".data.o"
    os.replace(out_obj, code_obj)
    build_data_obj(elf_path, data_obj)
    subprocess.run(["mips-linux-gnu-ld", "-r", "-EL", code_obj, data_obj, "-o", out_obj], check=True)
    os.unlink(code_obj); os.unlink(data_obj)
    m = ELFFile(open(out_obj, "rb"))
    if m.get_section_by_name(".text").data() != ob:
        raise RuntimeError("merging data changed .text")
    bad_data = verify_data(elf_path, out_obj)
    if bad_data:
        raise RuntimeError(f"data sections differ from retail: {bad_data}")
    return nfunc, bad

if __name__ == "__main__":
    if sys.argv[1] == "--data-only":
        retail, out = sys.argv[2:4]
        build_data_obj(retail, out)
        bad = verify_data(retail, out)
        print(f"{os.path.basename(out)}: data sections differing from retail: {bad or 'none'}")
        sys.exit(1 if bad else 0)
    levels, out = sys.argv[1:3]
    os.makedirs(out, exist_ok=True)
    for elf in sorted(glob.glob(os.path.join(levels, "*", "*", "overlay.elf"))):
        name = os.path.basename(os.path.dirname(elf))
        nfunc, bad = build(elf, os.path.join(out, "_work", name), os.path.join(out, name + ".o"))
        print(f"{name}: {nfunc} functions, non-reloc mismatches vs retail: {bad}")
        shutil.rmtree(os.path.join(out, "_work", name), ignore_errors=True)
