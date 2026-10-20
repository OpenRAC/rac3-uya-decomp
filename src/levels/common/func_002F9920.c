#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00439610(u8 *);
extern s32 func_004C4A18(u8 *, s32, f32, f32, f32);

u8 *func_002F9920(s128 *pos, s128 *a1)
{
    u8 *m;
    s32 *v;

    m = func_00435E70(121, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 511;
        m[49] = 1;
        m[32] = 0;
        v = *(s32 **)(m + 104);
        *(s128 *)(m + 16) = *pos;
        *(s128 *)v = *a1;
        v[5] = 0;
        v[4] = 30;
        v[6] = 300;
        *(f32 *)(m + 240) = func_004408C0(-3.1415927f, 3.1415927f);
        *(f32 *)(m + 244) = func_004408C0(-3.1415927f, 3.1415927f);
        *(f32 *)(m + 248) = func_004408C0(-3.1415927f, 3.1415927f);
        *(s32 *)(m + 252) = 0;
        func_00439610(m);
        v[7] = func_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
