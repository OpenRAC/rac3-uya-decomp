#include "common.h"

/* localdecomp:start func_00670B50 */
extern u8 D_004998A0[];

static __inline__ s32 decode_00670B50(u8 *key) {
    s32 buf[2];
    s32 i;
    u8 *b;
    s32 n;
    if (*key == 0) {
        return 0;
    }
    n = *key;
    {
    s32 m = n + 1;
    s32 o = ((u32)key - n) & 7;
    b = (u8 *)buf;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_004998A0[m + ((o + i) & 7) * 255];
    }
    }
    buf[0] ^= (s32)key;
    buf[1] ^= buf[0];
    return buf[1];
}

s32 func_00670B50(u8 *a0) {
    struct { u8 v; } r;
    r.v = 0;
    if (*(s16 *)(a0 + 0x36C) != 0) {
        if ((decode_00670B50(*(u8 **)(a0 + 0x368) + 0x19E6) ^ 0x14) != 0) {
            r.v = 1;
        }
    }
    return r.v;
}
/* localdecomp:end func_00670B50 */
