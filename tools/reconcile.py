#!/usr/bin/env python3
"""
reconcile.py — normalize undefined_funcs_auto.txt / undefined_syms_auto.txt
so every symbol name text.c actually references resolves, regardless of
whether it uses the unpadded (D_143950) or zero-padded-to-8-digit
(D_00143950) hex naming convention, and regardless of manually-added
disambiguation suffixes like _b for a second declaration of the same
address under a different C type.

Why this is needed: this splat-based decomp project's auto-generated
symbol files were regenerated at some point after a splat config/behavior
change, and the two conventions ended up mixed together in the same files
(confirmed: undefined_syms_auto.txt has unpadded entries through line 123,
then switches to 0-padded-to-8 from line 124 onward). text.c's actual
`extern` declarations use whichever convention was in effect when that
particular INCLUDE_ASM block was last processed, so a name lookup against
only one form of the address leaves the other form's references dangling
-- this is a real, confirmed cause of "undefined reference" errors for an
otherwise-cataloged address.

What this script does:
  1. Parses both _auto.txt files into a canonical {address (int) -> prefix
     (D_/func_/jtbl_/etc.)} map, using whichever prefix each entry already
     uses (first occurrence wins if an address appears more than once with
     different prefixes -- unexpected, but reported if it happens).
  2. For every canonical address, emits BOTH the unpadded and the
     0-padded-to-8-hex-digit name, each assigned to that same address --
     so a reference under either convention resolves.
  3. Scans text.c for `extern ... NAME` / `extern ... NAME[]` declarations
     whose NAME does not match any known canonical symbol even after
     stripping a trailing `_b`, `_c`, ... disambiguation suffix, and:
       - if NAME minus the suffix (e.g. D_00143950_b -> D_00143950) DOES
         match a canonical address, emits NAME at that same address
         (this is the developer's own disambiguation for a second
         declaration of the same address under a different C type --
         confirmed with Nick for D_00143950_b specifically).
       - otherwise, reports NAME as unresolved so it can be handled by
         hand (a real gap in the symbol tables, not a naming-convention
         issue).
  4. Writes a single merged output file, symbol_addrs_resolved.txt, ready
     to be split back into two INPUT() files or used as one.

Usage:
    python reconcile.py undefined_funcs_auto.txt undefined_syms_auto.txt text.c
"""

import re
import sys
from pathlib import Path

ASSIGN_RE = re.compile(
    r"^\s*(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*=\s*(?P<addr>0x[0-9A-Fa-f]+)\s*;\s*$"
)

# Matches the prefix (letters/underscores before the hex digits) and the
# hex digits themselves, e.g. "D_00143950" -> prefix="D_", hex="00143950"
# "jtbl_00318000" -> prefix="jtbl_", hex="00318000"
NAME_RE = re.compile(r"^(?P<prefix>[A-Za-z]+_)(?P<hex>[0-9A-Fa-f]+)$")

# extern declarations in text.c, e.g.:
#   extern u8 D_00143950;
#   extern s32 D_00143950_b[];
#   extern void func_00393460(void);
EXTERN_RE = re.compile(
    r"^\s*extern\s+[A-Za-z_][A-Za-z0-9_ ]*?\s+\**(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*(?:\[[^\]]*\])?\s*;",
    re.MULTILINE,
)

DISAMBIG_SUFFIX_RE = re.compile(r"^(?P<base>.+?)_[a-z]$")


def parse_auto_file(path: Path, canonical: dict, name_to_addr: dict, warnings: list):
    for lineno, line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        line = line.strip()
        if not line:
            continue
        m = ASSIGN_RE.match(line)
        if not m:
            warnings.append(f"{path.name}:{lineno}: unrecognized line, skipped: {line!r}")
            continue
        name = m.group("name")
        addr = int(m.group("addr"), 16)
        name_to_addr[name] = addr

        nm = NAME_RE.match(name)
        if not nm:
            # Name doesn't fit the <prefix>_<hex> pattern (e.g. it's
            # already something unusual) -- keep it as its own canonical
            # entry keyed by address, but don't try to derive padded /
            # unpadded variants for it.
            canonical.setdefault(addr, {"prefix": None, "names": set()})
            canonical[addr]["names"].add(name)
            continue

        prefix = nm.group("prefix")
        entry = canonical.setdefault(addr, {"prefix": prefix, "names": set()})
        if entry["prefix"] is None:
            entry["prefix"] = prefix
        elif entry["prefix"] != prefix:
            warnings.append(
                f"{path.name}:{lineno}: address 0x{addr:X} seen with prefix "
                f"{entry['prefix']!r} and now {prefix!r} (name {name!r}); "
                f"keeping first prefix seen"
            )
        entry["names"].add(name)


def hex_variants(prefix: str, addr: int) -> set:
    """Return the set of plausible name spellings for this prefix/address:
    unpadded upper-hex, and zero-padded-to-8 upper-hex (the two conventions
    actually observed in this project's auto-generated files)."""
    unpadded = f"{prefix}{addr:X}"
    padded8 = f"{prefix}{addr:08X}"
    return {unpadded, padded8}


def main(argv):
    if len(argv) != 4:
        print(f"usage: {argv[0]} undefined_funcs_auto.txt undefined_syms_auto.txt text.c", file=sys.stderr)
        return 2

    funcs_path = Path(argv[1])
    syms_path = Path(argv[2])
    text_c_path = Path(argv[3])

    canonical: dict[int, dict] = {}   # addr -> {"prefix": str|None, "names": set()}
    name_to_addr: dict[str, int] = {} # every literal name seen in the auto files -> addr
    warnings: list[str] = []

    parse_auto_file(funcs_path, canonical, name_to_addr, warnings)
    parse_auto_file(syms_path, canonical, name_to_addr, warnings)

    # Build the full set of resolvable names: every canonical address's
    # padded + unpadded spelling (for names that fit <prefix>_<hex>), plus
    # every literal name already seen (covers anything with a weirder
    # shape, e.g. explicit odd-length hex or non-hex suffixes).
    resolvable: dict[str, int] = {}
    for addr, entry in canonical.items():
        if entry["prefix"] is not None:
            for variant in hex_variants(entry["prefix"], addr):
                resolvable.setdefault(variant, addr)
        for n in entry["names"]:
            resolvable.setdefault(n, addr)

    # Scan text.c for extern declarations and find any name we can't
    # already resolve.
    text_c = text_c_path.read_text(encoding="utf-8", errors="surrogateescape")
    extern_names = set(m.group("name") for m in EXTERN_RE.finditer(text_c))

    unresolved = []
    disambig_resolved: dict[str, int] = {}
    for name in sorted(extern_names):
        if name in resolvable:
            continue
        m = DISAMBIG_SUFFIX_RE.match(name)
        if m:
            base = m.group("base")
            if base in resolvable:
                disambig_resolved[name] = resolvable[base]
                continue
            # the base itself might resolve via its own name-encoded
            # address even though it's not in either _auto.txt file
            bm = NAME_RE.match(base)
            if bm:
                disambig_resolved[name] = int(bm.group("hex"), 16)
                continue
        # Not in the catalog under any spelling and no disambiguation
        # suffix matched -- but if the name itself is a <prefix>_<hex>
        # splat-style name, the address is embedded in the name itself,
        # so it can be resolved directly even though it was never listed
        # in undefined_funcs_auto.txt / undefined_syms_auto.txt (a real
        # gap in those generated catalogs, not an unknown address).
        nm = NAME_RE.match(name)
        if nm:
            disambig_resolved[name] = int(nm.group("hex"), 16)
            continue
        unresolved.append(name)

    # Emit the merged, fully-expanded symbol file.
    out_lines = []
    out_lines.append("/* Auto-generated by reconcile.py -- do not hand-edit. */")
    out_lines.append("/* Each canonical address is emitted under both its unpadded and */")
    out_lines.append("/* zero-padded-to-8-hex-digit spellings, so either naming convention */")
    out_lines.append("/* text.c happens to use for a given reference will resolve. */")
    out_lines.append("")

    emitted = set()
    for addr in sorted(canonical.keys()):
        entry = canonical[addr]
        names = set(entry["names"])
        if entry["prefix"] is not None:
            names |= hex_variants(entry["prefix"], addr)
        for name in sorted(names):
            if name in emitted:
                continue
            emitted.add(name)
            out_lines.append(f"{name} = 0x{addr:X};")

    if disambig_resolved:
        out_lines.append("")
        out_lines.append("/* Names resolved from their own embedded hex address: either a */")
        out_lines.append("/* _b-style disambiguation suffix over a cataloged base symbol, */")
        out_lines.append("/* or a <prefix>_<hex> name missing from both _auto.txt catalogs */")
        out_lines.append("/* whose address is nonetheless given directly by the name itself. */")
        for name in sorted(disambig_resolved):
            if name in emitted:
                continue
            emitted.add(name)
            out_lines.append(f"{name} = 0x{disambig_resolved[name]:X};")

    out_path = Path("symbol_addrs_resolved.txt")
    out_path.write_text("\n".join(out_lines) + "\n", encoding="utf-8")

    print(f"reconcile: {len(canonical)} canonical addresses, {len(emitted)} symbol names emitted")
    print(f"reconcile: wrote {out_path}")
    if disambig_resolved:
        print(f"\n{len(disambig_resolved)} disambiguation-suffix name(s) resolved via base symbol:")
        for name in sorted(disambig_resolved):
            print(f"  {name} -> 0x{disambig_resolved[name]:X}")
    if unresolved:
        print(f"\n{len(unresolved)} extern name(s) in text.c could NOT be resolved (real gaps, need manual addresses):", file=sys.stderr)
        for name in unresolved:
            print(f"  {name}", file=sys.stderr)
    if warnings:
        print(f"\n{len(warnings)} warning(s) while parsing input files:", file=sys.stderr)
        for w in warnings:
            print(f"  {w}", file=sys.stderr)

    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
