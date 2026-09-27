#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER)

/* ASM_FUNC: a function that was assembly in the original (hand-written), so
 * its .s is the source. LINKER_REMNANT: the leftover last word of a function
 * the original linker stripped as unused; not source at all, just bytes that
 * must stay in place. Both are final, so unlike INCLUDE_ASM they stay in the
 * objdiff base build and count as done. See tools/migrate_asm_sources.py. */
#define ASM_FUNC(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#define LINKER_REMNANT(FOLDER, NAME) ASM_FUNC(FOLDER, NAME)

/* TEXT_PADDING(N): N zero words (nops) after the preceding function. A few
 * retail functions are followed by more nops than gcc's 8-byte function
 * alignment adds (see docs/trailing_padding.md). The INCLUDE_ASM .s carries
 * them after its endlabel; once the function is C, put TEXT_PADDING right
 * after it with N = retail trailing nops minus the one alignment nop gcc
 * emits (if any). tools/pr_check.py reports the N each such function needs. */
#define TEXT_PADDING(N) __asm__(".section .text\n    .space (" #N ") * 4\n")

/* objdiff "base" build (make objdiff): drop every not-yet-decompiled function
 * so the object only contains real C. objdiff then counts those as missing. */
#ifdef OBJDIFF_BASE
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        ".section .text" \
    )
#endif

/* NO_MACRO_INC: set by tools/build_text.py for ranges assembled with SN's
 * Ps2EeAs (@ps2as in tools/text_parts.txt), which can't read GNU as macro
 * files. Such ranges hold only C, so they need neither include. */
#ifndef NO_MACRO_INC
#if INCLUDE_ASM_USE_MACRO_INC
__asm__(".include \"include/macro.inc\"\n");
#else
__asm__(".include \"include/labels.inc\"\n");
#endif
#endif

#else

#define ASM_FUNC(FOLDER, NAME)
#define LINKER_REMNANT(FOLDER, NAME)
#define TEXT_PADDING(N)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif /* !defined(M2CTX) && !defined(PERMUTER) */

#endif /* INCLUDE_ASM_H */
