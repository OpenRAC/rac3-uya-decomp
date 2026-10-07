# libgcc

The executables link GCC's runtime library, `libgcc.a`, from Sony's prebuilt
copy. Those functions were not written for the game: they are GCC's own
source, built by Sony's ee-gcc **2.9-ee-991111**, so they are rebuilt from
GCC's source with that compiler instead of being decompiled
(`docs/compiler_matrix_i5bootn.md` has the evidence).

- **License.** Everything in this folder except this README is GCC source
  (GCC 2.95.2: `gcc/libgcc2.c`, `gcc/longlong.h`, `gcc/gbl-ctors.h`,
  `gcc/config/fp-bit.c`, `gcc/gthr.h`, `gcc/gthr-single.h`,
  `gcc/eh-common.h`, `gcc/frame.h`, `gcc/dwarf2.h`; `frame.c` is in its
  module file), under the GNU GPL version 2 or later with the
  libgcc runtime exception, as each file's header says, and so are the
  module files that use it (`src/i5bootn/libgcc/`,
  `src/boot_elf/core/libgcc/`). That is compatible
  with this repository's GPLv3.
- **Shared parts as headers.** `libgcc2.h` is the opening part of
  `libgcc2.c` (types, `longlong.h`, `__negdi2`, `__udivmoddi4`) and
  `fp-bit.h` the opening part of `fp-bit.c` (everything before `pack_d`).
  The text is GCC's; changes are marked `decomp:`.
- **Module files** live with each target's sources (`src/i5bootn/libgcc/`,
  `src/boot_elf/core/libgcc/`):
  one file per libgcc.a member, because each member is its own object in
  retail (the gaps between them are object alignment), listed in the
  target's `src_files.txt`. A module file defines its `L_<module>` macro
  (or `FLOAT` and the options Sony built fp-bit.c with) and includes one
  of the headers; its blocks hold that module's functions with GCC's text,
  under the repo's `func_XXXXXXXX` names (the GCC name is in a comment).
  For fp-bit.c it sets `FP_NAME_<name>` for the names the functions call
  each other by (`pack_d`, `unpack_d`, ...), so the calls reach the
  `func_` names.
- **Compiler.** The target's `text_parts.txt` marks the range
  `@ee29 -O2 -G0`: `tools/build_text.py` and the matching tools compile it
  with the 2.9-ee driver (`tools/ee29.py`), then assemble it with the
  project's assembler, without `asm_filter.py`.
- **Storage** that retail keeps in its data segments is named instead of
  defined: each libgcc2 module's static `__clz_tab` copy (`.rodata`),
  `__main`'s `initialized` and fp-bit's `nan()` object (`.bss`). The code
  that uses them is the same. `unpack_d` has Sony's no-denormals test
  (`NO_DENORMALS`, as in later GCC).
- **Dead-stripped functions.** Retail's linker removed the functions
  nothing calls, minus their last word (the `LINKER_REMNANT` lines). Those
  are left out of the C.
- **Libcalls.** The compiler calls the soft-float and 64-bit helpers by
  their GCC names (`dpadd`, `__muldi3`, ...); the target's
  `symbol_addrs_resolved.txt` gives those names their retail addresses.

## i5bootn (`src/i5bootn/libgcc/`)

`_main.c` (L__main), `_divdi3.c`, `_fixunsdfdi.c`, `_floatdidf.c`,
`_moddi3.c`, `_udivdi3.c`, `_umoddi3.c`, `dp-bit.c`, `fp-bit.c`,
`_muldi3.c`. Dead-stripped: `__do_global_dtors` (end of `func_008025F0`),
`dptoli` (`func_00804C00`), `__negdf2` (nothing left) and most of fp-bit.o
(`func_00804ED0`, `func_00804EF8`). `__moddi3`, `__udivdi3` and
`__umoddi3` stay assembly: they reserve stack that only Sony's Linux
2.9-ee-991111-01 reproduces, not the Windows 2.9-ee-991111 the build uses.

## boot_elf (`src/boot_elf/core/libgcc/`)

0x126020-0x12A948: `_main.c`, `_divdi3.c`, `_eh.c` (libgcc2.c's `L_eh`),
`_fixunsdfdi.c`, `_floatdidf.c`, `_moddi3.c`, `_muldi3.c`, `_pure.c`
(`__pure_virtual`), `_udivdi3.c`, `_umoddi3.c`, `dp-bit.c` (with `dptoli`,
which boot_elf keeps), `fp-bit.c` (with `fptoui`), `frame.c` (GCC's
`frame.c`; its `__register_frame*` functions were dead-stripped). The EH
code needs a few of the EE port's tm.h facts (`FIRST_PSEUDO_REGISTER` 79
sizes `frame_state` as retail has it); the module files define them. The linker filled module gaps with `0xCDCDCDCD`: those words are
`INCLUDE_ASM` pieces at the end of the module before them. Dead-stripped:
`__do_global_dtors` (`func_00126018`, in 124988.c), `__negdf2`, and most of
fp-bit.o (`func_00129920`). `_eh.c` is compiled with `-fexceptions` (its
own `text_parts.txt` line), as GCC's build compiles `L_eh`; without it the
2.9-ee turns some calls into sibling calls retail doesn't have. Still
assembly: `__moddi3`, `__udivdi3` and `__umoddi3` (as in i5bootn),
`_eh.o`'s `copy_reg`, `throw_helper`, `__throw`, `__rethrow`, and
`frame.o`'s `execute_cfa_insn` (switch table in `.rdata`).
