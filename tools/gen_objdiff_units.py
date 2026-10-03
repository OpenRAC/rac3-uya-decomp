#!/usr/bin/env python3
"""Rewrite objdiff.json's frontbin .text units: one unit per source file.

objdiff compares build/objdiff/target/frontbin/<file>.o (the matching build's
object for that file) with build/objdiff/base/frontbin/<file>.o (the same file
built with -DOBJDIFF_BASE, so only its C functions are in it). Run this after
adding, removing or renaming a file in tools/src_files.txt; every other unit
in objdiff.json (data, levels, executables) is left as it is.

    python tools/gen_objdiff_units.py
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import srcfiles as sf  # noqa: E402

PATH = os.path.join(sf.ROOT, "objdiff.json")


def main():
    cfg = json.load(open(PATH))
    units = cfg["units"]
    keep = [u for u in units if not (u["name"] == "frontbin/text" or u["name"].startswith("frontbin/src/"))]
    new = []
    for rel, _ in sf.read_file_list():
        stem = os.path.splitext(os.path.basename(rel))[0]
        new.append({
            "name": "frontbin/src/" + stem,
            "target_path": "build/objdiff/target/frontbin/%s.o" % stem,
            "base_path": "build/objdiff/base/frontbin/%s.o" % stem,
            "metadata": {"source_path": rel, "progress_categories": ["frontend"]},
        })
    # frontbin units first, in link order, then everything else as before
    cfg["units"] = new + keep
    with open(PATH, "w", newline="\n") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    print("%d frontbin units, %d other units" % (len(new), len(keep)))


if __name__ == "__main__":
    main()
