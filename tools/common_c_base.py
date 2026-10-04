#!/usr/bin/env python3
"""Build the objdiff base for the `levels/common` unit (common-level C).

`make objdiff` runs this so the progress report (CI, decomp.dev, localdecomp's
Full check) counts the C functions in src/levels/common/:

  * If the private reference inputs are there (the unpacked levels, the 51
    original level target objects and the split common.o, normally under
    C:\\decomp-refs, see docs/wiki/Setup.md), it runs tools/build_common_c.py,
    which compiles every catalogued function, proves its bytes against retail
    and writes build/objdiff/base/common.o. If a function no longer passes,
    this fails, like a NO MATCH.
  * If they aren't, it writes an empty base object, so `objdiff-cli report`
    still works and simply counts no common-level C (objdiff refuses to report
    at all when a unit's base_path is missing).

    python tools/common_c_base.py [--refs C:/decomp-refs] [-o build/objdiff/base/common.o]

Only the standard library is used here, so the fallback works on a machine
without the level tools' Python packages.
"""
import argparse
import os
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def empty_elf():
    """A relocatable little-endian MIPS ELF with an empty .text and no symbols."""
    shstr = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    names = {n: shstr.index(n.encode() + b"\0") for n in (".text", ".symtab", ".strtab", ".shstrtab")}
    symtab = b"\0" * 16          # the null symbol
    strtab = b"\0"
    off = 52
    data = bytearray()
    sections = []                # (name, type, flags, offset, size, link, info, align, entsize)
    for name, typ, flags, blob, link, info, align, ent in (
            (".text", 1, 6, b"", 0, 0, 8, 0),
            (".symtab", 2, 0, symtab, 3, 1, 4, 16),
            (".strtab", 3, 0, strtab, 0, 0, 1, 0),
            (".shstrtab", 3, 0, shstr, 0, 0, 1, 0)):
        while (off + len(data)) % max(align, 1):
            data.append(0)
        sections.append((names[name], typ, flags, off + len(data), len(blob), link, info, align, ent))
        data += blob
    while (off + len(data)) % 4:
        data.append(0)
    shoff = off + len(data)
    ident = b"\x7fELF" + bytes([1, 1, 1, 0]) + b"\0" * 8
    # e_flags: mips3 + noreorder, like the other objects; objdiff doesn't depend on it
    header = struct.pack("<16sHHIIIIIHHHHHH", ident, 1, 8, 1, 0, 0, shoff, 0x20000001,
                         52, 0, 0, 40, len(sections) + 1, len(sections))
    shdrs = b"\0" * 40 + b"".join(struct.pack("<IIIIIIIIII", n, t, f, 0, o, s, l, i, a, e)
                                  for n, t, f, o, s, l, i, a, e in sections)
    return header + bytes(data) + shdrs


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--refs", default=os.environ.get("UYA_REFS", r"C:\decomp-refs"),
                    help="folder with levels/, level-targets/ and level-targets-split/common.o")
    ap.add_argument("-o", "--output", default=os.path.join(ROOT, "build", "objdiff", "base", "common.o"))
    a = ap.parse_args()

    levels = os.path.join(a.refs, "levels")
    targets = os.path.join(a.refs, "level-targets")
    common = os.path.join(a.refs, "level-targets-split", "common.o")
    os.makedirs(os.path.dirname(os.path.abspath(a.output)), exist_ok=True)
    missing = [p for p in (levels, targets, common) if not os.path.exists(p)]
    if missing:
        with open(a.output, "wb") as f:
            f.write(empty_elf())
        print("common_c_base: %s not found; wrote an empty %s, so the report counts no common-level C"
              % (", ".join(missing), a.output))
        return
    cmd = [sys.executable, os.path.join(ROOT, "tools", "build_common_c.py"),
           "--levels-dir", levels, "--targets-dir", targets, "--common-target", common, "--output", a.output]
    if os.environ.get("UYA_TOOLCHAIN"):
        cmd += ["--toolchain", os.environ["UYA_TOOLCHAIN"]]
    if os.environ.get("UYA_RUNNER"):
        cmd += ["--runner", os.environ["UYA_RUNNER"]]
    sys.exit(subprocess.run(cmd, cwd=ROOT).returncode)


if __name__ == "__main__":
    main()
