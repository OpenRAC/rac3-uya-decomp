#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *D_002212D4[];

extern u8 *func_0045E438(s32);

u8 *func_0046FE70(s128 *pos, s128 *dir, s32 a2, f32 f) {
    u8 *p = func_0045E438(111);

    if (p != 0) {
        if (f != 1.0f) {
            *(u32 *)(p + 4) = 0x64FF2020;
        } else {
            *(u32 *)(p + 4) = 0x64FFFFFF;
        }
        *(u32 *)(p + 12) = *(u32 *)(p + 4);
        p[9] = 34;
        p[3] = 72;
        p[1] = 3;
        p[2] = D_002212D4[0][0];
        *(s128 *)(p + 48) = *dir;
        *(f32 *)(p + 60) = f;
        *(s128 *)(p + 16) = *pos;
        *(s16 *)(p + 10) = a2;
        *(f32 *)(p + 28) = f * 0.013f;
        *(f32 *)(p + 44) = 1.0f;
        p[8] = p[10] - 15;
    }
    return p;
}
