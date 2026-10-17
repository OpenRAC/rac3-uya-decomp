#include "common.h"

extern s32 func_0040D020(f32, s32, s32);
extern s32 D_001DFBC0;

extern f32 func_0040C3E0(f32);
void func_004D4108(u8 *ctx, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 n) {
    s32 r = D_001DFBC0 % n;
    f32 s = func_0040C3E0(((f32)r / (f32)n + (f32)r / (f32)n) * 3.1415927f + -3.1415927f);
    s32 x = (s32)(s * a7) + a7 / 2;
    s32 y = (s32)(s * a6) + a6 / 2;
    s32 z = (s32)(s * a5) + a5 / 2;
    a3 += x;
    a2 += y;
    a1 += z;
    *(s32 *)(ctx + 0x78) = func_0040D020(0.05f, *(s32 *)(ctx + 0x78),
        (a4 << 24) | (a3 << 16) | (a2 << 8) | a1);
}
