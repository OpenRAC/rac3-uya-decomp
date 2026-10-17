#include "common.h"

extern u8 *D_001DFC00[];
s32 func_003FECA8(s32 a0, s32 a1, s32 a2) {
    u8 *b = D_001DFC00[0];
    u8 *res = b + *(s32 *)b;
    u16 *p = (u16 *)(b + 4);
    s32 y = a2 - p[0];
    s32 x, z;
    if (y < 0 || y >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + y]) == 0) return 0;
    p = (u16 *)(b + p[2 + y] * 4);
    x = a1 - p[0];
    if (x < 0 || x >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + x]) == 0) return 0;
    p = (u16 *)(b + p[2 + x] * 4);
    z = a0 - p[0];
    if (z < 0 || z >= p[1]) return 0;
    if (p[2 + z] == 0xFFFF) return 0;
    return (s32)(res + (p[2 + z] << 7));
}
