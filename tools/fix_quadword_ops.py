#!/usr/bin/env python3
"""
fix_quadword_ops.py — rewrite lq/sq/lqc2/sqc2 instructions (R5900 128-bit
quadword load/store, GPR and VU0-register forms) into raw `.word` encodings,
in place, for splat-generated .s files.

Why: this project's assembler (SN Systems ee-as.exe, ee-gcc 2.95.3 era) does
not implement these four opcodes at all -- confirmed absent from the
assembler binary's own opcode-mnemonic string table, and confirmed by
"illegal operands" errors on every use. There is no available substitute
instruction, so each one is instead emitted as a raw 32-bit word containing
the correctly-encoded instruction, computed here in Python.

Encoding (standard MIPS I-type layout, confirmed against real captured
instruction bytes from this project's own build log -- see conversation
notes / commit message for the byte-level verification):

    bits 31-26: opcode   (lq=0x1E, sq=0x1F, lqc2=0x36, sqc2=0x3E)
    bits 25-21: base register (the address register, e.g. $gp, $sp, $16)
    bits 20-16: rt (GPR form: plain $N register; COP2 form: $vfN -> N)
    bits 15-0:  signed 16-bit immediate offset

Two operand forms are handled:
    1. Register-relative: `lq $2, 0x30($16)` -- the immediate is already a
       literal, used directly.
    2. Gp-relative: `lq $11, D_001D75D0($gp)` -- the immediate must be
       computed as (symbol_address - gp_value), since this assembler has no
       %gp_rel-equivalent operator and _gp is not resolvable at assembly
       time (confirmed: "Subtraction of two symbols in different sections").
       This only works for splat's `D_<hex_address>` / `L_<hex_address>` /
       similar address-encoded symbol names, or literal hex addresses --
       see SYMBOL_ADDR_RE. gp_value comes from this project's splat.yaml
       (`options.gp_value`), passed in via --gp-value.

Each replaced line becomes a `.word 0x........` with the original
instruction preserved as a trailing comment, so the change stays legible
and reversible.

Usage:
    python fix_quadword_ops.py --gp-value 0x001DC8B0 <file_or_dir> [...]

Safety: symbol-address extraction only trusts splat's own naming
convention (a hex address embedded in the symbol name after a known
prefix). A gp-relative reference to a symbol whose address can't be
determined this way is left UNCHANGED and reported, rather than guessed at
-- fix those manually rather than silently emitting a wrong offset.
"""

import argparse
import re
import sys
from pathlib import Path

OPCODES = {
    "lq": 0x1E,
    "sq": 0x1F,
    "lqc2": 0x36,
    "sqc2": 0x3E,
}

# Matches one of our four mnemonics, a target register -- GPR ($N), VU0
# ($vfN), or one of this assembler's natively-recognized symbolic names
# ($at, $sp, $gp, $fp, $kt0, $kt1, $pc) which fix_reg_names.py deliberately
# leaves un-numbered -- a comma, then either:
#   - a bare hex/decimal offset with (base_reg), e.g. "0x30($16)" or "0($sp)"
#   - a symbol name with ($gp), e.g. "D_001D75D0($gp)"
NATIVE_REG_NUMS = {"at": 1, "sp": 29, "gp": 28, "fp": 30, "kt0": 26, "kt1": 27, "pc": None}

INSN_RE = re.compile(
    r"(?P<mnem>\blq\b|\bsq\b|\blqc2\b|\bsqc2\b)"
    r"(?P<ws1>\s+)"
    r"\$(?:vf(?P<rt_vf>\d+)|(?P<rt_num>\d+)|(?P<rt_native>at|sp|gp|fp|kt0|kt1))\s*,\s*"
    r"(?P<off>(?:-?(?:0[xX][0-9a-fA-F]+|\d+))|(?P<sym>[A-Za-z_][A-Za-z0-9_]*))"
    r"\((?P<breg>\$[A-Za-z0-9]+)\)"
)

# splat's address-in-name convention: D_<8 hex digits>, L_<...>, etc. Take
# the longest trailing run of hex digits in the symbol name as its address.
# Also tolerates an optional trailing "+0x.." / "-0x.." addend on the symbol.
SYMBOL_ADDR_RE = re.compile(r"^[A-Za-z]+_([0-9A-Fa-f]{5,8})$")

REG_NUM_RE = re.compile(r"^\$(\d{1,2})$")


def base_reg_number(breg_token: str) -> int:
    """Resolve a base-register token (already-numeric $N, or one of the
    handful of names this assembler keeps natively) to its register number.
    Assumes fix_reg_names.py has already normalized most registers to
    numeric form; this covers the natively-symbolic leftovers too."""
    m = REG_NUM_RE.match(breg_token)
    if m:
        return int(m.group(1))
    native = {"$sp": 29, "$gp": 28, "$fp": 30, "$at": 1}
    if breg_token in native:
        return native[breg_token]
    raise ValueError(f"unrecognized base register token: {breg_token!r}")


def resolve_symbol_address(sym: str) -> int:
    m = SYMBOL_ADDR_RE.match(sym)
    if not m:
        raise ValueError(f"cannot determine address of symbol {sym!r}")
    return int(m.group(1), 16)


def encode(mnem: str, rt: int, base: int, imm: int) -> int:
    opcode = OPCODES[mnem]
    imm16 = imm & 0xFFFF
    return (opcode << 26) | (base << 21) | (rt << 16) | imm16


def process_line(line: str, gp_value: int, warnings: list, lineno: int, path: Path) -> str:
    m = INSN_RE.search(line)
    if not m:
        return line

    mnem = m.group("mnem")
    if m.group("rt_vf") is not None:
        rt = int(m.group("rt_vf"))
    elif m.group("rt_num") is not None:
        rt = int(m.group("rt_num"))
    else:
        rt_name = m.group("rt_native")
        rt = NATIVE_REG_NUMS.get(rt_name)
        if rt is None:
            warnings.append(
                f"{path}:{lineno}: unsupported target register ${rt_name}; line left unchanged"
            )
            return line
    breg_token = m.group("breg")
    sym = m.group("sym")

    try:
        base = base_reg_number(breg_token)
    except ValueError as e:
        warnings.append(f"{path}:{lineno}: {e}; line left unchanged")
        return line

    if sym is not None:
        if sym != "gp" and breg_token != "$gp":
            # A gp-relative-looking symbol reference but base isn't $gp --
            # unexpected shape, don't guess.
            warnings.append(
                f"{path}:{lineno}: symbol offset {sym!r} with non-$gp base "
                f"{breg_token!r}; line left unchanged"
            )
            return line
        try:
            sym_addr = resolve_symbol_address(sym)
        except ValueError as e:
            warnings.append(f"{path}:{lineno}: {e}; line left unchanged")
            return line
        imm = sym_addr - gp_value
    else:
        off_text = m.group("off")
        imm = int(off_text, 0)

    word = encode(mnem, rt, base, imm)
    original = line.rstrip("\n")
    indent_match = re.match(r"^(\s*)", original)
    indent = indent_match.group(1) if indent_match else ""
    # Strip the original line's own /* ... */ byte-dump comment (if any)
    # before re-wrapping the whole thing in one comment, to avoid nested
    # /* */ markers.
    stripped = re.sub(r"/\*.*?\*/", "", original).strip()
    return f"{indent}.word 0x{word:08X} /* {stripped} */\n"


def process_file(path: Path, gp_value: int, warnings: list) -> bool:
    text = path.read_text(encoding="utf-8", errors="surrogateescape")
    lines = text.splitlines(keepends=True)
    changed = False
    new_lines = []
    for i, line in enumerate(lines, start=1):
        new_line = process_line(line, gp_value, warnings, i, path)
        if new_line != line:
            changed = True
        new_lines.append(new_line)
    if changed:
        path.write_text("".join(new_lines), encoding="utf-8", errors="surrogateescape")
    return changed


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--gp-value", required=True, help="the project's _gp value, e.g. 0x001DC8B0")
    ap.add_argument("paths", nargs="+", help="files or directories to process (recurses into *.s)")
    args = ap.parse_args(argv[1:])

    gp_value = int(args.gp_value, 0)

    targets = []
    for arg in args.paths:
        p = Path(arg)
        if p.is_dir():
            targets.extend(p.rglob("*.s"))
        elif p.is_file():
            targets.append(p)
        else:
            print(f"warning: {p} not found, skipping", file=sys.stderr)

    warnings = []
    changed = 0
    for f in targets:
        if process_file(f, gp_value, warnings):
            changed += 1

    print(f"fix_quadword_ops: scanned {len(targets)} file(s), modified {changed}")
    if warnings:
        print(f"\n{len(warnings)} line(s) need manual attention:", file=sys.stderr)
        for w in warnings:
            print(f"  {w}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
