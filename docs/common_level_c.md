# Common-level C: verified sources and opt-in build

`src/levels/common/func_004D0538.c` is a C implementation of the canonical
Veldin function at `0x004D0538`, 304 bytes. Its source is adapted from this
project's existing `func_003ABC30`, not from a retail instruction listing.
The compiler settings come from that donor's range in `tools/text_parts.txt`.

The first catalogue entry uses the existing SN compiler, N/default settings,
and no inline assembly. The eight calls refer to the singleplayer executable's
`0x0011A0B0`; this does not claim that a multiplayer address is an equivalent
callee. Other placements and normalized hashes are only search candidates.

The catalogue also contains six call-free Veldin owners:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_004CF578` | `func_003AAC70` | 208 | N/default |
| `func_00495980` | `func_003B5128` | 196 | S/Ps2EeAs, inline float constants |
| `func_004CF648` | `func_003AAD40` | 192 | N/default |
| `func_004CF7D0` | `func_003AAEC8` | 192 | N/default |
| `func_00495A48` | `func_003B51F0` | 156 | S/default |
| `func_00417A30` | `func_0038E248` | 156 | N/default |

Two additional Veldin owners use explicit callee aliases derived from their
owning overlay, rather than a global address delta:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_00495868` | `func_003B5018` | 268 | S/default |
| `func_00514C58` | `func_003E3DF0` | 248 | N/default |

Their named R26 relocations have zero addends. Every call is resolved for the
complete retail-byte comparison; aliases do not change the C instruction body.
The second function retains the observed three-integer/five-float interface,
not the decompiler's guessed mixed-register argument list.

The same gates accept five further owners with complete declaration context:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_005147F0` | `func_003E3988` | 248 | N/default |
| `func_004CD018` | `func_003A95A0` | 244 | N/default |
| `func_005143A0` | `func_003E3700` | 240 | N/default |
| `func_00514B70` | `func_003E3D08` | 232 | N/default |
| `func_00519D48` | `func_003E8EC8` | 228 | N/default |

Eight more owners retain their observed integer/float interfaces and typed
callee aliases; the DMA routine uses ordinary volatile EE register accesses:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_005142D0` | `func_003E3630` | 208 | N/default |
| `func_005148E8` | `func_003E3A80` | 208 | N/default |
| `func_00511D38` | `func_003E17C0` | 204 | S/default |
| `func_004478E0` | `func_003BF4F8` | 200 | S/Ps2EeAs |
| `func_004C1AF0` | `func_003A3A40` | 188 | S/default |
| `func_00511200` | `func_003E0CC0` | 180 | S/default |
| `func_004CB610` | `func_003A7E80` | 180 | S/Ps2EeAs |
| `func_004957A0` | `func_003B4F50` | 176 | S/default |

Their 25 named calls are resolved individually, not masked. No callee gains
C credit merely because one of these callers uses it.

Two further call-free owners use the same gates:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_004CB788` | `func_003A7FE8` | 64 | N/default |
| `func_00490B98` | `func_003AEF70` | 64 | N/default |

They retain byte/float state updates and the observed word-field setter layout.
The ring-view candidate `func_004D06F8` is excluded: resolved retail equality
alone does not excuse a different raw object encoding.

`func_003C5640` adds a newly reconstructed 44-byte state transition, not a
frontbin body transfer. Its `flags_from=func_003C5098` is only an existing
compiler-profile anchor (S/default). The unused first argument's spelling does
not establish a semantic type for that slot. Its one GPREL16 load at body +0x14
references the real `D_001DFBC0`; ordinary GNU assembly needs no early-extern
metadata option. Raw compiler/member/common equality and fully linked retail
equality are separate gates, both satisfied without rewriting an instruction.

Eight additional owners include the by-value vector interpolation from the
verified frontbin contribution, cosine interpolation, quaternion composition,
typed state/property operations and a float-output record reader:

| Owner | Frontbin donor | Bytes | Existing compiler settings |
|---|---|---:|---|
| `func_00514220` | `func_003E3580` | 176 | N/default |
| `func_00510B80` | `func_003E06D0` | 160 | S/default |
| `func_00444F70` | `func_003BEB58` | 152 | S/default |
| `func_00450FE0` | `func_003C0D70` | 152 | S/Ps2EeAs |
| `func_0051AAD0` | `func_003E9C50` | 152 | N/default |
| `func_004421E8` | `func_003BE6A8` | 148 | S/Ps2EeAs |
| `func_00443FD8` | `func_003BEA80` | 148 | S/default |
| `func_00440CF8` | `func_0037E4B8` | 144 | S/default |

Quaternion helpers use actual void-returning pointer interfaces, rather than
unprototyped integer-returning casts. Both quaternion and by-value vector
storage retain their observed 16-byte alignment. Complete call resolution
caught and rejected two initially mistranscribed quaternion aliases; fixing
only their names leaves the raw body unchanged and proves the real targets.

Together these thirty-three sources cover 6060 owned function bytes. The float function
is still plain C: selecting the existing Ps2EeAs assembler is not inline ASM.
Every source passes the same complete-size and raw/resolved-byte gates.

## Seeded from frontbin

About 1100 canonical owners have the same instructions as a frontbin function
that is already C, apart from addresses. `tools/seed_levels.py` copies those:

1. Owners and frontbin functions are paired by their instructions with the
   address fields masked (j/jal targets, `lui` and the low halves that use a
   `lui` register or `$gp`). Field offsets stay in the comparison.
2. Each function's own pair gives the level address of every global and callee
   it touches. Names it only declares come from a per-level table built from
   every pair in that level; an address that pairs with two level addresses is
   dropped.
3. The frontbin block becomes a standalone source: the declarations it needs
   (followed through typedefs and prototypes), then the block, with every
   `func_`/`D_`/`jtbl_` name renamed. `.extern` size hints are dropped, since
   the gates allow no assembly; a function that needed them fails the byte
   gates.
4. Every candidate goes through `build_common_c.py`'s gates. Only passing ones
   are kept and added to `tools/common_c.json`; `--report FILE` lists the rest
   with the reason.

A donor in `tools/sq_ra_funcs.txt` or `tools/divs_nops.txt` passes its entry on
to `tools/common_c_sq_ra_funcs.txt` / `tools/common_c_divs_nops.txt`, which
`tools/asm_filter.py` reads alongside the target's own tables. The tool never
adds a name that is also a function in a built target.

    python tools/seed_levels.py --jobs 8

Run it after `make` (it reads `build/frontbin.elf` for function sizes) and
again whenever frontbin gains matches. The usual reasons a copy fails: the
donor accesses globals as `D_X` plus a field offset, which the raw-encoding
gate rejects because the target names each address; the donor needs Ps2EeAs's
`.extern` hints; or a jump table or float constant needs a data section.

## Which levels a function is in

A source is named after its canonical owner (the first level, in level
order, with that code), so its name says nothing about the other overlays.
`targets/levels/common_occurrences.tsv` lists every shared function: canonical
name, owner level, size, how many levels have it, C or asm, and the level
numbers. `tools/level_occurrences.py` regenerates it and prints the addresses:

    python tools/level_occurrences.py                       (rewrite the TSV after new matches)
    python tools/level_occurrences.py --function func_004D0538   (every level and address)
    python tools/level_occurrences.py --level 5_daxx        (one level's shared functions)
    python tools/level_occurrences.py --summary             (per-level progress)

1671 functions are in all 51 levels. Story levels are 94% to 99% shared code
(25 to 270 functions of their own; 571 in Annihilation Nation), the
multiplayer maps 5 to 13, and the multiplayer menu 2338.

About 20 canonical names belong to two different functions owned by
different levels: the address is the same, the code isn't. The catalogue
tells them apart by its `overlay` field.

## Trying one function

`tools/try_level.py` is the level counterpart of `try_func.py`. It runs the
gates for one source and, when the bytes differ, prints the compiled and
retail listings side by side:

    python tools/try_level.py src/levels/common/func_004D0538.c --flags-from func_003ABC30 --mode N --assembler default

An entry already in the catalogue needs no options. An empty function body
shows the retail listing. On a match it prints the catalogue entry to add.

## Private inputs

Supply your own extracted NTSC-U levels and the reference objects made by
`tools/gen_level_targets.py` and `tools/split_shared_levels.py`. Generate and
split the objects on a persistent Linux filesystem: `/tmp` can be volatile,
and the documented `ld -r` merge can alter text on a Windows mount.

The original target directory must contain all 51 unsplit level objects;
the split directory supplies `common.o`. No reference object, ELF, generated
assembly, SDK, or build artifact is added to Git.

Run from the repository root with the contributor Python environment:

```text
python tools/build_common_c.py --levels-dir PERSONAL_LEVELS --targets-dir ORIGINAL_LEVEL_TARGETS --common-target SPLIT_LEVEL_TARGETS/common.o
```

The default outputs are ignored build artifacts:

- `build/objdiff/base/common.o`: only the successfully compiled C functions.
- `build/objdiff/base/common.proof.json`: source/input hashes, flags, ownership,
  full-function size, resolved-byte proof and relocation evidence.

`--toolchain`, `--runner`, `--catalogue` and `--output` can be supplied explicitly.
No global toolchain, Makefile or CI configuration is changed by this command.

## Required gates

The builder refuses a function unless all of these pass:

1. The standalone source defines the catalogued function and contains no
   assembly tokens. The compiler creates no unexpected data sections.
2. Its address and complete size agree with both the personal ELF and the
   original reference object's function symbol.
3. Fresh ownership from all 51 objects chooses this level and symbol as the
   canonical common representative, with occurrences in multiple levels.
4. All compiler relocations resolve. The complete resolved function equals
   the personal retail bytes, with no masks or trailing-padding tolerance.
5. The unrelocated compiler body equals both the original owner object's body
   and the corresponding split common target body. No word projection or
   target-byte substitution is allowed.

The partial base uses the same relocation-free object representation as
upstream's split `common.o`. Its instructions come exclusively from the
compiler object. Dropping that representation's relocations is **not** the
retail-byte proof: gate 4 independently checks the fully resolved calls.
Functions whose object encoding differs must be investigated, not patched
into matching by copying reference instructions.

## Reporting and limits

Since 2026-10-04 the `levels/common` unit in `objdiff.json` uses
`build/objdiff/base/common.o` as its base, and `make objdiff` builds it with
`tools/common_c_base.py`. That script runs this builder with the inputs in
`C:\decomp-refs` (`levels/`, `level-targets/`, `level-targets-split/common.o`;
another folder with `UYA_REFS`), so CI and localdecomp's Full check count
every function that passes the gates. If a catalogued function stops passing,
`make objdiff` fails. On a machine without those private inputs it writes an
empty base instead: the report still runs and counts no common-level C. The
full-game denominator is unchanged.

Count the owned function once, not once per overlay or per identical alias.
Handwritten ASM, linker remnants, data and alignment bytes are not C gains.
Objdiff percentages alone do not prove the full-function relocation checks.
This is source/byte verification, not a playable-level build or gameplay test.
