#include "common.h"

/* localdecomp:start func_00327030 */
extern f32 D_00275210[][2];
extern f32 D_002753F0[];

void func_00327030(s32 *n, f32 d, f32 x, f32 y) {
    f32 s;
    f32 t;
    D_00275210[*n][0] = x;
    __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(x * x + y * y));
    t = s / d;
    D_00275210[*n][1] = y;
    if (t > 1.0f) {
        t = 1.0f;
    }
    t = 1.0f - t;
    D_002753F0[*n] = (t + t) - t * t;
    *n += 1;
}
/* localdecomp:end func_00327030 */
