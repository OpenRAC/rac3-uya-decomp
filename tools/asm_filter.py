#!/usr/bin/env python3
"""asm_filter.py: make compiled loops come out the way retail's assembler made them.

The R5900 has a hardware bug with very short loops, so the assembler that
built retail pads every loop to at least 6 instructions (counting the branch
and its delay slot) with nops right before the backward branch. Retail
frontbin has 142 such padded loops and not a single loop shorter than 6.

None of the assemblers we have does exactly that:
  bin/ee-as.exe  never pads a loop gcc wrote in .set noreorder mode;
  Ps2EeAs        pads every loop to 7, one nop too many.

So between gcc and the assembler, this filter rewrites every backward branch
gcc emitted in noreorder mode that closes a loop of 6 or fewer instructions:
it adds nops before the branch until the loop is 6 long, and writes the branch
as a raw `.word` whose offset the assembler computes from the label. A raw
.word is data to the assembler, so neither assembler pads it again, and the
branch bytes are the ones the assembler would have produced.

Loops whose body contains a macro instruction (a load from a symbol, `li`,
...) are left alone, since their length isn't known before assembly. Inline asm
(#APP ... #NO_APP) and .include'd asm files are left alone; the INCLUDE_ASM
files already carry raw branches (tools/fix_short_loops.py).

Used by tools/build_text.py, tools/try_func.py, localdecomp and
tools/permuter_setup.py, so every path compiles C the same way:

    ee-gcc -S ... -o part.s part.c
    python tools/asm_filter.py part.s          # rewrites in place
    ee-gcc -c ... -o part.o part.s
"""
import os, re, sys

REG = {**{"$%d" % i: i for i in range(32)},
       **{"$" + n: i for i, n in enumerate(
           "zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra".split())},
       "$s8": 30}

# mnemonic -> (encoder taking register operands) ; the label is the last operand
TWO = {"beq": 4, "bne": 5, "beql": 0x14, "bnel": 0x15}
ONE = {"blez": 6, "bgtz": 7, "blezl": 0x16, "bgtzl": 0x17}
REGIMM = {"bltz": 0, "bgez": 1, "bltzl": 2, "bgezl": 3, "bltzal": 0x10, "bgezal": 0x11}
BC1 = {"bc1f": 0, "bc1t": 1, "bc1fl": 2, "bc1tl": 3}
PSEUDO_Z = {"beqz": "beq", "bnez": "bne", "beqzl": "beql", "bnezl": "bnel"}


def encode(mn, ops):
    """Branch opcode bits without the offset, or None if not a known branch."""
    if mn in PSEUDO_Z:
        return encode(PSEUDO_Z[mn], [ops[0], "$0"])
    if mn == "b":
        return encode("beq", ["$0", "$0"])
    if mn in TWO:
        return (TWO[mn] << 26) | (REG[ops[0]] << 21) | (REG[ops[1]] << 16)
    if mn in ONE:
        return (ONE[mn] << 26) | (REG[ops[0]] << 21)
    if mn in REGIMM:
        return (1 << 26) | (REG[ops[0]] << 21) | (REGIMM[mn] << 16)
    if mn in BC1:
        return (0x11 << 26) | (8 << 21) | (BC1[mn] << 16)
    return None


BRANCH_RE = re.compile(r"^(\s*)([a-z0-9]+)\s+(.*?)\s*(#.*)?$")
LABEL_RE = re.compile(r"^\s*([$.\w]+):")


SIMPLE_OPS = re.compile(r"^(addu|addiu|subu|and|andi|or|ori|xor|xori|nor|slt|slti|sltu|sltiu|sll|srl|sra|sllv|srlv|srav|"
                        r"daddu|daddiu|dsubu|dsll|dsrl|dsra|dsll32|dsrl32|dsra32|move|negu|not|lui|"
                        r"lb|lbu|lh|lhu|lw|lwu|ld|sb|sh|sw|sd|lwc1|swc1|lq|sq|"
                        r"add\.s|sub\.s|mul\.s|neg\.s|abs\.s|mov\.s|c\.\w+\.s|cvt\.\w+\.\w+|mtc1|mfc1|"
                        r"movz|movn|mult|multu|mult1|multu1|nop)$")


def insn_count(lines):
    """Number of machine instructions in these .s lines, or None if unsure
    (macro instructions, which may expand to more than one word)."""
    n = 0
    for l in lines:
        s = l.split("#", 1)[0].strip()
        if not s or s.startswith(".") or LABEL_RE.match(l):
            continue
        m = re.match(r"([a-z0-9.]+)\s*(.*)", s)
        if not m or not SIMPLE_OPS.match(m.group(1)):
            return None
        ops = m.group(2)
        # a symbol operand (not reg, not N(reg), not a small number) is a macro
        last = ops.split(",")[-1].strip() if ops else ""
        if last and not re.match(r"^(\$\w+|-?\d+|-?0x[0-9a-fA-F]+|-?\d*\(\$\w+\)|-?0x[0-9a-fA-F]+\(\$\w+\)|%\w+\([^)]*\)(\(\$\w+\))?)$", last):
            return None
        if m.group(1) in ("li",):
            return None
        n += 1
    return n


# 13 retail functions save $ra with `sq` (16-byte slot) where gcc 2.95.3 writes
# `sd`, and the ones that also save $s registers lay the slots out ascending
# ($s0 lowest, $ra highest) where gcc puts $ra lowest. No compiler or flag we
# have produces that. The slot set and the frame size are the same, so for the
# functions listed in tools/sq_ra_funcs.txt (compiled without -fopt-stack, which
# already gives sq for the $s registers) every callee-saved save and restore is
# rewritten to the slot retail uses. $ra is written as a raw word (sq =
# 0x7FBF0000 | off, lq = 0x7BBF0000 | off, base $sp), like the retail .s files.
SQ_RA_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "sq_ra_funcs.txt")
SAVE_RE = re.compile(r"^(\s*)(sd|sq|ld|lq)\s+\$(1[6-9]|2[0-3]|30|31|fp),\s*(\d+)\(\$sp\)\s*(#.*)?$")
SAVE_ORDER = [16, 17, 18, 19, 20, 21, 22, 23, 30, 31]


def sq_ra_funcs():
    try:
        with open(SQ_RA_FILE) as f:
            return {l.split("#")[0].strip() for l in f if l.split("#")[0].strip()}
    except OSError:
        return set()


def sq_rewrite(lines):
    """lines: one function's .s lines, from .ent to .end."""
    saves = []  # (index, is_store, reg, offset, indent, line ending)
    for i, l in enumerate(lines):
        body = l.rstrip("\r\n")
        m = SAVE_RE.match(body)
        if m:
            saves.append((i, m.group(2) in ("sd", "sq"), (30 if m.group(3) == "fp" else int(m.group(3))), int(m.group(4)),
                          m.group(1), l[len(body):]))
    regs = sorted({s[2] for s in saves}, key=SAVE_ORDER.index)
    offs = sorted({s[3] for s in saves})
    if not regs or len(regs) != len(offs):
        return lines
    new_off = dict(zip(regs, offs))
    for i, store, reg, off, ind, nl in saves:
        o = new_off[reg]
        if reg == 31:
            w = (0x7FBF0000 if store else 0x7BBF0000) | o
            lines[i] = f"{ind}.word 0x{w:08X}  # {'sq' if store else 'lq'} $31,{o}($sp){nl}"
        else:
            lines[i] = f"{ind}{'sq' if store else 'lq'} {'$fp' if reg == 30 else '$' + str(reg)},{o}($sp){nl}"
    return lines


def sq_pass(text):
    funcs = sq_ra_funcs()
    if not funcs:
        return text
    out, buf, cur = [], [], None
    for line in text.splitlines(True):
        s = line.strip()
        em = re.match(r"\.ent\s+(\S+)", s)
        if cur is None and em and em.group(1) in funcs:
            cur, buf = em.group(1), [line]
            continue
        if cur is not None:
            buf.append(line)
            if re.match(r"\.end\s", s):
                out.extend(sq_rewrite(buf))
                cur, buf = None, []
            continue
        out.append(line)
    out.extend(buf)
    return "".join(out)


def filter_asm(text):
    out, labels, noreorder, app = [], {}, False, False
    text = sq_pass(text)
    for line in text.splitlines(True):
        s = line.strip()
        if s.startswith("#APP"):
            app = True
        elif s.startswith("#NO_APP"):
            app = False
        if app:
            out.append(line)
            continue
        m = LABEL_RE.match(line)
        if m:
            labels[m.group(1)] = len(out)
        if s.startswith(".set"):
            if "noreorder" in s:
                noreorder = True
            elif re.search(r"\breorder\b", s):
                noreorder = False
        if s.startswith((".ent", ".end")) and not s.startswith(".endif"):
            labels = {}  # labels are per function
        bm = BRANCH_RE.match(line)
        if noreorder and bm and not s.startswith("."):
            mn = bm.group(2)
            ops = [o.strip() for o in bm.group(3).split(",")]
            target = ops[-1] if ops else ""
            if target in labels:
                try:
                    bits = encode(mn, ops[:-1])
                except KeyError:
                    bits = None
                n = insn_count(out[labels[target] + 1:]) if bits is not None else None
                if n is not None and n + 2 <= 6:
                    ind = bm.group(1)
                    out.append(f"{ind}nop\n" * (4 - n))
                    out.append(f"{ind}.word 0x{bits:08X} | ((({target} - . - 4) >> 2) & 0xFFFF)"
                               f"  # {mn} {bm.group(3)}\n")
                    continue
        out.append(line)
    return "".join(out)


def main():
    for p in sys.argv[1:]:
        t = open(p, newline="").read()
        open(p, "w", newline="").write(filter_asm(t))


if __name__ == "__main__":
    main()
