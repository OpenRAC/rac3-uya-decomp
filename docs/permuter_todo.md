# decomp-permuter worklist

Near misses found while matching on 2026-09-30/10-01. Every instruction is right (or nearly) and the difference is register allocation or scheduling, so these are decomp-permuter targets (see `docs/permuter.md`). Scores are the localdecomp score at the best flag mode (0 = match, lower is closer); sizes are in bytes.

The first three groups are **families**: solve one member, then transplant the C to the rest (only constants, symbols and a few offsets differ).

## Table-lookup family (16 functions)

Each looks up an object through the `D_001DA9B8` singleton, checks it with a virtual call, then calls a function found by a hash lookup. A generator produced the draft for every member and all compile; none match yet. Retail keeps the singleton pointer in `$a0` and the object in the saved copy of `arg0`, and gcc hoists the table address instead.

| Function | Score |
|---|---|
| `func_003E29B8` | 670 |
| `func_003E2118` | 730 |
| `func_003E2728` | 790 |
| `func_003E28E0` | 790 |
| `func_003E2808` | 790 |
| `func_003E21F8` | 850 |
| `func_003E1F40` | 885 |
| `func_003E2028` | 1005 |
| `func_003E1E50` | 1005 |
| `func_003E2C88` | 1005 |
| `func_003E2B98` | 1530 |
| `func_003E22D0` | 1530 |
| `func_003E23C0` | 1530 |
| `func_003E30C8` | 2135 |
| `func_003E2A90` | 2330 |
| `func_003E2618` | 2330 |

## Mod-3 hash lookups (3 functions)

Loop is right; retail places `x = 0` after the sentinel address is formed.

| Function | Score |
|---|---|
| `func_003E4890` | 60 |
| `func_003E4918` | 60 |
| `func_003E4DA0` | 60 |

## Mod-3 hash inserts (3 functions)

Same loop as above plus a call to the lookup; the `key & 1` and base-pointer setup are scheduled earlier in retail.

| Function | Score |
|---|---|
| `func_003E5F00` | 285 |
| `func_003E6680` | 285 |
| `func_003E67B8` | 285 |

## Individual near misses

| Function | Size | Score |
|---|---|---|
| `func_003ADAE0` | 0x5C | 20 |
| `func_003AE1A8` | 0x94 | 20 |
| `func_003E9BA8` | 0xA4 | 25 |
| `func_003958A0` | 0x50 | 30 |
| `func_003B8A68` | 0xA4 | 30 |
| `func_003CB890` | 0xC4 | 40 |
| `func_003B1430` | 0x60 | 60 |
| `func_003AAEC8` | 0xC0 | 60 |
| `func_003E8718` | 0x70 | 65 |
| `func_003E91F8` | 0x64 | 90 |
| `func_003B11C0` | 0x50 | 105 |
| `func_003E18C0` | 0x68 | 180 |
| `func_003B42D0` | 0xE0 | 180 |
| `func_0038EA58` | 0x2C | 210 |
| `func_003AE120` | 0x84 | 230 |
| `func_003ADF88` | 0xDC | 240 |
| `func_003EC6E0` | 0x80 | 245 |
| `func_003EA9B0` | 0x84 | 265 |
| `func_003A32E0` | 0x88 | 355 |
| `func_003B9B60` | 0x88 | 365 |
| `func_003BA2A8` | 0xA8 | 365 |
| `func_003C1A40` | 0x20 | 425 |
| `func_003AE098` | 0x84 | 450 |
| `func_003A2E40` | 0xA0 | 535 |
| `func_003A9CF8` | 0xE4 | 570 |
| `func_003B6368` | 0xA8 | 620 |
| `func_003E0FC8` | 0x11C | 630 |
| `func_003B1518` | 0x9C | 785 |
| `func_0039C1C8` | 0x48 | 795 |
| `func_003E0870` | 0x90 | 830 |
| `func_003B7618` | 0x258 | 1000 |
| `func_0039CC98` | 0x20C | 1000 |
| `func_003B5440` | 0x284 | 1000 |
| `func_003EB180` | 0x1D4 | 1000 |
| `func_003BA3E8` | 0xA8 | 1000 |

## Update 2026-10-01 (second pass)

Matched since the list above was written: `func_003AE1A8`, `003E9BA8`, `003B8A68`, `003E18C0`, `003AAEC8`, `003E8718`, `003B42D0`, `003EA9B0`, `003B11C0`, `003EC6E0` (permuter or by hand), plus 14 plain functions from the by-hand pass. Closest remaining, with the best score reached (the sources are in the gitignored `scratch/permuter_bests/<func>.c`, first line = score and flag mode; start the permuter from those, not from a fresh m2c draft):

| Function | Score | Mode |
|---|---|---|
| `func_003ADAE0` | 10 | N (only the `lui` temp register differs) |
| `func_003958A0` | 20 | S |
| `func_003ADF88` | 40 | default |
| `func_003CB890` | 40 | default |
| `func_003B1430` | 60 | S |
| `func_003AE120` | 135 | PS |
| `func_003E91F8` | 170 | NPS |

Not touched yet: the mod-3 hash lookups/inserts and the 16-function table-lookup family above. Hand-search tricks that matched things in this pass: drop temporaries (`func_003B8A68`, `003AAEC8`), `(a1 << 2)` for the index (`003E18C0`), reorder stores (`003E9BA8`, `003EA9B0`).

More near misses from the by-hand pass (not saved in `scratch/permuter_bests/`, rewrite from the m2c draft):

| Function | Score | Note |
|---|---|---|
| `func_003BF4F8` | 20 (PS) | only the stack-byte store/load order differs |
| `func_003AED40` | 100 | one missing `nop` in a short loop containing a `jal` |
| `func_003BC0F0` | 120 (default) | one swapped `daddu $4/$5` pair in the third `func_0011B754` call |
| `func_003D27C0` | 205 (N) | scheduling of one `lw` from `D_001A1ED4` |
| `func_00396F18` | 60 (NPS) | position of `sd $ra` in the prologue |
| `func_003B2958` | 340 | second loop has pointer/counter registers swapped |

Tooling gap: `tools/asm_filter.py` does not pad short loops that contain a `jal` (`jal` is not in its simple-op list), but retail has the pad `nop` there (`func_003AED40`, `func_003B46F0`). Fixing the filter would unlock these without inline asm. Two idioms from this pass: `*(s32 *)0x1D4B4C = 0;` gives `lui $at; sw lo($at)` where a declared global gives `$gp` or `$v1`; chain `&` over call results with a separate temp (`t = f() != 0; r = r & t;`), because `r &= f() != 0` becomes `movz` (`func_003E3700`).
