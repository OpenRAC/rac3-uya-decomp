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
   the gates allow no assembler directives; a function that needed them fails
   the byte gates. Inline asm statements in the function (VU0, MMI) stay, and
   the entry gets `"inline_asm": true` ([Inline assembly](#inline-assembly)).
4. Every candidate goes through `build_common_c.py`'s gates. The first build
   uses the profile `tools/asm_profile.py` reads off the owner's retail bytes,
   with the donor's mode or assembler wherever retail shows nothing; if that
   differs from the donor's flags and fails, the donor's flags are tried too.
   Only passing ones are kept and added to `tools/common_c.json` (with
   the profile that passed); `--report FILE` lists the rest with the reason.
   `--inline-asm-only` tries only the blocks with inline asm.

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

## Inline assembly

Since 2026-10-20 a common-level source may use GCC inline asm statements
inside its function, and the function counts as C. Insomniac wrote VU0
macro-mode math and MMI instructions (`plzcw`, `pextlw`, `qmtc2`, ...) as
inline asm in C functions, and ee-gcc 2.95 can't emit them any other way;
kfiv-decomp, God Hand and DOTR count such functions as matched C too, and so
do this project's frontbin and boot_elf. Every other gate is unchanged:
complete size, resolved retail bytes, raw object body equal to the split
common target, no data sections.

`pr_check.inline_asm_statements` decides what is allowed; `build_common_c.py`,
`try_level.py`, `seed_levels.py` and localdecomp's level editor all use it:

| Allowed | Refused |
|---|---|
| `__asm__`/`asm` statements with instructions, inside the function body, volatile or not, with or without operands | `INCLUDE_ASM`, `INCLUDE_RODATA`, `ASM_FUNC`, `LINKER_REMNANT` |
| `.set noreorder`/`reorder`, `noat`/`at`, `nomacro`/`macro`, `push`/`pop` inside a statement | every other directive: `.extern` size hints, `.word`, `.section`, ... |
| | file-scope `__asm__` (outside a function body) |
| | an empty statement (`__asm__ volatile("" ::: "memory")`, a scheduling barrier) |
| | asm labels: register pins (`register int x asm("$16")`) and symbol aliases (`extern void f() __asm__("func_X")`) |

Each catalogue entry records it: `"inline_asm": true` when the source has
inline asm statements, absent otherwise. `build_common_c.py` refuses an entry
whose field disagrees with its source, so the field can't drift. The proof
file has `inline_asm` per function and `inline_asm_functions` /
`inline_asm_bytes` in total, and the summary line reports them separately:

    MATCH common C: 3155 functions, 507568 source bytes (74 functions, 22144 bytes with inline asm); zero masks, canonical owners

`tools/link_common_sources.py` links these sources into Veldin like any other
(the build compiles them with the catalogue's flags, exactly as the gates did).

### The single-statement VU0 form

Write each contiguous VU0 sequence as **one** `__asm__ __volatile__`
statement, in retail's order, with retail's `$vf` registers and `nop`s:

```c
void func_0040BE30(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vmini.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "memory");
}
```

gcc treats a volatile statement as one unit, so its scheduler can't
interleave other code into the sequence, and no `do {} while (0)` barriers or
empty asm statements are needed around it (God Hand removed 40 such barriers
in 25 functions this way with every function still byte-identical). One
statement per instruction lets the scheduler move ordinary instructions
between them; use that, the [j-form](wiki/Matching-Patterns.md#vu0-j-form-one-asm-statement-per-instruction),
only where retail really interleaves (argument moves or `lq`/`sq` copies
between VU0 instructions). MMI instructions that produce an ordinary value
are a single statement with operands, `__asm__("plzcw %0, %1" : "=r"(n) : "r"(x));`.

The first 74 entries (all Veldin-owned, seeded from frontbin's matched C by
`python tools/seed_levels.py --inline-asm-only`) are VU0 leaves and VU0 code
inside C (`lqc2`/`vadd`/`vsub`/`sqc2`, `vcallms`), MMI (`plzcw`, `pextlh`,
`psraw`, `sq`), and a few FPU (`abs.s`, `sqrt.s`, `cvt`) and COP0/`sync.p`
statements carried over from their frontbin donors. Two further candidates
were refused because they call through an asm-label alias. 33 of the 74 are
linked into Veldin's build (`make check-veldin` MATCH), 20 of them VU0/MMI
functions of up to 600 bytes; the other 41 are followed by padding and stay
INCLUDE_ASM there, like other padded entries.

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

## Format of a source

Each source is `#include "common.h"`, then the function's own declarations and
the function between `/* localdecomp:start func_X */` and
`/* localdecomp:end func_X */` markers, like every other source in the repo
(level targets link these files directly, `docs/veldin.md`). The markers are
comments, so the gates don't see them.

A `$gp` reference must name an address within 16 bits of `$gp` (0x1DC8B0):
`check.resolve_relocations` treats anything further away as unresolved, since
the linker would reject it. Before that check, 13 sources passed with names
off by 0x70000 or so, because only the low 16 bits were compared.

## Trying one function

`tools/try_level.py` is the level counterpart of `try_func.py`. It runs the
gates for one source and, when the bytes differ, prints the compiled and
retail listings side by side:

    python tools/try_level.py src/levels/common/func_004D0538.c --flags-from func_003ABC30 --mode N --assembler default

An entry already in the catalogue needs no options. A new source needs none
either: `--flags-from` defaults to `func_003ABC30` (frontbin's plain base
flags), and without `--mode`/`--assembler` the first build uses the profile
read off the owner's retail bytes (below), then the `--flags-from` function's
own, then the two other combinations, stopping at the first match. An empty
function body shows the retail listing. On a match it prints the catalogue
entry to add.

## Reading the profile off retail

Every shared function was built in N or S address mode and assembled by GNU as
or Ps2EeAs (the catalogue's `mode` and `assembler`). `tools/asm_profile.py`
reads both off the retail bytes and lists the evidence (the marks are in
[Matching patterns](wiki/Matching-Patterns.md#reading-the-profile-off-retail)):

    python tools/asm_profile.py func_00495980                     (owner overlay, from C:\decomp-refs)
    python tools/asm_profile.py func_00495980 --overlay singleplayer/1_veldin
    python tools/asm_profile.py --evaluate --target common --verify

Against the 3081 catalogue entries (2026-10-21) it decides the mode for 1406
and agrees on 97.4% of them (98.6% counting the ones that pass the gates with
the guessed mode as well), and decides the assembler for 639, agreeing on
95.0% (98.4%). It cannot tell the mode of a function that reaches no global
in a mode-specific way; 89% of those pass the gates in either mode. Reading an
undecided assembler as the default one agrees with 94.2% of the catalogue.
`try_level.py` and `seed_levels.py` use it for their first build.

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
   assembly except inline asm statements inside it ([Inline assembly](#inline-assembly)),
   and its catalogue entry's `inline_asm` field says whether it has them. The
   compiler creates no unexpected data sections.
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
