# UYA / RAC2 / RAC1 / Lombyte: cross-repository resources

Prepared on 2026-10-03 to identify useful reference implementations and targets while distinguishing algorithmic similarity, existing C source, and verified matching.
Versioned references were inspected locally with `git show` at the commits below. The newer `003BEB58` contribution is linked separately; its function-level comparison and integrated full build have passed.
Dates are Git committer timestamps (`%cI`), retaining their original UTC offsets; they are not author or publication dates.

| Key | Project / credit | Exact SHA | Commit timestamp |
|---|---|---|---|
| U | vetusmagnus / ratchet-uya-decomp | `f0685ac7cc859d469aced63b9b892679e33bdee6` | `2026-10-02T20:23:34-04:00` |
| R | llesieur99 / rac2-decomp | `8c781ebf62b5ceff9615ad20373ba14d4070abc9` | `2026-10-03T00:48:47-04:00` |
| L | mateuszklysz / Lombyte | `f10ca43d95edef7596bbc1b745a28aa5129703fe` | `2026-10-03T01:44:38+02:00` |
| P | Veradictus / rac1-decomp, originating from Kryštof “Lynder063” Malinda's work | `82cc82dd4fc81725c2d0057e28beb264c84f66d2` | `2026-10-02T22:19:18-06:00` |
| O | OpenRAC / rac1-decomp (the organisation repository that P's fork merges into) | `661bb60c1fb2e8f4e335a577193b8ee4a165b8fc` | `2026-10-06T18:07:21-06:00` |

## O: libgcc and Sony library code in rac1-decomp (checked 2026-10-07)

O rebuilds RAC1's `libgcc` from GCC's own sources ([O libgcc README][o-libgcc]) and builds most of its Sony library code (newlib, libkernl, libcdvd, libgraph, libmpeg and more) with Sony's 2.9-ee compiler. UYA links the same kind of code: 56 boot_elf core functions are byte-identical to `libgcc.a` members, and about 440 more core functions carry Sony 2.9-ee or 2.96 fingerprints (see [boot_elf.md](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/boot_elf.md)). What carries over:

| What O does | Where | Use for UYA |
|---|---|---|
| `libgcc2.c`, `gbl-ctors.h`, `longlong.h` from GCC trunk `31cf01446d` (1999-09-09); `fp-bit.c` from GCC 2.95.3 with `NO_DENORMALS` backported and one shared `__thenan_df`; stand-in build headers | [`src/libgcc/`][o-libgcc] | The same sources build UYA's libgcc modules. Our i5bootn matrix used the 2.95.2 release `libgcc2.c` and Sony's no-denormals change written in place; both work. GPLv2 with the libgcc exception. |
| Flags `-O2 -G2 -S`, `-DIN_LIBGCC2 -DL_<module>`, one object per `L_` module; `FP_DEFS := -DFLOAT_BIT_ORDER_MISMATCH -DNO_DENORMALS -DUS_SOFTWARE_GOFAST`, `fp-bit.c` built twice (`-DFLOAT` for fp-bit.o) | [`Makefile.sn`][o-make] | One object per module reproduces the 8-byte alignment gaps between modules. Each division module has its own static `__clz_tab` in rodata, which needs its own rodata placement. |
| Compile through the 2.9-ee **driver** (`ee-gcc.exe`), never `cc1` directly | O libgcc README | The driver supplies `__mips__`/`__R5900__`, which `longlong.h` needs; through `cc1` alone `__divdi3` and `__muldi3` come out wrong. |
| Per-file compiler: a third column `ee29` in `config/core_text.objects` selects a static pattern rule that compiles with 2.9-ee and an explicit `-I.../gcc-lib/ee/2.9-ee-991111/include` (the driver under Wine doesn't find its own include dir) | [`Makefile.sn`][o-make], `config/core_text.objects` | The model for our planned per-file compiler pseudo-flag in `text_parts.txt`, next to `@ps2as`. |
| Linker dead-stripping rule: an unreferenced function lost its first `floor(size/8)*8` bytes, leaving the last word plus alignment `nop` when its size is 4 mod 8; fill between objects is `0xCDCDCDCD` | `tools/strip_dead.py`, O libgcc README | Explains linker remnants inside library ranges, the same rule our remnants follow. |
| A function that matches a member of Sony's prebuilt `.a` archives is 2.9-ee code; the archives also give real names | O docs | Same method as our `libgcc.a` comparison; their names can label UYA's library functions. |

**Their three open modules match with our compiler.** O keeps `__moddi3`, `__udivdi3` and `__umoddi3` as stubs: with the Windows `2.9-ee-991111b/r4` `cc1` they get the right instructions but smaller stack frames, and their README notes Sony's objects were built on Linux. Compiled from O's own `libgcc2.c` with the **Linux 2.9-ee-991111-01** driver (`-O2 -G0 -DIN_LIBGCC2 -DL_<module>`), `_udivdi3.o`, `_umoddi3.o`, `_moddi3.o` and `_divdi3.o` are word-for-word identical to the members of Sony's `libgcc.a` (same frames: 0x10, 0x30, 0x40). This agrees with our i5bootn matrix (26 of 26 libgcc functions with 2.9-ee-991111-01, 23 of 26 with the Windows 2.9-991111). `_eh.o` needs GCC's `gthr.h`/`gthr-single.h` from the same era, which O's tree doesn't have; `frame.c` isn't in O either.

Other findings in O worth knowing (from its docs, not re-verified here):
- Sony's 2.96-ee-001003-1 pads `div.s`/`sqrt.s`/`rsqrt.s` with `nop; nop` by default (`-mno-handle-ee-div-pipeline-bug` turns it off); SN 2.95.x and 2.9-ee never do. A function with padded divides is a 2.96 candidate.
- 2.9-ee tail-calls a void function that ends in a call but never `return f(...)`; it has `-fstrict-aliasing` on by default; it saves registers with `sd` in 16-byte-stride slots. These match the library signs our boot_elf core pass found.
- O's 989snd (`989snd.c`, about 42 functions in C) is most likely an earlier build of the sound library in UYA's SN-compiled range at 0x13B330 to 0x13D420 (inferred from names and layout, not compared): a starting point for those functions.
- `__sclose` and the other stdio internals right after `sprintf` match only under 2.95.3, while `sprintf.c` matches only under 2.9-ee: compiler boundaries can fall inside a library.
- License: MIT for project code (keep the notice); `libgcc` sources GPLv2+ with the libgcc exception; `include/moby_pvars.h` is GPL-3.0 (from Wrench).

## Confirmed reference relationships: already C in UYA

| Relationship | Evidence in pinned sources | Use and limitations |
|---|---|---|
| CRC: L `FUN_0020acc0` ↔ U `func_00399748` | Same `0xEDB88320` initialization, `0x8000` test, `0x1F45` polynomial, and eight steps per byte. [L CRC][l-crc], [U text][u-text]. | Strong algorithmic relationship; no new port. L caps length at `0x1800`; U calls a capacity function. Length and accumulator signedness differ. |
| Linear interpolation: R `FUN_002AA140` ↔ U `func_003BEB48` | Same expression, `a + (b - a) * t`. [R candidates][r-c], [U text][u-text]. | Scalar reference for a vector operation. C is present; byte equality between games has not been measured. |
| Cosine interpolation: P `func_00214220` ↔ U `func_003BE6A8` | Explicit `t = 0/1` cases followed by interpolation weighted by the cosine of `t * pi`. [P mobyutil][p-moby], [U text][u-text]. | Semantic relationship. P's `FastCos` name alone does not establish the identity of U's callee. |

These references are not new progress gains. Floating-point evaluation order and signedness remain part of the matching problem.

## A new match informed by the cross-game reference

**U `func_003BEB58`: linear interpolation of four components.**
The pinned [U text][u-text] still contains its `INCLUDE_ASM` and the C implementation of scalar `func_003BEB48`; the new local implementation is not part of that snapshot. (Both links point at the single `src/text.c` from before the 2026-10-03 split. On current `main`, `func_003BEB58`, `func_003BEB48` and `func_003BE6A8` are in `src/frontbin/3BDAC0.c`, and `func_00399748` is in `src/frontbin/3958F0.c`.)
Local inspection of the generated target disassembly found two `lq` loads, two `sq` copies of 16-byte vectors, four calls to the scalar, and result stores at offsets `0/4/8/12`.
This observation comes from local generated disassembly, not a published ASM file in the linked sources. No target bytes or derived listing are reproduced here.
The useful sibling is therefore **U `003BEB48`**, with R `002AA140` as a cross-game reference. R's cubic interpolation `002A7AA8` implements a different algorithm.
The [new C implementation][u-vector] has a **strict 152-byte match**, with all four `jal` targets resolved to `003BEB48` and zero masks, requiring no flag override or added symbol aliases. Its integrated full build reports `MATCH`, SHA-1 `3bc94ee895e4b4af9b5602a229af599c1103b542` (0x218924 bytes), and `pr_check.py` reports `OK`. This is a new C function, unlike the already-C references above. [PR #5][u-pr5] is a contribution awaiting maintainer review, not a claim that upstream has merged it.

**ABI pattern: two aligned vectors passed by value.**
The matching signature takes an output pointer, two four-`f32` structures explicitly aligned to 16 bytes **by value**, and an `f32` interpolation factor.
Passing the inputs as pointers describes a different ABI. Their observed `lq/sq` copies must not be mistaken for proof of pointer parameters. Preserve value semantics, alignment, and the four scalar calls when reproducing this pattern with the target compiler.
This is evidence for this function and toolchain, not a universal rule for vector arguments. Recheck argument placement and code generation for each target.
The complete PR #5 also includes `0038E730` and `003AD650`: **324 newly matched C bytes** across three functions. Those two functions are not claimed as cross-game ports. No PS2/gameplay validation is claimed.

## Verified frontend-to-level bridge

The cross-game interpolation references now also lead to concrete singleplayer
common-level implementations. At snapshot `df121cd88669b9de716e857336ad5c44d30ef438`,
the opt-in [common C path][u-common-c] covers 33 canonical functions / 6060 bytes.
Every body passes complete raw compiler/member/common equality and independently
resolved retail equality, with zero masks and no unexpected allocated payload.
Official objdiff reports every catalogued function at 100%. Count each common
owner once, not once for each overlay; the canonical configuration is unchanged.

- [Level vector interpolation][u-level-vector] at `00444F70` transfers the
  verified U `003BEB58` implementation: 152 bytes, two aligned vectors passed
  by value, and four fully resolved scalar calls to level `00444F60`.
- [Level cosine interpolation][u-level-cosine] at `004421E8` transfers U
  `003BE6A8`: 148 bytes, the explicit endpoint cases, and the actual level
  cosine helper `0040C3C8`. P remains an algorithmic reference, not proof that
  its `FastCos` implementation or structure layout is identical.
- The quaternion caller in the same catalogue uses observed void-returning
  pointer interfaces, rather than unprototyped integer-returning casts. Full
  call resolution rejects a wrong alias even when raw size and bytes match.

[PR #8][u-pr8] is a contribution awaiting maintainer review. These are verified
UYA frontend-to-level transfers informed by the cross-game references, not
new RAC1/RAC2 matches, merged upstream progress, or playable-level validation.

## Types, alignment, and resources in both directions

- [L EE types][l-ee] declares four-float vectors, 4×4 matrices, and qword/TI storage aligned to 16 bytes; [U common][u-common] provides scalar types.
- Check scalar, pointer, and `long` widths, effective alignment, array strides, and argument/return ABI with the target compiler. The host ABI is not evidence for these properties.
- A 16-byte storage size does not establish every structure's alignment or guarantee matching `lq/sq` accesses. Field offsets remain specific to the game and version.
- L's [resource lookup][l-lookup] uses 64 records, a 16-byte stride, a value at `+4`, and rejection value `-3`. No UYA counterpart is established; this is a search signature, not a table to transplant.
- UYA→RAC1/RAC2: U `003E1150/003E11D0` describes a 1024-entry hash table, a tombstone, and key-dependent probing. No cross-game sibling is confirmed. Check collisions, deletion, duplicates, and saturation before functional reuse.
- Game-structure headers require verified provenance and independent offset validation before reuse; none are copied or proposed for transplantation here.

## Matching and relocation workflow

1. Pin the source commit, regional version, reference binary identity, target symbol, address, and size. A PAL name or address does not identify an NTSC/UYA function.
2. Use sizes and normalized hashes for candidate selection; then confirm instructions, constants, data accesses, and call relationships. [P's mapper][p-map] distinguishes `us_map` from size-sequence pairing.
3. [U's shared-overlay tool][u-shared] masks `j/jal` destinations when comparing relocated functions. This does not establish callee identity; its data deduplication is explicitly approximate.
4. Resolve each relocation against target symbols. Preserve `$gp` versus `lui/lo` accesses, declared global sizes, and function-local aliases; see [U matching patterns][u-patterns]. Do not apply a blind address delta.
5. Keep globals `extern` and retain the project's per-function overrides. [R compiler notes][r-compiler] documents a GNU-EE 2.9 profile, not a compiler prescription for UYA/SN.
6. Compare linked bytes at the exact address and size, using correct endianness and fresh artifacts. [R's verifier][r-check] checks reference identity and symbols; adapt its dependencies before porting it.
7. UYA requires `pr_check.py` and a full build reporting `MATCH`, as specified in [its contribution rules][u-contrib]. Similarity scores and algorithmic relationships do not replace that gate.

## Useful verification cases

- CRC: zero length, boundary and excess lengths, and bytes with the high bit set; retain the distinct signed/unsigned behaviors.
- Interpolation: `t = 0/1`, extrapolation, and destination/input aliasing; preserve copies and operation order rather than introducing FMA arbitrarily.
- Triage: preserved raw annotations, COP0/COP2 fallback, scalar SPECIAL2 exclusion from the packed-MMI bucket, and invalid-data fixtures. An opcode family does not prove that a region contains executable code.
- Matching: reject displaced aliases, missing symbols, size discrepancies, wrong regional binaries, and stale build results.

## Attribution and reuse boundaries

[L's license][l-license], [P's license][p-license], and [R's license][r-license] are MIT at the pinned snapshots; retain the applicable notices when reusing code.
No `LICENSE`, `COPYING`, or `LEGAL` file was found at the root of snapshot U. Contribution instructions alone do not establish a general reuse license.
This note describes relationships and methods. It distributes no new shared implementation, binary, asset, SDK, or generated game artifact. Contributions remain subject to the receiving project's permissions and matching requirements.

[u-text]: https://github.com/vetusmagnus/ratchet-uya-decomp/blob/f0685ac7cc859d469aced63b9b892679e33bdee6/src/text.c
[u-common]: https://github.com/vetusmagnus/ratchet-uya-decomp/blob/f0685ac7cc859d469aced63b9b892679e33bdee6/include/common.h
[u-shared]: https://github.com/vetusmagnus/ratchet-uya-decomp/blob/f0685ac7cc859d469aced63b9b892679e33bdee6/tools/split_shared_levels.py
[u-patterns]: https://github.com/vetusmagnus/ratchet-uya-decomp/blob/f0685ac7cc859d469aced63b9b892679e33bdee6/docs/wiki/Matching-Patterns.md
[u-contrib]: https://github.com/vetusmagnus/ratchet-uya-decomp/blob/f0685ac7cc859d469aced63b9b892679e33bdee6/CONTRIBUTING.md
[r-c]: https://github.com/llesieur99/rac2-decomp/blob/8c781ebf62b5ceff9615ad20373ba14d4070abc9/candidates/boot.c
[r-compiler]: https://github.com/llesieur99/rac2-decomp/blob/8c781ebf62b5ceff9615ad20373ba14d4070abc9/docs/COMPILER-NOTES.md
[r-check]: https://github.com/llesieur99/rac2-decomp/blob/8c781ebf62b5ceff9615ad20373ba14d4070abc9/scripts/check_candidates.py
[l-crc]: https://github.com/mateuszklysz/Lombyte/blob/f10ca43d95edef7596bbc1b745a28aa5129703fe/src/storage/memory_card/data/calculate_crc16.c
[l-ee]: https://github.com/mateuszklysz/Lombyte/blob/f10ca43d95edef7596bbc1b745a28aa5129703fe/include/eetypes.h
[l-lookup]: https://github.com/mateuszklysz/Lombyte/blob/f10ca43d95edef7596bbc1b745a28aa5129703fe/src/runtime/resources/lookup_resource_entry.c
[p-moby]: https://github.com/Veradictus/rac1-decomp/blob/82cc82dd4fc81725c2d0057e28beb264c84f66d2/src/game/mobyutil.c
[p-map]: https://github.com/Veradictus/rac1-decomp/blob/82cc82dd4fc81725c2d0057e28beb264c84f66d2/tools/lombyte.py
[l-license]: https://github.com/mateuszklysz/Lombyte/blob/f10ca43d95edef7596bbc1b745a28aa5129703fe/LICENSE
[p-license]: https://github.com/Veradictus/rac1-decomp/blob/82cc82dd4fc81725c2d0057e28beb264c84f66d2/LICENSE
[r-license]: https://github.com/llesieur99/rac2-decomp/blob/8c781ebf62b5ceff9615ad20373ba14d4070abc9/LICENSE


[u-vector]: https://github.com/llesieur99/ratchet-uya-decomp/blob/d54228fd175d1bac62ff6fb959a3f5ad8ea2cbcd/src/text.c#L11436
[u-pr5]: https://github.com/vetusmagnus/ratchet-uya-decomp/pull/5
[u-common-c]: https://github.com/llesieur99/ratchet-uya-decomp/blob/df121cd88669b9de716e857336ad5c44d30ef438/docs/common_level_c.md
[u-level-vector]: https://github.com/llesieur99/ratchet-uya-decomp/blob/df121cd88669b9de716e857336ad5c44d30ef438/src/levels/common/func_00444F70.c
[u-level-cosine]: https://github.com/llesieur99/ratchet-uya-decomp/blob/df121cd88669b9de716e857336ad5c44d30ef438/src/levels/common/func_004421E8.c
[u-pr8]: https://github.com/vetusmagnus/ratchet-uya-decomp/pull/8
[o-libgcc]: https://github.com/OpenRAC/rac1-decomp/blob/661bb60c1fb2e8f4e335a577193b8ee4a165b8fc/src/libgcc/README.md
[o-make]: https://github.com/OpenRAC/rac1-decomp/blob/661bb60c1fb2e8f4e335a577193b8ee4a165b8fc/Makefile.sn
