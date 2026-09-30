"""Split the level target objects into common code, level-specific code and level data.

The 51 level overlays share most of their code: a function that appears in two
or more overlays is counted once, in a "common" unit, and dropped from every
level's own unit. Otherwise decomp.dev reports ~100 MB of level code to
decompile when only ~10 MB of it is distinct.

Input is the directory made by gen_level_targets.py (one <N>_<name>.o per
overlay). Those files are derived from retail code, so they are never
committed. Output goes to <out_dir>, which must be outside the repo:

  common.o         every shared function once (no relocations)
  <N>_<name>.o     the original object, with its shared functions demoted to
                   plain symbols (size 0, NOTYPE) and its data sections
                   emptied, so objdiff counts only the level-specific code.
                   Relocations, symbols and .text are otherwise untouched.
  <N>_<name>_data.o the level's .data/.lit/.bss/lvl.* sections, on their own

Two functions are "the same" when their bytes match once every j/jal target is
masked (shared code sits at different addresses in each overlay). Only the
26-bit target of j/jal is masked: masking lui/addiu immediates as well changed
the shared-code share by under 2 points, and risks false sharing.

With --objdiff FILE the level units and progress categories in that
objdiff.json are rewritten to match (see update_objdiff).

Usage:
    python tools/split_shared_levels.py C:\\decomp-refs\\level-targets C:\\decomp-refs\\level-targets-split
    python tools/split_shared_levels.py IN OUT --objdiff objdiff.json
Needs pyelftools.
"""
import argparse, glob, hashlib, json, os, re, struct, sys
from elftools.elf.elffile import ELFFile

SHF_WRITE, SHF_ALLOC, SHF_EXEC = 1, 2, 4
SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_NOBITS = 1, 2, 3, 8
DATA_SECTIONS = (".data", ".lit", ".bss", "lvl.vtbl", "lvl.camvtbl", "lvl.sndvtbl")
SYM = struct.Struct("<IIIBBH")   # Elf32_Sym: name, value, size, info, other, shndx
SHDR = struct.Struct("<IIIIIIIIII")
EHDR = struct.Struct("<16sHHIIIIIHHHHHH")


def level_no(path):
    return int(re.match(r"(\d+)_", os.path.basename(path)).group(1))


def norm_hash(code):
    """sha1 of a function's bytes with j/jal targets masked."""
    n = len(code) // 4
    words = struct.unpack("<%dI" % n, code[:n * 4])
    masked = [(w & 0xFC000000) if (w >> 26) in (2, 3) else w for w in words]
    return hashlib.sha1(struct.pack("<%dI" % n, *masked) + code[n * 4:]).digest()


class Level:
    def __init__(self, path):
        self.path = path
        self.no = level_no(path)
        self.raw = bytearray(open(path, "rb").read())
        elf = ELFFile(open(path, "rb"))
        self.ehdr = bytes(self.raw[:EHDR.size])
        self.shoff, self.shentsize = elf["e_shoff"], elf["e_shentsize"]
        text = elf.get_section_by_name(".text")
        self.text = text.data()
        symtab = elf.get_section_by_name(".symtab")
        self.symtab_off = symtab["sh_offset"]
        self.funcs = []   # (symtab index, name, value, size, hash)
        for i, s in enumerate(symtab.iter_symbols()):
            if s["st_info"]["type"] == "STT_FUNC" and s["st_size"]:
                a, sz = s["st_value"], s["st_size"]
                self.funcs.append((i, s.name, a, sz, norm_hash(self.text[a:a + sz])))
        self.data = []    # (section index, name, type, flags, align, size, bytes)
        for i, s in enumerate(elf.iter_sections()):
            if s.name in DATA_SECTIONS:
                blob = b"" if s["sh_type"] == "SHT_NOBITS" else s.data()
                self.data.append((i, s.name, s["sh_type"] == "SHT_NOBITS", s["sh_flags"],
                                  s["sh_addralign"], s["sh_size"], blob))


def build_elf(ehdr_src, sections, symbols):
    """Minimal MIPS relocatable ELF.

    sections: (name, type, flags, align, data-or-None, size)
    symbols:  (name, value, size, info, shndx); shndx is 1-based into `sections`.
    """
    shstr = b"\0"
    name_off = {}
    for name, *_ in sections + [(".symtab",), (".strtab",), (".shstrtab",)]:
        name_off[name] = len(shstr)
        shstr += name.encode() + b"\0"
    strtab = b"\0"
    syms = [SYM.pack(0, 0, 0, 0, 0, 0)]
    for name, value, size, info, shndx in symbols:
        syms.append(SYM.pack(len(strtab), value, size, info, 0, shndx))
        strtab += name.encode() + b"\0"
    symdata = b"".join(syms)

    body = bytearray(b"\0" * EHDR.size)
    shdrs = [SHDR.pack(*([0] * 10))]
    def add(name, typ, flags, align, data, size, link=0, info=0, entsize=0):
        off = 0
        if data:
            while len(body) % max(align, 1):
                body.append(0)
            off = len(body)
            body.extend(data)
        elif typ == SHT_NOBITS:
            off = len(body)
        shdrs.append(SHDR.pack(name_off[name], typ, flags, 0, off, size, link, info, max(align, 1), entsize))
    for name, typ, flags, align, data, size in sections:
        add(name, typ, flags, align, data, size)
    n = len(sections)
    add(".symtab", SHT_SYMTAB, 0, 4, symdata, len(symdata), link=n + 2, info=1, entsize=SYM.size)
    add(".strtab", SHT_STRTAB, 0, 1, strtab, len(strtab))
    add(".shstrtab", SHT_STRTAB, 0, 1, shstr, len(shstr))
    while len(body) % 4:
        body.append(0)
    shoff = len(body)
    body.extend(b"".join(shdrs))
    e = list(EHDR.unpack(ehdr_src))
    e[1], e[2] = 1, 8                         # ET_REL, EM_MIPS
    e[4], e[5], e[6] = 0, 0, shoff            # entry, phoff, shoff
    e[8], e[9], e[10] = EHDR.size, 0, 0       # ehsize, phentsize, phnum (e[7] keeps e_flags)
    e[7] = struct.unpack("<I", ehdr_src[36:40])[0]
    e[11], e[12], e[13] = SHDR.size, len(shdrs), len(shdrs) - 1
    e[3] = 1
    body[:EHDR.size] = EHDR.pack(*e)
    return bytes(body)


def write_common(levels, shared, out):
    text, syms, used, order = bytearray(), [], {}, []
    seen = set()
    for lv in levels:                          # lowest level number owns the function
        for _, name, a, sz, h in lv.funcs:
            if h in shared and h not in seen:
                seen.add(h)
                order.append((lv, name, a, sz, h))
    for lv, name, a, sz, h in order:
        while len(text) % 8:
            text.append(0)
        n = name if name not in used else "%s_L%d" % (name, lv.no)
        used[n] = h
        syms.append((n, len(text), sz, 0x12, 1))   # GLOBAL FUNC in section 1
        text.extend(lv.text[a:a + sz])
    blob = build_elf(levels[0].ehdr, [(".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXEC, 8, bytes(text), len(text))], syms)
    open(os.path.join(out, "common.o"), "wb").write(blob)
    return sum(o[3] for o in order), len(order)


def write_level_code(lv, shared, out):
    raw = bytearray(lv.raw)
    dropped = 0
    for idx, _, _, sz, h in lv.funcs:
        if h in shared:
            off = lv.symtab_off + idx * SYM.size
            struct.pack_into("<I", raw, off + 8, 0)      # st_size = 0
            raw[off + 12] &= 0xF0                        # type = NOTYPE
            dropped += sz
    for i, *_ in lv.data:                                # empty the data sections
        struct.pack_into("<I", raw, lv.shoff + i * lv.shentsize + 20, 0)
    open(os.path.join(out, os.path.basename(lv.path)), "wb").write(raw)
    return dropped


def write_level_data(lv, out):
    secs, syms = [], []
    for k, (_, name, nobits, flags, align, size, blob) in enumerate(lv.data, 1):
        secs.append((name, SHT_NOBITS if nobits else SHT_PROGBITS, flags, align, None if nobits else blob, size))
        syms.append((name, 0, 0, 0x03, k))               # STT_SECTION
    p = os.path.join(out, os.path.basename(lv.path)[:-2] + "_data.o")
    open(p, "wb").write(build_elf(lv.ehdr, secs, syms))
    return sum(d[5] for d in lv.data)


def update_objdiff(path, levels):
    """Rewrite level units and categories in objdiff.json (frontbin units untouched)."""
    d = json.load(open(path))
    keep = [u for u in d["units"] if not u["name"].startswith("levels/")]
    old = {level_no(u["target_path"]): u for u in d["units"] if u["name"].startswith("levels/") and "target_path" in u}
    cats = [c for c in d.get("progress_categories", [])
            if c["id"] in ("frontend", "singleplayer", "multiplayer")]
    cats += [{"id": "levels", "name": "Level code"},
             {"id": "common_level_code", "name": "Common level code"},
             {"id": "level_specific", "name": "Level-specific code"},
             {"id": "level_data", "name": "Level data (not deduplicated)"}]
    units = []
    tdir = "build/objdiff/target/levels/"
    units.append({"name": "levels/common", "target_path": tdir + "common.o",
                  "metadata": {"progress_categories": ["levels", "common_level_code"]}})
    for lv in levels:
        u = old[lv.no]
        pretty = u["name"].split("/", 2)[2]
        mode = u["name"].split("/")[1]
        cid = "level_%02d" % lv.no
        cats.append({"id": cid, "name": "Level %02d: %s" % (lv.no, pretty)})
        base = os.path.basename(lv.path)
        units.append({"name": u["name"], "target_path": tdir + base,
                      "metadata": {"progress_categories": ["levels", "level_specific", mode, cid]}})
        units.append({"name": u["name"] + " (data)", "target_path": tdir + base[:-2] + "_data.o",
                      "metadata": {"progress_categories": ["level_data", mode]}})
    d["units"] = keep + units
    d["progress_categories"] = cats
    with open(path, "w") as f:
        json.dump(d, f, indent=2)
        f.write("\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("in_dir")
    ap.add_argument("out_dir")
    ap.add_argument("--objdiff", help="objdiff.json to update")
    a = ap.parse_args()
    root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
    out_abs = os.path.abspath(a.out_dir)
    inside = os.path.splitdrive(root)[0] == os.path.splitdrive(out_abs)[0] and os.path.commonpath([root, out_abs]) == root
    if inside and not out_abs.startswith(os.path.join(root, "build")):
        sys.exit("refusing to write retail-derived objects inside the repo (use build/ or a path outside it)")
    paths = sorted(glob.glob(os.path.join(a.in_dir, "*.o")), key=level_no)
    if not paths:
        sys.exit("no level objects in " + a.in_dir)
    os.makedirs(a.out_dir, exist_ok=True)
    levels = [Level(p) for p in paths]
    owners = {}
    for lv in levels:
        for h in {f[4] for f in lv.funcs}:
            owners[h] = owners.get(h, 0) + 1
    shared = {h for h, n in owners.items() if n > 1}
    common_bytes, common_funcs = write_common(levels, shared, a.out_dir)
    total = spec = data = 0
    for lv in levels:
        t = sum(f[3] for f in lv.funcs)
        dropped = write_level_code(lv, shared, a.out_dir)
        data += write_level_data(lv, a.out_dir)
        total += t
        spec += t - dropped
    print("levels: %d, level code summed: %.1f MB" % (len(levels), total / 1e6))
    print("common code (each function once): %.2f MB in %d functions" % (common_bytes / 1e6, common_funcs))
    print("level-specific code: %.2f MB" % (spec / 1e6))
    print("code to decompile: %.2f MB (was %.1f MB)" % ((spec + common_bytes) / 1e6, total / 1e6))
    print("level data (not deduplicated): %.1f MB" % (data / 1e6))
    if a.objdiff:
        update_objdiff(a.objdiff, levels)
        print("updated", a.objdiff)


if __name__ == "__main__":
    main()
