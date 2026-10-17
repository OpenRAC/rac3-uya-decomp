#include "common.h"
f32 func_00347CA0(u8 *a0) {
    f32 t[2];
    f32 f;
    s32 i;
    u8 *p0;
    u8 *p1;
    u8 **arr;
    i = 4;
    if (a0[66] != 0xFF) i = 0;
    arr = (u8 **)(a0 + 88);
    f = *(f32 *)(a0 + 68);
    p0 = *(u8 **)((u8 *)arr + i);
    p1 = *(u8 **)(a0 + 92);
    t[0] = (f32)*(s16 *)(p0 + 4) * 0.0625f;
    t[1] = (f32)*(s16 *)(p1 + 4) * 0.0625f;
    if (f == 0.0f) {
        return t[0];
    }
    if (a0[66] != a0[67]) {
        return t[1];
    }
    if (a0[64] <= a0[65]) {
        return t[0] * (1.0f - f) + t[1] * f;
    }
    return t[1];
}
