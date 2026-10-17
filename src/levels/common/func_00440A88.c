#include "common.h"

extern f32 func_004408C0(void);
extern f32 func_00440978(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

void func_00440A88(f32 *out) {
    f32 r;
    f32 a;
    f32 b;

    r = func_004408C0();
    a = func_00440978();
    b = func_00440978();
    out[0] = func_0040C3C8(a) * func_0040C3E0(b) * r;
    out[1] = func_0040C3E0(a) * func_0040C3E0(b) * r;
    out[2] = func_0040C3C8(b) * r;
}
