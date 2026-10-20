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
