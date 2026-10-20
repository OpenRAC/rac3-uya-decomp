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

1. Put your own `i5bootn.elf` in `baserom/`. It is in the unpacked disc's
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
| `.text` | 0x800000 | 0x4FD8 | `src/i5bootn/*.c` (5 files) and `src/i5bootn/libgcc/*.c` (libgcc, 10 files) |
| `.data` | 0x805000 | 0x9DC | `asm/i5bootn/data/data.data.s` |
| `.rodata` | 0x805A00 | 0xBEFC3 | `rodata_a`, the jump table (`INCLUDE_RODATA`), `rodata_b`; almost all of it is the payload the launcher loads |
| `.sbss`, `.bss` | 0x8C4A00, 0x8C4A80 | | not in the file |
| `.reginfo`, `.shstrtab`, section headers | file 0xC59C4 | | `asm/i5bootn/trailer.s` |

Tables are in `config/i5bootn/`, the linker script is
`linker_scripts/i5bootn.ld` and the splat config `config/splat/i5bootn.yaml`
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
  `exit`, a printf-style formatter, the loader and `main`. All are C except
  newlib `exit()` (`func_008006E0`): it needs Sony's 2.96 (8-byte save slots
  and a sibling call), which exists only as a Linux build, so it stays
  `INCLUDE_ASM`. Its C (byte-identical with 2.96-ee-001003-1 `-O2 -G0`) is
  kept as a near miss outside the build.

The source-file split (5 files) and the flags in `config/i5bootn/text_parts.txt`
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
  `config/i5bootn/text_parts.txt`).

The libgcc range (0x802640 to the end of `.text`) is in `src/i5bootn/libgcc/`,
one source file per libgcc.a member, from GCC 2.95.2's own source, and is
compiled with Sony's Windows 2.9-ee-991111 through the `@ee29` pseudo-flag in
`config/i5bootn/text_parts.txt` (`tools/ee29.py`; the compiler's folder is
`C:/tools/testfolder/ee-gcc2.9-991111` unless `EE29` / `UYA_EE29` says
otherwise). See `src/libgcc/README.md`. The Windows build matches 23 of
the 26 libgcc functions directly. `__moddi3`, `__udivdi3` and `__umoddi3`
reserve stack that Sony's build left (dead slots of the inlined
`__udivmoddi4`); their files give the same frame with an unused padding local.
`__moddi3` and `__udivdi3` also need one of the two `DECOMP_UDIVMODDI4_*`
switches in `src/libgcc/libgcc2.h` (see "Patterns" below).
The small libc and SIO helpers can use `@ee29` the same way (a range override
in their own files).

## Patterns (2026-10-11)

- **A USE left by combine.** When an uninitialized union (`DIunion rr`, `ww`)
  gets its two halves assigned one after the other, combine drops the dead
  first mask and leaves a `(use (reg))` of the mask's pseudo at the block's
  label. Sony's build gave that pseudo no register (a dead stack slot, the
  "reserved stack"); the Windows 2.9-ee gives it `$v0`, which then looks live
  to the delay-slot pass and the scheduler. `__moddi3` clears `rr` first
  (`DECOMP_UDIVMODDI4_CLEAR_RR`), `__udivdi3` stores `ww`'s high word twice
  (`DECOMP_UDIVMODDI4_WW_HIGH_TWICE`); both give Sony's code.
- **The printf core (`func_00801778`).** The re-read of the next format
  character is a labelled block inside the `'e'`/`'f'` case (where retail has
  it), and the paths that already hold it in `c` skip it. The loop test reads
  into `t` and copies to `c`, with the first read before the loop and a
  statement in between, so cse keeps `t`. An empty asm on `c` in `default`
  stops gcse's copy propagation from replacing `ch` there; it emits nothing.
  The range uses `@ee29 @newas`: the default assembler puts a `nop` before
  `c.eq.s`.
- **Empty asm instead of a volatile.** `func_008014A0` and `func_00801510`
  need a delay slot that Sony's assembler filled by swapping; a non-volatile
  operation plus `__asm__("" : "+r"(x))` lets gcc's own delay-slot pass do it.

## Starting the tree again

`tools/bootstrap_target.py --target i5bootn` made the tree; it refuses to run
once any function is C. See [`docs/targets.md`](targets.md) for what it does.
