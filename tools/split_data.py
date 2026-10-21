#!/usr/bin/env python3
"""split_data.py: link source files' own data at its retail addresses.

A level overlay's data isn't grouped by kind as frontbin's is: every original
source file's read-only data (switch jump tables, constant tables), small data
(.sdata: the file's small variables and constants, which code reaches through
$gp) and float literals sit at that file's place in link order, between other
files' data (docs/veldin.md, "Per-file data"). So a data segment is assembled
whole from asm/, and a source file that emits data of its own needs that data
cut out of the segment at the address where retail has it.

The target's table (Target.data_split, e.g. targets/veldin/data_split.txt) says
which file provides which range:

    # section   address     source file
    .rodata     0x002BF270  src/veldin/3DF888.c
    .sdata      0x001DE57C  src/veldin/3ADAC0.c

Each row places the file's whole SECTION (.rodata, .lit4, .lit8, .sdata,
.sbss, .data or .bss) at ADDRESS. tools/build_text.py renames that section in
the file's object to .split.SECTION.STEM (.split.rodata.3DF888), so it stays
apart when all objects are linked into one; this script then, after build_text.py:

  1. reads each placed section's size and alignment from the unit object
     (build/veldin/src/text.c.o) and checks that it fits: aligned, inside one
     data segment (Target.data_segments), not overlapping another row;
  2. writes <build>/data/<segment>.s: the segment's retail bytes in pieces,
     one section per gap between placed ranges, with the segment's labels
     (the `dlabel`s of asm/.../data/<segment>.data.s) at their addresses, and
     assembles it;
  3. writes <build>/data/<segment>.ld, the segment's output section for the
     linker script (INCLUDEd by linker_scripts/veldin.ld): the pieces and the
     placed sections in address order, plus PROVIDE(label = address) for the
     labels inside placed ranges (asm code may still name them);
  4. fails if some source emits data that no row places (the linker script
     discards everything it doesn't name, so it would vanish silently).

With an empty table each segment is one piece: the same bytes as before.

    python tools/split_data.py --target veldin --as C:/.../bin/ee-as.exe [--runner wibo]

Run by `make check-veldin` and tools/build.py; it needs the retail ELF in
the retail ELF (the pieces are its bytes, as the asm/ files are).
"""
import argparse, os, re, shlex, struct, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402

# sections a row can place
DATA_SECTIONS = (".rodata", ".lit4", ".lit8", ".sdata", ".sbss", ".data", ".bss")
# sections a code object may have that are not data
NOT_DATA = (".text", ".reginfo", ".mdebug", ".comment", ".pdr")
ASFLAGS = ["-I", "include", "-EL", "-mips3", "-mcpu=5900", "-mabi=eabi"]


def die(msg):
    sys.exit("split_data: " + msg)


def stem(rel):
    return os.path.splitext(os.path.basename(rel))[0]


def placed_name(section, rel):
    """The name build_text.py gives a placed section in its file's object:
    .split.rodata.3DF888. (Not .rodata.3DF888: ld -r's default script folds
    .sdata.* into .sdata.)"""
    return ".split%s.%s" % (section, stem(rel))


def read_table(t):
    """The target's rows as [(section, address, file)], by address. Empty when
    the target has no table."""
    if not getattr(t, "data_split", None):
        return []
    path = t.path("data_split")
    if not os.path.exists(path):
        return []
    rows, seen = [], set()
    for n, line in enumerate(open(path), 1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        f = line.split()
        if len(f) != 3 or f[0] not in DATA_SECTIONS or not re.fullmatch(r"(0x)?[0-9A-Fa-f]+", f[1]):
            die("%s:%d: expected `SECTION ADDRESS FILE` with SECTION one of %s"
                % (t.data_split, n, ", ".join(DATA_SECTIONS)))
        rel = f[2].replace("\\", "/")
        if (f[0], rel) in seen:
            die("%s:%d: %s of %s is placed twice (a section is placed whole)" % (t.data_split, n, f[0], rel))
        seen.add((f[0], rel))
        rows.append((f[0], int(f[1], 16), rel))
    return sorted(rows, key=lambda r: r[1])


def sections_by_file(t):
    """{source file: [sections placed from it]} for tools/build_text.py."""
    out = {}
    for sec, _, rel in read_table(t):
        out.setdefault(rel, []).append(sec)
    return out


def rename_sections(ld, obj, rel, sections, runner=None):
    """Rename the placed sections of one file's object (ld -r with a small
    script), so they keep their own names in the unit object."""
    script = obj + ".split.x"
    lines = ["SECTIONS", "{", "    .text 0 : { *(.text) }"]
    for sec in sections:
        lines.append("    %s 0 : { *(%s) }" % (placed_name(sec, rel), sec))
    lines.append("}")
    with open(script, "w", newline="\n") as f:
        f.write("\n".join(lines) + "\n")
    raw = obj + ".unsplit.o"
    os.replace(obj, raw)
    cmd = ([runner] if runner else []) + [ld, "-r", "-T", script, "-o", obj, raw]
    if subprocess.run(cmd).returncode != 0:
        die("ld -r -T %s failed" % script)
    os.remove(raw)


# --- ELF (32-bit little-endian) ---------------------------------------------

def elf_sections(path):
    """[(name, type, flags, size, align, offset)] of an ELF32 LE file."""
    b = open(path, "rb").read()
    if b[:4] != b"\x7fELF":
        die("%s is not an ELF file" % path)
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<3H", b, 0x2E)
    hdrs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    stroff = hdrs[shstrndx][4]

    def name(o):
        e = b.index(b"\0", stroff + o)
        return b[stroff + o:e].decode()
    return [(name(h[0]), h[1], h[2], h[5], h[8], h[4]) for h in hdrs]


SHT_PROGBITS, SHT_NOBITS = 1, 8


def data_sections(path):
    """{name: (size, align)} of the allocated PROGBITS/NOBITS sections."""
    out = {}
    for name, typ, flags, size, align, _ in elf_sections(path):
        if typ in (SHT_PROGBITS, SHT_NOBITS) and flags & 2:  # SHF_ALLOC
            out[name] = (size, max(align, 1))
    return out


# --- the split ---------------------------------------------------------------

LABEL_RE = re.compile(r"^dlabel\s+(\S+)")
ADDR_RE = re.compile(r"/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\b")


def segment_labels(path):
    """{address: [label, ...]} of a splat data .s (dlabel lines, at the address
    of the next line that has one)."""
    out, pending = {}, []
    for line in open(path):
        m = LABEL_RE.match(line)
        if m:
            pending.append(m.group(1))
            continue
        if pending:
            m = ADDR_RE.search(line)
            if m:
                out.setdefault(int(m.group(1), 16), []).extend(pending)
                pending = []
    return out


def piece_asm(data, vram, labels):
    """Assembly for retail bytes `data` that load at `vram`, with labels."""
    out = []
    i, n = 0, len(data)
    words = vram % 4 == 0   # .word auto-aligns within the section: only when the piece starts aligned
    while i < n:
        for lab in labels.get(vram + i, ()):
            out.append(".global %s\n%s:" % (lab, lab))
        # up to the next label, at most a line's worth
        nxt = min([a - vram for a in labels if vram + i < a < vram + n] + [n])
        if words and i % 4 == 0 and nxt - i >= 4:
            k = (nxt - i) // 4
            for j in range(0, k, 8):
                vals = struct.unpack_from("<%dI" % min(8, k - j), data, i + 4 * j)
                out.append("    .word " + ", ".join("0x%08X" % v for v in vals))
            i += 4 * k
        else:
            m = min(nxt, (i // 4 + 1) * 4 if words else nxt)
            m = max(m, i + 1)
            for j in range(i, m, 16):
                out.append("    .byte " + ", ".join("0x%02X" % c for c in data[j:min(m, j + 16)]))
            i = m
    return out


def main():
    t = targets.from_argv()
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--as", dest="as_", required=True, help="ee-as.exe")
    ap.add_argument("--runner", default=None, help="wibo, to run the Windows assembler on Linux/macOS")
    ap.add_argument("--unit", default=None, help="the code unit whose object holds the placed sections")
    a = ap.parse_args()
    segs = getattr(t, "data_segments", None)
    if not segs:
        die("%s has no data_segments in tools/targets.py" % t.name)
    unit = t.unit(a.unit) if a.unit else t.units[0]
    unit_obj = t.obj(unit)
    rows = read_table(t)

    # 1. sizes and checks
    have = data_sections(os.path.join(ROOT, unit_obj))
    placed = []   # (address, size, section in the unit object, row)
    for sec, addr, rel in rows:
        name = placed_name(sec, rel)
        if name not in have:
            die("%s: %s has no %s (no section %s in %s); remove its row or rebuild"
                % (t.data_split, rel, sec, name, unit_obj))
        size, align = have[name]
        if addr % align:
            die("%s: %s of %s is %d-byte aligned, but 0x%08X is not" % (t.data_split, sec, rel, align, addr))
        placed.append((addr, size, name, (sec, addr, rel)))
    for (a1, s1, _, r1), (a2, _, _, r2) in zip(placed, placed[1:]):
        if a1 + s1 > a2:
            die("%s: %s of %s (0x%08X..0x%08X) overlaps %s of %s at 0x%08X"
                % (t.data_split, r1[0], r1[2], a1, a1 + s1, r2[0], r2[2], a2))

    # 4. data nobody places
    names = {p[2] for p in placed}
    stray = {n: v for n, v in have.items() if n not in names and n not in NOT_DATA and v[0]}
    if stray:
        import srcfiles
        who = []
        for rel, start in srcfiles.read_file_list():
            o = os.path.join(ROOT, t.workdir(unit), stem(rel) + ".o")
            if not unit.contains(start) or not os.path.exists(o):
                continue
            for n, (size, _) in data_sections(o).items():
                if size and n not in NOT_DATA and n not in names:
                    who.append("%s: %s (0x%X bytes)" % (rel, n, size))
        die("sources emit data that %s doesn't place (the link would discard it):\n  %s\n"
            "Add a row `SECTION ADDRESS FILE` for each (docs/veldin.md, \"Per-file data\")."
            % (t.data_split, "\n  ".join(who or ["%s (0x%X bytes)" % (n, v[0]) for n, v in stray.items()])))

    # 2./3. pieces and linker fragments, per segment
    retail = open(t.path("elf"), "rb").read()
    outdir = os.path.join(t.build_dir, "data")
    os.makedirs(os.path.join(ROOT, outdir), exist_ok=True)
    used = set()
    for seg, (rom, rom_end, vram) in segs.items():
        end = vram + rom_end - rom
        mine = [p for p in placed if vram <= p[0] < end]
        for p in mine:
            if p[0] + p[1] > end:
                die("%s: %s of %s runs past the end of segment %s" % (t.data_split, p[3][0], p[3][2], seg))
            used.add(p[3])
        labels = segment_labels(os.path.join(ROOT, t.asm_root, "data", seg + ".data.s"))
        spath = os.path.join(outdir, seg + ".s").replace("\\", "/")
        opath = os.path.join(outdir, seg + ".o").replace("\\", "/")
        asm = ["# Generated by tools/split_data.py from the retail bytes of segment %s" % seg,
               "# and the labels of %s/data/%s.data.s. Do not edit." % (t.asm_root, seg)]
        body = []          # linker statements for the output section
        provide = []
        pos, k, starts = vram, 0, {}
        for addr, size, name, row in mine + [(end, 0, None, None)]:
            if addr > pos:
                piece = ".split_%s_%d" % (seg, k)
                asm.append('.section %s, "wa"' % piece)
                inside = {a: v for a, v in labels.items() if pos <= a < addr}
                asm.extend(piece_asm(retail[rom + pos - vram:rom + addr - vram], pos, inside))
                body.append("%s(%s);" % (opath, piece))
                starts[piece] = pos
                k += 1
            if name:
                body.append("%s(%s);   /* %s %s */" % (unit_obj.replace("\\", "/"), name, row[0], row[2]))
                for a2, labs in sorted(labels.items()):
                    if addr <= a2 < addr + size:
                        provide.extend("PROVIDE(%s = 0x%08X);" % (lab, a2) for lab in labs)
                pos = addr + size
        with open(os.path.join(ROOT, spath), "w", newline="\n") as f:
            f.write("\n".join(asm) + "\n")
        cmd = ([a.runner] if a.runner else []) + shlex.split(a.as_, posix=False) + ASFLAGS + ["-o", opath, spath]
        print(" ".join(cmd), flush=True)
        if subprocess.run(cmd, cwd=ROOT).returncode != 0:
            die("assembling %s failed" % spath)
        # a piece's alignment must not move it from where the previous range ends
        for name, (size, align) in data_sections(os.path.join(ROOT, opath)).items():
            if name in starts and starts[name] % align:
                die("%s in %s is %d-byte aligned but starts at 0x%08X" % (name, opath, align, starts[name]))
        ld = ["/* Generated by tools/split_data.py from %s: segment %s, with the" % (t.data_split or "(no table)", seg),
              "   source files' placed data at its retail addresses. Do not edit. */",
              "SECTIONS", "{",
              "    .%s 0x%08X : AT(0x%08X)" % (seg, vram, rom), "    {"]
        ld += ["        " + s for s in body + provide]
        ld += ["    }", "}"]
        with open(os.path.join(ROOT, outdir, seg + ".ld"), "w", newline="\n") as f:
            f.write("\n".join(ld) + "\n")
        print("%s: %d piece(s), %d placed section(s)" % (seg, k, len(mine)))
    for row in [p[3] for p in placed if p[3] not in used]:
        die("%s: %s of %s at 0x%08X is in no data segment (%s)"
            % (t.data_split, row[0], row[2], row[1], ", ".join(segs)))


if __name__ == "__main__":
    main()
