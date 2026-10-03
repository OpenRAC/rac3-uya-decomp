## Functions

<!-- One line each. Mark anything that isn't plain C. -->
- `func_XXXXXXXX`: plain C
- `func_XXXXXXXX`: needs `@ps2as` (mixed gp/lui access)

## Checks

- [ ] `python tools/pr_check.py` prints `OK`
- [ ] Full build (`make.exe` or `python3 tools/build.py`) prints `MATCH`
- [ ] No retail or generated files (`frontbin.elf`, overlays, `build/`, `.localdecomp_work/`) in the diff
- [ ] New aliases are in `symbol_addrs_resolved.txt`; flag overrides in `tools/text_parts.txt` are single-function
- [ ] Based on current `main`; functions are in the `src/frontbin/` file whose range contains them (`pr_check.py` checks this)

## Notes

<!-- Flag overrides and why, new typedef/alias names, inline asm justification,
     and any pattern others can reuse (add it to docs/wiki/Matching-Patterns.md). -->
