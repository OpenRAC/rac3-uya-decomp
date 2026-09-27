# Tools

Every script in `tools/`, plus localdecomp and the Makefile, and what each is for. Run the Python tools from anywhere: they find the repo root themselves. Install their dependencies once with `pip install -r tools/requirements.txt`.

## Which tool do I need?

| I want to... | Use |
|---|---|
| Pick a function to work on | [`triage.py`](#triagepy) |
| Match a function in a browser | [localdecomp](#localdecomp) |
| Match a function on the command line | [`try_func.py`](#try_funcpy) |
| Check a function exactly as the full build compiles it | [`try_in_context.py`](#try_in_contextpy) |
| Get unstuck on a register or ordering near miss | [`permuter_setup.py`](#permuter_setuppy) |
| Draft inline asm for a VU0/MMI leaf | [`gen_asm_func.py`](#gen_asm_funcpy) |
| Check my changes before a PR | [`pr_check.py`](#pr_checkpy), then [`make`](#make-and-buildpy) |
| Build on Linux or macOS | [`build.py`](#make-and-buildpy) |
| Reproduce the CI and decomp.dev numbers | [`make objdiff`](#make-and-buildpy), or localdecomp's **Full check** |

The rest of this page goes tool by tool, grouped by when you'd use them.

---

## Matching a function

### localdecomp

`localdecomp/server.py` is a local decomp.me-style web page. Start it from the repo root and open the printed URL:

```
python localdecomp/server.py
```

- **Function list:** every function with its status: perfect, partial, not started. Hand-written functions and linker remnants show as perfect because they are final assembly; opening one explains that there is no C to write for it.
- **Editor and Build:**
  - Compiles your C with the flags of the function's address range (see [`text_parts.txt`](#text_partstxt-and-localdecomp_flagstxt)).
  - Puts the same `text.c` declarations in front of it that the full build does.
  - Shows a side-by-side diff. A score of 0 is a match.
- **Save:** writes the function into `src/text.c` between `/* localdecomp:start */` and `/* localdecomp:end */` markers, replacing its `INCLUDE_ASM` line. Saving is refused for functions that can't be C: `ASM_FUNC`/`LINKER_REMNANT` entries, and functions that don't start on an 8-byte boundary.
- **Full check:** runs the same steps as CI (full build, MATCH, objdiff report) and compares the result with your last push. Push is only enabled after a passing check.

Useful options:

| Option | Meaning |
|---|---|
| `--toolbin` | folder with `ee-gcc2953.exe` |
| `--port` | web port (default 8477) |
| `--no-git-sync` | don't auto-commit perfect matches |
| `--refs` | folder with the level targets and `frontbin_data.o`, as used by CI |
| `--objdiff-cli` | path to `objdiff-cli` |

A score of 0 in localdecomp is necessary, not sufficient. The full build (`make`) still has to print MATCH.

### try_func.py

The command-line equivalent of localdecomp's Build. Give it a self-contained snippet (externs, typedefs, the function) and it compiles it with the function's real flags and diffs against retail:

```
python tools/try_func.py scratch/func_0039BEC0.c
python tools/try_func.py scratch/func_0039BEC0.c --all-modes     # split/no-split x ee-as/Ps2EeAs
python tools/try_func.py scratch/f.c func_0039BEC0 --mode S --as ps2as
```

- Relocations are filled in with real addresses, so a wrong symbol or two swapped stores show up as differences.
- The `text.c` context is included by default. `--no-context` compiles your file alone.
- `--flags "..."` appends extra compiler flags, for experiments.
- On Linux, pass `--toolchain` and `--runner` (the path to wibo), or set `UYA_TOOLCHAIN` and `UYA_RUNNER`.

Output is `func_X: MATCH` or `func_X: N diff` plus a side-by-side listing.

### try_in_context.py

Puts your snippet into a copy of `src/text.c` in place of the function, builds only that function's part the way the real build does, and diffs it. Use it when something matches in `try_func.py` but not in `make`.

```
python tools/try_in_context.py scratch/func_003AED08.c
```

### permuter_setup.py

Sets up [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) for one function. The permuter randomly rewrites your C and keeps anything closer to retail. Use it for near misses where every instruction is right but gcc picks another register or order.

```
python3 tools/permuter_setup.py scratch/func_0037DF98.c
python3 ../decomp-permuter/permuter.py nonmatchings/func_0037DF98 -j4 --stop-on-zero
```

It writes `nonmatchings/<func>/` (gitignored), with the function's real flags, the `text.c` context and the retail target. `--mode S|N` and `--as ps2as` override the address mode or assembler. The permuter runs on Linux or WSL only. Full instructions: `docs/permuter.md`.

### gen_asm_func.py

Drafts an inline-asm C function from retail assembly, for leaf functions that were inline asm in the original (VU0 vector math, 128-bit MMI code). It decodes the raw `.word` lines back into `lqc2`/`sqc2`/`lq`/`sq` and reuses the function's existing prototype.

```
python tools/gen_asm_func.py scratch func_003886B0 func_00388B40
```

Test each result with `try_func.py`, both with and without `--as ps2as`. `NOREORDER=1` wraps the block in `.set noreorder`, which is rarely what retail has. See [Matching patterns](Matching-Patterns#vu0-code-inline-asm).

---

## Planning and checking

### triage.py

Sorts every remaining `INCLUDE_ASM` function into one bucket:

| Bucket | Meaning |
|---|---|
| `plain` | ordinary C |
| `switch` | jump tables |
| `vu0` | VU0 inline asm |
| `mmi` | 128-bit EE instructions |
| `float-nop` | an unexplained float load then `nop` |
| `handwritten`, `remnant` | not decompilation targets (see [`migrate_asm_sources.py`](#migrate_asm_sourcespy)) |

```
python tools/triage.py                                  # summary by bucket
python tools/triage.py --tsv docs/remaining_functions.tsv   # full list with sizes
```

Start with `plain`, smallest first. `docs/remaining_functions.tsv` is its saved output.

### pr_check.py

Catches the mistakes that break the full build, and names the line to fix:

- unbalanced localdecomp markers;
- a function that is both C and `INCLUDE_ASM`;
- variables *defined* in `text.c` (only `extern` is allowed);
- duplicate typedefs;
- missing symbol aliases;
- orphaned `INCLUDE_RODATA` lines;
- stale localdecomp scores;
- retail files staged in git.

```
python tools/pr_check.py
python tools/pr_check.py --obj build/src/text.c.o      # also check the built object
```

It also prints progress: C functions, `ASM_FUNC`, `LINKER_REMNANT`, remaining `INCLUDE_ASM`. Run it before every PR, then `make`.

---

## Building

### make and build.py

On Windows, use SN's `make.exe`:

```
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"          # build and check: prints MATCH
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe" objdiff  # also build the objdiff/decomp.dev objects
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe" clean
```

On Linux or macOS, `tools/build.py` runs the same steps through wibo:

```
python3 tools/build.py --toolchain ~/sn --runner ~/bin/wibo
```

Both do the same four steps:

1. Assemble the header and data.
2. Build `text.c` with `build_text.py`.
3. Link.
4. Compare with `check_match.py`.

### build_text.py

Called by the build; you don't run it yourself. It cuts `src/text.c` at the addresses in `tools/text_parts.txt` and compiles each part with that range's flags. Each part gets all the declarations from earlier in the file. The parts are then linked back into one `text.c.o`.

Its `function_context` function is what gives localdecomp, `try_func.py` and `permuter_setup.py` the same declarations as the real build.

### asm_filter.py

Runs between gcc and the assembler in every build path (`build_text.py`, `try_func.py`, localdecomp, `permuter_setup.py`); you don't call it yourself. Retail's assembler padded every loop shorter than 6 instructions with `nop`s before the backward branch. Neither assembler we have does that: `ee-as` never pads such loops and Ps2EeAs pads them to 7. The filter adds the `nop`s to reach 6, then writes the branch as a raw `.word` so neither assembler pads it again. Loops whose body contains a macro instruction are left alone.

Without it, no C function containing a short loop could match. With it, loops match with no special C.

### check_match.py

The build's last step: compares the built binary with your `frontbin.elf` and prints MATCH, or the first differing offsets.

### text_parts.txt and localdecomp_flags.txt

Not scripts, but they decide how every function is compiled.

**`tools/text_parts.txt`: the per-address-range flags for the real build.**
- Each line is a start address and its flags.
- `-mno-split-addresses` selects no-split mode; `@ps2as` selects the SN Ps2EeAs assembler.
- A function that needs different flags from its range gets a single-function override line, followed by a line restoring the range's flags at the next function.

**`tools/localdecomp_flags.txt`: temporary per-function flags while you experiment.**
- Only localdecomp and `try_func.py` read it.
- Move the setting into `text_parts.txt` before your PR.

Details in [Toolchain and build](Toolchain-and-Build#text_partstxt).

---

## Source-tree maintenance

These tools change the repo. Most were used once to migrate the whole tree and are idempotent: running them again changes nothing unless there is new work.

### migrate_asm_sources.py

Moves functions that aren't decompilation targets out of `INCLUDE_ASM`:

- **Hand-written functions** (the original was assembly) go to `asm/handwritten/` as `ASM_FUNC(...)`.
- **Linker remnants** (the last word of a function the original linker stripped) go to `asm/remnants/` as `LINKER_REMNANT(...)`.

Both count as done in objdiff and decomp.dev. The script also comments out splat's `nonmatching` line, which would otherwise make objdiff flag the function as not matching.

### split_remnant_prefix.py

Finds `INCLUDE_ASM` functions that start with linker-remnant `[instruction, nop]` pairs. Splat had no symbol between the remnants and the real function after them, so it glued them together, and the result can't be matched as C.

```
python tools/split_remnant_prefix.py            # report
python tools/split_remnant_prefix.py --apply    # split them
```

`--apply` splits each one into a `LINKER_REMNANT` (the pairs) and a new `INCLUDE_ASM` function starting at the real address, for example `func_003A5870` becomes a remnant plus `func_003A5880`. The build stays byte-identical. It found and split 21 functions.

### trailing_padding.py

Finds functions followed by more `nop`s than gcc's 8-byte alignment adds. Converting such a function to C would drop those words and shift everything after it.

```
python tools/trailing_padding.py            # report
python tools/trailing_padding.py --apply    # add TEXT_PADDING(N) after each and trim its .s
```

After `--apply`, a function can be converted to C with no extra step. See `docs/trailing_padding.md`.

### migrate_jtbls.py

Moves each `switch` jump table from the data blob into `text.c` as an `INCLUDE_RODATA` line right after its function's `INCLUDE_ASM`. That lets a C `switch` put its table in the right place. When you convert such a function, delete its `INCLUDE_ASM` and `INCLUDE_RODATA` lines together.

### fix_reg_names.py, fix_quadword_ops.py, fix_short_loops.py

These patch splat's `.s` output so SN's `ee-as.exe` assembles it to retail bytes:

| Script | Fixes |
|---|---|
| `fix_reg_names.py` | ABI register names become numbers (`$a0` to `$4`); `%gp_rel` forms ee-as can't parse |
| `fix_quadword_ops.py` | `lq`/`sq`/`lqc2`/`sqc2`, which ee-as doesn't know, become raw `.word`s |
| `fix_short_loops.py` | Short-loop branches become raw `.word`s, so ee-as doesn't pad them with an extra `nop` |

You only need these after re-running splat.

### extract_header.py

Regenerates `asm/header.s` (the ELF header bytes) from your own `frontbin.elf`. Only needed after re-splitting.

### reconcile.py

Normalizes `undefined_funcs_auto.txt` and `undefined_syms_auto.txt`, so both symbol spellings (`D_143950` and `D_00143950`) and suffixed aliases resolve. Run it if the link reports undefined `D_` symbols after regenerating the symbol files.

### gen_level_targets.py

Generates the objdiff *target* objects for the level overlays, so decomp.dev can count their functions (at 0% until someone decompiles a level). They come from retail files, so they are never committed. CI keeps them in `C:\decomp-refs\level-targets\`.

---

## Other files in tools/

- `requirements.txt`: Python packages for the tools (pyelftools, capstone).
- `remaining_functions.tsv`: an older copy of `triage.py --tsv` output. `docs/remaining_functions.tsv` is the current one.
