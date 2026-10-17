#include "common.h"

extern f32 func_00590360(f32, f32);
extern void func_00590318(f32, f32);

void func_00537180(f32 x, f32 y, f32 lim) {
    f32 a;
    f32 b;
    f32 c;

    a = func_00590360(y, x);
    b = lim;
    if (!(0.0f < a)) {
        b = -b;
    }
    c = __builtin_fabsf(a);
    if (c < b) {
        b = c;
    } else if (b < -c) {
        b = -c;
    }
    func_00590318(x, b);
}
