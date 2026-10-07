#!/usr/bin/env python3
"""bootstrap_target.py: create a new target's source tree (one-time; kept as the record).

For an executable with no matched twin to copy from (i5bootn; boot_elf had
frontbin, see tools/bootstrap_boot_elf.py). The target must already be in
tools/targets.py, with its splat config and linker script. This makes the tree
the way frontbin's looks today:

  1. Function boundaries: splat's discovery run (every jal target plus
     spimdisasm's analysis, the same as tools/gen_exe_targets.py), plus any
     piece plain splat splits off on its own (setup_asm.py would otherwise drop
     it), then linker remnants glued to the front of a function cut off
     (tools/split_remnant_prefix.py's rule).
  2. Classification. The ELF's entry point is the startup code (crt0.s) and
     becomes ASM_FUNC. Otherwise tools/triage.py's rules: remnant (only [instruction, nop]
     pairs, no return) becomes LINKER_REMNANT, hand-written (spimdisasm's
     "Handwritten function", COP0 performance counters, lq/sq with $at)
     becomes ASM_FUNC, the rest INCLUDE_ASM.
  3. Source files, estimated from what the assembly shows without any C yet:
     runs of three or more hand-written functions are their own file (the
     original was a .s file), and the rest splits where the address mode
     (-mno-split-addresses) changes for three or more functions in a row. A file
     can only start at an 8-aligned function. Moving a boundary later changes
     nothing in the output.
  4. Flags: the target's base_flags (tools/targets.py), plus
     -mno-split-addresses for files that look like N mode. They only matter once
     a function becomes C.
  5. INCLUDE_RODATA lines for the jump tables, divs_nops from
     tools/gen_divs_nops.py, and the symbol file.

    python tools/bootstrap_target.py --target i5bootn

It refuses to run on a tree that already has C in it.
"""
import hashlib, json, os, re, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles as sf  # noqa: E402
from bootstrap_boot_elf import classify_asm, address_mode  # noqa: E402

NL = "\r\n"   # the repo's sources are CRLF


def fileoff(data, vaddr):
    """File offset of vaddr, from the ELF's section headers."""
    import struct
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", data, 0x2E)
    for i in range(shnum):
        _, typ, _, addr, off, size = struct.unpack_from("<6I", data, shoff + i * shentsize)
        if typ != 8 and addr and addr <= vaddr < addr + size:
            return off + vaddr - addr
    return None


def run(*args):
    print("+", " ".join(args), flush=True)
    r = subprocess.run(list(args), cwd=ROOT)
    if r.returncode:
        sys.exit("failed: " + " ".join(args))


def write_tree(T, files, entries, parts_lines, extra_ro=None):
    """files: [(start, unit)], entries: {addr: kind}; writes the target's sources and lists."""
    extra_ro = extra_ro or {}
    for u in T.units:
        d = os.path.join(ROOT, u.src_dir)
        if os.path.isdir(d):
            shutil.rmtree(d)
        os.makedirs(d)
    starts = sorted(files)
    rels = []
    by_file = {}
    for a in sorted(entries):
        f = max(s for s, _ in starts if s <= a and T.unit_for(s) is T.unit_for(a))
        by_file.setdefault(f, []).append(a)
    for s, u in starts:
        rel = "%s/%06X.c" % (u.src_dir, s)
        rels.append((rel, s))
        lines = ['#include "common.h"', ""]
        for a in by_file.get(s, []):
            kind = entries[a]
            name = "func_%08X" % a
            if kind == "ASM_FUNC":
                lines.append('ASM_FUNC("%s", %s);' % (T.handwritten, name))
            elif kind == "LINKER_REMNANT":
                lines.append('LINKER_REMNANT("%s", %s);' % (T.remnants, name))
            else:
                lines.append('INCLUDE_ASM("%s", %s);' % (u.asm_dir, name))
                for t in extra_ro.get(a, []):
                    lines.append('INCLUDE_RODATA("%s/rodata", %s);' % (u.asm_dir, t))
            lines.append("")
        open(os.path.join(ROOT, rel), "w", newline="").write(NL.join(lines))
    os.makedirs(os.path.dirname(T.path("files")), exist_ok=True)
    hdr = ["# %s source files in link order: path and the address of its first function." % T.name,
           "# See tools/bootstrap_target.py for where the boundaries come from."]
    open(T.path("files"), "w", newline="").write(NL.join(hdr + ["%s %08X" % (r, s) for r, s in rels]) + NL)
    open(T.path("parts"), "w", newline="").write(NL.join(parts_lines) + NL)
    return rels


def asm_dirs(T):
    return [os.path.join(ROOT, u.asm_dir) for u in T.units] + [T.path("handwritten"), T.path("remnants")]


def uncovered(T, starts):
    """Addresses where a function's .s stops before the next function starts
    (plain splat split there; see tools/bootstrap_boot_elf.py)."""
    last = {}
    for d in asm_dirs(T):
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            m = re.match(r"func_([0-9A-F]{8})\.s$", f)
            if not m:
                continue
            addrs = [int(x, 16) for x in re.findall(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/",
                                                      open(os.path.join(d, f), errors="ignore").read())]
            if addrs:
                last[int(m.group(1), 16)] = max(addrs) + 4
    data = open(T.path("elf"), "rb").read()
    gaps = []
    for u in T.units:
        st = sorted(a for a in starts if u.contains(a))
        for a, b in zip(st, st[1:] + [u.end]):
            end = last.get(a)
            # all-zero gaps are trailing padding (TEXT_PADDING), not code
            if end is not None and end < b and any(data[fileoff(data, end):fileoff(data, end) + (b - end)]):
                gaps.append(end)
    return gaps


def write_symbols(T):
    """The target's symbol_addrs_resolved.txt: every symbol the asm references
    that no object defines, at the address its name gives."""
    defined, used = set(), set()
    for d, _, fs in os.walk(T.path("asm_root")):
        for f in fs:
            if not f.endswith(".s"):
                continue
            s = open(os.path.join(d, f), errors="ignore").read()
            defined |= set(re.findall(r"^\s*(?:glabel|dlabel|jlabel|alabel)\s+(\w+)", s, re.M))
            used |= set(re.findall(r"\b((?:D|func)_[0-9A-F]+)\b", s))
    lines = ["/* %s: symbols the assembly references that no object defines (tools/bootstrap_target.py). */" % T.name]
    for n in sorted(used - defined):
        lines.append("%s = 0x%s;" % (n, n.split("_")[1]))
    open(T.path("symbols_resolved"), "w", newline="").write(NL.join(lines) + NL)
    print("symbols: %d" % (len(lines) - 1))


def nobits_ranges(data):
    import struct
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", data, 0x2E)
    out = []
    for i in range(shnum):
        _, typ, _, addr, _, size = struct.unpack_from("<6I", data, shoff + i * shentsize)
        if typ == 8 and addr and size:
            out.append((addr, addr + size))
    return out


def add_bss_symbols(T, data):
    """Add D_ names for the .bss/.sbss addresses the asm uses as numbers. True if any were added."""
    ranges = nobits_ranges(data)
    found = set()
    for d in asm_dirs(T):
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            if f.endswith(".s"):
                txt = open(os.path.join(d, f), errors="ignore").read()
                for x in re.findall(r"\((0x[0-9A-Fa-f]+) (?:>> 16|& 0xFFFF)\)", txt):
                    a = int(x, 16)
                    if any(lo <= a < hi for lo, hi in ranges):
                        found.add(a)
    path = T.path("symbol_addrs")
    have = open(path).read() if os.path.exists(path) else ""
    new = ["D_%08X = 0x%08X; // .bss" % (a, a) for a in sorted(found) if ("D_%08X" % a) not in have]
    if new:
        with open(path, "a", newline="") as fh:
            fh.write(NL.join(new) + NL)
        print("%d .bss symbols added to %s" % (len(new), os.path.relpath(path, ROOT)))
    return bool(new)


def file_starts(T, u, seq, entries, modes):
    """Estimated source-file starts for one unit (see the module docstring, step 3)."""
    out = [seq[0]]
    i = 0
    while i < len(seq):  # runs of 3+ hand-written functions (remnants allowed between)
        if entries[seq[i]] == "ASM_FUNC":
            j, n = i, 0
            while j < len(seq) and entries[seq[j]] in ("ASM_FUNC", "LINKER_REMNANT"):
                n += entries[seq[j]] == "ASM_FUNC"
                j += 1
            if n >= 3:
                out.append(seq[i])
                if j < len(seq):
                    out.append(seq[j])
            i = max(j, i + 1)
        else:
            i += 1
    run_mode, run_start, run_len, last_mode = None, None, 0, None
    for a in seq:
        m = modes.get(a)
        if m is None:
            continue
        if m == run_mode:
            run_len += 1
        else:
            run_mode, run_start, run_len = m, a, 1
        if run_len == 3 and last_mode is not None and run_mode != last_mode:
            out.append(run_start)
        if run_len >= 3:
            last_mode = run_mode
    # each file's object .text is 8-aligned, so a file starts at an 8-aligned function
    aligned = set()
    for f in sorted(set(out)):
        nxt = next((a for a in seq if a >= f and a % 8 == 0), None)
        if nxt is not None:
            aligned.add(nxt)
    return sorted(aligned | {seq[0]})


def main():
    T = targets.from_argv()
    if len(sys.argv) > 1:
        sys.exit(__doc__)
    if T.name in ("frontbin", "boot_elf"):
        sys.exit("%s already has its tree (boot_elf's record is tools/bootstrap_boot_elf.py)" % T.name)
    data = open(T.path("elf"), "rb").read()
    if hashlib.sha1(data).hexdigest() != T.sha1:
        sys.exit("%s: wrong sha1" % T.elf)
    if os.path.exists(T.path("files")):
        for rel, _ in sf.read_file_list(T.path("files")):
            if os.path.exists(os.path.join(ROOT, rel)) and "localdecomp:start" in sf.read_source(rel):
                sys.exit("%s already has C in it; refusing to rebuild the tree" % rel)
    work = os.path.join(ROOT, "build", "bootstrap_" + T.name)
    os.makedirs(work, exist_ok=True)
    py = sys.executable

    # 1. boundaries
    cache = os.path.join(work, "found.json")
    if os.path.exists(cache):
        found = json.load(open(cache))
    else:
        from gen_exe_targets import find_functions
        found = find_functions(T.path("elf"), os.path.join(work, "splat"))
        json.dump(found, open(cache, "w"))
    starts = sorted(a for u in T.units for a, _ in found.get(u.section, []))
    print("splat: %d functions" % len(starts))
    base = T.base_flags

    def first_tree():
        entries = {a: "INCLUDE_ASM" for a in starts}
        files = [(min(a for a in starts if u.contains(a)), u) for u in T.units]
        write_tree(T, files, entries, ["0x%08X     %s" % (s, base) for s, _ in sorted(files)])
        return entries

    for k in ("divs_nops", "sq_ra_funcs"):
        open(T.path(k), "w").write("")
    if not os.path.exists(T.path("symbol_addrs")):
        open(T.path("symbol_addrs"), "w", newline="").write("// %s: named symbols for splat (NAME = 0xADDR;)%s" % (T.name, NL))
    first_tree()
    run(py, "tools/setup_asm.py", "--target", T.name)
    while True:
        gaps = uncovered(T, starts)
        if not gaps:
            break
        print("%d pieces splat split off on its own: adding them as functions" % len(gaps))
        starts = sorted(set(starts) | set(gaps))
        first_tree()
        run(py, "tools/setup_asm.py", "--target", T.name)

    # .bss / .sbss: splat has no segment there, so it writes the address as a
    # number ((0x8C5ED4 >> 16)). Name every address the code reaches there in the
    # target's symbol_addrs.txt so the asm (and later the C) uses D_ names.
    if add_bss_symbols(T, data):
        run(py, "tools/setup_asm.py", "--target", T.name)

    import split_remnant_prefix as srp
    added = []
    for a in starts:
        p = os.path.join(ROOT, T.unit_for(a).asm_dir, "func_%08X.s" % a)
        if not os.path.exists(p):
            continue
        _, ins = srp.parse(p)
        k = srp.prefix_pairs(ins)
        if k:
            added.append(ins[k][1])
    if added:
        print("%d remnant prefixes cut off" % len(added))
        starts = sorted(set(starts) | set(added))
        first_tree()
        run(py, "tools/setup_asm.py", "--target", T.name)

    # 2. classification
    entries = {}
    for a in starts:
        c = classify_asm(os.path.join(ROOT, T.unit_for(a).asm_dir, "func_%08X.s" % a))
        entries[a] = {"remnant": "LINKER_REMNANT", "handwritten": "ASM_FUNC"}.get(c, "INCLUDE_ASM")
    # the ELF's entry point is the startup code (crt0), hand-written in every PS2 SDK
    import struct
    entry, = struct.unpack_from("<I", data, 0x18)
    if entry in entries:
        entries[entry] = "ASM_FUNC"
    counts = {}
    for k in entries.values():
        counts[k] = counts.get(k, 0) + 1
    print("classification:", ", ".join("%s %d" % kv for kv in sorted(counts.items())))

    # 3 and 4. source files and flags
    files, parts = [], []
    for u in T.units:
        seq = [a for a in starts if u.contains(a)]
        modes = {a: address_mode(os.path.join(ROOT, u.asm_dir, "func_%08X.s" % a))
                 for a in seq if entries[a] == "INCLUDE_ASM"}
        fs = file_starts(T, u, seq, entries, modes)
        for n, f in enumerate(fs):
            end = fs[n + 1] if n + 1 < len(fs) else u.end
            ms = [modes.get(a) for a in seq if f <= a < end and modes.get(a)]
            nmode = ms and ms.count("N") > ms.count("S")
            parts.append("0x%08X     %s%s" % (f, base, " -mno-split-addresses" if nmode else ""))
            files.append((f, u))
        print("%s: %d source files" % (u.name, len(fs)))
    header = ["# Compiler flags for %s by address (see tools/text_parts.txt for the format)." % T.name,
              "# Estimates from tools/bootstrap_target.py: the target's base flags, plus",
              "# -mno-split-addresses where the assembly looks like N mode."]

    # 5. jump tables, tables, symbols
    ro = {}
    for a in starts:
        p = os.path.join(ROOT, T.unit_for(a).asm_dir, "func_%08X.s" % a)
        if entries[a] == "INCLUDE_ASM" and os.path.exists(p):
            ts = sorted(set(re.findall(r"jtbl_[0-9A-F]{6,8}", open(p).read())))
            if ts:
                ro[a] = ts
    write_tree(T, files, entries, header + parts, ro)
    run(py, "tools/setup_asm.py", "--target", T.name)
    run(py, "tools/gen_divs_nops.py", "--target", T.name)
    run(py, "tools/split_text.py", "--refresh", "--target", T.name)
    write_symbols(T)
    print("done: %d entries (%s)" % (len(entries), ", ".join("%s %d" % kv for kv in sorted(counts.items()))))


if __name__ == "__main__":
    if sys.argv[1:2] == ["--symbols-only"]:
        del sys.argv[1]
        write_symbols(targets.from_argv())
    else:
        main()
