#!/usr/bin/env python3
"""Split the old single src/text.c into one C file per source file, or refresh
the cross-file declarations of the files that already exist.

  python tools/split_text.py --from src/text.c --boundaries tools/src_files.txt
      Cut text.c at the start addresses listed in tools/src_files.txt and
      write each file. Used once for the migration (and again if text.c-based
      branches have to be carried over).

  python tools/split_text.py --refresh
      Recompute the "declarations from other files" section at the top of
      every file in tools/src_files.txt. Run it after adding a prototype or
      extern that a later file relies on; the build and pr_check.py report
      when it is stale.

Each file gets only the declarations its own blocks use: every statement from
an earlier file (in link order) that declares a name the file uses before
declaring it itself, plus,
transitively, what those statements mention (a typedef's struct, a macro's
expansion). Preprocessor lines keep their order; identical C statements are
written once. A file never sees declarations from later files, the same rule
the single text.c had.
"""
import argparse
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import srcfiles as sf  # noqa: E402

HEADER = '#include "common.h"\n'


def write_keeping_newlines(path, text, default_nl="\n"):
    """Write `text` (LF) with the line endings the file already has (CRLF on
    a Windows checkout), or `default_nl` for a new file."""
    nl = default_nl
    if os.path.exists(path):
        nl = "\r\n" if b"\r\n" in open(path, "rb").read() else "\n"
    with open(path, "w", newline="") as f:
        f.write(text.replace("\r\n", "\n").replace("\n", nl))


def norm(s):
    return re.sub(r"\s+", " ", s).strip()


def external_declarations(stmts_before, need):
    """Statements (from earlier files, in order) that a file needs, given the
    names it uses. stmts_before: [(stmt, declared names, used names)]."""
    need = set(need)
    chosen = set()
    changed = True
    while changed:
        changed = False
        for i, (stmt, decl, used) in enumerate(stmts_before):
            if i in chosen or not (decl & need):
                continue
            chosen.add(i)
            new = used - need
            if new:
                need |= new
                changed = True
    out, seen = [], set()
    for i in sorted(chosen):
        stmt = stmts_before[i][0]
        if stmt.startswith("#"):
            out.append(stmt)
            continue
        k = norm(stmt)
        if k in seen:
            continue
        seen.add(k)
        out.append(stmt if stmt.endswith(";") else stmt + ";")
    return out


def statements_of(chunks):
    out = []
    for _, _, body in chunks:
        for st in sf.declaration_statements(body):
            out.append((st, sf.declared_names(st), sf.used_names(st)))
    return out


def render(ext, chunks, prelude=None):
    body = "".join(b for _, _, b in chunks)
    ext_text = "\n".join(ext)
    section = sf.EXT_BEGIN + "\n" + (ext_text + "\n" if ext_text else "") + sf.EXT_END
    if prelude and sf.EXT_BEGIN in prelude and sf.EXT_END in prelude:
        head, rest = prelude.split(sf.EXT_BEGIN, 1)
        tail = rest.split(sf.EXT_END, 1)[1]
        return head + section + tail + body
    return HEADER + "\n" + sf.EXT_BEGIN + "\n" + (ext_text + "\n" if ext_text else "") + sf.EXT_END + "\n\n" + body.lstrip("\n")


def file_needs(chunks):
    """Names a file uses before declaring them itself: the only ones it needs
    from earlier files. A name the file declares (prototype, extern, typedef,
    struct, macro) before its first use comes from the file's own
    declaration; copying an earlier file's declaration in front of it would
    only add a second one, which conflicts when the types differ."""
    need, declared = set(), set()
    for _, _, body in chunks:
        mine = set()
        for st in sf.declaration_statements(body):
            mine |= sf.declared_names(st)
        need |= sf.used_names(body) - declared - mine
        declared |= mine
    return need


def write_files(per_file, root, default_nl="\n"):
    """per_file: [(rel, chunks, prelude or None)] in link order."""
    stmts_before = []
    results = []
    for rel, chunks, prelude in per_file:
        ext = external_declarations(stmts_before, file_needs(chunks))
        results.append((rel, render(ext, chunks, prelude)))
        stmts_before += statements_of(chunks)
    for rel, text in results:
        path = os.path.join(root, rel)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        write_keeping_newlines(path, text, default_nl)
    return results


def split(text_path, files, root):
    raw = open(text_path, "rb").read()
    default_nl = "\r\n" if b"\r\n" in raw else "\n"
    text = raw.decode("utf-8", "replace").replace("\r\n", "\n")
    chunks = sf.split_chunks(text)
    if chunks and chunks[0][0] is None:
        prelude = chunks.pop(0)[2]
        if norm(prelude) != norm(HEADER):
            sys.exit("unexpected text before the first function in %s:\n%s" % (text_path, prelude))
    chunks = sf.attach_free_text(chunks)
    per = {rel: [] for rel, _ in files}
    for addr, line, body in chunks:
        per[sf.file_for_address(files, addr)].append((addr, line, body))
    empty = [rel for rel, _ in files if not per[rel]]
    if empty:
        sys.exit("files with no functions: " + ", ".join(empty))
    return write_files([(rel, per[rel], None) for rel, _ in files], root, default_nl)


def refresh(files, root):
    per_file = []
    for rel, _ in files:
        prelude, _, chunks = sf.split_file(sf.read_source(rel, root))
        per_file.append((rel, chunks, prelude))
    before = {rel: sf.read_source(rel, root) for rel, _ in files}
    results = write_files(per_file, root)
    return [rel for rel, text in results if text != before[rel]]


def earlier_statements(rel, files=None, root=sf.ROOT):
    """Declaration statements of every file before `rel` in link order."""
    out = []
    for r, _ in (files or sf.read_file_list()):
        if r == rel:
            break
        _, _, chunks = sf.split_file(sf.read_source(r, root))
        out += statements_of(chunks)
    return out


def extra_declarations(rel, src, files=None, root=sf.ROOT):
    """Declarations from earlier files that `src` (new code for file `rel`)
    needs and the file doesn't have yet: what `--refresh` would add once the
    code is saved. localdecomp and try_func.py put these in front of a test
    build so a function that uses another file's prototype compiles."""
    text = sf.read_source(rel, root)
    have = set(norm(x) for x in sf.declaration_statements(text))
    # names the new code or the file's own blocks declare come from those declarations
    blocks = "".join(b for _, _, b in sf.split_file(text)[2])
    own = set()
    for st in sf.declaration_statements(src) + sf.declaration_statements(blocks):
        own |= sf.declared_names(st)
    ext = external_declarations(earlier_statements(rel, files, root), sf.used_names(src) - own)
    return [x for x in ext if x.startswith("#") or norm(x.rstrip(";")) not in have and norm(x) not in have]


def refresh_one(rel, files=None, root=sf.ROOT):
    """Recompute one file's declarations from other files. True if it changed."""
    files = files or sf.read_file_list()
    text = sf.read_source(rel, root)
    prelude, _, chunks = sf.split_file(text)
    ext = external_declarations(earlier_statements(rel, files, root), file_needs(chunks))
    new = render(ext, chunks, prelude)
    if new != text:
        write_keeping_newlines(os.path.join(root, rel), new)
        return True
    return False


def main():
    import targets
    targets.from_argv(allow_all=True)   # --target boot_elf: that target's file list
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--from", dest="src", help="the old single text.c to split")
    ap.add_argument("--boundaries", default=sf.FILES_LIST, help="file list (path and start address per line)")
    ap.add_argument("--refresh", action="store_true", help="recompute cross-file declarations")
    ap.add_argument("--check", action="store_true", help="with --refresh: only report stale files")
    a = ap.parse_args()
    files = sf.read_file_list(a.boundaries)
    if a.src:
        res = split(a.src, files, sf.ROOT)
        print("wrote %d files" % len(res))
    elif a.refresh:
        if a.check:
            import shutil, tempfile
            tmp = tempfile.mkdtemp()
            for rel, _ in files:
                os.makedirs(os.path.dirname(os.path.join(tmp, rel)), exist_ok=True)
                shutil.copy(os.path.join(sf.ROOT, rel), os.path.join(tmp, rel))
            stale = refresh(files, tmp)
            shutil.rmtree(tmp)
            for rel in stale:
                print("stale declarations:", rel)
            sys.exit(1 if stale else 0)
        changed = refresh(files, sf.ROOT)
        print("updated %d files" % len(changed))
    else:
        ap.print_help()


if __name__ == "__main__":
    main()
