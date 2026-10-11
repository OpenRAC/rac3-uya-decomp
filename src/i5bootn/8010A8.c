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

/* localdecomp:start func_008014A0 */
/* Sony 2.9-ee library code: SIO putc, waits for room in the transmit FIFO and writes one byte.
   Retail has the byte store in the jr delay slot. The original store was most likely volatile
   and moved there by the assembler (binutils 2.10 swaps it; none of this project's assemblers
   do). A plain store that gcc's own delay-slot pass can move matches instead; the empty asm
   keeps the address in a register (lui/ori + sb 0(reg)) instead of folding it into the store. */
int func_008014A0(int c) {
    unsigned char *p;
    while (*(volatile unsigned int *)0x1000F130 & 0x8000)
        ;
    p = (unsigned char *)0x1000F180;
    __asm__("" : "+r"(p));
    *p = c;
    return c;
}
/* localdecomp:end func_008014A0 */

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

/* localdecomp:start func_00801510 */
/* Double (bits in a GPR, soft-float) to int, rounding the last two shifted-out bits; 9999 when too
   large. Called by func_008015A0. Retail ends with dsll32 / jr / dsra32: the sign extension was
   most likely the (int) conversion, a single two-word pattern that the assembler split into the
   delay slot (binutils 2.10 does, this project's assemblers don't). Here the shifts are two
   separate instructions, so gcc's own delay-slot pass puts the second one there; the empty asm
   stops combine from merging them back. The value is the same, sign-extended in $v0. */
long func_00801510(double d) {
    union { double d; unsigned long u; } x;
    long e;
    x.d = d;
    e = (x.u << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    x.u = (x.u << 12) >> 12;
    x.u |= 1UL << 52;
    if (e < 0) {
        e = -e;
        x.u >>= (int)(e - 2);
        if ((x.u & 3) == 3) x.u = (x.u >> 2) + 1;
        else x.u >>= 2;
    } else {
        x.u <<= (int)e;
    }
    {
        long t = x.u << 32;
        __asm__("" : "+r"(t));
        return t >> 32;
    }
}
/* localdecomp:end func_00801510 */

/* localdecomp:start func_008015A0 */
typedef int (*putc_fn_8015A0)(void *, int *, int);
extern int func_008024B8_008015A0(void *, void *, int *, const char *, ...);
extern int func_00801510_008015A0(unsigned long);
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
    m = func_00801510_008015A0((unsigned long)(x * 1000000.0));
    count += func_008024B8_008015A0(out, ctx, n, "0.%d", m);
    if (e >= 0)
        count += func_008024B8_008015A0(out, ctx, n, "e+%d", e);
    else
        count += func_008024B8_008015A0(out, ctx, n, "e%d", e);
    return count;
}
/* localdecomp:end func_008015A0 */

/* localdecomp:start func_00801778 */
/* Sony 2.9-ee library code: the printf core behind func_008024B8 and func_00802508. out is
   called with ctx, &size and each character. Three things here look odd but are what gives
   retail's code:
   - The loop test reads *fmt into t and copies it to c in one expression, with the first read
     of c before the loop and a statement in between (cse keeps t for the test and for ch).
   - After a conversion or a plain character the next character is re-read at "reload:", which
     is written inside the 'e'/'f' case where retail has that block; the paths that already
     have it in c (an unknown conversion character of 0, a field width that ran into the end
     of the string) go to "next:" directly.
   - In the default case an empty asm on c keeps gcc's global copy propagation from replacing
     ch with c there (retail tests ch, the copy made before the switch). It emits nothing. */
typedef int (*putc_fn_801778)(void *, int *, int);
typedef char *va_list_801778;
extern int func_008015A0(putc_fn_801778, void *, int *, double);
#define VA_ARG_801778(ap, T) (*(T *)((ap += 8) - 8))
#define ISDIGIT_801778(c) ((unsigned)((unsigned char)(c) - '0') < 10)

int func_00801778(putc_fn_801778 out, void *ctx, int size, const unsigned char *fmt, va_list_801778 ap) {
    char buf[32];
    char pfx[32];
    char *bufend;
    int width;
    int plen;
    int count;
    char *cp;
    char *start;
    char *digits;
    int flags;
    int prec;
    int len;
    int i;
    int n;
    int t;
    unsigned char c;
    int ch;
    char pad;
    unsigned long uv;
    long sv;
    float f;
    char *s;

    bufend = &buf[31];
    c = *fmt;
    count = 0;
    for (; (t = c) != 0; t = c = *fmt) {
        flags = 0;
        width = 0;
        prec = 0;
        plen = 0;
        ch = (char)t;

        if (ch == '%') {
        again:
            c = *++fmt;
            ch = c;
            switch ((char)c) {
            case '-':
                flags |= 1;
                goto again;
            case '+':
                flags |= 2;
                goto again;
            case '0':
                flags |= 4;
                goto again;
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                i = 0;
                do {
                    i = i * 10 + ((char)c - '0');
                    c = *++fmt;
                } while (ISDIGIT_801778(c));
                width = i;
            check:
                if (c == 0)
                    goto next;
                fmt--;
                goto again;
            case '.':
                fmt++;
                flags |= 0x20;
                n = *(char *)fmt;
                c = *fmt;
                if (n == '*') {
                    i = VA_ARG_801778(ap, int);
                    prec = i < 0 ? -1 : i;
                    goto again;
                }

                i = 0;
                while (ISDIGIT_801778(c)) {
                    i = i * 10 + ((char)c - '0');
                    c = *++fmt;
                }
                prec = i < 0 ? -1 : i;
                goto check;
            case ' ':
                flags |= 8;
                goto again;
            case '#':
                flags |= 0x10;
                goto again;
            case 'l':
                flags |= 0x40;
                goto again;
            case 'h':
                flags |= 0x80;
                goto again;
            case 'o':
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = (uv & 7) + '0';
                        uv >>= 3;
                    }
                    if (flags & 0x10)
                        *cp-- = '0';
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'x':
                digits = "0123456789abcdef";
                if (flags & 0x10) {
                    pfx[0] = '0';
                    pfx[1] = 'x';
                    plen = 2;
                }
                goto hex;
            case 'X':
                digits = "0123456789ABCDEF";
                if (flags & 0x10) {
                    pfx[0] = '0';
                    pfx[1] = 'X';
                    plen = 2;
                }
            hex:
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    plen = 0;
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = digits[uv & 0xF];
                        uv >>= 4;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'd':
            case 'i':
                if (flags & 0x40)
                    sv = VA_ARG_801778(ap, long);
                else if (flags & 0x80)
                    sv = VA_ARG_801778(ap, short);
                else
                    sv = VA_ARG_801778(ap, int);
                cp = bufend;
                if (sv >= 0) {
                    if (flags & 2) {
                        pfx[0] = '+';
                        plen = 1;
                    } else if (flags & 8) {
                        pfx[0] = ' ';
                        plen = 1;
                    }
                } else {
                    pfx[0] = '-';
                    plen = 1;
                }
                if (sv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    if (sv < 0)
                        sv = -sv;
                    while (sv) {
                        *cp-- = sv % 10 + '0';
                        sv /= 10;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'u':
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = uv % 10 + '0';
                        uv /= 10;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'e':
            case 'f':
                f = VA_ARG_801778(ap, double);
                if (f == 0.0f)
                    count += out(ctx, &size, '0');
                else
                    count += func_008015A0(out, ctx, &size, f);
            reload:
                c = *fmt;
                goto next;
            case 's':
                s = VA_ARG_801778(ap, char *);
                if (s == 0) {
                    out(ctx, &size, '(');
                    out(ctx, &size, 'n');
                    out(ctx, &size, 'u');
                    out(ctx, &size, 'l');
                    out(ctx, &size, 'l');
                    out(ctx, &size, ')');
                    goto reload;
                }
                cp = s;
                if (flags & 0x20) {
                    for (i = 0; i < prec && *cp++; i++)
                        ;
                    len = i;
                } else {
                    len = 0;
                    while (*cp) {
                        cp++;
                        len++;
                    }
                }
                start = s;
                break;
            case 'c':
                uv = VA_ARG_801778(ap, char);
                flags |= 0x100;
                prec = 1;
                cp = bufend;
                *cp-- = uv;
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'p':
                uv = VA_ARG_801778(ap, unsigned int);
                digits = "0123456789abcdef";
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = digits[uv & 0xF];
                        uv >>= 4;
                    }
                }
                pfx[0] = '0';
                pfx[1] = 'x';
                plen = 2;
                start = cp + 1;
                len = bufend - cp;
                break;
            default:
                __asm__ ("" : "+r" (c));
                if ((char)ch == 0)

                    goto next;
                flags |= 0x100;
                prec = 1;
                cp = bufend;
                *cp-- = c;
                start = cp + 1;
                len = bufend - cp;
                break;
            }
            if (len < prec) prec -= len; else prec = 0;
            cp = start + len;
            width = width - len - plen - prec;
            if (flags & 0x100) {
                pad = ' ';
                if (flags & 4)
                    pad = width > 0 ? '0' : ' ';
            } else {
                pad = ' ';
                if ((flags & 0x24) == 4)
                    pad = width > 0 ? '0' : ' ';
            }
            if (flags & 1) {
                for (i = 0; i < plen; i++)
                    count += out(ctx, &size, pfx[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
                for (i = 0; i < width; i++)
                    count += out(ctx, &size, ' ');
            } else if (flags & 4) {
                if (pad == '0') {
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &size, pfx[i]);
                    for (i = 0; i < width; i++)
                        count += out(ctx, &size, pad);
                } else {
                    for (i = 0; i < width; i++)
                        count += out(ctx, &size, pad);
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &size, pfx[i]);
                }
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
            } else {
                for (i = 0; i < width; i++)
                    count += out(ctx, &size, pad);
                for (i = 0; i < plen; i++)
                    count += out(ctx, &size, pfx[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
            }
            goto reload;
        } else if (ch) {
            count += out(ctx, &size, ch);
            goto reload;
        }
    next:
        if (c)
            fmt++;
    }
    out(ctx, &size, 0);
    return count;
}
/* localdecomp:end func_00801778 */

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
extern int func_00801778_008024B8(putc_fn_8024B8, void *, unsigned int, const char *, va_list_8024B8);
int func_008024B8(putc_fn_8024B8 out, void *ctx, unsigned int *p, const char *fmt, ...) {
    va_list_8024B8 ap;
    int n;
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    n = func_00801778_008024B8(out, ctx, *p, fmt, ap);
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
extern int func_00801778_00802508(putc_fn_802508, void *, unsigned int, const char *, va_list_802508);
void func_00802508(const char *fmt, ...) {
    int ctx = 0;
    int r;
    va_list_802508 ap;
    r = func_00802588();
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_00801778_00802508((putc_fn_802508)func_00802490, &ctx, (unsigned int)-1, fmt, ap);
    if (r)
        func_008025D8();
}
/* localdecomp:end func_00802508 */

ASM_FUNC("asm/i5bootn/handwritten", func_00802588);

ASM_FUNC("asm/i5bootn/handwritten", func_008025D8);

LINKER_REMNANT("asm/i5bootn/remnants", func_008025F0);
