#include "common.h"

extern void func_00413258(s32, s32);

extern u32 *D_001E10E8_0038E030;
extern void func_004C1FE8(s32, unsigned long);
void func_00413258(s32 x, s32 y) {
    s32 n = x / 32;
    unsigned long *p, *q, *r;
    s32 i, a, b, lo, hi;
    func_004C1FE8(0x42, (0x8000UL << 24) | 0x4A);
    D_001E10E8_0038E030[0] = (n + 5) | 0x10000000;
    D_001E10E8_0038E030[1] = 0;
    D_001E10E8_0038E030[2] = 0;
    D_001E10E8_0038E030[3] = (n + 5) | 0x50000000;
    p = (unsigned long *)D_001E10E8_0038E030;
    r = p + 2;
    D_001E10E8_0038E030 = (u32 *)r;
    p[2] = (0x8000UL << 45) | 1;
    r[1] = 0xE;
    r[2] = 0x32003;
    r[3] = 0x47;
    r[4] = (0x9000UL << 46) | 1;
    r[5] = 0x10;
    r[6] = 0x146;
    r[7] = (0x8000UL << 16) | 0x8080;
    r[8] = n | 0x8000 | (0x9000UL << 46);
    r[9] = 0x44;
    i = 0;
    if (n > i) {
        unsigned long t0, t1;
        a = y * 8;
        t0 = (unsigned long)(0x8000 - a) << 16;
        t1 = (unsigned long)(a + 0x7FF0) << 16;
        b = -(x * 8);
        lo = b + 0x8000;
        hi = b + 0x8200;
        q = p + 12;
        do {
            *q++ = lo | t0;
            *q++ = hi | t1;
            hi += 0x200;
            lo += 0x200;
            i++;
        } while (i < n);
    }
    D_001E10E8_0038E030 += n * 4 + 0x14;
}
