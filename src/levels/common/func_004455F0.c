#include "common.h"

/* localdecomp:start func_004455F0 */
extern f32 func_004454A8(f32 target, f32 pos, s32 mode);
extern void func_00445010(f32 *vel, f32 d, f32 a, f32 b, f32 c);
extern f32 func_0040CEC8(f32 a, f32 b);
f32 func_004455F0(f32 *pos, f32 *vel, s32 mode, f32 target, f32 a, f32 b, f32 c) {
    f32 d;

    if (mode == 2) {
        if ((target > 0.0f && *pos < 0.0f) || (target < 0.0f && *pos > 0.0f)) {
            if (target < 0.0f) {
                mode = -1;
            } else {
                mode = 1;
            }
        } else {
            mode = 0;
        }
    }
    func_00445010(vel, func_004454A8(target, *pos, mode), a, b, c);
    *pos = func_0040CEC8(*pos, *vel);
    d = func_004454A8(target, *pos, mode);
    if (__builtin_fabsf(d) < c * 0.01f) {
        *pos = target;
        *vel = 0.0f;
        return *vel;
    }
    return d;
}
/* localdecomp:end func_004455F0 */
