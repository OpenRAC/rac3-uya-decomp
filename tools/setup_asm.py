#!/usr/bin/env python3
"""setup_asm.py: generate a target's asm/ files from YOUR copy of its ELF.

asm/ is gitignored (it is the game's code, so it can't be shipped). A fresh clone
therefore has no asm/ at all and `make` stops with
"No rule to make target `asm/header.s'". Run this once after cloning, from anywhere:

    python tools/setup_asm.py                    # frontbin.elf  -> asm/
    python tools/setup_asm.py --target boot_elf  # boot_elf.elf  -> asm/boot_elf/
    python tools/setup_asm.py --target i5bootn   # i5bootn.elf   -> asm/i5bootn/
    python tools/setup_asm.py --target all       # every target whose ELF is in the repo root

then build (`make` on Windows, `python3 tools/build.py` on Linux/macOS). Re-run it
after pulling if the build says an asm/ file is missing; it is safe to repeat.
The targets and their folders are listed in tools/targets.py.

What it does, in order (a plain `splat split` is NOT enough, see 3 and 6):

  1. checks the ELF's sha1;
  2. writes one temporary C file per code section for splat (src/text.c for
     frontbin; src/boot_elf/core.c and text.c for boot_elf), each holding all of
     that section's source files concatenated, and saves the target's splat side
     files (undefined_funcs_auto / undefined_syms_auto), which splat overwrites;
  3. splat only writes a .s for functions that are INCLUDE_ASM in those files, so it
     temporarily turns the ASM_FUNC / LINKER_REMNANT entries back into INCLUDE_ASM
     (those are final source, but their .s still has to come from somewhere), and lists the
     functions that are already C the same way so localdecomp sees all of them;
  4. python -m splat split (with every func_<address> of the sources added as a function
     symbol so the function boundaries are exactly the sources'), then puts the saved
     files back;
  5. the ee-as fixups: fix_reg_names.py, fix_quadword_ops.py, fix_short_loops.py,
     and extract_header.py (the raw header bytes and, for boot_elf, the section-header
     table at the end of the file);
  6. the same post-processing the project applied when asm/ was committed:
       - moves the ASM_FUNC / LINKER_REMNANT .s files to the handwritten and remnants
         folders and comments out their `nonmatching` marker (it would make objdiff count
         them as unmatched);
       - trailing_padding.py --apply (cuts extra trailing nops; the sources are unchanged);
       - cuts the switch jump tables out of each data segment that holds them into
         <section>/rodata/jtbl_*.s and splits the segment into <name>_a.data.s /
         <name>_b.data.s (the steps of tools/migrate_jtbls.py that touch asm/).

Needs: the ELF in the repo root, `pip install -r tools/requirements.txt` and splat
(`pip install splat64`).
"""
import hashlib, os, re, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles  # noqa: E402


def run(*args):
    print("+", " ".join(args), flush=True)
    r = subprocess.run(list(args), cwd=ROOT)
    if r.returncode != 0:
        sys.exit("failed: %s" % " ".join(args))


def rd(p):
    return open(p, "rb").read()


def wr(p, b):
    open(p, "wb").write(b)


def yaml_option(yml, key, default):
    m = re.search(r"^\s*%s:\s*(\S+)" % key, yml, re.M)
    return m.group(1) if m else default


def asm_paths(t):
    """The target's asm folder, without other targets' folders nested inside it
    (frontbin's asm/ holds asm/boot_elf/)."""
    root = t.path("asm_root")
    others = {os.path.normpath(o.path("asm_root")) for o in targets.TARGETS.values() if o is not t}
    if not any(o.startswith(os.path.normpath(root) + os.sep) for o in others):
        return [root]
    if not os.path.isdir(root):
        return []
    return [os.path.join(root, e) for e in sorted(os.listdir(root))
            if os.path.normpath(os.path.join(root, e)) not in others]


def clear_asm(t):
    for p in asm_paths(t):
        if os.path.isdir(p):
            shutil.rmtree(p)
        elif os.path.exists(p):
            os.remove(p)


def normalize_data_words(t):
    """splat symbolizes data words that point at functions; the project's data .s files use literals."""
    ddir = os.path.join(t.path("asm_root"), "data")
    rx = re.compile(r"\.word func_([0-9A-F]{8})\b")
    for f in os.listdir(ddir):
        if not f.endswith(".s"):
            continue
        p = os.path.join(ddir, f)
        txt = open(p, newline="").read()
        t2 = rx.sub(lambda m: ".word 0x" + m.group(1), txt)
        t2 = re.sub(r"\.word func_0(?=\s|$)", ".word 0x00000000", t2, flags=re.M)
        if t2 != txt:
            open(p, "w", newline="").write(t2)


def split_data(t, seg, unit):
    """The asm/ half of tools/migrate_jtbls.py (steps 1 and 2) for one data segment."""
    data = os.path.join(t.path("asm_root"), "data", seg + ".data.s")
    rodir = os.path.join(ROOT, unit.asm_dir, "rodata")
    if not os.path.exists(data):
        print("%s not there, data split skipped (already done?)" % os.path.relpath(data, ROOT))
        return
    lines = open(data).read().split("\n")
    starts = [i for i, l in enumerate(lines) if l.startswith("nonmatching ")]
    header = lines[:starts[0]]
    blocks = []
    for k, i in enumerate(starts):
        j = starts[k + 1] if k + 1 < len(starts) else len(lines)
        blocks.append((lines[i].split()[1].rstrip(","), lines[i:j]))
    jt = [k for k, (n, _) in enumerate(blocks) if n.startswith("jtbl_")]
    if not jt:
        print("%s: no jump tables" % seg)
        return
    first, last = jt[0], jt[-1]
    if any(not n.startswith("jtbl_") for n, _ in blocks[first:last + 1]):
        sys.exit("%s: non-jtbl data inside the jump table block; aborting" % seg)
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

    d = os.path.dirname(data)
    write(os.path.join(d, seg + "_a.data.s"), blocks[:first])
    write(os.path.join(d, seg + "_b.data.s"), [],
          extra=tail + [""] + ["\n".join(b) for _, b in blocks[last + 1:]])
    os.replace(data, data + ".premigrate")
    print("split %s.data.s into %s_a / %s_b and wrote %d jump tables" % (seg, seg, seg, last - first + 1))


def fix_alignment(t):
    """splat starts every function's .s with `.align 3` (gcc aligns functions to 8 bytes).
    Some of boot_elf's core functions (Sony libraries, hand-written code) start on a
    4-byte boundary; for those the .s must say `.align 2`, or the assembler inserts a
    word and every later function moves. frontbin has none."""
    dirs = [u.asm_dir for u in t.units] + [t.handwritten, t.remnants]
    n = 0
    for d in dirs:
        d = os.path.join(ROOT, d)
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            m = re.match(r"func_([0-9A-F]{8})\.s$", f)
            if not m or int(m.group(1), 16) % 8 == 0:
                continue
            p = os.path.join(d, f)
            txt = open(p, newline="").read()
            new = re.sub(r"^\.align 3", ".align 2", txt, count=1, flags=re.M)
            if new != txt:
                open(p, "w", newline="").write(new)
                n += 1
    if n:
        print("%d functions start on a 4-byte boundary: .align 2" % n)


def main():
    t = targets.from_argv(allow_all="elf")
    elf = t.path("elf")
    if not os.path.exists(elf):
        sys.exit("%s not found in the repo root (see docs/wiki/Setup.md, step 2)" % t.elf)
    h = hashlib.sha1(rd(elf)).hexdigest()
    if h != t.sha1:
        sys.exit("%s has sha1 %s, expected %s (NTSC-U, SCUS-97353)" % (t.elf, h, t.sha1))

    yml = open(t.path("yaml")).read()
    side = [yaml_option(yml, "undefined_funcs_auto_path", "undefined_funcs_auto.txt"),
            yaml_option(yml, "undefined_syms_auto_path", "undefined_syms_auto.txt")]
    saved = {n: rd(os.path.join(ROOT, n)) for n in side if os.path.exists(os.path.join(ROOT, n))}

    files = srcfiles.read_file_list()
    temps, final_src, names, c_count = [], [], set(), 0
    for u in t.units:
        text = srcfiles.read_all(ROOT, [(r, s) for r, s in files if u.contains(s)]).encode("utf-8", "surrogateescape")
        final_src += re.findall(rb'(?:ASM_FUNC|LINKER_REMNANT)\("([^"]+)",\s*(func_[0-9A-Fa-f]{8})\)', text)
        # Functions already written as C have no INCLUDE_ASM, so splat would skip them.
        # localdecomp builds its function list (and the progress numbers) from the .s
        # files, so list them in the temporary file too: every function gets its .s.
        have = set(re.findall(rb'(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]+",\s*(func_[0-9A-Fa-f]{8})\)', text))
        c_names = set(re.findall(rb"localdecomp:start (func_[0-9A-F]{8})", text))
        c_names |= set(re.findall(rb"(?m)^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]{8})\s*\([^;{]*\)[^;{]*\{", text))
        c_names = {n for n in c_names - have if u.contains(int(n[5:], 16))}
        c_count += len(c_names)
        stubs = b"".join(b'\nINCLUDE_ASM("%s", %s);' % (u.asm_dir.encode(), n) for n in sorted(c_names)) + b"\n"
        # Function boundaries: the names in the sources (func_<address>) are the project's
        # units, and every .s must end exactly where the next one starts.
        names |= {int(m, 16) for m in re.findall(rb"func_([0-9A-F]{8})", text) if u.contains(int(m, 16))}
        body = re.sub(rb'(?:ASM_FUNC|LINKER_REMNANT)\("[^"]+",', b'INCLUDE_ASM("%s",' % u.asm_dir.encode(), text)
        temps.append((os.path.join(ROOT, t.splat_src, u.name + ".c"), body + stubs))
    print("%d functions are already C; adding temporary stubs so each gets a .s" % c_count)

    m = re.search(r"symbol_addrs_path:\s*\n((?:[ \t]*-[ \t]*\S+[ \t]*\n)+)", yml)
    taken = set()
    for sf in (re.findall(r"-\s*(\S+)", m.group(1)) if m else []):
        p = os.path.join(ROOT, sf)
        if os.path.exists(p):
            taken |= {int(a, 16) for a in re.findall(rb"=\s*0x0*([0-9A-Fa-f]+)", rd(p))}
    # Hand splat those addresses as function symbols through a temporary extra symbol
    # file and a temporary yaml.
    extra = os.path.join(ROOT, "symbol_addrs_setup.txt" if t.name == "frontbin" else "symbol_addrs_setup_%s.txt" % t.name)
    tmp_yaml = os.path.join(ROOT, "%s.setup.yaml" % t.name)
    with open(extra, "w") as f:
        for a in sorted(names):
            if a not in taken:
                f.write("func_%08X = 0x%08X;\n" % (a, a))
    yml2 = re.sub(r"(symbol_addrs_path:\s*\n(\s*)- \S+)", r"\1\n\2- %s" % os.path.basename(extra), yml, count=1)
    open(tmp_yaml, "w").write(yml2)
    for p, _ in temps:
        if os.path.exists(p):
            sys.exit("%s exists; the sources live in per-file folders now (remove the stale file first)"
                     % os.path.relpath(p, ROOT))
    clear_asm(t)
    try:
        for p, body in temps:
            os.makedirs(os.path.dirname(p), exist_ok=True)
            wr(p, body)
        run(sys.executable, "-m", "splat", "split", os.path.basename(tmp_yaml))
    finally:
        for p, _ in temps:
            if os.path.exists(p):
                os.remove(p)
        for n, b in saved.items():
            wr(os.path.join(ROOT, n), b)
        for f in (extra, tmp_yaml):
            if os.path.exists(f):
                os.remove(f)

    py = sys.executable
    paths = [os.path.relpath(p, ROOT) for p in asm_paths(t)]
    run(py, "tools/fix_reg_names.py", *paths)
    run(py, "tools/fix_quadword_ops.py", "--gp-value", "0x%08X" % t.gp, *paths)
    run(py, "tools/fix_short_loops.py", *paths)
    run(py, "tools/extract_header.py", "--target", t.name)

    n = 0
    for folder, func in final_src:
        folder, func = folder.decode(), func.decode()
        unit = t.unit_for(int(func[5:], 16))
        os.makedirs(os.path.join(ROOT, folder), exist_ok=True)
        s = os.path.join(ROOT, unit.asm_dir, func + ".s")
        if not os.path.exists(s):
            sys.exit("missing %s (did splat finish?)" % s)
        dest = os.path.join(ROOT, folder, func + ".s")
        shutil.move(s, dest)
        # splat's `nonmatching` line defines NAME.NON_MATCHING, which makes objdiff (and
        # decomp.dev) count the function as not matching. This .s is final source, so turn
        # that line into a comment, as tools/migrate_asm_sources.py did.
        txt = open(dest, newline="").read()
        txt = re.sub(r"^nonmatching (func_[0-9A-Fa-f]{8})(, *0x[0-9A-Fa-f]+)?[ \t]*(\r?)$",
                     r"/* nonmatching \1\2 -- marker removed: final source */\3", txt, flags=re.M)
        open(dest, "w", newline="").write(txt)
        n += 1
    print("moved %d ASM_FUNC / LINKER_REMNANT sources" % n)

    fix_alignment(t)
    run(py, "tools/trailing_padding.py", "--apply", "--target", t.name)
    normalize_data_words(t)
    for seg, unit in t.jtbl_segments.items():
        split_data(t, seg, t.unit(unit))
    print("done. Now build: make (Windows) or python3 tools/build.py%s (Linux/macOS)."
          % ("" if t.name == targets.DEFAULT else " --target " + t.name))


if __name__ == "__main__":
    main()
