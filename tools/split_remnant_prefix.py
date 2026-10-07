#!/usr/bin/env python3
"""split_remnant_prefix.py: cut linker remnants off the front of functions.

When the original linker stripped an unused function it kept that function's
last instruction plus the alignment nop (see migrate_asm_sources.py). Where such
[instruction, nop] pairs sit right before a real function, splat has no symbol
between them and glues them onto the front of that function. The result can't
be matched as C: no compiler emits `addiu $sp, $sp, 0x20; nop` before a prologue.

This script finds INCLUDE_ASM functions that start with such pairs and splits
each into
  func_<start>  the pairs, as a LINKER_REMNANT in asm/remnants/
  func_<real>   the real function, a new INCLUDE_ASM in asm/nonmatchings/text/
The bytes built are identical.

    python tools/split_remnant_prefix.py            # report
    python tools/split_remnant_prefix.py --apply
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import srcfiles  # noqa: E402
import targets  # noqa: E402


def NM_for(name):
    return os.path.join(ROOT, targets.get().unit_for(int(name[5:], 16)).asm_dir)
INS = re.compile(r'^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s*(.*)$')
BRANCH = re.compile(r'^(j|jr|jal|jalr|b\w*|bc\d\w*)\s')


def parse(path):
    lines = open(path, newline="").read().splitlines(True)
    ins = []  # (line index, addr, text)
    for i, l in enumerate(lines):
        m = INS.match(l)
        if m:
            ins.append((i, int(m.group(1), 16), m.group(3).strip()))
        elif l.strip().startswith(".word") or "endlabel" in l:
            ins.append((i, None, l.strip()))
    return lines, ins


def prefix_pairs(ins):
    k = 0
    while k + 1 < len(ins):
        a, b = ins[k], ins[k + 1]
        if a[1] is None or b[1] is None or not b[2].startswith("nop"):
            break
        if BRANCH.match(a[2]):
            break
        k += 2
    if k == 0 or k >= len(ins) or ins[k][1] is None or ins[k][1] % 8:
        return 0
    # the rest must look like a function start, not more padding
    if ins[k][2].startswith("nop"):
        return 0
    return k


def main():
    t = targets.from_argv()   # --target boot_elf
    REM = t.path("remnants")
    apply = "--apply" in sys.argv
    text = srcfiles.read_all(ROOT)
    edits = []
    names = re.findall(r'^INCLUDE_ASM\("[^"]+", (func_[0-9A-F]{8})\);', text, re.M)
    todo = []
    for n in names:
        p = os.path.join(NM_for(n), n + ".s")
        if not os.path.exists(p):
            continue
        lines, ins = parse(p)
        k = prefix_pairs(ins)
        if k:
            todo.append((n, lines, ins, k))
    for n, lines, ins, k in todo:
        print(f"{n}: {k // 2} remnant pair(s), real function at func_{ins[k][1]:08X}")
    print(f"{len(todo)} functions")
    if not apply:
        return
    os.makedirs(REM, exist_ok=True)
    for n, lines, ins, k in todo:
        lnl = "\r\n" if lines and lines[0].endswith("\r\n") else "\n"
        start = int(n[5:], 16)
        real = ins[k][1]
        new = "func_%08X" % real
        split_line = ins[k][0]
        # move any label/.align lines just before the split point to the new function
        while split_line > 0 and not INS.match(lines[split_line - 1]) and "glabel" not in lines[split_line - 1] \
                and lines[split_line - 1].strip():
            split_line -= 1
        m_size = re.search(r"nonmatching\s+%s,\s*0x([0-9A-Fa-f]+)" % n, "".join(lines))
        total = int(m_size.group(1), 16)
        head = [l for l in lines[:split_line] if not re.match(r"\s*(\.align|nonmatching|glabel|$)", l)]
        rem = (".align 3" + lnl + f"/* nonmatching {n}, 0x{real - start:X} -- marker removed: final source */" + lnl
               + lnl + f"glabel {n}" + lnl + "".join(head) + f"endlabel {n}" + lnl)
        body = "".join(lines[split_line:]).replace(f"endlabel {n}", f"endlabel {new}")
        fn = (".align 3" + lnl + f"nonmatching {new}, 0x{total - (real - start):X}" + lnl + lnl
              + f"glabel {new}" + lnl + body)
        open(os.path.join(REM, n + ".s"), "w", newline="").write(rem)
        open(os.path.join(NM_for(n), new + ".s"), "w", newline="").write(fn)
        os.remove(os.path.join(NM_for(n), n + ".s"))
        edits.append((n, new))

    def edit(text):
        nl = "\r\n" if "\r\n" in text else "\n"
        for n, new in edits:
            folder = targets.get().unit_for(int(n[5:], 16)).asm_dir
            text = text.replace(f'INCLUDE_ASM("{folder}", {n});',
                                f'LINKER_REMNANT("{targets.get().remnants}", {n});{nl}{nl}'
                                f'INCLUDE_ASM("{folder}", {new});', 1)
        return text

    srcfiles.transform_all(edit, ROOT)
    print("applied")


if __name__ == "__main__":
    main()
