#include "common.h"

extern f32 func_004450C0(f32 *, f32, f32);

void func_004459B0(f32 *vel, f32 d, f32 maxv, f32 acc, f32 lim) {
    f32 v;
    if (d == 0.0f && *vel == 0.0f) return;
    if (0.0f <= *vel * d && d != 0.0f) {
        f32 stop;
        stop = *vel * *vel / acc * 0.5f;
        v = *vel;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_004450C0(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_004450C0(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_004450C0(vel, -s, v);
            } else {
                func_004450C0(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) return;
        *vel = d;
    } else {
        v = *vel;
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        if (d < 0.0f && v < d) *vel = d;
        else if (0.0f < d && d < *vel) *vel = d;
    }
}
