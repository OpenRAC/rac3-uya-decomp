"""regalloc.py: show how SN gcc's global register allocator treats a C function.

For register-allocation near misses (every instruction right, but a variable
ends up in another register), hand rewrites are blind: the choice depends on
numbers gcc computes internally. This compiles a snippet with `-dlg` and prints,
for each pseudo that global allocation handled, its reference count, live
length, priority and the hard register it got, in allocation order.

Background (gcc 2.95 global.c, reproduced in the Cygnus EE sources):
  - variables are allocated in decreasing priority, roughly
        refs * floor_log2(refs) / live_length
  - a variable takes the first register not conflicting with variables that are
    live at the same time and were already allocated; a parameter prefers its
    incoming register but loses it if a higher-priority local already took it.
  So if retail keeps an argument in a temporary (move $t3, $a0 at entry) while
  $a0 holds something else, some local outranked the argument and overlaps it.
  Change the C so that local has a different live range or fewer references.

Usage:
    python tools/regalloc.py scratch/func_0039BEC0.c
    python tools/regalloc.py scratch/f.c --flags "-O2 -G8 -mno-split-addresses"
The snippet should be self-contained like the ones tools/try_func.py takes
(externs, typedefs, the function); s8..f64 are provided. The default flags are
the project defaults; $UYA_TOOLCHAIN / --toolchain and $UYA_RUNNER (wibo) work as
in try_func.py. Note: this does not run the assembler, so @ps2as effects (which
globals use $gp) are not modelled; the register allocation itself is unaffected.
"""
import argparse, math, os, re, shutil, subprocess, sys, tempfile

PRELUDE = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
           "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
           "typedef float f32; typedef double f64;\n")
DEFAULT_FLAGS = "-O2 -G8 -fopt-stack -mno-check-zero-division"


def analyze(src, flags=DEFAULT_FLAGS, toolchain=None, runner=None, show=True):
    toolchain = toolchain or os.environ.get("UYA_TOOLCHAIN", "C:/tools/eegcc_2.95.3_sn_v1.36")
    runner = runner if runner is not None else os.environ.get("UYA_RUNNER")
    gcc = os.path.join(toolchain, "bin", "ee-gcc2953.exe")
    tmp = tempfile.mkdtemp(prefix="regalloc_")
    try:
        c = os.path.join(tmp, "v.c")
        open(c, "w").write(PRELUDE + src)
        cmd = ([runner] if runner else []) + [gcc, "-S"] + flags.split() + ["-dlg", "v.c", "-o", "v.s"]
        r = subprocess.run(cmd, cwd=tmp, capture_output=True, text=True)
        if r.returncode:
            print(r.stderr[:1200])
            return None
        lreg = open(os.path.join(tmp, "v.c.lreg")).read()
        greg = open(os.path.join(tmp, "v.c.greg")).read()
        asm = open(os.path.join(tmp, "v.s")).read()
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    info = {}
    for m in re.finditer(r"^Register (\d+) used (\d+) times across (\d+) insns(.*?)\.$", lreg, re.M):
        n, refs, live, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4)
        pri = (int(math.log2(refs)) if refs else 0) * refs / live if live else 0
        info[n] = dict(refs=refs, live=live, pri=pri, user="user var" in rest)
    alloc = re.search(r"regs to allocate: ([\d ]+)", greg)
    order = [int(x) for x in alloc.group(1).split()] if alloc else []
    disp_text = greg.split(";; Register dispositions:")[1].split(";; Hard regs")[0] if ";; Register dispositions:" in greg else ""
    disp = {int(a): int(b) for a, b in re.findall(r"(\d+) in (\d+)", disp_text)}
    if show:
        print("global allocation order (pseudo -> hard reg; MIPS $n, so 4=$a0, 11=$t3):")
        for p in order:
            i = info.get(p, {})
            print("  pseudo %-4d -> $%-3s refs %-3s live %-4s priority %.3f%s"
                  % (p, disp.get(p, "?"), i.get("refs"), i.get("live"), i.get("pri", 0),
                     "  (named variable)" if i.get("user") else ""))
    return order, disp, info, asm


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("--flags", default=DEFAULT_FLAGS)
    ap.add_argument("--toolchain")
    ap.add_argument("--runner")
    a = ap.parse_args()
    if analyze(open(a.file).read(), a.flags, a.toolchain, a.runner) is None:
        sys.exit(1)
