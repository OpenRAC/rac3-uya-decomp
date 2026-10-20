# Third-party notices

The repository is split-licensed ([LICENSE](LICENSE)). The following parts keep their own
licence.

## GCC runtime library (libgcc)

`src/libgcc/` (except its README.md), `src/i5bootn/libgcc/` and `src/boot_elf/core/libgcc/` hold
source from GCC 2.95.2's libgcc, copyright the Free Software Foundation, Inc., under the GNU
General Public License version 2 or later with the libgcc runtime exception, as each file's header
states.

## Patches to other projects

`tools/decomp-permuter-aligned-scorer.patch` and `tools/decomp-permuter-asm-passes.patch` are
changes to [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (Simon Lindholm),
applied to a separate checkout of it; they are offered under decomp-permuter's own licence.

## Tools used, not redistributed

splat, spimdisasm, rabbitizer, objdiff, asm-differ, pyelftools, Capstone, NumPy and wibo are
installed or downloaded separately under their own licences (`tools/requirements.txt`,
docs/wiki/Setup.md). The SN Systems and Sony compilers are proprietary and are never included.
docs/wiki/Credits.md thanks everyone whose work this project builds on.
