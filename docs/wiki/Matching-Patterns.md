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

A function's mode only shows when it touches a global. If the diff is all about how addresses are formed, run `try_func.py --all-modes`. Known N-only shapes: constructors that return `p`, destructors that save `ra` with `sd`, and the "no-split global load" class.

## Choosing the assembler

| Assembler | Selected by | When |
|---|---|---|
| `bin/ee-as.exe` (Aug 2000) | default | Almost everything. It inserts the `nop` after `mtc1` that retail has. |
| `ee/bin/Ps2EeAs.exe` (SN ps2eeas 1.9.25) | `@ps2as` | Mixed gp/lui access (above); float constants built inline with `lui`/`ori`/`mtc1`; `mtc1` hazard `nop`s that depend on whether the next instruction uses the register |
| `ee/bin/as.exe` (May 2001) | `@newas` | Rare; try it when both of the others are one instruction off |

Ps2EeAs can't read the GNU `macro.inc`, so a range assembled with it must not contain any `INCLUDE_ASM` stub. Give the function its own single-function range (the build then compiles it as a separate slice of its file) (see [Toolchain and build](Toolchain-and-Build#text_partstxt)).

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

- **Loop padding no assembler mode reproduces** (retail has `jal; nop; nop; nop; bnez`): `do { r = f(); __asm__ volatile("nop\n\tnop\n\tnop"); } while (r);` (`func_003B6488`, `func_003AB100`). This is an inline-asm hack. `tools/asm_filter.py` now counts `jal`/`jalr` when it pads short loops (see "Loop padding with a call in the body" below), so try the plain loop first; it may make the hack unnecessary.
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
- **Object-array initialisers** (`if (flag == 0) { for (...) init(p++); flag = 1; } return &array[i];`): retail has one `nop` in the loop that neither `S` nor `@ps2as` reproduces, so they need `i--; __asm__ volatile("nop"); p++;` (`func_003E13D0`, `func_003AD820`, `func_003AEDF8`, as in `func_003B46F0`). That is an inline-asm hack.
- **Order of independent stores** can only be found by search. A statement-order hill climb on the store lines found `func_003AC0D8`. decomp-permuter finds the same kind of change; it also tends to introduce `do { ... } while (0)` and `new_var` temporaries, which are harmless, but check that it did not change what the code does (it once moved an assignment into an `if`).

### Functions that save `$ra` with `sq`

Thirteen retail functions (`func_003869E8`, `0038C888`, `0038C9D8`, `003A6C30`, `003A9E60`, `003AAF88`, `003B3DB8`, `003B82C0`, `003BA5B8`, `003C0B10`, `003C1130`, `003D1B10`, `003D2370`) save `$ra` with `sq` in a 16-byte slot. gcc 2.95.3 writes `sd`, and when the function also saves `$s` registers it puts `$ra` in the lowest slot, where retail puts it in the highest (`$s0` lowest, ascending). No compiler or flag we have gives retail's layout, so `tools/asm_filter.py` rewrites it: list the function in `tools/sq_ra_funcs.txt` and every callee-saved save and restore is moved to retail's slot (same slot set, same frame size) as `sq`/`lq`. Write the C normally.

- A function with `$s` registers also needs the `-fopt-stack` flag removed (a single-function override in `tools/text_parts.txt`), because retail's `$s` saves are `sq`, not `sd`.
- `func_0038C888` and `func_0038C9D8` are done this way. `func_003A9E60` has the right slots and call; only its argument-copy registers differ (retail gives `$a0` the first temp, gcc gives it the last).
- A 64-bit argument that is moved with `daddu` must be `long`, not `s64` (`s64` produced a 128-bit `por`).

## Patterns from the third hand pass (2026-10, 13 functions)

- **Read a struct-typed global through its fields, with locals for the early reads.** `func_003A13B0` only matched once the two reads of `D_00225780` (`f30`, `f6C`) were locals at the top and the indexed table was a struct array (`D_160C40.e[idx].v[a]`, entry type 0x14C bytes) instead of pointer arithmetic. Retail's base-register reuse (`$a1` holds one global, then the other) follows from that.
- **Do not cache a field chain if retail re-reads it** (`func_003C0B10`): `obj->set->n` and `obj->set->arr[j]->e` written out each time matched; a local for `obj->set` did not.
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
- **Register allocation where retail keeps an argument in a temporary (`move $t3, $a0` at entry) while `$a0` holds something else** (`func_0039BEC0`): solvable in C, mostly. The cause is gcc's priority order (see `tools/regalloc.py`): a block-local temporary outranks the parameter and overlaps it, so the parameter is pushed out of its incoming register. Two changes reproduce retail's exact allocation for `func_0039BEC0` (`screenId` `$t3`, the `-2` constant `$a0`, `result` `$t2`, `flag` `$t1`): declare `D_001A7430` unsized (`extern s32 D_001A7430[];`, read as `D_001A7430[0]`), because retail reaches it with a compiler `lui`, and write the flag as `s32 flag = (screenId >= 0) ? D_001D5B78[screenId] : 0;`. That takes the diff from 1,680 to 210; what is left is the branch shape (which instruction lands in the `bltz` delay slot). The forms that get the registers right change the branch layout, and the forms that get the layout right change the registers, so this function is logged for decomp-permuter.
- **Resolved: "a match in isolation can still differ in the full build".** `func_003AEDC8` and `func_003AED08` passed `try_func.py` but failed the full build with two `$gp` stores swapped. The cause was the tool, not the build: it masked every relocated field, and two stores through `$gp` differ only in their relocated offsets, so the wrong order looked identical. `try_func.py` now fills relocations in with the symbols' real addresses and compares them in full (checked against all 617 previously matched blocks: no false failures). The `#define D_001D5B34 ...` hack macros above some functions still replace a later `extern` of the same name; `#undef` it in your block (see `func_00389908`).
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
- **Extra compiler flags are a per-file question, not a per-function trick.** The original build set flags per source file, so a flag a function needs must also leave every other function in its file matching. Check that before adding one: compile the file's other C functions with it (`try_func.py --flags="-fno-..."` on each).
  - `-fno-force-mem` (needed by `func_0039A040`): all 88 C functions in `3958F0.c` still match with it, and 1069 of all 1123 do. It's now the flag for the whole of `3958F0.c`, which is most likely what the original used. One exception: `func_00397490` needs `-fforce-mem` (the default) and has its own override; see the `func_00397490` section below. So either the file boundary there is wrong or the flag was not file-wide.
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
- **Tooling for very large functions:** `try_func.py`'s positional diff is unusable until the size matches. An aligned diff (difflib over the disassembly, branch targets mapped to labels) made progress measurable from 883 diffs to 0.

## Patterns from batch 21 (MMI bucket, 2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Check drafts with `try_in_context.py`, not only `try_func.py`.** `try_func.py` sees the extern declarations of earlier blocks but not their definitions, so a callee defined earlier in the file becomes an implicit `int` and gives false diffs (`func_003D1650` went from 23 diffs to MATCH in context; `func_0037F588`).
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
- **Tool gap:** the sq-`$ra` rewrite in `asm_filter.py` also matches `ld $16/$17` stack-argument loads, so `func_00386D98` (43 diffs) can't match until the rewrite is limited to the prologue saves and epilogue restores.

## VU0 instructions as separate asm statements (provisional, 2026-10-06)

`func_003DCD08` (0x1558 bytes) matches with each VU0 instruction written as its own non-volatile `__asm__` statement using the `j` (VU0 register) constraint, so gcc's scheduler can interleave VU0 ops with ordinary code as retail does. SN's cc1 only accepts `j` with `-mvu0-use-vf0-vfN`; the function's override uses `-mvu0-use-vf0-vf31`, but every N from 2 up gives the same bytes, so the original's N is unknown. This is the only function that uses the form so far. It may unlock much of the `vu0` bucket. Treat it as provisional until a second, independent function confirms it; until then, keep using the volatile-asm forms in "VU0 code: inline asm" where they work.
