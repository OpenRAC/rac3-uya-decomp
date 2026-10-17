#include "common.h"

extern s32 func_00431400(u8 *, s32, s32);
extern void func_0043C260(u8 *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_004238A0(u8 *);
extern u8 D_001D66B0[];

void func_0039C270(u8 *a0) {
    if (func_00431400(a0, -1, 0)) {
        func_0043C260(a0, 255, D_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_004238A0(a0);
    }
}
