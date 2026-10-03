# Trailing padding after functions

gcc starts every function with `.align 3`, so a C function is followed by at most one alignment nop. 17 retail functions are followed by more zero words than that (probably bodies of functions the original linker stripped). Splat keeps those words after the `endlabel` of the function's `.s`, so they build fine as `INCLUDE_ASM` but disappear when the function becomes C, and every address after it moves.

`TEXT_PADDING(N)` in `include/include_asm.h` emits N zero words after the preceding function. It already follows each affected function in its source file, and the extra nops were removed from their `.s` files, so the build is unchanged and converting the function to C needs no extra step: leave the `TEXT_PADDING` line where it is.

`python tools/trailing_padding.py` lists functions that still need it; `--apply` inserts the line and trims the `.s`. `tools/build_text.py` keeps a `TEXT_PADDING` line in the same part as the function just before it.
