#include "common.h"

void func_003273E0(f32 *v, f32 x, f32 y) {
    f32 a = v[0] + x;
    f32 b = v[1] + y;

    v[0] = a - (f32)(s32)a;
    v[1] = b - (f32)(s32)b;
}
