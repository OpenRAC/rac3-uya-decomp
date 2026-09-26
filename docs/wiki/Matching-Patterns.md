# Matching patterns

What makes SN ee-gcc 2.95.3 produce retail's exact code, collected from the ~690 functions matched so far. The research behind it (compiler comparisons, how the assemblers were identified) is in [`docs/compiler_matrix_findings.md`](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/compiler_matrix_findings.md).

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

The default assembler moves the last instruction into the `jr $ra` delay slot, like retail. Keep any `nop` that retail has between VU0 instructions in the template.

## Not everything is C

- **Linker remnants** (the `remnant` bucket in `triage.py`, about 200 entries). Retail has about 620 single instructions, each followed by a `nop`, between functions. Nothing references them, and 449 of them are `addiu $sp, $sp, N`, a function epilogue. They are what the original linker left behind when it stripped unused functions: the final odd instruction plus its alignment `nop`. They are not source code. Keep them as data (a macro that emits the words); don't write C for them.
- **Handwritten assembly** (the `handwritten` bucket, 100 functions). spimdisasm flags them (`addi`, `$at`, unusual registers). The original was a `.s` file, so they will move to `.s` files rather than C.

## Codegen tricks that matter

When the instructions are right but their order or registers aren't:

- **Independent stores get rotated by the scheduler.** Try moving the last store first, or the reverse.
- **Early `return` vs `if/else`** changes block layout and which branch is likely (`beql`/`bnel`).
- **`x = c ? a : b` vs `if`** produce different code (`movz`/`movn` vs branches). Try both.
- **Declaration order of locals** can swap registers.
- **Signedness** picks `slt` vs `sltu` and `sra` vs `srl`. `u8` vs `s32` for a flag changes `andi` masks.
- **A copy of a parameter** (`s32 id = arg;`) sometimes changes which register holds it.
- **Pointer vs index loops** (`p++` vs `a[i]`) produce different induction code.

Stop after a handful of attempts on the same register difference. Leave it as a partial and move on: breadth gets more done.

## Families

Many functions are near-copies. Once one is matched, the rest usually go fast:

- **`isA` checks through a vtable at `+8`:** `if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) { func_X(p, a, b); return 1; } return 0;`
- **8-slot hash tables (`HT_8`/`HE_8`):** `h = ((key & 7) + ((key % 7) * i + i)) & 7;` over 8 probes, with a sentinel value.
- **Getters/setters on the big state struct at `0x142430`**, each with its own aliased declaration.

If you find a family, say so in your PR. It helps the next person.

## Known open problems

Leave these for now, or open an issue if you crack one:

- `lwc1 $fN, off($gp)` followed by `nop` before the use (e.g. `func_003882D0`, which reads the main executable's literal pool). No flag or assembler reproduces the `nop` yet. Current matches use a `$gp` register hack plus `__asm__("nop")`.
- 64-bit constant synthesis `li 0x8000; dsll 24` (`func_00383B08`).
- `div.s` with double-`nop` padding (`func_003E1D18`). Lead: Ps2EeAs has built-in DIV padding ("DIV related opcode too near branch instruction - Added padding NOP/s"), so try `@ps2as`.
- Register allocation where retail keeps an argument in a temporary (`move $t3, $a0` at entry) while `$a0` holds a constant, e.g. `func_0039BEC0`. All its memory accesses match with `@ps2as`; only the registers differ.
- **A match in isolation can still differ in the full build.** `func_003AEDC8` and `func_003AED08` matched in `try_func.py` but the full build swapped two `$gp` stores; writing the stores in the opposite order fixed both. Something earlier in the same `text.c` part changes gcc's scheduling (a candidate is the file-level `register char *_gpreg __asm__("$28")` used by older hacks, but adding it alone to the test file did not reproduce the swap). Always confirm with the full build. Also, the `#define D_001D5B34 ...` hack macros above some functions replace a later `extern` of the same name; `#undef` it in your block (see `func_00389908`).
- About 20 matched functions use inline `__asm__` or a hand-rolled `$gp` register. They count, but plain-C rewrites of them are welcome.
