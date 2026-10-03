#include "common.h"
extern f32 func_0040C3C8_004421E8(f32);
f32 func_004421E8(f32 first, f32 second, f32 fraction) {
    if (fraction == 0.0f) return first;
    if (fraction == 1.0f) return second;
    return first + (second - first) * ((1.0f - func_0040C3C8_004421E8(fraction * 3.14159274f)) * 0.5f);
}
