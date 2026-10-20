# Distribution and source scope

This repository holds authored C, tools, build files and tables (names, addresses, sizes and
compiler flags, never bytes) for Ratchet & Clank: Up Your Arsenal, NTSC-U (`SCUS-97353`).

The retail programs (`frontbin.elf`, `boot_elf.elf`, `i5bootn.elf`), level overlays, disc images,
the assembly that `tools/setup_asm.py` generates from them (`asm/`), build output and other game
data are never committed: every contributor supplies their own disc. The SN Systems and Sony
toolchains are proprietary and stay outside the repository too.
`python3 tests/check_repository.py` (run by CI) rejects tracked game data.

The decompiled game code in `src/` is a derivative of the original game: no copyright is claimed
over it and it is not licensed. The project's own tooling, build files, tables and documentation
are GPL-3.0. [LICENSE](LICENSE) has the exact terms, and
[THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) lists the code that keeps its own licence.

Only permitted sources are used: the retail programs of a disc you own, SDK library binaries,
open-source code under its licence and public projects about these games. Never Sony SDK source,
samples or headers, and never leaked or NDA material.
