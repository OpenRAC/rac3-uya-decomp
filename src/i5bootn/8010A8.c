#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008010F8(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_008010A8 */
/* Sony 2.9-ee library code: word copy of n bytes (n rounded down to whole words). */
int func_008010A8(unsigned int *d, unsigned int *s, unsigned int n) {
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}
/* localdecomp:end func_008010A8 */

LINKER_REMNANT("asm/i5bootn/remnants", func_008010E0);

ASM_FUNC("asm/i5bootn/handwritten", func_008010E8);

/* localdecomp:start func_008010F8 */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);

void func_008010F8(void) {
    if (func_00801080() == 0x2000000) {
        func_00801138();
    } else {
        func_00801090();
    }
}
/* localdecomp:end func_008010F8 */

ASM_FUNC("asm/i5bootn/handwritten", func_00801138);

ASM_FUNC("asm/i5bootn/handwritten", func_00801340);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008014A0);

/* localdecomp:start func_008014D8 */
/* Sony 2.9-ee library code: SIO putc that turns '\n' into "\r\n" (func_008014A0 writes one byte). */
extern int func_008014A0(int);
void func_008014D8(int c) {
    if (c == '\n') {
        func_008014A0('\r');
        func_008014A0('\n');
    } else {
        func_008014A0(c);
    }
}
/* localdecomp:end func_008014D8 */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00801510);

/* localdecomp:start func_008015A0 */
typedef int (*putc_fn_8015A0)(void *, int *, int);
extern int func_008024B8_008015A0(void *, void *, int *, const char *, ...);
extern int func_00801510(unsigned long);
int func_008015A0(putc_fn_8015A0 out, void *ctx, int *n, double x) {
    int count = 0;
    int e = 0;
    int m;
    if (*n == 0) return 0;
    if (x < 0.0) {
        x = -x;
        count = 1;
        out(ctx, n, '-');
        (*n)--;
    }
    if (x < 0.1) {
        while (x < 0.1) {
            x = x * 10.0;
            e--;
        }
    } else if (x >= 1.0) {
        while (x >= 1.0) {
            x = x / 10.0;
            e++;
        }
    }
    m = func_00801510((unsigned long)(x * 1000000.0));
    count += func_008024B8_008015A0(out, ctx, n, "0.%d", m);
    if (e >= 0)
        count += func_008024B8_008015A0(out, ctx, n, "e+%d", e);
    else
        count += func_008024B8_008015A0(out, ctx, n, "e%d", e);
    return count;
}
/* localdecomp:end func_008015A0 */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00801778);
INCLUDE_RODATA("asm/i5bootn/nonmatchings/text/rodata", D_00805AC0);
INCLUDE_RODATA("asm/i5bootn/nonmatchings/text/rodata", D_00805AD8);
INCLUDE_RODATA("asm/i5bootn/nonmatchings/text/rodata", jtbl_00805AF0);

/* localdecomp:start func_00802490 */
extern void func_008014D8(int);
int func_00802490(void *ctx, int unused, int c) {
    if (c) func_008014D8(c);
    return 1;
}
/* localdecomp:end func_00802490 */

/* localdecomp:start func_008024B8 */
/* Sony 2.9-ee library code: varargs wrapper around the printf core (func_00801778) that
   takes the space left from *p and subtracts what was written. va_start is written out the
   way GCC 2.95's va-mips.h does it for EABI single-float with 64-bit registers. */
typedef int (*putc_fn_8024B8)(void *, unsigned int *, int);
typedef char *va_list_8024B8;
extern int func_00801778(putc_fn_8024B8, void *, unsigned int, const char *, va_list_8024B8);
int func_008024B8(putc_fn_8024B8 out, void *ctx, unsigned int *p, const char *fmt, ...) {
    va_list_8024B8 ap;
    int n;
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    n = func_00801778(out, ctx, *p, fmt, ap);
    *p -= n;
    return n;
}
/* localdecomp:end func_008024B8 */

/* localdecomp:start func_00802508 */
/* Sony 2.9-ee library code: printf to the SIO console, through the printf core with
   func_00802490 as the output callback and no size limit. va_start as in func_008024B8. */
typedef int (*putc_fn_802508)(void *, unsigned int *, int);
typedef char *va_list_802508;
extern int func_00802588(void);
extern void func_008025D8(void);
extern int func_00801778(putc_fn_802508, void *, unsigned int, const char *, va_list_802508);
void func_00802508(const char *fmt, ...) {
    int ctx = 0;
    int r;
    va_list_802508 ap;
    r = func_00802588();
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_00801778((putc_fn_802508)func_00802490, &ctx, (unsigned int)-1, fmt, ap);
    if (r)
        func_008025D8();
}
/* localdecomp:end func_00802508 */

ASM_FUNC("asm/i5bootn/handwritten", func_00802588);

ASM_FUNC("asm/i5bootn/handwritten", func_008025D8);

LINKER_REMNANT("asm/i5bootn/remnants", func_008025F0);
