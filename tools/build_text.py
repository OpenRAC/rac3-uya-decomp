#!/usr/bin/env python3
"""Build frontbin's .text from the per-file sources in src/frontbin/.

The sources are one C file per original source file, listed in link order in
tools/src_files.txt (see tools/srcfiles.py). Compiler and assembler flags come
from tools/text_parts.txt, by function address.

  * A file whose functions all use the same flags is compiled as it is, once.
  * A file that mixes flags (some functions only match with a different
    assembler or address mode) is compiled in slices, one per run of equal
    flags. Each slice is the file's own prelude (includes and its
    declarations from other files) plus the declarations of the file's
    earlier functions, then the slice's functions, with #line directives so
    errors point at the real file. Nothing from other files is replayed.

Every object goes through tools/asm_filter.py between gcc -S and the
assembler (retail's short-loop and div.s padding). Each source file ends up
as <workdir>/<file>.o (objdiff compares these, one unit per file; slice
objects are kept apart in <workdir>/slices/), and all of them are linked into
one relocatable object (ld -r) for the linker script.

Usage (from the repo root, normally via the Makefile):
  python tools/build_text.py --cc CC --ld LD --cflags "..." -o build/src/text.c.o [--base]
"""
import argparse
import os
import re
import shlex
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_filter  # noqa: E402
import srcfiles as sf  # noqa: E402
from srcfiles import strip_comments, declarations_only, EXTERN_HINT_RE  # noqa: E402,F401

FUNC_RE = re.compile(r'func_([0-9A-Fa-f]{8})')
_EXTERN_HINT_RE = EXTERN_HINT_RE


def read_parts(path):
    parts = []
    for line in open(path):
        line = line.split('#', 1)[0].strip()
        if not line:
            continue
        fields = line.split()
        parts.append((int(fields[0], 16), fields[1:]))
    parts.sort()
    if not parts:
        sys.exit(f"{path}: no parts defined")
    return parts


def expand_flags(flags, cc):
    """Expand text_parts.txt pseudo-flags that depend on the toolchain path.

    @ps2as  assemble with SN's own assembler (ee/bin/Ps2EeAs.exe) instead of
            the default bin/ee-as.exe. gcc looks for "<prefix>as.exe"; Windows
            file names are case-insensitive, so the prefix ".../ee/bin/Ps2Ee"
            finds Ps2EeAs.exe. gcc uses the last -B, so these are placed after
            the Makefile's CFLAGS.
    @newas  use ee/bin/as.exe (May 2001), the one gcc picks without any -B."""
    root = os.path.dirname(os.path.dirname(os.path.abspath(cc)))
    out = []
    for f in flags:
        if f == '@ps2as':
            out.append('-B' + os.path.join(root, 'ee', 'bin', 'Ps2Ee'))
            out.append('-DNO_MACRO_INC')  # Ps2EeAs can't read include/macro.inc
        elif f == '@newas':
            out.append('-B' + os.path.join(root, 'ee', 'bin') + os.sep)
        else:
            out.append(f)
    return out


def part_index(parts, addr):
    idx = 0
    for i, (start, _) in enumerate(parts):
        if addr >= start:
            idx = i
    return idx


def flags_for(parts, addr):
    return parts[part_index(parts, addr)][1]


_TYPEDEF_NAME_RE = re.compile(r'\btypedef\b[^;{]*?(?:\{(?:[^{}]|\{[^{}]*\})*\})?[^;{]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;', re.S)


def typedef_names(src):
    """Names of the typedefs a piece of C defines."""
    return set(_TYPEDEF_NAME_RE.findall(strip_comments(src)))


def drop_repeated_typedefs(context, src):
    """`src` without the typedefs that `context` already defines identically
    (C forbids defining one twice). A typedef with the same name but a
    different body is left in: that is a real conflict."""
    norm = lambda t: re.sub(r'\s+', ' ', t).strip()
    have = {m.group(1): norm(m.group(0)) for m in _TYPEDEF_NAME_RE.finditer(strip_comments(context))}
    return _TYPEDEF_NAME_RE.sub(
        lambda m: '' if have.get(m.group(1)) == norm(m.group(0)) else m.group(0), src)


def file_slices(chunks, parts):
    """[(flags, [chunk indices])]: runs of consecutive chunks with equal flags."""
    out = []
    for i, (addr, _, _) in enumerate(chunks):
        fl = flags_for(parts, addr)
        if out and out[-1][0] == fl:
            out[-1][1].append(i)
        else:
            out.append((fl, [i]))
    return out


def prelude_lines(prelude):
    return prelude.count('\n')


def slice_source(rel, prelude, chunks, idxs):
    """C text for one slice of a mixed-flag file."""
    path = rel.replace('\\', '/')
    out = ['#line 1 "%s"\n' % path, prelude]
    first = idxs[0]
    for addr, line, body in chunks[:first]:
        decl = declarations_only(body)
        if decl:
            out.append('#line %d "%s"\n%s\n' % (line, path, decl))
    for i in idxs:
        addr, line, body = chunks[i]
        out.append('#line %d "%s"\n%s' % (line, path, body))
    return ''.join(out)


def function_context(text_unused, parts, name, drop_typedefs=(), own_src=None):
    """What the build compiles in front of function `name`, minus code: the
    file's prelude (includes, declarations from other files), the
    declarations of the file's earlier functions, and the top-level `.extern`
    size hints of earlier functions compiled in the same slice (they change
    which globals Ps2EeAs reaches through $gp). localdecomp and
    tools/try_func.py compile a function after this, so a single-function
    build sees what the real build sees.

    Typedefs named in `drop_typedefs` are removed (the function's own block
    defines them; C forbids repeating a typedef). The first argument is
    ignored (it used to be the text of src/text.c).

    With `own_src` (the code about to be tested), declarations from earlier
    files that it needs and its file doesn't have yet are added after the
    prelude, as `tools/split_text.py --refresh` will add them on save."""
    files = sf.read_file_list()
    found = sf.find_function(name, files)
    if not found:
        return ''
    rel, text, _, _ = found
    prelude, _, chunks = sf.split_file(text)
    target = None
    for n, (addr, line, body) in enumerate(chunks):
        if sf.is_own_chunk(body, name):
            target = n
            break
    if target is None:
        return ''
    own = flags_for(parts, chunks[target][0])
    same = True
    out = [strip_comments(prelude)]
    if own_src:
        import split_text
        out.extend(split_text.extra_declarations(rel, own_src, files))
    # walk back to see which earlier chunks share this function's slice
    in_slice = [False] * target
    for n in range(target - 1, -1, -1):
        if flags_for(parts, chunks[n][0]) != own:
            break
        in_slice[n] = True
    for n, (addr, line, body) in enumerate(chunks[:target]):
        decl = declarations_only(body)
        if decl:
            out.append(decl)
        if in_slice[n]:
            out.extend(m.group(0).strip() for m in EXTERN_HINT_RE.finditer(strip_comments(body)))
    ctx = '\n'.join(out) + '\n'
    drop = set(drop_typedefs)
    if drop:
        ctx = _TYPEDEF_NAME_RE.sub(lambda m: '' if m.group(1) in drop else m.group(0), ctx)
    return ctx


def compile_errors(rel, text, parts, gcc_cmd, cflags, tmpdir):
    """Compile every slice of one source file to assembly, the way main()
    does, without assembling or keeping the output, and return the compiler's
    error lines ([] if it compiles). `text` is the file's content (it may
    differ from the file on disk), `gcc_cmd` the compiler command as a list
    (runner + gcc). Used by pr_check.py and try_in_context.py to catch
    conflicting declarations before a full build does."""
    import tempfile
    prelude, _, chunks = sf.split_file(text)
    slices = file_slices(chunks, parts)
    root = os.path.dirname(os.path.dirname(os.path.abspath(gcc_cmd[-1])))
    errors = []
    for k, (fl, idxs) in enumerate(slices):
        src = text if len(slices) == 1 else slice_source(rel, prelude, chunks, idxs)
        if len(slices) == 1:
            src = '#line 1 "%s"\n' % rel.replace('\\', '/') + src
        fd, cpath = tempfile.mkstemp(suffix='.c', dir=tmpdir)
        with os.fdopen(fd, 'w', newline='\n') as f:
            f.write(src)
        spath = cpath[:-2] + '.s'
        pflags = [f for f in expand_flags(fl, os.path.join(root, 'bin', 'x')) if not f.startswith('-B')]
        pc = [f for f in cflags if not f.startswith('-Wa,')]
        r = subprocess.run(gcc_cmd + ['-S'] + pflags + pc + ['-o', spath, cpath],
                           capture_output=True, text=True)
        for p in (cpath, spath):
            try:
                os.remove(p)
            except OSError:
                pass
        if r.returncode:
            lines = [l for l in (r.stdout + r.stderr).splitlines()
                     if l.strip() and 'never used' not in l and 'warning' not in l]
            where = rel if len(slices) == 1 else '%s (slice %d)' % (rel, k)
            errors.append((where, lines or ['compiler failed with no message']))
    return errors


def compile_one(cc, flags, cflags, cpath, spath, opath, label):
    pflags = expand_flags(flags, cc)
    asflags = [f for f in pflags if f.startswith('-B')]
    pflags = [f for f in pflags if not f.startswith('-B')]
    pcflags = cflags
    if '@ps2as' in flags:
        # Ps2EeAs rejects the GNU as options (-mips3, -mcpu=5900, ...)
        pcflags = [f for f in cflags if not f.startswith('-Wa,')]
    cmd = [cc, '-S'] + pflags + pcflags + asflags + ['-o', spath, cpath]
    print(' '.join(cmd), flush=True)
    if subprocess.run(cmd).returncode != 0:
        sys.exit(f'build_text: {label} failed to compile')
    with open(spath, newline='') as f:
        stext = f.read()
    with open(spath, 'w', newline='') as f:
        f.write(asm_filter.filter_asm(stext))
    cmd = [cc, '-c'] + pflags + pcflags + asflags + ['-o', opath, spath]
    print(' '.join(cmd), flush=True)
    if subprocess.run(cmd).returncode != 0:
        sys.exit(f'build_text: {label} failed to assemble')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--files', default=sf.FILES_LIST)
    ap.add_argument('--parts', default='tools/text_parts.txt')
    ap.add_argument('--cc', required=True)
    ap.add_argument('--ld', required=True)
    ap.add_argument('--cflags', default='')
    ap.add_argument('--base', action='store_true', help='objdiff base build (-DOBJDIFF_BASE)')
    ap.add_argument('--workdir', default=None)
    ap.add_argument('-o', '--output', required=True)
    a = ap.parse_args()

    parts = read_parts(a.parts)
    files = sf.read_file_list(a.files)
    workdir = a.workdir or os.path.join(os.path.dirname(a.output) or '.', 'frontbin')
    os.makedirs(workdir, exist_ok=True)
    cflags = shlex.split(a.cflags, posix=False)
    if a.base:
        cflags.append('-DOBJDIFF_BASE')
    objs = []
    for rel, _ in files:
        text = sf.read_source(rel)
        prelude, _, chunks = sf.split_file(text)
        stem = os.path.splitext(os.path.basename(rel))[0]
        slices = file_slices(chunks, parts)
        if len(slices) == 1:
            # the file as it is, once
            spath = os.path.join(workdir, stem + '.s')
            opath = os.path.join(workdir, stem + '.o')
            compile_one(a.cc, slices[0][0], cflags, rel, spath, opath, rel)
            objs.append(opath)
            continue
        sobjs = []
        # slices go in their own folder, so workdir holds one .o per file
        sdir = os.path.join(workdir, 'slices')
        os.makedirs(sdir, exist_ok=True)
        for k, (fl, idxs) in enumerate(slices):
            cpath = os.path.join(sdir, '%s.%d.c' % (stem, k))
            spath = os.path.join(sdir, '%s.%d.s' % (stem, k))
            opath = os.path.join(sdir, '%s.%d.o' % (stem, k))
            with open(cpath, 'w', newline='\n') as f:
                f.write(slice_source(rel, prelude, chunks, idxs))
            compile_one(a.cc, fl, cflags, cpath, spath, opath, '%s (slice %d)' % (rel, k))
            sobjs.append(opath)
        # one object per source file (objdiff compares file by file)
        opath = os.path.join(workdir, stem + '.o')
        if subprocess.run([a.ld, '-r', '-o', opath] + sobjs).returncode != 0:
            sys.exit(f'build_text: ld -r of {rel} failed')
        objs.append(opath)
    cmd = [a.ld, '-r', '-o', a.output] + objs
    print('%s -r -o %s (%d objects)' % (a.ld, a.output, len(objs)), flush=True)
    if subprocess.run(cmd).returncode != 0:
        sys.exit('build_text: ld -r failed')


if __name__ == '__main__':
    main()
