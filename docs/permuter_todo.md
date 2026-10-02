# decomp-permuter worklist

Near misses found while matching on 2026-09-30/10-01. Every instruction is right (or nearly) and the difference is register allocation or scheduling, so these are decomp-permuter targets (see `docs/permuter.md`). Scores are the localdecomp score at the best flag mode (0 = match, lower is closer); sizes are in bytes.

The sections below are a log, oldest first, so many of their rows are matched by now. Check the status list here before picking one.

## Status 2026-10-02

Matched since they were listed here (no longer `INCLUDE_ASM` in `src/`): `func_0038C888`, `0038C9D8`, `0038EA58`, `00393380`, `003958A0`, `00396F18`, `0039C1C8`, `003A2E40`, `003A32E0`, `003AAEC8`, `003AAF88`, `003ADF88`, `003AE098`, `003AE120`, `003AE1A8`, `003AED40`, `003B11C0`, `003B1518`, `003B42D0`, `003B46F0`, `003B8A68`, `003BA3E8`, `003BC0F0`, `003BF4F8`, `003C0B10`, `003CB890`, `003D27C0`, `003E0478`, `003E0870`, `003E18C0`, `003E1D68`, `003E8718`, `003E9BA8`, `003EA9B0`, `003EC6E0`, the table-lookup family and the mod-3 hash lookups (below).

Every other function in this file is still open. Biggest leftover groups: the mod-3 hash inserts (`func_003E5F00`, `003E6680`, `003E67B8`), the `func_003DFB40` family (six functions), `func_003E1F40`, and the `sq`-saving functions other than the four matched ones.

## Table-lookup family (done except `func_003E1F40`)

Each looks up an object through the `D_001DA9B8` singleton, checks it with a virtual call, then calls a function found by a hash lookup. 15 of the 16 match with the template in `Matching-Patterns.md` ("Singleton vtable wrappers"): `func_003E29B8`, `003E2118`, `003E2728`, `003E28E0`, `003E2808`, `003E21F8`, `003E2028`, `003E1E50`, `003E2C88`, `003E2B98`, `003E22D0`, `003E23C0`, `003E30C8`, `003E2A90`, `003E2618`. `func_003E1F40` is still open (see the fourth pass below).

## Mod-3 hash lookups (done)

`func_003E4890`, `003E4918` and `003E4DA0` matched by naming the hoisted constants as locals and assigning them in retail's order (`Matching-Patterns.md`, "Init order before a loop").

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

## Update 2026-10-01 (third pass)

Matched: `func_003BF4F8` (declare the locals in `r, g, b` order and store in natural order; `@ps2as`). Permuter runs of 400 s gave no improvement on `func_003958A0` (20), `003ADF88` (40), `003CB890` (40) or `003B1430` (60). New or improved near misses:

| Function | Score | Note |
|---|---|---|
| `func_00391A18` | 20 (S) | two separate locals `s32 x, y;` (not an array), first call is `func_0038EDE8(a0, &x, &y)`; only the register order of two loads differs |
| `func_00396F18` | 60 (NPS) | only the position of `sd $ra` in the prologue differs |
| `func_003AED40` | 100 | loop padding `nop` after the `jal` delay slot; needs the `asm_filter.py` `jal` fix |
| `func_00389468` | 360 (PS) | `__asm__("" : "+f"(pi));` before `pi + pi` stops gcc folding it; retail uses `$f0`/`$f1`, mine `$f12`/`$f0` |
| `func_0038C888` | 400 | retail saves `$ra` with `sq`/`lq`; no flag mode emits it, likely needs inline asm |

## Update 2026-10-01 (fourth pass, 50 functions)

Matched by hand or by the permuter: see `Matching-Patterns.md`, "Patterns from the hand pass". Still open, best first (all within a few instructions of retail; sources are in `scratch/permuter_bests` if you kept them):

| Function | Score | Note |
|---|---|---|
| `func_003B8968` | 5 (def) | `addiu $s0,$s2,0x1a0` uses `$v0` for the base; retail copies `&D_00225780` into `$s2` in the `blez` delay slot. The permuter's `do { i = 0; ... } while (0)` prologue got it from 65 to 5 |
| `func_003B27A8` | 5 (PS) | case 6: retail's first arm jumps to the second arm's tail (`b ec`); mine merges into the third arm's. Needs `.extern` hints for the four `$gp` globals and byte globals as scalars |
| `func_003ADAE0` | 10 (N) | retail is split-address (`lui $v1; addiu $a0,$v1`) but then gcc merges the base into `$v0`; N mode gets the structure |
| `func_003B0DA0` | 20 (PS) | store order around the first call |
| `func_003AE120` | 30 (PS) | the two final stores come out in the other order |
| `func_003E8420` | 55 (NPS) | order of the first stores and the two `lui`s |
| ~~`func_003E4890`, `003E4918`, `003E4DA0`~~ | matched | see "Mod-3 hash lookups" above |
| `func_003AD650` | 60 (S) | retail fills the `blez` delay slot with `lui`; mine with the `sw` |
| `func_003DFB40` and `003DFCA8`, `003DFE10`, `003E50A8`, `003E5210`, `003AFAA8` | 140 (S) | use the result of `func_003E1770` (a pointer pass-through). Left: the register order of the middle `vt->f8(o, 2)` call (`lw $v0,8($s0); lw $v1,8($v0)` in retail) and where `li $a0,0x48` lands. Do not use the permuter's 25: it moved `s2 = func_003E1898(b1)` inside an `if` |
| `func_003E1F40` | 100 (S) | sibling of the matched `D_001DA9B8` wrappers; the table address is built `lui; addiu; jal; daddu` here, not `lui; daddu; jal; addiu` |
| `func_003E5F00`, `003E6680`, `003E67B8` | 120, 285 | mod-3 hash inserts: invariants (`key & 1`, base pointers) are hoisted in a different order |
| `func_003B8E10` | 210 (PS) | same base-register copy as `func_003B8968` |
| `func_003A4DC8` | 285 | two float temporaries swap `$f22`/`$f23` |
| `func_003B1430` | 10 (S) | `return D = 1` gives `v1` for the stored constant and `v0` for the return; retail shares `v0` and puts `addiu $sp` before the `lui` |
| `func_003C1A40` | 3 | `unsigned long` shift/or chain; retail does `dsll` of the last arg before the first `or` (returns the stored value) |
| `func_003EB6B0` | 12 | midpoint of a box; retail loads `b[0]` into `$f12` first and stores `sw 0x34` before `sb 0x30` |
| `func_0037DFD8`, `func_0038E730`, `func_0038E6D0` | 12-19 | table lookups; retail peels the first loop iteration (0038E730), merges the final select with `movz` (0037DFD8) |
| `func_003A9E60` | 19 diff (S, no `-fopt-stack`) | in `sq_ra_funcs.txt`; only the argument-copy registers differ (retail `$a0`->`$t5`, mine `$s1`) |

## The `sq`-saving functions (`tools/sq_ra_funcs.txt`)

`func_0038C888`, `0038C9D8`, `003AAF88` and `003C0B10` are matched. Status of the rest (C drafts are in `scratch/`, gitignored; each has a line in `tools/localdecomp_flags.txt` with the right flags):

| Function | Status |
|---|---|
| `func_003A9E60` | 19 diffs (S, no `-fopt-stack`): only the argument-copy registers differ (retail `$a0`->`$t5`, mine `$s1`) |
| `func_003B82C0` | 48 diffs (S, `@ps2as`): right code, `$s` registers allocated in a different order (retail `$s0..$s7` = a7, a6, a4, a5, a3, a2, a1, ctx); statement-order and expression variants and 10 minutes of permuter did not move it |
| `func_003BA5B8` | 73 diffs (`@ps2as`): `a7` is spilled to `0x10($sp)` in retail but kept in `$fp` by gcc; the 128-bit copies and the `vadd.xyz` block are done |
| `func_003D1B10` | 95 diffs (`@ps2as`): same instructions as retail modulo registers (a multiset check), only scheduling and allocation differ; locals for the three packed words change the frame (0x70 instead of 0x80), so do not use them |
| `func_003D2370` | not started; sibling of `003D1B10` (same GIF packet style), m2c draft works |
| `func_003B3DB8`, `func_003869E8` | not started; m2c drafts work (`003869E8` has VU0 code) |
| `func_003C1130`, `func_003A6C30` | not started; m2c fails on them ("two delay slot instructions in a row") |

Lessons from the two that matched:

- Do not cache a field chain in a local if retail re-reads it: `func_003C0B10` only matched with `obj->set->n` and `obj->set->arr[j]->e` written out each time (a local `s` kept a different register assignment). The permuter found this by inlining the local.
- A loop counter that retail keeps separate from the loop test needs its own variable (`j` for the first loop, `i` for the second).
- `$fp` shows up in gcc's output as `$fp`, not `$30`, which `asm_filter` had to learn before the slot remap worked.

## Near misses from the third hand pass (2026-10)

| Function | Diffs | What is left |
|---|---|---|
| `func_0038E508` | 3 (S) | retail does not thread the `*st == 0xD` test into the `== 3` test (jumps to the second compare); gcc threads it |
| `func_00385908` | 4 (S) | retail computes each loop base with `lui $s; addiu $s, $s` (two registers in sequence); gcc interleaves through temporaries |
| ~~`func_00393380`~~ | matched | plain C once `tools/divs_nops.txt` took over the `div.s` padding |
| `func_0037F4F8` | 2 (S) | VU0 pointer: retail adds the base after the first `lqc2`, gcc before |
| `func_003BFBA8` | 21 (S, `@ps2as`) | VU asm at the top of the function is scheduled above the register saves in retail |
| `func_003C8CE0` | 20 (S, `@ps2as`) | store order of the `lui $at` macro stores |
| `func_003C9AE0` | 23 (S) | nested table loops; counted inner loop form not found |
| `func_003A5CA8` | 16 (N) | order of the byte stores at the end and where `lw $a0, 0x20($s0)` is placed |
| `func_003B60F0` | 35 (S, `@ps2as`) | float clamp with two stores; retail uses `$f4`/`$f1` select form |
| `func_003B9B60`, `func_003BA2A8` | 6, 10 (S) | sibling init functions: retail puts `move $a1, $zero` in the first call's delay slot after the `lui $at` byte stores; gcc fills the slot with the last byte store instead. Same fix would do both |
| `func_003E89F0` | 8 (N) | constructor on the `D_001DA9B8` singleton template; the vtable store is interleaved with the singleton address calculation in retail and `$v0`/`$v1` are swapped |
| `func_0037E878` | 7 (N) | retail keeps the counter address in `$a0` (then `$s3`); gcc uses `$v1` |
| `func_003E0478` | 4 (S) | the loop is right; `$s1`/`$s2` (`n - 1` and the next element pointer) are swapped |
| `func_003BE418` | 4 (S) | min/clamp of two bytes: `$v0`/`$v1`/`$a1` assigned differently |
| `func_003E5F00` | 5 (S) | hash insert with the zero-argument call and the `$gp` tombstone address; only the order of the four loop-setup moves differs |
| `func_003BD428` | 6 (S, `@ps2as`) | `$v0`/`$v1` swapped between the end pointer and the copy of `p` |
| `func_003A3430` | 8 (S, `@ps2as`) | argument-to-`$s` register order (retail `$s0..$s4` = a..e) |
| `func_003E0798` | 52 | singleton wrapper; retail keeps four `$s` registers (`o` distinct from `p`, `idx*4` saved) |
| `func_003822C8` | 43 | three-level `u16` table lookup; gcc folds the `+4` into the base, retail keeps `l` and adds `4` per load |

Near misses from the `div.s` pass (the padding itself is solved, see `tools/divs_nops.txt`):

| Function | Diffs | What is left |
|---|---|---|
| `func_003A6640` | 3 (S) | retail loads `$a2`, then `sltu`, then `move $a3, $a2`; mine loads `$a3` and copies to `$a2` |
| `func_003D3EE0` | 9 (S) | `$s1`/`$s2` swapped between the float source pointer and the quad source pointer |
| `func_003B5AB0` | 61 | callee-saved float registers `$f20-$f23`: retail has 11.0, 0.49, 6.0 and the scale in that order |
| `func_003BF910` | 36 | the `max(abs)` chain: retail keeps `abs.s` results in `$f1/$f0/$f2` and branches with `bc1tl` |
| `func_003B6410`, `func_003B6368` | 4, 14 | `sll` for the index lands in the `beqz` delay slot in retail, `lui` in mine |
| `func_003E1D68` etc. | matched | needed `@ps2as` plus `.extern X, 4` for the `$gp` floats |

Large-function pass (2026-10-02, largest plain functions first). Matched: `func_0039DB38`, `func_003E3F08`, `func_003DF038`, `func_003DE8F0`, `func_00384420`. Parked, with drafts in `scratch/` (gitignored):

| Function | Size | State | What is left |
|---|---|---|---|
| `func_0038F3F8` | 0x9C4 | 66 aligned diffs (S, `@ps2as`), 615 of 625 instructions | retail keeps a second copy of `&o->st` (`$s7` and `$s3`, frame 0x70 not 0x60); the per-direction chain loads into a temporary then `move`s it; the counter clamp is `slti` + `movn` where gcc gives `slt -1` + `movz`. Permuter running from 3550, best 3000 |
| `func_003EB728` | 0xCA4 | about 105 aligned diffs (N, `@ps2as`), frame and saves right | text layout with two inline helpers (parameters evaluated into `$s` registers first); retail re-reads `o->p` at a two-predecessor block that mine CSEs. Permuter: 7600 to 6800 in an hour |
| `func_003A8230` | 0x136C | every instruction right, 718 aligned diffs | register allocation only: retail keeps widget pointers in `$s0..$s7` in a reuse pattern a flat `s + off` source does not reproduce |
| `func_003BC568` | 0xA3C | 250 aligned diffs | HUD layout; retail keeps `&D_002CE0E0` in `$s5` and rederives it later from `&D_002CE100 - 0x20` |
| `func_003B3558` | 0x860 | not started | save-data serializer, 0xC00 frame, unaligned `ldl`/`ldr` copies |
