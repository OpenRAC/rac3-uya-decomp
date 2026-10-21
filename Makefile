# Makefile for frontbin.elf, boot_elf.elf and i5bootn.elf (Ratchet & Clank: Up
# Your Arsenal, PS2)
#
# `make check` builds every executable and checks each against its retail
# sha1; `make check-frontbin` / `make check-boot_elf` / `make check-i5bootn`
# build one. boot_elf's and i5bootn's sections are at the end of this file
# (docs/boot_elf.md, docs/i5bootn.md).
#
# Builds the whole project into a linked ELF via linker_scripts/frontbin.ld,
# using splat's generated asm/ output for not-yet-decompiled regions and
# src/*.c for decompiled code. Run from the repo root with SN's own make.exe
# (confirmed present in the toolchain bin folder alongside the compiler).
#
#   "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"
#
# This is a FIRST PASS meant to be iterated on against real compiler/linker
# errors, not a finished, battle-tested build -- see the session notes for
# what's still unverified (INCLUDE_ASM's relative .include path resolution
# in particular).

TOOLBIN := C:/tools/eegcc_2.95.3_sn_v1.36/bin

# Sony's ee-gcc 2.9-ee-991111 (the Windows build), for the text_parts.txt
# ranges marked @ee29: library code that came prebuilt with Sony's compiler
# (i5bootn's libgcc, see tools/ee29.py and docs/i5bootn.md). Set it with
# `make EE29=...` or the UYA_EE29 environment variable.
ifdef UYA_EE29
EE29 ?= $(UYA_EE29)
endif
EE29 ?= C:/tools/testfolder/ee-gcc2.9-991111

CC      := $(TOOLBIN)/ee-gcc2953.exe
AS      := $(TOOLBIN)/ee-as.exe
LD      := $(TOOLBIN)/ee-ld.exe
OBJCOPY := $(TOOLBIN)/ee-objcopy.exe
READELF := $(TOOLBIN)/ee-readelf.exe

BUILD_DIR := build
LD_SCRIPT := linker_scripts/frontbin.ld
TARGET    := $(BUILD_DIR)/frontbin.elf
# Flat file image built from TARGET's load addresses. The linker script places
# every section at its retail file offset (AT(...)), and asm/header.s supplies
# the retail ELF header bytes, so this file is what should equal the retail
# frontbin.elf byte for byte. Checked against the sha1 in config/splat/frontbin.yaml.
TARGET_BIN := $(BUILD_DIR)/frontbin.bin

# -G0: never let GCC guess small-data placement on its own -- only symbols
# explicitly forced gp-relative (via the same mechanism localdecomp uses
# per-function) should ever get that addressing mode. Matches the flags
# already proven correct by every localdecomp single-function build today.
#
# -Wa,-I,include: the INCLUDE_ASM(...) stubs in src/frontbin/*.c pull in per-function .s
# files that themselves `.include "macro.inc"` with no path prefix --
# same issue as the standalone data-segment .s files (see ASFLAGS below),
# but here it's GCC's own internal assembler pass doing the .include, so
# the flag has to go through -Wa (GCC's "pass this to the assembler"
# mechanism) rather than being a plain -I. UNVERIFIED -- if ee-gcc2953.exe
# doesn't accept -Wa the same way modern GCC does, this needs adjusting
# once we see the real error.
# Optimisation/-G/-mno-split-addresses are NOT set here: they come per
# address range from config/frontbin/text_parts.txt (see tools/build_text.py and
# compiler_matrix_findings.md). Retail frontbin was built from many source
# files, some with -mno-split-addresses; all use -O2 -G8.
# -B$(TOOLBIN)/ee- makes gcc use bin/ee-as.exe (the Aug 2000 assembler) instead
# of ee/bin/as.exe; retail needs the older one (mtc1 hazard nops).
CFLAGS := -I include -I . -Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi -DINCLUDE_ASM_USE_MACRO_INC=1 -B$(TOOLBIN)/ee-
PYTHON ?= python
TEXT_PARTS := config/frontbin/text_parts.txt
# .text sources: one C file per original source file, in link order in
# config/frontbin/src_files.txt (see tools/srcfiles.py and tools/build_text.py).
SRC_FILES := $(wildcard src/frontbin/*.c) config/frontbin/src_files.txt
TEXT_DEPS := $(SRC_FILES) $(TEXT_PARTS) tools/build_text.py tools/ee29.py tools/srcfiles.py tools/asm_filter.py tools/targets.py config/frontbin/divs_nops.txt config/frontbin/sq_ra_funcs.txt

# --- data segments: splat's whole-segment disassembly, one .o each -------
# data is split around the jump-table block (tools/migrate_jtbls.py); text.c.o(.rodata) goes between.
DATA_SEGMENTS := lit data_a data_b lvl_vtbl lvl_camvtbl lvl_sndvtbl
DATA_OBJS := $(patsubst %,$(BUILD_DIR)/asm/data/%.data.s.o,$(DATA_SEGMENTS))

# --- header segment: raw ELF header + padding, see asm/header.s ----------
HEADER_OBJ := $(BUILD_DIR)/asm/header.s.o

# --- code: src/frontbin/*.c contain both real decompiled C and INCLUDE_ASM(...)
# stubs for everything not decompiled yet; the assembler resolves each stub's
# .include at compile time. build_text.py compiles each file (one object per
# file in build/src/frontbin/) and links them into one text.c.o.
TEXT_OBJ := $(BUILD_DIR)/src/text.c.o

.PHONY: all clean check check-frontbin check-boot_elf check-i5bootn check-veldin objdiff objdiff-frontbin objdiff-boot_elf objdiff-i5bootn objdiff-veldin
all: check

# -I include: every splat-generated .s (data segments, per-function
# nonmatchings) starts with a bare `.include "macro.inc"` or
# `.include "labels.inc"` -- these live in include/, and with no path
# prefix on the .include itself, the assembler only finds them via its
# own -I search path. Without this, EVERY custom splat pseudo-op
# (nonmatching, dlabel, enddlabel, glabel, ...) fails as "unrecognized
# opcode", because those are macros macro.inc/labels.inc define -- not
# real MIPS opcodes -- and the cascade of errors is just every use of an
# undefined macro, not independent problems.
ASFLAGS := -I include -EL -mips3 -mcpu=5900 -mabi=eabi

$(BUILD_DIR)/asm/data/%.data.s.o: asm/data/%.data.s
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(AS)" $(ASFLAGS) -o "$@" "$<"

$(HEADER_OBJ): asm/header.s
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(AS)" $(ASFLAGS) -o "$@" "$<"

$(TEXT_OBJ): $(TEXT_DEPS)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(TARGET): $(HEADER_OBJ) $(DATA_OBJS) $(TEXT_OBJ) $(LD_SCRIPT)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(LD)" -T "$(LD_SCRIPT)" -o "$@"
	"$(READELF)" -h "$@"

$(TARGET_BIN): $(TARGET)
	"$(OBJCOPY)" -O binary "$<" "$@"

# Prints MATCH or the first differing offset; fails the build on a mismatch.
check: check-frontbin check-boot_elf check-i5bootn

check-frontbin: $(TARGET_BIN)
	python tools/check_match.py "$(TARGET_BIN)" baserom/frontbin.elf config/splat/frontbin.yaml

clean:
	@if exist "$(subst /,\,$(BUILD_DIR))" rmdir /s /q "$(subst /,\,$(BUILD_DIR))"

# --- objdiff progress report inputs ---------------------------------------
# One objdiff unit per source file (tools/objdiff/gen_objdiff_units.py writes them).
# target: the full build's per-file objects (build/src/frontbin/*.o). Only
#         copied after `check` has confirmed MATCH, so every function in them
#         (asm or C) is proven retail-exact.
# base:   the same files compiled with -DOBJDIFF_BASE, which makes every
#         INCLUDE_ASM expand to nothing (see include/include_asm.h). They hold
#         only the decompiled C functions, so objdiff reports
#         "decompiled / total" instead of 100%.
OBJDIFF_TARGET := $(BUILD_DIR)/objdiff/target/text.o
OBJDIFF_BASE   := $(BUILD_DIR)/objdiff/base/text.o
# common-level C (src/levels/common/, docs/common_level_c.md): the levels/common
# unit's base. tools/objdiff/common_c_base.py proves each function against your own
# reference files in C:\decomp-refs (or UYA_REFS) and fails if one stops
# matching; without those files it writes an empty base, so the report still runs.
OBJDIFF_COMMON := $(BUILD_DIR)/objdiff/base/common.o
# only the catalogued sources: an uncatalogued file in src/levels/common/ (work
# in progress, which may be deleted mid-build) isn't part of the base
COMMON_DEPS    := $(shell $(PYTHON) tools/objdiff/common_c_base.py --list-sources) config/levels/common_c.json tools/build_common_c.py tools/objdiff/common_c_base.py

objdiff: objdiff-frontbin objdiff-boot_elf objdiff-i5bootn objdiff-veldin

objdiff-frontbin: check-frontbin $(OBJDIFF_TARGET) $(OBJDIFF_BASE) $(OBJDIFF_COMMON)

$(OBJDIFF_TARGET): $(TEXT_OBJ) $(TARGET_BIN)
	@if not exist "$(subst /,\,$(dir $@))frontbin" mkdir "$(subst /,\,$(dir $@))frontbin"
	copy /Y "$(subst /,\,$(TEXT_OBJ))" "$(subst /,\,$@)" >nul
	copy /Y "$(subst /,\,$(BUILD_DIR))\src\frontbin\*.o" "$(subst /,\,$(dir $@))frontbin" >nul

$(OBJDIFF_BASE): $(TEXT_DEPS) include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --base --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(OBJDIFF_COMMON): $(COMMON_DEPS)
	$(PYTHON) tools/objdiff/common_c_base.py -o "$@"


# ===========================================================================
# boot_elf.elf (docs/boot_elf.md)
#
# Two code sections, each built from its own source files into one object:
# core.text (the engine core, src/boot_elf/core/) and .text (the front end
# overlay, src/boot_elf/text/, frontbin's code linked at other addresses).
# Everything else (header, .vutext, the data sections, the trailer with the
# section headers) is assembled from asm/boot_elf/, which
# `python tools/setup_asm.py --target boot_elf` writes from boot_elf.elf.
# Its tables (file list, flags, divs_nops, sq_ra_funcs, symbols) are in
# config/boot_elf/. All tools take `--target boot_elf`.
# ===========================================================================

BOOT_BUILD   := $(BUILD_DIR)/boot_elf
BOOT_LD      := linker_scripts/boot_elf.ld
BOOT_TARGET  := $(BOOT_BUILD)/boot_elf.elf
BOOT_BIN     := $(BOOT_BUILD)/boot_elf.bin
BOOT_TABLES  := config/boot_elf/src_files.txt config/boot_elf/text_parts.txt config/boot_elf/divs_nops.txt config/boot_elf/sq_ra_funcs.txt
BOOT_TOOLS   := tools/build_text.py tools/ee29.py tools/srcfiles.py tools/asm_filter.py tools/targets.py
BOOT_CORE_DEPS := $(wildcard src/boot_elf/core/*.c) $(BOOT_TABLES) $(BOOT_TOOLS)
BOOT_TEXT_DEPS := $(wildcard src/boot_elf/text/*.c) $(BOOT_TABLES) $(BOOT_TOOLS)
BOOT_CORE_OBJ  := $(BOOT_BUILD)/src/core.c.o
BOOT_TEXT_OBJ  := $(BOOT_BUILD)/src/text.c.o

BOOT_DATA_SEGMENTS := vutext core_data core_rdata core_lit lit data_a data_b lvl_vtbl lvl_camvtbl lvl_sndvtbl patch_data legal_data mc1_data_a mc1_data_b
BOOT_ASM_OBJS := $(BOOT_BUILD)/asm/boot_elf/header.s.o $(BOOT_BUILD)/asm/boot_elf/trailer.s.o \
                 $(patsubst %,$(BOOT_BUILD)/asm/boot_elf/data/%.data.s.o,$(BOOT_DATA_SEGMENTS))

$(BOOT_BUILD)/asm/boot_elf/%.s.o: asm/boot_elf/%.s
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(AS)" $(ASFLAGS) -o "$@" "$<"

$(BOOT_CORE_OBJ): $(BOOT_CORE_DEPS)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target boot_elf --unit core --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(BOOT_TEXT_OBJ): $(BOOT_TEXT_DEPS)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target boot_elf --unit text --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(BOOT_TARGET): $(BOOT_ASM_OBJS) $(BOOT_CORE_OBJ) $(BOOT_TEXT_OBJ) $(BOOT_LD)
	"$(LD)" -T "$(BOOT_LD)" -o "$@"

$(BOOT_BIN): $(BOOT_TARGET)
	"$(OBJCOPY)" -O binary "$<" "$@"

check-boot_elf: $(BOOT_BIN)
	python tools/check_match.py --target boot_elf "$(BOOT_BIN)" baserom/boot_elf.elf config/splat/boot_elf.yaml

# objdiff: build/objdiff/{target,base}/boot_elf/{core,text}/<file>.o, one unit
# per source file (tools/objdiff/gen_objdiff_units.py), the same way as frontbin.
BOOT_OBJDIFF_CORE_T := $(BUILD_DIR)/objdiff/target/boot_elf/core.o
BOOT_OBJDIFF_TEXT_T := $(BUILD_DIR)/objdiff/target/boot_elf/text.o
BOOT_OBJDIFF_CORE_B := $(BUILD_DIR)/objdiff/base/boot_elf/core.o
BOOT_OBJDIFF_TEXT_B := $(BUILD_DIR)/objdiff/base/boot_elf/text.o

objdiff-boot_elf: check-boot_elf $(BOOT_OBJDIFF_CORE_T) $(BOOT_OBJDIFF_TEXT_T) $(BOOT_OBJDIFF_CORE_B) $(BOOT_OBJDIFF_TEXT_B)

$(BOOT_OBJDIFF_CORE_T): $(BOOT_CORE_OBJ) $(BOOT_BIN)
	@if not exist "$(subst /,\,$(dir $@))core" mkdir "$(subst /,\,$(dir $@))core"
	copy /Y "$(subst /,\,$(BOOT_CORE_OBJ))" "$(subst /,\,$@)" >nul
	copy /Y "$(subst /,\,$(BOOT_BUILD))\src\core\*.o" "$(subst /,\,$(dir $@))core" >nul

$(BOOT_OBJDIFF_TEXT_T): $(BOOT_TEXT_OBJ) $(BOOT_BIN)
	@if not exist "$(subst /,\,$(dir $@))text" mkdir "$(subst /,\,$(dir $@))text"
	copy /Y "$(subst /,\,$(BOOT_TEXT_OBJ))" "$(subst /,\,$@)" >nul
	copy /Y "$(subst /,\,$(BOOT_BUILD))\src\text\*.o" "$(subst /,\,$(dir $@))text" >nul

$(BOOT_OBJDIFF_CORE_B): $(BOOT_CORE_DEPS) include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target boot_elf --unit core --base --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(BOOT_OBJDIFF_TEXT_B): $(BOOT_TEXT_DEPS) include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target boot_elf --unit text --base --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"


# ===========================================================================
# i5bootn.elf (docs/i5bootn.md)
#
# The bootstrap launcher: one code section (.text, src/i5bootn/), its .data and
# .rodata (mostly the payload it loads), assembled from asm/i5bootn/, which
# `python tools/setup_asm.py --target i5bootn` writes from i5bootn.elf. Tables
# in config/i5bootn/.
#
# The flat binary comes from tools/elf2bin.py, not ee-objcopy: SN's objcopy
# corrupts 21 bytes of this file's section-name table (the ELF it is given is
# right; see tools/elf2bin.py).
# ===========================================================================

I5_BUILD   := $(BUILD_DIR)/i5bootn
I5_LD      := linker_scripts/i5bootn.ld
I5_TARGET  := $(I5_BUILD)/i5bootn.elf
I5_BIN     := $(I5_BUILD)/i5bootn.bin
I5_TABLES  := config/i5bootn/src_files.txt config/i5bootn/text_parts.txt config/i5bootn/divs_nops.txt config/i5bootn/sq_ra_funcs.txt
I5_DEPS    := $(wildcard src/i5bootn/*.c) $(wildcard src/i5bootn/libgcc/*.c) $(wildcard src/libgcc/*.h) $(I5_TABLES) tools/build_text.py tools/ee29.py tools/srcfiles.py tools/asm_filter.py tools/targets.py
I5_TEXT_OBJ := $(I5_BUILD)/src/text.c.o
I5_ASM_OBJS := $(I5_BUILD)/asm/i5bootn/header.s.o $(I5_BUILD)/asm/i5bootn/trailer.s.o \
               $(patsubst %,$(I5_BUILD)/asm/i5bootn/data/%.data.s.o,data rodata_a rodata_b)

$(I5_BUILD)/asm/i5bootn/%.s.o: asm/i5bootn/%.s
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(AS)" $(ASFLAGS) -o "$@" "$<"

$(I5_TEXT_OBJ): $(I5_DEPS)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target i5bootn --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(I5_TARGET): $(I5_ASM_OBJS) $(I5_TEXT_OBJ) $(I5_LD)
	"$(LD)" -T "$(I5_LD)" -o "$@"

$(I5_BIN): $(I5_TARGET) tools/elf2bin.py
	$(PYTHON) tools/elf2bin.py "$<" "$@"

check-i5bootn: $(I5_BIN)
	python tools/check_match.py --target i5bootn "$(I5_BIN)" baserom/i5bootn.elf config/splat/i5bootn.yaml

# objdiff: build/objdiff/{target,base}/i5bootn/<file>.o, one unit per source file
I5_OBJDIFF_T := $(BUILD_DIR)/objdiff/target/i5bootn.o
I5_OBJDIFF_B := $(BUILD_DIR)/objdiff/base/i5bootn.o

objdiff-i5bootn: check-i5bootn $(I5_OBJDIFF_T) $(I5_OBJDIFF_B)

$(I5_OBJDIFF_T): $(I5_TEXT_OBJ) $(I5_BIN)
	@if not exist "$(subst /,\,$(dir $@))i5bootn" mkdir "$(subst /,\,$(dir $@))i5bootn"
	copy /Y "$(subst /,\,$(I5_TEXT_OBJ))" "$(subst /,\,$@)" >nul
	copy /Y "$(subst /,\,$(I5_BUILD))\src\i5bootn\*.o" "$(subst /,\,$(dir $@))i5bootn" >nul

$(I5_OBJDIFF_B): $(I5_DEPS) include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target i5bootn --base --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

# ===========================================================================
# veldin: level 1's overlay, levels/singleplayer/1_veldin/overlay.elf (docs/veldin.md)
#
# frontbin's layout at other addresses: one code section (.text, src/veldin/),
# its .lit (with .bss stored as zeros), .data and lvl.* vtables, assembled from
# asm/veldin/, which `python tools/setup_asm.py --target veldin` writes from
# baserom/veldin.elf, with each source file's own data placed in .lit and .data
# (tools/split_data.py). Tables in config/veldin/. Not part of `make check`
# yet: `make check-veldin`.
# ===========================================================================

VELDIN_BUILD   := $(BUILD_DIR)/veldin
VELDIN_LD      := linker_scripts/veldin.ld
VELDIN_TARGET  := $(VELDIN_BUILD)/veldin.elf
VELDIN_BIN     := $(VELDIN_BUILD)/veldin.bin
VELDIN_TABLES  := config/veldin/src_files.txt config/veldin/text_parts.txt config/veldin/divs_nops.txt config/veldin/sq_ra_funcs.txt
VELDIN_DEPS    := $(wildcard src/veldin/*.c) $(VELDIN_TABLES) config/veldin/data_split.txt tools/build_text.py tools/split_data.py tools/ee29.py tools/srcfiles.py tools/asm_filter.py tools/targets.py
VELDIN_TEXT_OBJ := $(VELDIN_BUILD)/src/text.c.o
VELDIN_ASM_OBJS := $(VELDIN_BUILD)/asm/veldin/header.s.o $(VELDIN_BUILD)/asm/veldin/trailer.s.o \
                   $(patsubst %,$(VELDIN_BUILD)/asm/veldin/data/%.data.s.o,lvl_vtbl lvl_camvtbl lvl_sndvtbl)
# .lit and .data: the segments' retail bytes with each source file's own data
# (config/veldin/data_split.txt) placed in between, and the linker script's
# output sections for them (tools/split_data.py, docs/veldin.md)
VELDIN_DATA    := $(VELDIN_BUILD)/data/lit.ld $(VELDIN_BUILD)/data/data.ld

$(VELDIN_BUILD)/asm/veldin/%.s.o: asm/veldin/%.s
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(AS)" $(ASFLAGS) -o "$@" "$<"

$(VELDIN_TEXT_OBJ): $(VELDIN_DEPS)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target veldin --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

$(VELDIN_DATA): $(VELDIN_TEXT_OBJ) config/veldin/data_split.txt tools/split_data.py asm/veldin/data/lit.data.s asm/veldin/data/data.data.s
	$(PYTHON) tools/split_data.py --target veldin --as "$(AS)"

$(VELDIN_TARGET): $(VELDIN_ASM_OBJS) $(VELDIN_TEXT_OBJ) $(VELDIN_DATA) $(VELDIN_LD)
	"$(LD)" -T "$(VELDIN_LD)" -o "$@"

$(VELDIN_BIN): $(VELDIN_TARGET)
	"$(OBJCOPY)" -O binary "$<" "$@"

check-veldin: $(VELDIN_BIN)
	python tools/check_match.py --target veldin "$(VELDIN_BIN)" baserom/veldin.elf config/splat/veldin.yaml

# objdiff: the levels/singleplayer/Veldin unit in objdiff.json. Its target
# (from C:\decomp-refs\level-targets-split) holds only Veldin's level-only
# functions; this base is every Veldin source compiled with -DOBJDIFF_BASE, so
# INCLUDE_ASM functions are absent and only C counts. The shared functions
# Veldin links from src/levels/common/ are in it too, but the unit's target
# doesn't list them (they count in levels/common).
VELDIN_OBJDIFF_B := $(BUILD_DIR)/objdiff/base/levels/1_veldin.o

objdiff-veldin: check-veldin $(VELDIN_OBJDIFF_B)

$(VELDIN_OBJDIFF_B): $(VELDIN_DEPS) include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(PYTHON) tools/build_text.py --target veldin --base --cc "$(CC)" --ld "$(LD)" --cflags "$(CFLAGS)" --ee29 "$(EE29)" -o "$@"

# shared functions that only Veldin's own files have as C count in the
# levels/common base too (tools/build_common_c.py target_proven), so that
# base needs Veldin's objects
$(OBJDIFF_COMMON): $(VELDIN_TEXT_OBJ)
