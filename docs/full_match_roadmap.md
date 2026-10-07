# Road to 100%: blockers and plan

Written on 2026-09-26; the dated updates below are a log, newest last. The current state is in **Update 2026-10-07** at the end. `python tools/pr_check.py --target all` and `python tools/triage.py --target all` print the live numbers.

> **Note 2026-10-03:** `src/text.c` was split into one file per original source file in `src/frontbin/` ([source_files.md](source_files.md)). The dated entries below are a log and still say `text.c`; read it as "the sources".

> **Update 2026-09-27:** the handwritten (100) and remnant (203) buckets are done: they moved to `asm/handwritten/` and `asm/remnants/`, included with `ASM_FUNC` / `LINKER_REMNANT`, and count as finished in objdiff. Current state: 763 functions in C, 303 assembly sources, 779 still to match (655 plain, 31 switch, 72 vu0, 14 mmi, 7 other). `python tools/triage.py` has live numbers.

## Where we are

The build has matched byte for byte since the start. The goal is to have every function come from real source: C for compiled code, `.s` for code that was assembly in the original.

On 2026-10-07 (`pr_check.py --target all`, `triage.py --target all`), all three targets build byte-identical:

| Target | In C | `ASM_FUNC` | `LINKER_REMNANT` | Still `INCLUDE_ASM` | % in C |
|---|---|---|---|---|---|
| frontbin | 1,414 | 156 | 225 | 72 (0x12ACC bytes) | 75.7% |
| boot_elf | 1,479 | 358 | 328 | 650 (0x384A4 bytes) | 52.5% |
| i5bootn | 2 | 147 | 8 | 42 (0x3D68 bytes) | 1.0% |

When this plan was written (2026-09-26, frontbin only), 695 functions were in C (about 0xAB00 bytes of `.text`, 10%) and 1,150 were still `INCLUDE_ASM` (about 0x65200 bytes, 90%). The functions matched first were the small ones (63 bytes on average) and what was left averaged about 380 bytes, so progress is better measured by bytes than by function count.

## Remaining functions by bucket (2026-09-26, the starting point)

Today's buckets are in Update 2026-10-07 below.

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
- asm functions pull their tables into their source file with `INCLUDE_RODATA`.

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
   - ~~The open problems: the `lwc1`/`nop` load, 64-bit constants, and `div.s` padding.~~ All three are solved (see the updates below and `Matching-Patterns.md`).

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
- Retail's `lwc1 ...($gp)` then `nop` pattern (func_003882D0 and neighbours) sits between hand-written functions and is probably hand-written too. They match as C with one `nop`, so they stay C. (Superseded 2026-09-30: they are `ASM_FUNC` now.)

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

## Update 2026-09-27 (evening): near-miss pass

The 19 m2c drafts that were 1 to 5 instructions off went through the permuter and a manual pass. All 19 now match; the first 16 and are in text.c (full build MATCH): func_0037E7D8, func_0037E920, func_0037EAA0, func_00396248, func_003997F0, func_0039D510, func_003A61D0, func_003A6888, func_003A6910, func_003BEBF8, func_003D47A0, func_003D99D8, func_003E1460, func_003E16B8, func_003E9C50, func_003EB620.

The permuter found only one of them (func_003997F0: load `arg0[0]` before the `if`). The rest came from fixing the draft, so check these before starting a permuter run:

- **Pointer arithmetic on typed pointers.** m2c writes `D_X + 0x40` or `p->f4 + 0x20` where `D_X`/`f4` has a struct or `s32 *` type, so the offset gets scaled. Cast to `u8 *` or give the field a `u8 *` type (func_0039D510, func_003E16B8).
- **Wrong callee prototype.** A per-function alias hides the prototype text.c already uses. func_003A3EF0 takes `unsigned long`; declaring it `(s32, s32)` leaves the constant load scheduled differently (func_003D47A0). A callee that takes one argument but is declared with three leaves extra argument moves (func_0037EAA0). Look up the real declaration in the sources (`src/frontbin/`) first.
- **Base + index + field offset.** Retail often keeps `base + i * size` in a register and uses the field offset in the load (`lw 0x50($a0)`), where gcc folds `base + 0x50` into the `lui`/`addiu`. Take a pointer to the element first: `S *p = &D[i]; p->f50` (func_0037E7D8), `s32 **b = p->slots; slot = b + i;` (func_003E1460).
- **Store order.** gcc emits the last of a run of stores to the same base first. To get retail's order A, B, C, D write B, C, D, A (func_003A61D0, func_003A6888). Trying every order of the stores with `try_func.py` takes seconds.
- **`abs.s` that is not scheduled.** Where retail has `abs.s` right before `jr $ra` (not in the delay slot) or before a load, `fabsf()` doesn't match; `__asm__("abs.s %0, %1" : "=f"(r) : "f"(x))` does (func_003BEBF8, func_0037E920). SN's math header probably defined fabsf as inline asm.
- **Mixed `$gp`/`lui` with `@ps2as`.** `__asm__(".extern D_X, 4");` before the function (Matching-Patterns, option A) fixed func_00396248.
- **Branch sense and conditions.** Writing the `if` the other way round (`arg1 == 1` first) and using `(x ^ 4) == 0` where retail has `xori` fixed func_003EB620 and func_003E9C50.

The last three matched after comparing notes with [rac1-decomp](https://github.com/Lynder063/rac1-decomp/blob/main/docs/DECOMP_PROGRESS.md), which found that the access form, not the order of the `+`, decides `addu` operand order:

- func_00395958: `D_0016C690.arr[i] = v` with `arr` at 0x34 of a struct (base-first `addu`, offset kept in the store).
- func_003A7FC8: `s->a[i] = x; s->b[i] = y;` with two `f32[3]` arrays in one struct. That is what produces retail's `$v0` to `$a0` copy.
- func_003E2D90: `func_003E16B8(&D_001DA9B8)`, passing the struct like its neighbours func_003E2DE0/func_003E2E60 do. func_003E16B8's definition became K&R (`void *func_003E16B8()`) so calls with an argument stay valid.

The permuter got none of the three in 25 minutes each. Matching-Patterns has the new rules under "Codegen tricks that matter".

## Update 2026-09-28: `nop`s before `div.s`/`sqrt.s` (in progress)

70 of the 666 unmatched functions contain `div.s` or `sqrt.s`. Across all of frontbin, retail pads them with 2 `nop`s (123 cases), 1 (16), 3 (2) or none (57).

- **The padding comes from the compiler, not the assembler.** Sony's ee-gcc 2.9-991111-01 (and -dtls13010), 2.96-ee-001003-1 and both 3.2 builds have a cc1 option `-mhandle-ee-div-pipeline-bug`, on by default. The `divsf3`/`sqrtsf3` templates then become `%(nop; nop; div.s%)`. SN 2.95.3 v1.36 (our compiler), Sony 2.95.3-114/-136, 2.95.2-273a, 2.9-991111 and 2.9-990721 don't have the option and never pad.
- **Those compilers always emit 2 `nop`s; retail doesn't.** Retail's compiler must have had a conditional version of this workaround. None of the 15 builds we have reproduces it.
- **Assemblers ruled out.** No GNU as build (any `-mcpu`/`-mips`) pads `div.s`. Ps2EeAs has an EE "divbug" padding rule ("DIV related opcode too near branch instruction / possible branch destination"), but it applies to integer `div` only.
- **Best static rule so far (144 of 190 retail cases):** 2 `nop`s, unless the instruction just before writes one of the `div.s` operands (the pipeline stalls anyway) or the `div.s` directly follows a call's delay slot. Position in the basic block, distance to branches or labels, and alignment don't explain the rest.
- **Next step:** implement the rule in `tools/asm_filter.py` (it already runs between gcc and the assembler), plus a per-function table listing retail's exact `nop` counts for the cases the rule misses, like `TEXT_PADDING`. That unblocks the 70 functions without inline asm, and the table shrinks as the rule improves.

## Update 2026-09-30: the three open problems

- **`lwc1 ($gp)` then `nop`: hand-written.** Retail has the same load-jump-use shape unpadded 19 times elsewhere; no compiler or assembler emits the `nop`. `func_003882D0`, `func_00388308`, `func_00388340`, `func_00388378` and `func_00388388` are now `ASM_FUNC` (149 hand-written functions).
- **`div.s`/`sqrt.s` `nop`s: not a C problem; needs the asm_filter emulation.** All 207 retail cases measured (131 with 2 `nop`s, 58 with none, 16 with one). Ps2EeAs pads by itself but matches retail's count in about 26% of cases, and both assemblers delete an explicit `nop` in reorder mode, so the padding has to be emitted as a raw `.word` from a per-function table.
- **Register allocation (`func_0039BEC0`): C-solvable in principle.** `tools/regalloc.py` shows gcc's priority order; two C changes reproduce retail's registers exactly (see Matching-Patterns), leaving a branch-shape difference (score 210).

## Update 2026-10-02: where things stand

`python tools/triage.py`: 464 functions (0x41B9C bytes) still `INCLUDE_ASM`: 371 plain (122 under 0x100 bytes), 26 switch, 53 vu0, 14 mmi.

- All the toolchain-level open problems are solved: jump tables, remnants, hand-written asm, trailing padding, short-loop padding (including loops with a `jal`), `$ra` saved with `sq`, the `lwc1`/`nop` load, 64-bit constants and `div.s`/`sqrt.s` padding.
- What blocks the rest is register allocation and scheduling near misses (`docs/permuter_todo.md`, status list at the top) and the volume of large functions.
- The MMI bucket is still untested.

## Update 2026-10-07: three targets, the VU0 flag, what blocks the rest

`pr_check.py --target all`: frontbin **1414 functions in C, 72 INCLUDE_ASM (75.7%)**; boot_elf **1479 in C, 650 INCLUDE_ASM (52.5%)**; i5bootn **2 in C, 42 INCLUDE_ASM (1.0%)**. All three build byte-identical (`3bc94ee8...`, `48797530...`, `71f3ecfc...`).

| Bucket | frontbin | boot_elf | i5bootn |
|---|---|---|---|
| plain | 41 (0x7D74 bytes) | 434 (0x22C34) | 36 (0x2D38) |
| sibcall | | 43 (0x1FB8) | 3 (0x108) |
| switch | 9 (0x3C3C) | 21 (0xA3B0) | 1 (0xD14) |
| vu0 | 11 (0x3304) | 41 (0x3AEC) | |
| mmi | 11 (0x3E18) | 29 (0x5428) | 1 (0x210) |
| sys | | 2 (0x288) | |
| odd | | 80 (0x36C) | 1 (0x4) |
| total | 72 (0x12ACC) | 650 (0x384A4) | 42 (0x3D68) |

### What happened since 2026-10-02

- **Large-function batches (2026-10-05/06):** 13 large functions matched, among them `func_00397490` (the memory card state machine, 2163 instructions, the largest), `func_003DCD08` (0x1558, the first VU0 j-form match), `func_003DBEC8`, `func_003EB728`, `func_003BC568`, `func_00382458`, `func_0037D200` (the front-end main loop), `func_003C0188`, `func_00384EC0`, `func_003B2F50`, `func_003B16B0`, `func_003D2878` and `func_003813E0`. An aligned diff (difflib over the disassembly) made progress measurable on functions this size.
- **Round d (19 agents, 2026-10-06):** 164 new frontbin matches (1183 to 1347 in C), 27 of them in the VU0 j-form.
- **Final passes f and g (2026-10-06/07):** every function still in assembly was attempted with all earlier drafts at hand: 33 matches, then 18 (1360 to 1393, then 1393 to 1411). Every remaining frontbin function has a near-miss draft with a header.
- **Round k (2026-10-07):**
  - Blocker fixes: `tools/asm_filter.py` counts a load or store of a symbol with an earlier `.extern SYM, N` (N <= 8) as one word, so short poll loops are padded like retail (`func_003B8840` matched); `tools/gen_divs_nops.py` recognises `sqrt.s`, which the disassembler prints as a raw `c1` word; the unreferenced rodata after `func_003BC218`'s jump table (0x318A18 to 0x318ABC) can be written as `const u32 D_00318A18[42]` after the function, so its rodata split no longer blocks it; three prototypes in other functions' blocks fixed (`func_003972A0`, `func_003ACC30`, `func_003B9B60`).
  - Permuter: `tools/permuter_scorer.py` scores by aligned diffs (hook: `tools/decomp-permuter-aligned-scorer.patch`), and `permuter_setup.py` keeps `mode(TI)` / `aligned(16)` typedef attributes (`attrs.json`), which had been silently dropped. See `docs/permuter.md`.
  - frontbin: 3 more matches (`func_003B8840`, `func_003A9B10`, `func_003AF718`).
  - boot_elf: `seed_boot_elf.py` rerun (17 more front-end functions), and 102 engine-core matches by k1 (1360 to 1479 in C).
  - Compiler matrix on the 74 remaining frontbin drafts: SN best or tied on 73, no hidden library code, `-O2` everywhere, `-fopt-stack` confirmed (`compiler_matrix_findings.md`, Update 2026-10-07).
  - boot_elf core classified by compiler (`boot_elf.md`).
- **`-mvu0-use-vf0-vf2` on every frontbin and boot_elf line.** It is Sony's VU0 register-range option; N = 2 is the only value that fits all 38 j-form matches and the whole build, and it changes ordinary loop code through loop.c's thresholds. `func_003B22C0` and its boot_elf twin `func_003B7A80` were rewritten to use the struct global directly instead of a local pointer. The j-form is now the leading explanation for VU0 code interleaved with ordinary code ([Matching patterns](wiki/Matching-Patterns.md#vu0-j-form-one-asm-statement-per-instruction)), though the maintainer has not formally approved it.

### What blocks the rest

1. **frontbin: 71 near misses** (the 72nd INCLUDE_ASM, `func_003ECDF0`, is a data blob). Each has a draft; `docs/permuter_todo.md` lists the best diff and what is left for every one. Closest: `func_003BC218` (1 diff, `r = 1` in one switch case reuses another pseudo in retail), `func_003B0A60`, `func_003E09D8`, `func_003E89F0` (2 each), `func_00391E78`, `func_003B43C0`, `func_003E0E90` (3). The compiler matrix found no better compiler and no global flag for any of them. Rework `func_003B1EB0`, `func_003A8230` and `func_0038FDC0` under the new VU0 flag first (117 to 79, 141 to 131, 22 to 20 in m1's sweep).
2. **Sony-compiled library code needs a compiler pseudo-flag.** About 440 boot_elf core functions and most of i5bootn were built with Sony's 2.9-ee-991111-01 or 2.96. A per-file pseudo-flag for each (like `@ps2as` for the assembler; the binaries are in `C:\tools\testfolder`) unlocks libgcc (56 functions in boot_elf, 26 in i5bootn, buildable from GCC 2.95's source) and the Sony library ranges.
3. **989snd next.** The EE side of the sound library (0x13B330 to 0x13D420, about 60 functions) is SN code and matchable now; k1 already matched several.
4. **`core.rdata` split.** Core functions with a `switch` stay INCLUDE_ASM until the core's read-only data is split per source file.
5. **The 21 frontbin/boot_elf twins that differ.** 21 frontbin functions are not the same instructions in boot_elf's front end, so seeding can't carry them over; they need their own C (plus the seeded functions that compiled but didn't match).
