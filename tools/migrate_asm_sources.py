#!/usr/bin/env python3
"""migrate_asm_sources.py: give non-C code its own home in the sources.

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
  2. rewrites their source lines to ASM_FUNC(...) / LINKER_REMNANT(...),
     which include/include_asm.h keeps in the objdiff base build, so they
     count as done;
  3. leaves any INCLUDE_RODATA line that follows (jump tables) in place.

The bytes built are identical. Buckets come from tools/triage.py.
Idempotent: entries already migrated are skipped. Run from anywhere:

    python tools/migrate_asm_sources.py
"""
import importlib.util, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import srcfiles  # noqa: E402
import targets  # noqa: E402


def main():
    t = targets.from_argv()   # --target boot_elf
    DEST = {"handwritten": (t.handwritten, "ASM_FUNC"),
            "remnant": (t.remnants, "LINKER_REMNANT")}
    spec = importlib.util.spec_from_file_location("triage", os.path.join(ROOT, "tools", "triage.py"))
    triage = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(triage)

    src = srcfiles.read_all(ROOT)
    moved = {k: 0 for k in DEST}
    renames = []
    for name in re.findall(r'INCLUDE_ASM\("[^"]+",\s*(func_[0-9A-Fa-f]{8})\)', src):
        bucket, _ = triage.classify(name)
        if bucket not in DEST:
            continue
        folder, macro = DEST[bucket]
        os.makedirs(os.path.join(ROOT, folder), exist_ok=True)
        old_path = os.path.join(ROOT, t.unit_for(int(name[5:], 16)).asm_dir, name + ".s")
        new_path = os.path.join(ROOT, folder, name + ".s")
        if os.path.exists(old_path):
            os.replace(old_path, new_path)
        # splat's `nonmatching` line defines NAME.NON_MATCHING, which makes
        # objdiff (and decomp.dev) count the function as not matching.
        # This .s is final source, so turn that line into a comment.
        if os.path.exists(new_path):
            s_src = open(new_path, newline="").read()
            s_src = re.sub(r"^nonmatching (func_[0-9A-Fa-f]{8})(, *0x[0-9A-Fa-f]+)?[ \t]*(\r?)$",
                           r"/* nonmatching \1\2 -- marker removed: final source */\3",
                           s_src, flags=re.M)
            open(new_path, "w", newline="").write(s_src)
        renames.append((name, macro, folder))
        moved[bucket] += 1

    def rename(text):
        for name, macro, folder in renames:
            text = re.sub(r'INCLUDE_ASM\("[^"]+",\s*%s\);' % name,
                          '%s("%s", %s);' % (macro, folder, name), text, count=1)
        return text

    srcfiles.transform_all(rename, ROOT)
    print("moved", ", ".join("%d %s" % (v, k) for k, v in moved.items()))


if __name__ == "__main__":
    main()
