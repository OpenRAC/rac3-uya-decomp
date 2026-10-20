# Ratchet & Clank: Up Your Arsenal decompilation

A matching C decompilation of `frontbin.elf`, `boot_elf.elf` and `i5bootn.elf` from *Ratchet & Clank: Up Your Arsenal* (PS2, NTSC-U, SCUS-97353). The build produces files byte-for-byte identical to retail (SHA-1 `3bc94ee895e4b4af9b5602a229af599c1103b542` for frontbin, `487975305f8a263c750dfede50391b575ed07835` for boot_elf, `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f` for i5bootn). [`docs/targets.md`](docs/targets.md) lists the three and how the tools handle them.

This repo contains no game code or assets. To build it you need your own copy of the game.

## Status

Final source per program, counted from `src/` (`python3 tools/progress.py --readme` refreshes this table; the full build proves every entry byte-identical):

<!-- progress:begin (tools/progress.py --readme) -->
| Program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| frontbin | 1867 | 1836 (98.3%) | 1455 | 156 | 225 | 31 |
| boot_elf | 2791 | 2503 (89.7%) | 1818 | 358 | 327 | 288 |
| i5bootn | 199 | 198 (99.5%) | 42 | 147 | 9 | 1 |
<!-- progress:end -->

objdiff's whole-game report, levels included, is [`progress/report.json`](progress/report.json) (`python3 tools/progress.py --check`).

Status on 2026-10-07 (`python3 tools/progress.py` prints the current counts): frontbin 1795 of 1867 functions are final source (1414 in C, the rest confirmed hand-written assembly or linker remnants), boot_elf 2165 of 2815 (1479 in C), i5bootn 157 of 199 (2 in C). All three build byte-identical. objdiff's progress report has the whole-game numbers.

boot_elf (the main executable: the engine core and a second copy of the front end) is split the same way, in `src/boot_elf/core/` and `src/boot_elf/text/`, and its front end was seeded from frontbin's C; see [`docs/boot_elf.md`](docs/boot_elf.md). `python tools/pr_check.py --target boot_elf` prints its count.

i5bootn (the bootstrap launcher the disc starts first) is in `src/i5bootn/`; see [`docs/i5bootn.md`](docs/i5bootn.md). Most of its compiled code is Sony library code built with another compiler (Sony ee-gcc 2.9-ee-991111; see [`docs/compiler_matrix_i5bootn.md`](docs/compiler_matrix_i5bootn.md)), so only its own two C functions are matched so far. `python tools/pr_check.py --target all` prints every target's count.

frontbin's code is in `src/frontbin/`, one C file per original source file (see [`docs/source_files.md`](docs/source_files.md)). Until 2026-10-03 it was a single `src/text.c`; branches or notes that mention that file are older than the split.

**Cloned before 2026-10-20?** The repository was rearranged like rac1-decomp and rac2-decomp: your ELFs go in `baserom/` (`mkdir baserom && mv *.elf baserom/`), each program's tables are in `config/<program>/` (they were in `tools/`, `targets/<program>/` and the root), the splat configs in `config/splat/`, localdecomp in `tools/localdecomp/`. Rerun `python tools/setup_asm.py --target all` and rebase open branches; git follows the moved files.

**Cloned before 2026-10-03?** The history of `main` was rewritten that day (commit messages only, no code). Run `git fetch` and `git reset --hard origin/main` on a clean `main`, or clone again, before starting new work. Rebase any open branch onto the new `main`.

## Quick start (Windows)

1. Install SN Systems ee-gcc 2.95.3 v1.36 to `C:\tools\eegcc_2.95.3_sn_v1.36`.
2. Put your own `frontbin.elf`, `boot_elf.elf` and `i5bootn.elf` (from the disc) in `baserom/`.
3. `pip install -r tools/requirements.txt` (this includes splat)
4. `python tools/setup_asm.py --target all`. This generates `asm/` from your `frontbin.elf`, `asm/boot_elf/` from `boot_elf.elf` and `asm/i5bootn/` from `i5bootn.elf` (all gitignored, so a fresh clone has none; without them `make` stops with "No rule to make target `asm/header.s'"). It takes a few minutes.
5. `& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"`. It ends with one `MATCH: ...` line per executable.

Linux and macOS: `python3 tools/setup_asm.py --target all`, then `python3 tools/build.py --target all --toolchain <dir> --runner <wibo>`.

Every tool works on frontbin unless you pass `--target boot_elf` / `--target i5bootn` (or set `UYA_TARGET`); several also take `--target all`. See [`docs/targets.md`](docs/targets.md).

## Contributing

Start with the [wiki](https://github.com/OpenRAC/rac3-uya-decomp/wiki):

- [Setup](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Setup)
- [Workflow](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Workflow)
- [Matching patterns](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Matching-Patterns)
- [Pull requests](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Pull-Requests)
- [Credits](https://github.com/OpenRAC/rac3-uya-decomp/wiki/Credits)

The wiki sources live in [`docs/wiki/`](docs/wiki). The compiler research is in [`docs/compiler_matrix_findings.md`](docs/compiler_matrix_findings.md), and the plan to 100% is in [`docs/full_match_roadmap.md`](docs/full_match_roadmap.md).

## Tools

| Tool | Purpose |
|---|---|
| `tools/localdecomp/server.py` | Local web editor: build one function with its real flags and diff against retail; its Permuter panel runs decomp-permuter on the editor's code with live progress ([docs/permuter.md](docs/permuter.md)) |
| `tools/permuter_engine.py` | The permuter search from the command line (Windows or Linux), with the fence and barrier passes |
| `tools/fence_search.py` | Tries every empty register fence, volatile barrier, `do { } while (0)` wrap and statement swap (and pairs) on a near miss |
| `tools/sched_explain.py` | Shows why gcc's scheduler ordered two instructions the way it did (priority, register weight, ...) |
| `tools/flags_probe.py` | Finds the mode and assembler a near miss wants and records them in `config/frontbin/localdecomp_flags.txt` |
| `tools/check.py` | The same compile and diff from the command line (Windows, or Linux via wibo); formerly `tools/try_func.py`, which still works |
| `tools/build_common_c.py` | Opt-in common-level C build with canonical ownership and strict retail-byte gates; see [common-level C](docs/common_level_c.md) |
| `tests/check_repository.py` | The pre-commit check: every program's source checks, the tables, and that no game data is tracked (CI runs it with the unit tests) |
| `tools/pr_check.py` | One program's source checks, plus compiling every file and slice: the usual full-build failures before a PR |
| `tools/progress.py` | Counts per program, the README table, and `progress/report.json` (objdiff's report) |
| `tools/build.py` | The Makefile's build for Linux and macOS |
| `tools/todo.py` | Sorts the remaining functions into buckets (plain, switch, vu0, handwritten, remnant, ...); formerly `tools/triage.py`, which still works |
| `tools/build_text.py` | Builds `src/frontbin/*.c`, one object per source file, with per-function flags (`config/frontbin/text_parts.txt`) |
| `tools/split_text.py` | Keeps each source file's declarations from other files up to date (`--refresh`) |
| `tools/check_match.py` | Compares the built binary with retail |
| `tools/targets.py` | The executables the repo builds (frontbin, boot_elf, i5bootn) and where each one's files live |
| `tools/bootstrap_target.py` | Makes a new target's source tree from its ELF (how i5bootn was set up) |
| `tools/elf2bin.py` | `objcopy -O binary` in Python (i5bootn's flat binary; SN's objcopy corrupts it) |
| `tools/seed_boot_elf.py` | Copies frontbin's matched C into boot_elf's front end; rerun it when frontbin gains matches |

## Layout

```
AGENTS.md, CLAUDE.md     instructions for AI agents
LEGAL.md, LICENSE        what is distributed; THIRD_PARTY_NOTICES.md
baserom/                 your own frontbin.elf, boot_elf.elf, i5bootn.elf (never committed)
config/<program>/        each program's tables: src_files, text_parts (flags), symbols, ...
config/splat/            splat's configuration per program
config/levels/           the shared level code's catalogue and tables
src/<program>/           the C, one file per original source file
include/, linker_scripts/
nonmatching/             near misses, never linked
progress/report.json     objdiff's progress report
tools/                   build, checks, setup; tools/localdecomp/, tools/objdiff/
tests/                   repository check and unit tests (CI)
docs/, docs/wiki/        research notes; the wiki's source
asm/, build/             generated locally, never committed
```

AI agents: read [AGENTS.md](AGENTS.md) first.

## License

The repository is split-licensed; [`LICENSE`](LICENSE) has the exact terms. The project's own tooling, build files, tables and documentation are GPL-3.0. The decompiled game code in `src/` is a derivative of the original game (copyright Sony Interactive Entertainment LLC): no copyright is claimed over it and it is not licensed; it is provided for educational, preservation and research purposes. The GCC runtime library source in the `libgcc/` folders keeps its own license (GPL-2.0-or-later with the libgcc runtime exception).
