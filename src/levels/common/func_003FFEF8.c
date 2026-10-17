#include "common.h"

extern s32 func_004638D0(s32, s32, s32);
extern void func_003FF208(f32, f32, f32, s32, s32, s32, s32, u32);

void func_003FFEF8(s32 a0) {
    if (func_004638D0(a0, -1, 0) != 0) {
        func_003FF208(2.5f, -5.6f, 1.0f, a0, 31, 0, 7903, 0xC0508080);
    }
}
