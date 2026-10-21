#include "common.h"

/* localdecomp:start func_004D8E10 */
void func_004D8E10(long **pp, s32 x0, s32 y0, s32 x1, s32 y1, s32 z) {
    s32 n, step, i, d;
    unsigned long *p, *q;
    s32 x;
    d = x1 - x0;
    x = x0;
    n = d >> 9;
    step = d / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x2400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x55;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)x | ((long)y0 << 16) | ((long)z << 32);
        q += 1;
        *pp = (long *)q;
        x += step;
        *q = (unsigned long)x | ((long)y1 << 16) | ((long)z << 32);
        *pp = (long *)(q + 1);
    }
}
/* localdecomp:end func_004D8E10 */
