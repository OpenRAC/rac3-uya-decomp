#include "common.h"
f32 func_0034A588(s32 a0, s32 a1, f32 f) {
    f32 t;
    if (a1 <= 0) {
        return 0.0f;
    }
    t = 1.0f - (f32)a0 / (f32)a1;
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    if (2.0f < f) {
        f = 2.0f;
    }
    return t * (1.0f - f * 0.5f * (1.0f - t));
}
