# Makefile for frontbin.elf (Ratchet & Clank: Up Your Arsenal, PS2)
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
# frontbin.elf byte for byte. Checked against the sha1 in frontbin.splat.yaml.
TARGET_BIN := $(BUILD_DIR)/frontbin.bin

# -G0: never let GCC guess small-data placement on its own -- only symbols
# explicitly forced gp-relative (via the same mechanism localdecomp uses
# per-function) should ever get that addressing mode. Matches the flags
# already proven correct by every localdecomp single-function build today.
#
# -Wa,-I,include: text.c's INCLUDE_ASM(...) stubs pull in per-function .s
# files that themselves `.include "macro.inc"` with no path prefix --
# same issue as the standalone data-segment .s files (see ASFLAGS below),
# but here it's GCC's own internal assembler pass doing the .include, so
# the flag has to go through -Wa (GCC's "pass this to the assembler"
# mechanism) rather than being a plain -I. UNVERIFIED -- if ee-gcc2953.exe
# doesn't accept -Wa the same way modern GCC does, this needs adjusting
# once we see the real error.
CFLAGS := -O2 -G0 -I include -I . -Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi -DINCLUDE_ASM_USE_MACRO_INC=1

# --- data segments: splat's whole-segment disassembly, one .o each -------
DATA_SEGMENTS := lit data lvl_vtbl lvl_camvtbl lvl_sndvtbl
DATA_OBJS := $(patsubst %,$(BUILD_DIR)/asm/data/%.data.s.o,$(DATA_SEGMENTS))

# --- header segment: raw ELF header + padding, see asm/header.s ----------
HEADER_OBJ := $(BUILD_DIR)/asm/header.s.o

# --- code: text.c contains both real decompiled C and INCLUDE_ASM(...)
# stubs for everything splat hasn't been hand-decompiled yet; the assembler
# resolves each stub's .include at compile time, so this is ONE compile
# step producing text.c.o with everything in it.
TEXT_OBJ := $(BUILD_DIR)/src/text.c.o

.PHONY: all clean check objdiff
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

$(TEXT_OBJ): src/text.c
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(CC)" -c $(CFLAGS) -o "$@" "$<"

$(TARGET): $(HEADER_OBJ) $(DATA_OBJS) $(TEXT_OBJ) $(LD_SCRIPT)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(LD)" -T "$(LD_SCRIPT)" -o "$@"
	"$(READELF)" -h "$@"

$(TARGET_BIN): $(TARGET)
	"$(OBJCOPY)" -O binary "$<" "$@"

# Prints MATCH or the first differing offset; fails the build on a mismatch.
check: $(TARGET_BIN)
	python tools/check_match.py "$(TARGET_BIN)" frontbin.elf frontbin.splat.yaml

clean:
	@if exist "$(subst /,\,$(BUILD_DIR))" rmdir /s /q "$(subst /,\,$(BUILD_DIR))"

# --- objdiff progress report inputs ---------------------------------------
# target: the full-build text.c.o. Only copied after `check` has confirmed
#         MATCH, so every function in it (asm or C) is proven retail-exact.
# base:   the same text.c compiled with -DOBJDIFF_BASE, which makes every
#         INCLUDE_ASM expand to nothing (see include/include_asm.h). It holds
#         only the decompiled C functions, so objdiff reports
#         "decompiled / total" instead of 100%.
OBJDIFF_TARGET := $(BUILD_DIR)/objdiff/target/text.o
OBJDIFF_BASE   := $(BUILD_DIR)/objdiff/base/text.o

objdiff: check $(OBJDIFF_TARGET) $(OBJDIFF_BASE)

$(OBJDIFF_TARGET): $(TEXT_OBJ) $(TARGET_BIN)
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	copy /Y "$(subst /,\,$(TEXT_OBJ))" "$(subst /,\,$@)" >nul

$(OBJDIFF_BASE): src/text.c include/include_asm.h
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	"$(CC)" -c $(CFLAGS) -DOBJDIFF_BASE -o "$@" "$<"
