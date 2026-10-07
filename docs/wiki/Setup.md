# Setup

You need three things the repo can't ship: the compiler toolchain, the retail `frontbin.elf`, `boot_elf.elf` and `i5bootn.elf`, and a few Python packages. Windows is the primary platform. Linux and macOS work through [wibo](https://github.com/decompals/wibo) (see the end of this page).

## 1. Toolchain: SN Systems ee-gcc 2.95.3 v1.36

It has to be this exact package. Sony's 2.95.3-136 compiler produces the same code, but the SN package also has the `-fopt-stack` option and the two assemblers that retail was built with.

[Here you can find the github where I located the 2.95.3-136 compiler. ](https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01/tree/main)

The default install path is `C:\tools\eegcc_2.95.3_sn_v1.36`. The build expects this layout:

```
C:\tools\eegcc_2.95.3_sn_v1.36\
  bin\ee-gcc2953.exe     compiler driver
  bin\ee-as.exe          default assembler (Aug 2000)
  bin\ee-ld.exe, ee-objcopy.exe, ee-objdump.exe, ee-readelf.exe
  bin\make.exe           SN's make, runs the Makefile
  ee\bin\as.exe          newer GNU assembler (May 2001), selected with @newas
  ee\bin\Ps2EeAs.exe     SN's own assembler (ps2eeas 1.9.25), selected with @ps2as
```

If you install elsewhere, change `TOOLBIN` in the `Makefile` locally (don't commit that change) and pass `--toolbin` to localdecomp.

## 2. Your own frontbin.elf

Extract `frontbin.elf` from your own copy of the game (NTSC-U, SCUS-97353) and put it in the repo root. Check it before anything else:

```
certutil -hashfile frontbin.elf SHA1        (Windows)
sha1sum frontbin.elf                       (Linux/macOS)
```

It must be `3bc94ee895e4b4af9b5602a229af599c1103b542`. The build output is compared against the same hash.

The game contents can be extracted from your legally obtained ISO using [the following software.](https://github.com/chaoticgd/wrench) Use the build tool to unpack the .ISO file. 

1. Open `wrenchlauncher.exe`. 
2. Select Import ISO and once again select the SCUS-97353 ISO. (This will take a few minutes.)
3. Go to where you installed wrench and look in the `games` folder and open `uya_scus_973_53`.
4. Navigate to the `\globals\misc` folder.
5. Run the above command depending on your platform to ensure you have the correct `frontbin.elf`. 

`frontbin.elf` is in `.gitignore`. Never force-add it.

### Your own boot_elf.elf

The repo also decompiles `boot_elf.elf`, the game's main executable (the engine core plus a second copy of the front end). It is in the root of the unpacked disc (the same `uya_scus_973_53` folder, next to `files` and `levels`). Put it in the repo root too and check it:

```
certutil -hashfile boot_elf.elf SHA1        (Windows)
sha1sum boot_elf.elf                       (Linux/macOS)
```

It must be `487975305f8a263c750dfede50391b575ed07835`. It is in `.gitignore` as well. See [`docs/boot_elf.md`](https://github.com/OpenRAC/rac3-uya-decomp/blob/main/docs/boot_elf.md) for how it is laid out.

### Your own i5bootn.elf

`i5bootn.elf` is the bootstrap launcher the disc starts first. It is in the unpacked disc's `files` folder. Put it in the repo root and check it the same way: the sha1 must be `71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f`. It is in `.gitignore` too. See [`docs/i5bootn.md`](https://github.com/OpenRAC/rac3-uya-decomp/blob/main/docs/i5bootn.md).

## 3. Python

- Python 3.9 or newer.
- `pip install -r tools/requirements.txt` (pyelftools and capstone, used by `try_func.py` and `pr_check.py --obj`, and splat, used by `tools/setup_asm.py`).
- For localdecomp: [asm-differ](https://github.com/simonlindholm/asm-differ). localdecomp runs it as `python -m diff`, so `diff.py` has to be importable (put it on `PYTHONPATH` or in `site-packages`), plus its dependencies: `pip install colorama ansiwrap watchdog levenshtein cxxfilt`.
- Optional: [objdiff](https://github.com/encounter/objdiff) (`objdiff-cli.exe`) for progress reports.

## 4. Generate asm/ from your frontbin.elf

`asm/` holds the disassembly of the game's code, so it is gitignored and a fresh clone doesn't have it. Generate it once from your own `frontbin.elf`:

```
python tools/setup_asm.py
```

It runs splat and the assembler fixups, then the same post-processing the project applied (moves the hand-written functions and linker remnants to `asm/handwritten` and `asm/remnants`, cuts trailing padding nops, splits the data blob and its jump tables). It checks the sha1 of `frontbin.elf` first, takes a few minutes, and is safe to repeat. Do not run a bare `python -m splat split` instead: it doesn't produce these files and it overwrites `undefined_funcs_auto.txt` and `undefined_syms_auto.txt`.

You do **not** need `C:\decomp-refs` or `C:\decomp-refs-objdiff` to build or to match functions. Those folders only hold the retail objects that CI and localdecomp's "Full check" use for the objdiff progress report.

Then generate the other executables' asm the same way (it goes to `asm/boot_elf/` and `asm/i5bootn/`, next to frontbin's):

```
python tools/setup_asm.py --target boot_elf
python tools/setup_asm.py --target i5bootn
```

`python tools/setup_asm.py --target all` does all three in one go.

If `make` stops with `No rule to make target 'asm/...'` (or `asm/boot_elf/...`, `asm/i5bootn/...`), this step is missing or incomplete.

## 5. First build

From the repo root in PowerShell:

```
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"
```

`make` builds every executable. The output should include these three lines, the last one at the end:

```
MATCH: build/frontbin.bin sha1 3bc94ee895e4b4af9b5602a229af599c1103b542 (0x218924 bytes)
MATCH: build/boot_elf/boot_elf.bin sha1 487975305f8a263c750dfede50391b575ed07835 (0x35EE64 bytes)
MATCH: build/i5bootn/i5bootn.bin sha1 71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f (0xC5B88 bytes)
```

`make check-frontbin`, `make check-boot_elf` and `make check-i5bootn` build just one of them.

If one doesn't match, check that ELF's hash and the toolchain layout before changing anything. If `make` fails right away because an `asm/` file is missing, run step 4 first. After that, the unmodified repo always matches.

## 6. localdecomp

localdecomp is the project's local, decomp.me-style web editor. It builds one function at a time with that function's real flags and shows a live diff against retail.

```
python localdecomp/server.py --project . --no-git-sync
```

Then open http://127.0.0.1:8477. See [Workflow](Workflow) for how to use it. The dropdown at the top of the function list picks the executable (frontbin, boot_elf or i5bootn); an executable whose ELF or `asm/` folder is missing is listed as "not set up".

Options you might need:

- `--toolbin PATH` if the toolchain isn't in the default location.
- `--no-git-sync` turns off auto-commit. Without it, localdecomp commits every function that reaches a perfect match. That's fine on a feature branch of your fork, but never on `main`.
- `--refs DIR` and `--objdiff-cli` are only for the full "check" button, which also needs the level target objects. Contributors can skip this and run `make` instead.

## 7. Full localdecomp build (optional)

localdecomp's **Full check** button (and CI) compares your build with every retail object in the game, not just the two executables it builds: the level overlays, `i5bootn.elf`, `ntgui.elf`, `sly2.elf` and frontbin's data. Those reference objects are made from your own copy of the game, so they aren't in the repo. A fresh clone has none, and the Full check stops at "copy reference objects". You do **not** need any of this for `make` or for matching functions in localdecomp; it is only for the full progress report.

You need:

- The unpacked disc from step 2 (the folder with `boot_elf.elf`, `files` and `levels`; the levels are in `levels\singleplayer` and `levels\multiplayer`).
- Linux or WSL with `binutils-mips-linux-gnu` (`sudo apt install binutils-mips-linux-gnu`). The generators call `mips-linux-gnu-as` and `mips-linux-gnu-ld`, so they don't run on plain Windows.
- A Python venv in that Linux/WSL environment: `python3 -m venv ~/uya_refs_venv`, then `~/uya_refs_venv/bin/pip install -r tools/requirements.txt` (splat, pyelftools and numpy are needed).
- For the Full check itself, on Windows: `git`, the toolchain from step 1 and `objdiff-cli` (on `PATH` or in `C:\tools`).

From the repo root inside WSL. Generate into a folder on the **Linux side** (here `~/uya-refs`), not directly under `/mnt/c`: the level step merges object files with `ld -r`, which fails ("merging data changed .text") when its output sits on the Windows drive. Then copy the result to the folder localdecomp reads, `C:\decomp-refs` by default. The tools refuse to write into the repo.

```
REFS=~/uya-refs
GAME=/path/to/unpacked/disc        # the folder with boot_elf.elf, files and levels
PY=~/uya_refs_venv/bin/python

$PY tools/gen_level_targets.py --data-only frontbin.elf $REFS/frontbin_data.o
$PY tools/gen_level_targets.py "$GAME/levels" $REFS/level-targets
$PY tools/split_shared_levels.py $REFS/level-targets $REFS/level-targets-split
$PY tools/gen_exe_targets.py "$GAME" $REFS/exe-targets

mkdir -p /mnt/c/decomp-refs
cp -r $REFS/level-targets $REFS/level-targets-split $REFS/exe-targets $REFS/frontbin_data.o /mnt/c/decomp-refs/
mkdir -p /mnt/c/decomp-refs/levels
cp -r "$GAME/levels/singleplayer" "$GAME/levels/multiplayer" /mnt/c/decomp-refs/levels/
```

The level step takes about ten minutes (51 overlays). Check the results in `C:\decomp-refs`:

- `level-targets-split` must hold **105** `.o` files (code and data for each level, `common`, `common_data` and `uninitialised`). `level-targets` (the 51 unsplit objects) and `levels` (your unpacked overlays) are what `make objdiff` uses to prove the common-level C in `src/levels/common/` and count it in the report (`tools/common_c_base.py`); without them that C counts as 0.
- `exe-targets` must hold **8** `.o` files (code and data for each of the four other executables).
- `frontbin_data.o` must be there, and its generator must have printed `data sections differing from retail: none`. The level generator prints `non-reloc mismatches vs retail: 0` for every overlay; anything else means the object isn't an exact copy of retail.

Then start localdecomp as usual (`python localdecomp/server.py --project .`, or add `--refs <folder>` if you used another one) and press Full check. Never commit any of these objects: they are retail code. See [Tools](Tools) for what each generator does.

## Linux and macOS

The compiler and binutils are Windows executables. [wibo](https://github.com/decompals/wibo) runs them. The project was verified with wibo 1.0.0-beta.1.

1. Copy the toolchain folder over with the same layout.
2. Test a function: `export UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo`, then `python3 tools/try_func.py some.c`.
3. Full build: `python3 tools/build.py --target all` (or one `--target`). It runs the same steps as the Makefile and ends each target with the same `MATCH` line.

wibo occasionally hangs, in Ps2EeAs or in the ee-gcc driver, most often on a busy machine. `try_func.py` and the build have no timeout of their own, so wrap scripted runs in one (`timeout 120 python3 tools/try_func.py ...`) and rerun a build that stops without printing `MATCH` after a clean `rm -rf build`.

localdecomp's `server.py` assumes Windows paths and executables. On Linux, use `tools/try_func.py` for matching.
