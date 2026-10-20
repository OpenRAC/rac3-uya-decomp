#include "common.h"

extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040CEC8(f32, f32);

void func_0044B920(u8 *obj, f32 *a, f32 *b, f32 scale, f32 da, f32 db) {
    *(f32 *)(obj + 240) = scale * func_0040C3E0(*a) * func_0040C3E0(*b);
    *(f32 *)(obj + 244) = scale * func_0040C3E0(*a) * func_0040C3C8(*b);
    *a = func_0040CEC8(*a, da);
    *b = func_0040CEC8(*b, db);
}
