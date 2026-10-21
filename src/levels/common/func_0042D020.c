#include "common.h"

/* localdecomp:start func_0042D020 */
extern void func_0042D170(u8 *, s32, s32, s32);

void func_0042D020(s32 *out, s32 a1, s32 a2) {
    s32 i;
    s32 j;
    s32 k;
    s32 *p;
    s32 bits;
    u8 b;
    u8 *spr;
    s32 x;
    s32 y;

    spr = (u8 *)0x70000000;
    for (i = 0; i < 256; i++) {
        func_0042D170((u8 *)0x70000000, i, a1, a2);
        x = i % 16;
        y = i / 16;
        p = &out[x + y * 512];
        for (j = 0; j < 32; j++) {
            bits = 0;
            for (k = 0; k < 32; k++) {
                b = spr[j * 16 + (k >> 1)];
                if (k & 1) {
                    b >>= 4;
                } else {
                    b &= 0xF;
                }
                if (b != 0) {
                    bits |= 1 << k;
                }
                if ((k & 31) == 31) {
                    *p++ = bits;
                    bits = 0;
                }
            }
            p += 15;
        }
    }
}
/* localdecomp:end func_0042D020 */
