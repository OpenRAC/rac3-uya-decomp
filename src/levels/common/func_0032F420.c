#include "common.h"

extern f32 func_003F95E8(f32 a);
extern f32 func_003F9600(f32 a);

void func_0032F420(f32 *out, f32 *in, f32 angle, f32 radius) {
    out[0] = in[0] + radius * func_003F95E8(angle);
    out[1] = in[1] + radius * func_003F9600(angle);
    out[2] = in[2];
    out[3] = 0.0f;
}
