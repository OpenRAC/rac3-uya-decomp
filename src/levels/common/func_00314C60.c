#include "common.h"
void func_00314C60(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a1 + 104);
    float x = *(float *)(v + 96);
    u8 *o = *(u8 **)(a0 + 104);
    if (0.0f <= x) *(float *)(o + 64) = x;
    else *(float *)(o + 64) = 0.0f;
    *(s32 *)(o + 96) = *(s32 *)(v + 32);
}
