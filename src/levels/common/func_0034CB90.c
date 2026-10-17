#include "common.h"

f32 func_0034CB90(s32 dir, f32 x, f32 lo, f32 hi) {
    if (hi < x) {
        x = hi;
    } else if (x < lo) {
        x = lo;
    }
    if (dir == 0) {
        x = (hi + lo) - x;
    }
    return (x - lo) / (hi - lo);
}
