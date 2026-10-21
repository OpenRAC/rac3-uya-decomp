#include "common.h"

/* localdecomp:start func_00674C00 */
extern u8 D_004998A0[];
extern u8 *func_006197D8(s32);
extern void func_0058F1B0(void *, void *, s32);

static __inline__ s32 decode_00674C00(u8 *key) {
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

s32 func_00674C00(s32 a0, s32 a1, s32 a2, u8 *msg) {
    u8 *p = func_006197D8(msg[0]);
    struct { u8 v; } ok;
    ok.v = 0;
    if (p != 0) {
        if ((decode_00674C00(p + 0x19E4) ^ 0x92) != 0 && *(u8 **)(p + 0x2558) != 0 && *(s32 *)(*(u8 **)(p + 0x2558) + 4) != 0) {
            ok.v = 1;
        }
    }
    if (ok.v) {
        func_0058F1B0(p + 0x255C, msg, 0x1C);
    }
    return 0x1C;
}
/* localdecomp:end func_00674C00 */
