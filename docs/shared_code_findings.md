# Shared code between executables and overlays

How much of `boot_elf.elf`, `i5bootn.elf`, `ntgui.elf`, `sly2.elf` and the level overlays is the same code as `frontbin.elf`, or as each other. This tells us where a match in one place counts for another, and which executables are mostly unique work.

## Method

Functions were taken from the generated reference objects (`C:\decomp-refs\exe-targets\*.o`, `C:\decomp-refs\level-targets\*.o`) and from `frontbin.elf` (function boundaries from the `func_XXXXXXXX` names in `src/text.c` and `asm/`, since the ELF has no function symbols). Each function's words were hashed with the 26-bit target of every `j`/`jal` masked, so shared code at different addresses still compares equal.

This is a **lower bound**. A shared function that differs in a `lui`/`addiu` address pair (a global at a different address) is not counted. Very small functions can match by coincidence, so check the large ones before relying on a count.

## Results

| Executable | Functions | Same as a frontbin function | Same as a function in some overlay |
|---|---|---|---|
| `boot_elf.elf` | 1,582 (458 KB) | 644 (138 KB, about 30%) | 476 (58 KB) |
| `i5bootn.elf` | 189 (20 KB) | 2 (752 B) | 2 |
| `ntgui.elf` | 4,580 (940 KB) | 0 | 142 (5 KB) |
| `sly2.elf` | 6,342 (1.4 MB) | 0 | 30 (under 1 KB) |

- Only 267 of about 10,700 distinct executable functions occur in more than one of the four executables, so they hardly overlap each other.
- The 51 overlays hold 100 MB of function bytes but only 9.3 MB distinct (this is what `tools/split_shared_levels.py` collapses into `common.o`). Only 217 of those distinct functions (31 KB) also appear in frontbin.

## What it means

- **`sly2.elf` and `ntgui.elf` are essentially unique code** (1.4 MB and 940 KB). Nothing we match in frontbin helps them.
- **`boot_elf.elf` is the exception.** About 644 of its functions are byte-identical to frontbin functions, probably shared SDK/engine code. Matching them in frontbin should carry over to `boot_elf` once the same C is built there.
- `i5bootn.elf` is tiny and almost entirely its own.
- Overlays already share heavily with each other; matching a function that lives in `common.o` counts once for all of them.

## Not done yet

- No list of the 644 `boot_elf`/frontbin pairs, and no check of how many are already in C on the frontbin side.
- No comparison with the address operands unmasked-aware (relocation-aware) matching, which would raise the shared counts.
