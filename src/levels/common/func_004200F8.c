#include "common.h"

extern f32 func_0047EF08(void);
extern f32 func_0047EFC0(void);
extern f32 func_0045CC28(f32);
extern f32 func_0045CC40(f32);

void func_004200F8(f32 *out) {
    f32 r = func_0047EF08();
    f32 a = func_0047EFC0();
    f32 b = func_0047EFC0();
    out[0] = func_0045CC28(a) * func_0045CC40(b) * r;
    out[1] = func_0045CC40(a) * func_0045CC40(b) * r;
    out[2] = 0.0f;
}
