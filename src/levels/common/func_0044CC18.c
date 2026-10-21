#include "common.h"

/* localdecomp:start func_0044CC18 */
extern f32 func_0040BFB0(f32 *, f32 *);
extern f32 func_0040BFE8(f32 *, f32 *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern s32 func_00447CA0(f32 *);

f32 func_0044CC18(f32 *a0, f32 *a1, s32 *a2, f32 f12, f32 f13, f32 f14, f32 f15) {
    f32 dist;
    f32 yaw;
    f32 pitch;
    f32 r;
    *a2 = 0;
    dist = func_0040BFB0(a0, a1 + 4);
    if (f13 < dist) {
        *a2 = 1;
    }
    yaw = func_0040CFB0(func_0040C490(a1[4] - a0[0], a1[5] - a0[1]), f12);
    pitch = func_0040CFB0(func_0040C490(func_0040BFE8(a0, a1 + 4), a1[6] - a0[2]), 0.0f);
    if (0.0f < f14 && f14 < yaw) {
        *a2 = 1;
    }
    if (0.0f < f15 && f15 < pitch) {
        *a2 = 1;
    }
    r = dist + yaw * dist;
    if (func_00447CA0(a1)) {
        r += 8.0f;
    }
    return r;
}
/* localdecomp:end func_0044CC18 */
