# Matching patterns

What makes SN ee-gcc 2.95.3 produce retail's exact code, collected from the ~1200 functions matched so far. The research behind it (compiler comparisons, how the assemblers were identified) is in [`docs/compiler_matrix_findings.md`](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/compiler_matrix_findings.md).

Every range already builds with `-O2 -G8 -fopt-stack -mno-check-zero-division`, so `$s` registers saved with `sd` in 8-byte slots and `div` without the trap come out right on their own. What varies per function is how globals are declared, split vs no-split addresses, and which assembler runs.

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

## Per-function aliases

`text.c` is one file, so every block sees every earlier declaration. When a function needs a variable declared differently from how an earlier block declared it (a different struct type, sized vs unsized), don't change the shared declaration. Declare a per-function alias named after the function address instead:

```c
typedef struct { u8 pad[0x18]; u16 h18; ... } S_3969B8;
extern S_3969B8 D_00142430_003969B8[];
```

and add `D_00142430_003969B8 = 0x142430;` to `symbol_addrs_resolved.txt`. `pr_check.py` flags any alias without an address.

Name typedefs uniquely the same way (`S_3969B8`, `S_142430x`). Two blocks defining the same typedef name with different bodies is the most common full-build error.

## Never define variables

`text.c` must only produce `.text`. Every variable is `extern`:

- `s32 D_X;`, `static s32 D_X = 3;` and `void (*D_X)(void);` without `extern` are definitions. They create `.data`, `.sdata` or `.bss`, which shifts the retail layout or fails the link with `multiple definition`.
- String literals and float constants that the compiler puts in `.rodata` or `.lit4` have the same problem. See floats below.
- `pr_check.py --obj build/src/text.c.o` lists any data section that sneaks in.

## Split vs no-split addresses

Retail was built from many source files, and some used `-mno-split-addresses` (N) while others used the default (S). They form address runs, recorded in `tools/text_parts.txt`:

- **S:** `lui $v0, %hi(X)` + `lw $v0, %lo(X)($v0)`, and array bases as `lui` + `addiu`.
- **N:** the compiler emits `lw $v0, X` and the assembler expands it, so you see `lui $at` pairs and loads that fold the offset differently.

A function's mode only shows when it touches a global. If the diff is all about how addresses are formed, run `try_func.py --all-modes`. Known N-only shapes: constructors that return `p`, destructors that save `ra` with `sd`, and the "no-split global load" class.

## Choosing the assembler

| Assembler | Selected by | When |
|---|---|---|
| `bin/ee-as.exe` (Aug 2000) | default | Almost everything. It inserts the `nop` after `mtc1` that retail has. |
| `ee/bin/Ps2EeAs.exe` (SN ps2eeas 1.9.25) | `@ps2as` | Mixed gp/lui access (above); float constants built inline with `lui`/`ori`/`mtc1`; `mtc1` hazard `nop`s that depend on whether the next instruction uses the register |
| `ee/bin/as.exe` (May 2001) | `@newas` | Rare; try it when both of the others are one instruction off |

Ps2EeAs can't read the GNU `macro.inc`, so a range assembled with it must not contain any `INCLUDE_ASM` stub. Give the function its own single-function range (see [Toolchain and build](Toolchain-and-Build#text_partstxt)).

## Floats

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

## Switch statements

`switch` works in C. The jump tables used to sit inside the data blob; since `tools/migrate_jtbls.py` they come from `text.c`, in function order, exactly where retail has them (the start of `.data`). Each asm function with a table has an `INCLUDE_RODATA(...)` line right after its `INCLUDE_ASM`. When you convert the function, delete both lines: gcc's table takes the same place. `pr_check.py` catches a leftover `INCLUDE_RODATA`.

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

Insomniac wrote VU0 math as inline assembly inside C functions, so that is the matching form too. Use explicit `$vfN` registers in the template and pass pointers as `"r"` operands:

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

- **Trailing padding is part of the layout.** A function's `.s` file also holds the padding words that follow it (`func_0039BD08` is 0x24 bytes with 5 `nop`s after it, because the next function starts at 0x39BD40). Converting such a function to C drops that padding and shifts everything after it, which changes every `jal` target in the build even though the function itself is byte-exact and `try_func.py` says MATCH. Before converting, check the gap to the next function's address; if there is one, the padding has to be reproduced or the function left as asm.
- **Linker remnants** (the `remnant` bucket in `triage.py`, about 200 entries). Retail has about 620 single instructions, each followed by a `nop`, between functions. Nothing references them, and 449 of them are `addiu $sp, $sp, N`, a function epilogue. They are what the original linker left behind when it stripped unused functions: the final odd instruction plus its alignment `nop`. They are not source code: they live in `asm/remnants/` and are included with `LINKER_REMNANT(...)`. Don't write C for them.

  A C function whose whole body is one `asm volatile("addiu $sp, $sp, 0x50")` looks like a match in localdecomp but is not one: gcc still appends `j $31` and a `nop`, which shifts every later function. 26 of these were scored 0 before localdecomp stopped trimming real instructions past the target size; `pr_check.py` now warns when its count runs ahead of text.c.
- **Handwritten assembly** (the `handwritten` bucket, 100 functions). spimdisasm flags them (`addi`, `$at`, unusual registers). The original was a `.s` file, so their `.s` in `asm/handwritten/` is the source, included with `ASM_FUNC(...)`. The same goes for VU0 leaves whose last instruction sits in the `jr $ra` delay slot after a dependent instruction (`mtc1 $4, $f0` after `qmfc2 $4`, `ppacb` after `ppach`): neither assembler nor gcc will put it there, even when gcc emits the `mtc1` itself, so the original wrote the whole function, `jr` included, in assembly.

## Codegen tricks that matter

When the instructions are right but their order or registers aren't:

- **Independent stores get rotated by the scheduler.** gcc emits the last store of a run to the same base first. For retail's order A, B, C, D write B, C, D, A (`func_003A61D0`, `func_003A6888`). The scheduler issues at most one memory access per cycle; between equal priorities it prefers the instruction with more dependents, then the one that frees a register, then source order (found by [rac1-decomp](https://github.com/Lynder063/rac1-decomp/blob/main/docs/DECOMP_PROGRESS.md)).
- **`addu` operand order is picked by the access form, not by the order you write the `+`.** gcc canonicalises the addition. `p = (u8 *)T + i * 4` and `b = table + i` give index first; `T[i].field`, `S.arr[i]` and `table[i]` give base first (rac1-decomp). A field at a fixed offset from an indexed table (`sw $a0, 0x34($v0)` after `addu base, idx`) is an array member of a struct: `extern T D_X; D_X.arr[i] = v;` (`func_00395958`).
- **Two registers holding the same pointer.** Retail computing `base + i * 4` into one register and copying it to another before the second store (`addu $v0, $a0, $a1; move $a0, $v0`) is two arrays in one struct: `s->a[i] = x; s->b[i] = y;` (`func_003A7FC8`). Pointer variables, `volatile` and return tricks don't produce it.
- **Callee prototypes decide argument code.** Use the declaration text.c already has instead of an alias with guessed types. A `long` / `unsigned long` parameter builds its constant as one macro that can move (`func_003A3EF0`, `func_003D47A0`); a callee declared with too many arguments leaves extra `move`s (`func_0037EAA0`). A function that ignores its argument in retail may still be called with one: `func_003E16B8(&D_001DA9B8)` is what keeps the pointer in `$v0` in `func_003E2D90`.
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

- **Loop padding no assembler mode reproduces** (retail has `jal; nop; nop; nop; bnez`): `do { r = f(); __asm__ volatile("nop
	nop
	nop"); } while (r);` (`func_003B6488`, `func_003AB100`). This is an inline-asm hack; revisit if a C-only form is found.
- **64-bit constants and `lwu`:** declare the callee parameter and the struct field as `unsigned long` (`func_00386608`, needs `@ps2as`).
- **Under `@ps2as`, a scalar `extern s32 X;` gets the non-gp form** (`lui; lw`, or `lui $at; sw`). Add `__asm__(".extern X, 4");` only for symbols retail reaches through `$gp` (`func_003A3220`, `func_003D3C80`).
- **Check the raw words for `lq`/`sq`** (`.word 0x78..`/`0x7C..`) before rewriting a copy loop (`func_0037F550`).
- **Singleton-style load through a different address form:** a second symbol alias at the same address (`D_001D52FC_003B42D0`, unsized array) gives retail's `lui`/`lw` where the plain name gives `$gp` (`func_003B42D0`).

### Declarations in text.c

The full build compiles `text.c` in parts (`tools/text_parts.txt`), and a part only sees *declarations* from earlier parts, never definitions. So:

- A call to a function that is only *defined* earlier still needs its own `extern`.
- An `extern` in your block must agree with that function's definition if both end up in the same part. When they differ, use the definition's types and cast at the call, or align the other `extern` lines to yours (callers that ignore the result are unaffected when the return type changes from `void` to `s32`).
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
- `div.s`/`sqrt.s` `nop` padding (`func_003E1D18` and 69 other functions). Measured over all 207 retail cases: 131 have 2 `nop`s, 58 none, 16 one, 2 three (those two are a branch-delay `nop` plus 2). The padding is not a C problem and no rule found so far predicts it: not the preceding instruction, operand latency, alignment or branch position. Ps2EeAs *does* pad `div.s` by itself (correcting the earlier note), but its rule matches retail's count in only about 26% of the cases, so the retail build did not use this version. Both GNU `as` and Ps2EeAs delete explicit `nop`s in reorder mode, so any emulation has to emit the padding as a raw `.word` the assembler cannot remove (like `tools/asm_filter.py` does for short loops), driven by a per-function table.
- **Register allocation where retail keeps an argument in a temporary (`move $t3, $a0` at entry) while `$a0` holds something else** (`func_0039BEC0`): solvable in C, mostly. The cause is gcc's priority order (see `tools/regalloc.py`): a block-local temporary outranks the parameter and overlaps it, so the parameter is pushed out of its incoming register. Two changes reproduce retail's exact allocation for `func_0039BEC0` (`screenId` `$t3`, the `-2` constant `$a0`, `result` `$t2`, `flag` `$t1`): declare `D_001A7430` unsized (`extern s32 D_001A7430[];`, read as `D_001A7430[0]`), because retail reaches it with a compiler `lui`, and write the flag as `s32 flag = (screenId >= 0) ? D_001D5B78[screenId] : 0;`. That takes the diff from 1,680 to 210; what is left is the branch shape (which instruction lands in the `bltz` delay slot). The forms that get the registers right change the branch layout, and the forms that get the layout right change the registers, so this function is logged for decomp-permuter.
- **Resolved: "a match in isolation can still differ in the full build".** `func_003AEDC8` and `func_003AED08` passed `try_func.py` but failed the full build with two `$gp` stores swapped. The cause was the tool, not the build: it masked every relocated field, and two stores through `$gp` differ only in their relocated offsets, so the wrong order looked identical. `try_func.py` now fills relocations in with the symbols' real addresses and compares them in full (checked against all 617 previously matched blocks: no false failures). The `#define D_001D5B34 ...` hack macros above some functions still replace a later `extern` of the same name; `#undef` it in your block (see `func_00389908`).
- About 20 matched functions use inline `__asm__` or a hand-rolled `$gp` register. They count, but plain-C rewrites of them are welcome.

### Forms this compiler has never been seen to produce (2026-10)

Three shapes showed up while trying to match the smallest functions still filed as
`plain`. All three are the reason to move on to another function, not to rewrite the C:
if your target's `.s` contains one of them, the C is not the problem.

- **`lq $at` - `$at` as a data register.** Compiling the same three-quadword copy
  (`*(u128_t *)` at 0x00/0x10/0x20) with the range's flags allocates `$2`, `$3`, `$6`;
  `$at` is not something this compiler hands to a value. In `frontbin.elf` the only
  files containing `lq $at` are the nine under `asm/handwritten/`, plus
  `func_00388E58` and `func_00388E38` - which `tools/triage.py` still lists as `plain`.
- **`sq $31` / `lq $31` - a 128-bit save of `$ra` where this compiler emits `sd`/`ld`.**
  13 functions in the text range save `$ra` that way, and **none** of the 13 has a C block
  in `src/text.c`, while their neighbours that save with `sd`/`ld` are matched.
  Unaffected by `-O1/-O3/-Os`, `-fno-opt-stack`, `-mgp64`, `-mips3`, `-mips4`, `-G0/-G24`
  and both assemblers.
- **`sq $zero` - a 128-bit zero store.** `*(u128_t *)p = 0;`, `(u128_t)0` and a named
  `register u128_t z = 0;` all compile to `por $2,$zero,$zero` followed by `sq $2,0($a0)`:
  the TImode zero is materialised in a register first, so retail's single `sq $zero` is out
  of reach from C here.

Reproduce any of them from the repo root:

```
python tools/try_func.py <your attempt>.c func_XXXXXXXX      # the ordinary judge
python tools/try_func.py <your attempt>.c func_XXXXXXXX --all-modes   # 4 flag/assembler combos
```

Two more things worth knowing before a long session: `sizeof(long)` is 8 here, so the
64-bit type is `unsigned long` (`long long`, and therefore `u64`, is 16 bytes and any
arithmetic on it fails with `unsupported wide integer operation`), and the literal suffix
`ULL` is rejected by this compiler - use `UL` or a cast.

#### Where the `sq`/`lq` forms probably come from

The 128-bit saves are a **compiler-version signature**, not evidence of a custom toolchain.
Two SN packages can be run side by side here, and they disagree exactly there:

| compiler | `$ra` save | stack adjust |
|---|---|---|
| SN ProDG 3.01 `ee-gcc2953.exe` (this repo) | `sd` / `ld` | `addiu $sp,$sp,-0x20` |
| SN ProDG 2.0 `ee-gcc295.exe` | **`sq` / `lq`** | `subu $sp,$sp,32` |
| retail | **`sq` / `lq`** | `addiu $sp,$sp,-0x20` |

Measured with the C bodies of `func_0038C888` and `func_0038C9D8`: 3.01 emits `sd`/`ld` under
`-O1`, `-O2`, `-O3`, `-Os`, `-G0`, `-G8` and `-mgp64`; 2.0 emits `sq`/`lq` for both, but with
the older `subu`/`j` spellings.

Retail therefore looks like an **intermediate SN release**: 2.95.3 instruction selection with
the older 16-byte stack slots - the same 2.95.3 built without the stack-save change that
`-fopt-stack` selects in the 3.01 package. Running other SN packages against these 13
functions is the cheapest way to pin the exact build; if one of them also fixes the `$at`
and `sq $zero` cases above, that is the compiler the game was built with.
