#!/usr/bin/env python3
"""asm_profile.py: read a function's compiler profile off its retail bytes.

Every function was built either with split addresses (S, gcc's default) or with
-mno-split-addresses (N), and assembled either by SN's GNU as (bin/ee-as.exe,
"default") or by SN's own Ps2EeAs ("ps2as", text_parts.txt's @ps2as). Both
choices leave marks in the instructions (docs/wiki/Matching-Patterns.md,
"Reading the profile off retail"):

  address mode
    S  gcc's own %hi/%lo split of an address in RAM: a `lui` whose register
       feeds two accesses, sits apart from its use, or is not the assembler's
       temporary (`$at` for stores and FPU accesses, the destination for loads)
    N  an assembler macro to an object outside small data (`lui $at` + access,
       `lui $at; addu $at, $at, $r` + access), or a large immediate built in
       `$at` (`addu $a0, $a0, 0x1fca8`): S mode would have split it in gcc;
       weakly, small data reached only through macros and no split at all
  assembler
    Ps2EeAs  a float constant built inline (`lui $at; ori $at; mtc1 $at`; GNU
             as puts it in .lit4); a 64-bit constant in Ps2EeAs's own `dli`
             expansion; one small-data global reached through both $gp and
             `lui`; `mfc1 $r` read by the next instruction, or an FPU
             instruction right after `mtc1`, without a nop; in S mode, small
             data reached through an assembler macro (Ps2EeAs is single-pass and
             learns symbol sizes from the `.extern`s gcc writes at the end)
    GNU as   a 64-bit constant in GNU as's `dli` expansion; a `nop` after
             `mtc1` that the next FPU instruction does not need

A function that reaches no global and builds no constant shows neither; that
choice is then "unknown" (callers keep their range's or donor's flags, and an
unknown assembler is most often the default one).

    python tools/asm_profile.py --target frontbin func_003B5128
    python tools/asm_profile.py --target veldin func_00495980 func_004CF578
    python tools/asm_profile.py func_00495980              (a common-level function)
    python tools/asm_profile.py --evaluate [--target frontbin|boot_elf|veldin|common|all] [--verify]

--evaluate compares the guess with the flags every matched function is built
with (config/<t>/text_parts.txt, tools/common_c.json); --verify also
builds every disagreement with the guess, to count those whose bytes do not
depend on that choice. tools/try_func.py, tools/try_level.py and
tools/seed_levels.py use guess() / profile_of() for their first try.
"""
import argparse, collections, csv, json, os, re, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402

GP = 0x1DC8B0
AT, GPR = 1, 28
RAM = (0x100000, 0x2000000)   # where a program's symbols are: past the kernel, inside the 32 MB

# opcodes
LUI, ADDIU, DADDIU, ORI = 0x0F, 0x09, 0x19, 0x0D
GLOADS = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x37, 0x1A, 0x1B, 0x1E}  # GPR destination
CLOADS = {0x31, 0x35, 0x36}                                                         # lwc1 ldc1 lqc2
GSTORES = {0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x3F, 0x1F}
CSTORES = {0x39, 0x3D, 0x3E}                                                        # swc1 sdc1 sqc2
MEM = GLOADS | CLOADS | GSTORES | CSTORES
BRANCH = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}


def sext(v):
    return v - 0x10000 if v & 0x8000 else v


def is_branch(w):
    op = w >> 26
    if op in BRANCH:
        return True
    if op == 0 and (w & 0x3F) in (8, 9):            # jr, jalr
        return True
    return op == 0x11 and (w >> 21) & 31 == 8       # bc1*


def gpr_reads(w):
    op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
    if op == 0:
        fn = w & 0x3F
        if fn in (0x10, 0x12):                       # mfhi mflo
            return set()
        if fn in (0, 2, 3, 0x38, 0x3A, 0x3B, 0x3C, 0x3E, 0x3F):  # shifts by sa
            r = {rt}
        elif fn in (8, 9, 0x11, 0x13):               # jr jalr mthi mtlo
            r = {rs}
        else:
            r = {rs, rt}
    elif op == 1 or op in (6, 7, 0x16, 0x17):
        r = {rs}
    elif op in (4, 5, 0x14, 0x15):
        r = {rs, rt}
    elif 8 <= op <= 0x0E or op in (0x18, 0x19):
        r = {rs}
    elif op in GLOADS:
        r = {rs, rt} if op in (0x22, 0x26, 0x1A, 0x1B) else {rs}
    elif op in GSTORES:
        r = {rs, rt}
    elif op in CLOADS or op in CSTORES:
        r = {rs}
    elif op == 0x11:
        r = {rt} if rs in (4, 6) else set()          # mtc1 ctc1
    elif op == 0x12:
        r = {rt} if rs in (5, 6) else set()          # qmtc2 ctc2
    elif op == 0x1C:
        r = {rs, rt}
    else:
        r = set()
    return r - {0}


def gpr_write(w):
    op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op == 0:
        fn = w & 0x3F
        return None if fn in (8, 0x0C, 0x0D, 0x0F, 0x11, 0x13, 0x1A, 0x1B) else rd
    if op == 3:
        return 31
    if 8 <= op <= 0x0F or op in (0x18, 0x19) or op in GLOADS:
        return rt
    if op == 0x11 and rs in (0, 2):                  # mfc1 cfc1
        return rt
    if op == 0x12 and rs in (1, 2):
        return rt
    if op == 0x1C:
        return rd
    return None


def fpr_reads(w):
    op, rs, ft, fs = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op in (0x39, 0x3D):                           # swc1 sdc1
        return {ft}
    if op != 0x11:
        return set()
    if rs == 0:                                      # mfc1
        return {fs}
    if rs in (16, 20):
        fn = w & 0x3F
        if fn == 4:                                  # sqrt.s
            return {ft}
        if fn in (5, 6, 7, 0x20, 0x24):              # abs mov neg cvt
            return {fs}
        return {fs, ft}
    return set()


def word(code, i):
    return struct.unpack_from("<I", code, 4 * i)[0]


def in_small(addr, gp=GP):
    return gp - 0x8000 <= addr < gp + 0x8000


class Fact:
    """One observation: kind (see the rule tables below), where, and what."""
    def __init__(self, kind, at, text, target=None):
        self.kind, self.at, self.text, self.target = kind, at, text, target


def lui_uses(ws, i, r):
    """Instructions after the lui at i that read register r, until r is
    overwritten or the function returns: [(index, kind)] where kind is
    "base" (memory base or addiu/daddiu source), "ori" or "other"."""
    out, n = [], len(ws)
    j = i + 1
    while j < n:
        w = ws[j]
        op, rs = w >> 26, (w >> 21) & 31
        if r in gpr_reads(w):
            if (op in MEM or op in (ADDIU, DADDIU)) and rs == r:
                out.append((j, "base"))
            elif op == ORI and rs == r:
                out.append((j, "ori"))
            else:
                out.append((j, "other"))
        if gpr_write(w) == r:
            break
        if w == 0x03E00008:                           # jr $ra: the delay slot, then stop
            if j + 1 < n and r in gpr_reads(ws[j + 1]):
                out.append((j + 1, "other"))
            break
        j += 1
    return out


def dli_style(ws, i):
    """("dli_ps2as"|"dli_gnu", text) for the 64-bit constant expansion that
    starts at i (a constant load followed by a doubleword shift of the same
    register), or None if both assemblers write it the same way. Assembling
    `dli` with both: Ps2EeAs starts with a 16-bit immediate whose top bit is
    set and shifts by whatever it takes (`ori 0xc800; dsll 22; ori 0x68`), and
    builds 1 << 63 as `addiu -1; dsll32 31`; GNU as starts with `lui` or a
    small immediate and shifts by 16 or 32 between the `ori`s
    (`addiu 50; dsll32 0; ori 0x68`)."""
    w, r = ws[i], (ws[i] >> 16) & 31
    seq, j = [w], i + 1
    while j < len(ws):
        x = ws[j]
        if x >> 26 == 0 and x & 0x3F in (0x38, 0x3C, 0x3A, 0x3E) and (x >> 16) & 31 == r and (x >> 11) & 31 == r:
            seq.append(x)
        elif x >> 26 == ORI and (x >> 16) & 31 == r and (x >> 21) & 31 == r:
            seq.append(x)
        else:
            break
        j += 1
    op, imm = w >> 26, w & 0xFFFF
    if op == LUI:
        return "dli_gnu", "64-bit constant built from lui and doubleword shifts (GNU as)"
    if op in (ORI, ADDIU) and imm and not imm & 0x8000:
        return "dli_gnu", "64-bit constant built from a small immediate 0x%X and shifts (GNU as)" % imm
    if op == ADDIU and imm == 0xFFFF and len(seq) == 2 and seq[1] & 0x3F == 0x3C and (seq[1] >> 6) & 31 == 31:
        return "dli_ps2as", "1 << 63 built as addiu -1; dsll32 31 (Ps2EeAs)"
    for k in range(1, len(seq) - 1):
        x = seq[k]
        if x & 0x3F in (0x38, 0x3C) and seq[k + 1] >> 26 == ORI:
            sa = ((x >> 6) & 31) + (32 if x & 0x3F == 0x3C else 0)
            if sa not in (16, 32):
                return "dli_ps2as", "64-bit constant with a %d-bit shift between its parts (Ps2EeAs)" % sa
    return None


def scan(code, addr=0, gp=GP):
    """The facts in one function's retail bytes that bear on its profile."""
    facts = []
    n = len(code) // 4
    ws = [word(code, i) for i in range(n)]
    # VU0 macro code (COP2, lqc2/sqc2) is inline or hand-written assembly:
    # its coprocessor moves say nothing about the assembler's hazard handling
    cop2 = any(w >> 26 in (0x12, 0x36, 0x3E) for w in ws)
    if cop2:
        facts.append(Fact("cop2", addr, "VU0 instructions: inline or hand-written assembly"))
    gp_addrs, lui_small = set(), {}
    for i, w in enumerate(ws):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        at = addr + 4 * i
        in_delay = i > 0 and is_branch(ws[i - 1])
        if (op in MEM or op in (ADDIU, DADDIU)) and rs == GPR and rt != GPR:
            gp_addrs.add((gp + sext(w & 0xFFFF)) & 0xFFFFFFFF)
        # ---- coprocessor move hazards
        if not cop2 and op == 0x11 and rs == 0 and rt != AT and i + 1 < n and not in_delay:   # mfc1 $rt, $fs
            nxt = ws[i + 1]
            if nxt != 0 and rt in gpr_reads(nxt):
                facts.append(Fact("mfc1_nonop", at, "mfc1 result read by the next instruction, no nop"))
        if not cop2 and op == 0x11 and rs == 4 and i + 2 < n and not in_delay:              # mtc1 $rt, $fs
            fs = (w >> 11) & 31
            nxt = 1 if ws[i + 1] else 2
            fpu = ws[i + nxt] >> 26 == 0x11 and (ws[i + nxt] >> 21) & 31 in (16, 20) and fs not in fpr_reads(ws[i + nxt])
            if fpu and nxt == 1:
                facts.append(Fact("mtc1_nonop", at, "FPU instruction right after mtc1, no nop (it does not read the register)"))
            elif fpu:
                facts.append(Fact("mtc1_nop", at, "nop after mtc1 that the next FPU instruction does not need"))
        # ---- 64-bit constants (dli): each assembler has its own expansion
        if (op in (ORI, ADDIU) and rs == 0 or op == LUI) and rt and i + 1 < n \
                and ws[i + 1] >> 26 == 0 and ws[i + 1] & 0x3F in (0x38, 0x3C) and (ws[i + 1] >> 16) & 31 == rt \
                and (ws[i + 1] >> 11) & 31 == rt and not (i > 0 and ws[i - 1] >> 26 == LUI and (ws[i - 1] >> 16) & 31 == rt):
            kind = dli_style(ws, i)
            if kind:
                facts.append(Fact(kind[0], at, kind[1]))
        if op != LUI or rt == 0:
            continue
        hi = (w & 0xFFFF) << 16
        r = rt
        uses = lui_uses(ws, i, r)
        if not uses:
            continue
        j, kind = uses[0]
        first = ws[j]
        # ---- float constants: lui $at [; ori $at] ; mtc1 $at
        if r == AT:
            if kind == "ori" and j == i + 1 and (first >> 16) & 31 == AT and j + 1 < n \
                    and ws[j + 1] >> 26 == 0x11 and (ws[j + 1] >> 21) & 31 == 4 and (ws[j + 1] >> 16) & 31 == AT:
                facts.append(Fact("float_inline", at, "float constant 0x%08X built inline (lui/ori/mtc1)" % (hi | (first & 0xFFFF))))
                continue
            if kind == "other" and j == i + 1 and first >> 26 == 0x11 and (first >> 21) & 31 == 4:
                continue                                  # 1.0f etc.: both assemblers
            # a large immediate operand the assembler builds in $at: `addu $a0, $a0, 0x1fca8`
            k = j + 1 if kind == "ori" and j == i + 1 and (first >> 16) & 31 == AT else j if kind == "other" and j == i + 1 else None
            if k is not None and k < n and ws[k] >> 26 == 0 and AT in gpr_reads(ws[k]) and gpr_write(ws[k]) not in (None, AT) \
                    and ws[k] & 0x3F not in (8, 9):
                facts.append(Fact("imm_at", at, "large immediate 0x%X built in $at by the assembler"
                                  % (hi | (first & 0xFFFF if kind == "ori" else 0))))
                continue
        if kind == "ori" or (kind == "other" and not any(k == "base" for _, k in uses)):
            # lui $at; addu $at, $at, idx; access lo($at): an indexed symbol macro
            if kind == "other" and r == AT and j == i + 1 and first >> 26 == 0 and first & 0x3F in (0x21, 0x2D) \
                    and (first >> 11) & 31 == r and len(uses) == 1:
                k = j + 1
                if k < n and ws[k] >> 26 in MEM and (ws[k] >> 21) & 31 == r:
                    a = (hi + sext(ws[k] & 0xFFFF)) & 0xFFFFFFFF
                    if in_small(a, gp):
                        facts.append(Fact("small_at", at, "small-data 0x%X indexed with an assembler macro (lui $at; addu)" % a, a))
                    else:
                        facts.append(Fact("at_big", at, "0x%X indexed with an assembler macro (lui $at; addu)" % a, a))
            continue
        bases = [(j2, ws[j2]) for j2, k in uses if k == "base"]
        j, first = bases[0]
        target = (hi + sext(first & 0xFFFF)) & 0xFFFFFFFF
        if not RAM[0] <= target < RAM[1]:
            continue                                      # a hardware register or a number: gcc splits those in both modes
        fop, frt = first >> 26, (first >> 16) & 31
        adjacent = j == i + 1
        if fop in GLOADS or fop in (ADDIU, DADDIU):
            temp_ok = frt == r or r == AT
        else:
            temp_ok = r == AT
        if adjacent and len(uses) == 1 and temp_ok:
            if in_small(target, gp):
                lui_small.setdefault(target, at)
                if r == AT:
                    facts.append(Fact("small_at", at, "small-data 0x%X reached with an assembler macro (lui $at)" % target, target))
                else:
                    facts.append(Fact("small_same", at, "small-data 0x%X reached with lui and its use in one register" % target, target))
            elif r == AT:
                facts.append(Fact("at_big", at, "0x%X reached with an assembler macro (lui $at)" % target, target))
            else:
                facts.append(Fact("big_same", at, "0x%X: lui and its only use adjacent, one register" % target, target))
        else:
            why = ("its %%hi feeds %d accesses" % len(bases)) if len(bases) > 1 else \
                  "lui and use %d instructions apart" % (j - i) if not adjacent else \
                  "lui register is not the assembler's temporary"
            facts.append(Fact("split", at, "0x%X split by gcc: %s" % (target, why), target))
    for a, at in lui_small.items():
        if a in gp_addrs:
            facts.append(Fact("mixed", at, "small-data 0x%X reached through both $gp and lui" % a, a))
    kinds = {f.kind for f in facts}
    # A function that reaches small data only through macros and shows no gcc
    # split is usually N; with Ps2EeAs's own marks it is as often S (most
    # Ps2EeAs functions are S), so then it says nothing about the mode.
    if kinds & {"small_at", "small_same"} and not kinds & {"split", "at_big", "imm_at", "float_inline", "dli_ps2as", "mixed", "mfc1_nonop", "mtc1_nonop"}:
        facts.append(Fact("macros_only", addr, "small data reached only through assembler macros, no gcc split"))
    return facts


# Weights. MODE_RULES: positive for S, negative for N. ASM_RULES: positive for
# Ps2EeAs, negative for GNU as. The small-data rules depend on the mode: in S
# mode gcc splits an object it does not know to be small itself, so an
# assembler macro to small data means the assembler did not know the size yet,
# which is Ps2EeAs (single pass). In N mode every access is a macro, and the
# matched sources reach small data with lui under either assembler (GNU as
# with unsized declarations), so there it says nothing.
MODE_RULES = {"split": 4, "at_big": -4, "imm_at": -2, "macros_only": -1}
ASM_RULES = {"float_inline": 6, "dli_ps2as": 6, "dli_gnu": -4, "mixed": 4, "mfc1_nonop": 3, "mtc1_nop": -3}
ASM_RULES_BY_MODE = {"S": {"small_at": 4, "small_same": 2, "mtc1_nonop": 3},
                     "N": {"mtc1_nonop": 1},
                     None: {"small_at": 4, "small_same": 2, "mtc1_nonop": 3}}


class Evidence:
    """Weighted evidence: .mode and .asm are Counters, .notes the facts with
    the side and weight each one gave, in address order."""
    def __init__(self, facts):
        self.facts = facts
        self.mode = collections.Counter()
        self.asm = collections.Counter()
        self.notes = []
        for f in facts:
            w = MODE_RULES.get(f.kind)
            if w:
                self.mode["S" if w > 0 else "N"] += abs(w)
                self.notes.append((f.at, "mode", "S" if w > 0 else "N", abs(w), f.text))
        rules = dict(ASM_RULES, **ASM_RULES_BY_MODE[self.pick(self.mode, "S", "N")])
        for f in facts:
            w = rules.get(f.kind)
            if w:
                self.asm["ps2as" if w > 0 else "default"] += abs(w)
                self.notes.append((f.at, "asm", "ps2as" if w > 0 else "default", abs(w), f.text))
            elif f.kind not in MODE_RULES:
                self.notes.append((f.at, "-", "", 0, f.text))
        self.notes.sort(key=lambda x: x[0])

    @staticmethod
    def pick(c, a, b):
        if c[a] == c[b]:
            return None
        return a if c[a] > c[b] else b


def guess(code, addr=0, gp=GP):
    """Evidence for one function's profile from its retail bytes; profile_of()
    turns it into (mode, assembler)."""
    return Evidence(scan(code, addr, gp))


def profile_of(ev):
    """(mode or None, assembler or None) from an Evidence."""
    return Evidence.pick(ev.mode, "S", "N"), Evidence.pick(ev.asm, "ps2as", "default")


# ------------------------------------------------------------ retail lookups

def _elf_text(path):
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        e = ELFFile(f)
        return [(s["sh_addr"], s.data()) for s in e.iter_sections()
                if s["sh_flags"] & 4 and s["sh_size"] and s["sh_type"] == "SHT_PROGBITS"]


_TEXT = {}


def retail_bytes(elf, addr, size):
    if elf not in _TEXT:
        _TEXT[elf] = _elf_text(elf)
    for base, data in _TEXT[elf]:
        if base <= addr < base + len(data):
            return data[addr - base:addr - base + size]
    raise KeyError("0x%X is not in the code of %s" % (addr, elf))


SIZE_RE = re.compile(r"nonmatching (func_[0-9A-Fa-f]{8}), (0x[0-9A-Fa-f]+)")


def target_sizes(t):
    """name -> size for every function of a target, from its asm/ listings."""
    out = {}
    dirs = [u.asm_dir for u in t.units] + [t.handwritten, t.remnants]
    for d in dirs:
        p = os.path.join(ROOT, d)
        if not os.path.isdir(p):
            continue
        for fn in os.listdir(p):
            if fn.endswith(".s"):
                with open(os.path.join(p, fn), errors="ignore") as f:
                    m = SIZE_RE.search(f.read(400))
                if m:
                    out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def guess_function(name, target=None, overlay=None, refs=None):
    """(mode, assembler, Evidence) for func_X of a target, or of the common
    level code (target None: the catalogue, then targets/levels/common_occurrences.tsv,
    gives its owner overlay in the private level inputs)."""
    addr = int(name[5:], 16)
    if target:
        t = targets.get(target)
        size = target_sizes(t).get(name)
        if size is None:
            raise KeyError("%s has no asm listing in %s (python tools/setup_asm.py --target %s)" % (name, t.name, t.name))
        code = retail_bytes(os.path.join(ROOT, t.elf), addr, size)
    else:
        code = common_bytes(name, overlay, refs)
    ev = guess(code, addr)
    return profile_of(ev) + (ev,)


def default_refs():
    return os.environ.get("UYA_REFS", r"C:\decomp-refs")


def common_bytes(name, overlay=None, refs=None):
    refs = refs or default_refs()
    size = None
    for e in json.load(open(targets.levels_path("common_c"), encoding="utf-8")):
        if e["name"] == name and (overlay is None or e["overlay"] == overlay):
            overlay, size = overlay or e["overlay"], e["size"]
            break
    if size is None:
        with open(targets.levels_path("occurrences"), encoding="utf-8") as f:
            for row in csv.reader((l for l in f if not l.startswith("#")), delimiter="\t"):
                if row and row[0] == name:
                    size = int(row[2])
                    if overlay is None:
                        overlay = row[1]
                    break
    if size is None:
        raise KeyError("%s is not a shared level function (targets/levels/common_occurrences.tsv)" % name)
    levels = os.path.join(refs, "levels")
    path = os.path.join(levels, overlay, "overlay.elf")
    if not os.path.exists(path):
        hits = [os.path.join(levels, k, overlay, "overlay.elf") for k in ("singleplayer", "multiplayer")]
        hits = [h for h in hits if os.path.exists(h)]
        if not hits:
            raise KeyError("no overlay.elf for %s under %s" % (overlay, levels))
        path = hits[0]
    return retail_bytes(path, int(name[5:], 16), size)


def format_report(name, mode, asm, ev, verbose=True):
    lines = ["%s: mode %s, assembler %s   (evidence S %g / N %g, ps2as %g / default %g)"
             % (name, mode or "unknown", asm or "unknown", ev.mode["S"], ev.mode["N"], ev.asm["ps2as"], ev.asm["default"])]
    if verbose:
        for at, kind, choice, weight, text in ev.notes:
            side = "%-4s %-7s +%-2g" % (kind, choice, weight) if weight else "%-16s" % "(no weight)"
            lines.append("    %08X  %s  %s" % (at, side, text))
    return "\n".join(lines)


# ------------------------------------------------------------ evaluation

BLOCK_RE = re.compile(r"/\* localdecomp:start (func_[0-9A-Fa-f]{8}) \*/\n(.*?)/\* localdecomp:end \1 \*/", re.S)
# inline assembly, register pins, `.extern` size hints: a match steered by hand
# toward the other assembler's or mode's output
STEERED_RE = re.compile(r"\b(?:__asm__|__asm|asm)\b")


def matched_functions(t):
    """name -> ((mode, assembler), block) for every function of target t that
    is C, with the flags its range builds it with. @ee29 and @newas ranges are
    left out (another compiler or assembler)."""
    import build_text as bt
    import srcfiles
    parts = bt.read_parts(t.path("parts"))
    blocks = {}
    for rel, _ in srcfiles.read_file_list(t.path("files")):
        p = os.path.join(ROOT, rel)
        if os.path.exists(p):
            for m in BLOCK_RE.finditer(open(p, encoding="utf-8").read().replace("\r\n", "\n")):
                blocks[m.group(1)] = m.group(2)
    out = {}
    for n, block in blocks.items():
        fl = bt.flags_for(parts, int(n[5:], 16))
        if "@ee29" in fl or "@newas" in fl:
            continue
        out[n] = (("N" if "-mno-split-addresses" in fl else "S", "ps2as" if "@ps2as" in fl else "default"), block)
    return out


class Row:
    def __init__(self, where, name, truth, ev, plain, block=None, entry=None):
        self.where, self.name, self.truth, self.ev, self.plain = where, name, truth, ev, plain
        self.guess = profile_of(ev)
        self.block, self.entry = block, entry
        self.equivalent = {}                         # 0 (mode) / 1 (assembler) -> True, False, None


def collect(which, refs):
    rows = []
    names = ["frontbin", "boot_elf", "veldin"] if which == "all" else [] if which == "common" else [which]
    for tn in names:
        t = targets.get(tn)
        sizes = target_sizes(t)
        common_names = set()
        if getattr(t, "level_overlay", None):
            common_names = {e["name"] for e in json.load(open(targets.levels_path("common_c"), encoding="utf-8"))
                            if e["overlay"] == t.level_overlay}
        for n, (truth, block) in sorted(matched_functions(t).items()):
            if n in common_names or n not in sizes:
                continue                              # counted once, under common
            addr = int(n[5:], 16)
            ev = guess(retail_bytes(os.path.join(ROOT, t.elf), addr, sizes[n]), addr)
            plain = not STEERED_RE.search(re.sub(r"/\*.*?\*/", "", block, flags=re.S))
            rows.append(Row(tn, n, truth, ev, plain, block=block))
    if which in ("common", "all"):
        for e in json.load(open(targets.levels_path("common_c"), encoding="utf-8")):
            try:
                code = common_bytes(e["name"], e["overlay"], refs)
            except (KeyError, OSError) as err:
                print("skipped %s: %s" % (e["name"], err))
                continue
            rows.append(Row("common", e["name"], (e["mode"], e["assembler"]), guess(code, int(e["address"], 16)), True, entry=e))
    return rows


# ---- --verify: build each disagreement with the guessed choice

_VERIFY = {}


def _verify_init(refs):
    _VERIFY["refs"] = refs


def _verify_target(job):
    """[matches?] for each profile: target `tn`'s function `name` (its C block,
    compiled by check.py in its file's context) against retail."""
    tn, name, block, profiles = job
    import contextlib, io, tempfile
    from types import SimpleNamespace
    os.environ["UYA_TARGET"] = tn
    import check
    if _VERIFY.get("target") != tn:
        check._ADDRS = None
        _VERIFY["target"] = tn
        _VERIFY["retail"] = check.Retail(os.path.join(ROOT, targets.get(tn).elf))
    src = os.path.join(tempfile.mkdtemp(prefix="asm_profile_"), name + ".c")
    open(src, "w", encoding="utf-8").write(block)
    args = SimpleNamespace(no_context=False, toolchain=check.DEFAULT_TOOLCHAIN, runner=os.environ.get("UYA_RUNNER"),
                           early_extern_sizes={})
    base = check.flags_for(int(name[5:], 16))
    out = []
    for mode, asm in profiles:
        with contextlib.redirect_stdout(io.StringIO()):
            o = check.compile_c(src, check.apply_overrides(base, mode, asm), args, name)
            res = check.diff_object(o, [name], _VERIFY["retail"], True) if o else {}
        out.append(res.get(name) == 0)
    return out


def _verify_common(job):
    """[passes build_common_c's gates?] for each profile of a catalogue entry."""
    entry, profiles = job
    import contextlib, io
    from pathlib import Path
    from types import SimpleNamespace
    import build_common_c as bcc
    import check
    import try_level
    refs = Path(_VERIFY["refs"])
    if "owners" not in _VERIFY:
        _VERIFY["owners"], _VERIFY["common"] = try_level.load_refs(refs)
    opts = SimpleNamespace(no_context=True, toolchain=check.DEFAULT_TOOLCHAIN, runner=os.environ.get("UYA_RUNNER"))
    out = []
    for mode, asm in profiles:
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                bcc.compile_entry(dict(entry, mode=mode, assembler=asm), refs / "levels", refs / "level-targets",
                                  _VERIFY["owners"], _VERIFY["common"], opts)
            out.append(True)
        except (ValueError, OSError, KeyError):
            out.append(False)
    return out


def verify(rows, refs, jobs):
    """Build every disagreement with the guessed choice (the other choice as
    built) and record in Row.equivalent whether it matches anyway: then the
    function's bytes do not depend on that choice. None when the function does
    not match with its own flags outside the full build."""
    import concurrent.futures as cf
    from pathlib import Path
    todo = []
    for r in rows:
        alts = [(k, (r.guess[0], r.truth[1]) if k == 0 else (r.truth[0], r.guess[1]))
                for k in (0, 1) if r.guess[k] is not None and r.guess[k] != r.truth[k]]
        if r.guess[1] is None and r.truth[1] != "default":
            alts.append(("default", (r.truth[0], "default")))   # no Ps2EeAs marks, read as GNU as
        if r.guess[0] is None:
            alts.append(("other-mode", ("S" if r.truth[0] == "N" else "N", r.truth[1])))   # does the mode matter?
        if alts:
            todo.append((r, alts))
    if not todo:
        return
    if any(r.where == "common" for r, _ in todo):
        import try_level
        try_level.load_refs(Path(refs))              # fill the cache once, before the workers read it
    print("verifying %d disagreements..." % len(todo), flush=True)
    with cf.ProcessPoolExecutor(jobs, initializer=_verify_init, initargs=(str(refs),)) as ex:
        futs = {}
        for r, alts in todo:
            profiles = [r.truth] + [p for _, p in alts]
            job = (_verify_common, (r.entry, profiles)) if r.where == "common" else \
                  (_verify_target, (r.where, r.name, r.block, profiles))
            futs[ex.submit(*job)] = (r, alts)
        for f in cf.as_completed(futs):
            r, alts = futs[f]
            res = f.result()
            for (k, _), ok in zip(alts, res[1:]):
                r.equivalent[k] = ok if res[0] else None


def report(rows):
    """Agreement with the built flags, per program, for plain C and for all
    (some matches steer the output with inline asm, register pins or `.extern`
    hints toward the other mode or assembler)."""
    verified = any(r.equivalent for r in rows)
    for label, k in (("mode", 0), ("assembler", 1)):
        print("%s:" % label)
        print("  %-9s %-5s %6s %8s %6s %6s %7s%s %8s" % ("", "", "funcs", "decided", "agree", "differ", "agree%",
                                                     "  same-bytes" if verified else "", "unknown"))
        groups = {}
        for r in rows:
            if r.plain:
                groups.setdefault((r.where, "plain"), []).append(r)
            groups.setdefault((r.where, "all"), []).append(r)
        for (where, kind), rs in sorted(groups.items(), key=lambda x: (x[0][0], x[0][1] != "plain")):
            dec = [r for r in rs if r.guess[k] is not None]
            agree = sum(1 for r in dec if r.guess[k] == r.truth[k])
            same = sum(1 for r in dec if r.guess[k] != r.truth[k] and r.equivalent.get(k))
            print("  %-9s %-5s %6d %8d %6d %6d %6.1f%%%s %8d" % (
                where, kind, len(rs), len(dec), agree, len(dec) - agree, 100.0 * agree / max(len(dec), 1),
                "  %10d" % same if verified else "", len(rs) - len(dec)))
    if verified:
        print("mode unknown (no global reached in a mode-specific way): built with the other mode")
        for where in sorted({r.where for r in rows}):
            rs = [r for r in rows if "other-mode" in r.equivalent]
            rs = [r for r in rs if r.where == where]
            same = sum(1 for r in rs if r.equivalent["other-mode"])
            print("  %-9s %d of %d still match (%.1f%%)" % (where, same, len(rs), 100.0 * same / max(len(rs), 1)))
    print("assembler, reading 'unknown' (no Ps2EeAs marks) as the default assembler:")
    for where in sorted({r.where for r in rows}):
        rs = [r for r in rows if r.where == where]
        ok = sum(1 for r in rs if (r.guess[1] or "default") == r.truth[1])
        same = sum(1 for r in rs if r.equivalent.get("default")) + \
            sum(1 for r in rs if r.guess[1] is not None and r.guess[1] != r.truth[1] and r.equivalent.get(1))
        print("  %-9s %d of %d agree (%.1f%%)%s" % (where, ok, len(rs), 100.0 * ok / len(rs),
              ", %d more build the same bytes either way (%.1f%%)" % (same, 100.0 * (ok + same) / len(rs)) if verified else ""))


def evaluate(which, refs, show=0, check_builds=False, jobs=None):
    rows = collect(which, refs)
    if check_builds:
        verify(rows, refs, jobs or os.cpu_count() or 4)
    report(rows)
    if show:
        wrong = [r for r in rows if any(r.guess[k] is not None and r.guess[k] != r.truth[k] and not r.equivalent.get(k)
                                        for k in (0, 1))]
        for r in wrong[:show]:
            print("--- %s %s: built %s/%s%s" % (r.where, r.name, r.truth[0], r.truth[1], "" if r.plain else " (inline asm)"))
            print(format_report(r.name, r.guess[0], r.guess[1], r.ev))
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*", help="func_XXXXXXXX")
    ap.add_argument("--target", help="frontbin, boot_elf, veldin (omit for a common-level function; with --evaluate also common or all)")
    ap.add_argument("--overlay", help="common-level function: the overlay to read (default: its owner)")
    ap.add_argument("--refs", default=default_refs(), help="the private level inputs (default: env UYA_REFS or C:\\decomp-refs)")
    ap.add_argument("--evaluate", action="store_true", help="compare the guess with the flags of every matched function")
    ap.add_argument("--verify", action="store_true", help="with --evaluate: build every disagreement with the guess to see if it matches anyway")
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--show-wrong", type=int, default=0, metavar="N", help="with --evaluate: print the evidence of N disagreements")
    ap.add_argument("--brief", action="store_true", help="one line per function, no evidence")
    a = ap.parse_args()
    if a.evaluate:
        evaluate(a.target or "all", a.refs, a.show_wrong, a.verify, a.jobs)
        return 0
    if not a.names:
        ap.error("name at least one func_XXXXXXXX (or --evaluate)")
    status = 0
    for n in a.names:
        try:
            mode, asm, ev = guess_function(n, a.target, a.overlay, a.refs)
        except (KeyError, OSError) as err:
            print("%s: %s" % (n, err))
            status = 1
            continue
        print(format_report(n, mode, asm, ev, not a.brief))
    return status


if __name__ == "__main__":
    sys.exit(main())
