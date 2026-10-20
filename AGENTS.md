# Instructions for agents

This file is for AI agents (Claude, Codex or others) working in this repository. Read it
completely before changing anything; then read README.md, CONTRIBUTING.md and the wiki pages in
`docs/wiki/` (Setup, Workflow, Matching-Patterns, Pull-Requests). The repository follows the same
structure as rac1-decomp and rac2-decomp, the other OpenRAC decompilations: keep it that way.

## What this repository is

A matching decompilation of Ratchet & Clank: Up Your Arsenal (PS2, NTSC-U, `SCUS-97353`): three
programs from the disc, rebuilt from C and assembly until every byte equals retail.

| Program | What it is | SHA-1 of the retail file |
| --- | --- | --- |
| `frontbin` | the front end (menus) | `3bc94ee895e4b4af9b5602a229af599c1103b542` |
| `boot_elf` | the engine core plus a second copy of the front end | `487975305f8a263c750dfede50391b575ed07835` |
| `i5bootn` | the bootstrap launcher the disc starts first | `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f` |

`tools/targets.py` names every program's files; every tool reads its paths there and takes
`--target frontbin|boot_elf|i5bootn` (or `all` where it makes sense).

| Path | What it is | Who writes it |
| --- | --- | --- |
| `src/<program>/` | one C file per original source file: C, or `INCLUDE_ASM` markers | you (C replacing markers) |
| `src/levels/common/` | shared level code, opt-in and checked separately (docs/common_level_c.md) | you |
| `tools/src_files.txt`, `targets/<program>/src_files.txt` | each program's source files and their start addresses | by hand, rarely |
| `tools/text_parts.txt`, `targets/<program>/text_parts.txt` | compiler flags by address range (see "Compiler flags") | by hand |
| `symbol_addrs*.txt`, `targets/<program>/symbol_addrs*.txt` | symbol names and addresses | by hand / `tools/reconcile.py` |
| `include/`, `linker_scripts/` | headers, assembler macros, the hand-kept linker scripts | by hand |
| `nonmatching/` | near misses, never linked (`nonmatching/README.md`) | you |
| `progress_report.json`, `objdiff.json` | objdiff's progress report and its units | the CI and `tools/gen_objdiff_units.py` |
| `tools/`, `localdecomp/` | build, checks, the local matching editor | by hand |
| `docs/`, `docs/wiki/` | research notes; the wiki's source | by hand |
| the retail ELFs, `asm/`, `build/` | game data, generated assembly, build output | never committed |

## How a function is matched

1. Pick a function with an `INCLUDE_ASM` marker (`python3 tools/triage.py` sorts what is left).
2. Write C for it in localdecomp or with `python3 tools/try_func.py func_XXXXXXXX` until it
   compiles to retail's bytes with its range's flags.
3. Replace the marker with the C, in place, in the file that owns its address, inside
   `/* localdecomp:start func_XXXXXXXX */ ... /* localdecomp:end func_XXXXXXXX */`.
4. `python3 tools/pr_check.py --target <program>`: the source checks (declarations, markers,
   extern-only globals, aliases, jump tables, compiles every file and slice).
5. The real check: the full build (`make` on Windows, `python3 tools/build.py --target all` on
   Linux and macOS) prints one `MATCH` line per program with the SHA-1s above. A function counts
   only when it links into a program that equals retail byte for byte.

If you get close but not exact, put your C in `nonmatching/<program>/func_XXXXXXXX.c` with a line
in `nonmatching/README.md` saying what still differs, and put the `INCLUDE_ASM` marker back.

## Compiler flags: per-function overrides are being migrated

rac1-decomp and rac2-decomp allow one flag set per real source file: a function that matches only
with flags of its own is not matched there (rac1-decomp's `docs/BUILD_FIDELITY.md`). This
repository does not meet that rule yet, and this is recorded here as it is:

- Flags are set **by address range** in `text_parts.txt`. `tools/build_text.py` compiles each run
  of equal flags inside a file as its own slice.
- Many matched functions have a **single-function override** (a range of one function with its
  own flags), and about 500 ranges pick another assembler for one function (`@ps2as`).
- Sony library code is compiled with Sony's ee-gcc 2.9-ee-991111 (`@ee29` ranges, about 175);
  Sony built it separately, so it will become files of its own.

The project owner decided to migrate to honest per-file flags (OpenRAC's `docs/TODO.md`,
section 2, step 6): library code into its own files, every other override matched again under its
file's flags or returned to `INCLUDE_ASM` with its draft in `nonmatching/`. Until that migration is
done, existing overrides stay as they are. **Do not change matched C or the flag tables as a side
effect of other work**, and if a new match needs a new single-function override, say so in its
pull request so the migration can count it.

## Matching rules

- **Plain C.** No inline assembly in functions, no register pins, no artificial barriers, where it
  can be avoided. Some existing matches use inline assembly or a `$gp` register hack; a pull
  request that adds one calls it out and justifies it (docs/wiki/Pull-Requests.md).
- **Globals are `extern`.** Never define a variable in `src/`: it creates data that breaks the
  layout.
- **Handwritten assembly** (`ASM_FUNC`) and linker remnants (`LINKER_REMNANT`) are final source,
  marked only on evidence (VU0 / COP2 code, instructions the compiler never emits), never because a
  function resisted matching.
- **A match is the full build saying `MATCH`.** Not a compiled object, not a masked comparison, not
  a model's claim. Report exactly what you ran and what it printed.

## When to stop on a function

OpenRAC's `docs/workflow/BACKFILL.md` has the measurements. In short: stop when it is not a
function (it reads registers it never sets or has no `jr $ra`), when it is handwritten, when three
different wordings compile to the same wrong bytes, or after about ten compiles without getting
closer. Leave the attempt in `nonmatching/` with what differs, and move on.

## Rules

- **Sources.** Use the retail programs of your own disc, SDK library *binaries*, open-source code
  under its licence, public decompilations and tools, and public hardware documentation. Never use
  Sony's SDK source, samples or headers, or leaked or NDA material, not even as a reference. If a
  function looks like SDK sample code, decode it from the assembly.
- **Never commit game data or proprietary tools**: the retail ELFs, level overlays, disc images,
  `asm/`, build output, the SN or Sony toolchains. They stay in ignored places; keep them so.
  `python3 tests/check_repository.py` checks this.
- **English** in everything that lands here: code, comments, commits, pull requests, `nonmatching/`
  notes.
- **Never delete what you did not create**, and leave other people's uncommitted work alone.
- **Never rewrite `main`'s history** and never force-push a shared branch.
- Before a commit: `python3 -m unittest discover -s tests` and `python3 tests/check_repository.py`
  (both need no game data; CI runs them), and for anything that affects the build, the full build
  with its three `MATCH` lines.

## Commits

- Conventional Commits with a scope: `feat(frontbin): match func_0039BEC0`,
  `fix(tools): ...`, `docs(wiki): ...`, `build: ...`, `chore: ...`.
- A body that says what changed, why, and what you verified (the commands and what they printed).
- No `Co-authored-by:` trailers for AI tools (docs/wiki/Pull-Requests.md).
- Small, coherent commits; matches and tool or doc changes in separate pull requests when large.
