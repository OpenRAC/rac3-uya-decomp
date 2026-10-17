#include "common.h"

extern u8 *func_00458650(u8 *a0);

void func_00458A70(u8 *a0, f32 a, f32 b, f32 c, f32 d)
{
    u8 *p = func_00458650(a0);

    if (p != 0) {
        *(f32 *)(p + 32) = a;
        *(f32 *)(p + 36) = a;
        *(f32 *)(p + 40) = b;
        *(f32 *)(p + 20) = c;
        *(f32 *)(p + 24) = c;
        *(f32 *)(p + 28) = d;
    }
}
