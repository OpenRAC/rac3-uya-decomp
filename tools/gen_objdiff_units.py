#!/usr/bin/env python3
"""Rewrite objdiff.json's code units: one unit per source file, per target.

For every target in tools/targets.py and every code section (unit) of it,
objdiff compares build/objdiff/target/<dir>/<file>.o (the matching build's
object for that file) with build/objdiff/base/<dir>/<file>.o (the same file
built with -DOBJDIFF_BASE, so only its C functions are in it). <dir> is the
target's objdiff_dirs entry: frontbin for frontbin, boot_elf/core and
boot_elf/text for boot_elf.

Run this after adding, removing or renaming a file in a target's file list;
every other unit in objdiff.json (data, levels, other executables) is left
as it is, except the units a target says its files replace
(objdiff_replaces: boot_elf's old reference-only exes/boot_elf unit).

    python tools/gen_objdiff_units.py
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import srcfiles as sf  # noqa: E402
import targets  # noqa: E402

PATH = os.path.join(sf.ROOT, "objdiff.json")

# progress categories the boot_elf units use (added when missing)
CATEGORIES = [
    {"id": "boot_elf", "name": "Boot ELF"},
    {"id": "boot_elf_core", "name": "Boot ELF: engine core"},
    {"id": "boot_elf_frontend", "name": "Boot ELF: front end"},
]


def ours(name):
    """True for a unit this script writes (or one it replaces)."""
    if name == "frontbin/text":  # before frontbin was split into source files
        return True
    for t in targets.TARGETS.values():
        if name in getattr(t, "objdiff_replaces", []):
            return True
        if any(name.startswith(p) for p in t.objdiff_units.values()):
            return True
    return False


def main():
    cfg = json.load(open(PATH))
    keep = [u for u in cfg["units"] if not ours(u["name"])]
    new = []
    counts = []
    for t in targets.TARGETS.values():
        files = sf.read_file_list(t.path("files"))
        for unit in t.units:
            n = 0
            for rel, start in files:
                if not unit.contains(start):
                    continue
                stem = os.path.splitext(os.path.basename(rel))[0]
                d = t.objdiff_dir(unit)
                new.append({
                    "name": t.objdiff_prefix(unit) + stem,
                    "target_path": "build/objdiff/target/%s/%s.o" % (d, stem),
                    "base_path": "build/objdiff/base/%s/%s.o" % (d, stem),
                    "metadata": {"source_path": rel,
                                 "progress_categories": t.objdiff_categories[unit.name]},
                })
                n += 1
            counts.append("%s %s: %d" % (t.name, unit.name, n))
    cats = cfg.setdefault("progress_categories", [])
    have = {c["id"]: c for c in cats}
    for c in CATEGORIES:
        if c["id"] in have:
            have[c["id"]]["name"] = c["name"]
        else:
            cats.append(dict(c))
    # code units first (frontbin, then the other targets, in link order),
    # then everything else as before
    cfg["units"] = new + keep
    # CRLF, like the file in the repo
    with open(PATH, "w", newline="\r\n") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    print("%s; %d other units" % (", ".join(counts), len(keep)))


if __name__ == "__main__":
    main()
