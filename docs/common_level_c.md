# Common-level C: first verified source and opt-in build

`src/levels/common/func_004D0538.c` is a C implementation of the canonical
Veldin function at `0x004D0538`, 304 bytes. Its source is adapted from this
project's existing `func_003ABC30`, not from a retail instruction listing.
The compiler settings come from that donor's range in `tools/text_parts.txt`.

The first catalogue entry uses the existing SN compiler, N/default settings,
and no inline assembly. The eight calls refer to the singleplayer executable's
`0x0011A0B0`; this does not claim that a multiplayer address is an equivalent
callee. Other placements and normalized hashes are only search candidates.

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
