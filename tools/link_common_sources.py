#!/usr/bin/env python3
"""link_common_sources.py: build a level target from the shared level sources.

The shared level code (src/levels/common/, docs/common_level_c.md) is named
after its canonical owner. For the owner's own target (Veldin owns everything
it shares) those sources already carry the right addresses, so the target can
link them as they are instead of keeping a copy: each catalogued function
becomes its own source file in the target's link order.

    python tools/link_common_sources.py --target veldin [--exclude func_X ...]

For every catalogue entry the target owns (Target.level_overlay):

  * its source gets localdecomp:start/end markers around the function if it
    has none, so the tools see it as a one-function file like any other;
  * if the function can be a file of its own, its INCLUDE_ASM line goes, the
    range file is cut there, and targets/<t>/src_files.txt lists
    src/levels/common/<name>.c at its address, followed by a new range file
    for the rest. A function can stand alone when the next entry starts at its
    8-aligned end (objects are 8-aligned) and no TEXT_PADDING follows it;
  * text_parts.txt gets a single-function line with the catalogue's flags
    (flags_from's frontbin flags with its mode and assembler, exactly what
    build_common_c.py compiled) and a line restoring the range's flags after it.

Functions that can't stand alone are listed and left INCLUDE_ASM. It is
incremental: sources linked by an earlier run stay as they are, and only
catalogue entries that are still INCLUDE_ASM are linked, so run it again
after new matches. Run `python tools/split_text.py --refresh --target <t>`
and the build afterwards.
"""
import argparse, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles as sf  # noqa: E402
import build_text as bt  # noqa: E402

ENTRY_RE = re.compile(r'^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]*", (func_[0-9A-F]{8})\);', re.M)
COMMON = "src/levels/common"


def frontbin_flags(flags_from):
    """What try_func.flags_for gives on frontbin: localdecomp_flags, then text_parts."""
    fb = targets.TARGETS["frontbin"]
    for line in open(fb.path("localdecomp_flags")):
        f = line.split("#", 1)[0].split()
        if f and f[0] == flags_from:
            return f[1:]
    return list(bt.flags_for(bt.read_parts(fb.path("parts")), int(flags_from[5:], 16)))


def entry_flags(e):
    """build_common_c.py's flags for a catalogue entry (try_func.apply_overrides)."""
    fl = frontbin_flags(e["flags_from"])
    if e.get("mode"):
        fl = [f for f in fl if f != "-mno-split-addresses"]
        if e["mode"] == "N":
            fl.append("-mno-split-addresses")
    if e.get("assembler"):
        fl = [f for f in fl if f not in ("@ps2as", "@newas")]
        if e["assembler"] != "default":
            fl.append("@" + e["assembler"])
    for sym, size in (e.get("early_extern_sizes") or {}).items():
        fl.append("@extern:%s=%d" % (sym, size))
    if e.get("gp_size") is not None:
        g = "-G%d" % e["gp_size"]
        fl = [g if re.fullmatch(r"-G\d+", f) else f for f in fl]
        if g not in fl:
            fl.append(g)
    return fl


def add_markers(path, name):
    """Wrap a standalone common source's code in localdecomp markers. True if changed."""
    text = open(path, encoding="utf-8").read()
    if "localdecomp:start " + name in text:
        return False
    nl = "\r\n" if "\r\n" in text else "\n"
    body = text.replace("\r\n", "\n")
    head = '#include "common.h"\n'
    rest = body[len(head):] if body.startswith(head) else body
    new = head + "\n/* localdecomp:start %s */\n%s\n/* localdecomp:end %s */\n" % (name, rest.strip("\n"), name)
    open(path, "w", encoding="utf-8", newline="").write(new.replace("\n", nl))
    return True


NAME_RE = re.compile(r"\b((?:func|D|jtbl)_([0-9A-Fa-f]{6,8})(?:_\w+)?)\b")
LABEL_RE = re.compile(r"^\s*(?:glabel|dlabel|alabel|jlabel)\s+(\w+)", re.M)


def add_symbols(T, sources, defined_here):
    """Every func_/D_/jtbl_ name the linked sources use gets an address in the
    target's symbol file (build_common_c.py read it off the name), unless the
    build defines it: a label in the target's assembly or a linked function."""
    path = T.path("symbols_resolved")
    text = open(path, encoding="utf-8").read()
    have = set(re.findall(r"^\s*(\w+)\s*=", text, re.M))
    for d, _, fs in os.walk(T.path("asm_root")):
        for f in fs:
            if f.endswith(".s"):
                have |= set(LABEL_RE.findall(open(os.path.join(d, f), errors="replace").read()))
    have |= defined_here
    new = {}
    for rel in sources:
        for name, hexaddr in NAME_RE.findall(open(os.path.join(ROOT, rel), encoding="utf-8").read()):
            if name not in have:
                new[name] = int(hexaddr, 16)
    if new:
        nl = "\r\n" if "\r\n" in text else "\n"
        add = "".join("%s = 0x%08X;%s" % (n, new[n], nl) for n in sorted(new))
        open(path, "w", encoding="utf-8", newline="").write(text.rstrip("\r\n") + nl + add)
    return len(new)


def drop_table_entries(T, names):
    """A linked function's div.s nops and sq saves come from the common-level
    tables (tools/), which build_common_c.py proved its bytes with.
    The target's own tables (generated from its assembly) would add them a
    second time where the C already produces them, so its entries go."""
    n = 0
    for attr in ("divs_nops", "sq_ra_funcs"):
        path = T.path(attr)
        if not os.path.exists(path):
            continue
        lines = open(path, encoding="utf-8").read().split("\n")
        keep = [l for l in lines if l.split("#", 1)[0].split()[:1] not in [[x] for x in names]]
        n += len(lines) - len(keep)
        open(path, "w", encoding="utf-8", newline="").write("\n".join(keep))
    return n


def main():
    T = targets.from_argv()
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--exclude", nargs="*", default=[], help="leave these INCLUDE_ASM")
    a = ap.parse_args()
    overlay = getattr(T, "level_overlay", None)
    if not overlay:
        sys.exit("%s has no level_overlay in tools/targets.py" % T.name)
    files = sf.read_file_list()
    already = {os.path.basename(rel)[:-2] for rel, _ in files if rel.startswith(COMMON + "/")}

    cat = json.load(open(os.path.join(targets.ROOT, "tools", "common_c.json"), encoding="utf-8"))
    own = {e["name"]: e for e in cat
           if e["overlay"] == overlay and e["name"] not in a.exclude and e["name"] not in already}

    # every entry of the target in address order, and which file holds it
    entries = []  # (addr, name, rel)
    for rel, start in files:
        if rel.startswith(COMMON + "/"):
            entries.append((start, os.path.basename(rel)[:-2], rel))
            continue
        text = sf.read_source(rel)
        for m in ENTRY_RE.finditer(text):
            entries.append((int(m.group(2)[5:], 16), m.group(2), rel))
        # functions already in C in the range file
        for m in re.finditer(r"localdecomp:start (func_[0-9A-F]{8})", text):
            entries.append((int(m.group(1)[5:], 16), m.group(1), rel))
    entries.sort()
    nxt = {entries[i][1]: entries[i + 1][0] for i in range(len(entries) - 1)}

    standalone, skipped = set(), {}
    for name, e in own.items():
        addr, size = int(e["address"], 16), int(e["size"])
        end8 = (addr + size + 7) & ~7
        if name not in nxt:
            skipped[name] = "last entry"
        elif addr % 8:
            skipped[name] = "starts off the 8-byte file alignment (0x%X)" % addr
        elif nxt[name] != end8:
            skipped[name] = "padding after it (next entry 0x%X, end 0x%X)" % (nxt[name], addr + size)
        else:
            standalone.add(name)

    parts = bt.read_parts(T.path("parts"))
    new_files, new_parts = [], {}
    origin = {}  # range file -> the original range file it was cut from
    for rel, start in files:
        if rel.startswith(COMMON + "/"):
            new_files.append((rel, start, None, None))  # linked by an earlier run
            continue
        text = sf.read_source(rel)
        prelude, _, chunks = sf.split_file(text)
        seg = None  # (rel, start, [chunk bodies])
        def flush():
            # a piece with no entry and no C left (only blank text after a cut) isn't a file
            if seg and any(ENTRY_RE.search(b) or "localdecomp:start" in b for b in seg[2]):
                new_files.append((seg[0], seg[1], seg[3], seg[2]))
                origin.setdefault(seg[0], rel)
        seg = [rel, start, [], prelude]
        for caddr, _, body in chunks:
            m = ENTRY_RE.search(body)
            name = m.group(2) if m else None
            if name in standalone:
                if re.search(r"TEXT_PADDING|INCLUDE_RODATA", body):
                    skipped[name] = "INCLUDE_RODATA/TEXT_PADDING with it"
                    standalone.discard(name)
                    seg[2].append(body)
                    continue
                flush()
                addr = int(name[5:], 16)
                new_files.append(("%s/%s.c" % (COMMON, name), addr, None, None))
                new_parts[addr] = entry_flags(own[name])
                after = nxt[name]
                if after not in new_parts:
                    new_parts.setdefault(after, list(bt.flags_for(parts, after)))
                seg = ["%s/%06X.c" % (T.units[0].src_dir, after), after, [], '#include "common.h"\n\n']
            else:
                seg[2].append(body)
        flush()

    # write the range files (the original paths keep their text up to the first cut)
    keep = set()
    for rel, start, prelude, bodies in new_files:
        if bodies is None:
            continue
        keep.add(rel)
        out = prelude + "".join(bodies)
        open(os.path.join(ROOT, rel), "w", newline="").write(out.replace("\n", "\r\n"))
    moved = {}
    for rel, _ in files:
        # a range file whose functions are all common sources now; never a common source itself
        if rel not in keep and not rel.startswith(COMMON + "/"):
            os.remove(os.path.join(ROOT, rel))
            # its data placements go to the first piece of it that is still a file
            pieces = [r for r, _, _, b in new_files if b is not None and origin.get(r) == rel]
            if pieces:
                moved[rel] = pieces[0]
    if moved and getattr(T, "data_split", None):
        split = open(T.path("data_split"), newline="").read()
        for old, new in moved.items():
            split = re.sub(r"(?<=\s)%s(?=\s)" % re.escape(old), new, split)
        open(T.path("data_split"), "w", newline="").write(split)
    marked = sum(add_markers(os.path.join(ROOT, rel), os.path.basename(rel)[:-2])
                 for rel, _, _, b in new_files if b is None and os.path.basename(rel)[:-2] in standalone)

    # file list
    hdr = [l.rstrip("\r\n") for l in open(T.path("files")) if l.startswith("#")]
    lines = hdr + ["%s %08X" % (rel, start) for rel, start, _, _ in new_files]
    open(T.path("files"), "w", newline="").write("\r\n".join(lines) + "\r\n")

    # flags: the single-function lines and the restores, in address order
    text = [l.rstrip("\r\n") for l in open(T.path("parts"))]
    head = [l for l in text if not l.startswith("0x")]
    body = {int(l.split()[0], 16): l for l in text if l.startswith("0x")}
    for addr, fl in new_parts.items():
        if addr in body and not any(f for f in own.values() if int(f["address"], 16) == addr):
            continue  # a range's own line is already there
        tag = "   # common source" if any(int(f["address"], 16) == addr for f in own.values()) else ""
        body[addr] = "0x%08X     %s%s" % (addr, " ".join(fl), tag)
    open(T.path("parts"), "w", newline="").write("\r\n".join(head + [body[k] for k in sorted(body)]) + "\r\n")

    linked = [rel for rel, _, _, b in new_files if b is None and os.path.basename(rel)[:-2] in standalone]
    nsym = add_symbols(T, linked, {os.path.basename(r)[:-2] for r in linked})
    ntab = drop_table_entries(T, {os.path.basename(r)[:-2] for r in linked})

    print("%d common functions linked from %s/ (%d sources given markers, %d symbol addresses added, "
          "%d target table entries dropped), %d left INCLUDE_ASM"
          % (len(standalone), COMMON, marked, nsym, ntab, len(skipped)))
    why = {}
    for n, r in skipped.items():
        why.setdefault(r.split(" (")[0], []).append(n)
    for r, ns in sorted(why.items(), key=lambda x: -len(x[1])):
        print("  %4d %s: %s" % (len(ns), r, " ".join(sorted(ns)[:6]) + (" ..." if len(ns) > 6 else "")))


if __name__ == "__main__":
    main()
