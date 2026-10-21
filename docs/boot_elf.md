# boot_elf.elf

`boot_elf.elf` is the game's main executable. The repo builds it byte for byte
the same way as `frontbin.elf`: `make check-boot_elf` (or `make`, which builds
both) ends with

```
MATCH: build/boot_elf/boot_elf.bin sha1 487975305f8a263c750dfede50391b575ed07835 (0x35EE64 bytes)
```

Every tool that works on frontbin works on boot_elf with `--target boot_elf`
(or `UYA_TARGET=boot_elf`). Where each target's files live is in
`tools/targets.py`.

Status on 2026-10-07 (`pr_check.py --target boot_elf`): 1479 functions in C,
650 INCLUDE_ASM (52.5% in C). The front end has 1376 in C and 154 left; the
engine core 103 in C and 496 left, most of it library code built with other
compilers (see "The engine core" below). `triage.py --target boot_elf` buckets
the 650 as 434 plain, 43 sibcall, 21 switch, 41 vu0, 29 mmi, 2 sys and 80 odd.
Every line in `targets/boot_elf/text_parts.txt` (core and front end) carries
`-mvu0-use-vf0-vf2`, as frontbin's do (see Toolchain-and-Build).

## Setup

1. Put your own `boot_elf.elf` in the repo root (it is in the root of the
   unpacked disc, next to `files` and `levels`). Its sha1 must be
   `487975305f8a263c750dfede50391b575ed07835`. It is gitignored; never add it.
2. `python tools/setup_asm.py --target boot_elf` writes `asm/boot_elf/` (also
   gitignored). It is the same process as frontbin's: splat, the assembler
   fix-ups, hand-written functions and linker remnants moved to
   `asm/boot_elf/handwritten` and `asm/boot_elf/remnants`, trailing padding
   cut, the data blob split around its jump tables.
3. `make check-boot_elf` on Windows, `python3 tools/build.py --target boot_elf`
   on Linux and macOS.
4. CI and localdecomp's Full check copy `C:\decomp-refs\asm`, so copy
   `asm\boot_elf` into `C:\decomp-refs\asm\boot_elf` and `boot_elf.elf` into
   `C:\decomp-refs`.

## Layout

The file is a straight memory image: every section sits at its own file
offset, and the gaps (both `.bss` regions included) are zeros. $gp is
`0x1DC8B0`, the same as frontbin.

| Section | Address | Size | Built from |
|---|---|---|---|
| header, `.reginfo` | file 0x0 | 0x2000 | `asm/boot_elf/header.s` |
| `.vutext` | 0x100080 | | `asm/boot_elf/data/vutext.data.s` (VU microcode, kept as data) |
| `core.text` | 0x116F80 | 0x264A0 | `src/boot_elf/core/*.c` (13 files) |
| `core.data`, `core.rdata`, `core.lit` | 0x13D480, 0x150080, 0x1D4D80 | | `asm/boot_elf/data/core_*.data.s` |
| `.lit`, `.data` | 0x1D5680, 0x31BE80 | | `asm/boot_elf/data/lit.data.s`, `data_a`/`data_b` around the front end's jump tables |
| `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` | 0x381000.. | | `asm/boot_elf/data/lvl_*.data.s` |
| `.text` | 0x381180 | 0x71438 | `src/boot_elf/text/*.c` (65 files) |
| `patch.data`, `legal.data`, `mc1.data` (2) | 0x3F2600, 0x1800000, .. | | `asm/boot_elf/data/*.data.s` |
| `.shstrtab`, section headers | file 0x35EA98 | | `asm/boot_elf/trailer.s` |

The tables that frontbin keeps in `tools/` are in `targets/boot_elf/`:
`src_files.txt`, `text_parts.txt`, `divs_nops.txt`, `sq_ra_funcs.txt`,
`localdecomp_flags.txt`, `symbol_addrs.txt` and `symbol_addrs_resolved.txt`.
The linker script is `linker_scripts/boot_elf.ld`, the splat config
`boot_elf.splat.yaml`.

Function names are `func_<address>` in both executables, so the same name can
mean two unrelated functions (`func_00381180` exists in both). Anything keyed
by function name is per target.

## The two code sections

**`.text` (the front end).** It is frontbin's code linked at other addresses:
1812 of frontbin's 1853 functions are the same instructions once address
immediates are masked (96% of the bytes), and only 21 frontbin functions
differ. Its source files start where frontbin's do (65 files), and every
function has the flags its frontbin twin has. `tools/seed_boot_elf.py` copied
frontbin's matched C into it (1359 functions on the first run, 1376 in C on
2026-10-07); see below. The twin of a frontbin function rewritten for the
global VU0 flag needs the same edit (`func_003B7A80`, twin of
`func_003B22C0`).

**`core.text` (the engine core).** New code, including Sony's libraries. Its
13 source files are a first cut (runs of hand-written code and runs that need
another flag set). Things to know:

- 63 core functions start on a 4-byte boundary, not 8. Each object's `.text`
  is 8-aligned, so a source file can only start at an 8-aligned function; the
  file boundaries were moved to respect that.
- Some core code switches `$gp` (`lw $gp, %lo(sym)($v0)`).
  `tools/fix_reg_names.py` no longer rewrites a load into `$gp`.
- `core.rdata` is not split: the core's jump tables sit between each source
  file's strings and constants, so splitting it means giving every piece to
  its file. That is needed before a core function with a `switch` can become
  C. Until then those stay INCLUDE_ASM.
- 43 core functions end in a sibling call (`j func_...` after the epilogue),
  which SN ee-gcc 2.95.3 never emits: those parts of the core were built with
  another compiler (Sony's 2.9-ee-991111 for the libraries, likely 2.96 for
  the newlib region; see "The engine core" below). `tools/triage.py` lists
  them as `sibcall`; see Matching-Patterns, "Code from another compiler".
- 56 core functions (0x4568 bytes) are byte-identical to objects in the
  prebuilt `libgcc.a` (C++ exception runtime, soft-float, 64-bit division);
  see [`docs/compiler_matrix_i5bootn.md`](compiler_matrix_i5bootn.md).

## The engine core: which compiler built what (2026-10-07)

Agent m1 classified the 598 core functions that were still assembly before
k1's pass, from the PsIIlib version strings, the strings each function
references, byte-identical library hits and compiler fingerprints.

**Region map**

| Address range | Contents | Compiler |
|---|---|---|
| 0x116F80-0x11F2A0 | newlib / C runtime | likely 2.96 (8-byte save slots, but 16 sibling calls and 1 tail `jal`) |
| 0x11F2A0-0x11FA10 | kernel stubs | hand-written / syscall |
| 0x11FA10-0x126020 | libkernl / libc | Sony 2.9-ee-991111 fingerprint |
| 0x126020-0x12AAE0 | libgcc (56 functions byte-identical, contiguous at 0x126020-0x12A7C8) | 2.9-ee-991111-01 |
| 0x12AAE0-0x13B330 | libcdvd, libgraph, libdma, libmc, libmtap, libpad, libvu0, libmpeg/ipu, libscf | Sony 2.9-ee-991111 fingerprint |
| 0x13B330-0x13D420 | 989snd, EE side | **SN** (8-byte slots, `$gp` use, no sibling calls, 46 tail `jal`s): matchable with our toolchain at `-O2 -G8 -fopt-stack` |

**Fingerprints**, calibrated on frontbin's 1414 C functions (known SN), on
frontbin sources recompiled with SN, 2.96, 2.9-991111-01 and 3.2, and on the
56 libgcc hits:

| Fingerprint | SN | 2.96 / 3.2 | 2.9-991111-01 and libgcc |
|---|---|---|---|
| 16-byte save slots | 0-2% | 0% | 99-100% |
| `$ra` restored before the s-registers | 4-7% | 9-11% | 99-100% |
| Sibling calls | 0% | 11-12% | 10% |
| Tail call left as `jal` + epilogue | 15-20% | 3% | 4% |
| `$gp` data access | 35-42% (at `-G8`) | about 0-3% (at `-G0`) | about 0-3% (at `-G0`) |

`sd` versus `sq` saves and `daddu` moves don't separate the compilers (SN
without `-fopt-stack`, and Sony's 2.95.x builds, use `sq` with 16-byte slots).

**Classes** (per function in m1's `core_classified.tsv`):

| Class | Functions | Bytes |
|---|---|---|
| Library, 2.9-ee-991111 fingerprint | 196 | 0x1164C |
| Library, region only | 139 | 0x3A40 |
| Library, libgcc exact | 56 | 0x4568 |
| Library, sibling call | 46 | 0xE28 |
| Hand-written / asm | 53 | 0x648 |
| Likely 2.96 | 40 | 0x5EC0 |
| Likely SN | 57 + 5 region only | 0x1D2C |
| Unknown (frameless leaves) | 6 | 0x78C |

- **Likely SN** (989snd, 62 functions, 0x13B330 to 0x13D3D0): the key
  internals are `func_0013C578` (IOP command send) and `func_0013C348`; most
  of the small 0x24-0x3C wrappers call one of those two. Start core work here.
- **Likely 2.96** (40; needs a 2.96 compiler option): `func_00116FD0`,
  `func_001173F8` (0x1264 bytes), `func_001197E0`, `func_0011A328` to
  `func_0011B460`, `func_0011BD9C`, `func_0011C008` to `func_0011E8C0`
  (including `func_0011C180`, 0xBF8, and `func_0011CEF0`, 0x1670). Test one
  2.96-like function first to confirm the verdict.
- **Unknown**: `func_0011B610`, `func_0011B754`, `func_0011B868`,
  `func_0011B9A0`, `func_0011BB58`, `func_0011BD14`.
- `libstdc++.a` has no non-trivial hits. 61 more one- to three-instruction
  stubs equal generic libgcc stubs, which is not evidence. Only the
  2.9-991111 (Windows) build ships these archives. The other near hits are
  coincidences, except possibly the dtoa helpers at 0x11A5D8.

The `@ee29` pseudo-flag in `text_parts.txt` now compiles a range with Sony's
Windows 2.9-ee-991111 (`tools/ee29.py`, [Toolchain and
Build](wiki/Toolchain-and-Build.md)). The libgcc range 0x126020-0x12A948 uses
it: `src/boot_elf/core/libgcc/`, one file per `libgcc.a` member, built from
GCC 2.95.2's own source (shared headers in `src/libgcc/`, see its README).
54 libgcc functions are C that way (`__main.o`, `_divdi3`, `_fixunsdfdi`,
`_floatdidf`, `_muldi3`, `_pure.o`, all of `dp-bit.o` and `fp-bit.o`, 17 of
`_eh.o`'s entries (built with `-fexceptions`, as GCC's own build does for
`L_eh`) and 11 of `frame.o`'s). `__moddi3`, `__udivdi3` and `__umoddi3` only
match with the Linux 2.9-ee-991111-01. Still assembly: `_eh.o`'s
`copy_reg`, `throw_helper`, `__throw` and `__rethrow` (no 2.9-ee build gives
them; `__rethrow` crashes both 2.9-ee compilers here), and `frame.o`'s
`execute_cfa_insn` (its switch table is in `.rdata`, which is still one asm
blob). Unlike
i5bootn, the linker filled the gaps between modules with `0xCDCDCDCD`; those
words are `INCLUDE_ASM` pieces at the end of each module file, so every file
starts and ends where its object does. The rest of the core (about 380
functions built with 2.9-ee-991111-01 or 2.96) still needs those compilers. OpenRAC's
rac1-decomp already has those sources set up (`src/libgcc/`, one object per
`L_` module, a per-file compiler column in its Makefile); built from them with
the Linux 2.9-ee-991111-01 driver, `_divdi3.o`, `_moddi3.o`, `_udivdi3.o` and
`_umoddi3.o` are word-for-word identical to Sony's `libgcc.a` members. See
[Cross-repository resources](wiki/Cross-Repository-Resources.md).

## Matching the core (k1, 2026-10-07)

Agent k1 took 200 small plain core functions: **102 matched, 15 near misses,
83 skipped.** No inline asm, no j-form, no `volatile`. Five need
single-function overrides: `func_00122278`, `func_0013A9F0` and
`func_00136010` match only with the default zero-division check (no
`-mno-check-zero-division`), and `func_0013CEF8` and `func_0013D290` need
`-mno-split-addresses`.

The 83 skips agree with m1's classification; the signs (details in
Matching-Patterns, "boot_elf's engine core"):

| Reason | Functions |
|---|---|
| each saved register in its own 16-byte `sd` slot, `$ra` highest | 30 |
| sibling calls | 18 |
| short loop with an empty delay slot, padded with `nop`s to 7 words | 10 |
| newlib reent wrappers (`&errno` kept as a full address) | 6 |
| varargs FP register saves (none or all eight; ours saves four) | 5 |
| alignment `nop` after `b` | 4 |
| `$gp` stored or reloaded | 4 |
| other (`pref` remnant words, a 4-byte function, `mult $0` + `mflo`, one not tried) | 6 |

In 0012E9D8, 00124C50 and the 0013AA40/0013AAA8 pair the frame is the only
difference. The near misses (drafts with headers in k1's bundle) include the
`func_0012FC78` family (`func_0012FC78`, `func_0012F470`, `func_0012FC18`,
`func_0012F5A8`), where gcc's global allocator records a conflict between a
value and `$a2` for no visible reason, and several newlib functions
(`func_0011A718`, `func_0011B018`, `func_0011B060`, `func_0011ABB8`,
`func_0011A328`) that look like library code too.

## Compiler ranges in text_parts.txt (2026-10-20)

`targets/boot_elf/text_parts.txt` now gives the core's flags by range, one
line per compiler, instead of one override per function:

| Range | Compiler | text_parts.txt |
|---|---|---|
| 0x116F80-0x11EA10 | newlib, Sony ee-gcc **2.96-ee-001003-1** | SN's flags (2.96 has no Windows build; see below) |
| 0x11EA10-0x11F2A0 | hand-written kernel stubs (`ASM_FUNC`) | SN's flags (unused) |
| 0x11F2A0-0x13B330 | Sony's libraries and libgcc, ee-gcc **2.9-ee-991111** | `@ee29 -O2 -G0` (libgcc keeps its lines; `_eh.c` adds `-fexceptions`) |
| 0x13B330-0x13D420 | 989snd's EE side, **SN** ee-gcc 2.95.3 | SN's flags, as before |

How the verdicts were checked:

- **2.9-ee.** Every C function of 0x11F2A0-0x13B330 was compiled again with
  `@ee29 -O2 -G0`: 225 of 231 match that way too, so the old SN lines and
  one-function `@ee29` overrides (162) went. Six match only with SN and keep
  a single-function override (`func_00124560`, `func_0012D650`,
  `func_00135C10`, `func_00135E40`, `func_00136010`, `func_0013A8E8`). The
  2.9-ee fingerprint (16-byte `sd` slots, `$ra` highest and restored first,
  no `$gp`, sibling calls) holds in every object of the range.
- **2.96.** newlib's `isinf` and `isnan` (`func_0011B018`, `func_0011B060`)
  compile byte for byte with 2.96-ee-001003-1 at `-O2 -G0` from fdlibm's own
  text, and with neither SN nor 2.9-ee (12 and 14 instructions differ). The
  drafts are in `nonmatching/boot_elf/`. To run the Linux 2.96 under WSL,
  copy the compiler and the source into WSL's own file system (`/tmp`): its
  32-bit `cc1` can't open files on `/mnt/c` ("Value too large for defined
  data type", then an internal error in `init_c_lex`).
- **SN.** 989snd uses `$gp`, 8-byte slots and no sibling calls, as the game
  does; its remaining `func_0013CB20` is a 2-instruction near miss
  (`nonmatching/boot_elf/`), and `func_0013D3D0` is hand-written: it is the
  `srand` of the hand-written `rand` that follows it (same seed, same `$8`).

**Object boundaries.** The original linker filled the gap between two
objects' `.text` with `0xCDCDCDCD`; inside an object the padding is `nop`.
So every `CDCDCDCD` word in the core is the end of an object (82 of them),
which gives most of the real source-file split (a file that ends 8-aligned
leaves no fill word). splat had glued nine of these words onto the front of
the next function; each is now its own 4-byte `INCLUDE_ASM` piece in front
of the real function (`func_00117170`, `func_00118670`, `func_001192F0`,
`func_0011BD18`, `func_0011BDA0`, `func_0011E800`, `func_0012CB88`,
`func_0012CE48`, and `func_00137448`, a remnant). The VU0 helpers at
0x12FE78, 0x12FED8 and 0x12FF08 began with linker remnants; the remnants
are `LINKER_REMNANT`s now and the functions start at 0x12FE98, 0x12FEF0
and 0x12FF10. After pulling this, run `python tools/setup_asm.py --target
boot_elf` (and refresh `C:\decomp-refs\asm\boot_elf` for CI).

**Veldin's calls into the core.** Ten call targets in Veldin were not a
`func_` start in boot_elf: 0x11BD18, 0x12CB88, 0x12CE48, 0x12FE98 and
0x12FF10 were the glued functions above (now split); 0x128F28, 0x128F90,
0x1294B8, 0x1295C0 and 0x129A18 were already function starts, libgcc's
`dpsub`, `dpmul`, `dpcmp`, `dptoli` and `fptodp` (C under those names in
`src/boot_elf/core/libgcc/`).

**Matching with 2.9-ee: what helped.**

- 2.9-ee makes a sibling call only when the call's value is not returned:
  `return f(x);` in an `int` function is `jal` and an epilogue, `f(x);` in a
  `void` one is `j f`. A wrapper that ends in `j` is a `void` function (a
  caller that uses the value gets an alias with the other type, e.g.
  `func_00139F80_0013A0F8`).
- One 2.9-ee slice now holds a whole library file, so every declaration in
  the file has to agree with the definitions: an earlier block's
  `extern void f(void);` for a function defined later as `int f(int)` is an
  error, not a warning. Make the extern follow the definition (callers that
  ignore the value compile the same), or give the block an alias.
- Store/load order follows the types: a pointer field and an `int` field are
  in different alias sets, so 2.9-ee moves a load across the store
  (`func_00122780` needed `void *` fields where retail moves the load).
- Whether a callee returns a value changes register choice in the caller
  (`func_00122AE0` needs `func_0011EE60` as `s32`, through
  `func_0011EE60_00122AE0`).
- Busy-wait loops: retail's `lui` before the loop label and `addiu -1`
  inside is `i = 0x100000; while (--i != -1);`.
- `$gp`-switching callbacks (`func_0012ADC8`, `func_00135D50`,
  `func_00135DC8`) and the handler tables that store `$gp`
  (`func_00121B70`, `func_00135D08`) read or write `$gp`, which C can only
  do with inline assembly; they are still assembly.

Status (`tests/check_repository.py`, 2026-10-20): boot_elf 1867 functions in
C and 245 INCLUDE_ASM (1826 and 279 before this work). 41 of the new ones are
2.9-ee library functions (231 C functions in that range before, 272 after);
near misses are in `nonmatching/boot_elf/`.

## Seeding from frontbin

```
python tools/seed_boot_elf.py                                    (Windows)
python3 tools/seed_boot_elf.py --toolchain ~/sn --runner ~/bin/wibo   (Linux/macOS)
```

It pairs frontbin's functions with their boot_elf twins, builds a frontbin to
boot_elf address table from the paired assembly (3709 addresses, plus
neighbour shifts for addresses the assembly never shows), renames every
`D_`/`func_` in each matched frontbin block, inserts it in place of the
twin's INCLUDE_ASM, refreshes the declarations and symbols, then builds and
compares every seeded function with retail. Whatever doesn't match goes back
to INCLUDE_ASM until the build prints MATCH. Functions already C in boot_elf
are left alone, so **rerun it whenever frontbin gains matches**. It needs both
ELFs and both asm trees.

On 2026-10-07 a rerun carried 17 more frontbin matches over.

The first run seeded 1359 of 1386 candidates. 27 went back to INCLUDE_ASM:
`func_0039DB38` (its typedef `Pad_39DB38` belongs to a function that differs
in boot_elf) and 26 that compile but differ. They are worth a look: the
frontbin C is a good starting point.

`tools/bootstrap_boot_elf.py` is the one-time script that made the first
tree (pairing, file split, flags, `divs_nops`/`sq_ra_funcs` carried over). It
is kept as a record; don't rerun it on a tree with work in it.

## localdecomp

The dropdown at the top of the function list picks the executable. Each one
has its own list, progress bar, editor cache (`.localdecomp_work/boot_elf/`)
and Save target; Full check builds and compares everything and shows the
numbers for the executable that is picked.

## Progress report

`objdiff.json` has one unit per source file, `boot_elf/core/<file>` and
`boot_elf/text/<file>` (`python tools/gen_objdiff_units.py` writes them for
every target), in the progress categories `boot_elf`, `boot_elf_core` and
`boot_elf_frontend`. They replace the old reference-only `exes/boot_elf`
code unit; `exes/boot_elf (data)` stays.

All units of the three executables the game runs to reach the main menu
(i5bootn, boot_elf and frontbin, code and data) are also in the `menu`
category, "Menu (i5bootn + boot_elf + frontbin)", so it has one progress bar.
`boot_elf_core` is shown as "Engine (boot_elf core)" and frontbin's
`frontend` as "Front end (frontbin)".
