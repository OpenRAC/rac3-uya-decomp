#include "common.h"
extern s32 func_003F1BF0(s32, s32, f32);
void func_00358F20(u8 *a0, s32 a1, s32 a2, f32 f) {
    s32 *p = (s32 *)(a0 + 64);
    s32 i;
    for (i = 3; i >= 0; i--) {
        *p++ = func_003F1BF0(a1, a2, f);
    }
}
