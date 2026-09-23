#ifndef COMMON_H
#define COMMON_H

/* Base integer/float typedefs used throughout the project. Matches the
 * set localdecomp already generates for its own isolated single-function
 * builds (see localdecomp_common.h in server.py) -- kept identical so a
 * function's behavior under a full project build matches what it showed
 * under localdecomp.
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

/* INCLUDE_ASM / INCLUDE_RODATA -- lets a not-yet-decompiled function pull
 * in its target .s directly via inline asm .include, resolved by the
 * assembler at compile time (see include/include_asm.h for the real
 * macro definitions).
 */
#include "include_asm.h"

#endif /* COMMON_H */
