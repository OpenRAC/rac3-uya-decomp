#!/usr/bin/env python3
"""setup_asm.py: generate everything under asm/ from YOUR frontbin.elf.

asm/ is gitignored (it is the game's code, so it can't be shipped). A fresh clone
therefore has no asm/ at all and `make` stops with
"No rule to make target `asm/header.s'". Run this once after cloning, from anywhere:

    python tools/setup_asm.py

then build (`make` on Windows, `python3 tools/build.py` on Linux/macOS). Re-run it
after pulling if the build says an asm/ file is missing; it is safe to repeat.

What it does, in order (a plain `splat split` is NOT enough, see 3 and 6):

  1. checks frontbin.elf (sha1 3bc94ee895e4b4af9b5602a229af599c1103b542);
  2. saves src/text.c and the two tracked splat side files
     (undefined_funcs_auto.txt, undefined_syms_auto.txt), which splat overwrites;
  3. splat only writes a .s for functions that are INCLUDE_ASM in src/text.c, so it
     temporarily turns the ASM_FUNC / LINKER_REMNANT entries back into INCLUDE_ASM
     (those are final source, but their .s still has to come from somewhere), and lists the
     functions that are already C the same way so localdecomp sees all of them;
  4. python -m splat split (with every func_<address> of text.c added as a function symbol so
     the function boundaries are exactly text.c's), then puts the saved files back;
  5. the ee-as fixups: fix_reg_names.py, fix_quadword_ops.py, fix_short_loops.py,
     and extract_header.py (asm/header.s);
  6. the same post-processing the project applied when asm/ was committed:
       - moves the ASM_FUNC / LINKER_REMNANT .s files to asm/handwritten and asm/remnants;
       - trailing_padding.py --apply (cuts extra trailing nops; text.c is left unchanged);
       - cuts the switch jump tables out of asm/data/data.data.s into
         asm/nonmatchings/text/rodata/jtbl_*.s and splits the blob into
         data_a.data.s / data_b.data.s (the steps of tools/migrate_jtbls.py that touch asm/).

Needs: frontbin.elf in the repo root, `pip install -r tools/requirements.txt` and splat
(`pip install splat64`).
"""
import hashlib, os, re, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SHA1 = "3bc94ee895e4b4af9b5602a229af599c1103b542"
GP = "0x1DC8B0"
TEXT_C = os.path.join(ROOT, "src", "text.c")
SIDE = ["undefined_funcs_auto.txt", "undefined_syms_auto.txt"]


def run(*args):
    print("+", " ".join(args), flush=True)
    r = subprocess.run(list(args), cwd=ROOT)
    if r.returncode != 0:
        sys.exit("failed: %s" % " ".join(args))


def rd(p):
    return open(p, "rb").read()


def wr(p, b):
    open(p, "wb").write(b)


def normalize_data_words():
    """splat symbolizes data words that point at functions; the project's data .s files use literals."""
    ddir = os.path.join(ROOT, "asm", "data")
    rx = re.compile(r"\.word func_([0-9A-F]{8})\b")
    for f in os.listdir(ddir):
        if not f.endswith(".s"):
            continue
        p = os.path.join(ddir, f)
        t = open(p, newline="").read()
        t2 = rx.sub(lambda m: ".word 0x" + m.group(1), t)
        t2 = re.sub(r"\.word func_0(?=\s|$)", ".word 0x00000000", t2, flags=re.M)
        if t2 != t:
            open(p, "w", newline="").write(t2)


def split_data():
    """The asm/ half of tools/migrate_jtbls.py (steps 1 and 2); text.c is already migrated."""
    data = os.path.join(ROOT, "asm", "data", "data.data.s")
    rodir = os.path.join(ROOT, "asm", "nonmatchings", "text", "rodata")
    if not os.path.exists(data):
        print("asm/data/data.data.s not there, data split skipped (already done?)")
        return
    lines = open(data).read().split("\n")
    starts = [i for i, l in enumerate(lines) if l.startswith("nonmatching ")]
    header = lines[:starts[0]]
    blocks = []
    for k, i in enumerate(starts):
        j = starts[k + 1] if k + 1 < len(starts) else len(lines)
        blocks.append((lines[i].split()[1], lines[i:j]))
    first = next(k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_"))
    last = max(k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_"))
    if any(not n.startswith("jtbl_") for n, _ in blocks[first:last + 1]):
        sys.exit("non-jtbl data inside the jump table block; aborting")
    name, body = blocks[last]
    cut = next((i for i, l in enumerate(body) if "0xCDCDCDCD" in l), None)
    tail = []
    if cut is not None:
        tail = ["", "/* linker fill after .rdata (0xCD) */"] + body[cut:]
        blocks[last] = (name, body[:cut])
    os.makedirs(rodir, exist_ok=True)
    for name, body in blocks[first:last + 1]:
        out = [".align 4", ""]
        for l in body:
            l = l.replace(".word func_0 ", ".word 0x00000000 ").rstrip()
            if l.rstrip().endswith(".word func_0"):
                l = l.replace(".word func_0", ".word 0x00000000")
            out.append(l)
        open(os.path.join(rodir, name + ".s"), "w").write("\n".join(out).rstrip() + "\n")

    def write(path, blks, extra=()):
        text = "\n".join(header) + "\n"
        text += "\n".join("\n".join(b) for _, b in blks)
        text += "\n".join(extra)
        open(path, "w").write(text.rstrip() + "\n")

    write(os.path.join(ROOT, "asm", "data", "data_a.data.s"), blocks[:first])
    write(os.path.join(ROOT, "asm", "data", "data_b.data.s"), [],
          extra=tail + [""] + ["\n".join(b) for _, b in blocks[last + 1:]])
    os.replace(data, data + ".premigrate")
    print("split data.data.s into data_a / data_b and wrote %d jump tables" % (last - first + 1))


def main():
    elf = os.path.join(ROOT, "frontbin.elf")
    if not os.path.exists(elf):
        sys.exit("frontbin.elf not found in the repo root (see docs/wiki/Setup.md, step 2)")
    h = hashlib.sha1(rd(elf)).hexdigest()
    if h != SHA1:
        sys.exit("frontbin.elf has sha1 %s, expected %s (NTSC-U, SCUS-97353)" % (h, SHA1))

    asm = os.path.join(ROOT, "asm")
    if os.path.isdir(asm):
        shutil.rmtree(asm)

    text = rd(TEXT_C)
    saved = {n: rd(os.path.join(ROOT, n)) for n in SIDE if os.path.exists(os.path.join(ROOT, n))}
    macro_rx = re.compile(rb'(?:ASM_FUNC|LINKER_REMNANT)\("(asm/(?:handwritten|remnants))",')
    final_src = re.findall(rb'(?:ASM_FUNC|LINKER_REMNANT)\("(asm/[a-z]+)",\s*(func_[0-9A-Fa-f]{8})\)', text)
    py = sys.executable
    # Functions already written as C have no INCLUDE_ASM, so splat would skip them. localdecomp
    # builds its function list (and the progress numbers) from asm/nonmatchings, so list them
    # in the temporary text.c too: every function gets its .s, like a tree that was split before
    # the conversions.
    have = set(re.findall(rb'(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("asm/[A-Za-z/]+",\s*(func_[0-9A-Fa-f]{8})\)', text))
    c_names = set(re.findall(rb"localdecomp:start (func_[0-9A-F]{8})", text))
    c_names |= set(re.findall(rb"(?m)^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]{8})\s*\([^;{]*\)[^;{]*\{", text))
    c_names = {n for n in c_names - have if 0x37D100 <= int(n[5:], 16) < 0x3ED000}
    c_stubs = b"".join(b'\nINCLUDE_ASM("asm/nonmatchings/text", %s);' % n for n in sorted(c_names)) + b"\n"
    print("%d functions are already C; adding temporary stubs so each gets a .s" % len(c_names))
    # Function boundaries: the names in text.c (func_<address>) are the project's units,
    # and every .s must end exactly where the next one starts. Hand splat those addresses
    # as function symbols through a temporary extra symbol file and a temporary yaml.
    names = sorted({int(m, 16) for m in re.findall(rb"func_([0-9A-F]{8})", text)})
    taken = {int(a, 16) for a in re.findall(rb"=\s*0x0*([0-9A-Fa-f]+)", rd(os.path.join(ROOT, "symbol_addrs.txt")))}
    extra = os.path.join(ROOT, "symbol_addrs_setup.txt")
    tmp_yaml = os.path.join(ROOT, "frontbin.setup.yaml")
    with open(extra, "w") as f:
        for a in names:
            if 0x37D100 <= a < 0x3ED000 and a not in taken:
                f.write("func_%08X = 0x%08X;\n" % (a, a))
    yml = open(os.path.join(ROOT, "frontbin.splat.yaml")).read()
    yml = re.sub(r"(symbol_addrs_path:\s*\n(\s*)- symbol_addrs\.txt)", r"\1\n\2- symbol_addrs_setup.txt", yml)
    open(tmp_yaml, "w").write(yml)
    try:
        wr(TEXT_C, macro_rx.sub(b'INCLUDE_ASM("asm/nonmatchings/text",', text) + c_stubs)
        run(py, "-m", "splat", "split", "frontbin.setup.yaml")
    finally:
        wr(TEXT_C, text)
        for n, b in saved.items():
            wr(os.path.join(ROOT, n), b)
        for t in (extra, tmp_yaml):
            if os.path.exists(t):
                os.remove(t)

    run(py, "tools/fix_reg_names.py", "asm")
    run(py, "tools/fix_quadword_ops.py", "--gp-value", GP, "asm")
    run(py, "tools/fix_short_loops.py", "asm")
    run(py, "tools/extract_header.py")

    src_dir = os.path.join(asm, "nonmatchings", "text")
    n = 0
    for folder, func in final_src:
        folder, func = folder.decode(), func.decode()
        os.makedirs(os.path.join(ROOT, folder), exist_ok=True)
        s = os.path.join(src_dir, func + ".s")
        if not os.path.exists(s):
            sys.exit("missing %s (did splat finish?)" % s)
        shutil.move(s, os.path.join(ROOT, folder, func + ".s"))
        n += 1
    print("moved %d ASM_FUNC / LINKER_REMNANT sources" % n)

    try:
        wr(TEXT_C, re.sub(rb"(?m)^[ \t]*TEXT_PADDING\(\d+\);?[ \t]*\r?\n", b"", text))
        run(py, "tools/trailing_padding.py", "--apply")
    finally:
        wr(TEXT_C, text)      # the TEXT_PADDING lines are already in src/text.c
    normalize_data_words()
    split_data()
    print("done. Now build: make (Windows) or python3 tools/build.py (Linux/macOS).")


if __name__ == "__main__":
    main()
