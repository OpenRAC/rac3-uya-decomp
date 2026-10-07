#!/usr/bin/env python3
"""elf2bin.py IN.elf OUT.bin: what `objcopy -O binary` does, in Python.

Writes every loadable segment's file bytes at its load (physical) address,
counted from the lowest one, with zeros in the gaps. The linker scripts put
each section at its retail file offset with AT(...), so the result is the
retail file.

Used for i5bootn instead of SN's ee-objcopy.exe: that objcopy corrupts 21
bytes of i5bootn's section-name table (every 8 bytes from file offset 0xC59E8,
the same each run) while the linked ELF itself is right; GNU objcopy and this
script both produce the retail file from it. See docs/i5bootn.md.
"""
import struct
import sys


def flatten(data):
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        sys.exit("elf2bin: not a little-endian ELF32 file")
    phoff, = struct.unpack_from("<I", data, 0x1C)
    phentsize, phnum = struct.unpack_from("<HH", data, 0x2A)
    loads = []
    for i in range(phnum):
        ptype, off, _, paddr, filesz = struct.unpack_from("<5I", data, phoff + i * phentsize)
        if ptype == 1 and filesz:
            loads.append((paddr, data[off:off + filesz]))
    if not loads:
        sys.exit("elf2bin: no loadable segments")
    base = min(p for p, _ in loads)
    out = bytearray(max(p + len(b) for p, b in loads) - base)
    for p, b in sorted(loads, key=lambda x: x[0]):
        out[p - base:p - base + len(b)] = b
    return bytes(out)


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    data = open(sys.argv[1], "rb").read()
    open(sys.argv[2], "wb").write(flatten(data))


if __name__ == "__main__":
    main()
