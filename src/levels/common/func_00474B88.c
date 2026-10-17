#include "common.h"
extern void func_00513548(f32);
void func_00474B88(s32 a0, s32 a1, s32 a2, f32 f) {
    f32 r;
    if (a2 == 0) {
        a2 = 1;
    }
    if (a2 > 0) {
        r = (f32)a1 / (f32)a2;
    } else {
        r = 0.0f;
    }
    if (r > 1.0f) {
        r = 1.0f;
    }
    func_00513548(f * r);
}
