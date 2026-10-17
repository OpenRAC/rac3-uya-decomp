#include "common.h"

void func_004D8EB0(long **pp, s32 x0, s32 y0, s32 u0, s32 v0, s32 x1, s32 y1, s32 u1, s32 v1) {
    s32 n, dx, du, i;
    unsigned long *p, *q;
    s32 x, u, nu, nx;
    dx = x1 - x0;
    du = u1 - u0;
    x = x0;
    u = u0;
    n = dx >> 9;
    dx = dx / n;
    du = du / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x4400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x5353;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)u | ((long)v0 << 16);
        q += 1;
        *pp = (long *)q;
        *q = (unsigned long)x | ((long)y0 << 16);
        *pp = (long *)(q + 1);
        nu = u + du;
        *(q + 1) = (unsigned long)nu | ((long)v1 << 16);
        *pp = (long *)(q + 2);
        nx = x + dx;
        *(q + 2) = (unsigned long)nx | ((long)y1 << 16);
        *pp = (long *)(q + 3);
        u = nu;
        x = nx;
    }
}
