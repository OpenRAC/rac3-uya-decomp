# i5bootn.elf

`i5bootn.elf` is the bootstrap launcher: the program the disc starts first,
which loads the game. The repo builds it byte for byte like the other
executables: `make check-i5bootn` (or `make`, which builds all of them) ends with

```
MATCH: build/i5bootn/i5bootn.bin sha1 71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f (0xC5B88 bytes)
```

Every tool takes `--target i5bootn` (or `UYA_TARGET=i5bootn`); see
[`docs/targets.md`](targets.md).

## Setup

1. Put your own `i5bootn.elf` in the repo root. It is in the unpacked disc's
   `files` folder (`files\i5bootn.elf`). Its sha1 must be
   `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f`. It is gitignored; never add it.
2. `python tools/setup_asm.py --target i5bootn` writes `asm/i5bootn/`
   (gitignored).
3. `make check-i5bootn` on Windows, `python3 tools/build.py --target i5bootn`
   on Linux and macOS.
4. CI and localdecomp's Full check copy `C:\decomp-refs\asm` and
   `C:\decomp-refs\files\i5bootn.elf`, so copy `asm\i5bootn` into
   `C:\decomp-refs\asm\i5bootn`.

## Layout

One PT_LOAD at 0x800000 from file offset 0x1000. Every section sits at its own
file offset and the gaps are zeros. Nothing uses `$gp` (its `gp` in
`tools/targets.py` is 0), so the code was built with `-G0`.

| Section | Address | Size | Built from |
|---|---|---|---|
| ELF and program header | file 0x0 | 0x1000 | `asm/i5bootn/header.s` |
| `.text` | 0x800000 | 0x4FD8 | `src/i5bootn/*.c` (5 files) |
| `.data` | 0x805000 | 0x9DC | `asm/i5bootn/data/data.data.s` |
| `.rodata` | 0x805A00 | 0xBEFC3 | `rodata_a`, the jump table (`INCLUDE_RODATA`), `rodata_b`; almost all of it is the payload the launcher loads |
| `.sbss`, `.bss` | 0x8C4A00, 0x8C4A80 | | not in the file |
| `.reginfo`, `.shstrtab`, section headers | file 0xC59C4 | | `asm/i5bootn/trailer.s` |

Tables are in `targets/i5bootn/`, the linker script is
`linker_scripts/i5bootn.ld` and the splat config `i5bootn.splat.yaml`
(`global_vram_end` covers `.bss`, so splat names the `.bss` addresses the code
uses as `D_` symbols instead of writing numbers).

**The flat binary comes from `tools/elf2bin.py`, not ee-objcopy.** SN's
`ee-objcopy.exe -O binary` corrupts 21 bytes of i5bootn's section-name table
(three bytes in every 8 from file offset 0xC59E8, the same on every run). The
linked ELF is right: GNU objcopy and `elf2bin.py` both produce the retail file
from it. The trigger is the content (with other bytes in that section it
doesn't happen). `elf2bin.py` gives the same output as ee-objcopy for frontbin
and boot_elf, but those keep ee-objcopy.

## The code

199 functions:

- 147 hand-written (`ASM_FUNC`): the startup code (crt0, the ELF's entry point
  at 0x800008) and Sony's libkernl system-call stubs (`addiu $v1, $0, N;
  syscall; jr $ra`).
- 8 linker remnants.
- 44 compiled functions: libgcc (26), small libc and SIO helpers, newlib
  `exit`, a printf-style formatter, the loader and `main`. 2 are C so far
  (`main`, `func_008010F8`); the rest are `INCLUDE_ASM`.

The source-file split (5 files) and the flags in `targets/i5bootn/text_parts.txt`
are estimates from `tools/bootstrap_target.py` (the target's base flags,
`-mno-split-addresses` where the assembly looks like it). Unlike frontbin and
boot_elf, its lines don't carry `-mvu0-use-vf0-vf2`; the 2026-10-07 global
builds matched i5bootn with every VU0 range tried, so it makes no difference
here.

**Most of it was not built with our compiler.** The compiler matrix
([`docs/compiler_matrix_i5bootn.md`](compiler_matrix_i5bootn.md)) shows three
compilers in this one file:

- **libgcc** (26 functions: soft-float, 64-bit division and multiply,
  `__main`): Sony **ee-gcc 2.9-ee-991111-01** at `-O2`, from GCC 2.95's own
  source. All 26 rebuild byte for byte.
- **Small libc and SIO helpers** (8 functions, including the 3 in the
  `sibcall` bucket): the same Sony 2.9-ee-991111 family. It does make sibling
  calls; SN 2.95.3 never does.
- **newlib `exit()`**: 2.96-ee-001003-1.
- **`main` and `func_008010F8`**: our SN 2.95.3. Both are matched in C (`main`
  at `-O0` without `-fopt-stack`, a single-function override in
  `targets/i5bootn/text_parts.txt`).

So expect near misses on the library code until Sony's 2.9-ee-991111-01 is in
the toolchain; the build stays correct.

## Starting the tree again

`tools/bootstrap_target.py --target i5bootn` made the tree; it refuses to run
once any function is C. See [`docs/targets.md`](targets.md) for what it does.
