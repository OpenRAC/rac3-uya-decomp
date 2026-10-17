"""The shared level code (levels/common) as a localdecomp target.

The common code of the 51 level overlays isn't a splatted executable: each
function is a standalone source in src/levels/common/, catalogued in
tools/common_c.json, and verified by tools/build_common_c.py's gates against
its canonical owner overlay (docs/common_level_c.md). This class gives the
server the same interface as server.Project (list, asm, C, build, save) on top
of those tools:

  * functions: every canonical owner (tools/try_level.py's cached ownership
    table); matched = in the catalogue
  * build: compile with a compiler profile (mode N/S, assembler default/ps2as,
    flags from a frontbin function's range), resolve relocations, and diff
    against the owner overlay's retail bytes with asm-differ, like the other
    targets. At a 0 score the real gates run as well, so 100% here means the
    function would count in the report.
  * save: only a build that passes the gates is written to src/levels/common/
    and added to (or updated in) the catalogue; both files are committed.
"""
import contextlib
import io
import json
import os
import re
import sys
import threading
from pathlib import Path
from types import SimpleNamespace

NAME = "levels_common"
LABEL = "levels/common (shared level code)"
DEFAULT_FLAGS_FROM = "func_003ABC30"  # a plain frontbin range; mode/assembler pick the profile
PROFILES = [("N", "default"), ("S", "default"), ("S", "ps2as"), ("N", "ps2as")]
GP = 0x1DC8B0
_lock = threading.RLock()


def _write_like(path, text):
    """Write text with the line endings the file already has (git's autocrlf
    checks files out with CRLF), LF for a new file."""
    nl = "\r\n" if path.exists() and b"\r\n" in path.read_bytes()[:4096] else "\n"
    path.write_text(text.replace("\r\n", "\n"), encoding="utf-8", newline=nl)


class LevelProject:
    def __init__(self, root: Path, toolbin: Path, refs_dir, git_sync, build_error, differ, git_commit, run_git, target_lock):
        self.root = root
        self.name = NAME
        self.label = LABEL
        self.toolbin = toolbin
        self.refs = Path(refs_dir)
        self.gp_value = GP
        self.check_state = None
        self.BuildError = build_error
        self._differ = differ
        self._git_commit = git_commit
        self._run_git = run_git
        self._target_lock = target_lock
        self.git_sync = git_sync
        self.src_dir = root / "src" / "levels" / "common"
        self.catalogue_path = root / "tools" / "common_c.json"
        self.work_dir = root / ".localdecomp_work" / NAME
        (self.work_dir / "src").mkdir(parents=True, exist_ok=True)
        self.status_path = self.work_dir / "status.json"
        self.target_elf = self.refs / "level-targets-split" / "common.o"
        needed = [self.refs / "levels", self.refs / "level-targets", self.target_elf]
        missing = [str(p) for p in needed if not p.exists()]
        if missing:
            raise FileNotFoundError("not found: " + ", ".join(missing))
        tools = str(root / "tools")
        if tools not in sys.path:
            sys.path.insert(0, tools)
        self._owners = None
        self._overlay_text = {}

    # -- environment -------------------------------------------------------

    def active(self):
        """The level sources compile with frontbin's tools and tables
        (flags_from names a frontbin function), so UYA_TARGET is frontbin."""
        lock = self._target_lock

        class _Active:
            def __enter__(self):
                lock.acquire()
                self.old = os.environ.get("UYA_TARGET")
                os.environ["UYA_TARGET"] = "frontbin"

            def __exit__(self, *exc):
                if self.old is None:
                    os.environ.pop("UYA_TARGET", None)
                else:
                    os.environ["UYA_TARGET"] = self.old
                lock.release()
        return _Active()

    def _tools(self):
        import try_func, build_common_c, try_level  # noqa: E401 (tools/, on sys.path)
        return try_func, build_common_c, try_level

    def owners(self):
        """{name: [(overlay, size), ...]} for every canonical owner (a few
        names own different functions in two levels; level order), plus the
        raw (identity -> owner) table and split common bodies the gates need."""
        with _lock:
            if self._owners is None:
                _, _, tl = self._tools()
                owners, common = tl.load_refs(self.refs)
                dirs = {p.parent.name: p.parent.relative_to(self.refs / "levels").as_posix()
                        for p in (self.refs / "levels").glob("*/*/overlay.elf")}
                by_name = {}
                for lv, n, off, sz in owners.values():
                    by_name.setdefault(n, []).append((dirs[Path(lv.path).stem], sz))
                level_no = lambda o: int(re.match(r"(\d+)_", o[0].split("/")[-1]).group(1))
                for v in by_name.values():
                    v.sort(key=level_no)
                self._owners = (by_name, owners, common)
            return self._owners

    def catalogue(self):
        try:
            return json.loads(self.catalogue_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return []

    def load_status(self):
        try:
            return json.loads(self.status_path.read_text())
        except (OSError, json.JSONDecodeError):
            return {}

    def save_status_entry(self, name, current_score, max_score):
        st = self.load_status()
        st[name] = {"current_score": current_score, "max_score": max_score}
        self.status_path.write_text(json.dumps(st, indent=2))

    # -- function list -----------------------------------------------------

    def list_functions(self):
        by_name, _, _ = self.owners()
        done = {e["name"] for e in self.catalogue()}
        status = self.load_status()
        files = {p.stem for p in self.src_dir.glob("func_*.c")}
        out = []
        cat_overlay = {e["name"]: e["overlay"] for e in self.catalogue()}
        for name, choices in by_name.items():
            overlay, size = next((c for c in choices if c[0] == cat_overlay.get(name)), choices[0])
            entry = status.get(name)
            if name in done:
                ms = "perfect"
            elif entry is not None:
                ms = "partial"
            elif name in files:
                ms = "unverified"   # a source exists but isn't catalogued yet
            else:
                ms = "none"
            out.append({"name": name, "vaddr": int(name[5:], 16), "size": size, "overlay": overlay,
                        "asm_path": overlay + "/overlay.elf", "match_status": ms,
                        # its last build passed the gates, but it was never saved
                        "unsaved": ms == "partial" and (entry or {}).get("current_score") == 0,
                        "current_score": 0 if name in done else (entry or {}).get("current_score"),
                        "max_score": (entry or {}).get("max_score")})
        out.sort(key=lambda f: f["vaddr"])
        return out

    def _choices(self, name):
        """The owners a build compares against: the catalogue's overlay for a
        catalogued function, else every overlay that owns this name."""
        by_name, _, _ = self.owners()
        if name not in by_name:
            raise KeyError(name)
        ent = next((e for e in self.catalogue() if e["name"] == name), None)
        picked = [c for c in by_name[name] if ent and c[0] == ent["overlay"]]
        return picked or by_name[name]

    def _retail(self, name, overlay=None):
        choices = self._choices(name)
        overlay, size = next((c for c in choices if c[0] == overlay), choices[0])
        if overlay not in self._overlay_text:
            from elftools.elf.elffile import ELFFile
            with open(self.refs / "levels" / overlay / "overlay.elf", "rb") as f:
                t = ELFFile(f).get_section_by_name(".text")
                self._overlay_text[overlay] = (t.data(), t["sh_addr"])
        data, base = self._overlay_text[overlay]
        addr = int(name[5:], 16)
        return overlay, size, data[addr - base:addr - base + size]

    def get_function_asm(self, name):
        _, _, tl = self._tools()
        overlay, size, code = self._retail(name)
        lines = tl.disasm(code, int(name[5:], 16), str(self.toolbin.parent))
        return ("# %s: canonical owner in %s, 0x%X bytes\n" % (name, overlay, size)
                + "\n".join("%08X  %s" % (int(name[5:], 16) + 4 * i, l) for i, l in enumerate(lines)) + "\n")

    def get_function_c(self, name):
        self._retail(name)  # KeyError for a name that isn't an owner
        p = self.src_dir / ("%s.c" % name)
        if p.exists():
            return p.read_text(encoding="utf-8")
        cached = self.work_dir / "src" / ("%s.c" % name)
        if cached.exists():
            return cached.read_text(encoding="utf-8")
        return ('#include "common.h"\n\n'
                "/* Shared level code: one function per file, no assembly, globals and\n"
                " * callees named by their level address (docs/common_level_c.md). */\n"
                "void %s(void) {\n    // TODO\n}\n" % name)

    # -- build -------------------------------------------------------------

    def _profiles(self, profile, name):
        """The (flags_from, mode, assembler) candidates for a build: the one
        picked in the page, the function's catalogue entry, or all four."""
        if profile and profile != "auto":
            mode, asm = profile.split("/")
            return [(DEFAULT_FLAGS_FROM, mode, asm)]
        ent = next((e for e in self.catalogue() if e["name"] == name), None)
        out = [(ent["flags_from"], ent["mode"], ent["assembler"])] if ent else []
        return out + [(DEFAULT_FLAGS_FROM, m, a) for m, a in PROFILES if (DEFAULT_FLAGS_FROM, m, a) not in out]

    def _compile(self, src_path, name, flags_from, mode, asm):
        """Linked bytes of `name` compiled from src_path, or raise BuildError."""
        tf, _, _ = self._tools()
        flags = tf.apply_overrides(tf.flags_for(int(flags_from[5:], 16)), mode, asm)
        opts = SimpleNamespace(no_context=True, toolchain=str(self.toolbin.parent), runner=None)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            o = tf.compile_c(str(src_path), flags, opts, name)
        if o is None:
            raise self.BuildError("compile", buf.getvalue().strip()[-3000:])
        from elftools.elf.elffile import ELFFile
        with open(o, "rb") as f:
            el = ELFFile(f)
            sym = [s for s in el.get_section_by_name(".symtab").iter_symbols() if s.name == name]
            if not sym:
                raise self.BuildError("compile", "the source doesn't define %s" % name)
            text = el.get_section_by_name(".text").data()
            st, sz = sym[0]["st_value"], sym[0]["st_size"]
            res, _ = tf.resolve_relocations(el, text)
        linked = bytearray(text[st:st + sz])
        for pos, w in res.items():
            if st <= pos < st + sz:
                linked[pos - st:pos - st + 4] = w.to_bytes(4, "little")
        return bytes(linked), flags

    def build(self, name, c_source, profile=None):
        """asm-differ JSON for the best profile, plus `profile`, `flags` and
        `gates` ({ok, message}; only run at a 0 score)."""
        src_path = self.work_dir / "src" / ("%s.c" % name)
        src_path.write_text(c_source, encoding="utf-8", newline="\n")
        work = self.work_dir
        target_bin = work / ("%s_target.bin" % name)
        source_bin = work / ("%s_source.bin" % name)
        best, errors, compiled = None, [], {}
        for overlay, _ in self._choices(name):
            _, size, retail = self._retail(name, overlay)
            for flags_from, mode, asm in self._profiles(profile, name):
                key = (flags_from, mode, asm)
                try:
                    if key not in compiled:
                        compiled[key] = self._compile(src_path, name, flags_from, mode, asm)
                    code, flags = compiled[key]
                except self.BuildError as e:
                    errors.append(e)
                    continue
                target_bin.write_bytes(retail)
                source_bin.write_bytes(code)
                d = self._differ(work, target_bin, source_bin, self.toolbin)
                d["profile"] = {"flags_from": flags_from, "mode": mode, "assembler": asm}
                d["overlay"] = overlay
                d["flags"] = flags
                d["size"] = {"compiled": len(code), "retail": size}
                if best is None or (d.get("current_score") or 0) < (best.get("current_score") or 0):
                    best = d
                if d.get("current_score") == 0 and len(code) == size:
                    break
            if best and best.get("current_score") == 0 and best["size"]["compiled"] == best["size"]["retail"]:
                break
        if best is None:
            raise errors[0]
        # 0 instruction diffs isn't enough: the gates also need the exact size,
        # the raw object body and no data sections
        if best.get("current_score") == 0:
            best["gates"] = self.gates(name, src_path, best["profile"], best["overlay"])
        else:
            best["gates"] = {"ok": False, "message": "not run (the instructions still differ)"}
        verified = best["gates"]["ok"]
        self.save_status_entry(name, 0 if verified else max(1, best.get("current_score") or 0), best.get("max_score"))
        best["verified"] = verified
        return best

    def gates(self, name, src_path, profile, overlay):
        """build_common_c.py's gates for the source at src_path, against the
        owner in `overlay`."""
        _, bcc, _ = self._tools()
        _, owners, common = self.owners()
        overlay, size = next(c for c in self._choices(name) if c[0] == overlay)
        entry = {"name": name, "source": src_path.relative_to(self.root).as_posix(), "overlay": overlay,
                 "address": "0x" + name[5:], "size": size, "flags_from": profile["flags_from"],
                 "mode": profile["mode"], "assembler": profile["assembler"]}
        opts = SimpleNamespace(no_context=True, toolchain=str(self.toolbin.parent), runner=None)
        buf = io.StringIO()
        try:
            with contextlib.redirect_stdout(buf):
                bcc.compile_entry(entry, self.refs / "levels", self.refs / "level-targets", owners, common, opts)
            return {"ok": True, "message": "all gates pass: counts in the report once saved"}
        except ValueError as e:
            return {"ok": False, "message": "gate failed: %s" % e}

    # -- save --------------------------------------------------------------

    def save(self, name, c_source, profile=None, force=False):
        """Write the source and its catalogue entry. Without force the build
        must pass the gates; with force only the source is written (kept out
        of the catalogue, so it doesn't count and can't break the report)."""
        d = None if force else self.build(name, c_source, profile)
        if d is not None and not d["verified"]:
            raise self.BuildError("save", "%s isn't verified yet (%s); only functions that pass the gates are "
                                  "saved, since a catalogued function that fails breaks `make objdiff`. "
                                  "Your code is kept in the editor." % (name, d["gates"]["message"]))
        # committing the catalogue would also commit entries someone else left
        # uncommitted (whose sources may not be committed): check before writing
        self.catalogue_was_dirty = self._catalogue_dirty()
        path = self.src_dir / ("%s.c" % name)
        _write_like(path, c_source)
        touched = [path]
        if d is not None:
            overlay, size = next(c for c in self._choices(name) if c[0] == d["overlay"])
            p = d["profile"]
            entry = {"name": name, "source": "src/levels/common/%s.c" % name, "overlay": overlay,
                     "address": "0x" + name[5:], "size": size, "flags_from": p["flags_from"],
                     "mode": p["mode"], "assembler": p["assembler"]}
            # replace in place or append: the catalogue keeps its order, so a
            # save is a one-entry diff
            cat = self.catalogue()
            at = next((i for i, e in enumerate(cat) if e["name"] == name), None)
            if at is None:
                cat.append(entry)
            else:
                cat[at] = entry
            _write_like(self.catalogue_path, json.dumps(cat, indent=2) + "\n")
            touched.append(self.catalogue_path)
        return touched, d

    def _catalogue_dirty(self):
        try:
            return self._run_git(self.root, ["diff", "--quiet", "HEAD", "--", "tools/common_c.json"]).returncode == 1
        except Exception:
            return False

    def sync_to_git(self, name, paths):
        def result(attempted, ok, message):
            return SimpleNamespace(to_json=lambda: {"attempted": attempted, "ok": ok, "message": message})
        if not self.git_sync:
            return result(False, True, "git sync disabled")
        if getattr(self, "catalogue_was_dirty", False):
            return result(False, False, "saved but not committed: tools/common_c.json already had uncommitted "
                          "entries from elsewhere; commit those (with their sources) first")
        return self._git_commit(self.root, "levels/common %s" % name, paths)
