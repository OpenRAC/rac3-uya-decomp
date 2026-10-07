#!/usr/bin/env python3
"""build.py: the Makefile's `check` target in Python, for Linux and macOS.

On Windows, use the Makefile (SN's make.exe). This script runs the same steps
for systems where make.exe's cmd.exe syntax doesn't work, running the Windows
toolchain through wibo (https://github.com/decompals/wibo):

  1. assemble the raw header blobs and the data segments (bin/ee-as.exe):
     every build/.../*.s.o object the target's linker script names
  2. build each code section's sources with tools/build_text.py (per-file,
     per-function flags)
  3. link with the target's linker script, objcopy to a flat binary
  4. tools/check_match.py: prints MATCH or the first differing offsets

    python3 tools/build.py --toolchain ~/sn --runner ~/bin/wibo
    python3 tools/build.py --target boot_elf --toolchain ~/sn --runner ~/bin/wibo
    python3 tools/build.py --target all --toolchain ~/sn --runner ~/bin/wibo

The toolchain folder must have the Windows layout (bin/ee-gcc2953.exe,
bin/ee-as.exe, bin/ee-ld.exe, bin/ee-objcopy.exe, ee/bin/Ps2EeAs.exe).
build_text.py derives the toolchain root from the compiler path, so this
script writes small wrapper scripts into build/wrap/ that call wibo.
"""
import argparse, os, re, stat, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402
ASFLAGS = ["-I", "include", "-EL", "-mips3", "-mcpu=5900", "-mabi=eabi"]


def run(cmd, **kw):
    print("+", " ".join(cmd))
    p = subprocess.run(cmd, cwd=ROOT, **kw)
    if p.returncode:
        sys.exit(f"failed: {' '.join(cmd)}")


def main():
    t = targets.from_argv(allow_all=True)
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"), required="UYA_TOOLCHAIN" not in os.environ)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER", "wibo"))
    args = ap.parse_args()
    tc = os.path.abspath(os.path.expanduser(args.toolchain))
    runner = args.runner
    exe = lambda name: [runner, os.path.join(tc, "bin", name)]

    build = os.path.join(ROOT, t.build_dir)
    os.makedirs(os.path.join(build, "src"), exist_ok=True)

    # 1. the asm-built objects are whatever the linker script links:
    #    <build_dir>/<path of the .s>.o
    script = open(t.path("ld")).read()
    prefix = t.build_dir.replace("\\", "/").rstrip("/") + "/"
    for obj in dict.fromkeys(re.findall(r"(%s(?:asm/\S+?\.s)\.o)" % re.escape(prefix), script)):
        src = obj[len(prefix):-2]
        os.makedirs(os.path.join(ROOT, os.path.dirname(obj)), exist_ok=True)
        run(exe("ee-as.exe") + ASFLAGS + ["-o", obj, src])

    # Wrappers live inside a fake toolchain tree (wrap/bin/...) with ee/ linked
    # to the real one, so build_text.py's "<root>/ee/bin/Ps2Ee" still resolves.
    wrap = os.path.join(ROOT, "build", "wrap")
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

    # 2. one relocatable object per code section
    cflags = ("-I include -I . -Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi "
              "-DINCLUDE_ASM_USE_MACRO_INC=1 -B" + os.path.join(tc, "bin", "ee-"))
    for u in t.units:
        run([sys.executable, "tools/build_text.py", "--target", t.name, "--unit", u.name,
             "--cc", wrappers["cc"], "--ld", wrappers["ld"], "--cflags", cflags, "-o", t.obj(u)])

    # 3. link, flatten, compare
    elf = os.path.join(t.build_dir, t.name + ".elf")
    binf = os.path.join(t.build_dir, t.bin_name)
    run(exe("ee-ld.exe") + ["-T", t.ld, "-o", elf])
    if getattr(t, "flatten", "objcopy") == "elf2bin":
        run([sys.executable, "tools/elf2bin.py", elf, binf])
    else:
        run(exe("ee-objcopy.exe") + ["-O", "binary", elf, binf])
    run([sys.executable, "tools/check_match.py", "--target", t.name, binf, t.elf, t.yaml])


if __name__ == "__main__":
    main()
