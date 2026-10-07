# Compiler matrix: i5bootn (2026-10-07)

Which compiler built i5bootn's compiled code. Same 13 GCC builds as the
frontbin matrix ([compiler_matrix_findings.md](compiler_matrix_findings.md)),
but with real or near-original source instead of our own matched C.

## Result

i5bootn was linked from objects built by **three different compilers**:

| Code | Functions | Compiler | Evidence |
|---|---|---|---|
| libgcc: soft-float (`dp-bit.o`, `fp-bit.o`), 64-bit division and multiply, `__main` | 26 | **Sony ee-gcc 2.9-ee-991111-01** (also 991111a and -dtls13010, which give the same output), `-O2` | all 26 byte-identical from GCC's own source (below) |
| small libc and SIO helpers: `memcpy`-style copy loops, SIO `putc` and its `\n` to `\r\n` wrapper, `_exit` and its two jump stubs, a printf output callback | 8 | **Sony 2.9-ee-991111** family, `-O2` | 8 byte-identical from drafted C |
| newlib `exit()` (`func_008006E0`) | 1 | **2.96-ee-001003-1**, `-O2` | byte-identical from newlib's `exit.c`; no other build matches |
| `main` (`func_00800698`) | 1 | **SN 2.95.3** (or Sony 2.95.3-136), **`-O0`** without `-fopt-stack`, with SN's assembler | byte-identical: `sq $fp` frame, unfilled delay slots |
| `func_008010F8` (a `if (f() == 0x2000000) g(); else h();` dispatch) | 1 | SN 2.95.3 / 2.95.3-136 at `-O1`..`-O3`, or 2.96 at `-O1` | byte-identical; the 2.9 builds turn it into sibling calls |

`main` and `func_008010F8` were built with the same SN compiler as frontbin,
so they are most likely the launcher's own code. The rest is library code that
came prebuilt.

The 4 still open: `func_00801510` (double to int with rounding), the two
varargs printf wrappers (`func_008024B8`, `func_00802508`; our minimal
`stdarg.h` is not Sony's `va-mips.h`, so they can't match yet) and the 0xD14-byte
printf core (`func_00801778`), which wasn't drafted. `func_00800488` (0x210,
MMI) wasn't drafted either.

### Correction: sibling calls are not a "later compiler" sign

The `sibcall` bucket and the docs said a `j func_` tail call meant Sony 2.96 or
3.2. That was wrong: Sony's **2.9-ee-991111** builds emit sibling calls too
(`func_008007C8` and `func_008014D8` match with them and with nothing newer).
What the matrix shows is narrower: **SN 2.95.3 never does**, so a sibling call
means "not our compiler" (in practice, Sony's 2.9-ee-991111, a library
compiler). The docs and `tools/triage.py` now say that.

## The libgcc result in detail

28 of i5bootn's 44 compiled functions are byte-identical (relocations masked)
to objects in the prebuilt `libgcc.a` that ships with both SN 2.95.3 v1.36 and
Sony 2.9-991111. Two of those are 2-instruction jump stubs that only look like
`__pure_virtual`; the other 26 are real libgcc functions. Rebuilding them from
source pins the compiler:

- `fp-bit.c` from **GCC 2.95.x** (identical in 2.95.0 to 2.95.3), compiled twice
  (`dp-bit` without, `fp-bit` with `-DFLOAT`) with `-DUS_SOFTWARE_GOFAST`
  (the `dpadd`/`fptodp` names) and `-DFLOAT_BIT_ORDER_MISMATCH` (bitfield
  pack/unpack), plus one Sony change: `unpack_d`/`unpack_f` treat every zero
  exponent as zero (no denormals on the EE). It is the later `NO_DENORMALS`
  option, written as `if (fraction == 0 || 1)`; dropping the denormal branch
  outright leaves one `nop` different.
- `libgcc2.c` from GCC 2.95.2 with `-DL_muldi3`, `-DL_divdi3`, `-DL_moddi3`,
  `-DL_udivdi3`, `-DL_umoddi3`, `-DL_fixunsdfdi`, `-DL_floatdidf`, `-DL__main`.
- `-O2 -G0`, either assembler.

| Compiler | libgcc, 26 functions | drafted C, 14 functions |
|---|---|---|
| Sony 2.9-ee-991111-01 / 991111a / -dtls13010 | **26** | 8 |
| Sony 2.9-ee-991111 (Windows) | 23 | 8 |
| Sony 2.9-ee-990721 | 17 | 5 |
| SN 2.95.3 v1.36 (ours) | 8 | 2 |
| Sony 2.95.3-136 | 8 | 2 |
| Sony 2.95.3-107, -114, 2.95.2-273a, -274 | 5 | 0 |
| 2.96-ee-001003-1 | 0 | 1 |
| GCC 3.2-040921 | 0 | 0 |

Best flag set for each row: `-O2` (`-O3` gives the same here), and `-O0` for
`main`. Other source versions tried for `fp-bit.c`: egcs 1.0.3, 1.1.x (worse),
GCC 3.0 and 3.2 (don't build without their newer headers; not needed once 2.95
matched).

## Also: boot_elf's engine core

The same `libgcc.a` comparison on boot_elf finds **56 core functions (0x4568
bytes)** byte-identical to libgcc objects: the C++ exception runtime (`_eh.o`,
16), `dp-bit.o` (14), `frame.o` (12), `fp-bit.o` (5) and the 64-bit division
and multiply helpers. None in the front end. They can be built the same way
(GCC 2.95 source, 2.9-ee-991111-01) once that compiler is in the toolchain.

## Method

- Compilers: the builds from `C:\tools\testfolder` (Linux ELF builds run
  natively, Windows builds through wibo), each with its own `-B` lib directory.
- Flag sets: `-O0` to `-O3`, each with and without `-mno-split-addresses`,
  always `-G0` (nothing in i5bootn uses `$gp`).
- Assembly: `-S`, then one common assembler for every compiler (2.96's GNU
  `ee-as`, and in a second pass SN's `bin/ee-as.exe`, the project's). Output
  that trips the EE short-loop check goes through `tools/asm_filter.py` first.
- Comparison: every function word by word against retail i5bootn.elf,
  relocated fields masked, trailing zero padding ignored; a similarity score
  (instruction sequence match) for the ones that don't match.
- `.mdebug.eabi64`: i5bootn.elf has this (empty) section; of all 13 builds
  only 2.96 and 3.2 emit it, which fits `exit()` being a 2.96 object.

The harness, the corpus and the raw results are in
`C:\tools\testfolder\i5bootn_matrix\` on Nathan's machine (not in the repo:
the libgcc comparison reads the compilers' own archives).

## What this means for matching i5bootn

- The 26 libgcc functions can become C, from GCC 2.95's own source, as soon as
  the toolchain can compile a file with Sony's 2.9-ee-991111-01 (a per-file
  compiler pseudo-flag in `text_parts.txt`, like `@ps2as` picks an assembler).
  That build exists only as a Linux binary here; the Windows 2.9-991111 gets
  23 of 26. Until then they stay assembly.
- The 8 small library functions above match with the same compiler.
- `main` and `func_008010F8` are matched in C now, with our toolchain: `main`
  at `-O0 -G0 -mno-check-zero-division` (no `-fopt-stack`: that packs the frame
  and loses the `sq $fp`), a single-function override in
  `targets/i5bootn/text_parts.txt`; `func_008010F8` with its file's flags.
