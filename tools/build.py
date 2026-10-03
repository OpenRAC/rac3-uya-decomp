#!/usr/bin/env python3
"""build.py: the Makefile's `check` target in Python, for Linux and macOS.

On Windows, use the Makefile (SN's make.exe). This script runs the same steps
for systems where make.exe's cmd.exe syntax doesn't work, running the Windows
toolchain through wibo (https://github.com/decompals/wibo):

  1. assemble asm/header.s and the data segments (bin/ee-as.exe)
  2. build src/frontbin/*.c with tools/build_text.py (per-file, per-function flags)
  3. link with linker_scripts/frontbin.ld, objcopy to a flat binary
  4. tools/check_match.py: prints MATCH or the first differing offsets

    python3 tools/build.py --toolchain ~/sn --runner ~/bin/wibo

The toolchain folder must have the Windows layout (bin/ee-gcc2953.exe,
bin/ee-as.exe, bin/ee-ld.exe, bin/ee-objcopy.exe, ee/bin/Ps2EeAs.exe).
build_text.py derives the toolchain root from the compiler path, so this
script writes small wrapper scripts into build/wrap/ that call wibo.
"""
import argparse, os, re, stat, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASFLAGS = ["-I", "include", "-EL", "-mips3", "-mcpu=5900", "-mabi=eabi"]


def run(cmd, **kw):
    print("+", " ".join(cmd))
    p = subprocess.run(cmd, cwd=ROOT, **kw)
    if p.returncode:
        sys.exit(f"failed: {' '.join(cmd)}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"), required="UYA_TOOLCHAIN" not in os.environ)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER", "wibo"))
    args = ap.parse_args()
    tc = os.path.abspath(os.path.expanduser(args.toolchain))
    runner = args.runner
    exe = lambda name: [runner, os.path.join(tc, "bin", name)]

    build = os.path.join(ROOT, "build")
    os.makedirs(os.path.join(build, "asm", "data"), exist_ok=True)
    os.makedirs(os.path.join(build, "src"), exist_ok=True)

    run(exe("ee-as.exe") + ASFLAGS + ["-o", "build/asm/header.s.o", "asm/header.s"])
    # the data segments are whatever the linker script links
    script = open(os.path.join(ROOT, "linker_scripts", "frontbin.ld")).read()
    for seg in dict.fromkeys(re.findall(r"build/asm/data/(\w+)\.data\.s\.o", script)):
        run(exe("ee-as.exe") + ASFLAGS + ["-o", f"build/asm/data/{seg}.data.s.o", f"asm/data/{seg}.data.s"])

    # Wrappers live inside a fake toolchain tree (wrap/bin/...) with ee/ linked
    # to the real one, so build_text.py's "<root>/ee/bin/Ps2Ee" still resolves.
    wrap = os.path.join(build, "wrap")
    os.makedirs(os.path.join(wrap, "bin"), exist_ok=True)
    ee_link = os.path.join(wrap, "ee")
    if not os.path.exists(ee_link):
        os.symlink(os.path.join(tc, "ee"), ee_link)
    wrappers = {}
    for name, target in (("cc", "ee-gcc2953.exe"), ("ld", "ee-ld.exe")):
        path = os.path.join(wrap, "bin", name)
        with open(path, "w") as f:
            f.write(f'#!/bin/sh\nexec "{runner}" "{os.path.join(tc, "bin", target)}" "$@"\n')
        os.chmod(path, os.stat(path).st_mode | stat.S_IEXEC)
        wrappers[name] = path

    cflags = ("-I include -I . -Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi "
              "-DINCLUDE_ASM_USE_MACRO_INC=1 -B" + os.path.join(tc, "bin", "ee-"))
    run([sys.executable, "tools/build_text.py", "--cc", wrappers["cc"], "--ld", wrappers["ld"],
         "--cflags", cflags, "-o", "build/src/text.c.o"])

    run(exe("ee-ld.exe") + ["-T", "linker_scripts/frontbin.ld", "-o", "build/frontbin.elf"])
    run(exe("ee-objcopy.exe") + ["-O", "binary", "build/frontbin.elf", "build/frontbin.bin"])
    run([sys.executable, "tools/check_match.py", "build/frontbin.bin", "frontbin.elf", "frontbin.splat.yaml"])


if __name__ == "__main__":
    main()
