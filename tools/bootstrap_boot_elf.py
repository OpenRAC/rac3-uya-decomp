#!/usr/bin/env python3
"""bootstrap_boot_elf.py: create boot_elf's source tree (one-time; kept as the record).

boot_elf.elf has two code sections:

  core.text (0x116F80)  the engine core and Sony's libraries. Unrelated to frontbin.
  .text     (0x381180)  a front-end overlay. It is frontbin's code linked at other
                        addresses: 1,860 of frontbin's 1,861 functions are in it,
                        identical once address immediates are masked.

This script makes the tree the way frontbin's looks today, not the way frontbin
started (one big text.c with raw splat boundaries):

  1. Function boundaries.
       .text: frontbin's curated boundaries (remnants already cut off, bad splits
              fixed), carried over by aligning the two sections word by word with
              address immediates masked. Where boot_elf has code frontbin doesn't,
              splat's boundaries are used.
       core:  splat's boundaries (every jal target plus spimdisasm's analysis, the
              same discovery tools/gen_exe_targets.py used for the reference
              objects), then linker remnants glued to the front of a function are
              cut off (tools/split_remnant_prefix.py's rule).
  2. Classification.
       .text: a function that is ASM_FUNC / LINKER_REMNANT in frontbin and has the
              same code here is the same here.
       other: tools/triage.py's rules (remnant: only [instruction, nop] pairs and no
              return; handwritten: spimdisasm's "Handwritten function", COP0
              performance counters, lq/sq with $at).
  3. Source files.
       .text: frontbin's files (tools/src_files.txt), each starting at its first
              function's new address. Named after that address, like frontbin's.
       core:  estimated from the evidence available without any C yet:
              runs of hand-written functions are their own file (the original was a
              .s file), and the address mode seen in the assembly (-mno-split-
              addresses makes every global access an adjacent lui/%lo pair on one
              register) splits the rest where it changes for three or more
              functions in a row. Like frontbin's, these are estimates; moving a
              boundary changes nothing in the output.
  4. Flags (targets/boot_elf/text_parts.txt).
       .text: frontbin's lines, moved to the new addresses.
       core:  the project's base flags, plus -mno-split-addresses for files that
              look like N mode. They only matter once a function becomes C.
  5. Per-function tables: sq_ra_funcs and divs_nops entries for .text functions
     carried over from frontbin; divs_nops for everything still INCLUDE_ASM then
     comes from tools/gen_divs_nops.py --target boot_elf.

Then it runs tools/setup_asm.py --target boot_elf, adds the INCLUDE_RODATA lines for
the overlay's jump tables and writes targets/boot_elf/symbol_addrs_resolved.txt.

    python tools/bootstrap_boot_elf.py   (needs frontbin.elf, boot_elf.elf, frontbin's asm/)
"""
import difflib, hashlib, json, os, re, shutil, struct, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles as sf  # noqa: E402
import build_text as bt  # noqa: E402

FB = targets.get("frontbin")
BE = targets.get("boot_elf")
BASE = "-O2 -G8 -fopt-stack -mno-check-zero-division"
HI_LO = {0x0F, 0x09, 0x08, 0x0D, 0x23, 0x2B, 0x21, 0x25, 0x29, 0x24, 0x20, 0x28, 0x31, 0x39,
         0x37, 0x3F, 0x1E, 0x1F, 0x1A, 0x1B, 0x36, 0x3E}
NL = "\r\n"   # the repo's sources are CRLF


def mask(w):
    op = w >> 26
    if op in (2, 3):
        return w & 0xFC000000
    if op in HI_LO:
        return w & 0xFFFF0000
    return w


def section_words(data, foff, size):
    return list(struct.unpack_from("<%dI" % (size // 4), data, foff))


def asm_size(path):
    m = re.search(r"nonmatching (func_[0-9A-F]{8}), (0x[0-9A-Fa-f]+)", open(path, errors="replace").read())
    return int(m.group(2), 16) if m else None


# ------------------------------------------------------------ frontbin side

def frontbin_entries():
    """[(addr, kind)] in link order; kind is C, INCLUDE_ASM, ASM_FUNC or LINKER_REMNANT."""
    out = []
    for rel, _ in sf.read_file_list(FB.path("files")):
        _, _, chunks = sf.split_file(sf.read_source(rel))
        seen = set()
        for addr, _, body in chunks:
            if addr in seen:
                continue
            name = "func_%08X" % addr
            if ("localdecomp:start " + name) in body:
                kind = "C"
            else:
                m = re.search(r"^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\(\"[^\"]*\",\s*%s\)" % name, body, re.M)
                if not m:
                    continue
                kind = m.group(1)
            seen.add(addr)
            out.append((addr, kind))
    return out


def frontbin_size(addr):
    name = "func_%08X.s" % addr
    for d in (FB.unit("text").asm_dir, FB.handwritten, FB.remnants):
        p = os.path.join(ROOT, d, name)
        if os.path.exists(p):
            return asm_size(p)
    return None


# ------------------------------------------------------------ alignment

def align_text(fdata, bdata):
    fu, bu = FB.unit("text"), BE.unit("text")
    foff = fu.start - 0x37D100 + 0x1A8A80
    boff = bu.start - 0x381180 + 0x283100
    fw = [mask(w) for w in section_words(fdata, foff, fu.end - fu.start)]
    bw = [mask(w) for w in section_words(bdata, boff, bu.end - bu.start)]
    print("aligning %d frontbin words with %d boot_elf words..." % (len(fw), len(bw)), flush=True)
    blocks = difflib.SequenceMatcher(None, fw, bw, autojunk=False).get_matching_blocks()
    wmap = {}
    for a, b, n in blocks:
        for k in range(n):
            wmap[a + k] = b + k
    print("aligned %d words" % len(wmap))
    return wmap


# ------------------------------------------------------------ classification

INS = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/\s+(\S+)\s*([^\n]*)")


def classify_asm(path):
    """triage.py's remnant / handwritten rules on one .s file: 'remnant', 'handwritten' or None."""
    s = open(path, errors="ignore").read()
    words = []
    for line in s.splitlines():
        m = INS.search(line)
        if m:
            words.append(int.from_bytes(bytes.fromhex(m.group(2)), "little"))
            continue
        w = re.match(r"\s*\.word\s+(0x[0-9A-Fa-f]+)", line)
        if w:
            words.append(int(w.group(1), 16))
    has_return = any(w == 0x03E00008 or (w >> 26) == 2 or (w & 0xFC00003F) == 8 for w in words)
    if not has_return and words and len(words) % 2 == 0 and all(words[i + 1] == 0 for i in range(0, len(words), 2)):
        return "remnant"
    if "Handwritten function" in s:
        return "handwritten"
    for w in words:
        if (w >> 26) == 0x10 and ((w >> 21) & 31) in (0, 4) and (w & 0x7FF):
            return "handwritten"
        if (w >> 26) in (0x1E, 0x1F) and ((w >> 16) & 31) == 1:
            return "handwritten"
    return None


def address_mode(path):
    """'N', 'S' or None from the global accesses in one .s (see the module docstring)."""
    ins = [m.groups() for m in (INS.search(l) for l in open(path, errors="ignore").read().splitlines()) if m]
    pairs = adjacent = 0
    for i, (_, _, op, args) in enumerate(ins):
        m = re.match(r"(\$\w+), %hi\((\w+)\)", args) if op == "lui" else None
        if not m:
            continue
        pairs += 1
        nxt = ins[i + 1][3] if i + 1 < len(ins) else ""
        if ("%%lo(%s)" % m.group(2)) in nxt and m.group(1) in nxt:
            adjacent += 1
    if pairs < 2:
        return None
    r = adjacent / pairs
    return "N" if r == 1.0 else "S" if r <= 0.5 else None


# ------------------------------------------------------------ writing the tree

def write_tree(files, entries, parts_lines, extra_ro=None):
    """files: [(start, unit)], entries: {addr: kind}; writes src/boot_elf/** and the lists."""
    extra_ro = extra_ro or {}
    for u in BE.units:
        d = os.path.join(ROOT, u.src_dir)
        if os.path.isdir(d):
            shutil.rmtree(d)
        os.makedirs(d)
    starts = sorted(files)
    rels = []
    by_file = {}
    for a in sorted(entries):
        f = max(s for s, _ in starts if s <= a and BE.unit_for(s) is BE.unit_for(a))
        by_file.setdefault(f, []).append(a)
    for s, u in starts:
        rel = "%s/%06X.c" % (u.src_dir, s)
        rels.append((rel, s))
        lines = ['#include "common.h"', ""]
        for a in by_file.get(s, []):
            kind = entries[a]
            name = "func_%08X" % a
            if kind == "ASM_FUNC":
                lines.append('ASM_FUNC("%s", %s);' % (BE.handwritten, name))
            elif kind == "LINKER_REMNANT":
                lines.append('LINKER_REMNANT("%s", %s);' % (BE.remnants, name))
            else:
                lines.append('INCLUDE_ASM("%s", %s);' % (u.asm_dir, name))
                for t in extra_ro.get(a, []):
                    lines.append('INCLUDE_RODATA("%s/rodata", %s);' % (u.asm_dir, t))
            lines.append("")
        open(os.path.join(ROOT, rel), "w", newline="").write(NL.join(lines))
    os.makedirs(os.path.dirname(BE.path("files")), exist_ok=True)
    hdr = ["# boot_elf source files in link order: path and the address of its first function.",
           "# core.text files first (0x116F80..), then the overlay .text (0x381180..).",
           "# See tools/bootstrap_boot_elf.py for where the boundaries come from."]
    open(BE.path("files"), "w", newline="").write(NL.join(hdr + ["%s %08X" % (r, s) for r, s in rels]) + NL)
    open(BE.path("parts"), "w", newline="").write(NL.join(parts_lines) + NL)
    return rels


def uncovered(starts_by_unit):
    """Addresses where a function's .s stops before the next function starts.
    setup_asm runs plain splat, which can split where the discovery run didn't;
    splat only writes a .s for functions the sources list, so those pieces would
    be dropped. Each gap start is a function splat wants."""
    dirs = [os.path.join(ROOT, u.asm_dir) for u in BE.units] + [BE.path("handwritten"), BE.path("remnants")]
    last = {}
    for d in dirs:
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
    data = open(BE.path("elf"), "rb").read()
    foff = lambda va: va - 0x100080 + 0x2000     # boot_elf's first PT_LOAD
    gaps = []
    for u in BE.units:
        st = sorted(a for a in starts_by_unit if u.contains(a))
        for a, b in zip(st, st[1:] + [u.end]):
            end = last.get(a)
            # all-zero gaps are trailing padding (TEXT_PADDING), not code
            if end is not None and end < b and any(data[foff(end):foff(b)]):
                gaps.append(end)
    return gaps


def run(*args):
    print("+", " ".join(args), flush=True)
    r = subprocess.run(list(args), cwd=ROOT)
    if r.returncode:
        sys.exit("failed: " + " ".join(args))


def main():
    fdata = open(FB.path("elf"), "rb").read()
    bdata = open(BE.path("elf"), "rb").read()
    for t, d in ((FB, fdata), (BE, bdata)):
        if hashlib.sha1(d).hexdigest() != t.sha1:
            sys.exit("%s: wrong sha1" % t.elf)
    work = os.path.join(ROOT, "build", "bootstrap_boot_elf")
    os.makedirs(work, exist_ok=True)

    # 1a. splat's boundaries (discovery run, as for the reference objects)
    cache = os.path.join(work, "found.json")
    if os.path.exists(cache):
        found = {k: [tuple(x) for x in v] for k, v in json.load(open(cache)).items()}
    else:
        from gen_exe_targets import find_functions
        found = find_functions(BE.path("elf"), os.path.join(work, "splat"))
        json.dump(found, open(cache, "w"))
    core_starts = sorted(a for a, _ in found["core.text"])
    splat_text = sorted(a for a, _ in found[".text"])
    print("splat: %d core functions, %d overlay functions" % (len(core_starts), len(splat_text)))

    # 1b. frontbin's boundaries carried over
    fents = frontbin_entries()
    wmap = align_text(fdata, bdata)
    fstart, bstart = FB.unit("text").start, BE.unit("text").start
    fmap = {}       # frontbin addr -> boot addr
    same = set()    # frontbin functions whose whole body aligns unchanged
    for addr, kind in fents:
        i = (addr - fstart) // 4
        if i in wmap:
            fmap[addr] = bstart + 4 * wmap[i]
            size = frontbin_size(addr)
            if size and all(wmap.get(i + k) == wmap[i] + k for k in range(size // 4)):
                same.add(addr)
    aligned_boot = set(wmap.values())
    boot_only = [a for a in splat_text if (a - bstart) // 4 not in aligned_boot]
    text_starts = sorted(set(fmap.values()) | set(boot_only))
    print("overlay: %d functions from frontbin (%d unchanged), %d from splat where boot_elf has its own code"
          % (len(fmap), len(same), len(boot_only)))

    # 2. first pass: everything INCLUDE_ASM, to get one .s per function
    entries = {a: "INCLUDE_ASM" for a in core_starts + text_starts}
    files = [(core_starts[0], BE.unit("core")), (text_starts[0], BE.unit("text"))]
    write_tree(files, entries, ["0x%08X     %s" % (core_starts[0], BASE), "0x%08X     %s" % (text_starts[0], BASE)])
    open(BE.path("divs_nops"), "w").write("")
    open(BE.path("sq_ra_funcs"), "w").write("")
    py = sys.executable
    run(py, "tools/setup_asm.py", "--target", "boot_elf")
    while True:
        gaps = uncovered(core_starts + text_starts)
        if not gaps:
            break
        print("%d pieces splat split off on its own: adding them as functions" % len(gaps))
        core_starts = sorted(set(core_starts) | {g for g in gaps if BE.unit("core").contains(g)})
        text_starts = sorted(set(text_starts) | {g for g in gaps if BE.unit("text").contains(g)})
        entries = {a: "INCLUDE_ASM" for a in core_starts + text_starts}
        write_tree(files, entries, ["0x%08X     %s" % (core_starts[0], BASE), "0x%08X     %s" % (text_starts[0], BASE)])
        run(py, "tools/setup_asm.py", "--target", "boot_elf")

    # 2b. remnants glued to the front of core functions (split_remnant_prefix.py's rule)
    import split_remnant_prefix as srp
    cdir = os.path.join(ROOT, BE.unit("core").asm_dir)
    added = []
    for a in core_starts:
        p = os.path.join(cdir, "func_%08X.s" % a)
        if not os.path.exists(p):
            continue
        _, ins = srp.parse(p)
        k = srp.prefix_pairs(ins)
        if k:
            added.append(ins[k][1])
    if added:
        print("core: %d remnant prefixes cut off" % len(added))
        core_starts = sorted(set(core_starts) | set(added))
        entries = {a: "INCLUDE_ASM" for a in core_starts + text_starts}
        write_tree(files, entries, ["0x%08X     %s" % (core_starts[0], BASE), "0x%08X     %s" % (text_starts[0], BASE)])
        run(py, "tools/setup_asm.py", "--target", "boot_elf")

    # 2c. classification
    fkind = dict(fents)
    inv = {v: k for k, v in fmap.items()}
    tdir = os.path.join(ROOT, BE.unit("text").asm_dir)
    for a in core_starts + text_starts:
        fa = inv.get(a)
        if fa is not None and fa in same:
            # unchanged from frontbin: frontbin's classification stands (some functions
            # spimdisasm calls hand-written are C there)
            entries[a] = fkind[fa] if fkind[fa] in ("ASM_FUNC", "LINKER_REMNANT") else "INCLUDE_ASM"
            continue
        d = cdir if BE.unit("core").contains(a) else tdir
        c = classify_asm(os.path.join(d, "func_%08X.s" % a))
        if c == "remnant":
            entries[a] = "LINKER_REMNANT"
        elif c == "handwritten":
            entries[a] = "ASM_FUNC"
    counts = {}
    for a, k in entries.items():
        key = ("core" if BE.unit("core").contains(a) else "text", k)
        counts[key] = counts.get(key, 0) + 1
    print("classification:", ", ".join("%s %s %d" % (u, k, n) for (u, k), n in sorted(counts.items())))

    # 3. source files
    ffiles = sf.read_file_list(FB.path("files"))
    text_files = []
    for rel, s in ffiles:
        if s in fmap:
            text_files.append(fmap[s])
        else:  # a file whose first function moved: use its first mapped function
            later = [fmap[a] for a, _ in fents if a >= s and a in fmap]
            text_files.append(min(later))
    text_files = sorted(set(text_files))
    if text_files[0] != text_starts[0]:
        text_files[0] = text_starts[0]
    # core: hand-written runs and address-mode runs
    modes = {}
    for a in core_starts:
        if entries[a] == "INCLUDE_ASM":
            modes[a] = address_mode(os.path.join(cdir, "func_%08X.s" % a))
    core_files = [core_starts[0]]
    seq = core_starts
    i = 0
    while i < len(seq):  # runs of 3+ hand-written functions (remnants allowed between)
        if entries[seq[i]] == "ASM_FUNC":
            j = i
            n = 0
            while j < len(seq) and entries[seq[j]] in ("ASM_FUNC", "LINKER_REMNANT"):
                n += entries[seq[j]] == "ASM_FUNC"
                j += 1
            if n >= 3:
                core_files.append(seq[i])
                if j < len(seq):
                    core_files.append(seq[j])
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
            core_files.append(run_start)
        if run_len >= 3:
            last_mode = run_mode
    # Each file becomes one object whose .text is 8-byte aligned, so a file must start
    # on an 8-byte boundary: some core functions (Sony libraries, hand-written code)
    # don't. Move such a boundary forward to the next aligned function.
    aligned = []
    for f in sorted(set(core_files)):
        nxt = next((a for a in core_starts if a >= f and a % 8 == 0), None)
        if nxt is not None:
            aligned.append(nxt)
    core_files = sorted(set(aligned) | {core_starts[0]})
    print("source files: %d core, %d overlay (frontbin has %d)" % (len(core_files), len(text_files), len(ffiles)))

    # 4. flags
    fparts = bt.read_parts(FB.path("parts"))
    parts = []
    for f in core_files:
        nf = [a for a in core_starts if a >= f and (core_files.index(f) + 1 == len(core_files)
                                                   or a < core_files[core_files.index(f) + 1])]
        ms = [modes.get(a) for a in nf if modes.get(a)]
        n_mode = ms and ms.count("N") > ms.count("S")
        parts.append("0x%08X     %s%s" % (f, BASE, " -mno-split-addresses" if n_mode else ""))
    def boot_of(fa):
        i = (fa - fstart) // 4
        if i in wmap:
            return bstart + 4 * wmap[i]
        later = [fmap[a] for a, _ in fents if a >= fa and a in fmap]
        return min(later) if later else None
    raw = {}
    for line in open(FB.path("parts")):
        body, _, comment = line.rstrip("\r\n").partition("#")
        fields = body.split()
        if not fields:
            continue
        b = boot_of(int(fields[0], 16))
        if b is None:
            continue
        raw[b] = "0x%08X     %s%s" % (b, " ".join(fields[1:]), ("   #" + comment) if comment else "")
    if text_starts[0] not in raw:
        raw[text_starts[0]] = "0x%08X     %s" % (text_starts[0], " ".join(bt.flags_for(fparts, fstart)))
    parts += [raw[k] for k in sorted(raw)]
    header = ["# Compiler flags for boot_elf by address (see tools/text_parts.txt for the format).",
              "# core.text: base flags, -mno-split-addresses where the assembly looks like N mode",
              "# (tools/bootstrap_boot_elf.py). Overlay .text: frontbin's lines at the new addresses."]

    # 5. per-function tables carried over from frontbin (only for unchanged functions)
    def carry(path_from, path_to):
        out = []
        for line in open(path_from):
            body = line.split("#", 1)[0].split()
            if not body or not body[0].startswith("func_"):
                continue
            fa = int(body[0][5:], 16)
            if fa in same:
                out.append(" ".join(["func_%08X" % fmap[fa]] + body[1:]))
        open(path_to, "w", newline="").write(NL.join(out) + (NL if out else ""))
        return len(out)
    print("carried over: %d sq_ra_funcs, %d divs_nops lines"
          % (carry(FB.path("sq_ra_funcs"), BE.path("sq_ra_funcs")), carry(FB.path("divs_nops"), BE.path("divs_nops"))))

    # jump tables: which overlay function uses which table
    ro = {}
    for a in text_starts:
        p = os.path.join(tdir, "func_%08X.s" % a)
        if entries[a] == "INCLUDE_ASM" and os.path.exists(p):
            ts = sorted(set(re.findall(r"jtbl_[0-9A-F]{8}", open(p).read())))
            if ts:
                ro[a] = ts

    files = [(f, BE.unit("core")) for f in core_files] + [(f, BE.unit("text")) for f in text_files]
    write_tree(files, entries, header + parts, ro)
    run(py, "tools/setup_asm.py", "--target", "boot_elf")
    have_ro = set(os.listdir(os.path.join(tdir, "rodata"))) if os.path.isdir(os.path.join(tdir, "rodata")) else set()
    used = {t + ".s" for ts in ro.values() for t in ts}
    if have_ro != used:
        print("WARNING: jump tables without a user: %s; users without a table: %s"
              % (sorted(have_ro - used)[:10], sorted(used - have_ro)[:10]))
    write_symbols()
    print("done")


def write_symbols():
    """targets/boot_elf/symbol_addrs_resolved.txt: every symbol the asm references
    that no object defines, at the address its name gives."""
    defined, used = set(), set()
    root = BE.path("asm_root")
    for d, _, fs in os.walk(root):
        for f in fs:
            if not f.endswith(".s"):
                continue
            s = open(os.path.join(d, f), errors="ignore").read()
            defined |= set(re.findall(r"^\s*(?:glabel|dlabel|jlabel|alabel)\s+(\w+)", s, re.M))
            used |= set(re.findall(r"\b((?:D|func)_[0-9A-F]+)\b", s))
    lines = ["/* boot_elf: symbols the assembly references that no object defines (tools/bootstrap_boot_elf.py). */"]
    for n in sorted(used - defined):
        if n.startswith(("D_", "func_")):
            lines.append("%s = 0x%s;" % (n, n.split("_")[1]))
    open(BE.path("symbols_resolved"), "w", newline="").write(NL.join(lines) + NL)
    print("symbols: %d" % (len(lines) - 1))


if __name__ == "__main__":
    if sys.argv[1:] == ["--symbols-only"]:
        write_symbols()
    else:
        main()
