#include "common.h"
extern s32 func_00431400(u8 *, s32, s32);
extern void func_003CE270(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_003CDF10(u8 *a0) {
    if (func_00431400(a0, -1, 0)) {
        func_003CE270(a0, 7, 0, 7834, 1, 1, 1, 0, 0xC050C020, 0.0f, 1.0f);
    }
}
