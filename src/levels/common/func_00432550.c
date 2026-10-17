#include "common.h"

f32 func_00432550(f32 *pos, f32 *vel, f32 target, f32 k, f32 damp) {
    f32 t;
    *vel *= damp;
    t = k * 0.10471976f;
    *vel += t * t * (target - *pos);
    *pos += *vel;
    return *vel;
}
