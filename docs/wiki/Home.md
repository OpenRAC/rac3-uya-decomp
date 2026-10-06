# Ratchet & Clank: Up Your Arsenal decompilation

A matching C decompilation of `frontbin.elf` from *Ratchet & Clank: Up Your Arsenal* (PS2, NTSC-U, SCUS-97353). "Matching" means the C in this repo compiles and links to a file that is byte-for-byte identical to the retail one. Every pull request has to keep it that way.

## Where things stand

- `src/frontbin/*.c` hold every function in the `.text` section, one file per original source file (`tools/src_files.txt`, see [docs/source_files.md](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/source_files.md)). Functions that are done are C. The rest are `INCLUDE_ASM(...)` stubs that pull in the retail assembly from `asm/nonmatchings/text/`.
- As of 2026-10-06, 1,582 of the 1,867 functions are final source: 1201 in C, plus 156 hand-written assembly functions (`ASM_FUNC`) and 225 linker remnants (`LINKER_REMNANT`). Run `python tools/pr_check.py` for the current count.
- Until 2026-10-03 all of this was one file, `src/text.c`. Anything that still refers to it (an old branch, an old note) predates the split; see [docs/source_files.md](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/source_files.md) for how to carry it over.
- The toolchain is fully identified: SN Systems ee-gcc 2.95.3 v1.36, plus the right assembler per function. See [Toolchain and build](Toolchain-and-Build).
- The level overlays are tracked for progress. Work on their shared code has started with a few verified functions in `src/levels/common/`, built by an opt-in tool ([docs/common_level_c.md](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/common_level_c.md)); it is not part of `make`.

## Pages

| Page | What it covers |
|---|---|
| [Setup](Setup) | Toolchain, Python, your own copy of the game file, first build |
| [Workflow](Workflow) | Picking a function, matching it in localdecomp or on the command line, putting it into its source file |
| [Matching patterns](Matching-Patterns) | The rules and tricks that make this compiler produce retail code |
| [Cross-repository resources](Cross-Repository-Resources) | Pinned RAC1, RAC2 and Lombyte references, ABI evidence, and limits of cross-game matching |
| [Tools](Tools) | Every script in `tools/`, localdecomp and the Makefile: what each is for and when to use it |
| [Toolchain and build](Toolchain-and-Build) | How the build works: `text_parts.txt`, assemblers, symbol files, objdiff |
| [Pull requests](Pull-Requests) | What a PR must contain and the checklist a reviewer uses |
| [Credits](Credits) | The people, tools and projects this decomp relies on |

## Ground rules

1. **Never commit retail files.** Not `frontbin.elf`, not level overlays, not objects generated from them, not disc images. They are copyrighted. You supply your own copy locally; `.gitignore` already covers the usual names.
2. **The full build must print `MATCH`.** A function that only matches in localdecomp is not done until `make` matches too.
3. **Declare, never define, variables in the source files.** Retail data lives in the data segments. Details in [Matching patterns](Matching-Patterns#never-define-variables).
4. **Plain C first.** Inline `__asm__` and `$gp` register hacks produce the right bytes but aren't the original source. Use them only when documented as the only option, and say so in the PR.
