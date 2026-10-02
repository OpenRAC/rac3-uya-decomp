# Ratchet & Clank: Up Your Arsenal decompilation

A matching C decompilation of `frontbin.elf` from *Ratchet & Clank: Up Your Arsenal* (PS2, NTSC-U, SCUS-97353). "Matching" means the C in this repo compiles and links to a file that is byte-for-byte identical to the retail one. Every pull request has to keep it that way.

## Where things stand

- `src/text.c` holds every function in the `.text` section. Functions that are done are C. The rest are `INCLUDE_ASM(...)` stubs that pull in the retail assembly from `asm/nonmatchings/text/`.
- As of 2026-10-02, 1,411 of the 1,867 functions are final source: 1037 in C, plus 149 hand-written assembly functions (`ASM_FUNC`) and 225 linker remnants (`LINKER_REMNANT`). Run `python tools/pr_check.py` for the current count.
- The toolchain is fully identified: SN Systems ee-gcc 2.95.3 v1.36, plus the right assembler per function. See [Toolchain and build](Toolchain-and-Build).
- The level overlays are tracked for progress only. Nobody is working on them yet.

## Pages

| Page | What it covers |
|---|---|
| [Setup](Setup) | Toolchain, Python, your own copy of the game file, first build |
| [Workflow](Workflow) | Picking a function, matching it in localdecomp or on the command line, putting it into `text.c` |
| [Matching patterns](Matching-Patterns) | The rules and tricks that make this compiler produce retail code |
| [Tools](Tools) | Every script in `tools/`, localdecomp and the Makefile: what each is for and when to use it |
| [Toolchain and build](Toolchain-and-Build) | How the build works: `text_parts.txt`, assemblers, symbol files, objdiff |
| [Pull requests](Pull-Requests) | What a PR must contain and the checklist a reviewer uses |

## Ground rules

1. **Never commit retail files.** Not `frontbin.elf`, not level overlays, not objects generated from them, not disc images. They are copyrighted. You supply your own copy locally; `.gitignore` already covers the usual names.
2. **The full build must print `MATCH`.** A function that only matches in localdecomp is not done until `make` matches too.
3. **Declare, never define, variables in `text.c`.** Retail data lives in the data segments. Details in [Matching patterns](Matching-Patterns#never-define-variables).
4. **Plain C first.** Inline `__asm__` and `$gp` register hacks produce the right bytes but aren't the original source. Use them only when documented as the only option, and say so in the PR.
