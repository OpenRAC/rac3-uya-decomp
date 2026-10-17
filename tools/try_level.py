#!/usr/bin/env python3
"""try_level.py: compile one common-level source and compare it with retail.

The level counterpart of try_func.py. It runs build_common_c.py's gates for
one function and, when the resolved bytes differ, prints both instruction
listings side by side with the differing lines marked.

    python tools/try_level.py src/levels/common/func_004D0538.c --overlay singleplayer/1_veldin --flags-from func_003ABC30
    python tools/try_level.py src/levels/common/func_004D0538.c      (an entry already in tools/common_c.json)

--overlay defaults to the function's canonical owner; --flags-from names the
frontbin function whose text_parts.txt flags to compile with (--mode N|S and
--assembler default|ps2as override them, as in the catalogue). Exit status 0
only on a full match.
"""
import argparse, io, json, os, struct, subprocess, sys, tempfile
from pathlib import Path
from types import SimpleNamespace

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build_common_c as bcc  # noqa: E402
import try_func as matching  # noqa: E402


def disasm(code, addr, toolchain):
    """objdump listing of raw little-endian MIPS words."""
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "f.bin")
        open(p, "wb").write(code)
        r = subprocess.run([os.path.join(toolchain, "bin", "ee-objdump.exe"), "-D", "-b", "binary", "-m", "mips:5900",
                            "-EL", "--adjust-vma=0x%x" % addr, p], capture_output=True, text=True)
    out = []
    for line in r.stdout.splitlines():
        parts = line.split("\t")
        if len(parts) >= 3 and parts[0].strip().endswith(":"):
            out.append(" ".join(parts[2:]).strip())
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("--overlay")
    ap.add_argument("--flags-from")
    ap.add_argument("--mode", choices=["N", "S"])
    ap.add_argument("--assembler", choices=["default", "ps2as"])
    ap.add_argument("--refs", type=Path, default=Path(os.environ.get("UYA_REFS", r"C:\decomp-refs")))
    ap.add_argument("--toolchain", default=matching.DEFAULT_TOOLCHAIN)
    a = ap.parse_args()
    src = a.source.resolve()
    name = src.stem
    entry = next((e for e in json.loads((ROOT / "tools" / "common_c.json").read_text()) if e["name"] == name), {})
    owners = bcc.inventory(a.refs / "level-targets")
    owner = next(((lv, off, sz) for lv, n, off, sz in owners.values() if n == name), None)
    if owner is None:
        sys.exit("%s is not a canonical common-level owner" % name)
    lv, off, size = owner
    dirs = {p.parent.name: p.parent.relative_to(a.refs / "levels").as_posix() for p in (a.refs / "levels").glob("*/*/overlay.elf")}
    overlay = a.overlay or entry.get("overlay") or dirs[Path(lv.path).stem]
    flags_from = a.flags_from or entry.get("flags_from")
    if not flags_from:
        sys.exit("give --flags-from (a frontbin function with the right compiler flags)")
    fl = matching.flags_for(int(flags_from[5:], 16))
    mode = a.mode or entry.get("mode") or ("N" if "-mno-split-addresses" in fl else "S")
    asm = a.assembler or entry.get("assembler") or ("ps2as" if "@ps2as" in fl else "default")
    e = {"name": name, "source": src.relative_to(ROOT).as_posix(), "overlay": overlay, "address": name[5:] and "0x" + name[5:],
         "size": size, "flags_from": flags_from, "mode": mode, "assembler": asm}
    with open(a.refs / "level-targets-split" / "common.o", "rb") as f:
        ct = ELFFile(io.BytesIO(f.read()))
        text = ct.get_section_by_name(".text").data()
        common = {s.name: text[s["st_value"]:s["st_value"] + s["st_size"]] for s in ct.get_section_by_name(".symtab").iter_symbols()
                  if s["st_info"]["type"] == "STT_FUNC" and s["st_size"]}
    opts = SimpleNamespace(no_context=True, toolchain=a.toolchain, runner=None)
    try:
        bcc.compile_entry(e, a.refs / "levels", a.refs / "level-targets", owners, common, opts)
        print("MATCH %s (%d bytes)" % (name, size))
        print("catalogue entry: " + json.dumps(e))
        return 0
    except ValueError as err:
        print("NO MATCH: %s" % err)
    # show where it differs
    flags = matching.apply_overrides(fl, mode, asm)
    o = matching.compile_c(str(src), flags, opts, name)
    if o is None:
        return 1
    el = ELFFile(open(o, "rb"))
    sym = [s for s in el.get_section_by_name(".symtab").iter_symbols() if s.name == name]
    if not sym:
        print("the object doesn't define %s" % name)
        return 1
    t = el.get_section_by_name(".text").data()
    st, csz = sym[0]["st_value"], sym[0]["st_size"]
    res, _ = matching.resolve_relocations(el, t)
    lk = bytearray(t[st:st + csz])
    for pos, w in res.items():
        if st <= pos < st + csz:
            lk[pos - st:pos - st + 4] = w.to_bytes(4, "little")
    ov = ELFFile(open(a.refs / "levels" / overlay / "overlay.elf", "rb")).get_section_by_name(".text")
    addr = int(name[5:], 16)
    rt = ov.data()[addr - ov["sh_addr"]:addr - ov["sh_addr"] + size]
    mine, theirs = disasm(bytes(lk), addr, a.toolchain), disasm(rt, addr, a.toolchain)
    n, diffs = max(len(mine), len(theirs)), 0
    print("size: C %d bytes, retail %d bytes" % (csz, size))
    for i in range(n):
        x = mine[i] if i < len(mine) else ""
        y = theirs[i] if i < len(theirs) else ""
        mark = " " if x == y else "*"
        diffs += mark == "*"
        print("%s %08X  %-40s %s" % (mark, addr + 4 * i, x, y))
    print("%d differing instructions" % diffs)
    return 1


if __name__ == "__main__":
    sys.exit(main())
