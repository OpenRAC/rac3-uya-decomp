#include "common.h"

/* localdecomp:start func_00445758 */
extern f32 func_004454A8(s32, f32, f32);
extern f32 func_004450C0(f32 *, f32, f32);
extern void func_00445558(f32 *, s32, f32, f32);
extern f32 func_0040CEC8(f32, f32);

f32 func_00445758(f32 target, f32 maxv, f32 acc, f32 lim, f32 *pos, f32 *vel, s32 mode) {
    f32 d;
    f32 v;
    f32 w;
    s32 sgn = mode;
    if (mode == 2) {
        if ((0.0f < target && *pos < 0.0f) || (target < 0.0f && 0.0f < *pos)) {
            sgn = 1;
            if (target < 0.0f) {
                sgn = -1;
            }
        } else {
            sgn = 0;
        }
    }
    d = func_004454A8(sgn, target, *pos);
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (0.0f <= v * d) {
        f32 stop = v * v / acc * 0.5f;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                func_004450C0(vel, 0.0f, acc);
            } else {
                func_004450C0(vel, 0.0f, acc * 1.1f);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            if (d < 0.0f) {
                func_00445558(vel, 0, -s, maxv);
            } else {
                func_00445558(vel, 0, s, maxv);
            }
        }
        w = *vel; if (!(__builtin_fabsf(w) < __builtin_fabsf(d))) { *pos = target; return d; }
    } else {
        if (v < 0.0f) w = v + acc; else w = v - acc; *vel = w;
    }
    *pos = func_0040CEC8(w, *pos); return *vel;
}
/* localdecomp:end func_00445758 */
