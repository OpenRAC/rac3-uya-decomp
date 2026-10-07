"""Sony's ee-gcc 2.9-ee-991111 for the `@ee29` pseudo-flag in text_parts.txt.

Most of the game was built with SN's ee-gcc 2.95.3, the toolchain's normal
compiler. The library code linked into the executables came prebuilt from
Sony's own compiler instead: i5bootn's libgcc (soft-float, 64-bit division,
`__main`) and its small libc/SIO helpers were built with ee-gcc
2.9-ee-991111 (docs/compiler_matrix_i5bootn.md). A text_parts.txt range whose
flags contain `@ee29` is compiled to assembly with that compiler, through its
**driver** (bin/ee-gcc.exe), never cc1 directly: the driver passes the target
predefines (`__mips__`, `__R5900__`, ...) that libgcc's longlong.h needs.

The assembly is then assembled with the project's normal assembler, like
every other range, but it does **not** go through tools/asm_filter.py: that
filter reproduces the short-loop padding of the assembler SN's code was built
with, and Sony's library objects don't have it (with the filter,
`__do_global_ctors` gets one nop too many; without it every libgcc function
the Windows 2.9-ee builds right matches). Every path that compiles C
(build_text.py, try_func.py, try_in_context.py, permuter_setup.py,
localdecomp) skips the filter for an @ee29 range.

Where the compiler is:

  * env UYA_EE29: the 2.9-ee folder (the one holding bin/ and lib/gcc-lib/);
  * otherwise C:/tools/testfolder/ee-gcc2.9-991111 (the maintainer's layout).

The folder must have bin/ee-gcc.exe (the Windows build: committed matches
must use it, since the maintainer builds on Windows) or bin/ee-gcc (a Linux
build, e.g. 2.9-ee-991111-01, for experiments only). A Windows build runs
through UYA_RUNNER (wibo) on Linux and macOS. Its cc1/cpp folder
(lib/gcc-lib/ee/<version>/) is passed with -B, and its include folder (if it
has one) with -I, explicitly: under wibo the driver can't always find them
from its own location.

The rest of the range's flags (for example `-O2 -G0`) are passed to the 2.9
driver as they are, so write only options it knows on an @ee29 line (no
-fopt-stack, -mvu0-use-vf0-vf2, ...). The project's -B options (SN's
assembler) are dropped for the compile step.
"""
import os
import re
import shutil
import subprocess
import tempfile

FLAG = "@ee29"
DEFAULT_ROOT = "C:/tools/testfolder/ee-gcc2.9-991111"


def wanted(flags):
    """True if a text_parts.txt flag list asks for the 2.9-ee compiler."""
    return FLAG in flags


def strip(flags):
    """The flag list without the pseudo-flag."""
    return [f for f in flags if f != FLAG]


def root(path=None):
    return os.path.expanduser(path or os.environ.get("UYA_EE29") or DEFAULT_ROOT)


def gcc_lib(path=None):
    """lib/gcc-lib/ee/<version>/ of the 2.9-ee folder (cc1, cpp, specs)."""
    base = os.path.join(root(path), "lib", "gcc-lib", "ee")
    try:
        vers = sorted(d for d in os.listdir(base) if os.path.isdir(os.path.join(base, d)))
    except OSError:
        vers = []
    if not vers:
        raise FileNotFoundError("2.9-ee compiler not found: no %s/<version>/ (set UYA_EE29 to the "
                                "ee-gcc2.9-991111 folder)" % base.replace("\\", "/"))
    return os.path.join(base, vers[0])


def command(path=None, runner=None):
    """The driver command as a list, with its -B and -I options:
    [runner,] ee-gcc(.exe), -B<gcc-lib>/, [-I <gcc-lib>/include]."""
    r = root(path)
    exe = os.path.join(r, "bin", "ee-gcc.exe")
    native = os.path.join(r, "bin", "ee-gcc")
    cmd = []
    if os.path.exists(exe) or not os.path.exists(native):
        if os.name != "nt":
            cmd.append(runner or os.environ.get("UYA_RUNNER") or "wibo")
        cmd.append(exe)
    else:
        cmd.append(native)
    lib = gcc_lib(path)
    cmd.append("-B" + lib.replace("\\", "/").rstrip("/") + "/")
    inc = os.path.join(lib, "include")
    if os.path.isdir(inc):
        cmd += ["-I", inc]
    return cmd


def compile_flags(flags, cflags=()):
    """Options for the 2.9 driver's -S step: the range's flags without any
    pseudo-flag (@ee29, and an assembler choice like @newas or @ps2as,
    which only matters to the assembling step), then the project's compile
    options without SN's -B (the assembler choice) and -Wa (assembler
    options; the -S step doesn't assemble). @ps2as also needs
    -DNO_MACRO_INC here, as build_text.py's expand_flags() adds it for SN's
    compiler (Ps2EeAs can't read include/macro.inc)."""
    out = [f for f in flags if not f.startswith("@")]
    if "@ps2as" in flags and "-DNO_MACRO_INC" not in out:
        out.append("-DNO_MACRO_INC")
    out += [f for f in cflags if not f.startswith(("-B", "-Wa,"))]
    return out


_LINE1_RE = re.compile(r'^([ \t]*#[ \t]*line[ \t]+)1([ \t]+")', re.M)


def fix_line_directives(text):
    """The Windows 2.9-ee cpp turns `#line 1 "file"` into `# 0 "file"`,
    which its cc1 rejects ("invalid #-line"); other line numbers work. The
    build and the tools put `#line 1` in front of slices and contexts, so
    those become `#line 2` (error messages in that stretch are one line
    late)."""
    return _LINE1_RE.sub(lambda m: m.group(1) + "2" + m.group(2), text)


def to_asm(flags, cflags, cpath, spath, cwd=None, path=None, runner=None, capture=False):
    """Compile cpath to assembly spath with the 2.9 driver. Each run gets its
    own TMP folder (the driver keeps its .i file there). Returns the
    CompletedProcess."""
    tmp = tempfile.mkdtemp(prefix="ee29_")
    env = dict(os.environ, TMP=tmp, TEMP=tmp, TMPDIR=tmp)
    cmd = command(path, runner)
    src = cpath
    if any(c.lower().endswith("ee-gcc.exe") for c in cmd):
        text = open(os.path.join(cwd or ".", cpath), errors="replace").read()
        fixed = fix_line_directives(text)
        if fixed != text:
            # the copy keeps the source's name, so .file and messages still name it
            src = os.path.join(tmp, "src", os.path.basename(cpath))
            os.makedirs(os.path.dirname(src))
            with open(src, "w", newline="\n") as f:
                f.write(fixed)
    cmd = cmd + ["-S"] + compile_flags(flags, cflags) + ["-o", spath, src]
    try:
        if capture:
            return subprocess.run(cmd, cwd=cwd, env=env, capture_output=True, text=True)
        print(" ".join(cmd), flush=True)
        return subprocess.run(cmd, cwd=cwd, env=env)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
