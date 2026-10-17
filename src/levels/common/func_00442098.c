#include "common.h"
f32 func_00442098(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 t2 = t * t;
    f32 a = (p3 - p2) - (p0 - p1);
    f32 b = (p0 - p1) - a;
    return a * (t2 * t) + b * t2 + (p2 - p0) * t + p1;
}
