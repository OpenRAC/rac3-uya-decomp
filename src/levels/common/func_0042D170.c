#include "common.h"

/* localdecomp:start func_0042D170 */
void func_0042D170(u8 *dst, s32 idx, u8 *base, s16 *tbl) {
    u8 *src;
    s32 count;
    s32 i;
    s32 k;
    u8 *p;
    u32 nib;
    u32 run;
    s32 n;
    s32 half = 0;
    u32 hi;
    u8 byte;

    if (idx != 0) {
        src = base + tbl[idx - 1];
    } else {
        src = base + 512;
    }
    count = ((base + tbl[idx]) - src) * 2 / 3;
    for (i = 0; i < count; i++) {
        k = i * 3;
        p = src + (k >> 1);
        nib = p[0];
        run = p[1];
        if (k & 1) {
            nib >>= 4;
        } else {
            run = ((run << 4) | (nib >> 4)) & 0xFF;
            nib &= 0xF;
        }
        hi = nib << 4;
        n = 256;
        byte = nib | hi;
        if (run != 0) {
            n = run;
        }
        if (half) {
            *dst |= hi;
            dst++;
            half = 0;
            n--;
        }
        if (n != 0) {
            do {
                *dst++ = byte;
                n -= 2;
            } while (n > 0);
            if (n != 0) {
                dst--;
                half = 1;
                *dst = nib;
            }
        }
    }
}
/* localdecomp:end func_0042D170 */
