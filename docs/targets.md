# Targets: the executables this repo builds

| Target | ELF | sha1 | Code | Docs |
|---|---|---|---|---|
| `frontbin` | `frontbin.elf` (`globals\misc` on the unpacked disc) | `3bc94ee895e4b4af9b5602a229af599c1103b542` | `src/frontbin/` | [Setup](wiki/Setup.md), [source files](source_files.md) |
| `boot_elf` | `boot_elf.elf` (disc root) | `487975305f8a263c750dfede50391b575ed07835` | `src/boot_elf/core/`, `src/boot_elf/text/` | [boot_elf.md](boot_elf.md) |
| `i5bootn` | `i5bootn.elf` (`files\`) | `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f` | `src/i5bootn/` | [i5bootn.md](i5bootn.md) |

`tools/targets.py` is the registry: each target's ELF and sha1, its code
sections ("units", each an address range with its own source and asm folder),
its tables, its linker script, splat config and objdiff names. Everything else
reads it.

## Using the tools on a target

Every tool works on frontbin unless told otherwise:

```
python tools/triage.py --target boot_elf
UYA_TARGET=i5bootn python3 tools/try_func.py scratch/f.c
```

These also take `--target all`, which runs them once per target that is set
up (its ELF and asm folder are there) and fails if any run fails:

| Tool | `--target all` |
|---|---|
| `setup_asm.py` | every target whose ELF is in the repo root |
| `build.py` | builds and checks each |
| `pr_check.py` | checks each |
| `triage.py` | one summary per target |
| `split_text.py --refresh` | refreshes each |
| `gen_divs_nops.py`, `migrate_asm_sources.py` | each |

`make` builds and checks every target (`make check-<target>` for one), and
`make objdiff` makes the objdiff inputs for all of them.

Per target:

| | frontbin | boot_elf, i5bootn |
|---|---|---|
| source file list, flags | `tools/src_files.txt`, `tools/text_parts.txt` | `targets/<t>/src_files.txt`, `targets/<t>/text_parts.txt` |
| `divs_nops`, `sq_ra_funcs`, `localdecomp_flags` | `tools/*.txt` | `targets/<t>/*.txt` |
| symbols | `symbol_addrs.txt`, `symbol_addrs_resolved.txt` | `targets/<t>/symbol_addrs*.txt` |
| asm | `asm/` | `asm/<t>/` |
| build | `build/` | `build/<t>/` |
| localdecomp cache | `.localdecomp_work/` | `.localdecomp_work/<t>/` |
| permuter work dirs | `nonmatchings/<func>/` | `nonmatchings/<t>/<func>/` |
| objdiff units | `frontbin/src/<file>` | `boot_elf/{core,text}/<file>`, `i5bootn/src/<file>` |

Function names are `func_<address>` in every target, so the same name can
mean different functions in two targets. Anything keyed by name is per target.

In localdecomp, the dropdown above the function list picks the target.

## Adding a target

1. Look at the ELF's sections and program headers (`mips-linux-gnu-readelf -lS`).
   Note the code sections, what sits in the gaps (they must be zeros or covered
   by a raw blob), where `$gp` is set (or that nothing uses it) and whether the
   file is a straight memory image.
2. Add it to `tools/targets.py`: copy i5bootn's entry and change the paths,
   sha1, `gp`, `base_flags`, units, `raw_blobs` (the header and anything after
   the last section), `jtbl_segments` (the data segment the jump tables are in)
   and the objdiff names. Set `flatten="elf2bin"` if ee-objcopy doesn't
   reproduce the file.
3. Write `<t>.splat.yaml` (segments: `bin` for raw ranges and gaps, `data` for
   data sections, one `code` segment with a `c` subsegment per unit;
   `global_vram_start/end` to cover `.bss`) and `linker_scripts/<t>.ld` (each
   section at its retail address with `AT(<file offset>)`; the data segment with
   jump tables split into `_a`, `<unit>.c.o(.rodata)`, `_b`).
4. `python tools/bootstrap_target.py --target <t>` (needs splat). It finds the
   functions, classifies them, estimates the source files and flags, writes
   `src/<t>/` and `targets/<t>/` and runs `setup_asm.py`.
5. `python3 tools/build.py --target <t>` must print MATCH.
6. Add the target to the `Makefile` (copy the i5bootn section), to
   `.github/workflows/build-and-report.yml` (copy its ELF, check its asm),
   `.gitignore` (its ELF), and run `python tools/gen_objdiff_units.py`.
7. Write `docs/<t>.md` and add it to this page.

boot_elf was made by its own script, `tools/bootstrap_boot_elf.py`, because its
front end could take frontbin's boundaries, classification and flags (and
then frontbin's C, with `tools/seed_boot_elf.py`).
