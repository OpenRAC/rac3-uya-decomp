# Pull requests

## Before you open one

1. Fork the repo and work on a branch (`match/func_0039BEC0` or `match/vtable-isa-family`), not `main`. Start it from the current `main`.
   - The sources are `src/frontbin/*.c`. A branch that still edits `src/text.c` is from before the 2026-10-03 split and can't be merged as it is; see `docs/source_files.md` ("Migration notes") to carry it over.
   - `main`'s history was rewritten on 2026-10-03 (commit messages only). If your clone or fork is older, `git fetch` and `git reset --hard origin/main` (or re-clone) before branching, and rebase open branches onto the new `main`.
2. Run `python tools/pr_check.py`. It must print `OK`.
3. Run the full build (`make.exe`, or `python3 tools/build.py`). It must end with `MATCH`.
4. Check `git status` for anything that shouldn't be there (below).

## What a PR contains

Usually just:

- `src/frontbin/*.c`: the new blocks, each replacing its `INCLUDE_ASM` line, inside `localdecomp:start/end` markers, in the file whose address range (`tools/src_files.txt`) contains the function. If a new block uses another file's prototype, run `python tools/split_text.py --refresh` (localdecomp does this when it saves); the changed "declarations from other files" section belongs in the PR too.
- `tools/text_parts.txt`: single-function overrides, only if a function needs non-default flags.
- `symbol_addrs_resolved.txt`: addresses for any new aliases.

Sometimes: tool fixes, docs, or new symbol names. Keep those in separate PRs from matches when they're large.

## Never include

- `frontbin.elf`, level overlays, disc images, or anything extracted or generated from them (level target objects, `frontbin_data.o`, `.bin` files).
- `build/`, `.localdecomp_work/`, scratch `.c` files, editor settings.
- Local path changes to the `Makefile` (your `TOOLBIN`).
- `Co-authored-by:` trailers for AI tools in commit messages. Remove them (`git commit --amend`, or an interactive rebase for older commits) before you push.

If you added one by accident, `git rm --cached <file>` and amend. If it was pushed, tell a maintainer: it has to be removed from history, not just deleted.

## PR description

The template asks for:

- Which functions are matched (names), and whether each is plain C or uses inline asm or a `$gp` register hack.
- Any flag overrides and why (for example "mixed gp/lui access, needs @ps2as").
- New aliases or typedef names.
- Patterns you discovered that others can reuse. If one is new, add it to [Matching patterns](Matching-Patterns) (`docs/wiki/Matching-Patterns.md` in the repo) in the same PR.

## Review checklist

Reviewers build every PR locally, since CI doesn't run on forks.

- [ ] `pr_check.py` prints `OK`; full build prints `MATCH`.
- [ ] No retail or generated files in the diff.
- [ ] Every new block is inside `localdecomp:start/end` markers, in the right file for its address, and its `INCLUDE_ASM` line is gone.
- [ ] The PR is based on the current `main` and doesn't touch `src/text.c`.
- [ ] No variable definitions: every global is `extern`.
- [ ] Typedefs and aliases have unique names; aliases are in `symbol_addrs_resolved.txt`.
- [ ] Flag overrides are single-function (two lines) and restore the range's flags after.
- [ ] Inline asm or `$gp` hacks are called out and justified.
- [ ] Code reads like source: sensible types, struct fields over raw offsets where the struct is known, no leftover debugging comments.

## Merging

Squash-merge, and check the squashed commit message before confirming: delete any `Co-authored-by:` lines for AI tools that GitHub copied from the branch's commits. A plain merge commit brings every branch commit, and its message, into `main`. Each merge to `main` triggers CI, which rebuilds with the maintainer's retail files and publishes the progress report.

## Updating the wiki

The wiki is generated from `docs/wiki/` in the repo, so doc changes go through PRs like code. Edit the page there. After merge, the wiki sync workflow (or a maintainer) copies it to the GitHub wiki.
