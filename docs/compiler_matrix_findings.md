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

## Update 2026-09-25: the three "ceilings" are toolchain settings

All three groups previously written off (`$s` saves in 8-byte slots, `div` without the trap, `mtc1`/`nop`) match with SN tools and settings. Checked by a full cloud build of text.c: 2043/2043 functions byte-identical, all relocations resolve to retail addresses.

| Symptom | Fix |
|---|---|
| `$s` registers saved with `sq` in 16-byte slots (retail: `sd`, 8-byte) | `-fopt-stack` (SN-only cc1 option, "Optimise stack frame") |
| `div` followed by `break 7` trap | `-mno-check-zero-division` |
| Missing `nop` after `mtc1` before its use | Assemble with `bin/ee-as.exe` (Aug 2000) instead of `ee/bin/as.exe` (May 2001): `-B$(TOOLBIN)/ee-` |

Both compiler flags are on every line of `tools/text_parts.txt`. They changed none of the existing matched code.

### The retail assembler is SN's Ps2EeAs.exe

`ee/bin/Ps2EeAs.exe` (ps2eeas 1.9.25) explains the rest:

- It is single-pass. A global is only `$gp`-relative if it's known to be small at the point of use (defined earlier in the file, or `.extern` seen earlier). gcc emits `.extern` at the end of the file, so otherwise it uses `lui`.
- A macro load/store in a branch delay slot (`.set noreorder`) can't expand to two instructions, so it is forced `$gp`-relative.
- This is the "mixed" pattern: `lui` reads and `$gp` writes of the same variable in one function. Natural C matches. Examples: the D_001D4CEC functions are bitfield writes (`flags.b5 = 0;`), and the GIF packet writers are `p[0] = ...; p += 4;`.
- Its `mtc1` hazard nops depend on whether the next instruction uses the register, also for `li.s`. That's why some float functions only match with it.
- It can't read GNU `macro.inc`, so it can't build `INCLUDE_ASM` stubs. The default assembler stays `bin/ee-as.exe`. It reproduces everything else.

`text_parts.txt` accepts pseudo-flags that `tools/build_text.py` and `localdecomp/server.py` expand:

- `@ps2as`: assemble the range with Ps2EeAs (adds `-DNO_MACRO_INC` and drops the GNU `-Wa,` options).
- `@newas`: use `ee/bin/as.exe`.

gcc uses the last `-B`, so the range's choice wins over the Makefile's default.

Other notes:

- Globals that retail reads through `lui` and writes through `$gp` can also be reproduced with ee-as by using two declarations: an array for reads, and a sized alias (`D_X_g`) for writes. Several functions use this.
- `-Wa,-G0` with a sized declaration gives split loads with `lui $at` stores (func_00396B50).
- Split/no-split and assembler choice now vary per function. Single-function overrides in `text_parts.txt` are marked `# single-function override`.
- Still open: 64-bit constant synthesis (`li 0x8000; dsll 24`, func_00383B08), the `div.s` double-nop padding (func_003E1D18), and a few float `li.s` cases.

## Update 2026-09-26

### Ps2EeAs and `$gp`: declare the size early

With `@ps2as`, a sized `extern` alone gives `lui` accesses, because gcc writes its `.extern NAME, size` hints at the end of the file and Ps2EeAs is single-pass. To get `$gp` for a variable that retail always reaches through `$gp`, put the hint before the function:

```c
__asm__(".extern D_001D6DA4, 4");
extern s32 D_001D6DA4;
```

`.extern` declares a size only and creates no storage. Used in func_003969B8 and func_003D3050, and it gets every memory access of func_0039BEC0 right (5B90/5B94/4CEC/1A7430 through `lui`, 6DA4/6D9C/6DA0/6DA8 through `$gp`, the 5B90 store as `lui $at` + `sw`). func_0039BEC0 is still not a match: retail keeps `screenId` in `$t3` (`move $t3, $a0` in the first delay slot) and uses `$a0` for the `-2` constant. About 40 source variants did not change that register allocation.

### Float constants: `R_MIPS_LITERAL lit4` means inline `li.s`

Retail builds most float constants inline (`lui $at` / `ori` / `mtc1`). `bin/ee-as.exe` puts them in a `.lit4` pool addressed through `$gp`, which fails to link (`relocation truncated to fit: R_MIPS_LITERAL lit4`) and would not match anyway. Ps2EeAs expands them inline, so such functions need `@ps2as` (func_003830E8 is an example).

### Still unreproduced: `lwc1` from `$gp` followed by a load-delay `nop`

func_003882D0, func_00388308 and func_00388340 load a float with `lwc1 $f0, -0x75a8($gp)` and retail has a `nop` before its use. Plain C with a sized `extern f32` gives the right load but no `nop` with `bin/ee-as.exe`, Ps2EeAs (with `.extern`) or `ee/bin/as.exe`, in split or no-split mode. The existing matches use a `$gp` register variable plus `__asm__("nop")`. Similar loads appear in func_0037FF90, func_003801C0 and func_003813E0.

### Work-in-progress flag overrides

`tools/localdecomp_flags.txt` (`func_XXXXXXXX <flags>`) gives a function flags in localdecomp and `tools/try_func.py` while it is still `INCLUDE_ASM`. `text_parts.txt` can't carry `@ps2as` for such a function, because Ps2EeAs can't assemble the stub. Once the function matches, its flags move to a single-function override in `text_parts.txt`.

### Linux builds

The whole build runs on Linux with wibo 1.0.0-beta.1 running the Windows toolchain, and gives the same `MATCH` (`tools/build.py`). Per-function matching works the same way through `tools/try_func.py`.

### Contributor tooling

- `tools/try_func.py`: compile one C file with its range's flags and diff it against retail, with relocations masked. `--all-modes` tries split/no-split times ee-as/Ps2EeAs.
- `tools/pr_check.py`: source checks for the usual full-build failures (unbalanced markers, C plus `INCLUDE_ASM` for one function, variable definitions, conflicting typedefs, aliases missing from `symbol_addrs_resolved.txt`, `@ps2as` ranges containing stubs, retail files tracked by git) and, with `--obj`, data sections in `text.c.o`.
- The contributor guide lives in `docs/wiki/` and is synced to the GitHub wiki.

## Update 2026-09-26 (2): blockers for 100%

The full breakdown and plan are in `docs/full_match_roadmap.md`. The findings in brief:

- **Jump tables fixed.** The 47 switch tables form one block at the start of `.data` (0x317FE0 to 0x318CB0), 16-byte aligned, in function order, fenced by `0xCDCDCDCD` linker fill. It is the concatenated read-only data of all source files. gcc's `.rdata` directive lands in the section named `.rodata`, which the old linker script discarded. `tools/migrate_jtbls.py` split the blob into `data_a`/`data_b` and moved the tables into `text.c` (`INCLUDE_RODATA`), and `text.c.o(.rodata)` now links between the halves. `func_003B0FC8` is the first C `switch`; the full build matches.
- **VU0 inline asm matches.** `func_00388698` (lqc2/vmini/sqc2) matches as `__asm__ __volatile__` with explicit `$vfN` registers and the default assembler, which moves the last instruction into the `jr` delay slot.
- **Linker remnants.** 203 splat "functions" are just [instruction, `nop`] pairs with no return and no references (619 instructions, 449 of them `addiu $sp, $sp, N`). They are the last odd instruction of functions the original linker stripped. They are not source.
- **Handwritten.** 100 functions are flagged handwritten by spimdisasm and belong in `.s` files.
- **Floats through `$gp`** are small-data variables (220 in frontbin's `.lit`, 8 in the main executable's), not literals.
- **Short loops.** The default ee-as does not pad short loops in gcc output (gcc emits them in noreorder mode). Ps2EeAs does pad them, which matters for `@ps2as` functions with tight loops.
- **Ps2EeAs has automatic DIV hazard padding.** Its strings include "DIV related opcode too near branch instruction - Added %i padding NOP/s". This is the lead for the open `div.s` double-nop case (func_003E1D18).
- **`/DISCARD/ : { *(*) }`** at the end of the linker script silently drops any section not named earlier. Check it whenever C starts producing a new section type.

## Update 2026-09-27: inline-asm leaves, and a false-match class

- **VU0/MMI leaf functions match as one inline-asm block.** 27 matched this way (func_00388680, func_003886B0, func_003886C0, func_003886E8, func_00388700, func_00388718, func_00388758, func_00388830, func_00388880, func_003888C8, func_003888F0, func_00388948, func_00388B40, func_00388B68, func_00388B98, func_00388BF0, func_00388EB8, func_00388F50, func_003890D8, func_003890F8, func_00389118, func_00389240, func_003892D8, func_00389330, func_0039BC90, func_003CC838, func_003CD7D0). `tools/gen_asm_func.py` drafts them from the retail asm.
  - The raw `.word` lines that `fix_quadword_ops.py` writes have to be decoded back to lqc2/sqc2/lq/sq.
  - gcc ends the function with its own `j $31`. The default assembler (reorder mode) moves the block's last instruction into that delay slot; Ps2EeAs does not. Whichever matches retail decides the assembler, so both are worth trying (`@ps2as` for 3 of the 27).
  - A block containing a branch label needs `.set noreorder` around it.
  - Functions ending `mtc1 $x, $f0` still fail (2 instructions off): retail has that in the delay slot, and gcc owns the return value, so the value has to come out of C, not out of the asm block.
- **Trailing padding blocks conversion.** A function whose `.s` carries padding words after it (func_0039BD08: 0x24 bytes + 5 nops before the next function at 0x39BD40) cannot simply become C: dropping the padding shifts every later function and rewrites every `jal` target, even though the function's own bytes are exact and the single-function diff says MATCH.
- **localdecomp scored 26 non-functions as perfect.** Its single-function diff trimmed up to 8 bytes of overshoot to ignore `.align` padding, which also hid gcc's `j $31` + `nop`. A "function" whose body is one `asm volatile("addiu $sp, $sp, 0x10")` therefore scored 0 while being unusable in the build. The trim now only removes trailing zero words, and `tools/pr_check.py` warns when status.json's perfect count runs ahead of what text.c actually has as C.
- **`try_func.py` gave false MATCHes on swapped `$gp` stores.** It masked every relocated field, and two stores through `$gp` differ only in their relocated offsets. It now fills relocations in with the symbols' real addresses (symbol_addrs_resolved.txt, or the address in a D_/func_ name) and compares them in full; only section-relative relocations are still masked. Rechecked against all 617 previously matching blocks: no false failures. This, not "context in the full build", was why func_003AEDC8 and func_003AED08 needed their stores reordered.
- **VU0 leaves ending `mtc1 $x, $f0` in the delay slot are hand-written.** Even with gcc emitting the `mtc1` itself (a union return from an asm output bound to `$4`), neither gcc's delay-slot filler, ee-as, Ps2EeAs nor ee/bin/as.exe puts it in the `jr $ra` slot. The originals wrote the whole function, `jr` included, in assembly.
- **Hand-written functions and linker remnants moved out of INCLUDE_ASM** (`tools/migrate_asm_sources.py`): 100 to `asm/handwritten/` via `ASM_FUNC`, 203 to `asm/remnants/` via `LINKER_REMNANT`. Same bytes; they stay in the objdiff base build, so they count as done.
