#include "common.h"
extern s32 func_004638D0(u8 *, s32, s32);
extern void func_003FF208(u8 *, s32, s32, s32, s32, f32, f32, f32);
void func_003FF500(u8 *a0) {
    if (func_004638D0(a0, -1, 0)) {
        func_003FF208(a0, 7, 0, 7854, 0xC050C020, 0.7f, -0.2f, 0.25f);
    }
}
