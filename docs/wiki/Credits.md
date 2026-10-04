# Credits

This project stands on other people's work. Thank you to everyone below. Nothing listed here is redistributed by this repo: each tool is installed or downloaded separately under its own license, and the game itself is never included.

If you think something or someone is missing, or you'd like your entry changed or removed, open an issue or a pull request.

## Contributors

- **vetusmagnus**: project lead, toolchain identification, build system, localdecomp, most of the matched C.
- **Louis-Philippe Le Sieur ([llesieur99](https://github.com/llesieur99))**: matched functions, the common-level C and its verified build (`tools/build_common_c.py`), the cross-repository research, tool fixes (`try_func.py`, `triage.py`, `pr_check.py`) and many of the patterns in [Matching patterns](Matching-Patterns).

## The game

*Ratchet & Clank: Up Your Arsenal* was developed by **Insomniac Games** and published by **Sony Computer Entertainment** (2004). This is an unofficial fan project, not affiliated with or endorsed by Insomniac Games or Sony Interactive Entertainment. *Ratchet & Clank* is a trademark of Sony Interactive Entertainment LLC. You need your own copy of the game to build anything here.

## Toolchain

- **SN Systems ProDG for PlayStation 2** (ee-gcc 2.95.3 v1.36, Ps2EeAs): the compiler and assemblers retail was built with. Preserved by [AngheloAlf/SN-Systems-ProDG_for_PS2_3.01](https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01).
- **[decompme/compilers](https://github.com/decompme/compilers)**: the PS2 GCC builds (Sony 2.9 to 3.2) used to identify the compiler ([compiler matrix findings](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/compiler_matrix_findings.md)).
- **[wibo](https://github.com/decompals/wibo)** (decompals): runs the Windows toolchain on Linux and macOS.
- **GNU Binutils** (`binutils-mips-linux-gnu`): disassembly and the level reference objects.

## Decompilation tools

- **[splat](https://github.com/ethteck/splat)** (Ethan Roseman and contributors): splits `frontbin.elf` into assembly and data.
- **[spimdisasm](https://github.com/Decompollaborate/spimdisasm)** and **[rabbitizer](https://github.com/Decompollaborate/rabbitizer)** (Decompollaborate, Anghelo Carvajal): the MIPS/R5900 disassembly behind splat and several of our tools.
- **[objdiff](https://github.com/encounter/objdiff)** (Luke Street): per-file diffs and the progress report.
- **[decomp.dev](https://decomp.dev)** (Luke Street): hosts the progress page.
- **[decomp-permuter](https://github.com/simonlindholm/decomp-permuter)** (Simon Lindholm): finds the C rewrites behind register and scheduling near misses.
- **[asm-differ](https://github.com/simonlindholm/asm-differ)** (Simon Lindholm): the assembly diff used by localdecomp.
- **[m2c](https://github.com/matt-kempster/m2c)** (Matt Kempster and contributors): first drafts of C from assembly.
- **[decomp.me](https://decomp.me)**: the collaborative matching site that localdecomp is modelled on.

## Python libraries

- **[pyelftools](https://github.com/eliben/pyelftools)** (Eli Bendersky): ELF reading in nearly every tool.
- **[Capstone](https://github.com/capstone-engine/capstone)**: disassembly in `try_func.py` and `pr_check.py`.
- **[NumPy](https://numpy.org)**: the level and executable reference-object generators.

## Game files

- **[Wrench](https://github.com/chaoticgd/wrench)** (chaoticgd): unpacks the game ISO to get `frontbin.elf`, the levels and the other executables.

## Related projects

Research in [Cross-repository resources](Cross-Repository-Resources) compared functions with these decompilations (MIT licensed at the pinned snapshots; no code was copied into this repo):

- **Ratchet & Clank** decompilation: [Lynder063/rac1-decomp](https://github.com/Lynder063/rac1-decomp) (Kryštof "Lynder063" Malinda) and [Veradictus/rac1-decomp](https://github.com/Veradictus/rac1-decomp).
- **Ratchet & Clank: Going Commando** decompilation: [llesieur99/rac2-decomp](https://github.com/llesieur99/rac2-decomp).
- **[Lombyte](https://github.com/mateuszklysz/Lombyte)** (mateuszklysz).
