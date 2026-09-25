#!/usr/bin/env python3
"""Build src/text.c as several parts with per-range compiler flags.

Retail frontbin was built from many source files, and some of them used
different flags (currently: -mno-split-addresses). text.c stays the one file
everyone edits; this script cuts it at the addresses listed in
tools/text_parts.txt, compiles each part with that range's flags, and links
the parts back into a single relocatable object (ld -r). The result is a
drop-in replacement for the old single-compile text.c.o, so the linker
script and objdiff setup don't change.

Each part file contains:
  * everything text.c declares before that part (typedefs, externs,
    #defines, global register vars) -- so every function still sees exactly
    what it saw in the single-file build -- but none of the earlier code;
  * then the part's own functions and INCLUDE_ASM stubs, with #line
    directives so compiler errors point at src/text.c.

Usage (from the repo root, normally via the Makefile):
  python tools/build_text.py --cc CC --ld LD --cflags "..." -o build/src/text.c.o [--base]
"""
import argparse, os, re, subprocess, sys, shlex

FUNC_RE = re.compile(r'func_([0-9A-Fa-f]{8})')


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


def part_index(parts, addr):
    idx = 0
    for i, (start, _) in enumerate(parts):
        if addr >= start:
            idx = i
    return idx


def strip_comments(s):
    out, i, n = [], 0, len(s)
    while i < n:
        c = s[i]
        if c == '"' or c == "'":
            j = i + 1
            while j < n and s[j] != c:
                j += 2 if s[j] == '\\' else 1
            out.append(s[i:j + 1]); i = j + 1
        elif s.startswith('/*', i):
            j = s.find('*/', i + 2); j = n if j < 0 else j + 2
            out.append('\n' * s.count('\n', i, j)); i = j
        elif s.startswith('//', i):
            j = s.find('\n', i); j = n if j < 0 else j
            i = j
        else:
            out.append(c); i += 1
    return ''.join(out)


def declarations_only(chunk, dropped=None):
    """Top-level declarations of a chunk: preprocessor lines, typedefs,
    extern declarations, prototypes and global register variables. Function
    bodies, top-level asm and anything that would allocate storage are left
    out (they belong only to the part that owns them)."""
    s = strip_comments(chunk)
    keep, stmt, depth, i, n = [], [], 0, 0, len(s)
    aggregate = False
    while i < n:
        c = s[i]
        if depth == 0 and not ''.join(stmt).strip() and c == '#':
            j = i
            while True:  # preprocessor line with continuations
                k = s.find('\n', j); k = n if k < 0 else k
                if k > 0 and s[k - 1] == '\\':
                    j = k + 1; continue
                break
            keep.append(s[i:k].strip()); i = k + 1; stmt = []; continue
        if c == '"' or c == "'":
            j = i + 1
            while j < n and s[j] != c:
                j += 2 if s[j] == '\\' else 1
            stmt.append(s[i:j + 1]); i = j + 1; continue
        stmt.append(c)
        if c == '{':
            if depth == 0:
                head = ''.join(stmt)[:-1]
                aggregate = bool(re.search(r'\b(struct|union|enum)\b[\w\s]*$', head)) or '=' in head
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0 and not aggregate:
                stmt = []  # end of a function definition
        elif c == ';' and depth == 0:
            text = ''.join(stmt).strip()
            stmt = []
            if not text:
                pass
            elif text.startswith(('INCLUDE_ASM', 'INCLUDE_RODATA', '__asm__', 'asm(', 'asm (')):
                pass
            elif text.startswith(('extern', 'typedef', 'register')) or \
                    (re.match(r'^(struct|union|enum)\b[^=]*$', text)) or \
                    (re.search(r'\)\s*;?$', text) and '=' not in text and '(' in text):
                keep.append(text)  # declaration or prototype
            elif dropped is not None:
                dropped.append(text)
        i += 1
    return '\n'.join(k for k in keep if k)


def split_chunks(text):
    """Split text.c into (addr_or_None, start_line, chunk_text) in file order.

    A chunk is one localdecomp block or INCLUDE_ASM line (addr = its function)
    or the free-standing text between them (addr = None)."""
    pat = re.compile(
        r'(/\* localdecomp:start (func_[0-9A-Fa-f]{8}) \*/.*?/\* localdecomp:end \2 \*/\n?)'
        r'|(^INCLUDE_ASM\("[^"]*",\s*(func_[0-9A-Fa-f]{8})\);[^\n]*\n?)', re.S | re.M)
    chunks, pos = [], 0
    for m in pat.finditer(text):
        if m.start() > pos:
            chunks.append((None, text.count('\n', 0, pos) + 1, text[pos:m.start()]))
        name = m.group(2) or m.group(4)
        chunks.append((int(name[5:], 16), text.count('\n', 0, m.start()) + 1, m.group(0)))
        pos = m.end()
    if pos < len(text):
        chunks.append((None, text.count('\n', 0, pos) + 1, text[pos:]))
    return chunks


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--src', default='src/text.c')
    ap.add_argument('--parts', default='tools/text_parts.txt')
    ap.add_argument('--cc', required=True)
    ap.add_argument('--ld', required=True)
    ap.add_argument('--cflags', default='')
    ap.add_argument('--base', action='store_true', help='objdiff base build (-DOBJDIFF_BASE)')
    ap.add_argument('--workdir', default=None)
    ap.add_argument('-o', '--output', required=True)
    a = ap.parse_args()

    parts = read_parts(a.parts)
    text = open(a.src).read()
    chunks = split_chunks(text)

    # assign free-standing text to the part of the next function after it
    assigned, pending = [], []
    for addr, line, body in chunks:
        if addr is None:
            pending.append((line, body))
            continue
        idx = part_index(parts, addr)
        for pl, pb in pending:
            assigned.append((idx, pl, pb))
        pending = []
        assigned.append((idx, line, body))
    last = assigned[-1][0] if assigned else 0
    for pl, pb in pending:
        assigned.append((last, pl, pb))

    header_end = 0
    workdir = a.workdir or os.path.join(os.path.dirname(a.output) or '.', 'parts' + ('_base' if a.base else ''))
    os.makedirs(workdir, exist_ok=True)
    src_abs = a.src.replace('\\', '/')
    cflags = shlex.split(a.cflags, posix=False)
    if a.base:
        cflags.append('-DOBJDIFF_BASE')
    objs = []
    used = sorted(set(i for i, _, _ in assigned))
    for pi in used:
        out = []
        for i, line, body in assigned:
            if i < pi:
                decl = declarations_only(body)
                if decl:
                    out.append(decl + '\n')
            elif i == pi:
                out.append(f'#line {line} "{src_abs}"\n{body}')
        cpath = os.path.join(workdir, f'text_p{pi:02d}.c')
        opath = os.path.join(workdir, f'text_p{pi:02d}.o')
        with open(cpath, 'w') as f:
            f.write(''.join(out))
        cmd = [a.cc, '-c'] + parts[pi][1] + cflags + ['-o', opath, cpath]
        print(' '.join(cmd), flush=True)
        r = subprocess.run(cmd)
        if r.returncode != 0:
            sys.exit(f'build_text: part {pi} (0x{parts[pi][0]:08X}) failed to compile')
        objs.append(opath)
    cmd = [a.ld, '-r', '-o', a.output] + objs
    print(' '.join(cmd), flush=True)
    r = subprocess.run(cmd)
    if r.returncode != 0:
        sys.exit('build_text: ld -r failed')


if __name__ == '__main__':
    main()
