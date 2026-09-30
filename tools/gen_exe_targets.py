"""Generate objdiff *target* objects for the game's other executables.

boot_elf.elf, i5bootn.elf, ntgui.elf and sly2.elf are stripped (no symbols), so
this finds functions the way gen_level_targets.py does (every jal target, then
splat/spimdisasm), but instead of assembling splat's output it builds the object
straight from the ELF: each code section's bytes are copied verbatim, so the
code is retail by construction. There are no relocations.

Per ELF, written to <out_dir>:
  <name>.o        code sections (.text, core.text, ...) with one function symbol
                  per function found
  <name>_data.o   every other allocated section that has bytes (.data, .rodata,
                  .lit, .irx, VU microcode, ...). NOBITS sections (.bss, .sbss)
                  hold nothing to decompile and are left out.

These objects are derived from retail code, so they are never committed: they
live next to the level targets in C:\\decomp-refs\\exe-targets\\. The tool
refuses to write inside the repo (other than build/).

With --objdiff FILE the matching units and categories are (re)written in that
objdiff.json.

Usage:
    python tools/gen_exe_targets.py <game_dir> <out_dir>
    python tools/gen_exe_targets.py <game_dir> <out_dir> --objdiff objdiff.json
<game_dir> is the unpacked disc (the folder containing boot_elf.elf and files\\).
Needs splat64==0.50.0, spimdisasm==1.42.4, pyelftools.
"""
import argparse, hashlib, json, os, re, shutil, struct, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from elftools.elf.elffile import ELFFile
from gen_level_targets import NOHALT
from split_shared_levels import build_elf, SHF_ALLOC, SHF_EXEC, SHF_WRITE, SHT_PROGBITS, SHT_NOBITS

# (file under <game_dir>, object name, category id, category name)
EXES = [
    ("boot_elf.elf", "boot_elf", "boot_elf", "Boot ELF (core engine)"),
    ("files/i5bootn.elf", "i5bootn", "i5bootn", "Bootstrap (i5bootn)"),
    ("files/netgui/ntgui.elf", "ntgui", "ntgui", "Network GUI (ntgui)"),
    ("files/sly2/sly2.elf", "sly2", "sly2", "Sly 2 (sly2.elf)"),
]
VU_SECTIONS = (".vutext", ".vudata")      # VU microcode: bytes, not MIPS code


def sections(elf):
    out = []
    for i, s in enumerate(elf.iter_sections()):
        if s.name and s["sh_flags"] & SHF_ALLOC and s["sh_size"]:
            out.append(s)
    return out


def code_sections(elf):
    return sorted((s for s in sections(elf)
                   if s["sh_flags"] & SHF_EXEC and s["sh_type"] == "SHT_PROGBITS" and s.name not in VU_SECTIONS),
                  key=lambda s: s["sh_offset"])


def safe(name):
    return re.sub(r"\W", "_", name.strip("."))


def find_functions(elf_path, work):
    """-> {section name: [(vram, size)]} from splat's disassembly."""
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)
    shutil.copy(elf_path, os.path.join(work, "input.elf"))
    raw = open(elf_path, "rb").read()
    elf = ELFFile(open(elf_path, "rb"))
    code = code_sections(elf)
    targets = set()
    for s in code:
        off, va, size = s["sh_offset"], s["sh_addr"], s["sh_size"]
        for i in range(0, size - 3, 4):
            w = struct.unpack_from("<I", raw, off + i)[0]
            if w >> 26 == 3:
                a = ((va + i + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                if any(c["sh_addr"] <= a < c["sh_addr"] + c["sh_size"] for c in code):
                    targets.add(a)
    open(os.path.join(work, "symbol_addrs.txt"), "w").write(
        "".join(f"func_{a:08X} = 0x{a:08X}; // type:func\n" for a in sorted(targets)))
    open(os.path.join(work, "nohalt.py"), "w").write(NOHALT)
    segs, pos = [], 0
    for i, s in enumerate(code):
        off = s["sh_offset"]
        if off > pos:
            segs.append(f"  - {{name: gap{i}, type: bin, start: {pos:#x}}}")
        n = safe(s.name)
        segs.append(f"  - name: {n}\n    type: code\n    start: {off:#x}\n    vram: {s['sh_addr']:#x}\n"
                    f"    subsegments:\n      - [{off:#x}, asm, {n}]")
        pos = off + s["sh_size"]
    segs.append(f"  - {{name: tail, type: bin, start: {pos:#x}}}")
    segs.append(f"  - [{len(raw):#x}]")
    open(os.path.join(work, "x.splat.yaml"), "w").write(f"""name: x
sha1: {hashlib.sha1(raw).hexdigest()}
options:
  basename: x
  target_path: input.elf
  base_path: .
  build_path: build
  asm_path: asm
  src_path: src
  ld_script_path: x.splat.ld
  compiler: EEGCC
  platform: ps2
  gp_value: 0x0
  asm_function_macro: glabel
  asm_data_macro: dlabel
  generate_asm_macros_files: True
  symbol_addrs_path: [symbol_addrs.txt]
segments:
""" + "\n".join(segs) + "\n")
    r = subprocess.run([sys.executable, "nohalt.py", "split", "x.splat.yaml"], cwd=work, capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError(r.stderr[-2000:])
    insn = re.compile(r"^\s*/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) [0-9A-Fa-f]{8} \*/")
    size_re = re.compile(r"^nonmatching \S+, 0x([0-9A-Fa-f]+)")
    found = {}
    for s in code:
        funcs, size, pending = [], 0, False
        for line in open(os.path.join(work, "asm", safe(s.name) + ".s"), errors="replace"):
            m = size_re.match(line)
            if m:
                size = int(m.group(1), 16)
            elif line.startswith("glabel "):
                pending = True
            else:
                m = insn.match(line)
                if m and pending:
                    funcs.append((int(m.group(1), 16), size))
                    pending = False
        found[s.name] = funcs
    return found


def build_objects(elf_path, funcs, out_dir, name):
    raw = open(elf_path, "rb").read()
    elf = ELFFile(open(elf_path, "rb"))
    code = code_sections(elf)
    secs, syms = [], []
    for k, s in enumerate(code, 1):
        blob = raw[s["sh_offset"]:s["sh_offset"] + s["sh_size"]]
        secs.append((s.name, SHT_PROGBITS, SHF_ALLOC | SHF_EXEC, 16, blob, len(blob)))
        for a, size in funcs[s.name]:
            syms.append(("func_%08X" % a, a - s["sh_addr"], size, 0x12, k))
    open(os.path.join(out_dir, name + ".o"), "wb").write(build_elf(raw[:52], secs, syms))
    dsecs = []
    code_names = {s.name for s in code}
    for s in sections(elf):
        if s.name in code_names or s["sh_type"] == "SHT_NOBITS":
            continue
        if s["sh_type"] != "SHT_PROGBITS":          # reginfo, notes, ...
            continue
        blob = raw[s["sh_offset"]:s["sh_offset"] + s["sh_size"]]
        dsecs.append((s.name, SHT_PROGBITS, SHF_ALLOC | (SHF_WRITE if s["sh_flags"] & SHF_WRITE else 0),
                      max(s["sh_addralign"], 4), blob, len(blob)))
    dsyms = [(sec[0], 0, 0, 0x03, k) for k, sec in enumerate(dsecs, 1)]
    open(os.path.join(out_dir, name + "_data.o"), "wb").write(build_elf(raw[:52], dsecs, dsyms))
    return sum(sz for v in funcs.values() for _, sz in v), sum(len(x[4]) for x in dsecs)


def update_objdiff(path):
    d = json.load(open(path))
    d["units"] = [u for u in d["units"] if not u["name"].startswith("exes/")]
    ids = {c[2] for c in EXES} | {"executables"}
    d["progress_categories"] = [c for c in d.get("progress_categories", []) if c["id"] not in ids]
    d["progress_categories"].append({"id": "executables", "name": "Other executables"})
    tdir = "build/objdiff/target/exes/"
    for _, name, cid, cname in EXES:
        d["progress_categories"].append({"id": cid, "name": cname})
        d["units"].append({"name": f"exes/{name}", "target_path": tdir + name + ".o",
                           "metadata": {"progress_categories": ["executables", cid]}})
        d["units"].append({"name": f"exes/{name} (data)", "target_path": tdir + name + "_data.o",
                           "metadata": {"progress_categories": ["executables", cid]}})
    with open(path, "w") as f:
        json.dump(d, f, indent=2)
        f.write("\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game_dir")
    ap.add_argument("out_dir")
    ap.add_argument("--objdiff", help="objdiff.json to update")
    a = ap.parse_args()
    root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
    out = os.path.abspath(a.out_dir)
    if os.path.splitdrive(root)[0] == os.path.splitdrive(out)[0] and os.path.commonpath([root, out]) == root \
            and not out.startswith(os.path.join(root, "build")):
        sys.exit("refusing to write retail-derived objects inside the repo (use build/ or a path outside it)")
    os.makedirs(out, exist_ok=True)
    for rel, name, _, _ in EXES:
        path = os.path.join(a.game_dir, *rel.split("/"))
        work = os.path.join(out, "_work", name)
        funcs = find_functions(path, work)
        code_bytes, data_bytes = build_objects(path, funcs, out, name)
        nfunc = sum(len(v) for v in funcs.values())
        print(f"{name}: {nfunc} functions, {code_bytes / 1e6:.2f} MB code, {data_bytes / 1e6:.2f} MB data")
        shutil.rmtree(work, ignore_errors=True)
    shutil.rmtree(os.path.join(out, "_work"), ignore_errors=True)
    if a.objdiff:
        update_objdiff(a.objdiff)
        print("updated", a.objdiff)


if __name__ == "__main__":
    main()
