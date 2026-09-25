# Compiler and flag matrix: findings

Ratchet & Clank: Up Your Arsenal (SCUS_973.53), frontbin.elf decomp. Tested 2026-09-24/25.

## Summary

- **SN 2.95.3 v1.36 stays the project compiler.** It reproduces 270 of 271 existing C functions. No other build tops 189. Sony 2.95.3-136 is output-identical to SN in every test.
- **Use `-G8` everywhere**, with one declaration rule (below). With it, all 19 affected existing functions still match, and 14 of 15 `$gp` test functions match as plain C.
- **`-mno-split-addresses` is a per-source-file flag.** Functions needing it and functions needing the default form 18 clean, non-interleaved address runs. No variable declaration form can reproduce the no-split code under split mode.
- **Three groups previously written off are really no-split files, not compiler limits:** constructors returning `p` (4/4), `sd ra` destructors (3/3), and the no-split global-load class (7/8).
- **Still unmatched by any available compiler or flag:** callee-saved `$s` registers in 8-byte slots (retail `sd`, SN emits `sq`), `div` without the zero-divide trap, and the int-to-float `mtc1`/`nop`/`cvt` pattern. These are the only candidates for an unreleased or custom Insomniac toolchain. Skip them for now.

## Recommended project settings

| Item | Setting |
|---|---|
| Compiler | SN 2.95.3 v1.36 (`ee-gcc2953.exe`) |
| Default flags | `-O2 -G8` |
| No-split files | `-O2 -G8 -mno-split-addresses` |

**Declaration rule for `-G8`:** a global that retail reads with `lui`/`lw` (not through `$gp`) must be declared without a size, so GCC can't place it in small data:

```c
extern u8 D_00142734[];
#define D_00142734 (D_00142734[0])   /* keeps existing code unchanged */
```

Globals that retail accesses through `$gp` are declared with their real size (`extern s32 X;`). A few larger gp objects (e.g. the 24-byte struct at 0x1D9900 used by func_0037DC68) need `-G24` or a size-less declaration.

Verified in localdecomp: all 19 existing functions that break at plain `-G8` are back to 0 with this rule at both `-G0` and `-G8`. func_003A5608 is an inline-asm hack and was left out. No-split samples (func_003AA800, func_003D46B0, func_003AD458, func_003ECC40, func_003A5620) are 0 at `-G8 -mno-split-addresses` with the same rule.

## Split vs no-split address runs (SN 2.95.3)

S = needs default split addresses, N = needs `-mno-split-addresses`. Each file boundary lies between the last function of one run and the first of the next.

| Flag | First function | Last function | Functions seen |
|---|---|---|---|
| S | 0037D120 | 0037E070 | 3 |
| N | 00387BD8 | 00397258 | 5 |
| S | 0039A550 | 0039A780 | 7 |
| N | 0039BEA8 | 0039BEA8 | 1 |
| S | 0039C2A8 | 0039FFC8 | 4 |
| N | 003A5620 | 003ABA38 | 5 |
| S | 003ABD60 | 003AD430 | 3 |
| N | 003AD458 | 003AD4B0 | 3 |
| S | 003ADAA8 | 003ADB78 | 3 |
| N | 003AEE80 | 003AF0A0 | 2 |
| S | 003AFA90 | 003B0D88 | 3 |
| N | 003B0F58 | 003B2A28 | 2 |
| S | 003B4970 | 003B8A08 | 8 |
| N | 003B8BC8 | 003B8BC8 | 1 |
| S | 003BA350 | 003BE170 | 7 |
| N | 003D46B0 | 003DBE20 | 2 |
| S | 003DBEA0 | 003DE8E0 | 5 |
| N | 003E1B98 | 003ECC70 | 4 |

The boundaries get sharper as more functions are matched. A function's flag only shows when it loads a global.

## Test design

- **Compilers (15 builds):**
  - SN 2.95.3 v1.36
  - Sony 2.95.3-136, -114, -107
  - Sony 2.95.2-274, -273a
  - Sony 2.9-991111 (Windows), -991111-01, -991111-01-dtls, -991111a, -990721
  - 2.96-ee-001003-1
  - GCC 3.2-030926, 3.2-040921 (both with `-fno-optimize-sibling-calls`)
  - Not run: 3.2-030210-beta2 (its earlier 3-function test matched 030926). Metrowerks mwcps2 was excluded: a different compiler family, and RAC1 is confirmed GCC.
- **Flag sets (8):** every combination of `-O1`/`-O2`, `-G0`/`-G8`, and with or without `-mno-split-addresses`.
- **Corpus:** all 271 C functions in text.c, plus `cases.c` with 47 functions in 7 problem groups:
  - B: `$s` register saves (13)
  - C: no-split global loads (8)
  - D: `$gp` variables (15)
  - E: `sd ra` placement / destructors (3)
  - F: division trap (2)
  - G: int-to-float `nop` (2)
  - H: constructors returning `p` (4)
- **Method:** each compiler emitted assembly (`-S`), assembled with one common GNU as for the EE. Every function was compared word by word against retail frontbin.elf, with relocation fields masked. Sanity check: SN at the project flags reproduces 270/271, matching the real build.
- **Note:** C and D test cases use sized declarations. That's why C scores 0 at `-G8` in the table; with the declaration rule above they match (verified in localdecomp).

## Full results

| Compiler | Flags | text.c /271 | B /13 | C /8 | D /15 | E /3 | F /2 | G /2 | H /4 |
|---|---|---|---|---|---|---|---|---|---|
| SN 2.95.3 v1.36 (project) | `-O2 -G0` | 270 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| SN 2.95.3 v1.36 (project) | `-O2 -G0 -mno-split-addresses` | 227 | 0 | 7 | 0 | 3 | 0 | 0 | 4 |
| SN 2.95.3 v1.36 (project) | `-O2 -G8` | 250 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| SN 2.95.3 v1.36 (project) | `-O2 -G8 -mno-split-addresses` | 225 | 0 | 0 | 14 | 3 | 0 | 0 | 4 |
| SN 2.95.3 v1.36 (project) | `-O1 -G0` | 166 | 0 | 2 | 0 | 0 | 0 | 0 | 0 |
| SN 2.95.3 v1.36 (project) | `-O1 -G0 -mno-split-addresses` | 158 | 0 | 2 | 0 | 0 | 0 | 0 | 0 |
| SN 2.95.3 v1.36 (project) | `-O1 -G8` | 162 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| SN 2.95.3 v1.36 (project) | `-O1 -G8 -mno-split-addresses` | 156 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O2 -G0` | 270 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O2 -G0 -mno-split-addresses` | 227 | 0 | 7 | 0 | 3 | 0 | 0 | 4 |
| Sony 2.95.3-136 | `-O2 -G8` | 250 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O2 -G8 -mno-split-addresses` | 225 | 0 | 0 | 14 | 3 | 0 | 0 | 4 |
| Sony 2.95.3-136 | `-O1 -G0` | 166 | 0 | 2 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O1 -G0 -mno-split-addresses` | 158 | 0 | 2 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O1 -G8` | 162 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-136 | `-O1 -G8 -mno-split-addresses` | 156 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O2 -G0` | 183 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O2 -G0 -mno-split-addresses` | 155 | 0 | 0 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.95.3-114 | `-O2 -G8` | 165 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O2 -G8 -mno-split-addresses` | 153 | 0 | 0 | 14 | 0 | 0 | 0 | 4 |
| Sony 2.95.3-114 | `-O1 -G0` | 118 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O1 -G0 -mno-split-addresses` | 111 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O1 -G8` | 114 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-114 | `-O1 -G8 -mno-split-addresses` | 109 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O2 -G0` | 183 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O2 -G0 -mno-split-addresses` | 155 | 0 | 0 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.95.3-107 | `-O2 -G8` | 165 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O2 -G8 -mno-split-addresses` | 153 | 0 | 0 | 14 | 0 | 0 | 0 | 4 |
| Sony 2.95.3-107 | `-O1 -G0` | 118 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O1 -G0 -mno-split-addresses` | 111 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O1 -G8` | 114 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.3-107 | `-O1 -G8 -mno-split-addresses` | 109 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O2 -G0` | 183 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O2 -G0 -mno-split-addresses` | 155 | 0 | 0 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.95.2-274 | `-O2 -G8` | 165 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O2 -G8 -mno-split-addresses` | 153 | 0 | 0 | 14 | 0 | 0 | 0 | 4 |
| Sony 2.95.2-274 | `-O1 -G0` | 118 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O1 -G0 -mno-split-addresses` | 111 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O1 -G8` | 114 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-274 | `-O1 -G8 -mno-split-addresses` | 109 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O2 -G0` | 183 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O2 -G0 -mno-split-addresses` | 161 | 0 | 0 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.95.2-273a | `-O2 -G8` | 165 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O2 -G8 -mno-split-addresses` | 159 | 0 | 0 | 14 | 0 | 0 | 0 | 4 |
| Sony 2.95.2-273a | `-O1 -G0` | 118 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O1 -G0 -mno-split-addresses` | 115 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O1 -G8` | 114 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.95.2-273a | `-O1 -G8 -mno-split-addresses` | 113 | 0 | 0 | 12 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O2 -G0` | 188 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O2 -G0 -mno-split-addresses` | 156 | 0 | 2 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111 (Win) | `-O2 -G8` | 170 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O2 -G8 -mno-split-addresses` | 154 | 0 | 0 | 13 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111 (Win) | `-O1 -G0` | 123 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O1 -G0 -mno-split-addresses` | 113 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O1 -G8` | 119 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111 (Win) | `-O1 -G8 -mno-split-addresses` | 111 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O2 -G0` | 188 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O2 -G0 -mno-split-addresses` | 156 | 0 | 2 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111-01 | `-O2 -G8` | 170 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O2 -G8 -mno-split-addresses` | 154 | 0 | 0 | 13 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111-01 | `-O1 -G0` | 123 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O1 -G0 -mno-split-addresses` | 113 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O1 -G8` | 119 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01 | `-O1 -G8 -mno-split-addresses` | 111 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O2 -G0` | 188 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O2 -G0 -mno-split-addresses` | 156 | 0 | 2 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111-01-dtls | `-O2 -G8` | 170 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O2 -G8 -mno-split-addresses` | 154 | 0 | 0 | 13 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111-01-dtls | `-O1 -G0` | 123 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O1 -G0 -mno-split-addresses` | 113 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O1 -G8` | 119 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111-01-dtls | `-O1 -G8 -mno-split-addresses` | 111 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O2 -G0` | 188 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O2 -G0 -mno-split-addresses` | 156 | 0 | 2 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111a | `-O2 -G8` | 170 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O2 -G8 -mno-split-addresses` | 154 | 0 | 0 | 13 | 0 | 0 | 0 | 4 |
| Sony 2.9-991111a | `-O1 -G0` | 123 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O1 -G0 -mno-split-addresses` | 113 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O1 -G8` | 119 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-991111a | `-O1 -G8 -mno-split-addresses` | 111 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O2 -G0` | 189 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O2 -G0 -mno-split-addresses` | 157 | 0 | 2 | 0 | 0 | 0 | 0 | 4 |
| Sony 2.9-990721 | `-O2 -G8` | 171 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O2 -G8 -mno-split-addresses` | 155 | 0 | 0 | 13 | 0 | 0 | 0 | 4 |
| Sony 2.9-990721 | `-O1 -G0` | 123 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O1 -G0 -mno-split-addresses` | 113 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O1 -G8` | 119 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| Sony 2.9-990721 | `-O1 -G8 -mno-split-addresses` | 111 | 0 | 0 | 11 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O2 -G0` | 158 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O2 -G0 -mno-split-addresses` | 140 | 0 | 0 | 0 | 0 | 0 | 0 | 2 |
| 2.96-ee-001003-1 | `-O2 -G8` | 143 | 0 | 0 | 13 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O2 -G8 -mno-split-addresses` | 138 | 0 | 0 | 13 | 0 | 0 | 0 | 2 |
| 2.96-ee-001003-1 | `-O1 -G0` | 149 | 1 | 2 | 0 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O1 -G0 -mno-split-addresses` | 145 | 1 | 2 | 0 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O1 -G8` | 145 | 1 | 0 | 11 | 0 | 0 | 0 | 0 |
| 2.96-ee-001003-1 | `-O1 -G8 -mno-split-addresses` | 143 | 1 | 0 | 11 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O2 -G0` | 140 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O2 -G0 -mno-split-addresses` | 135 | 1 | 3 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O2 -G8` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O2 -G8 -mno-split-addresses` | build error | 1 | 3 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O1 -G0` | 127 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O1 -G0 -mno-split-addresses` | 126 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O1 -G8` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-030926 | `-O1 -G8 -mno-split-addresses` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O2 -G0` | 138 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O2 -G0 -mno-split-addresses` | 133 | 1 | 3 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O2 -G8` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O2 -G8 -mno-split-addresses` | build error | 1 | 3 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O1 -G0` | 125 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O1 -G0 -mno-split-addresses` | 124 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O1 -G8` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| GCC 3.2-040921 | `-O1 -G8 -mno-split-addresses` | build error | 1 | 0 | 0 | 0 | 0 | 0 | 0 |

## Other notes

- About 20 existing matched functions use inline `__asm__` or a hand-rolled `$gp` register hack. They produce correct bytes, so they count, but they aren't original-style C. func_003A4758, func_003ABE58 and func_003E1D50 already match as plain C at `-G8`, and the others are candidates for a cleanup pass.
- func_003A4A20 reads `D_001DA0D0` with `lui` and writes it through `$gp` in the same function. No single declaration reproduces this, so the original probably used two declarations or a macro.
- RAC1 (Lynder063's project) reports SN ProDG GCC 2.95.3 for `text` and Sony 2.9-ee for `core_text`, plus `-G2` in places. In UYA's frontbin, the 2.9 builds are not better than SN for any tested group, and `-G2` fails every 4-byte `$gp` variable.
