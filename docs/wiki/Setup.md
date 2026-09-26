# Setup

You need three things the repo can't ship: the compiler toolchain, the retail `frontbin.elf`, and a few Python packages. Windows is the primary platform. Linux and macOS work through [wibo](https://github.com/decompals/wibo) (see the end of this page).

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

## 3. Python

- Python 3.9 or newer.
- `pip install -r tools/requirements.txt` (pyelftools and capstone, used by `try_func.py` and `pr_check.py --obj`).
- For localdecomp: [asm-differ](https://github.com/simonlindholm/asm-differ). localdecomp runs it as `python -m diff`, so `diff.py` has to be importable (put it on `PYTHONPATH` or in `site-packages`), plus its dependencies: `pip install colorama ansiwrap watchdog levenshtein cxxfilt`.
- Optional: [objdiff](https://github.com/encounter/objdiff) (`objdiff-cli.exe`) for progress reports.

## 4. First build

From the repo root in PowerShell:

```
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"
```

The last line should be:

```
MATCH: build/frontbin.bin sha1 3bc94ee895e4b4af9b5602a229af599c1103b542 (0x218924 bytes)
```

If it isn't, check your `frontbin.elf` hash and the toolchain layout before changing anything. The unmodified repo always matches.

## 5. localdecomp

localdecomp is the project's local, decomp.me-style web editor. It builds one function at a time with that function's real flags and shows a live diff against retail.

```
python localdecomp/server.py --project . --no-git-sync
```

Then open http://127.0.0.1:8477. See [Workflow](Workflow) for how to use it.

Options you might need:

- `--toolbin PATH` if the toolchain isn't in the default location.
- `--no-git-sync` turns off auto-commit. Without it, localdecomp commits every function that reaches a perfect match. That's fine on a feature branch of your fork, but never on `main`.
- `--refs DIR` and `--objdiff-cli` are only for the full "check" button, which also needs the level target objects. Contributors can skip this and run `make` instead.

## Linux and macOS

The compiler and binutils are Windows executables. [wibo](https://github.com/decompals/wibo) runs them. The project was verified with wibo 1.0.0-beta.1.

1. Copy the toolchain folder over with the same layout.
2. Test a function: `export UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo`, then `python3 tools/try_func.py some.c`.
3. Full build: `python3 tools/build.py`. It runs the same steps as the Makefile and ends with the same `MATCH` line.

localdecomp's `server.py` assumes Windows paths and executables. On Linux, use `tools/try_func.py` for matching.
