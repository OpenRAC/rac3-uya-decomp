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


def expand_flags(flags, cc):
    """Expand text_parts.txt pseudo-flags that depend on the toolchain path.

    @ps2as  assemble this range with SN's own assembler (ee/bin/Ps2EeAs.exe)
            instead of the default bin/ee-as.exe. gcc looks for
            "<prefix>as.exe"; Windows file names are case-insensitive, so the
            prefix ".../ee/bin/Ps2Ee" finds Ps2EeAs.exe. gcc uses the last -B,
            so these are placed after the Makefile's CFLAGS.
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
            elif text.startswith(('INCLUDE_ASM', 'INCLUDE_RODATA', 'ASM_FUNC', 'LINKER_REMNANT',
                                  'TEXT_PADDING', '__asm__', 'asm(', 'asm (')):
                pass
            elif text.startswith(('extern', 'typedef', 'register')) or \
                    (re.match(r'^(struct|union|enum)\b[^=]*$', text)) or \
                    (re.search(r'\)\s*;?$', text) and '=' not in text and '(' in text):
                keep.append(text)  # declaration or prototype
            elif dropped is not None:
                dropped.append(text)
        i += 1
    return '\n'.join(k for k in keep if k)


# TEXT_PADDING(N) right after a function belongs to that function's chunk.
_PAD = r'(?:[ \t\r\n]*^TEXT_PADDING\(\w+\);[^\n]*\n?)?'


def split_chunks(text):
    """Split text.c into (addr_or_None, start_line, chunk_text) in file order.

    A chunk is one localdecomp block or INCLUDE_ASM line (addr = its function)
    or the free-standing text between them (addr = None). INCLUDE_RODATA lines
    right after an INCLUDE_ASM (its jump tables) stay with that function's
    part, so .rdata keeps function order and never lands in an @ps2as part."""
    pat = re.compile(
        r'(/\* localdecomp:start (func_[0-9A-Fa-f]{8}) \*/.*?/\* localdecomp:end \2 \*/\n?' + _PAD + ')'
        r'|(^(?:INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT)\("[^"]*",\s*(func_[0-9A-Fa-f]{8})\);[^\n]*\n?'
        r'(?:INCLUDE_RODATA\("[^"]*",\s*\w+\);[^\n]*\n?)*' + _PAD + ')', re.S | re.M)
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


def assign_parts(text, parts):
    """[(part index, start line, chunk text)] in file order, the way main()
    distributes text.c over the parts: free-standing text goes with the next
    function after it."""
    assigned, pending = [], []
    for addr, line, body in split_chunks(text):
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
    return assigned


_EXTERN_HINT_RE = re.compile(r'^\s*__asm__\s*\(\s*"\s*\.extern\s[^"]*"\s*\)\s*;', re.M)
_TYPEDEF_NAME_RE = re.compile(r'\btypedef\b[^;{]*?(?:\{(?:[^{}]|\{[^{}]*\})*\})?[^;{]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;', re.S)


def typedef_names(src):
    """Names of the typedefs a piece of C defines."""
    return set(_TYPEDEF_NAME_RE.findall(strip_comments(src)))


def drop_repeated_typedefs(context, src):
    """`src` without the typedefs that `context` already defines identically.

    The full build keeps the first definition; localdecomp's editor copy of a
    block often repeats typedefs from earlier blocks, and C forbids defining
    one twice. A typedef with the same name but a different body is left in:
    that is a real conflict, and the compiler should report it."""
    norm = lambda t: re.sub(r'\s+', ' ', t).strip()
    have = {m.group(1): norm(m.group(0)) for m in _TYPEDEF_NAME_RE.finditer(strip_comments(context))}
    return _TYPEDEF_NAME_RE.sub(
        lambda m: '' if have.get(m.group(1)) == norm(m.group(0)) else m.group(0), src)


def function_context(text, parts, name, drop_typedefs=()):
    """What the full build compiles in front of function `name`, minus code.

    The part file for a function starts with the declarations of every
    earlier part, then its own part's text up to the function. From the own
    part only declarations and top-level `.extern` size hints are kept: those
    change code generation (a #define that rewrites a name, a prototype whose
    return type decides register use, a hint that makes Ps2EeAs use $gp) but
    emit no bytes. localdecomp and tools/try_func.py compile a function after
    this, so a single-function build sees what the real build sees.

    Typedefs named in `drop_typedefs` are removed (the function's own block
    defines them; C forbids repeating a typedef)."""
    assigned = assign_parts(text, parts)
    target = None
    for n, (idx, line, body) in enumerate(assigned):
        if re.search(r'\b%s\s*\(' % re.escape(name), strip_comments(body)) and (
                'localdecomp:start ' + name in body or re.search(r'INCLUDE_ASM\([^)]*\b%s\)' % re.escape(name), body)):
            target = n
            break
    if target is None:
        return ''
    pi = assigned[target][0]
    out = []
    for idx, line, body in assigned[:target]:
        decl = declarations_only(body)
        if decl:
            out.append(decl)
        if idx == pi:
            out.extend(m.group(0).strip() for m in _EXTERN_HINT_RE.finditer(strip_comments(body)))
    ctx = '\n'.join(out) + '\n'
    drop = set(drop_typedefs)
    if drop:
        ctx = _TYPEDEF_NAME_RE.sub(lambda m: '' if m.group(1) in drop else m.group(0), ctx)
    return ctx


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
    assigned = assign_parts(text, parts)

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
        pflags = expand_flags(parts[pi][1], a.cc)
        asflags = [f for f in pflags if f.startswith('-B')]
        pflags = [f for f in pflags if not f.startswith('-B')]
        # gcc uses the LAST -B, so the range's assembler choice goes after cflags
        pcflags = cflags
        if '@ps2as' in parts[pi][1]:
            # Ps2EeAs rejects the GNU as options (-mips3, -mcpu=5900, ...)
            pcflags = [f for f in cflags if not f.startswith('-Wa,')]
        cmd = [a.cc, '-c'] + pflags + pcflags + asflags + ['-o', opath, cpath]
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
