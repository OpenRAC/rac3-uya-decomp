#include "common.h"

extern s32 func_00431400(s32, s32, s32);
extern void func_003CE270(f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, u32);

void func_003CE990(s32 a0) {
    if (func_00431400(a0, -1, 0) != 0) {
        func_003CE270(0.0f, a0, 31, 0.0f, 0, 7837, 1, 1, 1, 1, 0xC050C020);
    }
}
