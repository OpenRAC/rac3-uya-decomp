#include "common.h"

/* localdecomp:start func_0061A850 */
typedef struct {
    u8 pad[0x128];
    s32 time;
} G_0061A850;
extern u8 D_004998A0[];
extern G_0061A850 D_001A5E50;
extern void func_00635680(u8 *, s32, s32, s32, s32, s32, s32);
extern void func_0061C568(u8 *, u8 *, s32);

static __inline__ s32 decode_0061A850(u8 *key) {
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

void func_0061A850(u8 *p, s32 a1, s32 a2, s32 a3, s32 t0) {
    func_00635680(p, a1, a2, decode_0061A850(p + 0x19E4), t0, a3, 0);
    func_0061C568(*(u8 **)(p + 0x2558) + 0x10, p + 0xA0, D_001A5E50.time);
}
/* localdecomp:end func_0061A850 */
