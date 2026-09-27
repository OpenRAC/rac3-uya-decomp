#!/usr/bin/env python3
"""migrate_asm_sources.py: give non-C code its own home in src/text.c.

Two kinds of INCLUDE_ASM entry are not decompilation targets at all:

  handwritten  The original was assembly (spimdisasm marks the .s
               "Handwritten function": addi, $at, loops gcc never emits).
               Its assembly *is* the source.
  remnant      Only [instruction, nop] pairs with no return and no callers:
               the last odd word of a function the original linker stripped
               as unused, plus its alignment nop. Not source code at all.

Left as INCLUDE_ASM("asm/nonmatchings/...") they look like unfinished work
to every tool, and objdiff counts them as missing. This script:

  1. moves their .s files to asm/handwritten/ and asm/remnants/;
  2. rewrites their text.c lines to ASM_FUNC(...) / LINKER_REMNANT(...),
     which include/include_asm.h keeps in the objdiff base build, so they
     count as done;
  3. leaves any INCLUDE_RODATA line that follows (jump tables) in place.

The bytes built are identical. Buckets come from tools/triage.py.
Idempotent: entries already migrated are skipped. Run from anywhere:

    python tools/migrate_asm_sources.py
"""
import importlib.util, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT_C = os.path.join(ROOT, "src", "text.c")
SRC_DIR = os.path.join(ROOT, "asm", "nonmatchings", "text")
DEST = {"handwritten": ("asm/handwritten", "ASM_FUNC"),
        "remnant": ("asm/remnants", "LINKER_REMNANT")}


def main():
    spec = importlib.util.spec_from_file_location("triage", os.path.join(ROOT, "tools", "triage.py"))
    triage = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(triage)

    src = open(TEXT_C, newline="").read()
    moved = {k: 0 for k in DEST}
    for name in re.findall(r'INCLUDE_ASM\("asm/nonmatchings/text",\s*(func_[0-9A-Fa-f]{8})\)', src):
        bucket, _ = triage.classify(name)
        if bucket not in DEST:
            continue
        folder, macro = DEST[bucket]
        os.makedirs(os.path.join(ROOT, folder), exist_ok=True)
        old_path = os.path.join(SRC_DIR, name + ".s")
        new_path = os.path.join(ROOT, folder, name + ".s")
        if os.path.exists(old_path):
            os.replace(old_path, new_path)
        src = re.sub(r'INCLUDE_ASM\("asm/nonmatchings/text",\s*%s\);' % name,
                     '%s("%s", %s);' % (macro, folder, name), src, count=1)
        moved[bucket] += 1
    open(TEXT_C, "w", newline="").write(src)
    print("moved", ", ".join("%d %s" % (v, k) for k, v in moved.items()))


if __name__ == "__main__":
    main()
