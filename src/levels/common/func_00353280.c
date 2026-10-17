#include "common.h"

extern f32 func_0040C018(u8 *a0, u8 *a1);

s32 func_00353280(u8 *a0, u8 *a1) {
    s32 r = 0;
    if (a1 != 0 && a0 != 0 && *(s16 *)(a1 + 170) == 5947) {
        if (func_0040C018(a1 + 16, a0 + 16) < 25.0f) {
            r = a1[67] == 18;
        }
    }
    return r;
}
