#!/usr/bin/env python3
"""
fix_reg_names.py -- patch splat-generated .s files for compatibility with
this project's assembler (SN Systems ee-as.exe, ee-gcc 2.95.3 era), in place.

Two fixes:

1. Register names. ee-as only knows $fp $sp $gp $at $kt0 $kt1 $pc as
   symbolic names; every other ABI name ($zero, $v0, $a0, $ra, ...) is
   rewritten to its numeric form ($0, $2, $4, $31, ...). Unchanged from the
   previous version of this script.

2. %gp_rel(...) -- REWRITTEN. ee-as has no %gp_rel operator. The previous
   version of this script replaced
       lw $v0, %gp_rel(SYM)($gp)    ->  lw $v0, SYM($gp)
       addiu $a0, $gp, %gp_rel(SYM) ->  addiu $a0, $gp, %lo(SYM)
   Both assemble without errors but produce WRONG code:
     - `SYM($gp)` means "full 32-bit address SYM, plus $gp". ee-as expands
       it to THREE instructions (lui / addu $gp / lw), adding 8 bytes per
       use and computing gp+SYM instead of SYM. This was the main cause of
       every INCLUDE_ASM function drifting in the full link (e.g. retail
       0x37F050 `8F82D620 lw $2,-0x29E0($28)` became lui/addu/lw).
     - `%lo(SYM)` is the low 16 bits of the ABSOLUTE address, not the
       offset from $gp. Same instruction count, wrong immediate.
   Fixed version: the gp-relative displacement is computed here as
   (symbol_address + addend - gp_value) and written as a plain number:
       lw $2, -0x29E0($gp)
       addiu $4, $gp, -0x7158
   A numeric 16-bit displacement always assembles to exactly one
   instruction. This is the same approach fix_quadword_ops.py already
   uses for lq/sq.

   The build is not shiftable (every symbol is pinned to its retail
   address), so baking the displacement in loses nothing.

SAFETY CHECK: every spimdisasm instruction line carries the ORIGINAL
encoding in its comment, e.g. `/* 1AA9D0 0037F050 20D6828F */` (bytes are
little-endian). For every rewrite, the computed 16-bit immediate is
checked against the low 16 bits of that original word. If ANY rewrite in a
file disagrees, the file is left completely untouched and the mismatch is
reported. Lines without a spimdisasm comment are rewritten but counted as
"unverified" in the summary.

Also repairs files already processed by the OLD version of this script
(bare `SYM($gp)` and `, $gp, %lo(SYM)` forms), using the same check, so
you don't need to re-run splat just to fix them.

Usage:
    python fix_reg_names.py [--gp-value 0x001DC8B0] [--symbols FILE] <file_or_dir> ...

    --gp-value defaults to the gp_value in frontbin.splat.yaml (current dir)
    --symbols  defaults to symbol_addrs.txt and symbol_addrs_resolved.txt
               (current dir, if present); used only for symbols whose name
               doesn't encode their own address (D_/func_/jtbl_/L_ + hex).
"""

import argparse
import re
import sys
from pathlib import Path

NATIVE = {"fp", "sp", "gp", "at", "kt0", "kt1", "pc"}
REG_MAP = {
    "zero": 0, "v0": 2, "v1": 3,
    "a0": 4, "a1": 5, "a2": 6, "a3": 7,
    "t0": 8, "t1": 9, "t2": 10, "t3": 11, "t4": 12, "t5": 13, "t6": 14, "t7": 15,
    "s0": 16, "s1": 17, "s2": 18, "s3": 19, "s4": 20, "s5": 21, "s6": 22, "s7": 23,
    "t8": 24, "t9": 25, "k0": 26, "k1": 27, "s8": 30, "ra": 31,
}
TOKEN_RE = re.compile(r"\$([A-Za-z][A-Za-z0-9]*)\b")

# spimdisasm instruction comment: /* ROMOFF VADDR WORD_LE */
COMMENT_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/")

# Symbol expression: NAME, optionally "+ 0x5D0" / "+4" / "- 8"
EXPR_RE = re.compile(r"^\s*([A-Za-z_.][A-Za-z0-9_.]*)\s*(?:([+-])\s*(0x[0-9A-Fa-f]+|\d+))?\s*$")
NAME_ADDR_RE = re.compile(r"^(?:D|func|jtbl|L|B|jlabel)_([0-9A-Fa-f]{5,8})(?:_\w+)?$")

# Forms to rewrite (fresh splat output, and old-script output):
#   A) %gp_rel(EXPR)($gp)       -> DISP($gp)
#   B) %gp_rel(EXPR)            -> DISP
#   C) EXPR($gp)   (old script) -> DISP($gp)   only if EXPR is a symbol, not a number
#   D) $gp, %lo(EXPR) (old)     -> $gp, DISP
GP_REL_MEM = re.compile(r"%gp_rel\(([^()]*)\)\(\$gp\)")
GP_REL_PLAIN = re.compile(r"%gp_rel\(([^()]*)\)")
OLD_MEM = re.compile(r"(?<![\w%)])([A-Za-z_][A-Za-z0-9_]*(?:\s*[+-]\s*(?:0x[0-9A-Fa-f]+|\d+))?)\(\$gp\)")
OLD_LO = re.compile(r"(\$gp\s*,\s*)%lo\(([^()]*)\)")


def load_symbols(paths):
    table = {}
    for p in paths:
        if not p.exists():
            continue
        for line in p.read_text(encoding="utf-8", errors="replace").splitlines():
            line = line.split("//", 1)[0].split("/*", 1)[0].strip()
            m = re.match(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?", line)
            if m:
                table.setdefault(m.group(1), int(m.group(2), 16))
    return table


def resolve(expr, symtab):
    m = EXPR_RE.match(expr)
    if not m:
        raise ValueError(f"can't parse symbol expression {expr!r}")
    name, sign, add = m.groups()
    nm = NAME_ADDR_RE.match(name)
    if nm:
        addr = int(nm.group(1), 16)
    elif name in symtab:
        addr = symtab[name]
    else:
        raise ValueError(f"no address known for symbol {name!r}")
    if add:
        addr += int(add, 0) * (-1 if sign == "-" else 1)
    return addr


def fmt(disp):
    return f"-0x{-disp:X}" if disp < 0 else f"0x{disp:X}"


class Mismatch(Exception):
    pass


def process_line(line, gp, symtab, stats):
    # register names first (so the $gp token stays literal for the regexes)
    def reg(m):
        n = m.group(1).lower()
        if n in NATIVE:
            return m.group(0)
        return f"${REG_MAP[n]}" if n in REG_MAP else m.group(0)
    line = TOKEN_RE.sub(reg, line)

    # on spimdisasm lines the instruction text follows the /* ... */ comment
    code, sep, rest = line.partition("*/")
    if sep:
        head, body = code + sep, rest
    else:
        head, body = "", line
    cm = COMMENT_RE.search(head)
    orig = int.from_bytes(bytes.fromhex(cm.group(1)), "little") if cm else None

    rewrites = []

    def disp_for(expr):
        d = resolve(expr, symtab) - gp
        if not -0x8000 <= d <= 0x7FFF:
            raise Mismatch(f"displacement {fmt(d)} for {expr!r} doesn't fit in 16 bits")
        rewrites.append(d)
        return fmt(d)

    new_body = GP_REL_MEM.sub(lambda m: f"{disp_for(m.group(1))}($gp)", body)
    new_body = GP_REL_PLAIN.sub(lambda m: disp_for(m.group(1)), new_body)
    if new_body == body:  # only try old-script forms if nothing fresh matched
        new_body = OLD_LO.sub(lambda m: m.group(1) + disp_for(m.group(2)), new_body)
        new_body = OLD_MEM.sub(lambda m: f"{disp_for(m.group(1))}($gp)", new_body)

    if not rewrites:
        return line
    if len(rewrites) > 1:
        raise Mismatch(f"more than one gp-relative operand on one line: {line.strip()!r}")
    if orig is None:
        stats["unverified"] += 1
    elif (orig & 0xFFFF) != (rewrites[0] & 0xFFFF):
        raise Mismatch(f"computed {fmt(rewrites[0])} but original word 0x{orig:08X} "
                       f"has 0x{orig & 0xFFFF:04X}: {line.strip()!r}")
    else:
        stats["verified"] += 1
    return head + new_body


def process_file(path, gp, symtab, stats, errors):
    text = path.read_text(encoding="utf-8", errors="surrogateescape")
    out = []
    local = {"verified": 0, "unverified": 0}
    for i, line in enumerate(text.splitlines(keepends=True), 1):
        try:
            out.append(process_line(line, gp, symtab, local))
        except (Mismatch, ValueError) as e:
            errors.append(f"{path}:{i}: {e}")
            return False
    new = "".join(out)
    stats["verified"] += local["verified"]
    stats["unverified"] += local["unverified"]
    if new != text:
        path.write_text(new, encoding="utf-8", errors="surrogateescape")
        return True
    return False


def default_gp():
    y = Path("frontbin.splat.yaml")
    if y.exists():
        m = re.search(r"^\s*gp_value:\s*(0x[0-9A-Fa-f]+)", y.read_text(), re.M)
        if m:
            return int(m.group(1), 16)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--gp-value")
    ap.add_argument("--symbols", action="append", help="may be given more than once")
    ap.add_argument("paths", nargs="+")
    a = ap.parse_args()

    gp = int(a.gp_value, 0) if a.gp_value else default_gp()
    if gp is None:
        print("error: no --gp-value given and none found in frontbin.splat.yaml", file=sys.stderr)
        return 2
    sym_paths = [Path(p) for p in a.symbols] if a.symbols else [Path("symbol_addrs.txt"), Path("symbol_addrs_resolved.txt")]
    symtab = load_symbols(sym_paths)

    targets = []
    for p in map(Path, a.paths):
        targets.extend(p.rglob("*.s") if p.is_dir() else [p] if p.is_file() else [])

    stats = {"verified": 0, "unverified": 0}
    errors = []
    changed = sum(process_file(f, gp, symtab, stats, errors) for f in targets)

    print(f"fix_reg_names: gp_value=0x{gp:X}, scanned {len(targets)} file(s), modified {changed}")
    print(f"  gp-relative rewrites checked against original bytes: {stats['verified']}"
          f" (unverified, no comment: {stats['unverified']})")
    if errors:
        print(f"\n{len(errors)} file(s) LEFT UNTOUCHED because a rewrite didn't match the original bytes:", file=sys.stderr)
        for e in errors:
            print("  " + e, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
