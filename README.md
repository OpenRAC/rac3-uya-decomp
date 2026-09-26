# Ratchet & Clank: Up Your Arsenal decompilation

A matching C decompilation of `frontbin.elf` from *Ratchet & Clank: Up Your Arsenal* (PS2, NTSC-U, SCUS-97353). The build produces a file byte-for-byte identical to retail (SHA-1 `3bc94ee895e4b4af9b5602a229af599c1103b542`).

This repo contains no game code or assets. To build it you need your own copy of the game.

## Status

About 690 of 1,846 functions in `.text` are C. The rest are still included as assembly. `python tools/pr_check.py` prints the current count.

## Quick start (Windows)

1. Install SN Systems ee-gcc 2.95.3 v1.36 to `C:\tools\eegcc_2.95.3_sn_v1.36`.
2. Put your own `frontbin.elf` in the repo root.
3. `pip install -r tools/requirements.txt`
4. `& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"`. The last line should be `MATCH: ...`.

Linux and macOS: `python3 tools/build.py --toolchain <dir> --runner <wibo>`.

## Contributing

Start with the [wiki](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki):

- [Setup](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Setup)
- [Workflow](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Workflow)
- [Matching patterns](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Matching-Patterns)
- [Pull requests](https://github.com/vetusmagnus/ratchet-uya-decomp/wiki/Pull-Requests)

The wiki sources live in [`docs/wiki/`](docs/wiki). The compiler research is in [`docs/compiler_matrix_findings.md`](docs/compiler_matrix_findings.md).

## Tools

| Tool | Purpose |
|---|---|
| `localdecomp/server.py` | Local web editor: build one function with its real flags and diff against retail |
| `tools/try_func.py` | The same compile and diff from the command line (Windows, or Linux via wibo) |
| `tools/pr_check.py` | Catches the usual full-build failures before a PR |
| `tools/build.py` | The Makefile's build for Linux and macOS |
| `tools/build_text.py` | Builds `src/text.c` in address ranges with per-range flags (`tools/text_parts.txt`) |
| `tools/check_match.py` | Compares the built binary with retail |
