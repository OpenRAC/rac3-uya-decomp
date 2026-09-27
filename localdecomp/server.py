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
# Git sync: auto-commit a function locally the moment it's saved with a
# perfect match (current_score == 0). Pushing is the separate Push button,
# gated on a passing full-project check (see run_full_check / run_push). Off entirely if --no-git-sync is passed, or
# if the project root isn't inside a git work tree.
# ---------------------------------------------------------------------------



def _typedefs_in(txt):
    res = []
    for m in re.finditer(r"^typedef\b", txt, re.M):
        i = m.start(); d = 0; j = i
        while j < len(txt):
            c = txt[j]
            if c == "{": d += 1
            elif c == "}": d -= 1
            elif c == ";" and d == 0: break
            j += 1
        body = txt[i:j + 1]
        nm = re.search(r"(\w+)\s*(?:\[[^\]]*\])?\s*;$", body)
        if nm:
            res.append((nm.group(1), body.rstrip()))
    return res


_EXTERN_VAR_RE = r"^extern[^\n(]*?\b(\w+)\s*(?:\[\])?\s*;[ \t\r]*$"


def _prelude_for(block, before):
    """Earlier typedefs and extern variable declarations `block` depends on."""
    have_t = set(n for n, _ in _typedefs_in(block))
    have_e = set(re.findall(_EXTERN_VAR_RE, block, re.M))
    earlier_t = _typedefs_in(before)
    earlier_e = {}
    for m in re.finditer(_EXTERN_VAR_RE, before, re.M):
        earlier_e[m.group(1)] = m.group(0).rstrip()
    need_t, need_e, scan = {}, {}, block
    while True:
        added = False
        for n, line in earlier_t:
            if n not in have_t and n not in need_t and re.search(r"\b%s\b" % n, scan):
                need_t[n] = line; scan += "\n" + line; added = True
        for n, line in earlier_e.items():
            if n not in have_e and n not in need_e and re.search(r"\b%s\b" % n, scan):
                need_e[n] = line; scan += "\n" + line; added = True
        if not added:
            break
    return [line for n, line in earlier_t if n in need_t] + list(need_e.values())


class GitSyncResult:
    def __init__(self, attempted, ok, message):
        self.attempted = attempted
        self.ok = ok
        self.message = message

    def to_json(self):
        return {"attempted": self.attempted, "ok": self.ok, "message": self.message}


def _saved_windows_path():
    """PATH as currently saved in the registry (system + user). A process only
    sees the PATH it was started with, so a server launched from a terminal
    opened before a PATH edit won't find newly added tools without this."""
    try:
        import winreg
    except ImportError:
        return ""
    parts = []
    for hive, key in ((winreg.HKEY_LOCAL_MACHINE, r"SYSTEM\CurrentControlSet\Control\Session Manager\Environment"),
                      (winreg.HKEY_CURRENT_USER, r"Environment")):
        try:
            with winreg.OpenKey(hive, key) as k:
                parts.append(os.path.expandvars(winreg.QueryValueEx(k, "Path")[0]))
        except OSError:
            pass
    return os.pathsep.join(parts)


def _find_tool(name, fallbacks=()):
    """Full path to an executable: this process's PATH, then the PATH saved in
    the registry, then known install locations (a folder fallback is searched
    for `name`, and for any single objdiff-cli*.exe in it)."""
    found = shutil.which(name) or shutil.which(name, path=_saved_windows_path() or None)
    if found:
        return found
    for f in fallbacks:
        f = Path(f)
        if f.is_file():
            return str(f)
        if f.is_dir():
            if (f / name).is_file():
                return str(f / name)
            exes = sorted(f.glob(Path(name).stem + "*.exe"))
            if len(exes) == 1:
                return str(exes[0])
    return None


GIT_EXE = _find_tool("git", [
    r"C:\Program Files\Git\cmd\git.exe",
    r"C:\Program Files\Git\bin\git.exe",
    r"C:\Program Files (x86)\Git\cmd\git.exe",
    os.path.expandvars(r"%LOCALAPPDATA%\Programs\Git\cmd\git.exe"),
])


def _run_git(root: Path, args, timeout=30):
    if GIT_EXE is None:
        raise FileNotFoundError("git not found on PATH or in C:\\Program Files\\Git -- install Git for Windows or add it to PATH")
    return subprocess.run(
        [GIT_EXE, *args],
        cwd=root,
        capture_output=True,
        text=True,
        timeout=timeout,
    )


def is_git_repo(root: Path) -> bool:
    try:
        proc = _run_git(root, ["rev-parse", "--is-inside-work-tree"], timeout=10)
        return proc.returncode == 0 and proc.stdout.strip() == "true"
    except Exception:
        return False


def git_commit_and_push(root: Path, func_name: str, paths) -> GitSyncResult:
    """
    Stage exactly the files this function's save touched -- never a blanket
    `git add -A`, which could sweep up unrelated in-progress work -- commit,
    and push. Never raises -- any failure is reported back in the result so
    a git problem shows up as a status message in the UI instead of a 500 on
    the save request.

    Only paths actually tracked (or trackable) by git are staged: anything
    under a gitignored path (e.g. .localdecomp_work/, this tool's own scratch
    state) is silently skipped rather than passed to `git add`, since a
    single ignored path in the list makes the whole `git add` call fail --
    which previously blocked committing src/text.c too, even though that
    file was never ignored.
    """
    try:
        # git (including check-ignore's own output) always speaks
        # forward-slash paths internally, even on Windows -- so every
        # relative path here is normalized to forward slashes for both the
        # check-ignore call and the comparison against its output. Comparing
        # a Windows backslash path against check-ignore's forward-slash
        # output would never match, silently treating an ignored path (e.g.
        # .localdecomp_work/...) as NOT ignored and letting it back into the
        # `git add` call that then fails on it.
        candidates = [p for p in paths if p.exists()]
        rel_of = {
            p: str(p.relative_to(root)).replace("\\", "/") for p in candidates
        }

        ignored = set()
        if candidates:
            check = _run_git(
                root,
                ["check-ignore", "--no-index", *rel_of.values()],
            )
            # check-ignore prints the paths that ARE ignored, one per line,
            # and exits 0 if it found at least one -- exit 1 (no matches) is
            # not an error here, just "nothing ignored".
            if check.returncode in (0, 1):
                ignored = set(check.stdout.splitlines())

        rel_paths = [rel_of[p] for p in candidates if rel_of[p] not in ignored]
        if not rel_paths:
            return GitSyncResult(True, False, "nothing to stage")

        add = _run_git(root, ["add", "--", *rel_paths])
        if add.returncode != 0:
            return GitSyncResult(True, False, f"git add failed: {add.stderr.strip()}")

        diff = _run_git(root, ["diff", "--cached", "--quiet"])
        if diff.returncode == 0:
            # Nothing actually changed (e.g. re-saving an already-committed
            # perfect match) -- not an error, just nothing to do.
            return GitSyncResult(True, True, "no changes to commit")

        commit = _run_git(
            root, ["commit", "-m", f"localdecomp: match {func_name}"]
        )
        if commit.returncode != 0:
            return GitSyncResult(
                True, False, f"git commit failed: {commit.stderr.strip()}"
            )

        # No push here: pushing is the separate Push button, which only
        # unlocks after a full-project check (/api/check) passes on exactly
        # the commits being pushed.
        return GitSyncResult(True, True, f"committed {func_name} locally (not pushed)")
    except Exception as e:
        return GitSyncResult(True, False, f"git sync error: {e}")

# ---------------------------------------------------------------------------
# Project model: discover functions from splat's asm/nonmatchings output.
# ---------------------------------------------------------------------------


class Project:
    def __init__(self, root: Path, toolbin: Path, gp_value: int, git_sync: bool = True,
                 refs_dir: str = r"C:\decomp-refs", objdiff_cli: str = "objdiff-cli.exe"):
        self.root = root
        self.refs_dir = refs_dir
        self.objdiff_cli = objdiff_cli
        self.check_state = None  # result of the last /api/check, gates /api/push
        self.toolbin = toolbin
        self.gp_value = gp_value
        self.target_elf = root / "frontbin.elf"
        self.asm_dir = root / "asm" / "nonmatchings"
        self.src_file = root / "src" / "text.c"
        self.work_dir = root / ".localdecomp_work"
        self.work_dir.mkdir(exist_ok=True)
        self.symbol_addrs_path = root / "symbol_addrs.txt"
        self.git_sync = git_sync and is_git_repo(root)
        if git_sync and not self.git_sync:
            sys.stderr.write(
                f"[localdecomp] --git-sync requested but {root} is not a git "
                f"work tree -- auto-commit/push disabled.\n"
            )
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

    def flags_for(self, name: str):
        """Compiler flags for a function, from tools/text_parts.txt.

        text.c is built in address ranges with per-range flags (see
        tools/build_text.py). Each line of text_parts.txt is
        `<start address> <flags...>` and applies up to the next line's start.
        localdecomp uses the same table so a function is always test-built
        with the flags its range really uses."""
        default = ["-O2", "-G8"]
        m = re.search(r"func_([0-9A-Fa-f]{8})", name or "")
        path = self.root / "tools" / "text_parts.txt"
        if not m or not path.exists():
            return default
        addr = int(m.group(1), 16)
        # Work-in-progress overrides for functions still INCLUDE_ASM in text.c
        # (text_parts.txt can't carry @ps2as for them: the asm needs macro.inc).
        # tools/localdecomp_flags.txt lines: `func_XXXXXXXX <flags...>`
        ov = self.root / "tools" / "localdecomp_flags.txt"
        if ov.exists():
            for line in ov.read_text().splitlines():
                fields = line.split("#", 1)[0].split()
                if len(fields) >= 2 and fields[0].lower() == ("func_%08x" % addr):
                    return fields[1:]
        best = None
        for line in path.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            fields = line.split()
            start = int(fields[0], 16)
            if addr >= start and (best is None or start >= best[0]):
                best = (start, fields[1:])
        return best[1] if best else default

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
        # Functions whose .s now lives in asm/handwritten or asm/remnants are
        # listed from there (below). A stale copy left in asm/nonmatchings
        # would otherwise show up a second time, as "unverified".
        asm_sources = {
            p.stem
            for sub in ("handwritten", "remnants")
            for p in (self.root / "asm" / sub).glob("*.s")
        }

        for s_path in sorted(self.asm_dir.rglob("*.s")):
            if s_path.stem in asm_sources:
                continue
            content = s_path.read_text()
            m_name = re.search(r"^glabel\s+(\S+)", content, re.MULTILINE)
            if not m_name:
                # splat disassembles a few functions (COP0 code, the last one)
                # as data; list them only when text.c includes them as code.
                m_name = re.search(r"^dlabel\s+(func_[0-9A-Fa-f]{8})\b", content, re.MULTILINE)
                if m_name and not re.search(
                        rf'INCLUDE_ASM\([^)]*,\s*{m_name.group(1)}\s*\)', text_c):
                    m_name = None
            m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", content)
            m_addr = re.search(
                r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", content
            )
            if not (m_name and m_addr):
                continue
            name = m_name.group(1)
            vaddr = _func_vaddr(name, content)
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

        # Assembly that is final source rather than a matching target
        # (tools/migrate_asm_sources.py): hand-written functions and the
        # leftovers of functions the original linker stripped. They count as
        # done, the same way the objdiff base build counts them.
        for kind, sub in (("handwritten", "handwritten"), ("remnant", "remnants")):
            for s_path in sorted((self.root / "asm" / sub).glob("*.s")):
                content = s_path.read_text()
                m_name = re.search(r"^(?:glabel|dlabel)\s+(\S+)", content, re.MULTILINE)
                m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", content)
                if not m_name:
                    continue
                name = m_name.group(1)
                funcs.append({
                    "name": name,
                    "vaddr": _func_vaddr(name, content),
                    "size": int(m_size.group(1), 16) if m_size else None,
                    "asm_path": str(s_path.relative_to(self.root)),
                    "match_status": "perfect",
                    "kind": kind,
                    "current_score": 0,
                    "max_score": None,
                })

        funcs.sort(key=lambda f: f["vaddr"] or 0)
        return funcs

    def get_function_asm(self, name: str) -> str:
        paths = []
        for sub in ("handwritten", "remnants"):
            paths += list((self.root / "asm" / sub).glob("*.s"))
        paths += list(self.asm_dir.rglob("*.s"))
        for s_path in paths:
            content = s_path.read_text()
            if re.search(rf"^(?:glabel|dlabel)\s+{re.escape(name)}\b", content, re.MULTILINE):
                return content
        raise KeyError(name)

    def _func_store_path(self, name: str) -> Path:
        return self.funcs_dir / f"{name}.c"

    def _extract_marked_block(self, name: str):
        """
        Pull a function's body straight out of src/text.c by its
        localdecomp:start/end markers, if present. Returns None if there's
        no marker pair for this function (still an INCLUDE_ASM stub, or was
        never saved through this tool). This is the recovery path for when
        funcs/<name>.c is missing but the real code already lives in
        src/text.c -- e.g. the .localdecomp_work cache was deleted, never
        existed for an older save, or drifted from src/text.c some other
        way. Without this, get_function_c would silently hand back a blank
        `// TODO` template for a function that's actually already written.
        """
        if not self.src_file.exists():
            return None
        text_c = self.src_file.read_text()
        start_marker = f"/* localdecomp:start {name} */"
        end_marker = f"/* localdecomp:end {name} */"
        if start_marker not in text_c or end_marker not in text_c:
            return None
        start = text_c.index(start_marker) + len(start_marker)
        end = text_c.index(end_marker)
        if end < start:
            return None
        block = text_c[start:end].strip("\n") + "\n"
        # text.c declares each typedef once (a repeat is a compile error) and
        # some blocks rely on externs/typedefs written in earlier blocks.
        # Prepend whatever earlier declarations this block needs, repeating
        # until nothing new is pulled in, so the block compiles on its own.
        extra = _prelude_for(block, text_c[:start].replace("\r\n", "\n"))
        if extra:
            block = "\n".join(extra) + "\n" + block
        return block

    def _block_in(self, name: str, cached: str) -> bool:
        """True if the text.c block for `name` appears (whitespace-insensitive)
        in `cached`."""
        text_c = self.src_file.read_text() if self.src_file.exists() else ""
        a = text_c.find(f"/* localdecomp:start {name} */")
        b = text_c.find(f"/* localdecomp:end {name} */")
        if a < 0 or b < a:
            return True
        block = text_c[a + len(f"/* localdecomp:start {name} */"):b]
        norm = lambda t: re.sub(r"\s+", " ", t).strip()
        return norm(block) in norm(cached)

    def get_function_c(self, name: str) -> str:
        """
        Return the FULL editor content (externs + body together) last saved
        for this function, if any; otherwise a starter template.

        Preferred source is this tool's own store (funcs/<name>.c), since
        that's the one place externs/helpers are guaranteed intact. But if
        that cache entry is missing -- lost, cleared, or never written by an
        older version of this tool -- and src/text.c already has a marked
        block for this function (proof real work was saved at some point),
        recover the body from there instead of showing a blank template,
        and re-populate the cache so this recovery only has to happen once.
        """
        store_path = self._func_store_path(name)
        recovered = self._extract_marked_block(name)
        if store_path.exists():
            cached = store_path.read_text()
            # src/text.c is the source of truth once a function is saved there.
            # If its block was changed outside this tool (a merge, a fix-up
            # script, a hand edit), the cached editor copy is stale; building
            # or saving it would put the old version back into text.c.
            if recovered is None or self._block_in(name, cached):
                return cached
            store_path.write_text(recovered)
            return recovered

        if recovered is not None:
            store_path.write_text(recovered)
            return recovered

        # Final assembly (ASM_FUNC / LINKER_REMNANT in src/text.c) has no C
        # to write. Say so instead of offering a blank TODO template.
        text_c = self.src_file.read_text() if self.src_file.exists() else ""
        m_src = re.search(
            rf'^(ASM_FUNC|LINKER_REMNANT)\("([^"]+)",\s*{re.escape(name)}\s*\);',
            text_c, re.MULTILINE)
        if m_src:
            macro, folder = m_src.group(1), m_src.group(2)
            if macro == "LINKER_REMNANT":
                why = ("the leftover last instruction (plus alignment nop) of a function\n"
                       " * the original linker stripped as unused. It is not source code.")
            else:
                why = ("hand-written assembly in the original game, so its .s file\n"
                       " * is the source.")
            return (f"/* {name} is done: it is {why}\n"
                    f" *\n * Built from {folder}/{name}.s via {macro}(...) in src/text.c.\n"
                    f" * Nothing to decompile here. */\n")

        return f"s32 {name}(void) {{\n    // TODO\n}}\n"

    def save_function_c(self, name: str, c_source: str):
        """
        Persist the full editor content for `name` in this tool's own store
        (funcs/<name>.c), AND write it into the real project's src/text.c so
        the full-project build/splat workflow picks it up too -- replacing
        either the INCLUDE_ASM(...) stub (first save) or a previously-saved
        body for this function (subsequent saves).
        """
        if self.src_file.exists() and re.search(
                rf'^(?:ASM_FUNC|LINKER_REMNANT)\([^)]*,\s*{re.escape(name)}\s*\);',
                self.src_file.read_text(), re.MULTILINE):
            raise BuildError("save", f"{name} is final assembly (ASM_FUNC / LINKER_REMNANT); "
                             "there is no C to save for it")
        self._func_store_path(name).write_text(c_source)

        if not self.src_file.exists():
            raise BuildError("save", f"{self.src_file} does not exist")
        text_c = self.src_file.read_text()
        body = c_source.strip() + "\n"
        # The editor copy may carry typedefs that were prepended from earlier
        # blocks (see _prelude_for). text.c may only define each typedef once,
        # so drop any that already appear before this function's position.
        pos = text_c.find(f"/* localdecomp:start {name} */")
        if pos < 0:
            m_inc = re.search(r'INCLUDE_ASM\([^)]*\b%s\)' % re.escape(name), text_c)
            pos = m_inc.start() if m_inc else len(text_c)
        before = text_c[:pos].replace("\r\n", "\n")
        body = body.replace("\r\n", "\n")
        before_t = set(" ".join(line.split()) for _, line in _typedefs_in(before))
        for _, line in _typedefs_in(body):
            if " ".join(line.split()) in before_t:
                body = body.replace(line + "\n", "", 1)

        start_marker = f"/* localdecomp:start {name} */"
        end_marker = f"/* localdecomp:end {name} */"

        # The stub plus any INCLUDE_RODATA lines right after it (the asm
        # function's jump tables, see tools/migrate_jtbls.py): once the
        # function is C, gcc emits its own table in the same place.
        include_pat = re.compile(
            rf'INCLUDE_ASM\([^)]*,\s*{re.escape(name)}\s*\)\s*;'
            r'(?:[ \t]*\r?\n[ \t]*INCLUDE_RODATA\([^)]*\)\s*;)*'
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

    def sync_function_to_git(self, name: str) -> "GitSyncResult":
        """
        Auto-commit + push this function's change, gated on git_sync being
        enabled and the last known score for `name` being a perfect match
        (current_score == 0). Called after save_function_c, never before --
        it stages whatever save_function_c just wrote.
        """
        if not self.git_sync:
            return GitSyncResult(False, True, "git sync disabled")

        entry = self.load_status().get(name)
        if not entry or entry.get("current_score") != 0:
            return GitSyncResult(False, True, "not a perfect match yet")

        paths = [self.src_file, self._func_store_path(name)]
        return git_commit_and_push(self.root, name, paths)

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


def _text_c_context(project, func_name, c_source):
    """The declarations the full build compiles in front of this function
    (tools/build_text.py function_context): earlier #defines, prototypes,
    typedefs, extern declarations and the part's .extern hints. Without them a
    function could score 0 here and still differ, or fail to compile, in the
    real build. Returns (context, source) with the editor content's typedefs
    that the context already defines identically removed from the source, as
    the full build would; common.h is left out (localdecomp_common.h stands in
    for it)."""
    import importlib.util
    try:
        spec = importlib.util.spec_from_file_location(
            "build_text", str(project.root / "tools" / "build_text.py"))
        bt = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(bt)
        text = project.src_file.read_text(errors="replace").replace("\r\n", "\n")
        parts = bt.read_parts(str(project.root / "tools" / "text_parts.txt"))
        ctx = bt.function_context(text, parts, func_name)
        c_source = bt.drop_repeated_typedefs(ctx, c_source)
    except Exception as e:  # never block a build on this
        return f"/* text.c context unavailable: {e} */\n", c_source
    ctx = "\n".join(l for l in ctx.split("\n")
                    if not re.match(r'\s*#\s*include\s+"(common|include_asm)\.h"', l))
    return "/* ---- src/text.c context (declarations only) ---- */\n" + ctx + "\n/* ---- function ---- */\n", c_source


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
    extra_cflags = extra_cflags or project.flags_for(func_name)

    asm_text = project.get_function_asm(func_name)
    m_addr = re.search(
        r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", asm_text
    )
    m_size = re.search(r"nonmatching\s+\S+,\s*(0x[0-9A-Fa-f]+)", asm_text)
    if not (m_addr and m_size):
        raise BuildError("setup", f"Could not parse address/size for {func_name}")
    vaddr = _func_vaddr(func_name, asm_text)
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
    # With a real -G value the compiler places small globals in .sdata/.sbss
    # itself and emits genuine $gp-relative accesses (the project builds with
    # -G8 since the compiler/flag matrix, see compiler_matrix_findings.md), so
    # the register-variable emulation below is only needed for -G0 builds.
    if any(re.fullmatch(r"-G[1-9]\d*", f) for f in extra_cflags):
        gp_rel_syms = []

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
    context, filtered_c_source = _text_c_context(project, func_name, filtered_c_source)
    full_c = (
        f'#include "{common_h.name}"\n\n'
        + context
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

    # A C switch puts its jump table in .rodata. Place it where retail has
    # this function's table, so the lui/addiu of the table address match too.
    jtbls = sorted(int(a, 16) for a in re.findall(r"jtbl_([0-9A-Fa-f]{8})", asm_text))
    rodata_block = (f"    .rodata 0x{jtbls[0]:08X} : {{ *(.rodata) }}\n" if jtbls else "")

    ld_path.write_text(
        f"""/* auto-generated by localdecomp for {func_name} */
{provides_block}

SECTIONS
{{
    . = 0x{vaddr:08X};
    .text : {{ *(.text) }}
{rodata_block}
    _gp = 0x{project.gp_value:08X};
    /* Float constants the default assembler puts in .lit4/.lit8 are loaded
       $gp-relative; keep them in $gp range so the link works. (Retail builds
       most float constants inline with lui/ori/mtc1, which needs @ps2as.) */
    .lit 0x{project.gp_value - 0x7FF0:08X} : {{ *(.lit4) *(.lit8) *(.sdata) *(.sbss) *(.scommon) }}

    /DISCARD/ : {{ *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) }}
}}
"""
    )

    gcc = project.toolbin / "ee-gcc2953.exe"
    ld = project.toolbin / "ee-ld.exe"
    objcopy = project.toolbin / "ee-objcopy.exe"

    # --- compile ---
    # Use the older bin/ee-as.exe (Aug 2000) as the assembler: retail needs its
    # mtc1 hazard nops. See docs/compiler_matrix_findings.md.
    # text_parts.txt pseudo-flags: @ps2as / @newas pick another assembler for
    # that range (see tools/build_text.py). gcc uses the last -B, so these
    # come after the default one.
    tool_root = project.toolbin.parent
    as_flags = {"@ps2as": "-B" + str(tool_root / "ee" / "bin" / "Ps2Ee"),
                "@newas": "-B" + str(tool_root / "ee" / "bin") + "\\"}
    if "@ps2as" in extra_cflags and "-DNO_MACRO_INC" not in extra_cflags:
        extra_cflags = list(extra_cflags) + ["-DNO_MACRO_INC"]
        extra_cflags = [f for f in extra_cflags if not f.startswith("-Wa,")]
    extra_cflags = [as_flags.get(f, f) for f in extra_cflags]
    # compile to assembly, apply retail's loop padding (tools/asm_filter.py,
    # same as the full build), then assemble
    s_path = o_path.with_suffix(".s")
    base = [str(gcc), "-B" + str(project.toolbin / "ee-")] + extra_cflags
    cmd = base[:1] + ["-S"] + base[1:] + ["-o", str(s_path), str(c_path)]
    proc = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    if proc.returncode != 0:
        raise BuildError("compile", proc.stdout + proc.stderr)
    try:
        import importlib.util
        spec = importlib.util.spec_from_file_location(
            "asm_filter", str(project.root / "tools" / "asm_filter.py"))
        af = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(af)
        s_text = s_path.read_text()
        s_path.write_text(af.filter_asm(s_text))
    except FileNotFoundError:
        pass
    cmd = base[:1] + ["-c"] + base[1:] + ["-o", str(o_path), str(s_path)]
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
    # Only .text counts. Anything else the linker kept (a switch's jump table
    # in .rodata) would otherwise be dumped after the code and diffed as
    # extra instructions.
    source_raw = _elf_section_bytes(elf_path, ".text") or source_bin.read_bytes()
    source_bin.write_bytes(source_raw)
    # Trim ONLY trailing zero words (`.align` padding). Real instructions past
    # the target size are a genuine difference and must stay in the diff: gcc
    # always ends a function with `j $31` + nop, so trimming them scored a
    # one-instruction "function" whose whole body was an inline-asm statement
    # as a perfect match, while in the full build it shifts everything after it.
    if size < len(source_raw) <= size + ALIGN_SLOP and not any(source_raw[size:]):
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
    # -B + removing __pycache__: diff_settings.py is rewritten every build, and a
    # cached .pyc with the same size and whole-second mtime would otherwise be
    # reused, returning the PREVIOUS function's diff.
    shutil.rmtree(work / "__pycache__", ignore_errors=True)
    cmd = [sys.executable, "-B", "-m", "diff", "0", "--no-pager", "--format=json"]
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


def _func_vaddr(name: str, asm_text: str):
    """A function's address. Taken from its name (func_XXXXXXXX), not from
    the first `/* ROM VADDR WORD */` comment: functions that start with a raw
    `.word` (tools/fix_quadword_ops.py writes lqc2/sqc2/ld/sd that way) have
    no such comment on their first instructions, and the first comment found
    would be a few instructions in, so the target bytes were sliced too late
    (seen on func_00388698: a byte-identical build scored 56%)."""
    m = re.fullmatch(r"func_([0-9A-Fa-f]{8})", name or "")
    if m:
        return int(m.group(1), 16)
    m = re.search(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/", asm_text)
    return int(m.group(1), 16) if m else None


def _elf_section_bytes(elf_path: Path, section: str) -> bytes:
    """Contents of one section of a little-endian ELF32 file (stdlib only;
    this old SN objcopy has no -j/--only-section)."""
    import struct
    data = elf_path.read_bytes()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    def sh(i):
        return struct.unpack_from("<IIIIIIIIII", data, shoff + i * shentsize)
    strtab = sh(shstrndx)
    for i in range(shnum):
        name, typ, flags, addr, off, size = sh(i)[:6]
        end = data.index(b"\0", strtab[4] + name)
        if data[strtab[4] + name:end].decode() == section:
            return data[off:off + size] if typ != 8 else b""
    return b""


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
# Full-project check + gated push.
#
# /api/check reproduces the CI job locally: copy the retail reference objects
# in, run `make objdiff` (full build + byte-for-byte MATCH check), generate
# the full objdiff report over every unit, and compare it with the report
# saved at the last successful push. /api/push only runs `git push` if that
# check passed on the exact HEAD being pushed with no uncommitted changes to
# build inputs, then makes that report the new baseline.
# ---------------------------------------------------------------------------

DEFAULT_REFS_DIR = r"C:\decomp-refs"
DEFAULT_OBJDIFF_CLI = "objdiff-cli.exe"
# Tracked paths whose uncommitted edits would make "what was checked" differ
# from "what gets pushed".
BUILD_INPUTS = ["src", "include", "asm", "linker_scripts", "Makefile",
                "objdiff.json", "symbol_addrs.txt", "undefined_syms_auto.txt",
                "undefined_funcs_auto.txt", "symbol_addrs_resolved.txt",
                "reloc_addrs.txt", "tools"]

_check_lock = threading.Lock()


def _git_out(root, args, timeout=30):
    p = _run_git(root, args, timeout=timeout)
    return p.stdout.strip() if p.returncode == 0 else None


def _dirty_build_inputs(root):
    out = _run_git(root, ["status", "--porcelain", "--untracked-files=no", "--", *BUILD_INPUTS])
    return [l[3:] for l in out.stdout.splitlines() if l.strip()] if out.returncode == 0 else ["(git status failed)"]


def _matched_by_unit(report):
    """{unit name: set of function names at 100%} plus overall measures."""
    units = {}
    for u in report.get("units", []):
        units[u.get("name")] = {
            f.get("name") for f in u.get("functions", [])
            if float(f.get("fuzzy_match_percent", 0) or 0) == 100.0
        }
    return units


def _summary(report):
    m = report.get("measures", {})
    return {
        "matched_functions": int(m.get("matched_functions", 0) or 0),
        "total_functions": int(m.get("total_functions", 0) or 0),
        "matched_code": int(m.get("matched_code", 0) or 0),
        "total_code": int(m.get("total_code", 0) or 0),
        "matched_code_percent": float(m.get("matched_code_percent", 0) or 0),
        "matched_data_percent": float(m.get("matched_data_percent", 0) or 0),
    }


def run_full_check(project):
    root = project.root
    refs = Path(project.refs_dir)
    work = project.work_dir
    result = {"ok": False, "steps": []}

    def step(name, ok, detail=""):
        result["steps"].append({"name": name, "ok": ok, "detail": detail})
        return ok

    make = project.toolbin / "make.exe"
    objdiff = _find_tool(project.objdiff_cli, [Path(r"C:\tools\objdiff-cli"), Path(r"C:\tools")])
    missing = []
    if GIT_EXE is None:
        missing.append("git (not on PATH or in C:\\Program Files\\Git)")
    if not make.exists():
        missing.append(f"make.exe (expected at {make})")
    if objdiff is None:
        missing.append(f"{project.objdiff_cli} (not on PATH, the saved Windows PATH, C:\\tools\\objdiff-cli or C:\\tools)")
    if missing:
        step("find tools", False, "missing: " + "; ".join(missing))
        return result
    step("find tools", True, f"git={GIT_EXE}; objdiff={objdiff}")

    head = _git_out(root, ["rev-parse", "HEAD"])
    result["head"] = head
    result["dirty"] = _dirty_build_inputs(root)
    result["unpushed"] = (_git_out(root, ["log", "--oneline", "@{u}..HEAD"]) or "").splitlines()

    # 1. retail reference objects (copyrighted, live outside git, same as CI)
    try:
        lv = root / "build" / "objdiff" / "target" / "levels"
        lv.mkdir(parents=True, exist_ok=True)
        n = 0
        for f in (refs / "level-targets").glob("*.o"):
            shutil.copy2(f, lv / f.name); n += 1
        shutil.copy2(refs / "frontbin_data.o", root / "build" / "objdiff" / "target" / "frontbin_data.o")
        if not step("copy reference objects", n == 51, f"{n} level objects + frontbin_data.o from {refs}"):
            return result
    except Exception as e:
        step("copy reference objects", False, str(e)); return result

    # 2. full build + MATCH (make objdiff depends on the check target)
    p = subprocess.run([str(make), "objdiff"], cwd=root, capture_output=True, text=True, timeout=900)
    log = (p.stdout + p.stderr).strip()
    match_line = next((l for l in log.splitlines() if l.startswith(("MATCH", "NO MATCH"))), "")
    result["build_log_tail"] = "\n".join(log.splitlines()[-25:])
    if not step("full build + MATCH", p.returncode == 0 and match_line.startswith("MATCH"),
                match_line or f"make exited {p.returncode}"):
        return result

    # 3. full objdiff report over every unit
    cur_path = work / "report_check.json"
    p = subprocess.run([objdiff, "report", "generate", "-o", str(cur_path)],
                       cwd=root, capture_output=True, text=True, timeout=900)
    if not step("objdiff report", p.returncode == 0, (p.stdout + p.stderr).strip()[-600:]):
        return result
    cur = json.loads(cur_path.read_text(encoding="utf-8"))
    result["current"] = _summary(cur)

    # 4. compare with the report saved at the last successful push
    base_path = work / "report_pushed.json"
    if base_path.exists():
        base = json.loads(base_path.read_text(encoding="utf-8"))
        result["baseline"] = _summary(base)
        bu, cu = _matched_by_unit(base), _matched_by_unit(cur)
        gained, lost = [], []
        for unit in sorted(set(bu) | set(cu)):
            b, c = bu.get(unit, set()), cu.get(unit, set())
            gained += [f"{unit}: {f}" for f in sorted(c - b)]
            lost += [f"{unit}: {f}" for f in sorted(b - c)]
        result["newly_matched"], result["lost"] = gained, lost
        step("compare with last push", not lost,
             f"+{len(gained)} matched, -{len(lost)} lost" if lost else f"+{len(gained)} matched, none lost")
    else:
        result["baseline"] = None
        result["newly_matched"], result["lost"] = [], []
        step("compare with last push", True, "no baseline yet: this check becomes the baseline after the first push")

    result["ok"] = all(s["ok"] for s in result["steps"])
    return result


def run_push(project):
    root = project.root
    st = project.check_state
    head = _git_out(root, ["rev-parse", "HEAD"])
    if not st or not st.get("ok"):
        return {"ok": False, "message": "Run a full check first; the last check did not pass."}
    if st.get("head") != head:
        return {"ok": False, "message": "HEAD changed since the last check (new commit). Run the check again."}
    dirty = _dirty_build_inputs(root)
    if dirty:
        return {"ok": False, "message": "Uncommitted changes to build inputs, so the check didn't test what would be pushed: " + ", ".join(dirty)}
    p = _run_git(root, ["push"], timeout=120)
    if p.returncode != 0:
        return {"ok": False, "message": "git push failed: " + (p.stderr or p.stdout).strip()}
    shutil.copy2(project.work_dir / "report_check.json", project.work_dir / "report_pushed.json")
    project.check_state = None  # a new push needs a new check
    return {"ok": True, "message": ((p.stderr or "") + (p.stdout or "")).strip() or "pushed"}


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
        if parsed.path == "/api/check_state":
            self._send_json({"state": self.project.check_state})
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
            flags = body.get("flags") or self.project.flags_for(name)
            try:
                result = build_and_diff(self.project, name, c_source, flags)
                self._send_json({"ok": True, "diff": result})
            except BuildError as e:
                self._send_json({"ok": False, "stage": e.stage, "message": e.message})
            except Exception as e:
                self._send_json({"ok": False, "stage": "internal", "message": str(e)})
            return
        if parsed.path == "/api/check":
            if not _check_lock.acquire(blocking=False):
                self._send_json({"ok": False, "steps": [{"name": "check", "ok": False, "detail": "a check or push is already running"}]})
                return
            try:
                res = run_full_check(self.project)
                self.project.check_state = res
                self._send_json(res)
            except Exception as e:
                self._send_json({"ok": False, "steps": [{"name": "internal", "ok": False, "detail": str(e)}]})
            finally:
                _check_lock.release()
            return
        if parsed.path == "/api/push":
            if not _check_lock.acquire(blocking=False):
                self._send_json({"ok": False, "message": "a check or push is already running"})
                return
            try:
                self._send_json(run_push(self.project))
            except Exception as e:
                self._send_json({"ok": False, "message": str(e)})
            finally:
                _check_lock.release()
            return
        if parsed.path == "/api/save":
            length = int(self.headers.get("Content-Length", 0))
            body = json.loads(self.rfile.read(length))
            name = body.get("name")
            c_source = body.get("c", "")
            try:
                # Only perfect matches go into src/text.c: a non-matching body
                # there breaks the full build for everyone. Keep work in
                # progress in the editor (it is cached) instead.
                if not body.get("force"):
                    diff = build_and_diff(self.project, name, c_source)
                    score = diff.get("current_score") if isinstance(diff, dict) else None
                    if score != 0:
                        raise BuildError("save", f"{name} does not match yet (score {score}); "
                                         "only perfect matches are saved into src/text.c, "
                                         "because anything else breaks the full build. "
                                         "Your code is kept in the editor.")
                self.project.save_function_c(name, c_source)
                git_result = self.project.sync_function_to_git(name)
                self._send_json({"ok": True, "git": git_result.to_json()})
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
    ap.add_argument(
        "--no-git-sync",
        action="store_false",
        dest="git_sync",
        default=True,
        help="disable auto-commit+push of perfect-match functions to git "
        "(on by default; auto-disables anyway if --project isn't a git repo)",
    )
    ap.add_argument("--refs", default=DEFAULT_REFS_DIR,
                    help="folder holding level-targets\\*.o and frontbin_data.o (same as CI)")
    ap.add_argument("--objdiff-cli", default=DEFAULT_OBJDIFF_CLI, help="objdiff-cli executable")
    args = ap.parse_args()

    root = Path(args.project).resolve()
    toolbin = Path(args.toolbin)
    gp_value = int(args.gp, 16)

    project = Project(root, toolbin, gp_value, git_sync=args.git_sync,
                      refs_dir=args.refs, objdiff_cli=args.objdiff_cli)
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
