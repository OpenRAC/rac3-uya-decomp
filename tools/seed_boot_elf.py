#!/usr/bin/env python3
"""seed_boot_elf.py: copy frontbin's matched C into boot_elf's overlay.

boot_elf.elf's overlay (.text at 0x381180) is frontbin's code linked at other
addresses (see tools/bootstrap_boot_elf.py). When a frontbin function is C and
its boot_elf twin is the same code, the same C matches there once every
address it names is translated:

  1. The two sections are aligned word by word (address immediates masked) to
     pair each frontbin function with its boot_elf twin. Only twins whose whole
     body aligns unchanged are used.
  2. A translation table, frontbin address -> boot_elf address, comes from the
     two .s files of every unchanged pair: their instructions are the same, so
     the symbols in them (%hi/%lo, jal targets, $gp offsets) pair up one to one.
     An address the C names but the assembly never shows (a struct base only
     accessed at offsets) takes the shift of its nearest mapped neighbours, when
     the neighbours on both sides agree.
  3. Each block's D_/func_ names, per-function aliases included, are renamed
     through the table, and the block replaces the twin's INCLUDE_ASM (and its
     INCLUDE_RODATA lines: gcc emits the jump tables itself). The function gets
     its frontbin flags in targets/boot_elf/text_parts.txt.
  4. The declarations from other files are refreshed and the symbol file is
     regenerated; then the full build is run and every seeded function is
     compared with retail. A function that doesn't match goes back to
     INCLUDE_ASM, until the build prints MATCH.

Run it again whenever frontbin gains matches; functions already C in boot_elf
are left alone.

    python tools/seed_boot_elf.py                                     (Windows: make.exe check-boot_elf)
    python3 tools/seed_boot_elf.py --toolchain ~/sn --runner ~/bin/wibo   (Linux/macOS)
    add --no-build to insert without verifying
"""
import argparse, bisect, collections, json, os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
import srcfiles as sf  # noqa: E402
import build_text as bt  # noqa: E402
import bootstrap_boot_elf as bs  # noqa: E402

FB, BE = bs.FB, bs.BE
NL = "\r\n"
ASM_RE = re.compile(r'^INCLUDE_ASM\("%s",\s*(func_[0-9A-F]{8})\);[^\n]*\n(?:INCLUDE_RODATA\([^\n]*\n)*'
                    % re.escape(BE.unit("text").asm_dir), re.M)
# D_/func_<hex>, with an optional alias suffix: _<owner function address> or a
# word (frontbin has a few like D_001D9C48_g)
NAME_RE = re.compile(r"\b(D|func)_([0-9A-Fa-f]+)((?:_\w+)?)\b")
INS = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+([0-9A-F]{8})\s*\*/\s+(\S+)\s*(.*)$")
SYM = re.compile(r"\b((?:D|func|jtbl)_[0-9A-Fa-f]+)\b")
GPD = re.compile(r"(-?0x[0-9A-Fa-f]+|-?\d+)\(\$gp\)|\$gp,\s*(-?0x[0-9A-Fa-f]+|-?\d+)")


# ------------------------------------------------------------ pairing

def pair_functions():
    fdata = open(FB.path("elf"), "rb").read()
    bdata = open(BE.path("elf"), "rb").read()
    fents = bs.frontbin_entries()
    wmap = bs.align_text(fdata, bdata)
    fstart, bstart = FB.unit("text").start, BE.unit("text").start
    fmap, same = {}, set()
    for addr, _ in fents:
        i = (addr - fstart) // 4
        if i in wmap:
            fmap[addr] = bstart + 4 * wmap[i]
            size = bs.frontbin_size(addr)
            if size and all(wmap.get(i + k) == wmap[i] + k for k in range(size // 4)):
                same.add(addr)
    return fents, fmap, same


def asm_file(t, addr):
    unit = t.unit_for(addr)
    for d in ([unit.asm_dir] if unit else []) + [t.handwritten, t.remnants]:
        p = os.path.join(ROOT, d, "func_%08X.s" % addr)
        if os.path.exists(p):
            return p
    return None


def refs(path):
    out = []
    for l in open(path, errors="ignore"):
        m = INS.search(l)
        if not m:
            continue
        ops = m.group(4).split("/*")[0]
        r = [int(x.split("_")[1], 16) for x in SYM.findall(ops)]
        for g in GPD.finditer(ops):
            r.append(BE.gp + int(g.group(1) or g.group(2), 0))
        out.append(r)
    return out


def address_table(fmap, same):
    pairs = collections.defaultdict(collections.Counter)
    for fa in same:
        fp, bp = asm_file(FB, fa), asm_file(BE, fmap[fa])
        if not fp or not bp:
            continue
        fr, br = refs(fp), refs(bp)
        if len(fr) != len(br):
            continue
        for a, b in zip(fr, br):
            if len(a) == len(b):
                for x, y in zip(a, b):
                    pairs[x][y] += 1
    table = {x: c.most_common(1)[0][0] for x, c in pairs.items() if len(c) == 1}
    for fa, ba in fmap.items():      # every function start pairs too
        table.setdefault(fa, ba)
    return table


class Translator:
    def __init__(self, table):
        self.table = table
        self.keys = sorted(table)

    def addr(self, a):
        if a in self.table:
            return self.table[a]
        i = bisect.bisect_left(self.keys, a)
        if 0 < i < len(self.keys):
            lo, hi = self.keys[i - 1], self.keys[i]
            d1, d2 = self.table[lo] - lo, self.table[hi] - hi
            if d1 == d2 and (lo >> 20) == (a >> 20) == (hi >> 20):
                return a + d1
        return None

    def block(self, text, fmap):
        missing = []

        def sub(m):
            kind, hexa, suffix = m.group(1), m.group(2), m.group(3)
            a = int(hexa, 16)
            b = fmap.get(a) if kind == "func" else None
            if b is None:
                b = self.addr(a)
            if b is None:
                missing.append(m.group(0))
                return m.group(0)
            if re.fullmatch(r"_[0-9A-Fa-f]{6,8}", suffix):
                owner = int(suffix[1:], 16)
                new_owner = fmap.get(owner, owner)
                suffix = "_%0*X" % (len(suffix) - 1, new_owner)
            return "%s_%0*X%s" % (kind, len(hexa), b, suffix)

        return NAME_RE.sub(sub, text), missing


# ------------------------------------------------------------ editing

def frontbin_blocks():
    """({addr: C block body}, {addr: free-standing text in front of that entry}).
    Free-standing declarations between blocks belong to the next function
    (srcfiles.attach_free_text); later blocks rely on them."""
    out, free = {}, {}
    for rel, _ in sf.read_file_list(FB.path("files")):
        txt = sf.read_source(rel)
        for m in re.finditer(r"/\* localdecomp:start (func_[0-9A-F]{8}) \*/\n(.*?)/\* localdecomp:end \1 \*/", txt, re.S):
            out[int(m.group(1)[5:], 16)] = m.group(2)
        _, _, chunks = sf.split_file(txt)
        for a, _, body in chunks:
            if not sf.BLOCK_RE.match(body.lstrip("\n")) and body.strip():
                free[a] = free.get(a, "") + body.strip("\n") + "\n\n"
    return out, free


def insert_free(free):
    """Put translated free-standing text in front of each twin's entry (once)."""
    ent = re.compile(r'^(?:/\* localdecomp:start (func_[0-9A-F]{8}) \*/|(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]*",\s*(func_[0-9A-F]{8})\);)', re.M)
    n = 0
    for rel, _ in boot_files():
        path = os.path.join(ROOT, rel)
        txt = open(path, "rb").read().decode().replace("\r\n", "\n")

        def sub(m):
            nonlocal n
            a = int((m.group(1) or m.group(2))[5:], 16)
            t = free.get(a)
            if not t or t in txt:
                return m.group(0)
            n += 1
            return t + m.group(0)

        new = ent.sub(sub, txt)
        if new != txt:
            open(path, "wb").write(new.replace("\n", NL).encode())
    return n


def boot_files():
    return [(r, s) for r, s in sf.read_file_list(BE.path("files")) if BE.unit("text").contains(s)]


def insert_blocks(blocks):
    """blocks: {boot addr: C text}; replaces INCLUDE_ASM (+ INCLUDE_RODATA) lines."""
    done = set()
    for rel, _ in boot_files():
        path = os.path.join(ROOT, rel)
        raw = open(path, "rb").read().decode()
        txt = raw.replace("\r\n", "\n")

        def sub(m):
            a = int(m.group(1)[5:], 16)
            if a not in blocks:
                return m.group(0)
            done.add(a)
            name = m.group(1)
            return "/* localdecomp:start %s */\n%s/* localdecomp:end %s */\n" % (name, blocks[a], name)

        new = ASM_RE.sub(sub, txt)
        if new != txt:
            open(path, "wb").write(new.replace("\n", NL).encode())
    return done


def revert_blocks(addrs, rodata):
    """C blocks back to INCLUDE_ASM (+ their INCLUDE_RODATA lines)."""
    unit = BE.unit("text")
    for rel, _ in boot_files():
        path = os.path.join(ROOT, rel)
        txt = open(path, "rb").read().decode().replace("\r\n", "\n")

        def sub(m):
            a = int(m.group(1)[5:], 16)
            if a not in addrs:
                return m.group(0)
            lines = ['INCLUDE_ASM("%s", %s);' % (unit.asm_dir, m.group(1))]
            lines += ['INCLUDE_RODATA("%s/rodata", %s);' % (unit.asm_dir, t) for t in rodata.get(a, [])]
            return "\n".join(lines) + "\n"

        new = re.sub(r"/\* localdecomp:start (func_[0-9A-F]{8}) \*/\n.*?/\* localdecomp:end \1 \*/\n", sub, txt, flags=re.S)
        if new != txt:
            open(path, "wb").write(new.replace("\n", NL).encode())


def overlay_c():
    out = set()
    for rel, _ in boot_files():
        out |= {int(n[5:], 16) for n in re.findall(r"localdecomp:start (func_[0-9A-F]{8})", sf.read_source(rel))}
    return out


def overlay_entries():
    out = []
    for rel, _ in boot_files():
        _, _, chunks = sf.split_file(sf.read_source(rel))
        for a, _, _ in chunks:
            if not out or out[-1] != a:
                out.append(a)
    return sorted(set(out))


def write_parts(fmap):
    """Overlay lines of text_parts.txt from per-function flags: a C function gets
    its frontbin twin's flags; an assembly function the same without @ps2as /
    @newas (Ps2EeAs can't read INCLUDE_ASM stubs, see pr_check.py)."""
    fparts = bt.read_parts(FB.path("parts"))
    inv = {b: f for f, b in fmap.items()}
    cset = overlay_c()
    want, prev = [], None
    for a in overlay_entries():
        if a in inv:
            fl = list(bt.flags_for(fparts, inv[a]))
        else:
            fl = list(prev or [])
        if a not in cset:
            fl = [f for f in fl if f not in ("@ps2as", "@newas")]
        want.append((a, fl))
        prev = fl
    lines = []
    runs = []
    for a, fl in want:
        if not runs or runs[-1][1] != fl:
            runs.append([a, fl, 1])
        else:
            runs[-1][2] += 1
    starts = {s for _, s in boot_files()}
    for i, (a, fl, n) in enumerate(runs):
        single = n == 1 and 0 < i < len(runs) - 1 and runs[i - 1][1] == runs[i + 1][1] and a not in starts
        lines.append("0x%08X     %s%s" % (a, " ".join(fl), "   # single-function override" if single else ""))
    # file starts keep a line even when the flags don't change, so each file states its flags
    have = {int(l.split()[0], 16) for l in lines}
    for s in starts:
        if s not in have:
            fl = dict(want).get(s)
            lines.append("0x%08X     %s" % (s, " ".join(fl)))
    lines.sort(key=lambda l: int(l.split()[0], 16))
    path = BE.path("parts")
    old = open(path, "rb").read().decode().split("\r\n")
    keep = [l for l in old if not (l.startswith("0x") and BE.unit("text").contains(int(l.split()[0], 16)))]
    keep = [l for l in keep if l != ""]
    hdr = [l for l in keep if not l.startswith("0x")]
    core = [l for l in keep if l.startswith("0x")]
    open(path, "wb").write((NL.join(hdr + core + lines) + NL).encode())


def write_symbols():
    """bootstrap_boot_elf.write_symbols, plus the names the C sources use."""
    bs.write_symbols()
    path = BE.path("symbols_resolved")
    have = set(re.findall(r"^(\w+)\s*=", open(path, "rb").read().decode(), re.M))
    defined = set()
    for d, _, fs in os.walk(BE.path("asm_root")):
        for f in fs:
            if f.endswith(".s"):
                defined |= set(re.findall(r"^\s*(?:glabel|dlabel)\s+(\w+)", open(os.path.join(d, f), errors="ignore").read(), re.M))
    used = set()
    for rel, _ in sf.read_file_list(BE.path("files")):
        txt = sf.read_source(rel)
        used |= {m.group(0) for m in NAME_RE.finditer(txt)}
    c_defs = set()
    for rel, _ in sf.read_file_list(BE.path("files")):
        c_defs |= set(re.findall(r"localdecomp:start (func_[0-9A-F]{8})", sf.read_source(rel)))
    add = sorted(n for n in used - have - defined - c_defs)
    with open(path, "ab") as f:
        for n in add:
            f.write(("%s = 0x%s;%s" % (n, n.split("_")[1], NL)).encode())
    print("symbols: %d more for the C sources" % len(add))


# ------------------------------------------------------------ verification

def build(args):
    if os.name == "nt":
        # Windows: the Makefile's boot_elf build (SN's make.exe)
        make = os.path.join(args.toolchain or r"C:\tools\eegcc_2.95.3_sn_v1.36", "bin", "make.exe")
        cmd = [make, "check-boot_elf"]
    else:
        cmd = [sys.executable, "tools/build.py", "--target", "boot_elf", "--toolchain", args.toolchain]
        if args.runner:
            cmd += ["--runner", args.runner]
    p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    return p.returncode == 0, p.stdout + p.stderr


def check_functions(addrs):
    """{addr: diffs} for seeded functions, from the per-file objects of the last build."""
    import io, contextlib
    import try_func as tf
    retail = tf.Retail(BE.path("elf"))
    out = {}
    by_file = collections.defaultdict(list)
    for a in addrs:
        by_file[sf.file_for_address(sf.read_file_list(BE.path("files")), a)].append(a)
    for rel, al in by_file.items():
        stem = os.path.splitext(os.path.basename(rel))[0]
        o = os.path.join(ROOT, BE.workdir(BE.unit("text")), stem + ".o")
        with contextlib.redirect_stdout(io.StringIO()):
            res = tf.diff_object(o, ["func_%08X" % a for a in al], retail, True)
        for a in al:
            out[a] = res.get("func_%08X" % a)
    return out


def blocks_at_lines(rel, lines, alive):
    """Seeded functions whose block (or free-standing text in front of it) holds
    one of `lines`. An error in the file's prelude (declarations from other
    files) blames every seeded function of the file that uses the name the
    error is about; failing that, the file's last seeded function."""
    _, _, chunks = sf.split_file(sf.read_source(rel))
    out = set()
    starts = sorted((l, a) for a, l, _ in chunks)
    for ln in lines:
        owner = None
        for l, a in starts:
            if l <= ln:
                owner = a
        if owner in alive:
            out.add(owner)
    if not out:
        in_file = sorted(a for a, _, _ in chunks if a in alive)
        out = set(in_file[-1:])
    return out


def failing_files(out):
    return sorted(set(re.findall(r"build_text: (src/boot_elf/text/\w+\.c)", out)))


def main():
    targets.from_argv(["", "--target", "boot_elf"])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"),
                    help=r"toolchain folder (Windows default C:\tools\eegcc_2.95.3_sn_v1.36)")
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER"))
    ap.add_argument("--no-build", action="store_true", help="insert and stop (no verification)")
    args = ap.parse_args()

    fents, fmap, same = pair_functions()
    fkind = dict(fents)
    table = address_table(fmap, same)
    tr = Translator(table)
    print("address table: %d addresses" % len(table))
    fblocks, ffree = frontbin_blocks()
    have_c = overlay_c()
    cand, skipped = {}, collections.Counter()
    for fa, kind in fents:
        if kind != "C":
            continue
        if fa not in same:
            skipped["changed in boot_elf"] += 1
            continue
        ba = fmap[fa]
        if ba in have_c:
            continue
        text, missing = tr.block(fblocks[fa], fmap)
        if missing:
            skipped["an address with no translation"] += 1
            continue
        cand[ba] = text
    print("seeding %d functions (%s)" % (len(cand), ", ".join("%d %s" % (n, k) for k, n in skipped.items()) or "none skipped"))

    # rodata lines to restore on revert
    rodata = {}
    unit = BE.unit("text")
    for a in cand:
        p = os.path.join(ROOT, unit.asm_dir, "func_%08X.s" % a)
        if os.path.exists(p):
            ts = sorted(set(re.findall(r"jtbl_[0-9A-F]{8}", open(p).read())))
            if ts:
                rodata[a] = ts
    inserted = insert_blocks(cand)
    print("inserted %d" % len(inserted))
    free = {}
    for fa, t in ffree.items():
        if fa in fmap:
            tt, missing = tr.block(t, fmap)
            if not missing:
                free[fmap[fa]] = tt
    print("free-standing declarations carried over: %d" % insert_free(free))
    write_parts(fmap)
    subprocess.run([sys.executable, "tools/split_text.py", "--refresh", "--target", "boot_elf"], cwd=ROOT, check=True)
    write_symbols()
    if args.no_build:
        return

    alive = set(inserted)
    for rnd in range(1, 30):
        ok, out = build(args)
        bad = set()
        bad_files = failing_files(out)
        if bad_files:
            # a file that doesn't compile: drop its seeded functions one at a time from the end
            for rel in bad_files:
                errors = re.findall(r"%s:(\d+): (.*)" % re.escape(rel), out)
                print("round %d: %s does not build (%s)" % (rnd, rel, errors[:1]))
                bad |= blocks_at_lines(rel, {int(l) for l, _ in errors}, alive)
        else:
            res = check_functions(alive)
            bad = {a for a, d in res.items() if d != 0}
            if ok and not bad:
                print("round %d: MATCH with %d seeded functions" % (rnd, len(alive)))
                break
            if not bad:
                print(out[-2000:])
                sys.exit("build fails but every seeded function matches; look at the log above")
        print("round %d: %d functions back to INCLUDE_ASM" % (rnd, len(bad)))
        revert_blocks(bad, rodata)
        alive -= bad
        write_parts(fmap)
        subprocess.run([sys.executable, "tools/split_text.py", "--refresh", "--target", "boot_elf"], cwd=ROOT, check=True)
    print("seeded: %d functions now C in boot_elf's overlay" % len(alive))


if __name__ == "__main__":
    main()
