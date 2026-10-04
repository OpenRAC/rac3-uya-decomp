# Workflow

The loop for one function: pick it, read its assembly, write C until it matches, put it into its source file, and prove the full build still matches.

## 1. Pick a function

Every not-yet-decompiled function is an `INCLUDE_ASM("asm/nonmatchings/text", func_XXXXXXXX);` line in one of the source files in `src/frontbin/` (the one whose address range in `tools/src_files.txt` contains it), and its retail assembly is `asm/nonmatchings/text/func_XXXXXXXX.s`. The header line gives the size: `nonmatching func_0037D100, 0x20`.

`python tools/triage.py --tsv remaining.tsv` sorts every remaining function into a bucket (plain, switch, vu0, mmi, handwritten, remnant, ...) with its size. Pick from **plain**, smallest first, or from **switch** and **vu0** once you know those patterns.

Good first functions:

- Small ones (under about 0x100 bytes).
- Members of a family that is already matched: find a matched function with the same shape and copy its approach. Getters, setters, `isA` checks through a vtable, and the 8-slot hash lookups (`HT_8`) all come in families.

Not for C:

- **Already done, not C:** `ASM_FUNC(...)` lines in the source files are functions that were hand-written assembly in the original (their `.s` in `asm/handwritten/` is the source), and `LINKER_REMNANT(...)` lines are the leftover words of functions the original linker stripped (`asm/remnants/`). Both count as finished, including in objdiff. See [Matching patterns](Matching-Patterns#not-everything-is-c).
- **odd:** probably a bad split. Report it; don't write C for it yet.
- Functions listed in [Matching patterns: known open problems](Matching-Patterns#known-open-problems).

Tell others what you're working on (open a draft PR early) so two people don't match the same function.

## 2. Read the assembly

- The calling convention is EABI: integer args in `$a0-$a3, $t0-$t3` (`$4-$11`), float args in `$f12-$f19`, return in `$v0` or `$f0`.
- `$gp` is `0x1DC8B0`. An access like `lw $v0, -0x5b0c($gp)` is address `0x1DC8B0 - 0x5B0C = 0x1D6DA4`, so the symbol is `D_001D6DA4`.
- An access through `lui` + `%lo(...)` names its symbol directly (`%hi(D_00225980)`).
- **How each global is accessed matters as much as the code.** Before writing C, list every global the function touches and whether it goes through `$gp` or `lui`. That list decides the declarations and the flags ([Matching patterns](Matching-Patterns#globals-gp-vs-lui)).

## 3a. Match it in localdecomp

Start the server (`python localdecomp/server.py --project . --no-git-sync`) and open http://127.0.0.1:8477.

- The left pane is your C. It should hold the externs and typedefs the function needs, then the function. Types like `s32`, `u8` and `f32` come from `common.h` automatically.
- **Build** compiles with the flags of that function's address range (from `tools/text_parts.txt`, or `tools/localdecomp_flags.txt` if the function has an entry there) and shows the diff. A score of 0 is a match.
- **Save** stores your draft and **also writes it into its source file**, replacing the `INCLUDE_ASM` line. Only save at score 0, or you will break the full build. If you saved a partial by mistake, put the `INCLUDE_ASM` line back before committing.
- Functions that are already C show "unverified" until you Build them once.
- If a function needs a different assembler or address mode than its range while you're still working on it, add a line to `tools/localdecomp_flags.txt`:

  ```
  func_0039BEC0 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
  ```

  This affects localdecomp and `try_func.py` only, not the real build.

## 3b. Or match it on the command line

`tools/try_func.py` does the same compile and diff without a browser, and works on Linux through wibo:

```
python tools/try_func.py scratch/func_0039BEC0.c              # flags from its range
python tools/try_func.py scratch/func_0039BEC0.c --all-modes  # S/N x ee-as/Ps2EeAs
python tools/try_func.py scratch/f.c --mode S --as ps2as       # force a combination
```

It prints `func_X: MATCH` or `func_X: N diff` with a side-by-side listing (left is yours, right is retail, `**` marks differing lines). Relocated fields are masked, so `lui $a0, 0` against `lui $a0, 0x1e` is not a difference. Keep scratch files outside `src/` (for example in a gitignored `scratch/` folder).

`--all-modes` is the fastest way to find out whether a function needs non-default flags. Run it whenever a function is close but the global accesses don't line up.

## 4. Put it into its source file

If you used localdecomp's Save at score 0, this is done. By hand:

1. Replace the function's `INCLUDE_ASM` line with the block, wrapped in markers so localdecomp can find it:

   ```c
   /* localdecomp:start func_003E4790 */
   typedef struct { u32 key; void *val; } HE_8;
   extern u8 D_001DAA89;
   void *func_003E4790(HT_8 *t, u32 key) {
       ...
   }
   /* localdecomp:end func_003E4790 */
   ```

2. If the function needs flags other than its range's, add a single-function override to `tools/text_parts.txt` (see [Toolchain and build](Toolchain-and-Build#text_partstxt)) and delete its line from `localdecomp_flags.txt`.
3. Use plain names (`D_00142430`). Only if another block in the same file declares that name with a different type, declare a per-function alias such as `D_00142430_00396628` and add it to `symbol_addrs_resolved.txt` with the real address (`D_00142430_00396628 = 0x142430;`). A plain `D_` name that's new to the build also needs its line there.
4. If the block uses a prototype, typedef or extern that only another file declares, run `python tools/split_text.py --refresh`. It adds what the file needs to its "declarations from other files" section (localdecomp's Save does this for you). `pr_check.py` reports a file whose section is out of date.

## 5. Prove it

```
python tools/pr_check.py
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"          (or: python3 tools/build.py)
```

`pr_check.py` catches the usual full-build failures (undefined aliases, conflicting typedefs, variable definitions, `@ps2as` ranges with asm stubs, and any file or slice that no longer compiles) and tells you the line to fix. Before that, `python tools/try_in_context.py scratch/func_X.c` on each new function shows both its diff inside its file and whether the rest of the build still compiles with its declarations. `make` must end with `MATCH`. Then open a PR ([Pull requests](Pull-Requests)).

## Common full-build errors

| Error | Cause | Fix |
|---|---|---|
| `multiple definition of D_...` | A variable was defined in a source file (no `extern`) | Make it `extern`. Never define. |
| `relocation truncated to fit: R_MIPS_GPREL16 D_...` | Declared sized, so it went through `$gp`, but the address isn't in `$gp` range | Retail uses `lui`: declare it `extern T D_X[];` |
| `relocation truncated to fit: R_MIPS_LITERAL lit4` | A float constant went to the `.lit4` pool | Retail builds it inline: needs `@ps2as` |
| `undefined reference to D_..._suffix` | Alias missing from `symbol_addrs_resolved.txt` | Add it with the base address |
| `conflicting types for 'S_...'` | Two blocks define the same typedef name differently | Give one a unique name (e.g. suffix the function address) |
| Ps2EeAs errors about `macro.inc` or unknown options | An `@ps2as` range contains an `INCLUDE_ASM` stub | Narrow the override to end after the C function |
| `implicit declaration of function` or `'X' undeclared` in a file that used to build | The block uses something only another file declares | `python tools/split_text.py --refresh` |
| `conflicting types for 'func_X'` (or `D_X`) in a later block or another file | Your block declares a name with a different type than another declaration the compiler sees: a later block of the same file, or a later file that uses the name without declaring it (`split_text.py --refresh` gives it yours) | Use the existing declaration (grep `src/frontbin/`), or a per-function alias in your block plus its line in `symbol_addrs_resolved.txt`. `try_in_context.py` and `pr_check.py` report this before `make` does |
| `NO MATCH` with no compile error | A function compiled but doesn't match, often a partial saved from localdecomp | Rebuild each changed function in localdecomp or `try_func.py`; restore `INCLUDE_ASM` for any that aren't at 0 |
