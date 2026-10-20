#!/usr/bin/env python3
"""seed_levels.py: copy frontbin's matched C into the common level code.

Much of the code the 51 level overlays share (levels/common, see
docs/common_level_c.md) is frontbin's code linked at other addresses. When a
frontbin function is C and a canonical common owner has the same instructions,
the same C matches there once every address it names is translated:

  1. Functions are paired by their instructions with addresses masked (j/jal
     targets, %hi/%lo pairs and $gp offsets; field offsets are kept).
  2. Per owner level, a translation table frontbin address -> level address
     comes from every pair in that level: their instructions are the same, so
     the addresses in them pair up one to one. Addresses that pair with two
     different level addresses are dropped.
  3. Each frontbin block becomes a standalone source in src/levels/common/:
     the declarations in front of it in its frontbin file (the file header and
     earlier blocks, without function bodies or assembly), then the block, with
     every func_/D_/jtbl_ name renamed through the table.
  4. Every candidate goes through build_common_c.py's gates (complete size,
     resolved retail bytes, raw object body equal to the split common target,
     no data sections, no assembly). Only those that pass are kept and added to
     config/levels/common_c.json; the rest are deleted again.

Needs a built frontbin (build/frontbin.elf, for function sizes) and the private
level inputs (docs/common_level_c.md). Run it again whenever frontbin gains
matches; functions already in the catalogue are left alone.

    python tools/seed_levels.py [--refs C:/decomp-refs] [--jobs 8] [--limit N]
"""
import argparse, collections, concurrent.futures as cf, glob, io, json, os, re, struct, sys
from pathlib import Path
from types import SimpleNamespace

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import asm_filter  # noqa: E402
import build_common_c as bcc  # noqa: E402
import pr_check  # noqa: E402
import check as matching  # noqa: E402

GP = 0x1DC8B0
NAME_RE = re.compile(r"\b(func|D|jtbl)_([0-9A-Fa-f]{5,8})((?:_\w+)?)\b")
ASM_RE = re.compile(r"\b(?:__asm__|__asm|asm|INCLUDE_ASM|INCLUDE_RODATA|ASM_FUNC|LINKER_REMNANT)\b")
BLOCK_RE = re.compile(r"/\* localdecomp:start (\w+) \*/\n(.*?)/\* localdecomp:end \1 \*/", re.S)


def sext(v):
    return v - 0x10000 if v & 0x8000 else v


def words(b):
    return struct.unpack("<%dI" % (len(b) // 4), b[:len(b) // 4 * 4])


def shape(code):
    """Instruction words with address fields masked: j/jal targets, lui
    immediates, and the low halves that use a lui register or $gp."""
    out, hi = [], set()
    for w in words(code):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in (2, 3):
            w &= 0xFC000000
        elif op == 0x0F:
            w &= 0xFFFF0000
            hi.add(rt)
        elif (op in (0x08, 0x09, 0x0D) or op >= 0x20) and (rs == 28 or rs in hi):
            w &= 0xFFFF0000
        out.append(w)
    return tuple(out)


def address_pairs(fcode, faddr, lcode, laddr):
    """(frontbin address, level address) for every address field of two
    functions with the same shape."""
    hf, hl = {}, {}
    for i, (a, b) in enumerate(zip(words(fcode), words(lcode))):
        op, rs, rt = a >> 26, (a >> 21) & 31, (a >> 16) & 31
        if op in (2, 3):
            yield (((faddr + 4 * i + 4) & 0xF0000000) | (a & 0x3FFFFFF) << 2,
                   ((laddr + 4 * i + 4) & 0xF0000000) | (b & 0x3FFFFFF) << 2)
        elif op == 0x0F:
            hf[rt], hl[rt] = (a & 0xFFFF) << 16, (b & 0xFFFF) << 16
        elif op in (0x08, 0x09, 0x0D) or op >= 0x20:
            if rs == 28:
                yield GP + sext(a & 0xFFFF), GP + sext(b & 0xFFFF)
            elif rs in hf:
                lo = (lambda v: v & 0xFFFF) if op == 0x0D else (lambda v: sext(v & 0xFFFF))
                yield (hf[rs] + lo(a)) & 0xFFFFFFFF, (hl[rs] + lo(b)) & 0xFFFFFFFF
            if op < 0x20 or op in (0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x37):
                # addiu/ori/loads overwrite rt: its lui value is gone
                hf.pop(rt, None)
                hl.pop(rt, None)


def frontbin_functions():
    """name -> (address, retail bytes) for every frontbin .text function."""
    with open(ROOT / "baserom" / "frontbin.elf", "rb") as f:
        retail = ELFFile(f)
        text = retail.get_section_by_name(".text")
        tb, ta = text.data(), text["sh_addr"]
    with open(ROOT / "build" / "frontbin.elf", "rb") as f:
        linked = ELFFile(f)
        syms = [(s.name, s["st_value"], s["st_size"]) for s in linked.get_section_by_name(".symtab").iter_symbols()
                if s["st_info"]["type"] == "STT_FUNC" and s["st_size"] and s.name.startswith("func_")]
    return {n: (a, tb[a - ta:a - ta + sz]) for n, a, sz in syms if ta <= a and a + sz <= ta + len(tb)}


def frontbin_blocks():
    """name -> (prelude, block) for every C block in src/frontbin/."""
    out = {}
    for path in sorted(glob.glob(str(ROOT / "src" / "frontbin" / "*.c"))):
        text = open(path, encoding="utf-8").read().replace("\r\n", "\n")
        for m in BLOCK_RE.finditer(text):
            out[m.group(1)] = (text[:m.start()], m.group(2))
    return out


def top_level_items(code):
    """Split C at depth 0 into (text, is_function_definition)."""
    items, depth, start, i, n = [], 0, 0, 0, len(code)
    func = False
    while i < n:
        c = code[i]
        if c == "#" and depth == 0 and (i == 0 or code[i - 1] == "\n"):
            j = code.find("\n", i)
            j = n if j < 0 else j
            items.append((code[i:j + 1], False))
            i = start = j + 1
            continue
        if c == "{":
            if depth == 0:
                head = code[start:i].rstrip()
                func = head.endswith(")") and not re.search(r"\b(struct|union|enum)\b[^;]*$", head) and "=" not in head
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and func:
                items.append((code[start:i + 1], True))
                start, func = i + 1, False
        elif c == ";" and depth == 0:
            items.append((code[start:i + 1], False))
            start = i + 1
        i += 1
    if code[start:].strip():
        items.append((code[start:], False))
    return items


def declarations(code):
    """The declarations in this code: no function bodies, no assembly."""
    keep = []
    for text, is_def in top_level_items(pr_check.strip_comments(code, keep_strings=True)):
        if is_def or not text.strip() or ASM_RE.search(text):
            continue
        keep.append(text.strip())
    return keep


IDENT_RE = re.compile(r"\b[A-Za-z_]\w*\b")
KEYWORDS = set("""void char short int long float double signed unsigned const volatile extern static
    register struct union enum typedef return if else for while do switch case default break continue
    goto sizeof s8 u8 s16 u16 s32 u32 s64 u64 f32 f64""".split())


def declared(decl):
    """Names a declaration introduces (approximate, for dependency pruning)."""
    return _declared(decl) - KEYWORDS


def _declared(decl):
    if decl.startswith("#define"):
        m = re.match(r"#define\s+(\w+)", decl)
        return {m.group(1)} if m else set()
    names = set(re.findall(r"\(\s*\*\s*(\w+)", decl))
    flat = re.sub(r"\{.*\}", " ", decl, flags=re.S)  # struct bodies
    if flat.lstrip().startswith("typedef"):
        m = re.search(r"(\w+)\s*(?:\[[^\]]*\])*\s*;\s*$", flat)
        if m:
            names.add(m.group(1))
        names.update(re.findall(r",\s*\**\s*(\w+)", flat))
        return names
    m = re.search(r"(\w+)\s*\(", flat)
    if m and not re.search(r"\(\s*\*\s*$", flat[:m.start()]):
        names.add(m.group(1))
    names.update(re.findall(r"(\w+)\s*\[", flat))
    if "(" not in flat:
        m = re.search(r"(\w+)\s*(?:=[^;]*)?;\s*$", flat)
        if m:
            names.add(m.group(1))
    return names


def needed(decls, code):
    """The declarations `code` depends on, transitively, in their order."""
    want, keep, info = set(IDENT_RE.findall(code)), set(), [(d, declared(d), set(IDENT_RE.findall(d))) for d in decls]
    changed = True
    while changed:
        changed = False
        for i, (d, names, idents) in enumerate(info):
            if i not in keep and names & want:
                keep.add(i)
                want |= idents
                changed = True
    return [info[i][0] for i in sorted(keep)]


EXTERN_RE = re.compile(r'__asm__\s*\(\s*"\.extern[^"]*"\s*\)\s*;[ \t]*\n?')


def make_source(prelude, block, table, local=()):
    """Standalone level source for a frontbin block, or None if unusable.
    `.extern` size hints (for Ps2EeAs) are dropped: the level gates allow no
    assembly at all, and a function that needed them fails the byte gates."""
    block = EXTERN_RE.sub("", block)
    body = pr_check.strip_comments(block, keep_strings=True)
    if ASM_RE.search(body):
        return None
    items = top_level_items(body)
    if sum(1 for _, d in items if d) != 1:
        return None
    decls = []
    for d in declarations(prelude):
        if d not in decls and not d.startswith("#include"):
            decls.append(d)
    decls = needed(decls, body)
    src = "#include \"common.h\"\n\n" + "\n".join(decls) + ("\n\n" if decls else "") + block.strip() + "\n"

    def rename(m):
        a = int(m.group(2), 16)
        if a in table:
            return "%s_%08X%s" % (m.group(1), table[a], m.group(3))
        # a symbol the function only reaches at an offset (a struct field):
        # the function's own addresses just above it give its shift
        near = {y - x for x, y in local if a <= x < a + 0x100}
        if len(near) == 1:
            return "%s_%08X%s" % (m.group(1), a + near.pop(), m.group(3))
        return m.group(0)
    return NAME_RE.sub(rename, src)


def target_function_names():
    """Function names in the executables' builds: a common-level table entry
    must not name one of them (asm_filter reads both tables for every target)."""
    out = set()
    for path in (ROOT / "build" / "frontbin.elf", ROOT / "build" / "boot_elf" / "boot_elf.elf", ROOT / "build" / "i5bootn" / "i5bootn.elf"):
        if path.exists():
            with open(path, "rb") as f:
                out |= {s.name for s in ELFFile(f).get_section_by_name(".symtab").iter_symbols() if s["st_info"]["type"] == "STT_FUNC"}
    return out


def read_lines(path):
    return [l.rstrip("\n") for l in open(path, encoding="utf-8")] if path.exists() else []


def write_tables(sq, divs):
    """config/levels/common_c_sq_ra_funcs.txt and config/levels/common_c_divs_nops.txt."""
    Path(asm_filter.COMMON_SQ_RA).write_text(
        "# Common-level functions whose retail prologue saves $ra with sq/lq, like their\n"
        "# frontbin donor in config/frontbin/sq_ra_funcs.txt (tools/seed_levels.py).\n"
        + "".join(n + "\n" for n in sorted(sq)), encoding="utf-8", newline="\n")
    Path(asm_filter.COMMON_DIVS).write_text(
        "# Common-level div.s/sqrt.s nop counts, copied from the frontbin donor's line in\n"
        "# config/frontbin/divs_nops.txt (tools/seed_levels.py).\n"
        + "".join("%s %s\n" % (n, " ".join(map(str, divs[n]))) for n in sorted(divs)), encoding="utf-8", newline="\n")


def read_table_names(path):
    return [l.split("#")[0].split()[0] for l in read_lines(path) if l.split("#")[0].strip()]


def level_dirs(levels_dir):
    return {p.parent.name: p.parent.relative_to(levels_dir).as_posix() for p in levels_dir.glob("*/*/overlay.elf")}


def verify(args):
    entry, src, refs = args
    path = ROOT / entry["source"]
    path.write_text(src, encoding="utf-8", newline="\n")
    try:
        bcc.compile_entry(entry, *refs, SimpleNamespace(no_context=True, toolchain=matching.DEFAULT_TOOLCHAIN, runner=None))
        return entry, None
    except Exception as e:  # noqa: BLE001, a failed gate is a skip
        path.unlink()
        return entry, str(e)[:120]


_REFS = None


def _init(refs):
    global _REFS
    _REFS = refs


def _verify(job):
    return verify((job[0], job[1], _REFS))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--refs", type=Path, default=Path(os.environ.get("UYA_REFS", r"C:\decomp-refs")))
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--limit", type=int, default=0, help="try at most N candidates (smallest first)")
    ap.add_argument("--report", type=Path, help="write each skipped candidate's donor, source and reason here (JSON)")
    a = ap.parse_args()
    levels_dir, targets_dir = a.refs / "levels", a.refs / "level-targets"
    catalogue_path = ROOT / "config" / "levels" / "common_c.json"
    catalogue = json.loads(catalogue_path.read_text(encoding="utf-8"))
    have = {e["name"] for e in catalogue}

    fb = frontbin_functions()
    blocks = frontbin_blocks()
    by_shape = collections.defaultdict(list)
    for n, (addr, code) in fb.items():
        by_shape[shape(code)].append(n)

    owners = bcc.inventory(targets_dir)
    dirs = level_dirs(levels_dir)
    # per level: retail .text, and every function's (name, address, bytes)
    levels = {}
    for level, _, _, _ in owners.values():
        if level.path in levels:
            continue
        name = Path(level.path).stem
        with open(levels_dir / dirs[name] / "overlay.elf", "rb") as f:
            text = ELFFile(f).get_section_by_name(".text")
            data, base = text.data(), text["sh_addr"]
        levels[level.path] = (name, base, [(fn, base + off, data[off:off + sz]) for _, fn, off, sz, _ in level.funcs])

    # translation tables, one per owner level
    tables = {}
    for path, (name, base, funcs) in levels.items():
        seen = collections.defaultdict(set)
        for fn, laddr, code in funcs:
            for donor in by_shape.get(shape(code), ())[:1]:
                faddr, fcode = fb[donor]
                for x, y in address_pairs(fcode, faddr, code, laddr):
                    seen[x].add(y)
        tables[path] = {x: next(iter(ys)) for x, ys in seen.items() if len(ys) == 1}

    with open(a.refs / "level-targets-split" / "common.o", "rb") as f:
        ct = ELFFile(io.BytesIO(f.read()))
        text = ct.get_section_by_name(".text").data()
        common = {s.name: text[s["st_value"]:s["st_value"] + s["st_size"]] for s in ct.get_section_by_name(".symtab").iter_symbols()
                  if s["st_info"]["type"] == "STT_FUNC" and s["st_size"]}

    jobs = []
    for level, oname, off, size in owners.values():
        if oname in have:
            continue
        name, base, _ = levels[level.path]
        laddr = base + off
        if oname != "func_%08X" % laddr:
            continue
        with open(levels_dir / dirs[name] / "overlay.elf", "rb") as f:
            t = ELFFile(f).get_section_by_name(".text")
            code = t.data()[off:off + size]
        donors = [d for d in by_shape.get(shape(code), ()) if d in blocks]
        if not donors:
            continue
        donor = donors[0]
        # the function's own address pairs are exact for it; the level-wide
        # table covers the rest (prototypes of callees it only declares)
        local = set(address_pairs(fb[donor][1], fb[donor][0], code, laddr))
        own = collections.defaultdict(set)
        for x, y in local:
            own[x].add(y)
        table = dict(tables[level.path])
        table.update({x: next(iter(ys)) for x, ys in own.items() if len(ys) == 1})
        table[fb[donor][0]] = laddr
        src = make_source(*blocks[donor], table, local)
        if src is None:
            continue
        fl = matching.flags_for(fb[donor][0])
        entry = {"name": oname, "source": "src/levels/common/%s.c" % oname, "overlay": dirs[name],
                 "address": "0x%08X" % laddr, "size": size, "flags_from": donor,
                 "mode": "N" if "-mno-split-addresses" in fl else "S",
                 "assembler": "ps2as" if "@ps2as" in fl else "default"}
        jobs.append((entry, src))
    jobs.sort(key=lambda j: j[0]["size"])
    if a.limit:
        jobs = jobs[:a.limit]
    print("candidates: %d" % len(jobs), flush=True)

    # names whose donor needs sq_ra / div.s nops get the same entry
    fsq = set(read_table_names(ROOT / "config" / "frontbin" / "sq_ra_funcs.txt"))
    fdv = asm_filter.divs_table()
    old_sq = set(n for n in read_table_names(Path(asm_filter.COMMON_SQ_RA)))
    old_dv = {n: v for n, v in fdv.items() if n in set(read_table_names(Path(asm_filter.COMMON_DIVS)))}
    taken = target_function_names()
    new_sq = {e["name"] for e, _ in jobs if e["flags_from"] in fsq and e["name"] not in taken}
    new_dv = {e["name"]: fdv[e["flags_from"]] for e, _ in jobs if e["flags_from"] in fdv and e["name"] not in taken}
    write_tables(old_sq | new_sq, {**old_dv, **new_dv})

    refs = (levels_dir, targets_dir, owners, common)
    passed, reasons, failed = [], collections.Counter(), []
    sources = {e["name"]: src for e, src in jobs}
    if a.jobs > 1:
        # owners holds pyelftools objects that don't pickle; workers rebuild them
        with cf.ProcessPoolExecutor(a.jobs, initializer=_worker_init, initargs=(str(a.refs),)) as ex:
            for i, (entry, err) in enumerate(ex.map(_verify, jobs, chunksize=4)):
                if err is None:
                    passed.append(entry)
                else:
                    reasons.update([err.split(":")[0][:60]])
                    failed.append(dict(entry, reason=err, text=sources[entry["name"]]))
                if i % 50 == 49:
                    print("  %d/%d tried, %d match" % (i + 1, len(jobs), len(passed)), flush=True)
    else:
        for i, job in enumerate(jobs):
            entry, err = verify((job[0], job[1], refs))
            if err is None:
                passed.append(entry)
            else:
                reasons.update([err.split(":")[0][:60]])
                failed.append(dict(entry, reason=err, text=sources[entry["name"]]))
    ok = {e["name"] for e in passed}
    write_tables(old_sq | (new_sq & ok), {**old_dv, **{n: v for n, v in new_dv.items() if n in ok}})
    catalogue += sorted(passed, key=lambda e: int(e["address"], 16))
    catalogue_path.write_text(json.dumps(catalogue, indent=2) + "\n", encoding="utf-8")
    print("seeded: %d new common-level functions (%d bytes)" % (len(passed), sum(e["size"] for e in passed)))
    for r, n in reasons.most_common(12):
        print("  skipped %4d: %s" % (n, r))
    if a.report:
        a.report.write_text(json.dumps(failed, indent=1) + "\n", encoding="utf-8")


def _worker_init(refs):
    refs = Path(refs)
    owners = bcc.inventory(refs / "level-targets")
    with open(refs / "level-targets-split" / "common.o", "rb") as f:
        ct = ELFFile(io.BytesIO(f.read()))
        text = ct.get_section_by_name(".text").data()
        common = {s.name: text[s["st_value"]:s["st_value"] + s["st_size"]] for s in ct.get_section_by_name(".symtab").iter_symbols()
                  if s["st_info"]["type"] == "STT_FUNC" and s["st_size"]}
    _init((refs / "levels", refs / "level-targets", owners, common))


if __name__ == "__main__":
    main()
