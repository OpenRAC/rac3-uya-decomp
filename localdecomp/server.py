#!/usr/bin/env python3
"""
localdecomp - a minimal local decomp.me-alike for splat-based PS2 decompilation
projects, built to work with the frontbin_decomp project (or any splat project
using the same layout).

Run this from your project root (the folder containing asm/, src/, frontbin.elf,
etc) or point --project at it. It starts a local web server; open the printed
URL in a browser.

Requirements: Python 3.9+, no third-party pip packages (uses only stdlib).
The compiler toolchain and asm-differ ("python -m diff") must already work --
this reuses the exact same test_func.ld-style single-function link+diff
approach that was validated by hand earlier in this project.
"""

import argparse
import http.server
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading
import urllib.parse
from pathlib import Path

# ---------------------------------------------------------------------------
# Configuration - edit these to match your machine if they differ.
# ---------------------------------------------------------------------------

DEFAULT_TOOLBIN = r"C:\tools\eegcc_2.95.3_sn_v1.36\bin"
DEFAULT_GP_VALUE = 0x001DC8B0  # confirmed via PCSX2 live-debug for frontbin.elf
DEFAULT_PORT = 8477

# ---------------------------------------------------------------------------
# Project model: discover functions from splat's asm/nonmatchings output.
# ---------------------------------------------------------------------------


class Project:
    def __init__(self, root: Path, toolbin: Path, gp_value: int):
        self.root = root
        self.toolbin = toolbin
        self.gp_value = gp_value
        self.target_elf = root / "frontbin.elf"
        self.asm_dir = root / "asm" / "nonmatchings"
        self.src_file = root / "src" / "text.c"
        self.work_dir = root / ".localdecomp_work"
        self.work_dir.mkdir(exist_ok=True)
        self.symbol_addrs_path = root / "symbol_addrs.txt"
        # Canonical per-function source of truth: the FULL editor contents
        # (externs, helper decls, and the function body together) for each
        # function this tool has touched, plus its last known score. Never
        # try to regex-extract "just the function" back out of src/text.c --
        # that silently drops externs/helpers on every save/reload cycle.
        self.funcs_dir = self.work_dir / "funcs"
        self.funcs_dir.mkdir(exist_ok=True)
        self.status_path = self.work_dir / "status.json"

        if not self.target_elf.exists():
            raise SystemExit(f"Target ELF not found: {self.target_elf}")
        if not self.asm_dir.exists():
            raise SystemExit(f"asm/nonmatchings not found under: {root}")

    def load_status(self):
        if not self.status_path.exists():
            return {}
        try:
            return json.loads(self.status_path.read_text())
        except json.JSONDecodeError:
            return {}

    def save_status_entry(self, name: str, current_score, max_score):
        status = self.load_status()
        status[name] = {"current_score": current_score, "max_score": max_score}
        self.status_path.write_text(json.dumps(status, indent=2))

    def load_manual_symbol_addrs(self):
        """
        Parse splat-style symbol_addrs.txt lines: `NAME = 0xADDR;` (optionally
        with trailing `// comment` or size annotations splat itself may add).
        Lets you rename a D_XXXXXXXX symbol to something meaningful while
        still telling this tool its real address.
        """
        addrs = {}
        if not self.symbol_addrs_path.exists():
            return addrs
        for line in self.symbol_addrs_path.read_text().splitlines():
            line = line.split("//", 1)[0].strip()
            m = re.match(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?\s*$", line)
            if m:
                addrs[m.group(1)] = int(m.group(2), 16)
        return addrs

    # -- function discovery ------------------------------------------------

    def list_functions(self):
        """
        Scan every .s file under asm/nonmatchings for splat's
        'nonmatching NAME, 0xSIZE' / 'glabel NAME' header lines, plus the
        address encoded in the first instruction comment
        (/* FILEOFF VADDR WORDHEX */). Match status comes from status.json
        (the real score from the last Build through this tool) when present.

        A function that already has real C in src/text.c (not an
        INCLUDE_ASM(...) stub) but has never been Built through this tool --
        e.g. splat itself wrote a trivial `{}` body for a tiny function
        during the initial split, or you edited src/text.c by some other
        means -- is reported as "unverified" rather than "none", so it isn't
        silently downgraded from however it looked before this tool existed.
        Build it once to get a real "perfect"/"partial" verdict.
        """
        funcs = []
        status = self.load_status()
        text_c = self.src_file.read_text() if self.src_file.exists() else ""

        for s_path in sorted(self.asm_dir.rglob("*.s")):
            content = s_path.read_text()
            m_name = re.search(r"^glabel\s+(\S+)", content, re.MULTILINE)
            m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", content)
            m_addr = re.search(
                r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", content
            )
            if not (m_name and m_addr):
                continue
            name = m_name.group(1)
            vaddr = int(m_addr.group(1), 16)
            size = int(m_size.group(1), 16) if m_size else None

            entry = status.get(name)
            if entry is not None:
                match_status = "perfect" if entry.get("current_score") == 0 else "partial"
            else:
                is_stub = re.search(
                    rf'INCLUDE_ASM\([^)]*,\s*{re.escape(name)}\s*\)', text_c
                ) is not None
                match_status = "none" if is_stub else "unverified"

            funcs.append(
                {
                    "name": name,
                    "vaddr": vaddr,
                    "size": size,
                    "asm_path": str(s_path.relative_to(self.root)),
                    "match_status": match_status,
                    "current_score": entry.get("current_score") if entry else None,
                    "max_score": entry.get("max_score") if entry else None,
                }
            )

        funcs.sort(key=lambda f: f["vaddr"])
        return funcs

    def get_function_asm(self, name: str) -> str:
        for s_path in self.asm_dir.rglob("*.s"):
            content = s_path.read_text()
            if re.search(rf"^glabel\s+{re.escape(name)}\b", content, re.MULTILINE):
                return content
        raise KeyError(name)

    def _func_store_path(self, name: str) -> Path:
        return self.funcs_dir / f"{name}.c"

    def get_function_c(self, name: str) -> str:
        """
        Return the FULL editor content (externs + body together) last saved
        for this function, if any; otherwise a starter template. This is the
        tool's own canonical store -- never regex-sliced back out of
        src/text.c, which would silently drop externs/helpers on reload.
        """
        store_path = self._func_store_path(name)
        if store_path.exists():
            return store_path.read_text()
        return f"s32 {name}(void) {{\n    // TODO\n}}\n"

    def save_function_c(self, name: str, c_source: str):
        """
        Persist the full editor content for `name` in this tool's own store
        (funcs/<name>.c), AND write it into the real project's src/text.c so
        the full-project build/splat workflow picks it up too -- replacing
        either the INCLUDE_ASM(...) stub (first save) or a previously-saved
        body for this function (subsequent saves).
        """
        self._func_store_path(name).write_text(c_source)

        if not self.src_file.exists():
            raise BuildError("save", f"{self.src_file} does not exist")
        text_c = self.src_file.read_text()
        body = c_source.strip() + "\n"

        start_marker = f"/* localdecomp:start {name} */"
        end_marker = f"/* localdecomp:end {name} */"

        include_pat = re.compile(
            rf'INCLUDE_ASM\([^)]*,\s*{re.escape(name)}\s*\)\s*;'
        )
        if include_pat.search(text_c):
            wrapped = f"{start_marker}\n{body}{end_marker}"
            new_text_c = include_pat.sub(lambda _m: wrapped, text_c, count=1)
            self.src_file.write_text(new_text_c)
            return

        # Already saved before, with markers -- replace the whole marked
        # block, externs included, rather than regex-matching just a
        # function signature (fragile and lossy).
        if start_marker in text_c and end_marker in text_c:
            start = text_c.index(start_marker)
            end = text_c.index(end_marker) + len(end_marker)
            new_text_c = text_c[:start] + start_marker + "\n" + body + end_marker + text_c[end:]
            self.src_file.write_text(new_text_c)
            return

        # Legacy fallback: a body was saved by an older version of this tool
        # (before markers existed), so there's no INCLUDE_ASM and no marker
        # to find. Locate it the old way -- by function signature -- and
        # wrap the replacement in markers this time so future saves use the
        # reliable marker path instead of repeating this fallback.
        pattern = re.compile(
            rf"^[A-Za-z_][\w \*]*\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{",
            re.MULTILINE,
        )
        m = pattern.search(text_c)
        if m:
            start = m.start()
            depth = 0
            i = text_c.index("{", m.end() - 1)
            end = None
            for j in range(i, len(text_c)):
                if text_c[j] == "{":
                    depth += 1
                elif text_c[j] == "}":
                    depth -= 1
                    if depth == 0:
                        end = j + 1
                        break
            if end is not None:
                wrapped = f"{start_marker}\n{body}{end_marker}"
                new_text_c = text_c[:start] + wrapped + text_c[end:]
                self.src_file.write_text(new_text_c)
                return

        raise BuildError(
            "save",
            f"Could not find INCLUDE_ASM({name}), a previous localdecomp "
            f"save-marker, or an existing function body for {name} in "
            f"{self.src_file} -- nothing to replace.",
        )

    def find_referenced_symbols(self, asm_text: str, c_source: str):
        """
        Collect every external symbol this build might need pinned:
          - data globals referenced via %hi/%lo/%gp_rel in the TARGET asm
            (ground truth for what the real function touches)
          - anything matching the D_XXXXXXXX / func_XXXXXXXX auto-naming
            convention appearing in the user's C source, including function
            CALLS (which never show up as %hi/%lo/%gp_rel -- those relocate
            differently, via plain jal/j to an absolute or PC-region address)
        This over-collects a little (e.g. local variable names that happen to
        start with func_) but resolve_symbol_address() only succeeds for the
        real convention, so stray matches are harmlessly dropped later as
        "unresolved" only if actually referenced as an extern the linker
        needs -- and the linker link step is the real authority: if a symbol
        genuinely isn't needed, an unused PROVIDE() is harmless.
        """
        syms = set()
        for pat in (
            r"%hi\((\w+)\)",
            r"%lo\((\w+)\)",
            r"%gp_rel\((\w+)\)",
        ):
            syms.update(re.findall(pat, asm_text))

        # Anything named like the D_/func_/jtbl_ auto-convention in the C
        # source (covers function calls, which don't show up via
        # %hi/%lo/%gp_rel). splat doesn't always zero-pad to 8 hex digits
        # (e.g. D_1A1ED0 for 0x001A1ED0), so accept 5-8 digits here too --
        # matching resolve_symbol_address's own tolerance.
        syms.update(re.findall(r"\b(D_[0-9A-Fa-f]{5,8}\w*)\b", c_source))
        syms.update(re.findall(r"\b(func_[0-9A-Fa-f]{5,8}\w*)\b", c_source))
        syms.update(re.findall(r"\b(jtbl_[0-9A-Fa-f]{5,8}\w*)\b", c_source))

        # Never pin the function being defined itself.
        syms.discard(None)
        return sorted(syms)


# ---------------------------------------------------------------------------
# Build + diff pipeline (single function, matches the manually-validated
# approach: compile -G0, link at real vaddr with PROVIDE()-pinned externs and
# the real _gp, then diff target vs rebuilt .text bytes with asm-differ).
# ---------------------------------------------------------------------------


class BuildError(Exception):
    def __init__(self, stage, message):
        super().__init__(message)
        self.stage = stage
        self.message = message


# The HTTP server is threaded (ThreadingHTTPServer), so concurrent
# /api/build requests for DIFFERENT functions can genuinely run at once.
# That's a real problem here: asm-differ's `python -m diff` reads a
# hardcoded `diff_settings.py` filename from its cwd (there's no CLI way
# to point it at a per-request settings file), and build_and_diff always
# writes that same shared path just before invoking it. Two overlapping
# builds can interleave -- one thread's diff_settings.py write lands
# between another thread's write and its subprocess actually reading the
# file, so a build silently scores/diffs against the WRONG function's
# target and current bytes with no error raised. This was hit in
# practice (confirmed by a batch-driven exploration session seeing two
# contradictory "target" disassemblies for the same function across
# consecutive fetches). Serializing all builds behind one lock is the
# simplest fix that's actually correct: this is a single-user local tool,
# so giving up build parallelism costs nothing that matters, versus a
# silently wrong diff which is a correctness bug that can lead to saving
# incorrect C source with confidence.
_build_lock = threading.Lock()


def resolve_symbol_address(sym_hint: str):
    """
    D_001D5B90 / func_0037D100 / jtbl_00317FE0-style names encode their own
    address, matching splat's own auto-naming convention for data, code, and
    jump-table symbols. splat does NOT always zero-pad to 8 hex digits --
    an address below 0x01000000 can come out as e.g. D_1A1ED0 (6 digits) --
    so this accepts 5-8 hex digits rather than requiring exactly 8.
    Anything else (a renamed symbol) falls back to None -- add it to
    symbol_addrs.txt instead, which load_manual_symbol_addrs() checks first.
    """
    m = re.match(r"^(?:D|func|jtbl)_([0-9A-Fa-f]{5,8})(?:_\w*)?$", sym_hint)
    if m:
        return int(m.group(1), 16)
    return None


def build_and_diff(project: Project, func_name: str, c_source: str, extra_cflags=None):
    # Serialize the whole build+diff pipeline (see _build_lock's comment
    # above) -- the shared diff_settings.py race is the specific hazard,
    # but locking the whole function is simpler and safer than trying to
    # scope the lock just around the diff step, since intermediate files
    # under work_dir are also only safely reused across calls, not
    # genuinely safe for TRUE concurrent access to the same function name.
    with _build_lock:
        return _build_and_diff_locked(project, func_name, c_source, extra_cflags)


def _build_and_diff_locked(project: Project, func_name: str, c_source: str, extra_cflags=None):
    extra_cflags = extra_cflags or ["-O2", "-G0"]

    asm_text = project.get_function_asm(func_name)
    m_addr = re.search(
        r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", asm_text
    )
    m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", asm_text)
    if not (m_addr and m_size):
        raise BuildError("setup", f"Could not parse address/size for {func_name}")
    vaddr = int(m_addr.group(1), 16)
    size = int(m_size.group(1), 16)

    work = project.work_dir
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

    # Detect which symbols the TARGET actually accesses via %gp_rel($gp).
    # A plain `extern` in C can never become gp-relative under real GCC
    # semantics -- that addressing mode is only chosen by the compiler for
    # objects IT allocates into .sdata/.sbss in the current translation
    # unit, never for a symbol merely declared extern (the compiler has no
    # way to know at compile time where an external symbol's definition
    # will end up). We deliberately build with -G0 everywhere (see the
    # note above find_referenced_symbols) because -Gn would make GCC guess
    # which OTHER globals are small-data too, based on size alone, with no
    # relation to where the real linker actually placed them -- silently
    # corrupting currently-correct absolute-addressed accesses elsewhere.
    #
    # So for the specific symbols the target asm PROVES were gp-relative
    # (found via %gp_rel(SYM) in the target .s), we force exactly that
    # addressing mode using a real GCC register variable pinned to $gp
    # ($28) plus pointer arithmetic to the symbol's known offset from _gp
    # -- the same mechanism (not a guess) manually verified earlier to
    # produce byte-identical lw/sw $gp_rel instructions. This is generated
    # automatically per build from the target asm, so it only ever touches
    # symbols proven gp-relative for THIS function, never guessed.
    #
    # We `#define SYM (*_gprel_ptr_SYM)` so the user's C source keeps using
    # the plain extern name as an ordinary lvalue (reads, writes, `x++`,
    # `+=`, etc. all work normally) -- the redirection is invisible.
    gp_rel_syms = sorted(set(re.findall(r"%gp_rel\((\w+)\)", asm_text)))

    gp_helpers = ""
    gp_defines = ""
    if gp_rel_syms:
        manual_addrs_for_gp = project.load_manual_symbol_addrs()
        # HISTORY of what was tried here (all tested against func_0039BEC0,
        # baseline 1255/5400 = 76.76% match), so a future attempt doesn't
        # repeat a ruled-out variant:
        #
        # v1 (CURRENT / best found):
        #     `#define _gprel_ptr_SYM ((int *)(_gprel_gp_reg + offset))`
        #     where _gprel_gp_reg is a `register char *` pinned to $28.
        #     GCC's optimizer sometimes CSEs the address arithmetic for two
        #     nearby-offset symbols into one shared base register plus an
        #     extra `addiu` -- an instruction the real target never has.
        #     This caps the score at 1255/5400 (76.76%), but is still the
        #     best of the three variants tried.
        # v2: same, but pointee marked `volatile` to forbid that CSE.
        #     Tested: WORSE (52.5%) -- volatile also forbids GCC from
        #     reusing an already-loaded value across multiple uses in one
        #     C expression, which the target's real compile relies on (one
        #     lw feeding both an array index and an increment). Reverted.
        # v3: each symbol gets its own accessor FUNCTION (inlined),
        #     computing its address via one opaque inline-asm `addiu`
        #     instruction with no C-visible pointer arithmetic at all, so
        #     there's nothing to CSE between DIFFERENT symbols. Tested:
        #     WORSE (3090/5400, 57.2%) -- it built and inlined
        #     successfully, but because each reference to the SAME symbol
        #     now recomputes its own address from scratch (no shared
        #     pointer to reuse across multiple accesses to that one
        #     symbol, e.g. D_001D6DA4 is read/incremented/re-stored three
        #     times in this function), the cost of repeated address
        #     recomputation exceeded the cost of v1's occasional
        #     cross-symbol CSE. Reverted.
        #
        # Net: v1 remains the best mechanism found. The extra addiu CSE
        # is a known, accepted limitation -- do not re-try v2 or v3 as
        # written above; a genuinely new idea would need to let a SINGLE
        # symbol's address be computed once and reused across its own
        # multiple uses (like v1) while still preventing the optimizer
        # from sharing that computation with a DIFFERENT symbol (unlike
        # v1) -- something like a per-symbol register-pinned pointer
        # variable (not a shared base + macro arithmetic, and not a
        # function call) is the next thing worth trying if revisited.
        # v4: attempted a dedicated register-pinned pointer PER symbol,
        # each with its own statement-expression initializer computing the
        # address via one opaque `addiu`. NOT VALID AS WRITTEN: this was
        # emitted at file scope (before the function body), but a global
        # register variable in GCC can't carry a runtime statement
        # -expression initializer the way a local one can -- global
        # register variables just reserve a register for the whole
        # translation unit, with no "run this code once and cache it"
        # semantics. Making this legitimately local would require
        # injecting these declarations as the first statements INSIDE the
        # target function's body (after its opening `{`), which needs
        # fragile brace-matching text surgery on arbitrary user C -- the
        # same category of fragile regex surgery that caused real bugs
        # elsewhere in this project before (see save_function_c's
        # history). Not attempted for that reason; v1 stands.
        #
        # v5: tried each symbol with its OWN independently-named base
        # pointer register variable (still `char *` pinned to $28, but a
        # distinct C identifier per symbol). RESULT: scored IDENTICAL to
        # v1 (1255/5400, byte-for-byte the same extra `addiu`) -- GCC's
        # CSE keys off the computed expression's value/structure, not the
        # source-level variable name, so this naming trick changes
        # nothing. Ruled out; reverted to v1's simpler single shared
        # `_gprel_gp_reg` (no reason to keep the per-symbol names once
        # they're proven not to matter).
        #
        # The extra-addiu CSE is emitted by GCC's own gcse (global common
        # subexpression elimination) pass, which -O2 enables. The next
        # lever to try is disabling that PASS directly with -fno-gcse,
        # rather than continuing to vary how the C source expresses the
        # address computation -- see the extra_cflags handling below
        # build_and_diff's signature; this needs testing via the API's
        # `flags` override (POST /api/build accepts `flags`) before
        # changing the DEFAULT for every function.
        gp_helpers += "register char *_gprel_gp_reg __asm__(\"$28\");\n"
        for sym in gp_rel_syms:
            addr = manual_addrs_for_gp.get(sym)
            if addr is None:
                addr = resolve_symbol_address(sym)
            if addr is None:
                # Can't compute an offset without a real address; leave this
                # symbol as a plain extern (normal absolute addressing) --
                # better than failing the whole build over one symbol the
                # user hasn't renamed/mapped yet.
                continue
            offset = addr - project.gp_value
            gp_helpers += (
                f"#define _gprel_ptr_{sym} "
                f"((int *)(_gprel_gp_reg + ({offset})))\n"
            )
            gp_defines += f"#define {sym} (*_gprel_ptr_{sym})\n"

    # Strip the user's own `extern ... SYM;` declaration for each gp_rel
    # symbol -- once we #define SYM to a dereferenced pointer expression,
    # `extern s32 SYM;` would expand to `extern s32 (*_gprel_ptr_SYM);`,
    # a syntax error (and semantically wrong even if it parsed). The
    # #define takes over entirely for these symbols; leaving the extern
    # out is safe since nothing else needs the plain declaration.
    filtered_c_source = c_source
    for sym in gp_rel_syms:
        filtered_c_source = re.sub(
            rf"^\s*extern\s+[\w \*]+\b{re.escape(sym)}\s*(\[\s*\])?\s*;\s*$",
            "",
            filtered_c_source,
            flags=re.MULTILINE,
        )

    # The #defines must appear before c_source so they're in effect when the
    # user's code uses those symbol names.
    full_c = (
        f'#include "{common_h.name}"\n\n'
        + gp_helpers
        + gp_defines
        + "\n"
        + filtered_c_source
    )
    c_path.write_text(full_c)

    # Gather every extern-looking global referenced by the TARGET asm (the
    # ground truth for what this function touches) and pin each to its real
    # address so the linker can resolve them without real definitions.
    # Manual symbol_addrs.txt entries take precedence over the D_XXXXXXXX
    # auto-decoded convention, so renaming a symbol doesn't break linking.
    manual_addrs = project.load_manual_symbol_addrs()
    symbols = project.find_referenced_symbols(asm_text, c_source)
    symbols = [s for s in symbols if s != func_name]
    unresolved = []
    provides = []
    for sym in symbols:
        addr = manual_addrs.get(sym)
        if addr is None:
            addr = resolve_symbol_address(sym)
        if addr is not None:
            provides.append(f"PROVIDE({sym} = 0x{addr:08X});")
        else:
            unresolved.append(sym)
    provides_block = "\n".join(provides)

    if unresolved:
        raise BuildError(
            "setup",
            "Could not determine an address for: " + ", ".join(unresolved) +
            "\nAdd it to symbol_addrs.txt as `NAME = 0xADDRESS;` and retry.",
        )

    ld_path.write_text(
        f"""/* auto-generated by localdecomp for {func_name} */
{provides_block}

SECTIONS
{{
    . = 0x{vaddr:08X};
    .text : {{ *(.text) }}

    _gp = 0x{project.gp_value:08X};

    /DISCARD/ : {{ *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) }}
}}
"""
    )

    gcc = project.toolbin / "ee-gcc2953.exe"
    ld = project.toolbin / "ee-ld.exe"
    objcopy = project.toolbin / "ee-objcopy.exe"

    # --- compile ---
    cmd = [str(gcc), "-c"] + extra_cflags + ["-o", str(o_path), str(c_path)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("compile", proc.stdout + proc.stderr)

    # --- link ---
    cmd = [str(ld), "-T", str(ld_path), "-o", str(elf_path), str(o_path)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("link", proc.stdout + proc.stderr)

    # --- extract raw bytes for both sides ---
    # source side: objcopy the linked ELF straight to raw binary. This old
    # SN binutils build doesn't support --only-section/-j for objcopy, so we
    # rely on the linker script instead: it defines ONLY .text (everything
    # else is /DISCARD/ed). For most functions that dump is already exactly
    # the function's bytes.
    #
    # Very short functions are a special case: `.align 3` (8-byte) padding
    # after a single instruction can make the dump slightly LONGER than the
    # real target size, and asm-differ then diffs that trailing garbage
    # against nothing, which can push current_score past max_score (seen on
    # func_0037D1A0: 0x4-byte target, reported 300/100). Trim ONLY a small
    # overshoot (at most one alignment slot) to drop that padding.
    #
    # A LARGER overshoot is not padding -- it means the compiled code is
    # genuinely longer than the target (real extra/different instructions),
    # and asm-differ needs the full tail to score and display that honestly.
    # Truncating in that case cuts real instructions mid-stream and corrupts
    # the alignment of everything after the cut, which previously turned a
    # real 3470/5400 match into a worse-looking 3955/5400 for
    # func_0039BEC0 -- so only ever trim the small, alignment-sized case.
    ALIGN_SLOP = 8
    cmd = [str(objcopy), "-O", "binary", str(elf_path), str(source_bin)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("extract-source", proc.stdout + proc.stderr)
    source_raw = source_bin.read_bytes()
    if size < len(source_raw) <= size + ALIGN_SLOP:
        source_bin.write_bytes(source_raw[:size])

    # target side: slice the real frontbin.elf at vaddr's file offset.
    # We need .text's vaddr/fileoff to convert; read them once from the ELF
    # program header (assumes single PT_LOAD like frontbin.elf's real layout;
    # adjust here if your target binary has multiple LOAD segments).
    text_vaddr, text_fileoff = get_text_section_info(project.target_elf, project.toolbin)
    file_off = text_fileoff + (vaddr - text_vaddr)
    raw = project.target_elf.read_bytes()
    target_bin.write_bytes(raw[file_off : file_off + size])

    # --- diff ---
    diff_settings = work / "diff_settings.py"
    diff_settings.write_text(
        f'''def apply(config, args):
    config["baseimg"] = r"{target_bin}"
    config["myimg"] = r"{source_bin}"
    config["mapfile"] = None
    config["source_directories"] = ["."]
    config["arch"] = "mipsel"
    config["objdump_executable"] = r"{project.toolbin / 'ee-objdump.exe'}"
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

    project.save_status_entry(
        func_name, diff_json.get("current_score"), diff_json.get("max_score")
    )
    return diff_json


_text_section_cache = {}


def get_text_section_info(elf_path: Path, toolbin: Path):
    key = str(elf_path)
    if key in _text_section_cache:
        return _text_section_cache[key]
    readelf = toolbin / "ee-readelf.exe"
    proc = subprocess.run(
        [str(readelf), "-S", str(elf_path)], capture_output=True, text=True
    )
    for line in proc.stdout.splitlines():
        m = re.search(
            r"\.text\s+PROGBITS\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)", line
        )
        if m:
            vaddr = int(m.group(1), 16)
            fileoff = int(m.group(2), 16)
            _text_section_cache[key] = (vaddr, fileoff)
            return vaddr, fileoff
    raise BuildError("setup", f"Could not find .text section in {elf_path}")


# ---------------------------------------------------------------------------
# HTTP server
# ---------------------------------------------------------------------------

STATIC_DIR = Path(__file__).parent / "static"


class Handler(http.server.BaseHTTPRequestHandler):
    project: Project = None  # set by main()

    def _send_json(self, obj, status=200):
        body = json.dumps(obj).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def log_message(self, fmt, *args):
        sys.stderr.write("%s - %s\n" % (self.address_string(), fmt % args))

    def do_GET(self):
        parsed = urllib.parse.urlparse(self.path)
        if parsed.path == "/" or parsed.path == "/index.html":
            self._serve_static("index.html", "text/html")
            return
        if parsed.path == "/app.js":
            self._serve_static("app.js", "application/javascript")
            return
        if parsed.path == "/style.css":
            self._serve_static("style.css", "text/css")
            return
        if parsed.path == "/api/functions":
            try:
                funcs = self.project.list_functions()
                self._send_json({"functions": funcs})
            except Exception as e:
                self._send_json({"error": str(e)}, 500)
            return
        if parsed.path == "/api/function":
            qs = urllib.parse.parse_qs(parsed.query)
            name = qs.get("name", [None])[0]
            if not name:
                self._send_json({"error": "missing name"}, 400)
                return
            try:
                self._send_json(
                    {
                        "name": name,
                        "asm": self.project.get_function_asm(name),
                        "c": self.project.get_function_c(name),
                    }
                )
            except KeyError:
                self._send_json({"error": f"unknown function {name}"}, 404)
            return
        self.send_response(404)
        self.end_headers()

    def do_POST(self):
        parsed = urllib.parse.urlparse(self.path)
        if parsed.path == "/api/build":
            length = int(self.headers.get("Content-Length", 0))
            body = json.loads(self.rfile.read(length))
            name = body.get("name")
            c_source = body.get("c", "")
            flags = body.get("flags") or ["-O2", "-G0"]
            try:
                result = build_and_diff(self.project, name, c_source, flags)
                self._send_json({"ok": True, "diff": result})
            except BuildError as e:
                self._send_json({"ok": False, "stage": e.stage, "message": e.message})
            except Exception as e:
                self._send_json({"ok": False, "stage": "internal", "message": str(e)})
            return
        if parsed.path == "/api/save":
            length = int(self.headers.get("Content-Length", 0))
            body = json.loads(self.rfile.read(length))
            name = body.get("name")
            c_source = body.get("c", "")
            try:
                self.project.save_function_c(name, c_source)
                self._send_json({"ok": True})
            except BuildError as e:
                self._send_json({"ok": False, "stage": e.stage, "message": e.message})
            except Exception as e:
                self._send_json({"ok": False, "stage": "internal", "message": str(e)})
            return
        self.send_response(404)
        self.end_headers()

    def _serve_static(self, filename, content_type):
        path = STATIC_DIR / filename
        if not path.exists():
            self.send_response(404)
            self.end_headers()
            return
        data = path.read_bytes()
        self.send_response(200)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--project", default=".", help="splat project root")
    ap.add_argument("--toolbin", default=DEFAULT_TOOLBIN, help="ee-gcc2953 etc bin folder")
    ap.add_argument("--gp", default=hex(DEFAULT_GP_VALUE), help="real _gp value, e.g. 0x1DC8B0")
    ap.add_argument("--port", type=int, default=DEFAULT_PORT)
    args = ap.parse_args()

    root = Path(args.project).resolve()
    toolbin = Path(args.toolbin)
    gp_value = int(args.gp, 16)

    project = Project(root, toolbin, gp_value)
    Handler.project = project

    server = http.server.ThreadingHTTPServer(("127.0.0.1", args.port), Handler)
    print(f"localdecomp running at http://127.0.0.1:{args.port}")
    print(f"project root: {root}")
    print(f"toolchain:    {toolbin}")
    print(f"gp value:     0x{gp_value:08X}")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
