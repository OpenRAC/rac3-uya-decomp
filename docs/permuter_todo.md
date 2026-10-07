# decomp-permuter worklist

The frontbin near misses. The status list below (2026-10-07) is the current one: every frontbin function that is still `INCLUDE_ASM`, its best diff and what is left. The sections after it are a log, oldest first; rows for functions matched since have been removed.

## Status 2026-10-07

72 `INCLUDE_ASM` entries are left in `src/frontbin/` (`docs/remaining_functions.tsv`); `func_003ECDF0` (0x1B4, the last entry) ends in data and is not a real function, so 71 functions remain. Every one has a near-miss C draft with a header (flags, diff count, what is left, what was tried) in the reports bundles of the final passes (f, g) and round k.

- Diffs are aligned instruction diffs (the measure `tools/permuter_scorer.py` uses), from the latest report: g1 to g4 (second final pass), k2 for `func_003AA4B0` and `func_003953F0`, and m1's compiler-matrix re-measurement where it differs (marked m1).
- Most were measured before `-mvu0-use-vf0-vf2` became a base flag on 2026-10-07. That flag changes loop code, so re-measure a draft before working on it. m1 measured three that get closer with it: `func_003B1EB0`, `func_003A8230`, `func_0038FDC0`.
- "S" is split addresses, "N" `-mno-split-addresses`; "ps2as" the `@ps2as` assembler; "jform" the VU0 j-form (Matching-Patterns).
- Check `tools/text_parts.txt` for the function's range before trusting a draft's header: some headers had the mode wrong.
- Three blockers from the final passes are gone since round k: the prototypes for `func_00399A00`, `func_003ACB00` and `func_003B9DA8` in other functions' blocks are fixed, and `func_003BC218`'s extra rodata words can be written as a `const` array after the function.

| Function | Size | Bucket | Best | Flags | What is left |
|---|---|---|---|---|---|
| `func_003BC218` | 0x350 | switch | 1 | ps2as | Case 2's `r = 1` should reuse the constant-1 pseudo (`$s1`); 30 variants of the case-2 temporary and the switch index tried. When inserting, write the 42 data words after its jump table (0x318A18 to 0x318ABC) as `const u32 D_00318A18[42]` right after the function (text in the round k bundle, `k2/`). |
| `func_003B0A60` | 0x1E0 | plain | 2 | file flags (S), no override | Order of the `lui`/`addiu` of `D_0037B850` and the `move $a1` before the 5th sprintf. A double `do { } while (0)` around the table-base load got it from 12 to 2. |
| `func_003E09D8` | 0x1A0 | plain | 2 | default | Retail forms one address and `move $v1, $a2`; ours computes it twice. Looks like a gcse PRE copy; not reproduced. |
| `func_003E89F0` | 0xDC | plain | 2 | S ps2as | The `0x5C` store is issued early because it is the last use of the 1.0f constant (sched1 tie-breaker). Two-variable constants and store orders tried. The draft compiles in context (the file declares the function `s32`). |
| `func_00391E78` | 0x15C | plain | 3 | S ps2as | Local allocation gives the 0x25E4 byte `$v0` (retail `$v1`, with the 2 in `$a0`). |
| `func_003B43C0` | 0x1EC | plain | 3 | ps2as | The switch value lands in `$v0`, retail `$v1`; a 10-minute permuter run found nothing. |
| `func_003E0E90` | 0x138 | plain | 3 | S ps2as | Reorg steals the move into the `beqz` slot. Uses `static inline` helpers. |
| `func_0039CEA8` | 0x624 | switch | 4 | ps2as | `D.e[0].h` is read directly in the h1 helper; retail does not CSE that load to `e`. |
| `func_0039CAB8` | 0xE4 | plain | 4 | file flags | sched1 order of the constant loads versus the 12th argument's `dsll32`. 2.9-ee-990721 scores 2, read as noise (m1). |
| `func_0038DC08` | 0x2A8 | plain | 4 | S ps2as | The `0xE` register: the fake-lifetime adjacency of the `0x8000` constant (local-alloc's `find_free_reg` with sched2). Early locals `w`/`v` fixed the tail. |
| `func_003B9DA8` | 0xF0 | vu0 | 6 (4 in N mode, m1) | ps2as, jform | One float constant load is scheduled at the first stall instead of after the first `vadd`. Its blocking prototype is fixed. |
| `func_0038E930` | 0x128 | plain | 5 | ps2as | Head `sll` register and the second `sll` placement. The draft has volatile `pos` and `D_001D9F20` and a dead `else { pos = 0; }`. |
| `func_003ACB00` | 0x130 | plain | 5 | file flags (S) | Local allocation of the mult / `f50` / `f14` values at the loop bottom. The `func_003ACC30` prototype it needed is fixed. |
| `func_003B7B50` | 0x35C | mmi | 5 | S ps2as | Order of the three zero argument moves; a statement climb and argument variables didn't help. Uses the documented `sq $0` `"=m"` asm. The permuter's base score didn't agree with the aligned count here. |
| `func_003AA4B0` | 0x32C | plain | 5 (k2; was 13) | S ps2as | Before k2: sched1 put the `sp[3]` load before `$a2 = k`, so `k` lost `$v0`. k2's draft is in the round k bundle. |
| `func_003953F0` | 0x238 | switch | 7 (k2; was 15) | ps2as | Case 0's registers; all 90 statement orders of case 0 were tried before k2. |
| `func_003E0B78` | 0x148 | plain | 7 | default | Loop 2's table entry is in `$a0` where retail has `$v1`. One permuter output reused `j` (changed the meaning). |
| `func_003C1130` | 0x30C | vu0 | 8 | ps2as, no `-fopt-stack` | Listed in `sq_ra_funcs.txt`. Struct copies as statements in slot order got it from 49 to 8. |
| `func_003C9078` | 0x190 | plain | 8 | S ps2as | Retail loads `f1A` fourth and computes `b` in the `jal` slot; ours loads `f1A` second (more dependents in sched1's ranking). Same problem as `func_003C8ED0`. |
| `func_003EB180` | 0x1D4 | plain | 8 | S ps2as | All 120 orders of the first 5 stores and the constant-variable forms tried; a K&R zero-argument call to `func_003E16B8` fixed the `jal` slot. |
| `func_003A04A0` | 0x87C | vu0 | 8 | jform | Three scheduling spots. Not reworked since round d. |
| `func_00390730` | 0x4E8 | plain | 9 | S ps2as | The FP schedule in the angle block (`D_001D52FC->f1C4` read at every test, `do { } while (0)` around the angle statement). |
| `func_003BE1A0` | 0xBC | plain | 9 | S ps2as | Both permuter results changed the meaning and were rejected. |
| `func_00399A00` | 0x290 | plain | 9 | S, `-fforce-mem` | gcse PRE hoists the lone tail `%hi(D_142430)` before the first loop; with `-fno-gcse` the tail is retail's, but no C form stops the hoist. Its prototype in the `func_003972A0` block is fixed. |
| `func_003C8ED0` | 0x1A8 | plain | 11 | S ps2as | Only the loop body; the same `f1A` load-order problem as `func_003C9078`. Needs the alias `D_001D9388_003C8ED0`. |
| `func_003A21C0` | 0x2A0 | plain | 12 | S ps2as | sched1 moves `idx<<4` / `+arr` above the calls; `do { } while (0)` barriers fix that but break the `D_00225780` high-half copy (CSE is cut). Needs a scalar alias for `D_0022766C`. |
| `func_003921D8` | 0x224 | plain | 12 | S ps2as | Local-alloc order in the TEX0 tail. |
| `func_003B8560` | 0x19C | vu0 | 12 | S, jform | Retail copies the base into `$s5` after the guard; guard and in-loop forms tried. |
| `func_0038F3F8` | 0x9C4 | plain | 14 | S ps2as | 2 of the 14 are artifacts of the agents' diff tool (a retail `lui ..., 0x32` read as a jump-table high half). |
| `func_003B07B8` | 0x2A4 | plain | 15 | ps2as | Order of the local float constants. |
| `func_00382F90` | 0x154 | plain | 15 | S ps2as | Retail computes the h1 values before h0; uses constant-address stores; a dependency-aware climb gained nothing. |
| `func_00389FB8` | 0x890 | switch | 16 | S ps2as | A `kp = (volatile s32 *)&D_001D55C8;` pointer at the loop top fixed f16/f17; the rest is allocation. |
| `func_00395C48` | 0x1C4 | plain | 20 | file flags | First-block global allocation. |
| `func_003D1570` | 0xE0 | plain | 21 | default | Only the loop's register allocation; a rewrite in the style of its matched sibling `func_003D14D0` was worse. |
| `func_003D3428` | 0x358 | plain | 21 | | Declaration swaps and a climb gave nothing. |
| `func_0038FDC0` | 0x928 | switch | 22 (20 with vf2, m1) | S ps2as | Clamp constant, spill order. |
| `func_003E92D8` | 0x5DC | plain | 23 | ps2as | Not reworked in the final passes. |
| `func_00385E40` | 0x3CC | plain | 23 | | The CSE copy swap (set REG0 REG1) picks the other register. |
| `func_003ACD38` | 0x194 | plain | 24 | file flags | Prologue and pre-loop code match; the loop's globals start at `$a2` where retail starts at `$t0`. Keeps one volatile read from an earlier draft. |
| `func_003AE8A8` | 0x3F8 | switch | 25 | S ps2as | Block order in case 6. |
| `func_0039C548` | 0x1C4 | mmi | 25 (19 at `-G0`, m1) | | Store schedule through `p->` and registers. m1: the gp-relative address of a small-data object changes the schedule, so check its declaration. |
| `func_003EAC88` | 0x448 | plain | 26 | N ps2as | Float register order of w/sy/ay/sx/ax. |
| `func_003EA290` | 0x3B4 | switch | 27 | S ps2as | Registers for the four alpha bytes. `-fno-gcse` only fixes the word count, so it isn't needed. |
| `func_0038A848` | 0x964 | switch | 27 | S ps2as | Which of f16/f17 ends in `$f31`. Calls `func_00387118` through a floats-first alias: needs the symbol line `func_00387118_0038A848 = 0x387118;`. |
| `func_003AB3A8` | 0x260 | plain | 29 | S | Register numbering only; m1: needs a VU0 range of N <= 2 (the base flag now). Not reworked. |
| `func_00383FD8` | 0x440 | mmi | 29 | | Global-alloc placement of HIGH pseudos (2 diffs with only registers compared). |
| `func_003B9730` | 0x150 | vu0 | 31 | N ps2as, vf2 | |
| `func_00394C58` | 0x31C | mmi | 34 | | Loop-counter copies (analysis in the draft header). |
| `func_0037F978` | 0x570 | vu0 | 36 | jform | The `&v10` gcse reaching-register shape and the PRE of the 1e-5 constant. |
| `func_00381C18` | 0x178 | plain | 40 | | Combine's `lbu` narrowing versus retail's store order (CC6 first). |
| `func_003B6528` | 0xA00 | mmi | 41 | S ps2as | Reload's spare-register order (Matching-Patterns, batches 27 and 29). |
| `func_003AC6F0` | 0x30C | plain | 44 | S | Global alloc's first pass skips `$a2`/`$a3` for `sz` because the local pseudo `p0 - madr` prefers them. Probably wants the `func_003ACD38` rewrite (separate local for the position math). |
| `func_003DE560` | 0x30C | vu0 | 45 | S ps2as, jform | Not reworked. |
| `func_00394368` | 0x2F4 | mmi | 47 | ps2as | Global-alloc order (th, the k copy, an extra `$s7`). |
| `func_0038CC68` | 0x1D4 | plain | 50 | | The then-arm givs; a constant-address `0x1D4CF8`, a store climb and a non-replaceable `m0` giv got it from 104. |
| `func_00380D48` | 0x378 | plain | 56 (51 with N + `-fforce-addr`, m1) | S ps2as | Loop giv / strength-reduction shape. |
| `func_003A4E70` | 0x540 | mmi | 62 | S ps2as | Clamp on `sh`; needs the alias `func_003A4860_003A4E70`. |
| `func_003A35C0` | 0x440 | plain | 64 | S ps2as | Retail spills `lo` and `n` and keeps `q+0xC` in `$s6`. |
| `func_003830E8` | 0x754 | mmi | 76 | ps2as | Not worked: `div.s` issue order, store order. |
| `func_00395090` | 0x2C4 | mmi | 105 | ps2as | Its inner loop is `func_00394368`'s packet builder; match that first. |
| `func_003E9D78` | 0x300 | plain | 117 (113 with `-fno-schedule-insns2`, m1) | N ps2as | First call through a varargs cast; not reworked further. |
| `func_003B1EB0` | 0x410 | plain | 117 (79 with vf2, m1) | S | Layout of the spilled givs. Rework under the base VU0 flag. |
| `func_00390C18` | 0xDC8 | switch | 121 | | First 0x4E8 bytes match; case 2 tail and the i/sel tie looked at only. |
| `func_003BA9A0` | 0x4F8 | vu0 | 146 (124 in N mode, m1) | ps2as, vf2 | Retail spills six values; the draft was tuned in S. |
| `func_003B3558` | 0x860 | plain | 135 | S ps2as | Save-data serializer (0xC00 frame); surveyed only. |
| `func_003A8230` | 0x136C | plain | 141 (131 with vf2, m1) | S ps2as | Register allocation. Rework under the base VU0 flag. |
| `func_003A26D0` | 0x4EC | vu0 | 186 (169 with `-fno-gcse`, m1) | S ps2as, jform | Spills in the main loop and register pressure. Its `divs_nops.txt` line has the sixth count since round k. |
| `func_003C1440` | 0x4B4 | vu0 | 236 (229, m1) | ps2as, jform | First complete draft only. |
| `func_0038CE40` | 0xBE8 | mmi | ~330 (311 with `-fno-rerun-loop-opt`, m1) | | First draft (GS display / double-buffer setup). |
| `func_0039EE68` | 0xC8C | vu0 | 398 | ps2as, jform | Only the missing `func_0039ED50` prototype added since round d. |
| `func_0038B1E8` | 0x968 | mmi | ~400 (393 with `-fno-expensive-optimizations`, m1) | | First draft; the caller-saves `sq`/`lq` allocation isn't reproduced. |

## Log

Older entries, oldest first. The diffs in them are from the day they were written; the status list above supersedes them.

### Individual near misses (2026-09-30/10-01)

Scores in this and the 2026-10-01 sections are the localdecomp score at the best flag mode (0 = match, lower is closer); sizes are in bytes.

| Function | Size | Score |
|---|---|---|
| `func_003EB180` | 0x1D4 | 1000 |

### Update 2026-10-01 (second pass)

Matched in this pass: `func_003AE1A8`, `003E9BA8`, `003B8A68`, `003E18C0`, `003AAEC8`, `003E8718`, `003B42D0`, `003EA9B0`, `003B11C0`, `003EC6E0` (permuter or by hand), plus 14 plain functions from the by-hand pass. Hand-search tricks that matched things: drop temporaries (`func_003B8A68`, `003AAEC8`), `(a1 << 2)` for the index (`003E18C0`), reorder stores (`003E9BA8`, `003EA9B0`). Two idioms: `*(s32 *)0x1D4B4C = 0;` gives `lui $at; sw lo($at)` where a declared global gives `$gp` or `$v1`; chain `&` over call results with a separate temp (`t = f() != 0; r = r & t;`), because `r &= f() != 0` becomes `movz` (`func_003E3700`).

### Update 2026-10-01 (third pass)

Matched: `func_003BF4F8` (declare the locals in `r, g, b` order and store in natural order; `@ps2as`).

### The `sq`-saving functions (`tools/sq_ra_funcs.txt`)

All of them are matched now except `func_003C1130` (8 diffs, see the status list).

Lessons from the first two that matched (`func_003AAF88`, `func_003C0B10`):

- Do not cache a field chain in a local if retail re-reads it: `func_003C0B10` only matched with `obj->set->n` and `obj->set->arr[j]->e` written out each time (a local `s` kept a different register assignment). The permuter found this by inlining the local.
- A loop counter that retail keeps separate from the loop test needs its own variable (`j` for the first loop, `i` for the second).
- `$fp` shows up in gcc's output as `$fp`, not `$30`, which `asm_filter` had to learn before the slot remap worked.

### Near misses from the third hand pass (2026-10)

| Function | Diffs | What is left |
|---|---|---|
| `func_003E89F0` | 8 (N) | constructor on the `D_001DA9B8` singleton template; the vtable store is interleaved with the singleton address calculation in retail and `$v0`/`$v1` are swapped |

Large-function pass (2026-10-02, largest plain functions first). Matched: `func_0039DB38`, `func_003E3F08`, `func_003DF038`, `func_003DE8F0`, `func_00384420`, `func_003CBE40` (`volatile` on `D_001D9384` keeps its load out of delay slots and loops). Parked, with drafts in `scratch/` (gitignored):

| Function | Size | State | What is left |
|---|---|---|---|
| `func_0038F3F8` | 0x9C4 | 66 aligned diffs (S, `@ps2as`), 615 of 625 instructions | retail keeps a second copy of `&o->st` (`$s7` and `$s3`, frame 0x70 not 0x60); the per-direction chain loads into a temporary then `move`s it; the counter clamp is `slti` + `movn` where gcc gives `slt -1` + `movz`. Permuter running from 3550, best 3000 |
| `func_003A8230` | 0x136C | every instruction right, 718 aligned diffs | register allocation only: retail keeps widget pointers in `$s0..$s7` in a reuse pattern a flat `s + off` source does not reproduce |
| `func_003B3558` | 0x860 | not started | save-data serializer, 0xC00 frame, unaligned `ldl`/`ldr` copies |
| `func_003D3428` | 0x358 | 2 diffs (S, `@ps2as`) | GS packet writer; two loop increments swapped. Retail's register increments need `long step` variables: `u += step; w += step2;` with `x2` taken from the second induction variable `w` |
| `func_003B1EB0` | 0x410 | 45 diffs (S) | save-slot list; spilled induction variables and the slot base `&D_142430` reached two ways |

### Large-function near misses (batch 3, 2026-10-06)

Drafts are in the agents' `near_misses/` folders, each with a header (diff count, flags, what is left). Not inserted.

| Function | Diffs | Notes |
|---|---|---|
| `func_0039CEA8` | 5 | |
| `func_003A04A0` | 8 | vu0, uses the provisional `j` form |
| `func_0038F3F8` | 14 | 2 are tool artifacts |
| `func_00389FB8` | 20 | |
| `func_0038FDC0` | 22 | |
| `func_003E92D8` | 23 | |
| `func_0038A848` | 39 | |
| `func_003B6528` | 41 | |
| `func_003830E8` | 76 | |
| `func_00390C18` | 121 | |
| `func_003B3558` | 135 | |
| `func_003A8230` | 141 | |
| `func_0039EE68` | 409 | vu0; uses `__asm__("sq $0, %0")` |

Some c1 drafts rely on `volatile` reads to steer scheduling; check those against the sanctioned forms before inserting.

### MMI near misses after batch 29 (2026-10-06)

Aligned diffs (difflib over the disassembly). `.permuter.c` drafts are decomp-permuter output converted back to the draft style; check their semantics.

| Function | Diffs | Draft |
|---|---|---|
| `func_003B7B50` | 3 positional | hand |
| `func_00383FD8` | 27 | permuter; hand draft at 29 needs an `@ps2as` override at 0x383FD8 with a restore line at 0x384418 |
| `func_00394C58` | 32 | permuter |
| `func_0039C548` | 36 | permuter |
| `func_003A4E70` | 60 | permuter |
| `func_00395090` | 104 | permuter |
| `func_00394368` | 121 | permuter |
| `func_003B6528` | 191 (81 normalized) | hand; reload's spare-register order, see Matching-Patterns batch 29 |
| `func_003830E8` | 242 | hand |
| `func_0038CE40` | 233 normalized | hand |
| `func_0038B1E8` | 390 | hand |
