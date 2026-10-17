#include "common.h"

extern s32 func_0053ED70(s32, s32, s32, s32);
extern void func_00532320(s32, void *, s32);

void func_004129E0(s32 a0, s32 a1, void *a2, s32 a3, f32 f) {
    s32 h;
    s32 x;
    f32 y;
    s32 z;

    h = func_0053ED70(a0, a1, 0, -1);
    x = a1;
    func_00532320(h, &x, 4);
    func_00532320(h, a2, 16);
    y = f;
    func_00532320(h, &y, 4);
    z = a3;
    func_00532320(h, &z, 4);
}
