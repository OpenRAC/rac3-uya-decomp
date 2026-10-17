#include "common.h"

extern void func_0058F7B8(f32 *, s32, void *);
extern f32 func_0058F980(f32, f32);
extern void func_005B55B0(s32, f32, f32);

void func_00631430(u8 *a, s32 b, s32 c) {
    f32 v[4];

    func_0058F7B8(v, b, a + 96);
    func_005B55B0(c, func_0058F980(v[0], v[1]), 0.0f);
}
