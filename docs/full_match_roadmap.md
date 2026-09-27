# Road to 100%: blockers and plan

Status on 2026-09-26. `python tools/triage.py` prints the current numbers.

> **Update 2026-09-27:** the handwritten (100) and remnant (203) buckets are done: they moved to `asm/handwritten/` and `asm/remnants/`, included with `ASM_FUNC` / `LINKER_REMNANT`, and count as finished in objdiff. Current state: 763 functions in C, 303 assembly sources, 779 still to match (655 plain, 31 switch, 72 vu0, 14 mmi, 7 other). `python tools/triage.py` has live numbers.

## Where we are

The build has matched byte for byte since the start. The goal is to have every function come from real source: C for compiled code, `.s` for code that was assembly in the original.

| | Functions | Bytes of `.text` |
|---|---|---|
| In C | 695 | about 0xAB00 (10%) |
| Still `INCLUDE_ASM` | 1,150 | about 0x65200 (90%) |

The functions matched so far are the small ones (63 bytes on average). What's left averages about 380 bytes, so measure progress by bytes, not by function count.

## Remaining functions by bucket

| Bucket | Functions | Bytes | What it needs | Status |
|---|---|---|---|---|
| plain | 691 | 0x34CE8 | Ordinary matching. 428 are under 0x100 bytes. | The main workload |
| switch | 30 | about 0xC7F0 | Jump tables in the right place | **Unblocked**: `tools/migrate_jtbls.py`; first C switch is `func_003B0FC8` |
| vu0 | 101 | about 0x9680 | Inline asm for the VU0 parts, as the original had | **Unblocked**: pattern proven with `func_00388698` |
| mmi | 16 | 0x36E0 | EE 128-bit instructions | Probably inline asm like VU0; untested |
| sys | 2 | 0x44 | COP0 / sync | Inline asm |
| float-nop | 1 | 0x34 | `lwc1` from `$gp` then `nop` | Open problem |
| odd | 5 | 0xEC | Bad function boundaries (0x3CC880 to 0x3CD510) | Fix the split |
| handwritten | 100 | 0x15E48 | Nothing to decompile: the original was assembly | Mechanical: move to `.s` files |
| remnant | 203 | 0xFE4 | Nothing: linker leftovers, not source | Mechanical: emit as data |

Handwritten functions and remnants are 22% of the remaining bytes and need no matching at all, just a clean home in the source tree.

## Findings behind the table

### Jump tables (fixed)

All 47 switch tables sit in one block at the start of `.data` (0x317FE0 to 0x318CB0). They are 16-byte aligned, in exactly the order of the functions that use them, and fenced by the original linker's `0xCDCDCDCD` fill on both sides. That block is every source file's read-only data, concatenated in link order.

gcc writes its tables with `.rdata` / `.align 4`, which the assembler files under `.rodata`. So the fix is:

- the data blob is split into `data_a` and `data_b`;
- `text.c.o(.rodata)` is linked between the two halves;
- asm functions pull their tables into `text.c` with `INCLUDE_RODATA`.

Converting a function means deleting its `INCLUDE_ASM` and `INCLUDE_RODATA` lines together. Verified: full build `MATCH` with `func_003B0FC8` in C.

Before this fix, the linker script discarded `text.c.o(.rodata)`, so no function with a `switch` could have matched.

### Linker remnants

Retail has 619 single instructions, each followed by a `nop`, sitting between functions. They are in 203 splat "functions" with no return and no references. 449 of them are `addiu $sp, $sp, N`, the last instruction of an epilogue.

They are what the original linker left when it stripped unused functions. It removed each function's bytes down to an 8-byte boundary, so for functions with an odd instruction count the final instruction and its alignment `nop` stayed behind. They cluster at source file boundaries (for example `0x37D1A0`, just before the known boundary at `0x37D1A8`).

They can't come from C with our GNU linker. Emit them as data words.

### Handwritten assembly

spimdisasm flags 100 functions as handwritten: they use `addi`, `$at` and loop shapes gcc never emits. Examples are the memset-style loops at 0x388418 and 0x388440 and the hardware wait loops around 0x3D6BC0. They move to `.s` files. They are also why `tools/fix_short_loops.py` exists: the default assembler would pad their short loops, but compiled C never hits this, because gcc emits its loops in noreorder mode.

### VU0

VU0 macro instructions (`lqc2`, `vmul`, `qmtc2`...) appear in 101 compiled functions. The original used inline asm inside C functions, and that matches: with `__asm__ __volatile__` and explicit `$vfN` registers, the default assembler even moves the last instruction into the `jr` delay slot like retail. See [Matching patterns](wiki/Matching-Patterns.md#vu0-code-inline-asm).

### Floats through `$gp`

The 232 `lwc1 ...($gp)` loads in retail read small-data variables, not literals. 220 are in frontbin's `.lit` segment, 8 in the main executable's small data, and 4 just past `.lit` in the `.bss` range. Declare them sized. Constants in the source come out inline and need `@ps2as`. Only the loads followed by a `nop` are unexplained.

### Source file boundaries

For a later "real source files" pass (not needed for 100% C), boundaries can be recovered from:

- the split/no-split address runs;
- the linker remnants at file ends;
- the `0xCD` fills between output sections (8 in `.lit`, 3 in `.data`, 1 in `.text` at 0x39B1A0);
- the order of jump tables and small data, which follows file order.

## Year-end plan

About 14 weeks remain. The compiled buckets (plain, switch, vu0, mmi, sys) are about 840 functions and 0x4E000 bytes, roughly 7 times the bytes matched so far. That needs about 60 functions a week, weighted toward bigger ones.

1. **October: clear the mechanical buckets and the small plain functions.**
   - Remnants become data, and handwritten functions move to `.s` (this removes 303 entries).
   - Fix the 5 bad splits.
   - Run agent batches on the 428 plain functions under 0x100 bytes.
2. **November: medium work.**
   - Plain functions from 0x100 to 0x400 (about 225).
   - The 30 switch functions and 101 VU0 functions, now that both patterns work.
   - Test the MMI group.
3. **December: the long tail.**
   - The 20 plain functions over 0x400 bytes.
   - Register-allocation stragglers like `func_0039BEC0`.
   - The open problems: the `lwc1`/`nop` load, 64-bit constants, and `div.s` padding (lead: Ps2EeAs's DIV padding).

Honest risk: the last 5 to 10% (large functions and register-allocation holdouts) is where schedules slip. Keep the build matching at every step, so a partial result is always usable.

## A playable main menu

`frontbin.elf` is not a program. It is a **level overlay**, the "front end level", with the same layout as the level files (`lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl`). The main executable (SCUS_973.53) loads it on top of itself at 0x1D5680 and calls its entry at 0x37D200. It depends on that executable for almost everything:

| Dependency on the main executable | Count |
|---|---|
| Functions it calls directly | 132 distinct, 571 call sites in 166 functions |
| Main-executable globals it reads or writes | 253 via `lui` (1,387 references in 368 functions) plus 240 `$gp` accesses |
| Indirect calls (function pointers, vtables) | 272 |

It also talks straight to the hardware:

- DMA channels (0x1000xxxx), GS registers (0x12000000) and the scratchpad (0x70000000, 819 references);
- VU0 in macro mode (101 functions).

The menu's textures, fonts and sounds are loaded from the disc by the main executable.

So a native `.exe` cannot be built from `frontbin.elf` alone. The routes:

1. **Modded menu running in PCSX2 (reachable this year).** Our build already produces a byte-identical `frontbin.elf`. Change the C, rebuild, and put the file back into your own disc image or load it with an emulator patch. This is how most decomp projects become "playable" first. It needs a small repacking step (for example with Wrench).
2. **Static recompilation (separate track).** Recompile both the main executable and frontbin to native code with a PS2 recompiler plus a runtime that emulates GS, VU1 and IOP. The decomp helps (names, types), but doesn't have to be complete.
3. **True native port (multi-year).** Decompile the parts of the main executable that frontbin reaches: the renderer and VU1 microcode path, file and WAD loading, pad input, the sound RPC to the IOP, memory management, and whatever those call in turn. Then replace the hardware layer (GS packets, DMA, VU0/VU1) with a PC backend. The first step would be splitting and triaging SCUS_973.53 the same way as frontbin, to measure the transitive closure of those 132 functions.

Recommendation: make "100% C frontbin, byte-identical" plus "modified menu boots in PCSX2" the year-end goals. Treat the native menu as next year's project, starting with the main executable.

## Update 2026-09-27: blocker pass

`python tools/pr_check.py`: 763 functions in C, 139 `ASM_FUNC`, 204 `LINKER_REMNANT`, 740 `INCLUDE_ASM` left. 1,106 of 1,846 entries (59.9%) are final source.

- **Context-aware single-function builds (done).** `tools/try_func.py` and the localdecomp server compile a function with the declarations from earlier text.c parts (`build_text.function_context`), so a block that matches alone also compiles in the full build. All 764 C blocks re-verified with it.
- **`$gp` register hacks (done).** No `register char *_gpreg` or `#define X (*(T *)(_gpreg + off))` macros remain. The six affected functions use plain sized externs. Remaining inline asm is either VU0/COP0 code (original was inline asm too), the `sqrt.s` helper in func_003BF778 (retail's two nops before `sqrt.s` come from the original's inline asm), or two small register fences (func_0037DF98, func_003A5608) that no C variant tried so far reproduces.
- **Bad splits 0x3CC880 to 0x3CD548 (done).** The range is one hand-written VU0 clipper (register calling convention through `jalr $9`, `$at` as data, shared labels across the splat "functions"). All 11 pieces are now `ASM_FUNC`. Re-splitting would only rename symbols, so the boundaries are left as splat found them.
- **Trailing padding (done).** 17 functions are followed by more nops than gcc's 8-byte alignment adds. `TEXT_PADDING(N)` (include/include_asm.h) now sits after each of them in text.c and the extra nops were cut from their `.s`, so converting one to C needs nothing special. `python tools/trailing_padding.py` reports new cases, `--apply` fixes them. func_003ECDF0 (the last function, which ends in data) is not covered.
- **Hand-written leaves (done).** 28 more functions moved to `asm/handwritten`: `$at` used as a data register (`mfc1 $at`, `qmtc2 $at`, `lw $at`, `dsrl32 $at`), `mtc1`/`ppacb`/`mul.s` in the `jr $ra` delay slot, `adda.s` rounding tricks, DMA/VIF wait loops. Also func_003BE3A0 was a remnant hand-typed as top-level asm; it is now a `LINKER_REMNANT`.
- Retail's `lwc1 ...($gp)` then `nop` pattern (func_003882D0 and neighbours) sits between hand-written functions and is probably hand-written too. They match as C with one `nop`, so they stay C.

## Update 2026-09-27 (later): unsolved list #1 to #6

1. **Register/scheduling near misses: permuter set up.** `tools/permuter_setup.py` prepares a decomp-permuter directory for any function (see `docs/permuter.md`). It runs at about 25 candidates a second on two cores. First runs: func_0037DF98 stayed at 2 register diffs after 15,000 candidates; func_003E1D18 went from 265 to 35.
2. **Float multiply-add: hand-written.** SN's cc1 has no patterns for `adda.s`, `mula.s`, `madda.s` or 3-operand `madd.s`, so no C produces them. func_00388730 and func_003883F8 are now `ASM_FUNC`, like func_003882E0/318/350 before them.
3. and 4. **`nop`s before `div.s`/`sqrt.s`: still open, now measured.** 129 `div.s`/`sqrt.s` in unmatched functions have two `nop`s in front, 15 have one, 55 have none, sometimes in the same function. No flag, `-m` option or assembler in the toolchain set (ee-as, Ps2EeAs, as.exe, `-mfix4300`, `-mips1`...) inserts them. Plain C gets every other instruction of func_003E1D18 right, including load order and registers, which suggests the padding is added after the compiler. An inline-asm `nop; nop; div.s` helper (the pattern func_003BF778 uses for `sqrt.s`) gets within 5 diffs but changes the scheduling. The one-nop and no-nop cases still need an explanation before this can be solved properly.
5. **64-bit constant: matched.** func_00383B08 is plain C passing `0x8000000044` to func_003A3EF0 with `@ps2as`; Ps2EeAs expands it as `ori 0x8000; dsll 24; ori 0x44`, exactly like retail.
6. **Angle-wrap pair: hand-written.** func_00389380 and func_003893C8 sit in the hand-written math range around 0x388000 to 0x389500, use `$f14`/`$f15` and `$v0` as scratch in a leaf, and have none of the FPU hazard `nop`s gcc always emits after `c.lt.s`. Both are now `ASM_FUNC`.


## Update 2026-09-27 (evening): plain-function pass

`python tools/pr_check.py`: 813 functions in C (up from 764 this morning), 144 `ASM_FUNC`, 225 `LINKER_REMNANT`, 685 `INCLUDE_ASM` left. 1,182 of 1,867 entries (63.3%) are final source.

- **Short-loop padding solved (`tools/asm_filter.py`).** Retail's assembler padded every loop shorter than 6 instructions with nops before the backward branch; retail has 142 such loops and none shorter than 6. `ee-as` never pads them and Ps2EeAs pads to 7, so no C function with a short loop could match before. The filter runs between gcc and the assembler in every build path (build_text.py, try_func.py, localdecomp, permuter_setup.py). 177 remaining functions contain such loops.
- **Remnant prefixes split (`tools/split_remnant_prefix.py`).** 21 functions started with linker-remnant `[insn, nop]` pairs glued on by splat. Each is now a `LINKER_REMNANT` plus a new function at the real address (1,846 entries became 1,867).
- **Matching lessons:**
  - Callees whose result is unused should be declared `void`; an `s32` return keeps `$v0` busy and swaps `$v0`/`$v1` later.
  - A global accessed at several offsets matches as a struct array accessed with `->` (`extern S_X D_X[]; D_X->f18`): gcc then keeps the base in a register like retail, where byte-offset casts get folded into the symbol.
  - Mixed `lui`/`$at` and `$gp` accesses: S mode + `@ps2as`, with the split-accessed globals declared as arrays and the macro-accessed ones sized. Which global Ps2EeAs puts on `$gp` can depend on statement order.
  - 64-bit constants like `ori 0x8000; dsll 16` are just `(unsigned long)0x80000000` / `0x8000000044` literals.
- **Still open:** the `nop`s before `div.s`/`sqrt.s` (behaviour varies within a single function; no rule found yet), and store pairs that gcc emits in the opposite order to the source.
