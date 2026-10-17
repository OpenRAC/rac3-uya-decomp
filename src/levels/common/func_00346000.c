#include "common.h"

extern f32 D_0024D034;
extern void func_0041BB98(s32, f32, f32, f32, f32);

void func_00346000(u8 *a0, s32 a1, f32 x, f32 y, f32 z, f32 w, f32 u) {
    f32 t = x + (*(f32 *)(a0 + 16) < x ? -D_0024D034 : D_0024D034) * y;

    func_0041BB98(a1, t - *(f32 *)(a0 + 16), w, u, z);
}
