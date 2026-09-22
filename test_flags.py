#!/usr/bin/env python3
"""
test_flags.py -- standalone compile-flag experiment tool for a single
function, bypassing localdecomp's website UI (which always builds with a
fixed -O2 -G0 and no way to change that from the browser).

This reuses the EXACT SAME build+diff mechanics as localdecomp/server.py's
build_and_diff() -- same gp-relative register trick, same linker script
shape, same objcopy alignment-slop trim, same asm-differ invocation -- so a
result from this script is directly comparable to what the website would
show for the same C source. The only difference is you control extra_cflags
from the command line instead of it being hardcoded.

Run this from your project root (the folder containing asm/, src/,
frontbin.elf, symbol_addrs.txt), or pass --project.

USAGE
-----
Single flag set, one function:
    python test_flags.py func_0037D6C8 --c my_candidate.c --cflags -O2 -G0

Try several flag sets back-to-back and compare scores in one run:
    python test_flags.py func_0037D6C8 --c my_candidate.c --try-variants

--try-variants runs a small fixed battery of flag combinations relevant to
the "stray stack frame" symptom (frame pointer, scheduling, gcse) and
prints a ranked table. Add your own combos to the VARIANTS list below if
you want to try something not included.

The --c file should contain your FULL candidate source (externs + gp
register variable + function body), exactly like what you'd paste into the
website's C SOURCE editor -- this script wraps it the same way server.py
does (localdecomp_common.h include + gp-relative macro layer), so paste
straight from the website's editor with no changes needed.
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Same defaults as server.py -- edit here if yours differ.
# ---------------------------------------------------------------------------
DEFAULT_TOOLBIN = r"C:\tools\eegcc_2.95.3_sn_v1.36\bin"
DEFAULT_GP_VALUE = 0x001DC8B0

# Flag-set battery for --try-variants. Each is a full replacement for
# extra_cflags (not additive) so you see exactly what was passed.
VARIANTS = [
    ("baseline (-O2 -G0)", ["-O2", "-G0"]),
    ("+ -fomit-frame-pointer", ["-O2", "-G0", "-fomit-frame-pointer"]),
    ("+ -fno-gcse", ["-O2", "-G0", "-fno-gcse"]),
    ("+ -fomit-frame-pointer -fno-gcse", ["-O2", "-G0", "-fomit-frame-pointer", "-fno-gcse"]),
    ("-O1 -G0", ["-O1", "-G0"]),
    ("-O3 -G0", ["-O3", "-G0"]),
]

# Focused battery for pure instruction-SCHEDULING mismatches (same
# instructions present, different order -- e.g. sd $ra vs a load swapped).
# Selected with --try-sched-variants instead of --try-variants.
SCHED_VARIANTS = [
    ("baseline (-O2 -G0)", ["-O2", "-G0"]),
    ("-fno-schedule-insns", ["-O2", "-G0", "-fno-schedule-insns"]),
    ("-fno-schedule-insns2", ["-O2", "-G0", "-fno-schedule-insns2"]),
    ("-fno-schedule-insns -fno-schedule-insns2",
     ["-O2", "-G0", "-fno-schedule-insns", "-fno-schedule-insns2"]),
    ("-fschedule-insns (explicit on)", ["-O2", "-G0", "-fschedule-insns"]),
]


class BuildError(Exception):
    def __init__(self, stage, message):
        super().__init__(message)
        self.stage = stage
        self.message = message


def find_function_asm(asm_dir: Path, func_name: str) -> str:
    for s_path in asm_dir.rglob("*.s"):
        content = s_path.read_text()
        if re.search(rf"^glabel\s+{re.escape(func_name)}\b", content, re.MULTILINE):
            return content
    raise SystemExit(f"Could not find {func_name} under {asm_dir}")


def load_manual_symbol_addrs(symbol_addrs_path: Path):
    addrs = {}
    if not symbol_addrs_path.exists():
        return addrs
    for line in symbol_addrs_path.read_text().splitlines():
        line = line.split("//", 1)[0].strip()
        m = re.match(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?\s*$", line)
        if m:
            addrs[m.group(1)] = int(m.group(2), 16)
    return addrs


def resolve_symbol_address(sym_hint: str):
    m = re.match(r"^(?:D|func|jtbl)_([0-9A-Fa-f]{5,8})(?:_\w*)?$", sym_hint)
    if m:
        return int(m.group(1), 16)
    return None


def find_referenced_symbols(asm_text: str, c_source: str):
    syms = set()
    for pat in (r"%hi\((\w+)\)", r"%lo\((\w+)\)", r"%gp_rel\((\w+)\)"):
        syms.update(re.findall(pat, asm_text))
    syms.update(re.findall(r"\b(D_[0-9A-Fa-f]{5,8}\w*)\b", c_source))
    syms.update(re.findall(r"\b(func_[0-9A-Fa-f]{5,8}\w*)\b", c_source))
    syms.update(re.findall(r"\b(jtbl_[0-9A-Fa-f]{5,8}\w*)\b", c_source))
    syms.discard(None)
    return sorted(syms)


def get_text_section_info(elf_path: Path, toolbin: Path):
    readelf = toolbin / "ee-readelf.exe"
    proc = subprocess.run([str(readelf), "-S", str(elf_path)], capture_output=True, text=True)
    for line in proc.stdout.splitlines():
        m = re.search(r"\.text\s+PROGBITS\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)", line)
        if m:
            return int(m.group(1), 16), int(m.group(2), 16)
    raise BuildError("setup", f"Could not find .text section in {elf_path}")


def build_and_diff(
    project_root: Path,
    toolbin: Path,
    gp_value: int,
    func_name: str,
    c_source: str,
    extra_cflags,
    work: Path,
):
    asm_dir = project_root / "asm" / "nonmatchings"
    target_elf = project_root / "frontbin.elf"
    symbol_addrs_path = project_root / "symbol_addrs.txt"

    asm_text = find_function_asm(asm_dir, func_name)
    m_addr = re.search(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", asm_text)
    m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", asm_text)
    if not (m_addr and m_size):
        raise BuildError("setup", f"Could not parse address/size for {func_name}")
    vaddr = int(m_addr.group(1), 16)
    size = int(m_size.group(1), 16)

    work.mkdir(exist_ok=True, parents=True)
    c_path = work / f"{func_name}.c"
    ld_path = work / f"{func_name}.ld"
    o_path = work / f"{func_name}.o"
    elf_path = work / f"{func_name}_linked.elf"
    target_bin = work / f"{func_name}_target.bin"
    source_bin = work / f"{func_name}_source.bin"
    common_h = work / "localdecomp_common.h"

    if not common_h.exists():
        common_h.write_text(
            "#ifndef LOCALDECOMP_COMMON_H\n#define LOCALDECOMP_COMMON_H\n"
            "typedef signed char s8; typedef unsigned char u8;\n"
            "typedef signed short s16; typedef unsigned short u16;\n"
            "typedef signed int s32; typedef unsigned int u32;\n"
            "typedef signed long long s64; typedef unsigned long long u64;\n"
            "typedef float f32; typedef double f64;\n"
            "#endif\n"
        )

    # Same gp-relative macro layer as server.py: any symbol the TARGET asm
    # proves is gp-relative gets redirected through a register-pinned
    # pointer, and the user's plain `extern SYM;` for that symbol is
    # stripped (the #define takes over).
    gp_rel_syms = sorted(set(re.findall(r"%gp_rel\((\w+)\)", asm_text)))
    gp_helpers = ""
    gp_defines = ""
    if gp_rel_syms:
        manual_addrs_for_gp = load_manual_symbol_addrs(symbol_addrs_path)
        gp_helpers += 'register char *_gprel_gp_reg __asm__("$28");\n'
        for sym in gp_rel_syms:
            addr = manual_addrs_for_gp.get(sym) or resolve_symbol_address(sym)
            if addr is None:
                continue
            offset = addr - gp_value
            gp_helpers += f"#define _gprel_ptr_{sym} ((int *)(_gprel_gp_reg + ({offset})))\n"
            gp_defines += f"#define {sym} (*_gprel_ptr_{sym})\n"

    filtered_c_source = c_source
    for sym in gp_rel_syms:
        filtered_c_source = re.sub(
            rf"^\s*extern\s+[\w \*]+\b{re.escape(sym)}\s*(\[\s*\])?\s*;\s*$",
            "",
            filtered_c_source,
            flags=re.MULTILINE,
        )

    full_c = (
        f'#include "{common_h.name}"\n\n' + gp_helpers + gp_defines + "\n" + filtered_c_source
    )
    c_path.write_text(full_c)

    manual_addrs = load_manual_symbol_addrs(symbol_addrs_path)
    symbols = find_referenced_symbols(asm_text, c_source)
    symbols = [s for s in symbols if s != func_name]
    unresolved = []
    provides = []
    for sym in symbols:
        addr = manual_addrs.get(sym) or resolve_symbol_address(sym)
        if addr is not None:
            provides.append(f"PROVIDE({sym} = 0x{addr:08X});")
        else:
            unresolved.append(sym)
    if unresolved:
        raise BuildError(
            "setup",
            "Could not determine an address for: " + ", ".join(unresolved) +
            "\nAdd it to symbol_addrs.txt as `NAME = 0xADDRESS;`",
        )
    provides_block = "\n".join(provides)

    ld_path.write_text(
        f"""/* auto-generated by test_flags.py for {func_name} */
{provides_block}

SECTIONS
{{
    . = 0x{vaddr:08X};
    .text : {{ *(.text) }}

    _gp = 0x{gp_value:08X};

    /DISCARD/ : {{ *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) }}
}}
"""
    )

    gcc = toolbin / "ee-gcc2953.exe"
    ld = toolbin / "ee-ld.exe"
    objcopy = toolbin / "ee-objcopy.exe"

    cmd = [str(gcc), "-c"] + extra_cflags + ["-o", str(o_path), str(c_path)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("compile", proc.stdout + proc.stderr)

    cmd = [str(ld), "-T", str(ld_path), "-o", str(elf_path), str(o_path)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("link", proc.stdout + proc.stderr)

    ALIGN_SLOP = 8
    cmd = [str(objcopy), "-O", "binary", str(elf_path), str(source_bin)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("extract-source", proc.stdout + proc.stderr)
    source_raw = source_bin.read_bytes()
    if size < len(source_raw) <= size + ALIGN_SLOP:
        source_bin.write_bytes(source_raw[:size])

    text_vaddr, text_fileoff = get_text_section_info(target_elf, toolbin)
    file_off = text_fileoff + (vaddr - text_vaddr)
    raw = target_elf.read_bytes()
    target_bin.write_bytes(raw[file_off : file_off + size])

    diff_settings = work / "diff_settings.py"
    diff_settings.write_text(
        f'''def apply(config, args):
    config["baseimg"] = r"{target_bin}"
    config["myimg"] = r"{source_bin}"
    config["mapfile"] = None
    config["source_directories"] = ["."]
    config["arch"] = "mipsel"
    config["objdump_executable"] = r"{toolbin / 'ee-objdump.exe'}"
'''
    )
    cmd = [sys.executable, "-m", "diff", "0", "--no-pager", "--format=json"]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("diff", proc.stdout + proc.stderr)
    try:
        diff_json = json.loads(proc.stdout)
    except json.JSONDecodeError:
        raise BuildError("diff-parse", proc.stdout + proc.stderr)

    return diff_json


def match_percent(current_score, max_score):
    if not max_score:
        return 100.0 if current_score == 0 else 0.0
    pct = 100 * (max_score - current_score) / max_score
    return max(0.0, min(100.0, pct))


def render_diff_rows(diff, max_rows=40):
    rows = diff.get("rows", [])
    out = []
    shown = 0
    for row in rows:
        base = row.get("base")
        cur = row.get("current")
        base_text = "".join(seg["text"] for seg in base["text"]) if base else None
        cur_text = "".join(seg["text"] for seg in cur["text"]) if cur else None
        if base_text is not None and cur_text is not None and base_text.strip() == cur_text.strip():
            continue
        out.append(f"  TARGET:  {base_text.strip() if base_text else '(missing)'}")
        out.append(f"  CURRENT: {cur_text.strip() if cur_text else '(missing)'}")
        shown += 1
        if shown >= max_rows:
            out.append(f"  ... (truncated at {max_rows} differing rows)")
            break
    return "\n".join(out) if out else "  (no differing rows -- 100% match)"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("function", help="function name, e.g. func_0037D6C8")
    ap.add_argument("--c", required=True, help="path to a .c file with your full candidate source")
    ap.add_argument("--project", default=".", help="project root (default: current dir)")
    ap.add_argument("--toolbin", default=DEFAULT_TOOLBIN)
    ap.add_argument("--gp", default=hex(DEFAULT_GP_VALUE))
    ap.add_argument("--cflags", nargs="*", default=None, help="single flag set, e.g. --cflags -O2 -G0 -fomit-frame-pointer")
    ap.add_argument("--try-variants", action="store_true", help="run the built-in VARIANTS battery instead of a single --cflags run")
    ap.add_argument("--try-sched-variants", action="store_true", help="run the SCHED_VARIANTS battery (instruction-scheduling flags only)")
    ap.add_argument("--show-diff", action="store_true", help="print the differing rows for each result, not just the score")
    args = ap.parse_args()

    project_root = Path(args.project).resolve()
    toolbin = Path(args.toolbin)
    gp_value = int(args.gp, 16)
    c_source = Path(args.c).read_text()
    work_root = project_root / ".test_flags_work"

    if args.try_sched_variants:
        variants = SCHED_VARIANTS
    elif args.try_variants:
        variants = VARIANTS
    else:
        cflags = args.cflags if args.cflags is not None else ["-O2", "-G0"]
        variants = [(" ".join(cflags), cflags)]

    results = []
    for label, cflags in variants:
        work = work_root / re.sub(r"[^\w.-]", "_", label)
        print("=" * 78)
        print(f"VARIANT: {label}")
        print("=" * 78)
        try:
            diff = build_and_diff(project_root, toolbin, gp_value, args.function, c_source, cflags, work)
        except BuildError as e:
            print(f"  FAILED at stage '{e.stage}':")
            print("  " + e.message.replace("\n", "\n  "))
            results.append((label, None, None, None))
            continue
        cur, mx = diff.get("current_score"), diff.get("max_score")
        pct = match_percent(cur, mx)
        print(f"  {pct:.2f}% match (current_score={cur}, max_score={mx})")
        if args.show_diff:
            print(render_diff_rows(diff))
        results.append((label, pct, cur, mx))
        print()

    print("=" * 78)
    print("SUMMARY (best first)")
    print("=" * 78)
    ranked = sorted([r for r in results if r[1] is not None], key=lambda r: -r[1])
    failed = [r for r in results if r[1] is None]
    for label, pct, cur, mx in ranked:
        marker = "  <-- 100% MATCH" if cur == 0 else ""
        print(f"  {pct:6.2f}%  {label}{marker}")
    for label, *_ in failed:
        print(f"   FAILED  {label}")


if __name__ == "__main__":
    main()
