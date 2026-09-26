#!/usr/bin/env python3
"""migrate_jtbls.py: move switch jump tables out of the data blob into text.c.

Retail frontbin keeps every switch jump table in one block at the start of
.data (0x317FE0-0x318CB0), in the same order as the functions that use them.
That block is simply every source file's read-only data concatenated in
link order: gcc writes jump tables after a `.rdata` directive (the section
the assembler calls .rodata) with `.align 4`, so they are 16-byte aligned,
sorted by function address, and fenced by the linker's 0xCDCDCDCD fill on
both sides.

As long as the tables sat inside asm/data/data.data.s, a function with a
`switch` could never be written in C: gcc emits the table into text.c's
.rodata, which the linker put in the wrong place. This script makes text.c own its
tables, so C and asm functions can be mixed freely:

  1. every jtbl_XXXXXXXX is cut out of asm/data/data.data.s into
     asm/nonmatchings/text/rodata/jtbl_XXXXXXXX.s;
  2. the data blob is split into asm/data/data_a.data.s (before the block)
     and asm/data/data_b.data.s (after it);
  3. each jump table is pulled into text.c with INCLUDE_RODATA right after
     its function's INCLUDE_ASM, so text.c.o(.rodata) holds all tables in
     function order;
  4. the jtbl_ entries are removed from symbol_addrs_resolved.txt (the
     symbols are now defined by text.c.o).

The linker script then places build/src/text.c.o(.rodata) between the two
halves (see linker_scripts/frontbin.ld). When a function becomes C, delete
its INCLUDE_RODATA line along with the INCLUDE_ASM: gcc's own table lands in
the same place.

Run once from the repo root: python tools/migrate_jtbls.py
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(ROOT, "asm", "data", "data.data.s")
RODIR = os.path.join(ROOT, "asm", "nonmatchings", "text", "rodata")
TEXT_C = os.path.join(ROOT, "src", "text.c")
SYMS = os.path.join(ROOT, "symbol_addrs_resolved.txt")


def main():
    if not os.path.exists(DATA):
        sys.exit("asm/data/data.data.s not found (already migrated?)")
    lines = open(DATA).read().split("\n")
    # Blocks start at "nonmatching NAME" lines.
    starts = [i for i, l in enumerate(lines) if l.startswith("nonmatching ")]
    header = lines[:starts[0]]
    blocks = []
    for k, i in enumerate(starts):
        j = starts[k + 1] if k + 1 < len(starts) else len(lines)
        blocks.append((lines[i].split()[1], lines[i:j]))
    first = next(k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_"))
    last = max(k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_"))
    if any(not n.startswith("jtbl_") for n, _ in blocks[first:last + 1]):
        sys.exit("non-jtbl data inside the jump table block; aborting")

    # The last table's block also holds the linker's 0xCD fill that follows
    # the whole .rdata block. The fill belongs to data_b, not the table.
    name, body = blocks[last]
    cut = next((i for i, l in enumerate(body) if "0xCDCDCDCD" in l), None)
    tail = []
    if cut is not None:
        tail = ["", "/* linker fill after .rdata (0xCD) */"] + body[cut:]
        blocks[last] = (name, body[:cut])

    os.makedirs(RODIR, exist_ok=True)
    tables = []
    for name, body in blocks[first:last + 1]:
        out = [".align 4", ""]
        for l in body:
            l = l.replace(".word func_0 ", ".word 0x00000000 ").rstrip()
            if l.rstrip().endswith(".word func_0"):
                l = l.replace(".word func_0", ".word 0x00000000")
            out.append(l)
        open(os.path.join(RODIR, name + ".s"), "w").write("\n".join(out).rstrip() + "\n")
        tables.append(name)

    def write(path, blks, extra=()):
        text = "\n".join(header) + "\n"
        text += "\n".join("\n".join(b) for _, b in blks)
        text += "\n".join(extra)
        open(path, "w").write(text.rstrip() + "\n")

    write(os.path.join(ROOT, "asm", "data", "data_a.data.s"), blocks[:first])
    b_blocks = blocks[last + 1:]
    write(os.path.join(ROOT, "asm", "data", "data_b.data.s"),
          [], extra=tail + [""] + ["\n".join(b) for _, b in b_blocks])
    os.rename(DATA, DATA + ".premigrate")

    # Which function uses which table.
    users = {}
    asmdir = os.path.join(ROOT, "asm", "nonmatchings", "text")
    for f in sorted(os.listdir(asmdir)):
        if f.endswith(".s"):
            for t in sorted(set(re.findall(r"jtbl_[0-9A-F]{8}", open(os.path.join(asmdir, f)).read()))):
                users.setdefault(f[:-2], []).append(t)
    missing = set(tables) - {t for ts in users.values() for t in ts}
    if missing:
        sys.exit(f"tables with no user: {sorted(missing)}")

    src = open(TEXT_C, newline="").read()
    nl = "\r\n" if "\r\n" in src else "\n"  # keep text.c's line endings
    for func, ts in users.items():
        pat = re.compile(r'(INCLUDE_ASM\("asm/nonmatchings/text",\s*%s\);)' % func)
        if not pat.search(src):
            sys.exit(f"{func} uses {ts} but is not INCLUDE_ASM in text.c; add its table by hand")
        inc = "".join(f'{nl}INCLUDE_RODATA("asm/nonmatchings/text/rodata", {t});' for t in ts)
        src = pat.sub(lambda m: m.group(1) + inc, src, count=1)
    open(TEXT_C, "w", newline="").write(src)

    syms = [l for l in open(SYMS).read().split("\n") if not re.match(r"\s*jtbl_\w+\s*=", l)]
    open(SYMS, "w").write("\n".join(syms))
    print(f"moved {len(tables)} jump tables for {len(users)} functions")


if __name__ == "__main__":
    main()
