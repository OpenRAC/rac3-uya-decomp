#!/usr/bin/env python3
"""trailing_padding.py: find functions followed by more nops than gcc emits.

gcc aligns every function to 8 bytes, so a C function is followed by at most
one alignment nop. A few retail functions are followed by more (probably the
bodies of functions the original linker stripped, zeroed out). Splat keeps
those words after the endlabel of the function's .s, so they build fine as
INCLUDE_ASM but vanish as soon as the function becomes C, shifting every
address after it.

The fix is TEXT_PADDING(N) (include/include_asm.h) right after the function in
the source file: N zero words, where N = trailing words minus the alignment nop.

    python tools/trailing_padding.py            # report
    python tools/trailing_padding.py --apply    # insert TEXT_PADDING(N) after each
                                                # INCLUDE_ASM that needs it and cut
                                                # the extra nops from its .s

--apply is idempotent and keeps the build byte-identical (the .align 3 at the
start of the next function supplies the alignment nop). After it, converting
such a function to C needs nothing special: the TEXT_PADDING line stays.
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import srcfiles  # noqa: E402
import targets  # noqa: E402
ENTRY = re.compile(
    r'(?:/\* localdecomp:start (func_[0-9A-F]{8}) \*/)'
    r'|(?:^(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("([^"]+)",\s*(func_[0-9A-F]{8})\);)', re.M)
SIZE = re.compile(r'nonmatching\s+(func_[0-9A-F]{8}),\s*0x([0-9A-Fa-f]+)')
NOP = re.compile(r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} 00000000 \*/\s+nop\s*$')


def entries(text):
    out = []
    for m in ENTRY.finditer(text):
        if m.group(1):
            out.append((m.group(1), None, None, m))
        else:
            out.append((m.group(4), m.group(2), m.group(3), m))
    return out


def scan(text):
    """[(name, folder, extra_words, match)] for INCLUDE_ASM entries needing padding."""
    ents = entries(text)
    found = []
    for i, (name, macro, folder, m) in enumerate(ents):
        if macro != "INCLUDE_ASM" or i + 1 >= len(ents):
            continue
        path = os.path.join(ROOT, folder, name + ".s")
        src = open(path).read()
        sm = SIZE.search(src)
        if not sm:
            continue
        end = int(name[5:], 16) + int(sm.group(2), 16)
        nxt = int(ents[i + 1][0][5:], 16)
        t = targets.get()
        if t.unit_for(int(name[5:], 16)) is not t.unit_for(nxt):
            continue  # the next entry is in another code section
        gap = (nxt - end) // 4
        align = ((-end) % 8) // 4
        tail = src.split("endlabel " + name, 1)[1] if ("endlabel " + name) in src else ""
        tail_nops = sum(1 for l in tail.splitlines() if NOP.match(l))
        extra = gap - align
        if extra > 0:
            found.append((name, folder, extra, tail_nops, gap, m))
    return found


def main():
    targets.from_argv()
    apply = "--apply" in sys.argv
    text = srcfiles.read_all(ROOT)
    found = scan(text)
    for name, folder, extra, tail_nops, gap, m in found:
        print(f"{name}: {gap} words before the next function, TEXT_PADDING({extra})")
    print(f"{len(found)} functions need TEXT_PADDING")
    if not apply:
        return
    pads = {name: extra for name, folder, extra, tail_nops, gap, m in found}

    def insert(text):
        nl = "\r\n" if "\r\n" in text else "\n"
        for m in reversed(list(ENTRY.finditer(text))):
            name = m.group(4)
            if m.group(2) != "INCLUDE_ASM" or name not in pads:
                continue
            # skip the INCLUDE_RODATA lines that belong to this function
            after = text[m.end():]
            rm = re.match(r'[^\n]*\n(?:INCLUDE_RODATA\([^\n]*\n)*', after)
            pos = m.end() + (rm.end() if rm else len(after))
            if re.match(r'[ \t\r\n]*TEXT_PADDING\(', text[pos:]):
                continue
            text = text[:pos] + f"TEXT_PADDING({pads[name]});{nl}" + text[pos:]
        return text

    srcfiles.transform_all(insert, ROOT)
    for name, folder, extra, tail_nops, gap, m in found:
        path = os.path.join(ROOT, folder, name + ".s")
        src = open(path, newline="").read()
        head, tail = src.split("endlabel " + name, 1)
        first_nl = tail.find("\n")
        rest = [l for l in tail[first_nl + 1:].splitlines(True) if not NOP.match(l)]
        open(path, "w", newline="").write(head + "endlabel " + name + tail[:first_nl + 1] + "".join(rest))
    print("applied")


if __name__ == "__main__":
    main()
