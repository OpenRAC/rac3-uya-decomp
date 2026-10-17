#include "common.h"

extern f32 func_0058F400();

f32 func_00644D58(s32 a, s32 b) {
    f32 r = func_0058F400(b);
    if (1.0f < r) {
        r = 1.0f;
    }
    return r;
}
