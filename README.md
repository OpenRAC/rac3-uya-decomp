# Ratchet & Clank: Up Your Arsenal decompilation

A matching C decompilation of `frontbin.elf` and `boot_elf.elf` from *Ratchet & Clank: Up Your Arsenal* (PS2, NTSC-U, SCUS-97353). The build produces files byte-for-byte identical to retail (SHA-1 `3bc94ee895e4b4af9b5602a229af599c1103b542` for frontbin, `487975305f8a263c750dfede50391b575ed07835` for boot_elf).

This repo contains no game code or assets. To build it you need your own copy of the game.

## Status

1607 of 31316 functions (5.1%) are fully matched (2026-10-06). `python tools/pr_check.py` prints the current count for frontbin (the file being worked on). 1226 functions are matched fully in C with the rest matched being confirmed handwritten assembly as currently no known compiler or set of flags generates matching assembly.

boot_elf (the main executable: the engine core and a second copy of the front end) is split the same way, in `src/boot_elf/core/` and `src/boot_elf/text/`, and its front end was seeded from frontbin's C; see [`docs/boot_elf.md`](docs/boot_elf.md). `python tools/pr_check.py --target boot_elf` prints its count.

frontbin's code is in `src/frontbin/`, one C file per original source file (see [`docs/source_files.md`](docs/source_files.md)). Until 2026-10-03 it was a single `src/text.c`; branches or notes that mention that file are older than the split.

**Cloned before 2026-10-03?** The history of `main` was rewritten that day (commit messages only, no code). Run `git fetch` and `git reset --hard origin/main` on a clean `main`, or clone again, before starting new work. Rebase any open branch onto the new `main`.

## Quick start (Windows)

1. Install SN Systems ee-gcc 2.95.3 v1.36 to `C:\tools\eegcc_2.95.3_sn_v1.36`.
2. Put your own `frontbin.elf` and `boot_elf.elf` in the repo root.
3. `pip install -r tools/requirements.txt` (this includes splat)
4. `python tools/setup_asm.py`, then `python tools/setup_asm.py --target boot_elf`. These generate the `asm/` folder from your `frontbin.elf` and `asm/boot_elf/` from your `boot_elf.elf` (they are gitignored, so a fresh clone has none; without them `make` stops with "No rule to make target `asm/header.s'"). Each takes a few minutes.
5. `& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"`. The last two lines should be `MATCH: ...`, one per executable.

Linux and macOS: run both `setup_asm.py` commands with `python3`, then `python3 tools/build.py --toolchain <dir> --runner <wibo>` and the same with `--target boot_elf`.

Every tool works on frontbin unless you pass `--target boot_elf` (or set `UYA_TARGET=boot_elf`); the targets and their paths are listed in `tools/targets.py`.

## Contributing

Start with the [wiki](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki):

- [Setup](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Setup)
- [Workflow](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Workflow)
- [Matching patterns](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Matching-Patterns)
- [Pull requests](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Pull-Requests)
- [Credits](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Credits)

The wiki sources live in [`docs/wiki/`](docs/wiki). The compiler research is in [`docs/compiler_matrix_findings.md`](docs/compiler_matrix_findings.md), and the plan to 100% is in [`docs/full_match_roadmap.md`](docs/full_match_roadmap.md).

## Tools

| Tool | Purpose |
|---|---|
| `localdecomp/server.py` | Local web editor: build one function with its real flags and diff against retail |
| `tools/try_func.py` | The same compile and diff from the command line (Windows, or Linux via wibo) |
| `tools/build_common_c.py` | Opt-in common-level C build with canonical ownership and strict retail-byte gates; see [common-level C](docs/common_level_c.md) |
| `tools/pr_check.py` | Catches the usual full-build failures before a PR |
| `tools/build.py` | The Makefile's build for Linux and macOS |
| `tools/triage.py` | Sorts the remaining functions into buckets (plain, switch, vu0, handwritten, remnant, ...) |
| `tools/build_text.py` | Builds `src/frontbin/*.c`, one object per source file, with per-function flags (`tools/text_parts.txt`) |
| `tools/split_text.py` | Keeps each source file's declarations from other files up to date (`--refresh`) |
| `tools/check_match.py` | Compares the built binary with retail |
| `tools/targets.py` | The executables the repo builds (frontbin, boot_elf) and where each one's files live |
| `tools/seed_boot_elf.py` | Copies frontbin's matched C into boot_elf's front end; rerun it when frontbin gains matches |
