#!/usr/bin/env python3
"""
fix_short_loops.py -- stop ee-as from padding short loops, in place.

ee-as with -mcpu=5900 applies the R5900 short-loop workaround: when a
backward branch closes a loop of only a few instructions, it inserts an
extra `nop` before the branch. The original game code does not have those
nops, so every such loop in an INCLUDE_ASM function came out 4 bytes longer
(8 after function alignment), shifting every later function. Seen in the
full-build drift check as, e.g. retail 0x37D468 `0481FFFB bgez $4, .L0037D458`
vs build `00000000 / 0481FFFA`.

Fix: write the loop-closing branch as a raw `.word` of its original
encoding. The assembler only pads real branch instructions, and a `.word` is
data to it, so no nop is added. The encoding is PC-relative, so it stays
correct as long as the loop body assembles to the same bytes (which it has
to anyway for the function to match). Same trick fix_quadword_ops.py uses.

Scope: branch instructions whose target is a `.L<VADDR>`, `L<VADDR>` or
`func_<VADDR>` (alabel alternate entry) label at most
MAX_BACK bytes BEFORE the branch. Everything else is left alone.

Safety: the original encoding comes from spimdisasm's line comment
(`/* ROMOFF VADDR WORD_LE */`). Before rewriting, the script checks that the
16-bit offset in that word really points at the label. If any line in a file
fails that check, the file is left untouched and the problem is reported.

Run after fix_reg_names.py:
    python fix_short_loops.py asm
Idempotent: already-converted lines are no longer branch instructions.
"""

import re
import sys
from pathlib import Path

MAX_BACK = 0x40  # generous; the hardware rule is loops of <= 6 instructions

LINE_RE = re.compile(
    r"^(?P<indent>\s*)/\*\s*(?P<rom>[0-9A-Fa-f]+)\s+(?P<vaddr>[0-9A-Fa-f]{8})\s+(?P<word>[0-9A-Fa-f]{8})\s*\*/"
    r"\s*(?P<mn>b[a-z0-9]*)\s+(?P<ops>[^\n]*?,\s*|)(?P<label>(?:\.L|L|func_)(?P<target>[0-9A-Fa-f]{8}))\s*$"
)


def process_file(path, stats, errors):
    text = path.read_text(encoding="utf-8", errors="surrogateescape")
    lines = text.splitlines(keepends=True)
    out = []
    local = 0
    for i, line in enumerate(lines, 1):
        body = line.rstrip("\r\n")
        eol = line[len(body):]
        m = LINE_RE.match(body)
        if not m or m.group("mn") == "break":
            out.append(line)
            continue
        pc = int(m.group("vaddr"), 16)
        target = int(m.group("target"), 16)
        if not (0 <= pc - target <= MAX_BACK):
            out.append(line)
            continue
        word = int.from_bytes(bytes.fromhex(m.group("word")), "little")
        expected = ((target - (pc + 4)) >> 2) & 0xFFFF
        if (word & 0xFFFF) != expected:
            errors.append(f"{path}:{i}: original word 0x{word:08X} offset doesn't point at "
                          f"{m.group('label')}: {body.strip()!r}")
            return False
        out.append(f"{m.group('indent')}/* {m.group('rom')} {m.group('vaddr')} {m.group('word')} */  "
                   f".word 0x{word:08X} /* {m.group('mn')} {m.group('ops')}{m.group('label')} -- raw so ee-as can't pad the short loop */"
                   f"{eol}")
        local += 1
    if local:
        path.write_text("".join(out), encoding="utf-8", errors="surrogateescape")
        stats["branches"] += local
        return True
    return False


def main(argv):
    if len(argv) < 2:
        print(f"usage: {argv[0]} <file_or_dir> ...", file=sys.stderr)
        return 2
    targets = []
    for p in map(Path, argv[1:]):
        targets.extend(p.rglob("*.s") if p.is_dir() else [p] if p.is_file() else [])
    stats = {"branches": 0}
    errors = []
    changed = sum(process_file(f, stats, errors) for f in targets)
    print(f"fix_short_loops: scanned {len(targets)} file(s), modified {changed}, "
          f"short-loop branches converted: {stats['branches']}")
    if errors:
        print(f"\n{len(errors)} file(s) LEFT UNTOUCHED:", file=sys.stderr)
        for e in errors:
            print("  " + e, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
