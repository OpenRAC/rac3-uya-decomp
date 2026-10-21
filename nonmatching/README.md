# Near misses

C that compiles close to a function but not to its bytes: a starting point, never linked and
never counted. Keep one file per function, `nonmatching/<program>/func_XXXXXXXX.c`
(`<program>` is `frontbin`, `boot_elf` or `i5bootn`), with a comment at its top giving the
flags it was tried with and what still differs. Move it into `src/` once the full build prints
`MATCH` with it in place.

This is also where step 6 of the flag migration (AGENTS.md, "Compiler flags") leaves the drafts
of functions that go back to `INCLUDE_ASM` because they matched only with flags of their own.

| Function | Program | Size | What differs |
| --- | --- | ---: | --- |
| func_0011B018 | boot_elf | 0x48 | newlib `isinf`: byte-identical with Sony's ee-gcc 2.96-ee-001003-1 `-O2 -G0` (Linux build), which the Windows build can't run yet |
| func_0011B060 | boot_elf | 0x3C | newlib `isnan`: the same, byte-identical with 2.96 |
| func_00123B10 | boot_elf | 0x88 | 3 instructions (@ee29): the register of the last global's address and the order of `move $v0, $zero` |
| func_00125CB8 | boot_elf | 0x5C | 5 instructions (@ee29): retail has a second `ld $ra` before the join of the epilogue |
| func_0013ACC8 | boot_elf | 0x8C | 4 instructions (@ee29): $v0/$v1 and the operand order of one `addu` |
| func_0013CB20 | boot_elf | 0xDC | 2 instructions (SN without -fopt-stack, with sq_ra_funcs.txt): one `andi` and one `or` swapped |
