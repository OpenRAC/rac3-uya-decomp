# Matching patterns

What makes SN ee-gcc 2.95.3 produce retail's exact code, collected from the ~1400 frontbin functions matched so far (and boot_elf's). The research behind it (compiler comparisons, how the assemblers were identified) is in [`docs/compiler_matrix_findings.md`](https://github.com/OpenRAC/rac3-uya-decomp/blob/main/docs/compiler_matrix_findings.md).

Every frontbin and boot_elf range already builds with `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division`, so `$s` registers saved with `sd` in 8-byte slots and `div` without the trap come out right on their own. The VU0 flag (since 2026-10-07, see [VU0 j-form](#vu0-j-form-one-asm-statement-per-instruction)) also changes ordinary loop code, so measure drafts with it. What varies per function is how globals are declared, split vs no-split addresses, and which assembler runs.

## Globals: gp vs lui

`-G8` lets the compiler address any object of 8 bytes or less relative to `$gp`. Retail only did that for some variables. Match each global's declaration to how retail reaches it:

| Retail access | Declaration | Use |
|---|---|---|
| `lw $v0, -0x3e40($gp)` | `extern s32 D_001D8A70;` (sized) | `D_001D8A70` |
| `lui $v0, %hi(D_X)` + `lw $v0, %lo(D_X)($v0)` | `extern s32 D_001DA0D0[];` (no size) | `D_001DA0D0[0]` |
| Struct or table through `lui`/`addiu` | `extern S_Foo D_00142430[];` or `extern S_Foo D_00142430;` (size > 8) | `p = D_00142430; p->x` |

The address of a `$gp` access is `0x1DC8B0 + offset` (offsets are negative). Name the symbol `D_` plus 8 hex digits: `-0x5b0c($gp)` is `D_001D6DA4`.

An unsized array is never small data, so it always gets `lui`. To keep existing code readable you can alias the element:

```c
extern u8 D_00142734[];
#define D_00142734 (D_00142734[0])
```

## Mixed access in one function

Sometimes retail reads a variable through `lui` and writes it through `$gp` in the same function, or uses `$gp` only for the access that sits in a branch delay slot. No single declaration does that with the default assembler. The cause is SN's own assembler, Ps2EeAs, which retail was built with:

- It is **single-pass**. It uses `$gp` for a symbol only if it already knows the symbol is small at that point in the file. gcc writes its `.extern` size hints at the end of the file, too late.
- In a branch delay slot it can't expand a two-instruction `lui` access, so it uses `$gp` there regardless.

**Option A (preferred): natural C with `@ps2as`.** Declare everything with its natural sized type and assemble with Ps2EeAs. For the variables retail does reach through `$gp` everywhere in the function, tell the assembler their size before the function:

```c
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001D62FC, 4");
__asm__(".extern D_001D6308, 2");
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
```

`.extern` only declares a size. It creates no storage. Examples: `func_003969B8`, `func_003D3050`. The bitfield writes to `D_001D4CEC` (`flags.b5 = 0;`) and the GIF packet writers (`p[0] = ...; p += 4;`) are this pattern too.

**Option B: two declarations with the default assembler.** An unsized array for the `lui` accesses plus a sized alias for the `$gp` ones:

```c
extern s32 D_001D4CE8[];       /* lui reads */
extern s32 D_001D4CE8_g;       /* $gp writes */
```

The alias needs an address in `symbol_addrs_resolved.txt` (`D_001D4CE8_g = 0x1D4CE8;`) or the link fails.

## Plain names first, per-function aliases only when needed

Use the plain name (`D_00142430`, `func_003E8320`). A source file is one translation unit: every block sees the earlier blocks' declarations in its file, plus, at the top, the declarations from earlier files of names the file uses without declaring them itself. Other files' declarations never reach a file that declares the name itself.

An alias is needed only when two blocks **in the same file** need different types for one symbol (a different struct type, sized vs unsized, a function used once as an array to take its address), or as one of the code-generation techniques on this page (a second symbol at the same address to get `lui` where the plain name gets `$gp`, and the like). Then don't change the shared declaration; declare a per-function alias named after the function address:

```c
typedef struct { u8 pad[0x18]; u16 h18; ... } S_3969B8;
extern S_3969B8 D_00142430_003969B8[];
```

and add `D_00142430_003969B8 = 0x142430;` to `symbol_addrs_resolved.txt` (and a `D_00142430 = 0x142430;` line for the plain name if it's the first use of the address). `pr_check.py` flags any alias without an address, and `try_in_context.py` / `pr_check.py` report a clash that needs one.

Until 2026-10-04 aliases were the default, a leftover of the single `text.c`, where every declaration stayed in scope to the end. That day 646 of the 941 were renamed back to plain names; the 295 left are the ones where a block in the same file really uses another type, or where the alias changes the generated code.

To pass a function's address, use the function's own name (`func_003E8320`), declared the way the sources already declare it, not an `extern u8 func_003E8320_x[];` array alias.

Name typedefs uniquely the same way (`S_3969B8`, `S_142430x`). Two blocks defining the same typedef name with different bodies is the most common full-build error.

## Never define variables

The source files must only produce `.text`. Every variable is `extern`:

- `s32 D_X;`, `static s32 D_X = 3;` and `void (*D_X)(void);` without `extern` are definitions. They create `.data`, `.sdata` or `.bss`, which shifts the retail layout or fails the link with `multiple definition`.
- String literals and float constants that the compiler puts in `.rodata` or `.lit4` have the same problem. See floats below.
- `pr_check.py --obj build/src/text.c.o` lists any data section that sneaks in.

## Split vs no-split addresses

Retail was built from many source files, and some used `-mno-split-addresses` (N) while others used the default (S). They form address runs, recorded in `tools/text_parts.txt`:

- **S:** `lui $v0, %hi(X)` + `lw $v0, %lo(X)($v0)`, and array bases as `lui` + `addiu`.
- **N:** the compiler emits `lw $v0, X` and the assembler expands it, so you see `lui $at` pairs and loads that fold the offset differently.
- **A `lui` and `addiu` split by another instruction** (e.g. on either side of a prologue `sd $s0`) were two scheduled instructions, so that function is S mode even inside an N run: N mode emits the address as one `la`, which the assembler expands to an adjacent pair. Give it a single-function override without `-mno-split-addresses` rather than reproducing the split with asm (`func_003B9730`, `e = D_001D8D90;`).

A function's mode only shows when it touches a global. `tools/asm_profile.py` reads it off retail ([below](#reading-the-profile-off-retail)). If the diff is all about how addresses are formed, run `check.py --all-modes`. Known N-only shapes: constructors that return `p`, destructors that save `ra` with `sd`, and the "no-split global load" class.

## Choosing the assembler

| Assembler | Selected by | When |
|---|---|---|
| `bin/ee-as.exe` (Aug 2000) | default | Almost everything. It inserts the `nop` after `mtc1` that retail has. |
| `ee/bin/Ps2EeAs.exe` (SN ps2eeas 1.9.25) | `@ps2as` | Mixed gp/lui access (above); float constants built inline with `lui`/`ori`/`mtc1`; `mtc1` hazard `nop`s that depend on whether the next instruction uses the register |
| `ee/bin/as.exe` (May 2001) | `@newas` | Rare; try it when both of the others are one instruction off |

Ps2EeAs can't read the GNU `macro.inc`, so a range assembled with it must not contain any `INCLUDE_ASM` stub. Give the function its own single-function range (the build then compiles it as a separate slice of its file) (see [Toolchain and build](Toolchain-and-Build#text_partstxt)).

## Reading the profile off retail

`tools/asm_profile.py` reads the mode and the assembler off a function's retail bytes and prints the evidence, instruction by instruction:

```text
python tools/asm_profile.py --target frontbin func_003B5128
python tools/asm_profile.py --target veldin func_00495980
python tools/asm_profile.py func_00495980          (a shared level function, from the private level inputs)
```

What it looks for (each mark has a weight; the side with more wins):

| Mark | Says |
|---|---|
| a `lui` whose `%hi` feeds two accesses, sits apart from its use, or is in a register that is neither `$at` nor the load's destination (an address in RAM, not an EE register) | **S**: gcc split the address itself |
| `lui $at` + access to an object outside small data, `lui $at; addu $at, $at, $r` + access, or a large immediate built in `$at` | **N**: the assembler expanded a macro that S mode would have split in gcc |
| small data reached only through assembler macros, no split anywhere (weak) | **N** (most such functions are N; with any Ps2EeAs mark below it is a coin flip and is not counted) |
| `lui $at; ori $at, $at, lo; mtc1 $at` (a float constant with a non-zero low half) | **Ps2EeAs** (GNU as puts it in `.lit4`, which retail never has) |
| a 64-bit constant in Ps2EeAs's own `dli` expansion: a shift other than 16 or 32 between its parts (`ori 0xc800; dsll 22; ori 0x68`), or `addiu -1; dsll32 31` for `1 << 63` | **Ps2EeAs** |
| a 64-bit constant that starts with `lui` or with a small immediate (`addiu 50; dsll32 0; ori 0x68`) | **GNU as** |
| one small-data global reached through `$gp` and through `lui` | **Ps2EeAs** (single pass: `$gp` only where it already knew the size, or in a delay slot) |
| `mfc1 $r` read by the next instruction; an FPU instruction right after `mtc1` that does not read its register, with no `nop` | **Ps2EeAs** (GNU as puts a `nop` after every `mtc1`); the `mtc1` one counts less in N mode |
| in S mode, small data reached with an assembler macro (`lui $at` + store, `lui $r; lw $r, lo($r)`) | **Ps2EeAs** (GNU as knows every small symbol's size; in N mode the matched sources do this under either assembler, with unsized declarations, so it is not counted there) |

A function that reaches no global and builds no constant shows neither choice; the tool then says `unknown`. `--evaluate` compares the guess with the flags every matched function is built with, and `--verify` also builds each disagreement with the guess. On 2026-10-21, for plain C (no inline asm, register pins or `.extern` hints, which steer some matches toward the other mode or assembler):

| | mode decided | agrees | builds the same anyway | assembler decided | agrees | builds the same anyway |
|---|---:|---:|---:|---:|---:|---:|
| frontbin (1166) | 501 | 97.6% | 98.6% | 237 | 94.1% | 98.7% |
| boot_elf (1293) | 530 | 97.7% | 98.7% | 241 | 93.4% | 98.8% |
| shared level code (3081) | 1406 | 97.4% | 98.6% | 639 | 95.0% | 98.4% |

With the hand-steered matches included, the mode agrees on 95.0% (frontbin) and 95.1% (boot_elf). When the mode is `unknown`, 93% of frontbin's and boot_elf's functions and 89% of the shared ones build the same bytes in the other mode. Reading an `unknown` assembler as the default one agrees with 94.2% to 94.8% of every program's functions (96.0% to 96.7% counting those that build the same either way).

What it does not see yet: a constant offset folded into one `lui` that also serves as a value (`lui $v0, 5; addu $a0, $a0, $v0; sw $v0, 8($a0)` is S, N builds the address with `lui $at`), and the field offset an N-mode `la` folds into the address (`la $a0, D_X+0x25; lbu 0($a0)` against S's `lbu 0x25($v1)`); both look like an ordinary adjacent `lui` pair.

`tools/try_func.py` uses it as the first guess: without `--mode`/`--as`, a function with no flags of its own (no single-function line in `text_parts.txt` or `localdecomp_flags.txt`, no `@ee29`/`@newas` range) is built first with the guessed profile and then, if that is not a match, with its range's flags; the closer result is shown in full (`--no-guess` turns it off). `tools/try_level.py` and `tools/seed_levels.py` do the same for the shared level code ([docs/common_level_c.md](https://github.com/OpenRAC/rac3-uya-decomp/blob/main/docs/common_level_c.md)).

## Floats

### Early extern sizes for Ps2EeAs

Ps2EeAs can select `lui/lo` instead of `$gp` when GCC places its scalar
`.extern symbol, size` declaration after the first access. An isolated probe
with four real four-byte scalars and a float constant demonstrated both
`GPREL16` access and inline constants once the same size metadata was made
visible early. Alignment attributes alone did not change that result.

For a scoped candidate, `tools/try_func.py` accepts repeated
`--early-extern-size SYMBOL=SIZE` options, for example:

```text
python tools/try_func.py scratch/candidate.c --mode N --as ps2as --early-extern-size D_001DB6DC=4
```

The helper requires a positive size exactly present in the compiler's own
generated assembly. It duplicates only those declarations immediately before
the first `.ent`, preserving the initial header, instructions, and late
declarations. Missing symbols, different/conflicting sizes, malformed requests
and missing function entries are rejected. No source inline ASM, register
constraint, storage or instruction substitution is introduced.

This is an opt-in compiler-metadata experiment, not a matching result. Recheck
the full function's symbol type/size, payload, all resolved retail bytes and
raw object encoding. The current full-project builder does not automatically
enable this command-line option; successful candidates need a reproducible
build integration before promotion. Never guess a different data width merely
to influence GP selection.

- `li.s` constants: retail usually builds them inline (`lui $at, 0x3f80` / `ori` / `mtc1`). Only Ps2EeAs does that. With the default assembler, the constant goes to a `.lit4` pool and the link fails with `R_MIPS_LITERAL lit4`. Use `@ps2as`.
- Read the constant's value from the asm: `lui $at, 0x3f46` + `ori $at, $at, 0x6666` is `0x3F466666`, which is `0.775f`. Write it with enough digits that it rounds to the same bits.
- Float arguments need prototypes. Without one, a `float` argument is promoted to `double` (you'll see `cvt.d.s` and the wrong registers). Declare it (`extern f32 func_00388A28(f32, f32);`) or cast at the call (`((void (*)(void *, f32))func_00388830)(a, f)`).
- 64-bit values (`sd`, `ld`, `dsll32`, `dsra32`) are `long` or `unsigned long` in this compiler, not `s32`.

### Floats read through $gp

A float loaded through `$gp` (`lwc1 $f12, -0x33a4($gp)`) is a small-data global in frontbin's `.lit` segment (0x1D5680 to 0x1D9900), not a literal. Declare it sized, like any `$gp` variable:

```c
extern f32 D_001D950C;           /* 0x1DC8B0 - 0x33A4 */
```

A few such loads reach below 0x1D5680, into the main executable's small data; declare those the same way. Constants written in the source come out inline (`lui`/`ori`/`mtc1`) and need `@ps2as`, as above.

## Code from another compiler (`sibcall`)

A function that ends `ld $ra, ...; j func_X; addiu $sp, $sp, N` (or `j func_X` straight after the `$ra` reload) makes a sibling call: it jumps to its last callee instead of calling it and returning. SN ee-gcc 2.95.3 never does that (it emits `jal` and `jr $ra`), and frontbin has no such function. boot_elf's engine core has 43 and i5bootn 3. Sony's library compiler, ee-gcc 2.9-ee-991111, does make them (i5bootn's compiler matrix matched them with it, and with nothing newer), and so do 2.96 and 3.2 (about 11% of functions in the 2026-10-07 calibration builds; boot_elf's newlib region looks like 2.96, see `docs/boot_elf.md`). So a sibling call only says "not our compiler". `tools/triage.py` puts them in the `sibcall` bucket; skip them until that compiler is in the toolchain. See `docs/compiler_matrix_i5bootn.md`, which also lists the libgcc code (byte-identical to the prebuilt `libgcc.a`) in i5bootn and boot_elf's core.

## boot_elf's engine core

- Some core functions start on a 4-byte boundary. A source file's object starts 8-aligned, so a file can only begin at an 8-aligned function; inside a file gcc places the functions itself.
- Some core code reloads `$gp` (`lw $gp, %lo(sym)($v0)`): it is library code that switches small-data bases. Leave those as INCLUDE_ASM for now.
- `core.rdata` isn't split, so a core function with a `switch` (a `jtbl_` in its `.s`) stays INCLUDE_ASM until it is.
- Most of the core is Sony library code built with another compiler (region map in `docs/boot_elf.md`). Signs that a function is library code and not worth a C attempt yet (k1, 83 of 200 small core functions skipped for these):
  - each saved register in its own 16-byte slot with `sd`, `$ra` highest (our gcc gives 8-byte `sd` slots with `-fopt-stack` and `sq` without it; the `sq_ra_funcs.txt` rewrite only produces `sq`);
  - sibling calls;
  - a short loop whose branch delay slot is left empty, with `nop`s before the branch (padded to 7 words; neither Ps2EeAs nor `-fno-delayed-branch` reproduces it);
  - an alignment `nop` after a `b`;
  - newlib reent wrappers that keep `&errno` as a full address in a register (our gcc folds the low half into the offset);
  - varargs functions that save none or all eight FP argument registers (ours saves four);
  - `mult $0` + `mflo` (our gcc always uses the 3-operand `mult`).
- Three core functions (`func_00122278`, `func_0013A9F0`, `func_00136010`) match with SN gcc only with `-mcheck-zero-division` (the project's `-mno-check-zero-division` dropped), which suggests libraries built with their compiler's default flags. They have single-function overrides.
- 989snd's EE side (0x13B330 to 0x13D420) is SN code at `-O2 -G8 -fopt-stack` and matches with our toolchain; start core work there.
- **A wait loop that re-reads a `$gp` global with `lui`** (`func_0013BD58`, `@ps2as`): retail tests `D_1D4A00` through `$gp`, then polls it in a 6-word loop with `lui`/`lw`. Write the first test plainly and the loop's read as a volatile cast, `do { func_0011F0A0(0); } while (*(volatile u32 *)&D_1D4A00 == 0xFFFFFFFF);`. With an unsized alias or a literal address, gcc builds the address in a register before the loop, and a `goto` loop gets merged with the first test. The loop's load is an assembler macro, which `tools/asm_filter.py` counts as two words in `@ps2as` ranges (see [Tools](Tools#asm_filterpy)).

## Switch statements

`switch` works in C. The jump tables used to sit inside the data blob; since `tools/migrate_jtbls.py` they come from the source files, in function order, exactly where retail has them (the start of `.data`). Each asm function with a table has an `INCLUDE_RODATA(...)` line right after its `INCLUDE_ASM`. When you convert the function, delete both lines: gcc's table takes the same place. `pr_check.py` catches a leftover `INCLUDE_RODATA`.

Getting the table to start at the right index: if retail's table has entries for 0 and 1 that go to the default code, list them with the default at the end, as in `func_003B0FC8`:

```c
switch (D_00143A07[0]) {
case 2: return 0x151;
...
case 6: case 7: return 0x150;
case 0: case 1: default: return 0x150;
}
```

## VU0 code: inline asm

Insomniac wrote VU0 math as inline assembly inside C functions, so that is the matching form too. Two forms match retail. Where retail keeps a VU0 sequence together (leaves, and blocks with no ordinary instruction between the VU0 ones), one volatile block with explicit registers matches, as below. Where retail interleaves VU0 instructions with ordinary code (argument moves, constants, `lq`/`sq`), use the [j-form](#vu0-j-form-one-asm-statement-per-instruction): a volatile asm is a scheduling barrier, so one block can't reproduce that.

For the one-block form, use explicit `$vfN` registers in the template and pass pointers as `"r"` operands:

```c
void func_00388698(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vmini.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "memory");
}
```

Keep any `nop` retail has between VU0 instructions in the template.

Most VU0 functions are pure assembly leaves: a few `lqc2` loads, vector math, an `sqc2` store. For those, transcribe every instruction into one `__asm__ __volatile__` block in retail's order and let gcc emit the return. The details that decide whether it matches:

- **Raw `.word` lines.** `tools/fix_quadword_ops.py` writes `lqc2`, `sqc2`, `lq` and `sq` as raw words so the GNU assembler can't pad them. Decode them back to real instructions in your C (`.word 0xD8A10000` is `lqc2 $vf1, 0($5)`); a `.word` inside inline asm assembles fine but is unreadable.
- **The delay slot decides the assembler.** gcc ends the function with its own `j $31`. With the default assembler in reorder mode, the assembler moves your block's last instruction into that delay slot. When retail has that instruction in the delay slot, the default assembler is right; when retail has `jr $ra` followed by `nop`, use `@ps2as`, which leaves the order alone. Try both.
- **Branches inside the block** need `.set noreorder` around the part that contains the label, or the assembler re-pads the branch.
- Functions that end by moving a value into `$f0` (`mtc1 $at, $f0`) still don't match: retail has that instruction in the delay slot and neither assembler puts it there, since gcc, not the assembler, owns the return value. Those need the value returned from C instead of from the asm block.

## Not everything is C

- **Trailing padding is part of the layout.** A function's `.s` file also holds the padding words that follow it (`func_0039BD08` is 0x24 bytes with 5 `nop`s after it, because the next function starts at 0x39BD40). Converting such a function to C drops that padding and shifts everything after it, which changes every `jal` target in the build even though the function itself is byte-exact and `check.py` says MATCH. Before converting, check the gap to the next function's address; if there is one, the padding has to be reproduced or the function left as asm.
- **Linker remnants** (the `remnant` bucket in `todo.py`, about 200 entries). Retail has about 620 single instructions, each followed by a `nop`, between functions. Nothing references them, and 449 of them are `addiu $sp, $sp, N`, a function epilogue. They are what the original linker left behind when it stripped unused functions: the final odd instruction plus its alignment `nop`. They are not source code: they live in `asm/remnants/` and are included with `LINKER_REMNANT(...)`. Don't write C for them.

  The exception is a "remnant" that something calls: it is the first instruction of a function the splitter cut up. boot_elf's `func_0038DD38` (an `ld $at`, called from `3A9F18.c`) was split into that remnant, `func_0038DD40` (the body) and `func_0038DD8C` (the `sqc2` in the `jr` delay slot); one block under the called name replaces all three. Pass that name to `try_in_context.py` (otherwise it may pick a split name from a comment). It still reports diffs after the first instruction, since retail's symbol covers only the remnant, so the full build is the check. Split names that a comment mentions get a line in `targets/boot_elf/symbol_addrs_resolved.txt`, as `seed_boot_elf.py` would add (`func_0038DDDC` for `func_0038DD90`).

  A C function whose whole body is one `asm volatile("addiu $sp, $sp, 0x50")` looks like a match in localdecomp but is not one: gcc still appends `j $31` and a `nop`, which shifts every later function. 26 of these were scored 0 before localdecomp stopped trimming real instructions past the target size; `pr_check.py` now warns when its count runs ahead of the sources.
- **Handwritten assembly** (the `handwritten` bucket, 100 functions). spimdisasm flags them (`addi`, `$at`, unusual registers). The original was a `.s` file, so their `.s` in `asm/handwritten/` is the source, included with `ASM_FUNC(...)`. The same goes for VU0 leaves whose last instruction sits in the `jr $ra` delay slot after a dependent instruction (`mtc1 $4, $f0` after `qmfc2 $4`, `ppacb` after `ppach`): neither assembler nor gcc will put it there, even when gcc emits the `mtc1` itself, so the original wrote the whole function, `jr` included, in assembly.

## Codegen tricks that matter

When the instructions are right but their order or registers aren't:

- **Independent stores get rotated by the scheduler.** gcc emits the last store of a run to the same base first. For retail's order A, B, C, D write B, C, D, A (`func_003A61D0`, `func_003A6888`). The scheduler issues at most one memory access per cycle; between equal priorities it prefers the instruction with more dependents, then the one that frees a register, then source order (found by [rac1-decomp](https://github.com/Lynder063/rac1-decomp/blob/main/docs/DECOMP_PROGRESS.md)).
- **`addu` operand order is picked by the access form, not by the order you write the `+`.** gcc canonicalises the addition. `p = (u8 *)T + i * 4` and `b = table + i` give index first; `T[i].field`, `S.arr[i]` and `table[i]` give base first (rac1-decomp). A field at a fixed offset from an indexed table (`sw $a0, 0x34($v0)` after `addu base, idx`) is an array member of a struct: `extern T D_X; D_X.arr[i] = v;` (`func_00395958`).
- **Two registers holding the same pointer.** Retail computing `base + i * 4` into one register and copying it to another before the second store (`addu $v0, $a0, $a1; move $a0, $v0`) is two arrays in one struct: `s->a[i] = x; s->b[i] = y;` (`func_003A7FC8`). Pointer variables, `volatile` and return tricks don't produce it.
- **Callee prototypes decide argument code.** Use the declaration the sources already have instead of an alias with guessed types. A `long` / `unsigned long` parameter builds its constant as one macro that can move (`func_003A3EF0`, `func_003D47A0`); a callee declared with too many arguments leaves extra `move`s (`func_0037EAA0`). A function that ignores its argument in retail may still be called with one: `func_003E16B8(&D_001DA9B8)` is what keeps the pointer in `$v0` in `func_003E2D90`.
- **`volatile` pins accesses.** reorg never moves a volatile access into a delay slot, and volatile stores keep their order against the epilogue (rac1-decomp). Try it before an `__asm__` fence when retail leaves a slot empty.
- **`fabsf` that isn't scheduled.** When retail's `abs.s` sits before `jr $ra` instead of in its delay slot, write `__asm__("abs.s %0, %1" : "=f"(r) : "f"(x))` (`func_003BEBF8`, `func_0037E920`).
- **Check m2c's pointer arithmetic.** It writes `D_X + 0x40` or `p->f4 + 0x20` on struct or `s32 *` types, which scales the offset. Cast to `u8 *` first (`func_0039D510`, `func_003E16B8`).
- **Early `return` vs `if/else`** changes block layout and which branch is likely (`beql`/`bnel`).
- **`x = c ? a : b` vs `if`** produce different code (`movz`/`movn` vs branches). Try both.
- **Declaration order of locals** can swap registers.
- **Signedness** picks `slt` vs `sltu` and `sra` vs `srl`. `u8` vs `s32` for a flag changes `andi` masks.
- **A copy of a parameter** (`s32 id = arg;`) sometimes changes which register holds it.
- **Pointer vs index loops** (`p++` vs `a[i]`) produce different induction code.

Stop after a handful of attempts on the same register difference. Leave it as a partial and move on: breadth gets more done.

## Register allocation near misses

When every instruction is right but a variable sits in another register, `python tools/regalloc.py scratch/func_X.c` prints gcc's global allocation order: for each variable its reference count, live length, priority (about `refs * log2(refs) / live`) and the register it got. gcc allocates in decreasing priority, and a variable takes the first register not used by anything live at the same time that was already allocated; a parameter prefers its incoming register but loses it to a higher-priority local that overlaps it. So to move a parameter, change what outranks it or what overlaps it:

- Give the competing local a shorter live range (compute it later, or inline it into its single use), or one more or fewer use.
- Declare a temporary in a different block, or turn an `if` that sets it into a conditional expression: both change the live length and reference count the priority uses.
- Declaration order of locals only matters as a tie-break when priorities are equal.

Change the C, re-run the tool, and compare the `->` registers with retail before spending a build on it.

## Patterns from the m2c-assisted pass (2026-10)

m2c (`--target mipsee-gcc-c --valid-syntax`) gets the logic right for many functions but needs the fixes below before it matches. Each was confirmed on a real function.

- **m2c names parameters by register, C by position.** A function that only uses `$a0` and `$a3` must still declare `arg1` and `arg2`, or its arguments land in the wrong registers (`func_003ACED0`).
- **Virtual calls pass the object as the first argument.** m2c drops it when `$a0` already holds it: `(*vtbl[0x10])(obj, D_x)`, not `(*vtbl[0x10])(D_x)` (`func_003E7028`, `func_003E7D68`). The branch is also usually positive: `if (call(...) != 0) { ...; return 1; } return 0;`.
- **Early return versus a result variable changes the branch layout.** If only the branch shape differs, try `if (!cond) return 0; ...; return 1;` (`func_003B4220`).
- **Narrow argument types.** A `s8` parameter makes gcc sign-extend at entry. If retail only stores the byte, declare the parameter `s32` and let the store narrow it (`func_003B4220`).
- **Keep one base register with a struct pointer.** m2c repeats `M2C_FIELD(&D_x, ..., off)`, which gcc folds into the address. Declare a struct with the fields at their offsets, take `S *p = D_x;` once and write `p->field` (`func_003B8700`, `func_0039C710`).
- **`(x > -1 ? x : x + 0xFF) >> 8 << 8` is `(x / 256) * 256`** (signed). The same for 1024 (`func_003AAD40`, `func_003AAEC8`).
- **A callee's parameter order sets how its arguments are scheduled.** Registers are assigned by type independently (ints and floats separately), so a prototype can list parameters in a different order than their registers, and that changes which argument setup lands in the `jal` delay slot (`func_0038C840`, `func_0038C718`).
- **128-bit copies (`lq`/`sq`):** `typedef int u128_t __attribute__((mode(TI)));` and `*(u128_t *)p = *(u128_t *)q;`.
- **Unaligned 16-byte copies (`ldl`/`ldr`/`sdl`/`sdr`):** assign a struct of `u8 b[16]` (alignment 1): `V16 v = D_x;` (`func_003E5D08` and its four siblings, with `-O2 -G8` split addresses).
- **Singleton lookup template (`func_003E24B0` and six siblings).** Retail is split-address (`-G8`, no `-mno-split-addresses`), the singleton is a struct object with a local pointer, and the check is a conditional expression:
  ```c
  p = D_001DA9B8_x;            /* typedef struct { s32 x0, x4, x8, xC; } S; extern S D_...[]; */
  if (p->x4) q = p; else q = func_003E16B8(p);
  t = (void *)func_003E0E28(func_003E1898(q), arg0);
  v = (t != 0 && vcall(t, g) != 0) ? t : 0;
  ```
  Separate `t` and `v` are needed here: retail keeps the tested object in `$a0`.
- **Pointer-count loops over a table of function pointers** keep one outer struct pointer: `p->q->fn[i]` rather than caching `p->q` (`func_003E15D8`).

- **Loop padding no assembler mode reproduces** (retail has `jal; nop; nop; nop; bnez`): `do { r = f(); __asm__ volatile("nop\n\tnop\n\tnop"); } while (r);` (`func_003B6488`). This is an inline-asm hack. `tools/asm_filter.py` now counts `jal`/`jalr` when it pads short loops (see "Loop padding with a call in the body" below), so try the plain loop first; it may make the hack unnecessary. It did for `func_003AB100` and for the 4-nop polling loop in `func_003AD220` (the 2026-10-20 audit, at the end of this page); `func_003B6488` still needs it.
- **64-bit constants and `lwu`:** declare the callee parameter and the struct field as `unsigned long` (`func_00386608`, needs `@ps2as`).
- **Under `@ps2as`, a scalar `extern s32 X;` gets the non-gp form** (`lui; lw`, or `lui $at; sw`). Add `__asm__(".extern X, 4");` only for symbols retail reaches through `$gp` (`func_003A3220`, `func_003D3C80`).
- **Check the raw words for `lq`/`sq`** (`.word 0x78..`/`0x7C..`) before rewriting a copy loop (`func_0037F550`).
- **Singleton-style load through a different address form:** a second symbol alias at the same address (`D_001D52FC_003B42D0`, unsized array) gives retail's `lui`/`lw` where the plain name gives `$gp` (`func_003B42D0`).

## Patterns from the hand pass (2026-10, 50 functions)

Each of these fixed a real near miss.

- **Toggle a callee between `void` and `s32`.** Retail's register choice depends on whether the callee's result is live in `$v0`. A call whose result is discarded but declared `s32` kept `$v0` busy and moved a following `lui` from `$v0` to `$v1` (`func_003AE098`, `func_003B12C8`, `func_003CB890`, `func_003BC0F0`, `func_003B62E8`). If another block in the same part already declares it `void`, call through a cast (`((s32 (*)(s32))func_0039D6C8)(1)`) instead of redeclaring.
- **Scalar versus array decides who splits the address.** Under `@ps2as`, `extern s32 X;` becomes the assembler macro (`lui $a0; lw $a0, lo($a0)`, destination reused) and `extern s32 X[]` / `X[0]` becomes gcc's split form (`lui $v1; lw $v0, lo($v1)`). When a near miss differs only in which register holds the high half, flip that global (`func_003958A0`, `func_00396F18`, `func_003ADF88`). Add `.extern X, 4` for the symbols retail reaches through `$gp`.
- **Singleton vtable wrappers (the `D_001DA9B8` family) match in plain `S` mode** (no `-mno-split-addresses`). The key is a temporary for the virtual call's result: `t = vcall(p); cb = lookup(table, t); r = cb(p, ...)`. Twelve functions follow this template (`func_003E2728`, `func_003E2808`, `func_003E28E0`, `func_003E1E50`, `func_003E2028`, `func_003E2C88`, `func_003E22D0`, `func_003E23C0`, `func_003E2B98`, `func_003E21F8`, `func_003E2618`, `func_003E2A90`), and the permuter found the same template for `func_003E2118`, `func_003E29B8` and `func_003E30C8`. The lookup functions are defined later in the same part, so call them through an alias symbol and a cast.
- **Index first in an address sum.** `(i << 2) + (s32)base` gives `addu idx, base`, the order retail has; `base + i * 4` gives the other (`func_003E8EC8`, `func_00392108`).
- **A callee that returns its argument.** Use the result (`b = f(b, 1)`), or the pointer needs its own callee-saved register (`func_003DFB40` family).
- **Separate return variable, single return.** `func_003ABE98` and `func_003AD520` only match with one `return r;` at the end and no early return inside the else branch; early returns let gcc fold `r` to a constant and free the register.
- **Hash-style update `off = (key & 1) + (off + 1)`** gets reassociated; a temporary (`t = off + 1; off = (key & 1) + t;`) keeps retail's order. With it plus the init-order fix below, the lookups `func_003E4890`, `func_003E4918` and `func_003E4DA0` match; the inserts `func_003E5F00`, `func_003E6680` and `func_003E67B8` are still open (setup moves hoisted in a different order).
- **Chains of `!= 0` tests combined with `&`** (`func_003E34F0`, `func_003E3580`, `func_003E3630`): `r = f(a, b) != 0; t = f(a, c) != 0; r = r & t; ...`. A single expression gives conditional moves instead.
- **A switch whose table starts at 0** needs `case 0:` sharing the `default:` body (`func_003AE368`); without it gcc subtracts 1 and builds a shorter table.
- **A reload that retail really performs** after a store to the same global needs `volatile` on that global (`func_00395FF0`, `D_001D4CEC`); a second alias symbol is scheduled above the store instead.
- **Object-array initialisers** (`if (flag == 0) { for (...) init(p++); flag = 1; } return &array[i];`): retail has one `nop` in the loop. They used to be written `i--; __asm__ volatile("nop"); p++;` (`func_003E13D0`, `func_003AD820`, `func_003AEDF8`, `func_003AED40`, `func_003B46F0`), but the plain loop matches: ee-as pads the short loop itself (the 2026-10-20 audit removed all five).
- **Order of independent stores** can only be found by search. A statement-order hill climb on the store lines found `func_003AC0D8`. decomp-permuter finds the same kind of change; it also tends to introduce `do { ... } while (0)` and `new_var` temporaries, which are harmless, but check that it did not change what the code does (it once moved an assignment into an `if`).

### Functions that save `$ra` with `sq`

Thirteen retail functions (`func_003869E8`, `0038C888`, `0038C9D8`, `003A6C30`, `003A9E60`, `003AAF88`, `003B3DB8`, `003B82C0`, `003BA5B8`, `003C0B10`, `003C1130`, `003D1B10`, `003D2370`) save `$ra` with `sq` in a 16-byte slot. gcc 2.95.3 writes `sd`, and when the function also saves `$s` registers it puts `$ra` in the lowest slot, where retail puts it in the highest (`$s0` lowest, ascending). No compiler or flag we have gives retail's layout, so `tools/asm_filter.py` rewrites it: list the function in `tools/sq_ra_funcs.txt` and every callee-saved save and restore is moved to retail's slot (same slot set, same frame size) as `sq`/`lq`. Write the C normally.

- A function with `$s` registers also needs the `-fopt-stack` flag removed (a single-function override in `tools/text_parts.txt`), because retail's `$s` saves are `sq`, not `sd`.
- `func_0038C888` and `func_0038C9D8` are done this way. `func_003A9E60` has the right slots and call; only its argument-copy registers differ (retail gives `$a0` the first temp, gcc gives it the last).
- A 64-bit argument that is moved with `daddu` must be `long`, not `s64` (`s64` produced a 128-bit `por`).

## Patterns from the third hand pass (2026-10, 13 functions)

- **Read a struct-typed global through its fields, with locals for the early reads.** `func_003A13B0` only matched once the two reads of `D_00225780` (`f30`, `f6C`) were locals at the top and the indexed table was a struct array (`D_160C40.e[idx].v[a]`, entry type 0x14C bytes) instead of pointer arithmetic. Retail's base-register reuse (`$a1` holds one global, then the other) follows from that.
- **Do not cache a field chain if retail re-reads it** (`func_003C0B10`): `obj->set->n` and `obj->set->arr[j]->e` written out each time matched; a local for `obj->set` did not. The same holds for plain fields: `func_003AC6F0` matched with `p->f8`, `p->f0` written at each use, where locals for them rotated `$a2`/`$a3`/`$t0`.
- **A base pointer that is hoisted to the top** (`addiu $a1, $a0, 0x70` before anything else) is a local `u8 *b = p->b;` declared first (`func_003932B0`).
- **Assign first, then test** (`func_003932B0`): `p->f74 = t; if (a < t) p->f74 = a; else if (t < 0) p->f74 = 0;` puts the first store in the branch's delay slot the way retail has it. The if/else form with the store inside each arm does not.
- **Boolean return from a comparison: write `if (r < 0) return 0; return 1;`** (`func_003AAAC8`). `return r >= 0;` (and `!(r < 0)`, `(r < 0) ^ 1`) compile to `nor`/`srl`, retail has `slti` + `xori 1`.
- **Search loops** (`func_0038EC80`, `func_00395BC0`): `for (i = 0; i < N; i++) if (tab[i].k == key) break;` followed by `if (i == N) return;`/`if (i < N)` gives retail's rotated loop. They need a struct with the exact element stride; the function itself is easy once the stride is right.
- **Loop over an index range** (`func_0039B0F8`): `for (i = lo; i < hi; i++) { dst[i].x = ...; }` with `lo`/`hi` read from a table matched; the pointer-walking version with `n = hi - lo` did not.
- **Float immediates and `$gp` floats together** (`func_003A3028`): `@ps2as` plus `__asm__(".extern X, 4");` for each `$gp` float/pointer global; initialise a loop offset inside the `if` that guards the loop (`off = 0;` before the `if` moves the `move` above the branch).
- **Typedef and extern names collide within a file.** A block's typedefs and `extern`s stay visible to every later block in the same source file, so give each function's types a suffix (`S_395BC0`), and give a global an alias symbol (`D_160C40_00395BC0` plus a line in `symbol_addrs_resolved.txt`) only when another block of the file declares it differently.
- **VU0 code that is not a pure leaf** (`func_003BFD10`): C around one `__asm__` block with `lqc2`/`vadd.xyz`/`sqc2` matched in no-split mode; a callee that other matched code declares with fewer arguments needs an alias symbol (`func_003BFC18_003BFD10`).
- **`div.s` with `nop`s in front** (`func_00393380`): matched as plain C once `tools/divs_nops.txt` handled the padding (see the `div.s` entry under Known open problems). Don't use the old inline-asm `nop; nop; div.s` workaround; it changes the register choice.
## More patterns from the third hand pass (switches, delay slots, aliasing)

- **Switch functions work now.** Write the `switch`; the compiler emits its own jump table in `.rodata`, so delete the `INCLUDE_RODATA(... jtbl_XXXXXXXX)` line after the function (`func_003A0178`, `func_0039BD48`). Case numbers must follow the retail table, not the order of the code: read `asm/nonmatchings/text/rodata/jtbl_*.s`, find which index points at each body, and put the bodies in address order. gcc only builds a table when at least five non-merged case nodes exist and it deletes cases that lead to the same place as `default`; to get retail's long table add cases that `break` but are not adjacent (`case 0: case 2: case 4: case 18: break;`), which keeps a 19-entry table.
- **A store that gcc pulls into a branch delay slot but retail does not** (`func_003ADBB0`): make that store volatile, `*(volatile s32 *)&D_001D9F40 = 0;`. Retail put the epilogue's first load there instead.
- **A reload of a pointer global after every store** (`func_00385570`, `func_00387B10`, GIF packet writers): declare the pointer global `s32` and write through casts of it (`*(s32 *)(D + 0x64) = a;`). An `s32` store may alias an `s32` global, so gcc reloads it; a store through a typed struct pointer does not reload.
- **Boolean ANDs of call results** (`func_003E3A80`): `t = f() != 0; ok = ok & t;` with a temporary matches `sltu` + `and`. Writing `ok &= f() != 0` makes gcc use `movz`.
- **Two arms where retail's branch-likely goes to the later block** (`func_003AAC70`): put the `!=` case first (`if (b->f4 != 4) {A} else {B}`), and the arm that falls through first in the second `if`.
- **Pointer arithmetic order** (`func_003AAC70`): `(s32)((u8 *)b + 8 + b->f30)` gives `addiu` before `addu`; `(s32)b + b->f30 + 8` gives the opposite.
- **Loop padding with a call in the body** (`func_003BD360`): `tools/asm_filter.py` now counts `jal`/`jalr` as one instruction when it pads short loops to 6.
- **A call with no argument moves** (`func_003E11D0`, `func_003E5F00`): retail's `jal` follows the prologue with `$a0`/`$a1` untouched even though the callee takes them. The original called it with the incoming registers still live, so call it through a zero-argument declaration: `extern void *func_003E1150_003E11D0();` (alias symbol, K&R, no prototype) and write `func_003E1150_003E11D0()`. gcc then emits no `move $a0, $s1`.
- **Boolean from a compare** (`func_003AAAC8`): `if (r < 0) return 0; return 1;`, not `return r >= 0;`.

## Patterns from the large-function pass (2026-10-02)

Five functions between 0x600 and 0x96C bytes (`func_0039DB38`, `func_003E3F08`, `func_003DF038`, `func_003DE8F0`, `func_00384420`), all S mode with `@ps2as`.

- **Small objects get the assembler's `la`, not gcc's split.** Under `@ps2as`, gcc treats an object of 8 bytes or less as small data and emits one `la`/`lw` macro, which Ps2EeAs expands to `lui`/`addiu` (adjacent, same register) when it has no `.extern` hint. A larger or unsized object gets gcc's split form instead (`lui` and `addiu` scheduled apart, `%hi` CSE'd). So when retail's `lui`/`addiu` for an address are adjacent, and the same address is rebuilt at every use instead of kept in a register, declare the object with its real small size: `extern s32 D_001DA868[2];` (an 8-byte buffer cleared with `func_00388440(p, 0, 8)`) or the 0x20-spaced hash tables at 0x1DA9C8 in `func_003E3F08`.
- **Which addresses stay in `$s` registers is gcc's allocation priority.** In a long run of calls that reuse table addresses (`func_003E3F08`), each repeated address is one pseudo; the ones with many uses over a short span win the callee-saved registers and the rest are rebuilt with `lui`/`addiu` at each use. If the wrong ones are cached, look for an object that is really small data (previous point) before reordering calls.
- **`volatile` on a global that is saved and restored around a call** (`t = D_001D9F40; f(); D_001D9F40 = t;` in `func_00384420`). Retail keeps both accesses out of the call delay slots, which only happens for a volatile access.
- **A hardware register read with the full address in a register** (`lui; ori 0x800; lw 0($v0)`): `*(volatile u32 *)0x10000800`. Without `volatile` gcc folds the low half into the load offset.
- **A byte constant address that must not land in a delay slot**: `*(u8 *)0x1D5477` instead of a declared global (`func_0039DB38`). A declared scalar is small data, so reorg puts its load in a delay slot and Ps2EeAs turns it into `$gp`.
  - The same works without a constant address when the variable is the next word of a declared global: `(&D_1D4A40)[1] = b;` instead of `D_1D4A44 = b;` keeps the store as `lui; sw` before the branch, where `D_1D4A44` goes into the delay slot as a `$gp` store (`func_0013B918`).
- **Loop-invariant copies come from member access in the loop.** Retail's `move $t0, $t2` before each loop (`func_0039DB38`) is loop.c hoisting `o + 0x38C` out of `o->an[o->idx][i]`. A local pointer (`an = o->an`) makes it disappear. Likewise a pointer that loop strength reduction creates (`lbu 4($a2)` with `$a2` stepping) comes from indexing (`raw[i + 4]`), not from a pointer variable in the source.
- **One variable per loop counter.** A counter shared by a loop with calls and a loop without moves both into a callee-saved register; give each loop its own variable. The same goes for a temporary reused for unrelated values (a save/restore temp and a swap temp in `func_00384420`).
- **Stores to one struct in retail's order A..J**: the "write B, C, ..., A" rotation applied to `func_0039DB38`'s ten stores only after a statement-order search; try permutations of the stores before anything else.
- **`(x ^ 1) == 0` and `(x ^ 1) & 1`** give retail's `xori` test where `x == 1` or `!(x & 1)` give `li`/`bne` or `andi`/`bnez` (`func_003DE8F0`, `func_00384420`). Bit 0 of a flags word read with `lbu` is `*(u8 *)&flags`.
- **Blocks of the same function with their own locals**: two branches that each pass `&w` to a callee use two stack slots in retail (`sp0`, `sp4`), so each branch declares its own `f32 w;` (`func_003DE8F0`).
- **`div.s` right after `mtc1` under `@ps2as`**: Ps2EeAs adds its own `mtc1` hazard `nop`, so the `tools/divs_nops.txt` count for that `div.s` is one less than retail's `nop` count (`func_00384420`).
- **`sqrt.s` that spimdisasm prints as `c1 0x504`** is missed by `gen_divs_nops.py`; check the table line has one count per `sqrt.s` too (`func_0038F3F8`, `func_00390730`). With the default flags, `sqrtf()` adds an errno check and a fallback call. The existing inline form is `__asm__("sqrt.s %0, %1" : "=f"(r) : "f"(sum));` with a separate input variable. For a plain-C candidate, see the native compiler probe below before adding assembly.

### Native single-precision square root

SN ee-gcc 2.95.3 v1.36 can emit `sqrt.s` from plain C. An isolated probe on
2026-10-03 compiled `sqrtf(value)` and `__builtin_sqrtf(value)` with the existing
`-O2 -G8 -mno-split-addresses -fopt-stack -mno-check-zero-division` flags:

| Additional flags | Function size | Native `sqrt.s` | Calls in that function |
|---|---:|---:|---:|
| none | 44 bytes | 1 | 1, errno/fallback path |
| `-ffast-math` | 12 bytes | 1 | 0 |
| `-O3 -ffast-math` | 12 bytes | 1 | 0 |

The source used a correctly typed `extern f32 sqrtf(f32);` declaration and no
inline assembly, forced register or approximation. The correctly typed double
`sqrt` probe still needed conversions/calls, not the same single-precision leaf.
The spelling `__builtin_sqrt` remained an undefined symbol in a separate probe;
no supported double-precision builtin ABI is inferred from that result.
`-fno-math-errno` is not accepted by this
compiler's `cc1`.

This proves compiler capacity, **not** a matching game function or numerical
equivalence for arbitrary inputs. `-ffast-math` may also alter surrounding
floating-point evaluation and NaN/unordered comparisons. Try it only as a
scoped candidate configuration; compare the complete compiled function,
including padding, all branches and fully resolved relocations, against retail.
Never remove an errno/libm call by relabeling it as a native instruction or
replace square root with an approximate routine to obtain a match.

### Declarations in the source files

A function sees the declarations at the top of its file (from earlier files), every earlier block of its own file, and nothing from later files. A file with mixed flags is compiled in slices, and a slice only sees the *declarations* of the file's earlier blocks, never their definitions. So:

- A call to a function that is defined in another file, or in another slice of the same file, still needs its own `extern`.
- An `extern` in your block must agree with that function's definition if both end up in the same file (or slice). When they differ, use the definition's types and cast at the call, or align the other `extern` lines to yours (callers that ignore the result are unaffected when the return type changes from `void` to `s32`).
- A K&R declaration `extern s32 f();` followed by a prototyped definition with `u8` or `s16` parameters is a conflict; use a prototype.
- A function called with a different argument count than its existing prototype needs a cast call: `((s32 (*)())f)(a, b)`.

## Families

Many functions are near-copies. Once one is matched, the rest usually go fast:

- **`isA` checks through a vtable at `+8`:** `if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) { func_X(p, a, b); return 1; } return 0;`
- **8-slot hash tables (`HT_8`/`HE_8`):** `h = ((key & 7) + ((key % 7) * i + i)) & 7;` over 8 probes, with a sentinel value.
- **Getters/setters on the big state struct at `0x142430`**, each with its own aliased declaration.

If you find a family, say so in your PR. It helps the next person.

## Known open problems

Leave these for now, or open an issue if you crack one:

- **Resolved (hand-written): `lwc1 $fN, off($gp)` followed by `nop`** (`func_003882D0`, `func_00388308`, `func_00388340`, `func_00388378`, `func_00388388`). Not a C problem. Retail has the same load-then-jump-then-use shape unpadded 19 other times, so the `nop` is not something a compiler or assembler adds: SN gcc's `-S` output has none, and neither GNU `as` (any `-mips`/`-mcpu`) nor Ps2EeAs inserts one. The five sit in the hand-written math range (0x3882D0 to 0x388388) between functions already classified as hand-written, so they are `ASM_FUNC` now instead of C plus an `__asm__("nop")` hack.
- **Resolved:** 64-bit constant synthesis `li 0x8000; dsll 24` (`func_00383B08`): pass the constant as an `unsigned long` literal with `@ps2as`.
- **Resolved: `div.s`/`sqrt.s` `nop` padding** (`func_003E1D18` and 69 other functions). Retail pads most `div.s`/`sqrt.s` with 0 to 3 `nop`s; no rule predicts the count, and both assemblers delete explicit `nop`s in reorder mode. `tools/asm_filter.py` now puts them back as raw `.word 0` lines, driven by `tools/divs_nops.txt` (one line per function: `func_0037E568 2`, one count per `div.s`/`sqrt.s` in order). Run `python tools/gen_divs_nops.py` to add lines for every function that is still `INCLUDE_ASM`; existing lines are kept so a function keeps its padding after it is decompiled. If the number of `div.s`/`sqrt.s` in your C differs from the table, the function is left unpadded. First function matched this way: `func_0037E568`. Functions that were already in C without the table are not in it.
- **Resolved 2026-10-06: register allocation where retail keeps an argument in a temporary (`move $t3, $a0` at entry) while `$a0` holds something else** (`func_0039BEC0`): solvable in C. The cause is gcc's priority order (see `tools/regalloc.py`): a block-local temporary outranks the parameter and overlaps it, so the parameter is pushed out of its incoming register. Two changes reproduce retail's exact allocation for `func_0039BEC0` (`screenId` `$t3`, the `-2` constant `$a0`, `result` `$t2`, `flag` `$t1`): declare `D_001A7430` unsized (`extern s32 D_001A7430[];`, read as `D_001A7430[0]`), because retail reaches it with a compiler `lui`, and write the flag as `s32 flag = (screenId >= 0) ? D_001D5B78[screenId] : 0;`. That takes the diff from 1,680 to 210; what is left is the branch shape (which instruction lands in the `bltz` delay slot). The forms that get the registers right changed the branch layout, and the forms that got the layout right changed the registers. It matched in the first final pass under `@ps2as`, with a one-element alias of `D_001DA050` and `do { flag = 0; } while (0);` (found with f2's `do { } while (0)` brute force).
- **Resolved: "a match in isolation can still differ in the full build".** `func_003AEDC8` and `func_003AED08` passed `check.py` but failed the full build with two `$gp` stores swapped. The cause was the tool, not the build: it masked every relocated field, and two stores through `$gp` differ only in their relocated offsets, so the wrong order looked identical. `check.py` now fills relocations in with the symbols' real addresses and compares them in full (checked against all 617 previously matched blocks: no false failures). The `#define D_001D5B34 ...` hack macros above some functions still replace a later `extern` of the same name; `#undef` it in your block (see `func_00389908`).
- About 20 matched functions use inline `__asm__` or a hand-rolled `$gp` register. They count, but plain-C rewrites of them are welcome.
- **Init order before a loop:** loop-invariant constants gcc hoists (a divisor `3`, a `&symbol`) land between the loop variable's init and the other inits. To reproduce retail's order, name them as locals and assign in retail's order (`i = 0; three = 3; sent = &sym; off = 0;`, then `for (; i < 3; i++)`). Matched the three 3-slot hash lookups func_003E4890/4918/4DA0.
- **A quad store that the scheduler moves behind a narrow store:** make that one `sq` store volatile (`*(volatile u128_t *)(d + 0) = ...`) and keep the narrow stores plain; retail's `sq, sb, sh` order then holds (`func_0037FEE8`). Also: a down-counting `n` that retail keeps in the callee-saved register ahead of a copy of `q + 0x41DC` wants `n--` in the loop instead of `m = n - 1; n = m` (`func_003E0478`). A `do { h = f(&s, 1); } while (h == 0);` poll loop followed by `do {} while (g(h) >= 0);` matches the retail pair of raw-branch loops (`func_003AB180`).
- **`D[idx].field` against a cached pointer:** `&D[idx].f380` folds the field offset into the symbol (`lui; addiu D+0x380; addu idx*size`), while `p + 0x380` from a cached `p = &D[idx]` adds it to the register. When retail shows an extra copy of the element address, or an argument built as `(D + off) + idx*size`, write that access as `D[idx]...` with a struct type for the element instead of reusing `p` (`func_003809F0`; also matched with `u128_t` fields for the `lq`/`sq` pairs). A 16-byte struct of `u8[16]` assigned through a local gives the `ldl/ldr, sdl/sdr` pairs (`func_003E0930`). Passing the callee's float arguments before its integer ones in the prototype moved a `mov.s` into the right slot (`func_0038CA08`).

### Forms this compiler has never been seen to produce (2026-10)

Two shapes showed up while trying to match the smallest functions still filed as `plain`.
Neither is a C problem: if your target's `.s` contains one of them, move on to another
function rather than rewriting the C.

- **`lq $at` - `$at` as a data register.** Compiling the same three-quadword copy
  (`*(u128_t *)` at 0x00/0x10/0x20) with the range's flags allocates `$2`, `$3`, `$6`;
  `$at` is not something this compiler hands to a value. In `frontbin.elf` the only
  files containing `lq $at` are the nine under `asm/handwritten/`, plus
  `func_00388E58` and `func_00388E38`, which are now `ASM_FUNC` there too (2026-10-05:
  `tools/triage.py` files `lq`/`sq $at` and the COP0 performance-counter ops as hand-written).
- **`sq $zero` - a 128-bit zero store.** `*(u128_t *)p = 0;`, `(u128_t)0` and a named
  `register u128_t z = 0;` all compile to `por $2,$zero,$zero` followed by `sq $2,0($a0)`:
  the TImode zero is materialised in a register first, so retail's single `sq $zero` is out
  of reach from plain C. Resolved 2026-10-05 with the `QZERO` inline-asm macro (see the
  blocker pass below): the original used inline asm for it.

A third shape from the same pass, `sq $31` / `lq $31`, has a workaround rather than a dead
end - list the function in `tools/sq_ra_funcs.txt` (*Functions that save `$ra` with `sq`*
above); `tools/pr_check.py` now warns when a function that is C in `src/frontbin/` has the
signature in retail and is missing from that list. What the pass did settle is that no flag on this compiler produces it, which is
what the next section is about.

Reproduce any of them from the repo root:

```
python tools/try_func.py <your attempt>.c func_XXXXXXXX      # the ordinary judge
python tools/try_func.py <your attempt>.c func_XXXXXXXX --all-modes   # 4 flag/assembler combos
```

Two more things worth knowing before a long session: `sizeof(long)` is 8 here, so the
64-bit type is `unsigned long` (`long long`, and therefore `u64`, is 16 bytes and any
arithmetic on it fails with `unsupported wide integer operation`), and the literal suffix
`ULL` is rejected by this compiler - use `UL` or a cast.

#### The SN ProDG 2.0 package emits the `sq`/`lq` saves natively

The `sq $31` layout is not only reachable through `asm_filter`: the **SN ProDG 2.0**
package's `ee-gcc295.exe` (gcc 2.95.2, SN build v2.73a - a separate download, not the
3.01 package this repo builds with) emits `sq $31` / `lq $31` by default, puts `$ra` in
the highest callee-saved slot with `$s0` lowest, and does not know `-fopt-stack` at all
(`cc1.exe: Invalid option`).

Measured on the C bodies of `func_0038C888` and `func_0038C9D8`, **assembled and compared
word for word** rather than read off the `.s`: 2.0's output for both is byte-identical to
retail, the `jal` operand aside, while 3.01 at the project flags differs in the two `$ra`
accesses only. Nothing in 3.01's flag space moves those two: `-O1/-O2/-O3/-Os`,
`-G0/-G8/-G16/-G24`, `-mgp64`, `-mips3`, `-mips4` and `-fopt-stack`/`-fno-opt-stack` all
keep `sd $31`. On this compiler `-fopt-stack` only governs the **`$s` slots** (16-byte
`sq` without it, 8-byte `sd` with it), never `$ra` - which is why the layout the filter
reproduces was never a flag away.

The same test on the two larger matched functions, `func_003AAF88` and `func_003C0B10`,
splits the claim in two. 2.0 gets retail's **frame** right with no filter at all: same
frame size, `$sN` in the 16-byte `sq` slot at `0x10*N`, `$ra` highest - where 3.01 needs
`-fopt-stack` removed and the filter's rewrite to get there. But it does not emit them in
retail's order: retail saves the registers ascending by slot, 2.0 descending (on
`func_003AAF88`, 2.0 saves `$s3, $s1, $s0`, retail `$s3, $s0, $s1`). Those two bodies are
the C that makes 3.01 match, so a compiler swap would mean re-tuning them, and re-tuning is
what the filter avoids. 2.0 also emits the `lq $at` bodies above exactly as 3.01 does, and
the `sq $zero` body too (`por $2,$zero,$zero` + `sq $2,0($a0)`, unchanged), so the package
is a stack-slot signature and nothing else.

One of those tests is done: `func_003A9E60` (0x8C, reconstructed from its retail
disassembly alone, flags `-O2 -G8 -mno-split-addresses -mno-check-zero-division` plus the
unsized `D_001D5C78[]` declaration the range needs) comes out with retail's frame and slots
under 2.0 and with 3.01's layout under 3.01 - but both compilers leave the **same 22 of 35
words** different, all of them the argument-copy registers (`a0` lands in `$s1` where retail
uses `$t5`, and the `lui` takes `$2` where retail takes `$12`). So 2.0 does not fix this
one's schedule either; that half looks like allocation, not a compiler version.

So the layout is a real version signature and the arithmetic is unsettled. It is four
functions, and only the two wrappers are byte-exact; nine of the 13 still have no C block
at all. Most of the file still matches 3.01 at the project flags, so retail only
**possibly** looks like an intermediate SN release - 2.95.3-era instruction selection with
the older 16-byte stack slots - rather than a mix of two packages. Writing C for more of the
13 and running the 2.0 package against them is the cheap next test; the compiler/flag
matrix in `docs/compiler_matrix_findings.md` (15 builds) does not include this package.

## Patterns from the first agent batches (2026-10-03)

Each was confirmed by a function that now matches in the full build.

- **Pass the incoming parameter to a K&R call that doesn't need it.** In `func_003B7568`, `cb(a)` instead of `cb()` raises the parameter's priority, which flips which of two saved registers it gets.
- **Two loops, two counters.** Reusing one `i` for both loops of `func_003B2958` swapped `$s0`/`$s1`. A separate `j` for the second loop, indexing a `[2]`-sized `$gp` array as `D_arr[j]`, gives retail's pointer plus count-down loop (`bgezl`).
- **Table walk with an end marker:** `for (p = arr; *p >= 0; p++)` gives `move; lw; bgez; addiu` with the increment in the delay slot (`func_003D46E0`). A do-while with `v = *p++` doesn't.
- **`lui $v0; lh $v1, %lo(X)($v0)`** (the load into a different register than the `lui`) comes from reading through an unsized array alias, `X[0]`, not a raw `*(s16 *)0x1CD018` (`func_003A3430`).
- **Reuse the incoming pointer as the walking pointer** (`arg += 8; ... func(arg, arg + b, ...)`) instead of new `p`/`q` locals, which add a `move` and change register numbers (`func_003972A0`).
- **A select assigned to a new local** (`q2 = q - w`) changes which instruction fills the `jal` delay slot (`func_003ABB60`).
- **Two reads of the same `lui` global around calls** need a scalar `extern s32 X;` under `@ps2as`; an unsized array shares one `lui` across the calls (`func_003ABB60`).
- **`(flag >> 24)`** gives a bare `sra` where retail has one; the callee's parameter order sets the order of float register setup (`func_003A4DC8`).
- **Declaring a callee `s32` instead of `void`** changes the `$v0`/`$v1` choice around the call; a K&R zero-argument declaration leaves the argument registers untouched (`func_003B8968`).
- **Index an array in a loop instead of walking a pointer** (`func_003C1950`): `e[i].t`, `e[i].id` let gcc strength-reduce to a pointer whose start sits in a temp and is `move`d into the saved register, as retail does. A hand-written walking pointer gets other registers.
- **Count-down loops written `for (i = N; i != -1; i--)`, one counter per loop** (`func_003A9768`, `func_003A8060`): this decides which register holds the `-1` constant.
- **Store order sets delay-slot filling** (`func_003A5A90`): zero stores written `t[1]`, `t[2]`, `t[3]`, `t[0]` matched; ascending order did not.
- **K&R definition** when callers use an unprototyped `extern void f();` with another argument count (`func_003A5A90`); a prototyped definition makes those callers fail with "too few arguments".
- **64-bit values are `long` / `unsigned long`**, not `u64`/`s64`, or gcc reports an unsupported wide integer operation (`func_003D14D0`).
- **Float arguments need a prototype for the callee**, or gcc promotes them to double (`func_003A5DF0` went from 33 to 63 diffs without one).

## Patterns from agent batches 4 to 17 (2026-10-04)

Each was confirmed by a function that now matches in the full build.

- **The callee's return type changes the caller.** `extern void f();` versus `extern s32 f();` (or the real `s32 *`) moves registers and scheduling even when the result is unused. It was the deciding change for `func_003B0608`, `00397380`, `003C8D50`, `00384C98` and `003E0FC8`. Try the callee's real prototype, or `s32`, before anything else.
- **Size hints choose the address form of a scalar extern:** `__asm__(".extern X, 4");` before first use gives `$gp`; `.extern X, 16` gives the macro `lui` form even for a scalar; an unsized array read as `X[0]` gives the split `%hi`/`%lo` form (`func_003C8D50`, `003B0608`, `0039AAF0`, `0039C028`).
- **One variable, two address forms:** when retail reads the same address through both `$gp` and `lui`, declare two names for it and give only one the `.extern X, 4` hint (`func_003968F8`, `00396120`, `00396680`, `0038EB10`). This is one of the cases where an alias is a real technique, not a leftover.
- **Adjacent `$gp` objects need separate names**: an array base for several of them gets shared by gcc (batch 15).
- **A switch tree with `slti`:** a `switch` with only `case 1` and `case 2` gives `beq; beq`; retail's `beq 1; slti 2; ...` tree appears when the switch also has a `case 0:` (`func_003A6520`).
- **A one-element array declaration** (`u8 D_X[1]`, or a sized `T D_X[2]`) instead of `u8 D_X[]` changes whether the address is built before the call or split around its delay slot (`func_003E1F40`).
- **Calling a K&R extern with fewer arguments than it reads** matches retail where it passes only some registers; adding the extra arguments adds instructions (`func_003BE418`, `func_0039C028`).
- **Reuse the parameter as the working pointer** (`a0 = ...; a0[0] = ...`) to keep it in `$a0`; a fresh local lands in `$v1` (`func_0039C028`).
- **Early returns:** a `bnel` followed directly by the "return 0" block comes from `if (x == 0) return 0;`, not from nesting (`func_003822C8`).
- **Stores of different constants to one global in several branches:** write the separate stores with no result variable; gcc tail-merges them into one `sw` with retail's registers (`func_00396680`).
- **Index a struct-array member each time** (`D.row[a].f`) rather than taking a row pointer once; the pointer form folds the member offset into the base register (`func_00395AC8`).
- **Same family, different data:** adapt a matched sibling and change only the callee and the table global (`func_003E1F40` from `func_003E1E50`).
- **Extra compiler flags are a per-file question, not a per-function trick.** The original build set flags per source file, so a flag a function needs must also leave every other function in its file matching. Check that before adding one: compile the file's other C functions with it (`check.py --flags="-fno-..."` on each).
  - `-fno-force-mem` (needed by `func_0039A040`): all 88 C functions in `3958F0.c` still match with it, and 1069 of all 1123 do. It's the flag on `3958F0.c`'s file line. It is **not** file-wide in practice: `func_00397490`, `func_0039ABB0`, `func_00399C90`, `func_003959A8` and `func_0039A3B0` need `-fforce-mem` (the default) and each has a single-function override without it (see the `func_00397490` section below; the `or`/`addu` operand order shows it). So either the file boundaries there are wrong or the original did not set it per file.
  - `-fno-schedule-insns` (now only `func_003C8D50` and `func_00384C98`; `func_003AD650` lost its override, see the blocker pass below): 524 of the 1123 C functions change with it, so it wasn't a project-wide flag. Around those two, the C functions that still match with it form runs of only 3 and 1, so each would have to be its own small source file. That is possible (our file boundaries are estimates), but unproven. They stay single-function overrides; if more neighbours turn out to need the flag, that's evidence for a small file there. A test on 44 scheduling near misses (`tools/try_func.py --flags="-fno-schedule-insns"`): 0 matched and 44 got worse, so the flag is not a general fix for instruction-order near misses.
  - `-fno-schedule-insns2` was on: only 392 of the 1123 C functions still match without it.

## Patterns from agent batch 19 (2026-10-05)

- **A `long` working variable keeps a `movz` chain:** with `int`, gcc folds `r = 1; if (x == -2) r = 0;` into `xor`/`sltu`; with `long` (and a `long` return) it emits retail's `movz` chain.
- **`t = &A; p = &B; if (a0 == 0) p = t;`** loads the two addresses in the same order as retail's `movz $a2, $a1, $a0`; a ternary or if/else swaps them.
- **Statement-order search pays off early:** the order of a function's first few statements alone moved results between 5 and 46 differing words; a brute-force search over them matched `func_00394B38` and `func_00394F78`, and a random-swap search over store order matched `func_0039C7B0` and `func_0039C8A8`.
- **`for` versus `do { } while`** can change which registers a loop counter and its copy get (`func_003D98D0` needed `for`). Try both.
- **A guarded hardware wait loop:** `if (r & 0xF0) { do {} while (r & 0xF0); }` with `r` a `volatile` hardware register read gives retail's shape; a plain `while` gives the unguarded form (`func_003AC5E0`).
- **Callees with float arguments:** if retail loads `$f13` before a call, the callee's real prototype has more float parameters than the call seems to need. Check its definition.
- **No `#define` in a function block:** `split_text.py --refresh` copies a block's macros into later files like any declaration.
- **`-fno-schedule-insns` never helped a near miss:** tried on about 25 near misses, it made all but one worse and fixed none. The remaining differences in near misses are register allocation and statement order, not scheduling.
## Patterns from the blocker pass (2026-10-05)

A pass over the remaining `INCLUDE_ASM` functions, sorted by what each one needs. Each item below was confirmed by a function that now matches in the full build.

- **`sq $zero` is inline asm, resolved.** The compiler never stores a quadword zero directly: a zeroed `u128_t` always comes out as `por $v0, $zero, $zero; sq $v0`. Retail's bare `sq $zero, off(reg)` (the 16-byte zeroing loops in `func_003A0010` and `func_003A2DF8`) therefore came from an inline-asm macro in the original source, the same conclusion Lombyte's `qzero.h` reached for other Insomniac binaries. Use

  ```c
  #define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
  ```

  An asm with no outputs is implicitly volatile, so the `__volatile__` is just documentation; the `"=m"` output form is the only one that is not. Write the loop with the index in the address, `QZERO(D_1A3100 + i * 0x10)` for `i = 3; i >= 0; i--`, not with a running pointer: the running pointer makes gcc keep a second `lui` in a saved register and grows the frame (`func_003A0010`).
- **Which register comes first in `addu`.** For a C pointer plus an integer gcc always puts the pointer first in the tree, so `base + off` gives `addu $v0, $base, $off`. When retail has the offset register first, write the sum as integers with the offset on the left: `(u8 *)(off + (s32)b)`. For a loaded base, load it into a local first (`g = *(s32 *)0x1D4B38; base = g + off;`). Matched `func_0037F4F8` (a VU0 function: `lqc2`/`vadd.xyz`/`sqc2` in `__asm__` around plain `u128_t` copies).
- **A `do { } while (0)` macro changes scheduling.** Wrapping the loop's increment in a statement macro, `#define ADVANCE(o) do { (o) += 0x27E40; } while (0)`, reorders gcc 2.95's output enough that `func_003AD650` matches at the project flags; it needed `-fno-schedule-insns` before. Try this before reaching for a flag when the diff is only the position of an increment or a store.
- **Hand-written code the tools now flag.** `tools/triage.py` classifies as hand-written any function that reads or writes the COP0 performance counters (`mfpc`/`mtpc`, which spimdisasm cannot decode) or that uses `$at` as the data register of `lq`/`sq`; no compiler emits either. Seven functions moved to `asm/handwritten/` on that rule: `func_0039BC18`, `0039BC40`, `0039BC70`, `0039BC80`, `0039BCC8` (performance counters) and `func_00388E38`, `func_00388E58` (`$at` quadword copies).
- **Keep one prototype per callee across files.** The split build copies declarations from earlier files, so `extern void func_13B620();` in one file and `extern s32 func_13B620(void);` in another is a compile error in `pr_check.py` and the file check of `try_in_context.py`. Fix the older declaration (it was `void` only because that file ignored the result) rather than adding an alias.

## Patterns from `func_00397490` (2026-10-05, 0x21CC bytes)

The memory card state machine in `3958F0.c`, the largest function that was still `INCLUDE_ASM`: an outer 32-way switch on the state field and seven nested switches (9 jump tables, now emitted by gcc). Matched at `@ps2as` without `-fno-force-mem`.

- **`-fno-force-mem` shows as operand order.** `D.f188 += x` compiles to `addu rd, f188, x` in retail. Under `-fno-force-mem`, gcc's `expand_binop` swaps commutative operands while the first one is still a memory reference, giving `addu rd, x, f188`. Dropping the flag for this function took it from 280 to 238 aligned diffs.
- **An address-taken small-data symbol under `@ps2as` is one `la` macro.** Declaring `D_001D545C` as a scalar `extern u32` (its real type) instead of an unsized array gave retail's register allocation: `la` is one instruction (one pseudo) to gcc, the split `%hi`/`%lo` form is two. `&D_001D6318` in the same function is reached through `$gp`, so it gets `__asm__(".extern D_001D6318, 4");`. That pair is what identified `@ps2as`.
- **Where retail recomputes the global base (`addiu $X, $s2, 0x2430`) only after a join, the source has a real if/else join; where it reuses the case's base register, the source has separate exits** (duplicate tails ending in `break`) that gcc tail-merges. Write the struct accesses directly (`D.field`), no local pointer.
- **Cross-jumping keeps the later copy.** An earlier duplicate tail becomes a jump into the later one, so when retail jumps forward into another case's code, both tails must be byte-identical (same store order and registers).
- **Error-code chains store the field in every arm** (`if (r == -5) D.f16C = 0x15; else if ...`). An `e` temporary turns the last arm into a `movz`.
- **Reset-store order:** retail's `f154, f15C, f14C` comes from source order `f15C = 0; f14C = 0; f154 = 0;` (the store rotation documented above). Most of the last 150 diffs were store order.
- **No shared temporaries across the cases of a big switch.** One function-level `s32 t` reused in several cases pushed values into callee-saved registers everywhere; making them block-local took the diff from 544 to 278.
- **Strength-reduced loop pointers:** retail keeps three pointers into a 0x40-byte table (`entry`, `entry+0x20`, `entry+0x25`). That came from `de = &tbl[i]` for `de->size`/`de->name[4]` plus `tbl[i].name` for the string arguments; other combinations gave two pointers.
- Smaller ones: `func_11B2E8` (sprintf-like) must return `s32`, and `func_0038E6D0` is called through an `s32` cast, to keep `$v0` live. A `total + 1` that retail evaluates first needs its own temporary, since gcc reassociates `total + 1 + q`.
- **Tooling for very large functions:** `check.py`'s positional diff is unusable until the size matches. An aligned diff (difflib over the disassembly, branch targets mapped to labels) made progress measurable from 883 diffs to 0.

## Patterns from batch 21 (MMI bucket, 2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Check drafts with `try_in_context.py`, not only `check.py`.** `check.py` sees the extern declarations of earlier blocks but not their definitions, so a callee defined earlier in the file becomes an implicit `int` and gives false diffs (`func_003D1650` went from 23 diffs to MATCH in context; `func_0037F588`).
- **GS/GIF packet writers:** `long **pp` with `*(*pp)++ = value;` under `@ps2as` matches quickly. If callers declare the first parameter `s32`, define it `s32` and cast inside (`func_003D1E68`).
- **An earlier block's `.extern X, N` hint forces `$gp` for the rest of the file.** Where retail uses `lui` later in the file, use a per-function alias with no hint. Ps2EeAs still uses `$gp` in delay slots (`func_003D2878`).
- **A volatile read steers delay-slot filling**, since gcc keeps volatile loads out of delay slots (`func_00380AB0`).
- **Write symbol+offset constants inline** so related-value CSE picks retail's anchor register (`func_00381F18`).
- **`$s` registers saved with `sq` but no `$ra`** take the same fix as the sq-`$ra` functions: an entry in `tools/sq_ra_funcs.txt` and no `-fopt-stack` (`func_003D1978`, `func_003D3780`).
- **Rebase:** a `u8`-array access to `X + off` followed by stores through a local struct pointer gives retail's `addiu $s0, $s0, -off` (`func_003B8168`).
- **Chained assignment** `a = b = f()` gives retail's store order (`func_003BA490`).
- **Ps2EeAs fingerprint:** it expands the constant `1 << 63` as `addiu -1; dsll32 31` (`func_003B82C0`).
- **`plzcw`** has no C form: `__asm__("plzcw %0, %1" : "=r"(d) : "r"(d)); d = 30 - d;` (`func_003D1650`, `func_003D1E68`).
- **A dead 16-byte stack copy** is an aligned 4-float struct local, not a volatile `u128` (`func_003CB748`).
- **Open question:** `func_003CB5B0` declares `D_001D9350` as `s32[2]` with `.extern D_001D9350, 8` to get the `$gp` form, but retail reads 16 bytes from it with `lq`. The 8 steers codegen and is probably not the real size.
- **Fixed (batch 29):** the sq-`$ra` rewrite in `asm_filter.py` used to treat `ld $16/$17` stack-argument loads as restores. It now counts only loads of a saved (register, slot) pair, and `func_00386D98` matched.

## VU0 j-form: one asm statement per instruction

Status (2026-10-07): the leading explanation for VU0 code that is interleaved with ordinary code, and kept in the build. The maintainer has not formally approved it yet: each such block starts with a `PROVISIONAL, VU0 j-constraint form` comment, its override line in `tools/text_parts.txt` says `PROVISIONAL VU0 j-constraint form`, and agents commit each one separately as `func_X (jform)` so it can be dropped. `grep -rn "PROVISIONAL" src/frontbin tools/text_parts.txt` lists them. 38 frontbin functions are matched this way (first `func_003DCD08`, `func_003C0188`, `func_003813E0`; then 27 in round d and more in the final passes). Flag any new use in the PR.

### The form

Each VU0 instruction is its own **non-volatile** `__asm__` statement. VU0 values are TImode variables, and their operands use the `j` constraint, which is SN cc1's VU0 register class:

```c
typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
Q_3DCD08 x, y, r;
__asm__("lqc2 %0, %1" : "=j"(y) : "m"(D.v0));
__asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001D9E90));
__asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
__asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)b) : "j"(r));
```

gcc allocates the `$vf` registers and its scheduler moves ordinary instructions between the VU0 ones, the way retail does. A volatile asm is a scheduling barrier in gcc 2.95, and a non-volatile `sqc2` asm without a register input ties with a neighbouring move and keeps source order; with `j` operands the `sqc2` depends on the `vsub` result, so the move goes first, exactly as retail (`func_003C0188`: the best volatile form stops at 2 diffs, the j-form matches). The one-block volatile form in [VU0 code: inline asm](#vu0-code-inline-asm) still matches where retail keeps the VU0 sequence together; try the j-form when retail has argument moves, constants or `lq`/`sq` copies between VU0 instructions.

- gcc prints the registers as `vf1` (no `$`); Ps2EeAs accepts that.
- The `"m"` operand's type decides the address form. A struct of four floats (BLKmode) gives retail's split form, `lqc2 vf1, %lo(D_00222480)($16)` with the `%hi` kept in a saved register. A TImode operand gets its full address in a register (`addiu; lqc2 0($r)`). A small-data scalar (`extern f32 D_001D9E90;`) is printed as the bare symbol and Ps2EeAs expands it with `$at` (`func_003DCD08`). Vectors that are `lqc2` operands on the stack need `__attribute__((aligned(16)))`.
- A `j` value that is live across a `jal` is spilled with `sqc2`/`lqc2` to the stack (vf1 to vfN are call-clobbered, there are no callee saves), which is where many of retail's `sqc2`/`lqc2` to `$sp` come from.
- Struct arguments passed by value are passed by reference under EABI and copied by the callee. Retail's `sqc2` into a temporary before such a call is written as an `sqc2` with an `"=m"` output into a local, then a by-value call (`func_00383BB0`).

### Getting retail's registers

- **Statement order matters**, and so does which variable each temporary and result uses. Write the statements in retail's order. Give each `vsub` a **fresh output variable** rather than writing the result back into an input (`func_00383BB0`: `y0`, `y2` for the two differences of the cross product). `func_003DCD08` needed a separate result variable per operation in one case and the result in the first operand's variable in another; try both.
- **The load order decides the vf1/vf2 roles.** When the same VU0 sequence appears with the roles swapped, use two `static __inline__` helpers that differ only in which operand they load first (`vaddA_383BB0` loads `a` then `b`, `vaddB_383BB0` loads `b` then `a`; `func_003869E8`'s helpers load `a` then `b`).
- **Block-local temporaries** let repeated blocks get different registers, the way retail's do (`func_003B92B8`, `func_003B9DA8`).
- **A struct-member global as an `"m"` operand: write it as a cast byte offset.** `"m"(*(V4_3A04A0 *)((u8 *)&D_1A4BE0 + 0x80))` keeps retail's `%lo(D_1A4BE0+0x80)($s3)` addressing, with the `%hi` in a saved register. Written as `"m"(D_1A4BE0.f80)`, CSE rewrites the address as an offset from the struct base in another register. In `func_003A04A0` the cast form also fixed three register swaps.

### `-mvu0-use-vf0-vfN`: what it is, and why N = 2

SN's cc1 only accepts `j` with the target option `-mvu0-use-vf0-vfN`; without it any `j` operand fails ("fixed or forbidden register ... for class VU_REGS"). Since 2026-10-07 every frontbin and boot_elf line in `text_parts.txt` carries `-mvu0-use-vf0-vf2`, so the j-form needs no extra flag. What agent m1 found (round k):

- **Origin.** The cc1 help text is "Specify the range of vu0 registers to use", and the cc1 binary's build path is `C:\usr\PS2\gcc-2.95.3\gcc`: it is Sony's own gcc patch set, not an SN addition. `j` selects register class `VU_REGS` and is the only VU0 constraint letter SN has; there are no other `-mvu0-*` options.
- **Parsing.** The text after `vf0-` is compared with the names `vf0` to `vf31`; on a match vf1 to vfN become allocatable. Anything else (`vf32`, `vf99`, `31`, `abc`, empty) silently means vf31. `vf0-vf0` gives no registers, so every `j` asm fails. Only `vf0-` is accepted as the lower bound (`-mvu0-use-vf1-vf8` is rejected). vf0 is always fixed.
- **It never makes the compiler use VU registers on its own:** TImode copies stay `lq`/`sq`. Explicit `"vfK"` clobbers work with or without it.
- **Other compilers.** Sony's Windows builds (2.9-ee-991111 Win, 2.95.2-273a/274, 2.95.3-107/114/136) accept the option and `j` with identical behaviour. 3.2-040921 has a rewritten version (`-mvu0-use-REG1-REG2`, class `VU0_REGS`, letters `j` and `C` plus Q/R/Y/Z for the VU0 special registers). The Linux builds (990721, 991111-01, -dtls, 991111a, 2.96) reject it.
- **N changes ordinary code.** The range adds N to `n_non_fixed_regs`. In GCC 2.95.3's loop.c, `scan_loop` hoists invariants against a threshold of `(call ? 1 : 2) * (1 + n_non_fixed_regs)` and `strength_reduce` uses `(call ? 1 : 2) * (3 + n_non_fixed_regs)`, so N moves loop-invariant hoisting and induction-variable reduction in functions with no VU0 code at all. Examples: `func_003BAE98` has 122 diffs with vf31 (`i < 2` is hoisted out of the inner loop) and matches with vf2; `func_003A1438` has 234 with vf31; `func_003D3FA0` stays at 4 with vf31 and matches with vf2. Old drafts measured with vf31 or without the flag must be re-measured.
- **Only N = 2 fits everything.** A sweep of the 38 frontbin j-form matches over N = 1 to 32: 31 match at 2 to 32, three only at 2 (`func_00383BB0`, `func_00392A40`, `func_00392DD8`: at N >= 3 the allocator uses vf3 where retail has vf2), `func_003A1438` at 2 to 24, `func_003BAE98` at 2 to 28, `func_0039EB98` at 1 to 32. N = 1 can't compile 37 of them.
- **Global builds.** With the flag on every line: at N = 2 only `func_003B22C0` (and its boot_elf twin `func_003B7A80`) break, two prologue constants hoisted in swapped order; at N = 3 or 4 five functions break, including `func_00381A50`, which has no VU0 code; at N = 31, 22 break. i5bootn matches at every N. `func_003B22C0` matches under vf2 once the struct global is used directly instead of through a local pointer (`D_00160C40_003B22C0->f4954, (s32)D_00160C40_003B22C0->f7080` in the call, no `S_B22C0 *p` local); that form matches at no flag, vf1 and vf2 and fails from vf3, another N <= 2 bound. The same edit fixed `func_003B7A80`.
- **Retail evidence.** All compiler-allocated VU0 code in retail (37 matched j-form functions and 13 j-form near misses) uses only vf1 and vf2; hand-written code goes up to vf31. The functions that match only at N = 2 show the allocator really had just two registers.
- **What the source probably was** (m1's guess, not proven): SCE or Insomniac vector macros or inline functions written with `"j"` operands, compiled everywhere with `-mvu0-use-vf0-vf2`.

**Adding the flag to a line.** It is placed first on lines that did not have it before. Appending it instead changes which neighbouring lines have equal flag lists; `build_text.py` merges runs of equal lists into one slice, which exposes declaration conflicts (the first one is `func_003A0D58` in `39FFC8.c`). When you add an override, copy the neighbouring line's flags as they are written.

## Patterns from batch 23 (MMI bucket, 2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **`sq $0` as non-volatile asm with a memory output**, `__asm__("sq $0,%0" : "=m"(*(u128_t *)(p + off)));`, schedules like an ordinary store. The volatile `"r"` form of `QZERO` blocks scheduling around it (`func_003BD668`; `func_003B7B50` went from 43 to 5 diffs). Use the `"=m"` form when retail moves other instructions across the store.
- **Adjacent `@ps2as` overrides merge into one slice**, and an earlier block's `.extern` hints then reach the later functions of that slice. After adding an override, run the full build, and fix any function it breaks with per-function alias names (`func_003D2F90`, after `func_003D2878`'s override). `try_in_context.py` checks only the target function, so only the full build catches this.
- **A loop-invariant constant that retail adds with `addu`:** declare it as a `long` local before the loop and add `(s32)` of it: `long base = 0x590000; id = i + (s32)base;` (`func_003B3DB8`).
- **`addu` operand order:** read back the field you just stored, `p->h0 = c; p->h2 = p->h0 + p->hE;` (`func_003A6C30`).
- **A nested select's branch layout:** put the inner test's xor in its own block-local temporary, `else { s32 e = k ^ 0x259; m = e ? 0 : 8; }` (`func_003B8440`).
- **The callee's return type again:** declaring `func_12A9F0` as `s32` instead of `void` fixed a `$v0`/`$v1` swap in a final 64-bit pack (`func_00393E90`; its sibling `func_00393A18` needs the same).
- **An indexed loop with two increments**, `for (i = 0; i < n; i++, list++)`, matched where a single induction variable didn't (`func_003936A8`). A second index incremented in a call argument, `f(o, 0, i++)` next to loop counter `j`, is the same lever (`func_003B07B8`; using `j` there left 159 diffs).
- **Integration note:** `tools/divs_nops.txt` is keyed by function. When a patch changes a function's `div.s` padding count, that line has to travel with the function; a stale count makes the function longer by 4 bytes per `nop` and shifts everything after it (`func_0037D200`, 2 to 1).
- **Tool note:** `try_in_context.py` ignores `tools/localdecomp_flags.txt`, so an `@ps2as` candidate can only be checked in place once its `text_parts.txt` override exists.

## Patterns from large-function batch 3 (2026-10-06)

From the agents' reports and near-miss headers; each was found while matching or nearly matching a large function.

- **One C variable reused for unrelated values** decides close register ties.
- **Callee prototypes decide scheduling:** float/int parameter order and `long` parameters change the caller; when unsure, try every order.
- **Declare temporaries inside the one branch arm that uses them.**
- **Loop invariants hoisted by the second loop pass take the first callee-saved registers.**
- **Constants fold into adds but not multiplies** (`i * lh` keeps its register).
- **Many "mmi" bucket functions are plain C**: their 128-bit ops are `-fcaller-saves` spills of ordinary values, not MMI code.

## Patterns from batches 27 and 29 (2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Read the assembler off the retail bytes.** No `nop` after an `mfc1` whose result is used by the next instruction means Ps2EeAs (`@ps2as`). `func_0038BB50` (0x86C) had stalled for several batches on the default assembler; with `@ps2as` it matched.
- **A `do { ... } while (0)` around a loop** changed loop alignment and register weights enough to finish `func_0038BB50`, with no empty asm needed.
- **Two stores to the same object can be written in either order;** try both (`func_00386D98`: the `q+0x10` store comes after `q+0x48`).
- **Struct-member reads vs cast-pointer reads.** This gcc runs without strict aliasing, so a load through a cast pointer is untyped memory and the scheduler keeps stores to plain globals after it. Struct-member loads don't conflict with stores to fixed scalar globals. Reading a header through `struct { s32 x[0x27]; }` instead of `((s32 *)hdr)[i]` was the biggest gain on `func_003B6528`.
- **Float constants:** write the exact decimal of retail's bits, including truncated ones (`0.0749999955f` is `0x3D999999`, not `0.075f`) (`func_003A0EB0`).
- **decomp-permuter is useful once its score is replaced** with `check.py`'s own metric (relocations resolved against retail). Its default score tracked `try_func` diffs poorly; with the replacement it improved 9 of 11 near misses in under an hour. Check the semantics of its rewrites before building on them.

## Patterns from rounds d, f, g and k and the large-function batches (2026-10-05 to 10-07)

From the agent reports of the 19-agent round (d), the two final passes (f, g), round k and the large-function batches. Each item names the function that proved it; "near miss" means it was found on a function that still doesn't match.

### Forms still under review

These produce retail's bytes and are in the build, each in its own commit, but the maintainer has not approved them. Mention them in the PR if you use one; prefer a plain-C form when you find one.

- **The VU0 j-form** (section above).
- **Empty asm barrier,** `__asm__("" : "+r"(e));` on a computed store pointer: stops combine folding a base offset (-0x1C0) into the `sq` (`func_0037F7A8`). A volatile store also blocks the fold but stays out of delay slots.
- **An `ori` asm to keep a float constant in a general register** (`func_003A8230`): `k = 0x33140000; __asm__("ori %0, %0, 0x65B7" : "+r"(k)); v = *(f32 *)&k;`. Retail builds the constant in `$v0` with `lui`/`ori`, moves it with one `mtc1` into `$f20` and reuses it for two calls. In plain C, cse2 and combine fold any normal float's bit pattern into an `li.s` through `$at`, which is hoisted; unions, `*(s32 *)&v = K`, an inline helper and an empty `"+r"` barrier all failed.
- **Zero-length asm as an issue-slot filler,** `__asm__("" : "=r"(c) : "0"(c));` (non-volatile, an output tied to its input): one insn that emits no code and has no barrier semantics. sched2 still issues it, so it takes one of the cycle's two issue slots and moves a ready, dependence-free instruction one cycle later. Use it only when retail's schedule leaves a slot empty that gcc would fill: in `func_003A04A0`'s 25-iteration loop setup, retail's cycle 5 has a free ALU slot although four ready ALU instructions could issue (`sched_explain.py --pass 2`). A replay of every single change of dependence, priority or source order among the block's 15 instructions found none that gives retail's order; a 16th instruction in that slot does. Placed at the top of the branch, with the loop written up-counting, it matched (543/543, standalone and in context). An asm without outputs is volatile, a full barrier that also moves the PRE and loop.c instructions (9 rows).
- **`cvt.w.s` / `cvt.s.w` as two one-instruction asm statements** (`func_003A4860`, `@ps2as`). Retail keeps `(s32)t` in an FPU register for `t - (f32)(s32)t`; SN gcc always converts through a general register (`mfc1`/`mtc1`), and no other place in retail does this.
- **A non-volatile one-block VU0 asm** with explicit `$vf` registers and `"m"` operands (`func_003C0E10`). The volatile version is 8 diffs, all in the prologue save order: a volatile asm cuts the prologue scheduling region, so retail's early register saves need the non-volatile block.
- **One-block VU0 asm with `"m"` operands** of a 4-float struct instead of `"r"` pointers (`func_003E0190`): gives retail's `%lo(D)($hi)` addressing, where a 128-bit operand puts the full address in a register.

### Globals and declarations

- **Constant-address globals: `*(T *)0xADDR`.** Spot them by a retail `lui` of `(0xADDR >> 16)` with no relocation. The access is one 2-word macro that reorg never puts in a delay slot and that never uses `$gp`. It replaced every volatile alias in the drafts (`func_003BB398`, `func_003BA108`, `func_003B7EB0`, `func_003BA748`, `func_003B8F50`, `func_003BBFC8`); in `func_003BB398`/`func_003BA108` it let reorg produce retail's `bnel ... sltu`. An earlier example: `*(u8 *)0x1D5477` (`func_0039DB38`).
- **Declared size picks the address form, in both directions.** Under `@ps2as`, an object declared 8 bytes or smaller (`u8[8]`, `s32[2]`, a `fnptr[2]` table, or a one-element alias `T X_f[1]`) is one `la` macro that Ps2EeAs expands to adjacent `lui`/`addiu`, even for a large table reached through an alias (`func_0037F0D8`, `func_0037E878`, `func_003B8F50`, `func_003B5F88`, `func_003B6F28`, `func_003B8440`, `func_00382458`). The `la` is one pseudo, so it also changes local allocation. Because it is one insn, cse or loop can hoist it far from its use; when retail builds the address right at the use, declare the object larger instead (`func_003A1AD0`).
- **A scalar alias, not an array, fixes load order** when one load must stay a single macro (`func_003A2028`: `extern E *D_001DA51C_3A2028;`).
- **A buffer reached from two bases: make it a struct member.** When retail addresses a buffer directly (`sym`) for some accesses but through a register holding `sym - K` for others, declare a struct at `sym - K` with the buffer as a member at offset K: `typedef struct { u8 pad[0x7F00]; u8 buf[0x100]; } S;` at 0x2224A0 for the buffer at 0x22A3A0. Plain writes to the buffer, or a `u8` array at the lower address, get the base wrong. A local `u8 *h = D.buf;` then kept the hoisted `+0x7F00` register (143 diffs without it) (`func_003AB3A8`).
- **Each single-function override needs its own `.extern X, 4` hints** inside its block (s5's batch).
- **A `$gp` load in a short poll loop** used to make `asm_filter.py` give up on the loop (Ps2EeAs then padded it to 7 words). Since round k the filter counts a load or store of a symbol with an earlier `.extern SYM, N` (N <= 8) as one word, so write the loop plainly (`func_003B8840`). The older workaround, the default assembler plus two names for the global (an `.extern X, 16` alias for the `lui`/`lw` macro, the sized name for `$gp`), is what `func_003AD288` and `func_003AFF20` use.
- **Unreferenced rodata after a jump table.** When converting a switch function whose `jtbl_*.s` also holds data words no code references, write those words as a `const` array right after the function (a definition, but in `.rodata`, where retail has those words), so they keep their place when the `INCLUDE_RODATA` line goes: `const u32 D_00318A18[42] = {...};` after `func_003BC218` (0x318A18 to 0x318ABC). With that, the build differs only inside the function itself.

### Callee prototypes and arguments

- **Implicit-int callees in override slices.** A function with its own override slice can't see same-file definitions in other slices, so every same-file callee needs a prototype in the block. Without one the call silently becomes `int f()`: float arguments go as doubles and `$v0` stays busy. `--flags=-Werror-implicit-function-declaration` on `check.py` lists them. Declaring the callee alone took `func_003A0EB0` from 190 to 78 diffs; several old drafts had been measured with implicit-int calls (`func_0039C548` 27 to 25, `func_0039EE68` 411 to 398).
- **Extra callee arguments.** A value retail keeps in an argument register for no visible reason can be an extra argument of the callee: `func_003E8FB0` (the `f44` virtual call takes `s` third), `func_0039E4B0` (a third argument to `func_12F9E0`), `func_00394A20` (`func_00394660` reads a 6th argument from `$t1`). Read the callee before trusting a caller's argument count.
- **Ignored callee arguments still set registers.** When retail loads argument registers the callee ignores, pass them through a per-function alias prototype: `func_0037DCF0_0039A3B0(a0, a2)` (`func_0039A3B0`).
- **Pass-through arguments.** When retail keeps a copy of the first argument in a higher argument register, the function has extra parameters it passes untouched to its callee: `f(p, b, c)` calls `g(p, b, c)` (`func_00135E40`, boot_elf).
- **A phantom argument on the next call reorders earlier argument moves.** When argument moves before one call are misordered, check the argument count of the next call in the same block: an extra argument the callee doesn't take adds a hard-register write that changes sched2's "dependents" key for the earlier moves to that register (`sched_explain.py --pass 2 --why A B` shows `dependents: 465=4 vs 469=3`). In `func_003B7B50`, retail's `li $a2, 1` before `jal func_13D310` was the constant for a later store, not a third argument; `func_13D310(D_001D9D84, D_002CE180)`, as in `func_003A2460`, fixed the order of the zero moves for `func_0038DA28`.
- **Stale or missing arguments.** When retail never sets an argument register, the source passed the stale incoming parameter (`func_003E8590(o, ...)` in `func_003EA078`) or nothing at all (`func_003E16B8()` in `func_003DFE10`).
- **Int/float order in prototypes, both the callee's and your own.** Ints and floats get registers independently under EABI, so reordering a prototype keeps the ABI but changes the order (and schedule) of the argument moves. When only argument moves are misordered, sweep the interleavings: one of 35 matched `func_003A0EB0`, 60 were tried for `func_0037D200`'s 12-parameter callee, and `func_003813E0`, `func_003A7090`, `func_003B16B0` and `func_003DBEC8` needed their callee's floats or ints moved. The function's own parameter order works the same way: `f32 g` before `s32 n` gave `func_003A0D58` retail's `$f24`/`$f25`, `f32 f0` before `a3` matched `func_003BA5B8`.
- **Take a callee's parameter order from another matched caller** when the callee is still assembly and callers disagree (`func_003BBFC8`, via an alias of `func_00389FB8` with `func_0038BB50`'s order).
- **`long` locals and parameters.** A `long x = (s32)scr[0];` passed to an `s32` parameter gives retail's `dsll32`/`dsra32` truncation pair after the next call (`func_003813E0`); a `long` result passed to a `long` parameter avoids that pair (`func_003B7378`). A `long` 5th parameter moved `| 0x400000` into retail's slot (`func_003BC568`).
- **Declare operator new as `malloc`.** `func_003ECDC0` is operator new (size, heap). gcc gives a function named `malloc` a result that aliases nothing, so declaring it inside the function as `extern void *malloc(s32, s32) __asm__("func_003ECDC0");` lets the stores that fill the new object move past the store of its pointer into `p->f2C`, as in retail. Under its own name gcc assumes the result may alias `p` and keeps those stores in source order; `__attribute__((malloc))` on the plain name has no effect with this compiler (`func_003EB180`, `func_003E89F0`).
- **A 64-bit return type on a callee whose result is unused.** Declaring `func_13CDF0` as returning `long` (alias `func_13CDF0_003A21C0`) gave retail's `$v1` choices in `func_003A21C0`; with `s32` or `void` local-alloc picks other registers. Try it alongside the `void`-to-`s32` change for `func_12A9F0` (`func_00393E90`) when only the registers around a call differ.
- **K&R `s16` parameter.** A K&R definition with an `s16` parameter stays compatible with an `(s32, s32, s32)` prototype and gives `(s16)(kind - 1)` as `sll`/`sra` for a switch index (`func_0039A3B0`).

### Statement order, combine and scheduling

- **Hide a value from combine.** In `e = A; for (i = 0; ...)`, combine knows `e`'s sign and turns `blez` into `beqz`. `i = 0; e = A;` hides it (`func_003B5D10`).
- **Operand order sets local-alloc ties.** `combine_regs` ties an output to operand 1, so `k = C; k *= t;` (constant as operand 1) gives retail's register where `k = C * t` doesn't (`func_003A73A0`).
- **gcse constant propagation of float constants.** gcse's cprop copies a float constant into call-argument moves in other blocks whenever its set is available on entry, so `1.0` gets rebuilt at every call, where retail keeps it in `$f22`/`$f23`. Assign the constant inside the loop, in the same basic block as its use: gcse doesn't propagate within a block, cse keeps the register, and loop.c hoists the set to the preheader (`func_003AF2C0`, `zero = 0.0f; one2 = 1.0f;` in the loop's else arm). A second, dead assignment does not help here, because availability still holds.
- **A dead second store keeps a constant inside the loop.** A block-local constant with a second, dead assignment has two sets, so loop.c won't hoist it: `{ s32 lim = -1; if (i <= lim) i = 3; lim = 0; }` reproduces retail's `li -1` rebuilt in the loop body (`func_003B23F8`).
- **A variable loop bound keeps gcse from hoisting an array address.** When retail recomputes one array's address right before its loop while gcse hoists the others far away, give that loop a bound variable set at the top (`s32 nF = 5; ... for (i = 0; i < nF; i++)`). While gcse runs, the entry test isn't folded, so the address isn't anticipatable above it and PRE leaves it alone; cprop folds the bound later, so the loop itself is unchanged (`func_003B3558`).
- **Stack-slot order of PRE-hoisted pseudos follows gcse's hash buckets.** For `(plus fp C)` the bucket is (13259 + C) mod N, with N = (insns after cse1 / 2) | 1, read from the `-dG` dump ("Expression hash table (N buckets"). Each extra loop with a variable bound adds about 2 to N, so variable bounds that change no instruction can still fix spill-slot order: `func_003B3558` needed N = 215 for retail's slots 0xC54-0xC60. `func_003A8230` needed N = 589 and got the count by passing four float arguments as integer bit patterns (`k = 0x40000000; ... *(f32 *)&k`); as plain literals they gave 585 to 587 buckets and 21 to 113 diffs.
- **A call nested in a later argument runs after the earlier arguments' addresses are computed.** Arguments are expanded left to right, so the address for the first argument is built before a call inside a later one. Computing that argument into a variable first (`y = ... func_00388978(ang) ...; func_003A5928(&s->dots[j], x, y, 0.0f, 0.0f);`) moves the address computation after the inner call (`func_003A8230`).
- **Loop constants and clamps.** A loop constant retail keeps in a callee-saved register is a variable declared before the loop (`s32 one = 1;`, `func_003947B0`); the literal is neither hoisted nor kept. A clamp `c = K - x; if (v >= c) v = c;` needs a block-local limit variable to get K's register (`func_0039FBD8`).
- **Separate variables for identical constant arguments.** `k1 = 0x98; k2 = 0x98;` passed as two stack arguments stay two pseudos into sched1, so each `li` has one dependent and no longer outranks other instructions (`func_003D1D40`). In the same function, writing `w2 >> 6` inline in the call instead of a precomputed variable moved the operand's last use and fixed the stack-argument store order.
- **An empty volatile asm is also a priority lever.** Every later insn gets a dependence on every earlier set, with the setter's latency as its cost, so a chain through a long-latency op (a 6-cycle `div.s`) wins the ready-list race in both scheduling passes. Where the barrier sits relative to a load also sets that value's lifetime, and so local-alloc's choice: `t = D.f54; __asm__ __volatile__(""); diff = t - cur;` matched, the barrier before the load did not (`func_003DE560`).
- **An empty volatile asm orders two loads.** `b = e->f0; __asm__ __volatile__(""); h = e->f38;` keeps `b`'s load ahead of `h`'s, so `b`'s live range overlaps `e`'s and `b` takes retail's `$v1` (`func_00391E78`). In the same function, the constant 2 that a byte is compared against landed in retail's `$a0` by sharing a variable with the id later passed to `func_0038ED78` (`id = 2; if (b == id) { id = D_001D5EA0; ... }`).
- **A copy variable makes gcc recompute a value after an if/else join.** When retail recomputes an address after the join that gcc would share from before it (gcse PRE or cse following the jumps), copy the index early (`i = r;`) and use the copy only in the tail, with a separate pointer (`e2 = (u8 *)((i * 128) + (s32)D_1A30B0);`, not reassigning `e`). The `%hi` part is still shared, as in retail (`func_0039C548`, 57 to 43 aligned diffs).
- **An offset from another global makes an address one `la`.** In S mode, a store to a plain 16-byte global is a `lui` (which gcse PRE may share in a saved register) plus a reload-generated `addiu` before every `sq`. When retail keeps the full address in a saved register across several stores, write the stores relative to a neighbouring global, `*(V4 *)((u8 *)&D_001DA358 + 8) = t;` for `D_001DA360`: the `const(sym + off)` address is one `la` (adjacent `lui`/`addiu`) that PRE keeps in a saved register. The same form for a call argument builds it fresh next to the call, as retail does, instead of cse reusing the saved register. A pointer local (`V4 *d = &D_001DA360;`) gives `lui $v1; addiu $s4, $v1` instead (`func_003B9730`).
- **Read through a plain pointer to keep a load after a scalar store.** gcc 2.95's alias rule (`fixed_scalar_and_varying_struct_p`) lets a load through a struct pointer move past a store to a scalar global. When retail keeps the load after the store, read through `s32 *`: `f = *(f32 *)&h[2];` after `D_001DA6E4 = h[1];` with `s32 *h`, not a header struct (`func_00395090`).
- **A variable set twice instead of one expression.** `s32 tbp = t->w0; tbp = (g->x34 + tbp * 4) >> 8;` changes sched1 and local-alloc compared with `tbp = (g->x34 + t->w0 * 4) >> 8;`, and fixed a whole branch's schedule (`func_00394368`: 176 to 30 diffs; `base = g->x20; ... base >>= 8;` in the same function).
- **Anti-dependence ordering by reusing one variable.** `t = G; H = t; t += 0x10; G = t;` keeps the first store ahead of the later ones (`func_00384B68`).
- **Two sched1 tie-breakers decide most remaining store and load orders** (g4's reading of the scheduler dumps, `-dS -dR`): sched1 prefers the instruction that ends a register's life, then the one with more dependents (`func_003E89F0`, `func_003C9078`, `func_003EB180`, all near misses). `func_003C8ED0` matched once the pointer arguments of both calls were computed into variables before the first call, in retail's load order (`c = b + e->h1C; a0 = b + e->h18; d = b + e->h1A;`, with `c` and `d` used only by the second call): setting `c` and `d` after the first call, or writing them inline, gave 93 diffs, and any other order of the three (or `a0` inline) gave 6 or 7, in the order of the loads and `addu`s and their registers. Compare the store-rotation note under "Codegen tricks that matter".
- **New variables after calls.** A new variable that doesn't cross a call keeps its computation after the call; sched1 hoists the sets of pseudos that do cross calls (`func_003869E8`).
- **Moving one load decides the `jal`-slot argument.** `h = o->f60` moved after an `if (r) {...}` block fixed which argument move lands in the delay slot (`func_003EAAD0`).
- **A store written before the last call fills its delay slot** (`func_003AA0B8`). Halves computed into new variables before a call (`h2 = hh >> 1;`) give retail's `sra` before the `jal` plus one in its delay slot (`func_003BC568`).
- **A load retail repeats** is not CSE'd because of a mode difference or a block boundary: `w = e->bC; w -= 6; if (w < 0) w = 0;` as three statements kept retail's separate load (`func_00384EC0`).

### `do { } while (0)` as a lever

Wrapping one statement or a range in `do { ... } while (0)` (or `for (;;) { ...; break; }`) changes more than it looks:

- **Reference weight.** flow.c adds the loop depth to a register's reference count, so each wrap (or nested wrap) makes those uses count more in register allocation. `do { do { d = D_0037B7D0; } while (0); } while (0);` lifted a table base above the loop counter (`func_003B0A60`, 12 to 2); wrapping the loop's `e` load and update fixed `func_003A2028`; wraps matched `func_0039BEC0` and `func_00391B70`, `func_003E98B8` (permuter find, probably a macro) and moved a prologue `addiu` in `func_00121D70`/`func_00121DB0` (boot_elf). f2's scripts `dwrap.py` (single lines) and `dwrap2.py` (brace-balanced ranges) brute-force the position.
- **Scheduling barrier.** Its loop notes stop the scheduler moving instructions across that point. They cut CSE as well, so a high half shared across the barrier gets recomputed (`func_003A21C0`, near miss).
- **Side effect: `.p2align 3`.** A label right after the loop-begin note is aligned, which can add a padding `nop` (also at the continue label of `do { call } while (0)`). Wrap only the range that needs it.
- Around a loop, it makes loop.c hoist invariant addresses into `$s` registers (`func_00383FD8`, near miss) and can change loop alignment (`func_0038BB50`).

### Register allocation

- **Global-alloc priority** is `refs * floor_log2(refs) / live`; `allocno_compare` truncates it to an integer (x10000) and breaks ties by the lower pseudo number. `tools/regalloc.py` shows it. Splitting a statement raises a variable's refs (f1 on `func_00389D18`); an extra dummy pointer with an initializer, used once after the loop, lengthened live ranges by 2 so two constants tied the way retail's do (`func_003B16B0`, a permuter find).
- **Every pseudo is an allocno, local ones included.** A local's hard-register preferences can push a global off `$a2`/`$a3` in global.c's first pass (`func_003AC6F0`, near miss). Global-alloc also merges the preferences of a pseudo that dies in an insn into the pseudo that insn sets, so a function-scope temporary inherits a register from whatever it dies into; declared block-local in each arm, it is a local pseudo and reuses the dying input's register (`func_003D2878`, per-arm `plzcw` results).
- **Loop invariants hoisted by loop.c's second pass** get the highest priority, because they are hoisted closest to the loop. A movable with a short lifetime fails the first pass's `threshold * savings * lifetime >= insn_count` test; shortening one constant's lifetime (`h = D_001D8B0C - 0.007f;` before the call) moved it to the second pass and to retail's `$f23` (`func_003B16B0`). `-dL` shows the loop dump.
- **Shared versus block-local variables in big switches.** Shared function-level temporaries push values into callee-saved registers (block-local per case fixed `func_00397490` and `func_003B2F50`). But where retail keeps one stack address or value in the same saved register across cases, it is one function-level variable reused (`func_003DBEC8`), and values that share a register are often one variable (`cx = a->f10; cx = (b2 - b0) * cx + b0;`, `func_003EC960`). Separate variables instead of reuse matched `func_0037FF90`.
- **local-alloc first tries a widened lifetime.** With sched2 on (any -O2 build), local-alloc first places each block-local value in a register free over its lifetime extended by one insn on each side (`fake_birth` / `fake_death` in local-alloc.c's `block_alloc`), and uses the exact lifetime only if that fails. So a value born in the insn right after another dies usually does not reuse its register, even though nothing conflicts over the exact lifetimes (`func_003DE560`: `f48` in `$f0` dies at the `div.s`, and the `f54` load issued in that cycle gets `$f1`).
- **A constant in the quotient's register.** For retail's `div.s $f3, $f0, $f3` (the divisor's register reused for the result), assign the constant to the result variable first: `k = 0.0261799414f; k = D.f48 / k;`. The constant then lives in the global pseudo `k`, not in a local one (`func_003DE560`).
- **Reuse a variable to take it out of local-alloc.** Two block-local values with equal refs and lifetime get registers in birth order. Reusing one variable for an earlier, unrelated value in the same block (`v = D_001D52E0; buf[1] = v; ... v = D_001DA0B8;`: two sets, two deaths) makes it global-allocated, so the other value, now the first local, takes the first free register. The hint is retail using the same register for both of the variable's values (`lbu $v1` ... `lw $v1`) (`func_003A35C0`).
- **Parameter copy placement.** A copy made right after a parameter's first use (`d = x1 - x0; x = x0;`) keeps the parameter in its incoming register (`func_003D14D0`).
- **Stack slot order follows when a variable becomes addressable**, not its declaration: gcc 2.95 moves a scalar to the stack when it first sees `&x`, while arrays get their slot at the declaration. One `u8 cc[2]` array declared first, instead of two `u8` scalars, put the bytes at retail's 0x20/0x21 (`func_003C0188`, 198 to 62).
- **Function-level locals for stack buffers.** Block-local arrays get separate slots in gcc 2.95; retail shares slots between cases or loops, so declare them once at the top (`func_003DCD08`, `func_00382458`, `func_003A4A78`).
- **Inline helper parameters.** integrate.c copies every non-const formal into a fresh pseudo before the body, so the order of a `static __inline__` helper's formal parameters sets the schedule of those copies (`func_003EB728`, found by a climb over parameter orders).
- **Float constants named as locals.** Two float constants stored into a stack struct, declared as initialised locals at the top (`f32 c1 = 0.572f;`, then `s.f1C = c1;`), gave retail's `$f` registers; writing the literals in the stores left 17 diffs, all `$f`/`$a` register numbers (`func_003B07B8`).
- **Full if/else arms that repeat the shared assignment.** For alignment-style constants, `if (k == 1) { ax = 1; } else { sx = -2; ax = 1; }` (each of `sx`, `sy`, `ax`, `ay` initialised as its own constant) gives retail's float registers: jump optimisation still produces the hoisted `sy = 2; if (k == 2) sy = -2` shape, and the extra references set the global-alloc priorities. Writing the hoisted form by hand gives the same instructions with the wrong registers (`func_003EAC88`, copying its siblings `func_003E8C40`, `func_003EA648`, `func_003EC3D0`).
- **Stores before the updates that read them, when pointers may alias.** `out->x0 = ...; out->y0 = ...; out->x1 += out->x0 - x0; out->y1 += out->y0 - y0;`: because `clip` and `out` may alias, the later `clip->y` loads stay after the `out->x0` store, which puts the store before the delta's subtraction in sched1, and local-alloc ties the delta to the new value instead of to `x0` (`func_003EAC88`).

### Control flow, switches and loops

- **Branch versus conditional move.** gcc only turns `if (a < b) a = b;` into a conditional move when the source value is already in a register at that point; a memory source keeps the branch (from the `func_003921D8` analysis). `if (x != -2) r = 1; else r = 0;` goes through jump.c's conditional-move conversion and keeps the constant 1 in a register a later cmove shares (`func_0039BF98`). `if (a != b) c = f(..); else c = a;` puts `move c, a` in the `beq` delay slot (`func_0039FBD8`). `if (x) c = f(A); else c = f(B);` gives a branch where any selected-id form gives `movz` (`func_003B2AF8`).
- **Selector type sets if/else layout.** An `s32` selector gives `beq` with the then-assignment in its delay slot; a `u8` (or other narrow) selector gives `bne`/`b` (`func_003B8440`).
- **Cross-jumping keeps the later copy** (see `func_00397490`). To stop it merging duplicated tails, use block-local temporaries per case and a `goto` into the shared tail (`func_00391B70`), or reorder one arm (`func_003A4A78`). To get a merge retail has, write the shared body out in each case (`func_003A73A0`, `func_003C79F0`) or end both arms the same way and let gcc merge them (`func_003C0188`'s two shared tails). A call written in each arm (`idx = func_003A3220(0x1D);` and so on) is merged into retail's one `jal` and leaves the code after it in a separate block at the join, which schedules differently: a hint is an independent load that retail issues a cycle later than one block would allow after the call's result move (`func_003A35C0`).
- **An instruction duplicated into both arms comes from after the if/else.** When retail has the same `sll` at the end of both arms (in the `b` delay slot and in the else arm), reorg filled the delay slot with the join block's first instruction: write the shift once, after the if/else (`if (a1) s = h; else s = h*0x73/0xA0;`, then `s * 8` in the uses). Writing `<< 3` in each arm left 13-16 diffs (`func_0038CC68`).
- **A dead test whose arms do the same thing.** When retail loads and tests a flag but both paths then run the same code, write the test with two identical arms: `if (D_001D5BDC == 0) D_001D888C++; else D_001D888C++;`. gcc merges the arms but keeps the load of the flag (`func_003AE8A8`, case 22).
- **Switch trees.** `case 2: default:` gave retail's `beq 1 / slti 2 / bnez` tree (`func_003813E0`; `case 0: default:` in `func_003EAC88`); an extra `case 3: break;` picks another root (`func_003DCD08`, `func_003DBEC8`).
- **Error-code chains** (`func_00397490`, above) and **block order:** writing the `== 0` or bad case first gives retail's layout in several boot_elf functions: `if (D == 0) return f(); ...` (`func_0013CEB0`, `func_0013CF40`), `if (i < 0 || i >= n) return f(p); return ok;` (`func_001222A8`). A single result variable, `if (f() != 0) r = D; else {...} return r;`, fixed a `lui` register (`func_0013A930`, `func_0013A880`, `func_0013A988`), and `if (call) r = 0; else r = 0x800;` keeps a constant out of `$s0` where setting it before the call doesn't (`func_001223B8`, `func_00122520`).
- **Loop shapes.**
  - A loop that re-reads `self->field` each pass is left alone by loop.c, which is why retail reloads the bound and indexes with `sll`/`addu` (`func_003E8838`).
  - Count-up loops that gcc would reverse: `i = 0; if (n > i) { do { ... } while (...); }` (`func_0038E030`, permuter find).
  - A goto loop with the test wrapped in `do { } while (0)` gives a rotated loop with duplicated exit tests and an unconditional back branch (`func_003A54A0`). An early-exit test at the top of the body is a rotated `for` condition: `for (i = 0; i < N && !(test); i++)` (h05's batch).
  - `for (...; i++, q += 0x20, fl++)` puts loop.c's derived-pointer increment right after `i++` (`func_003C9078`, near miss).
  - Separate block-local pointers for separate loops (f2), and one counter per loop (`func_003A4A78`, `func_00393878`).
  - A loop over a null-terminated pointer table: index it, `for (i = 0; T[i] != 0; i++)`, with `T[i]->...` at every use, not a walking pointer. In `func_003A04A0` (`((O_3A04A0 **)D_00229930)[i]`) that gave retail's `beql` at the loop entry and fixed a `$s0`/`$s1` swap, 22 rows. Compare indexing over walking a pointer in `func_003C1950` ("Patterns from the first agent batches", above).
  - `-fno-rerun-loop-opt` as a single-function override kept an up-counting `slti` loop that the second loop pass reversed (`func_00394060`); its neighbour `func_00393C98` needs the second pass, so it can't be file-wide.

### GS/GIF packet writers and 64-bit values

- **`*(*pp)++ = v;`** with `s32` parameters widened by `(long)x << n` at the use (`func_003D3148`, 147 to 0, then four siblings).
- **One pointer variable per step** when retail repeats `p = D_001DA0D0; D_001DA0D0 = p + 0x10; ...` blocks (`p1, p2, q1, q2`): reusing one `p` changes allocation priorities (`func_003867F8` 53 to 0, `func_00387B10`). Separate pointer variables per group let the last access of each group update the pointer in place (`func_003A7090`).
- **Constant first in OR chains:** `0xA | (x << 4) | ...` keeps retail's grouping; with the constant in the middle gcc reassociates it (`func_003872F8`, `func_00386F38`). For TEX0 values, write the full `SCE_GS_SET_TEX0` expansion with all 12 fields, constants included, inline in the block (no `#define`): constant folding then groups the chain as retail (`func_00384EC0`).
- **`(1L << 63)` and other 64-bit constants need `@ps2as`.** Ps2EeAs builds `1L << 63` as `addiu -1; dsll32 31` (retail), the default assembler as `ori 0x8000; dsll32 16`. Keep `(x << 37) | 0x400000000L` as its own operand or statement, or gcc merges the constants (s3's batch, `func_00392DD8`). `u32 == 0xFFFFFFFF` makes Ps2EeAs build `lui 0xffff; ori 0xffff` like retail.
- **`lw` + `dsrl` + `andi` on a 32-bit global:** `unsigned long t = D[0]; if (!((t >> 6) & 1)) break;` with a separate 64-bit temporary (`func_0037D200`); one expression narrows to an SImode `sra`.

### Small forms that matched

- **A float constant reused as a variable:** `bx = 1.0f; by = bx - ay; bx = bx - ax;` where `1.0f - ay` doesn't (`func_003875A0`).
- **A dead store gcc would drop** is kept when it has a different mode from the later one: write the first stores as `f32 0.0f` (`func_003A6A00`).
- **Dead compare loads before a rounding expression:** `(D_001DA0F0 == 1 ? z0 : z1)` with two local zeros `z0 = z1 = 0.0f` (`func_003DBEC8`, `func_003A5DF0`); a literal `? 0.0f : 0.0f` folds away completely.
- **`(x & 0xFF) < (y & 0xFF)`** keeps a signed `slt` where two `u8` fields compare `sltu`; a boolean helper returning `u8` reproduces a `daddu` copy of the result before each loop test (h05's batch).
- **Struct copies as statements, declared in slot order**, so other stores can sit between them (`func_003C1130`, near miss, 49 to 8).
- **`__builtin_alloca` for a mid-function `$sp` adjustment.** When retail drops `$sp` again after the prologue (`addiu $sp, $sp, -0x40` with a `$fp` frame, then `daddu $sp, $fp, $0` in the epilogue), the source had a dynamic allocation: `buf = __builtin_alloca(15 * 4);` (`func_003B3558`).
- **Start over.** A clean rewrite, or a copy of an already matched sibling, often beats tuning an old draft: `func_003A3FB0` went from 46 to 0 with a plain rewrite, `func_00392400` from 89 to 0 copied from `func_00392878`.

## Matching workarounds audit (2026-10-20)

Every empty asm fence (`__asm__("")` / `__asm__ __volatile__("")`, with or without `"+r"` operands or a `"memory"` clobber), register pin (`register T x __asm__("$N")`), `__asm__ volatile("nop")` statement and `do { } while (0)` barrier or wrap inside a localdecomp block of `src/frontbin/` and `src/boot_elf/` was removed on its own, the function checked with `tools/try_in_context.py` (and `tools/try_func.py`), and the removal kept only if the function still matched. A pin was replaced by a plain local (`register T x __asm__("$N") = v;` became `T x = v;`); a wrap `do { S } while (0);` by `{ S }`. The single pass was repeated until nothing changed, then each function that still had workarounds was tried with groups removed together (all of them; each pinned variable together with the fences that name it; all fences; all pins). The full build was MATCH for all three programs afterwards. `src/veldin/` has none of these forms (its only inline asm is two j-form `vadd` helpers), and `src/levels/common/` allows no asm at all.

| | frontbin before | after | boot_elf before | after |
|---|---|---|---|---|
| register pins | 119 | 31 | 118 | 33 |
| empty asm fences | 52 | 41 | 48 | 37 |
| `nop` asm statements | 8 | 1 | 8 | 1 |
| `do { } while (0)` wraps of statements | 17 | 15 | 20 | 17 |
| empty `do { } while (0);` | 3 | 2 | 5 | 4 |
| **total** | 199 | 90 | 199 | 92 |

216 of 398 were not needed. Two more were not in the count: the `daddu` asm in `func_003A5608` / `func_003AADC8` is plain C once the function returns its argument (`*(u8 **)a0 = D_001D8178; return a0;`).

What the audit showed:

- **Most register pins were redundant** (173 of 237). They pinned the register the allocator picks anyway. 20 of them came out only in the group pass, together with another pin of the same function (`func_00389920`, `func_003B5EC8`, `func_003C9AE0`, `func_003E5F00`, `func_003E6680` and their boot_elf twins): removed one at a time, each was still needed while the other was pinned.
- **`nop` asm in short loops is never needed.** `do { f(p); i--; __asm__ volatile("nop"); p++; } while (i != -1);` matched without it, and so did the 2- and 4-nop polling loops (`func_003AB100`, `func_003AD220`): ee-as with `-mcpu=5900` pads short loops itself (the R5900 short-loop workaround that `tools/fix_short_loops.py` undoes for `INCLUDE_ASM` code). The 3-nop loop in `func_003B6488` / `func_003BBC48` still needs its asm (10 diffs without it).
- **God Hand's one-statement VU0 form.** In `func_003B9DA8` (boot_elf `func_003BF568`) one lone `lqc2` was volatile to keep the 0.0027f constant load after it. The contiguous run `lqc2 v; lqc2 v; sqc2 d; lqc2 a` is now one `__asm__ __volatile__` statement with `"=&j"` outputs, and the `vadd` and its `sqc2` stay separate j statements, so the constant still fills the `vadd` latency as in retail. Made non-volatile the block is 10 diffs; putting the `vadd` inside it as well, 11 (the `sqc2` then goes before the constant). In the other j-form functions with a barrier the barrier does not hold VU0 order, and merging did not help: `func_0037F7A8` (retail interleaves `mult`/`addiu`/`daddu` with its `lqc2`s; merged, 26 diffs with the fence and 93 without), `func_003DE560` (the fence orders FP code; merged helpers, 128 to 180 diffs), `func_003A04A0` (merged loop block, 2 diffs with its fence and 6 without).

### Open items: workarounds still needed

Each one below breaks the match when removed alone (the last column is the diff count `try_in_context.py` printed). They are open items: each needs another C form found by hand or with the permuter, or stays documented here. The two wraps in `func_0038BB50` / `func_003906A8` contain `break` and are real control flow rather than barriers.

| frontbin | boot_elf | Remaining | Diffs when removed alone |
|---|---|---|---|
| `func_0037DF98` (37D100.c) | `func_003823F0` (381180.c) | 1 pin, 1 fence | 16, 5 |
| `func_0037DFD8` (37D100.c) | `func_00382430` (381180.c) | 2 pins, 1 fence | 16, 7, 2 |
| `func_0037F7A8` (37E0F0.c) | `func_00383E38` (382780.c) | 1 fence | 79 |
| `func_00385908` (37E0F0.c) | `func_0038A368` (382780.c) | 1 pin, 1 fence | 10, 2 |
| `func_00388E78` (388B40.c) | `func_0038D8D8` (38D5A0.c) | 1 pin | 1 |
| `func_00389468` (389468.c) | `func_0038DEC8` (38DEC8.c) | 2 pins | 3, 2 |
| `func_00389920` (3896E8.c) | `func_0038E478` (38E1F8.c) | 3 pins, 8 fences | 11, 12, 13, 6, 6, 9, 8, 6, 13, 8, 8 |
| `func_0038BB50` (3896E8.c) | `func_003906A8` (38E1F8.c) | 1 do-while wrap | 485 |
| `func_0038DC08` (3896E8.c) | `func_00392760` (38E1F8.c) | 1 fence | 6 |
| `func_0038E508` (3896E8.c) | `func_00393060` (38E1F8.c) | 2 pins, 2 fences | 42, 2, 43, 13 |
| `func_0038E6D0` (3896E8.c) | `func_00393228` (38E1F8.c) | 1 pin, 1 fence | 17, 22 |
| `func_0038E930` (3896E8.c) | `func_00393488` (38E1F8.c) | 2 fences, 1 do-while wrap | 3, 5, 6 |
| `func_0038EA88` (3896E8.c) | `func_003935E0` (38E1F8.c) | 2 pins, 1 fence | 13, 8, 7 |
| `func_0038F3F8` (3896E8.c) | `func_00393F50` (38E1F8.c) | 1 do-while wrap | 4 |
| `func_00391B70` (3896E8.c) | `func_003966C8` (38E1F8.c) | 1 do-while wrap | 32 |
| `func_00391E78` (3896E8.c) | `func_003969D0` (38E1F8.c) | 1 fence | 18 |
| `func_00399F40` (3958F0.c) | `func_0039F1A0` (39A9A8.c) | 1 do-while wrap | 9 |
| `func_0039BEC0` (39BC00.c) | `func_003A1180` (3A0EC0.c) | 1 do-while wrap | 14 |
| `func_003A04A0` (39FFC8.c) | - | 1 fence | 4 |
| `func_003A2028` (39FFC8.c) | `func_003A7708` (3A56A8.c) | 2 do-while wrap | 14, 14 |
| `func_003A4768` (3A4758.c) | `func_003A9F28` (3A9F18.c) | 1 pin | 1 |
| `func_003A54A0` (3A5478.c) | `func_003AAC60` (3AAC38.c) | 1 do-while wrap | 68 |
| `func_003A7F58` (3A7690.c) | `func_003AD718` (3ACE50.c) | 1 pin, 2 fences | 3, 5, 4 |
| `func_003ACB00` (3ABA48.c) | `func_003B22C0` (3B1208.c) | 1 fence | 3 |
| `func_003ADAE0` (3AD8A8.c) | `func_003B32A0` (3B3068.c) | 1 pin, 1 fence | 6, 20 |
| `func_003B0A60` (3AD8A8.c) | `func_003B6220` (3B3068.c) | 1 fence, 2 do-while wrap | 3, 10, 10 |
| `func_003B5EC8` (3B5BF8.c) | `func_003BB688` (3BB3B8.c) | 2 pins | 43, 10 |
| `func_003B6410` (3B5BF8.c) | `func_003BBBD0` (3BB3B8.c) | 3 fences | 4, 4, 12 |
| `func_003B6488` (3B5BF8.c) | `func_003BBC48` (3BB3B8.c) | 1 nop asm | 10 |
| `func_003B9B60` (3B8F50.c) | `func_003BF320` (3BE710.c) | 1 pin, 3 fences (boot_elf: 1 pin, 1 fence) | 6, 6, 2, 2 (boot_elf: 6, 6) |
| `func_003BD428` (3B8F50.c) | `func_003C2BE8` (3BE710.c) | 1 pin | 6 |
| `func_003C1A40` (3C0E08.c) | `func_003C7200` (3C65C8.c) | 1 pin, 2 fences | 2, 2, 4 |
| `func_003C8CE0` (3C8B28.c) | `func_003CE4A0` (3CE2E8.c) | 2 pins | 15, 12 |
| `func_003CD710` (3CD710.c) | `func_003D2ED0` (3D2ED0.c) | 1 pin | 1 |
| `func_003D4858` (3D14B0.c) | `func_003DA018` (3D6C70.c) | 1 pin, 2 fences | 21, 7, 3 |
| `func_003DE560` (3DBDF0.c) | - | 1 fence | 10 |
| `func_003E09D8` (3E0190.c) | `func_003E6198` (3E5950.c) | 1 fence | 23 |
| `func_003E0B78` (3E0190.c) | `func_003E6338` (3E5950.c) | 1 fence, 1 empty do-while | 41, 20 |
| `func_003E2118` (3E1E38.c) | `func_003E78D8` (3E75F8.c) | 1 empty do-while | 2 |
| `func_003E29B8` (3E1E38.c) | `func_003E8178` (3E75F8.c) | 1 do-while wrap | 2 |
| `func_003E5F00` (3E5378.c) | `func_003EB6C0` (3EAB38.c) | 1 pin | 53 |
| `func_003E6680` (3E5378.c) | `func_003EBE40` (3EAB38.c) | 1 pin | 53 |
| `func_003E91F8` (3E5378.c) | `func_003EE9B8` (3EAB38.c) | 1 pin, 2 fences | 6, 4, 13 |
| `func_003E98B8` (3E5378.c) | `func_003EF078` (3EAB38.c) | 1 do-while wrap | 11 |
| `func_003EA648` (3E5378.c) | `func_003EFE08` (3EAB38.c) | 1 do-while wrap | 11 |
| `func_003EB6B0` (3E5378.c) | `func_003F0E70` (3EAB38.c) | 1 pin | 7 |
| `func_003EC3D0` (3E5378.c) | `func_003F1B90` (3EAB38.c) | 1 do-while wrap | 11 |
| - | `func_00121D70` (11FA10.c) | 1 empty do-while | 3 |
| - | `func_00121DB0` (11FA10.c) | 1 empty do-while | 3 |
| - | `func_0012AA78` (12A948.c) | 1 pin | 26 |
| - | `func_0012FD50` (12A948.c) | 1 pin | 71 |
| - | `func_00125878` (124988.c) | 1 do-while wrap | 2 |
| - | `func_0013B3F8` (133BB8.c) | 1 do-while wrap | 10 |
