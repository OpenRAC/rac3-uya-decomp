#!/usr/bin/env python3
"""pr_check.py: catch the mistakes that break the full build before a PR.

Run from anywhere; paths are relative to the repo root.

    python tools/pr_check.py                       # source checks
    python tools/pr_check.py --obj build/src/text.c.o   # plus object checks

`make` (MATCH) is still the real test. These checks explain the usual
reasons it fails, in terms of the line you need to fix:

  markers    every /* localdecomp:start X */ has a matching end and the block
             defines function X
  duplicates a function is not both INCLUDE_ASM and C
  variables  no variable is *defined* in text.c (only `extern`); a definition
             creates .data/.sdata/.bss and breaks the layout or the link
  typedefs   a typedef name is not defined twice with different bodies
  aliases    every per-function alias (D_XXXXXXXX_suffix) has an address in
             symbol_addrs_resolved.txt, or the link fails with "undefined"
  rodata     every INCLUDE_RODATA (jump table) directly follows its
             function's INCLUDE_ASM, so a converted function doesn't keep a
             stale copy of its table
  ps2as      no text_parts.txt range assembled with @ps2as contains an
             INCLUDE_ASM stub (Ps2EeAs cannot read macro.inc)
  overrides  tools/localdecomp_flags.txt entries for functions that are now
             C (move them into text_parts.txt)
  retail     no retail binaries are tracked by git
  --obj      the built text.c.o has no data sections

Exit status 1 if any error was found. Warnings don't fail.
"""
import argparse, os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT_C = os.path.join(ROOT, "src", "text.c")

errors, warnings = [], []

# A function definition: at the start of a line, a return type with no '(' or
# '=' before the name, a balanced parameter list, then '{'.
DEF_RE = re.compile(r"^[A-Za-z_][^\n;=(){}]*?\b(func_[0-9A-Fa-f]{8})\s*"
                    r"\((?:[^()]|\([^()]*\))*\)\s*(?:[A-Za-z_][^;{}()]*;\s*)*\{", re.M)  # also K&R


def err(msg): errors.append(msg)
def warn(msg): warnings.append(msg)


def lineno(text, pos):
    return text.count("\n", 0, pos) + 1


def strip_comments(text, keep_strings=False):
    """Blank out comments (and string literals unless keep_strings), keeping
    offsets and newlines."""
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        if text.startswith("/*", i):
            j = text.find("*/", i + 2); j = n if j < 0 else j + 2
        elif text.startswith("//", i):
            j = text.find("\n", i); j = n if j < 0 else j
        elif text[i] == '"':
            j = i + 1
            while j < n and text[j] != '"':
                j += 2 if text[j] == "\\" else 1
            j += 1
            if keep_strings:
                i = j; continue
        else:
            i += 1; continue
        for k in range(i, min(j, n)):
            if out[k] != "\n":
                out[k] = " "
        i = j
    return "".join(out)


def top_level_statements(code):
    """Yield (start_offset, text) for each statement at brace depth 0.
    Function bodies and struct bodies are collapsed to '{}'."""
    depth, start, buf = 0, 0, []
    i = 0
    while i < len(code):
        c = code[i]
        if depth == 0 and c == "#" and (i == 0 or code[i - 1] == "\n"):
            j = code.find("\n", i)
            while j > 0 and code[j - 1] == "\\":
                j = code.find("\n", j + 1)
            i = len(code) if j < 0 else j + 1
            start = i; buf = []
            continue
        if c == "{":
            if depth == 0:
                buf.append("{}")
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                stmt = "".join(buf).strip()
                # a function body ends the statement, a struct body doesn't
                if re.search(r"\)\s*\{\}$", stmt):
                    yield start, stmt
                    start, buf = i + 1, []
        elif depth == 0:
            if c == ";" and re.search(r"\b\w+\s*\([\w\s,]*\)\s*[A-Za-z_][^()]*$", "".join(buf)):
                buf.append(c)  # K&R parameter declaration: `f(p) u8 *p; {`
            elif c == ";":
                yield start, "".join(buf).strip()
                start, buf = i + 1, []
            else:
                if not buf and c.isspace():
                    start = i + 1
                else:
                    buf.append(c)
        i += 1


def is_variable_definition(stmt):
    s = re.sub(r"\s+", " ", stmt).strip()
    if not s:
        return False
    if re.match(r"(extern|typedef|__asm__|asm|INCLUDE_ASM|INCLUDE_RODATA)\b", s):
        return False
    if s.endswith("{}") and ")" in s:           # function definition
        return False
    if re.match(r"(struct|union|enum) \w+ ?\{\}$", s):  # tag declaration only
        return False
    if re.search(r"\bregister\b.*\basm\b", s) or re.search(r"\bregister\b.*__asm__", s):
        return False                            # global register variable: no storage
    head = s.split("=", 1)[0]
    # prototype: identifier directly followed by '(' (not a '(*name)' pointer)
    if re.search(r"\b\w+\s*\((?!\s*\*)", head) and not re.search(r"\(\s*\*\s*\w+\s*\)", head):
        return False
    return True


def check_text_c():
    raw = open(TEXT_C, encoding="utf-8", errors="replace").read().replace("\r\n", "\n")
    code = strip_comments(raw)
    code_str = strip_comments(raw, keep_strings=True)
    macros = set(re.findall(r"^\s*#\s*define\s+(\w+)", raw, re.M))

    # markers
    starts = [(m.start(), m.group(1)) for m in re.finditer(r"/\* localdecomp:start (\w+) \*/", raw)]
    ends = {m.group(1): m.start() for m in re.finditer(r"/\* localdecomp:end (\w+) \*/", raw)}
    seen = set()
    for pos, name in starts:
        if name in seen:
            err(f"text.c:{lineno(raw, pos)}: second localdecomp:start for {name}")
        seen.add(name)
        end = ends.get(name)
        if end is None or end < pos:
            err(f"text.c:{lineno(raw, pos)}: localdecomp:start {name} has no matching end marker")
            continue
        block = raw[pos:end]
        inner = re.search(r"/\* localdecomp:start (\w+) \*/", block[5:])
        if inner:
            err(f"text.c:{lineno(raw, pos)}: block {name} contains another start marker ({inner.group(1)})")
        if re.search(r"\.globa?l\s+%s\b" % re.escape(name), block):
            warn(f"text.c:{lineno(raw, pos)}: {name} is written as inline asm, not C")
        elif name not in [d.group(1) for d in DEF_RE.finditer(strip_comments(block))]:
            err(f"text.c:{lineno(raw, pos)}: block {name} does not define {name}")
    for name, pos in ends.items():
        if name not in seen:
            err(f"text.c:{lineno(raw, pos)}: localdecomp:end {name} without a start marker")

    # duplicates
    asm = {m.group(1): m.start() for m in
           re.finditer(r'INCLUDE_ASM\("[^"]+",\s*(func_[0-9A-Fa-f]{8})\)', code_str)}
    defined = {}
    for m in DEF_RE.finditer(code):
        if m.group(1) in defined:
            err(f"text.c:{lineno(raw, m.start())}: {m.group(1)} is defined twice")
        defined[m.group(1)] = m.start()
    for name in sorted(set(asm) & set(defined)):
        err(f"text.c:{lineno(raw, defined[name])}: {name} is both C and INCLUDE_ASM "
            f"(line {lineno(raw, asm[name])}); remove the INCLUDE_ASM line")

    # jump tables: an INCLUDE_RODATA belongs right after its function's
    # INCLUDE_ASM. Left behind after the function became C, it duplicates the
    # table gcc now emits and shifts all of .data.
    prev = ""
    for i, line in enumerate(raw.split("\n"), 1):
        t = line.strip()
        if t.startswith("INCLUDE_RODATA(") and not prev.startswith(("INCLUDE_ASM(", "INCLUDE_RODATA(")):
            err(f"text.c:{i}: {t} does not follow an INCLUDE_ASM; if its function is C now, delete this line")
        if t:
            prev = t

    # variable definitions
    for pos, stmt in top_level_statements(code):
        if is_variable_definition(stmt):
            one = re.sub(r"\s+", " ", stmt)[:90]
            err(f"text.c:{lineno(raw, pos)}: defines a variable: `{one};` "
                "declare it `extern` instead (retail data lives in the data segments)")

    # typedefs
    bodies = {}
    for m in re.finditer(r"\btypedef\b", code):
        # find the end of this typedef at depth 0
        depth, j = 0, m.end()
        while j < len(code):
            if code[j] == "{": depth += 1
            elif code[j] == "}": depth -= 1
            elif code[j] == ";" and depth == 0: break
            j += 1
        td = code[m.start():j]
        names = re.findall(r"(\w+)\s*(?:\[[^\]]*\])?\s*$", td)
        if not names:
            continue
        name = names[0]
        norm = re.sub(r"\s+", " ", td).strip()
        if name in bodies and bodies[name][1] != norm:
            err(f"text.c:{lineno(raw, m.start())}: typedef {name} redefined with a different body "
                f"(first at line {lineno(raw, bodies[name][0])}); give one of them a unique name")
        elif name in bodies:
            warn(f"text.c:{lineno(raw, m.start())}: typedef {name} repeated (identical); the second copy can go")
        else:
            bodies[name] = (m.start(), norm)

    # aliases
    sym_path = os.path.join(ROOT, "symbol_addrs_resolved.txt")
    known = set(re.findall(r"^\s*(\w+)\s*=", open(sym_path).read(), re.M)) if os.path.exists(sym_path) else set()
    for name in sorted(set(re.findall(r"\b(D_[0-9A-Fa-f]{8}_\w+)\b", code))):
        if name not in known and name not in macros:
            m = re.search(r"\b%s\b" % name, code)
            addr = name[2:10]
            err(f"text.c:{lineno(raw, m.start())}: alias {name} has no address; add "
                f"`{name} = 0x{addr.upper()};` to symbol_addrs_resolved.txt")
    return raw, code, asm, defined


def check_parts(raw, code, asm, defined):
    parts = []
    for line in open(os.path.join(ROOT, "tools", "text_parts.txt")):
        f = line.split("#", 1)[0].split()
        if f:
            parts.append((int(f[0], 16), f[1:]))
    parts.sort()
    for i, (start, flags) in enumerate(parts):
        if "@ps2as" not in flags:
            continue
        end = parts[i + 1][0] if i + 1 < len(parts) else 1 << 32
        bad = [n for n in asm if start <= int(n[5:], 16) < end]
        if bad:
            err(f"text_parts.txt: range 0x{start:08X} uses @ps2as but contains INCLUDE_ASM "
                f"{', '.join(sorted(bad)[:4])}; end the range after the C function(s)")
    ov = os.path.join(ROOT, "tools", "localdecomp_flags.txt")
    if os.path.exists(ov):
        for line in open(ov):
            f = line.split("#", 1)[0].split()
            if f and f[0] in defined:
                warn(f"localdecomp_flags.txt: {f[0]} is now C in text.c; move its flags into "
                     "text_parts.txt as a single-function override and delete this line")


def check_git():
    try:
        out = subprocess.run(["git", "ls-files"], cwd=ROOT, capture_output=True, text=True, timeout=30)
    except (OSError, subprocess.TimeoutExpired):
        warn("git not available; skipped the retail-file check")
        return
    if out.returncode:
        return
    for path in out.stdout.splitlines():
        low = path.lower()
        if low.startswith("asm/"):
            continue  # splat output (incl. asm/header.bin) is tracked on purpose
        if (low.endswith((".elf", ".bin", ".iso", ".wad", ".o"))
                or low.startswith(("build/", ".localdecomp_work/"))):
            err(f"git tracks {path}: retail binaries and build output must never be committed "
                f"(git rm --cached \"{path}\")")


def check_obj(path):
    try:
        from elftools.elf.elffile import ELFFile
    except ImportError:
        warn("--obj needs pyelftools (pip install -r tools/requirements.txt)")
        return
    elf = ELFFile(open(path, "rb"))
    bad = [(s.name, s["sh_size"]) for s in elf.iter_sections()
           if s["sh_type"] in ("SHT_PROGBITS", "SHT_NOBITS")
           and s.name not in (".text", ".reginfo", ".mdebug", ".comment", ".pdr") and s["sh_size"] > 0]
    for name, size in bad:
        err(f"{path}: section {name} has 0x{size:X} bytes; text.c must only produce .text "
            "(a variable was defined, or a string/float constant went to .rodata/.lit4)")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--obj", help="built object to check, e.g. build/src/text.c.o")
    ap.add_argument("--no-git", action="store_true", help="skip the git tracked-file check")
    args = ap.parse_args()

    raw, code, asm, defined = check_text_c()
    check_parts(raw, code, asm, defined)
    if not args.no_git:
        check_git()
    if args.obj:
        check_obj(args.obj)

    for w in warnings:
        print("warning:", w)
    for e in errors:
        print("error:", e)
    total = len(asm) + len(defined)
    print(f"{len(defined)} functions in C, {len(asm)} INCLUDE_ASM"
          + (f" ({100.0 * len(defined) / total:.1f}% in C)" if total else ""))
    print("OK" if not errors else f"{len(errors)} error(s)")
    sys.exit(1 if errors else 0)


if __name__ == "__main__":
    main()
