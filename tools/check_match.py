#!/usr/bin/env python3
"""check_match.py BUILT_BIN RETAIL_ELF SPLAT_YAML

Compares the flat binary built from build/frontbin.elf against the retail file.
Prints MATCH (and exits 0) when the sha1 equals the one in the splat config;
otherwise prints sizes and the first few differing file offsets and exits 1.
"""
import hashlib, re, sys

built, retail, yaml = sys.argv[1:4]
b = open(built, "rb").read()
want = re.search(r"^sha1:\s*([0-9A-Fa-f]{40})", open(yaml).read(), re.M).group(1).lower()
got = hashlib.sha1(b).hexdigest()
if got == want:
    print(f"MATCH: {built} sha1 {got} (0x{len(b):X} bytes)")
    sys.exit(0)

r = open(retail, "rb").read()
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
        print(f"  differs at file offset 0x{i:X} (vaddr 0x{i - 0x1000 + 0x1D5680:X} if in .lit and up)"
              f": built {b[i:i+8].hex()} retail {r[i:i+8].hex()}")
        shown += 1
        i = j
    i += 1
sys.exit(1)
