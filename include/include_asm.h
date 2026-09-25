#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER)

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

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif /* !defined(M2CTX) && !defined(PERMUTER) */

#endif /* INCLUDE_ASM_H */
