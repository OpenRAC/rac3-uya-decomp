#!/usr/bin/env python3
"""level_occurrences.py: which level overlays each shared function is in.

The 51 overlays link much of the same code at different addresses. The
common-level sources (src/levels/common/, docs/common_level_c.md) are named
after one canonical owner, so a source's name says nothing about the other
levels. This maps every shared function to all of its copies.

    python tools/level_occurrences.py                      write config/levels/common_occurrences.tsv
    python tools/level_occurrences.py --summary            per-level progress table
    python tools/level_occurrences.py --level 5_daxx       one level: address, canonical name, size, C or asm
    python tools/level_occurrences.py --function func_004D0538   every level and address of one function

Two copies are the same function when their bytes match with j/jal targets
masked (split_shared_levels.norm_hash), and the canonical owner is the first
level, in level order, that has it. build_common_c.py uses the same rule, so
the canonical names here are the catalogue's.

The committed TSV has one row per shared function: canonical name, owner
level, size, how many levels have it, whether it is C (config/levels/common_c.json),
and the level numbers as ranges. Addresses are left out (about 250k of them);
--level and --function print them. Needs the level target objects
(C:\\decomp-refs\\level-targets, or --refs / UYA_REFS).
"""
import argparse, collections, json, os, sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tools" / "objdiff"))  # split_shared_levels.py
import split_shared_levels as shared  # noqa: E402

OUT = ROOT / "config" / "levels" / "common_occurrences.tsv"


def load(refs):
    """level name -> (number, [(name, address, size, identity)]), in level order."""
    out = {}
    paths = sorted((refs / "level-targets").glob("*.o"), key=lambda p: shared.level_no(str(p)))
    dirs = {p.parent.name: p for p in (refs / "levels").glob("*/*/overlay.elf")}
    for p in paths:
        lv = shared.Level(str(p))
        with open(dirs[p.stem], "rb") as f:
            base = ELFFile(f).get_section_by_name(".text")["sh_addr"]
        out[p.stem] = (lv.no, [(n, base + off, sz, h) for _, n, off, sz, h in lv.funcs])
    return out


def occurrences(levels):
    """identity -> [(level, address, size, name)] for code in two or more levels."""
    occ = collections.defaultdict(list)
    for level, (_, funcs) in levels.items():
        seen = set()
        for n, addr, sz, h in funcs:
            if h not in seen:
                seen.add(h)
                occ[h].append((level, addr, sz, n))
    return {h: v for h, v in occ.items() if len(v) > 1}


def ranges(nums):
    nums, out, i = sorted(nums), [], 0
    while i < len(nums):
        j = i
        while j + 1 < len(nums) and nums[j + 1] == nums[j] + 1:
            j += 1
        out.append(str(nums[i]) if i == j else "%d-%d" % (nums[i], nums[j]))
        i = j + 1
    return ",".join(out)


def catalogued():
    """(name, owner level) of every C function: about 20 canonical names
    belong to two different functions owned by different levels."""
    return {(e["name"], Path(e["overlay"]).name) for e in json.loads((ROOT / "config" / "levels" / "common_c.json").read_text(encoding="utf-8"))}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--refs", type=Path, default=Path(os.environ.get("UYA_REFS", r"C:\decomp-refs")))
    ap.add_argument("--summary", action="store_true")
    ap.add_argument("--level")
    ap.add_argument("--function")
    a = ap.parse_args()
    levels = load(a.refs)
    occ = occurrences(levels)
    number = {lv: no for lv, (no, _) in levels.items()}
    canon = {h: v[0][3] for h, v in occ.items()}   # first level in level order owns it
    cat = catalogued()
    done = {h for h, v in occ.items() if (v[0][3], v[0][0]) in cat}

    if a.function:
        for h, v in occ.items():
            if canon[h] == a.function or any(n == a.function for _, _, _, n in v):
                print("%s (canonical %s, %d bytes, %s): %d levels" % (a.function, canon[h], v[0][2],
                      "C" if h in done else "asm", len(v)))
                for level, addr, _, _ in v:
                    print("  %-36s 0x%08X" % (level, addr))
                return
        sys.exit("%s is not shared code" % a.function)

    if a.level:
        if a.level not in levels:
            sys.exit("unknown level %s (one of: %s)" % (a.level, ", ".join(levels)))
        here = {}
        for h, v in occ.items():
            for level, addr, sz, _ in v:
                if level == a.level:
                    here[addr] = (canon[h], sz, len(v), h in done)
        print("address     canonical       size  levels  status")
        for addr in sorted(here):
            name, sz, n, c = here[addr]
            print("0x%08X  %s  %5d  %6d  %s" % (addr, name, sz, n, "C" if c else "asm"))
        return

    if a.summary:
        print("%-36s %6s %6s %6s %6s %7s" % ("level", "funcs", "shared", "own", "C", "C bytes"))
        for level, (no, funcs) in levels.items():
            ids = {h for _, _, _, h in funcs}
            sh = [h for h in ids if h in occ]
            cb = sum(occ[h][0][2] for h in sh if h in done)
            tb = sum(occ[h][0][2] for h in sh)
            print("%-36s %6d %6d %6d %6d %6.1f%%" % (level, len(ids), len(sh), len(ids) - len(sh),
                  sum(1 for h in sh if h in done), 100.0 * cb / max(1, tb)))
        return

    OUT.parent.mkdir(parents=True, exist_ok=True)
    rows = sorted(occ.items(), key=lambda hv: (-len(hv[1]), hv[1][0][3], hv[1][0][0]))
    with open(OUT, "w", encoding="utf-8", newline="\n") as f:
        f.write("# Shared level functions and the overlays that contain them (tools/level_occurrences.py).\n")
        f.write("# levels: level numbers (the N in N_name); --level/--function print the addresses.\n")
        f.write("name\towner\tsize\tcount\tstatus\tlevels\n")
        for h, v in rows:
            name = v[0][3]
            f.write("%s\t%s\t%d\t%d\t%s\t%s\n" % (name, v[0][0], v[0][2], len(v), "C" if h in done else "asm",
                                                  ranges(number[lv] for lv, _, _, _ in v)))
    in_c = len(done)
    print("wrote %s: %d shared functions, %d in C" % (OUT.relative_to(ROOT).as_posix(), len(rows), in_c))


if __name__ == "__main__":
    try:
        main()
    except BrokenPipeError:  # piped into head
        sys.stdout = None
