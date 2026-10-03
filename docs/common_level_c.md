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

Together these twenty-four sources cover 4784 owned function bytes. The float function
is still plain C: selecting the existing Ps2EeAs assembler is not inline ASM.
Every source passes the same complete-size and raw/resolved-byte gates.

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

For an opt-in local objdiff configuration, set the `levels/common` unit's
`base_path` to the generated `build/objdiff/base/common.o` only after the gates
pass. Keep every other unit and the full-game denominator unchanged. The
main configuration and existing CI remain untouched until personal level
inputs are provisioned there; this source does not silently promise a CI
progress increase.

Count the owned function once, not once per overlay or per identical alias.
Handwritten ASM, linker remnants, data and alignment bytes are not C gains.
Objdiff percentages alone do not prove the full-function relocation checks.
This is source/byte verification, not a playable-level build or gameplay test.
