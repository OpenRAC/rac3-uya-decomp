# Contributing

Thanks for helping. The full guide is on the [wiki](https://github.com/OpenRAC/rac3-uya-decomp/wiki) (sources in `docs/wiki/`). The short version:

1. **Set up** the SN ee-gcc 2.95.3 v1.36 toolchain and your own `frontbin.elf` ([Setup](docs/wiki/Setup.md)).
2. **Match** a function in localdecomp or with `tools/try_func.py` ([Workflow](docs/wiki/Workflow.md), [Matching patterns](docs/wiki/Matching-Patterns.md)).
3. **Check** with `python tools/pr_check.py` and a full build that prints `MATCH`.
4. **Open a PR** from a branch of your fork using the template ([Pull requests](docs/wiki/Pull-Requests.md)).

Hard rules:

- Never commit `frontbin.elf`, level overlays, disc images, or anything generated from them.
- The full build must match byte for byte.
- Variables in `src/frontbin/*.c` are always `extern`, never defined.
- Work from the current `main`. Code goes in `src/frontbin/`; there is no `src/text.c` any more ([source files](docs/source_files.md)).
