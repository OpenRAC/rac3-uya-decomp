#!/usr/bin/env python3
"""check_match.py [--target NAME] BUILT_BIN RETAIL_ELF SPLAT_YAML

Compares the flat binary built from the target's ELF against the retail file.
Prints MATCH (and exits 0) when the sha1 equals the one in the splat config;
otherwise prints sizes and the first few differing file offsets (with the
address each one loads at) and exits 1.
"""
import hashlib, os, re, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import targets  # noqa: E402

targets.from_argv()
built, retail, yaml = sys.argv[1:4]
b = open(built, "rb").read()
want = re.search(r"^sha1:\s*([0-9A-Fa-f]{40})", open(yaml).read(), re.M).group(1).lower()
got = hashlib.sha1(b).hexdigest()
if got == want:
    print(f"MATCH: {built} sha1 {got} (0x{len(b):X} bytes)")
    sys.exit(0)

r = open(retail, "rb").read()
# file offset -> address, from the retail ELF's program headers
phoff, = struct.unpack_from("<I", r, 0x1C)
phnum, = struct.unpack_from("<H", r, 0x2C)
loads = []
for i in range(phnum):
    ptype, off, va, _, filesz = struct.unpack_from("<5I", r, phoff + 32 * i)
    if ptype == 1:
        loads.append((off, va, filesz))


def where(off):
    for o, va, n in loads:
        if o <= off < o + n:
            return f"vaddr 0x{va + off - o:X}"
    return "outside the loaded segments"


print(f"NO MATCH: built sha1 {got}, expected {want}")
print(f"  size built 0x{len(b):X}, retail 0x{len(r):X} ({len(b) - len(r):+d} bytes)")
n = min(len(b), len(r))
shown = 0
i = 0
while i < n and shown < 10:
    if b[i] != r[i]:
        j = i
        while j < n and j - i < 64 and b[j] != r[j]:
            j += 1
        print(f"  differs at file offset 0x{i:X} ({where(i)}): built {b[i:i+8].hex()} retail {r[i:i+8].hex()}")
        shown += 1
        i = j
    i += 1
sys.exit(1)
