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
  <N>_<name>_data.o the level's own (non-zero, not shared) .data/.lit content
                   plus its lvl.* vtables, compacted
  common_data.o    .data/.lit content found in two or more overlays, once
  uninitialised.o  .bss and zero words of .data/.lit of every level, as two
                   zero-fill sections: nothing to decompile, only a size. Not
                   listed in objdiff.json unless --include-zero-fill.

Data has no function boundaries, so it is deduplicated by content: a 16-word
window (at least 8 words non-zero) that occurs in two or more overlays is shared.
Words that look like addresses are wildcards, because shared data holds pointers
that move with the overlay. Words at the edges of shared runs are approximate.
This is meant for progress numbers, not as a guide to where data sits in a build.

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
import argparse, glob, hashlib, io, json, os, re, struct, sys
import numpy as np
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
        elf = ELFFile(io.BytesIO(self.raw))
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


WIN, MIN_NZ = 16, 8
ADDR_MASK = 0xFFFFFFFF


def word_hashes(words):
    """Per-word hash with address-like words (0x100000..0x2000000, aligned) wildcarded."""
    m = words.copy()
    m[(words >= 0x00100000) & (words < 0x02000000) & ((words & 3) == 0)] = ADDR_MASK
    h = (m.astype(np.uint64) + np.uint64(1)) * np.uint64(0x9E3779B97F4A7C15)
    h ^= h >> np.uint64(32)
    return h * np.uint64(0xC2B2AE3D27D4EB4F)


def window_hashes(wh, nonzero):
    """Hash of every WIN-word window, plus a mask of windows with enough non-zero words."""
    n = len(wh) - WIN + 1
    if n <= 0:
        return np.zeros(0, np.uint64), np.zeros(0, bool)
    h = np.zeros(n, np.uint64)
    mult = np.uint64(1)
    for k in range(WIN):
        h += wh[k:k + n] * mult
        mult = np.uint64((int(mult) * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF)
    cs = np.concatenate(([0], np.cumsum(nonzero, dtype=np.int64)))
    return h, (cs[WIN:] - cs[:-WIN]) >= MIN_NZ


def cover(n, starts):
    """Mask of words covered by WIN-word windows starting at `starts`."""
    d = np.zeros(n + 1, np.int32)
    np.add.at(d, starts, 1)
    np.add.at(d, starts + WIN, -1)
    return np.cumsum(d[:n]) > 0


def split_data(levels):
    """-> (per-level {section: bytes}, common {section: bytes}, zero bytes per level, stats)."""
    own = [{} for _ in levels]
    common = {}
    zero = [0] * len(levels)
    stats = {"zero": 0, "specific": 0, "common": 0, "nonzero": 0}
    for name in (".data", ".lit"):
        arrs, nzs, hs, oks, lvl = [], [], [], [], []
        for li, lv in enumerate(levels):
            blob = next((d[6] for d in lv.data if d[1] == name), b"")
            a = np.frombuffer(blob[:len(blob) // 4 * 4], dtype="<u4")
            arrs.append(a)
            nz = a != 0
            nzs.append(nz)
            h, ok = window_hashes(word_hashes(a), nz)
            hs.append(h)
            oks.append(ok)
            lvl.append(np.full(len(h), li, np.int32))
        H = np.concatenate([h[o] for h, o in zip(hs, oks)])
        L = np.concatenate([l[o] for l, o in zip(lvl, oks)]).astype(np.uint64)
        pairs = np.unique(np.stack([H, L], 1), axis=0)          # distinct (window, level), sorted
        uh, first, cnt = np.unique(pairs[:, 0], return_index=True, return_counts=True)
        first_level = pairs[first, 1]
        for li, lv in enumerate(levels):
            a, nz, h, ok = arrs[li], nzs[li], hs[li], oks[li]
            starts = np.nonzero(ok)[0]
            pos = np.searchsorted(uh, h[starts])
            shared_w = cnt[pos] >= 2
            new_w = shared_w & (first_level[pos] == li)
            shared = cover(len(a), starts[shared_w]) & nz
            new = cover(len(a), starts[new_w]) & nz
            uniq = nz & ~shared
            out_c = a[new & shared]
            common.setdefault(name, []).append(out_c.tobytes())
            own[li][name] = a[uniq].tobytes()
            zero[li] += int((~nz).sum()) * 4
            stats["zero"] += int((~nz).sum()) * 4
            stats["nonzero"] += int(nz.sum()) * 4
            stats["specific"] += int(uniq.sum()) * 4
            stats["common"] += len(out_c) * 4
    return own, {k: b"".join(v) for k, v in common.items()}, zero, stats


def write_level_data(lv, own, out):
    secs, syms = [], []
    for name in (".data", ".lit"):
        blob = own.get(name, b"")
        if blob:
            secs.append((name, SHT_PROGBITS, SHF_ALLOC | SHF_WRITE, 16, blob, len(blob)))
    for _, name, nobits, flags, align, size, blob in lv.data:
        if name.startswith("lvl."):
            secs.append((name, SHT_PROGBITS, flags, align, blob, size))
    for k, sec in enumerate(secs, 1):
        syms.append((sec[0], 0, 0, 0x03, k))                 # STT_SECTION
    p = os.path.join(out, os.path.basename(lv.path)[:-2] + "_data.o")
    open(p, "wb").write(build_elf(lv.ehdr, secs, syms))
    return sum(sec[5] for sec in secs)


def write_common_data(ehdr, common, out):
    secs = [(n, SHT_PROGBITS, SHF_ALLOC | SHF_WRITE, 16, b, len(b)) for n, b in common.items() if b]
    syms = [(sec[0], 0, 0, 0x03, k) for k, sec in enumerate(secs, 1)]
    open(os.path.join(out, "common_data.o"), "wb").write(build_elf(ehdr, secs, syms))


def write_uninitialised(ehdr, bss, zero_words, out):
    flags = SHF_ALLOC | SHF_WRITE
    secs = [(".bss", SHT_NOBITS, flags, 16, None, bss), (".data_zero", SHT_NOBITS, flags, 16, None, zero_words)]
    syms = [(sec[0], 0, 0, 0x03, k) for k, sec in enumerate(secs, 1)]
    open(os.path.join(out, "uninitialised.o"), "wb").write(build_elf(ehdr, secs, syms))


def update_objdiff(path, levels, zero_fill=False):
    """Rewrite level units and categories in objdiff.json (frontbin units untouched)."""
    d = json.load(open(path))
    keep = [u for u in d["units"] if not u["name"].startswith("levels/")]
    # only the per-level code units (safe to re-run: skips common/_data/zero-fill units)
    old = {level_no(u["target_path"]): u for u in d["units"]
           if u["name"].startswith("levels/") and re.match(r"\d+_.*(?<!_data)\.o$", os.path.basename(u.get("target_path", "")))}
    cats = [c for c in d.get("progress_categories", [])
            if c["id"] in ("frontend", "singleplayer", "multiplayer")]
    cats += [{"id": "levels", "name": "Level code"},
             {"id": "common_level_code", "name": "Common level code"},
             {"id": "level_specific", "name": "Level-specific code"},
             {"id": "common_level_data", "name": "Common level data"},
             {"id": "level_data", "name": "Level-specific data"}]
    if zero_fill:
        cats.append({"id": "zero_fill", "name": "Zero-filled data (.bss, zeroed .data)"})
    units = []
    tdir = "build/objdiff/target/levels/"
    units.append({"name": "levels/common", "target_path": tdir + "common.o",
                  "metadata": {"progress_categories": ["levels", "common_level_code"]}})
    units.append({"name": "levels/common data", "target_path": tdir + "common_data.o",
                  "metadata": {"progress_categories": ["common_level_data"]}})
    if zero_fill:
        units.append({"name": "levels/zero-filled data", "target_path": tdir + "uninitialised.o",
                      "metadata": {"progress_categories": ["zero_fill"]}})
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
    ap.add_argument("--include-zero-fill", action="store_true",
                    help="also list uninitialised.o (.bss and zero words, ~61 MB) as a unit; off by default "
                         "because it has nothing to decompile and swamps the data total")
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
    own, common_data, zero, dstats = split_data(levels)
    bss = sum(d[5] for lv in levels for d in lv.data if d[1] == ".bss")
    write_common_data(levels[0].ehdr, common_data, a.out_dir)
    write_uninitialised(levels[0].ehdr, bss, sum(zero), a.out_dir)
    total = spec = data = 0
    for li, lv in enumerate(levels):
        t = sum(f[3] for f in lv.funcs)
        dropped = write_level_code(lv, shared, a.out_dir)
        data += write_level_data(lv, own[li], a.out_dir)
        total += t
        spec += t - dropped
    print("levels: %d, level code summed: %.1f MB" % (len(levels), total / 1e6))
    print("common code (each function once): %.2f MB in %d functions" % (common_bytes / 1e6, common_funcs))
    print("level-specific code: %.2f MB" % (spec / 1e6))
    print("code to decompile: %.2f MB (was %.1f MB)" % ((spec + common_bytes) / 1e6, total / 1e6))
    print("common data (each run once): %.2f MB" % (dstats["common"] / 1e6))
    print("level-specific data: %.2f MB (incl. lvl.* tables)" % (data / 1e6))
    print("zero-filled: %.1f MB .bss + %.1f MB zero words (was %.1f MB of data before)" % (
        bss / 1e6, dstats["zero"] / 1e6, (bss + dstats["zero"] + dstats["nonzero"]) / 1e6))
    if a.objdiff:
        update_objdiff(a.objdiff, levels, a.include_zero_fill)
        print("updated", a.objdiff)


if __name__ == "__main__":
    main()
