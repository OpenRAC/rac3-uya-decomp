#!/usr/bin/env python3
"""triage.py: sort every remaining INCLUDE_ASM function by what it needs.

    python tools/triage.py                 # summary
    python tools/triage.py --tsv docs/remaining_functions.tsv

Reads only the sources in src/frontbin/ and asm/nonmatchings/text/*.s. Each remaining function
gets one bucket, the first that applies:

  remnant      Only [instruction, nop] pairs and no return: the last 8 bytes of
               functions the original linker stripped as unused. Not source.
  handwritten  spimdisasm marks it "Handwritten function" (addi, $at, odd
               register use). The original was assembly.
               tools/migrate_asm_sources.py moves both of these out of
               INCLUDE_ASM (to ASM_FUNC / LINKER_REMNANT), so after it has run
               they no longer show up here.
  odd          No return and not a remnant: probably a bad split. Fix the
               function boundaries before trying C.
  switch       Uses a jump table. Works in C since tools/migrate_jtbls.py;
               delete the INCLUDE_RODATA line(s) with the INCLUDE_ASM.
  vu0          VU0 macro instructions (lqc2, vadd, qmtc2...). Needs inline asm
               for those parts, as the original did.
  mmi          EE 128-bit MMI instructions (pextlw, pcpyld, lq/sq...).
  sys          COP0 / sync / ei / di.
  float-nop    Loads a float from $gp followed by a nop: not reproducible yet
               (see Matching Patterns: known open problems).
  plain        Ordinary compiled C.

Floats loaded through $gp are small-data globals and count as "plain":
declare them sized (`extern f32 D_001D950C;`).
"""
import argparse, collections, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
GP = 0x1DC8B0
LIT_START = 0x1D5680
VU = re.compile(r"^(v[a-z0-9]+(\.[xyzw]+)?|cop2|lqc2|sqc2|qmtc2.*|qmfc2.*|cfc2.*|ctc2.*|vcallms.*|bc2[ft]l?)$")
MMI = re.compile(r"^(p(?!ref)[a-z0-9]+(\.[a-z]+)?|special2|lq|sq|qfsrv|mtsab|mtsah|pmfhl.*|plzcw)$")
SYS = re.compile(r"^(cop0|mfc0|mtc0|ei|di|sync.*|cache|syscall|eret|bc0[ft])$")
INS = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/\s+(\S+)\s*([^\n]*)")


def raw_instruction(word, operands):
    annotated = re.search(r"/\*\s*([a-z][a-z0-9.]*)\b([^*]*)\*/", operands)
    if annotated and annotated.group(1) != "invalid":
        return annotated.group(1), annotated.group(2).strip()
    opcode = word >> 26
    if opcode == 0x10:
        return "cop0", ""
    if opcode == 0x12:
        return "cop2", ""
    if opcode == 0x1E:
        return "lq", ""
    if opcode == 0x1F:
        return "sq", ""
    if opcode == 0x1C and word & 0x3F in (0x04, 0x08, 0x09, 0x28, 0x29, 0x30, 0x31,
                                         0x34, 0x36, 0x37, 0x3C, 0x3E, 0x3F):
        return "special2", ""
    if opcode == 0 and word & 0x3F == 0x0F:
        return "sync", ""
    return ".word", ""


def classify(name):
    unit = targets.get().unit_for(int(name[5:], 16))
    s = open(os.path.join(ROOT, unit.asm_dir, name + ".s"), errors="ignore").read()
    ins = []
    for line in s.splitlines():
        m = INS.search(line)
        if m:  # the comment holds the word's bytes in file (little-endian) order
            word = int.from_bytes(bytes.fromhex(m.group(2)), "little")
            mnemonic, operands = m.group(3), m.group(4)
            if mnemonic == ".word":
                mnemonic, operands = raw_instruction(word, operands)
            ins.append((word, mnemonic, operands))
            continue
        w = re.match(r"\s*\.word\s+(0x[0-9A-Fa-f]+)", line)
        if w:  # raw words (short-loop branches, undecodable opcodes)
            # The mnemonic, when it is known, lives in a trailing comment:
            #   .word 0x78A10000 /* lq $at, 0x0($5) */
            # tools/fix_quadword_ops.py writes lq/sq/lqc2/sqc2 that way, and a
            # function whose only 128-bit ops are raw words was landing in
            # "plain" because the op read ".word" here.
            word = int(w.group(1), 16)
            mnemonic, operands = raw_instruction(word, line[w.end():])
            ins.append((word, mnemonic, operands))
    m = re.search(r"nonmatching \w+, (0x[0-9A-Fa-f]+)", s)
    size = int(m.group(1), 16) if m else 4 * len(ins)
    words = [w for w, _, _ in ins]
    ops = [o for _, o, _ in ins]
    has_return = any(w == 0x03E00008 or (w >> 26) == 2 or (w & 0xFC00003F) == 8 for w in words)
    if not has_return and len(words) % 2 == 0 and words and all(words[i + 1] == 0 for i in range(0, len(words), 2)):
        return "remnant", size
    if "Handwritten function" in s:
        return "handwritten", size
    # Two shapes spimdisasm doesn't flag but no compiler produces: the COP0
    # performance-counter ops (mfpc/mtpc, which it can't decode), and lq/sq with
    # $at as the data register. Both only occur in the hand-written .s files.
    for w, o, operands in ins:
        if (w >> 26) == 0x10 and ((w >> 21) & 31) in (0, 4) and (w & 0x7FF):
            return "handwritten", size  # mfpc/mtpc: mfc0/mtc0 have the low 11 bits clear
        if (w >> 26) in (0x1E, 0x1F) and ((w >> 16) & 31) == 1:
            return "handwritten", size
    if not has_return:
        return "odd", size
    if "jtbl_" in s:
        return "switch", size
    if any(VU.match(o) for o in ops):
        return "vu0", size
    if any(MMI.match(o) for o in ops):
        return "mmi", size
    if any(SYS.match(o) for o in ops):
        return "sys", size
    lines = s.splitlines()
    for i, l in enumerate(lines):
        g = re.search(r"lwc1\s+\$f\d+, (-?0x[0-9A-Fa-f]+)\(\$gp\)", l)
        if g and i + 1 < len(lines) and re.search(r"\*/\s+nop\b", lines[i + 1]):
            return "float-nop", size
    return "plain", size


def main():
    t = targets.from_argv()   # --target boot_elf
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--tsv", help="write name, address, size, bucket to this file")
    ap.add_argument("--unit", help="only this code section (boot_elf: core or text)")
    args = ap.parse_args()
    import srcfiles
    text = srcfiles.read_all(ROOT)
    names = re.findall(r'INCLUDE_ASM\("[^"]+",\s*(func_[0-9A-Fa-f]{8})\)', text)
    if args.unit:
        names = [n for n in names if t.unit(args.unit).contains(int(n[5:], 16))]
    rows = [(n,) + classify(n) for n in names]
    count, size = collections.Counter(), collections.Counter()
    for _, b, sz in rows:
        count[b] += 1
        size[b] += sz
    order = ["plain", "switch", "vu0", "mmi", "sys", "float-nop", "odd", "handwritten", "remnant"]
    print(f"{'bucket':<12}{'functions':>10}{'bytes':>10}")
    for b in order:
        if count[b]:
            print(f"{b:<12}{count[b]:>10}{size[b]:>#10x}")
    print(f"{'total':<12}{len(rows):>10}{sum(size.values()):>#10x}")
    small = sum(1 for _, b, sz in rows if b == "plain" and sz < 0x100)
    print(f"plain functions under 0x100 bytes: {small}")
    if args.tsv:
        with open(args.tsv, "w") as f:
            f.write("function\taddress\tsize\tbucket\n")
            for n, b, sz in sorted(rows, key=lambda r: (order.index(r[1]), r[2])):
                f.write(f"{n}\t0x{n[5:]}\t0x{sz:X}\t{b}\n")
        print("wrote", args.tsv)


if __name__ == "__main__":
    main()
