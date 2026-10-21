#include "common.h"

typedef struct {
    s32 n;
    f32 y, z, w;
} T_4746C8;

/* localdecomp:start func_004746C8 */
f32 func_004746C8(T_4746C8 *t, s32 dir, f32 x, f32 pos, f32 max) {
    f32 sum = 0.0f;
    f32 frac;
    s32 i;

    if (dir > 0) {
        if (pos < 0.0f) {
            if (0.0f < x) {
                frac = -pos;
                sum += x * frac;
                if (max <= sum) return max;
            }
            i = (s32)pos;
        } else {
            i = (s32)pos;
            if (0.0f < *(f32 *)((u8 *)t + (i << 4) + 28)) {
                frac = pos - (f32)i;
                if (frac >= 1.0f) {
                    frac -= 1.0f;
                    i++;
                }
                frac = 1.0f - frac;
                sum += *(f32 *)((u8 *)t + (i << 4) + 28) * frac;
                if (max <= sum) return max;
            }
        }
        for (i++; i < t->n; i++) {
            if (0.0f < *(f32 *)((u8 *)t + (i << 4) + 28)) {
                sum += *(f32 *)((u8 *)t + (i << 4) + 28);
                if (max <= sum) return max;
            }
        }
    } else {
        if (pos < 0.0f) {
            if (0.0f < x) {
                frac = -pos;
                sum += x * (1.0f - frac);
                if (max <= sum) return max;
            }
        } else {
        i = (s32)pos;
        if (0.0f < *(f32 *)((u8 *)t + (i << 4) + 28)) {
            frac = pos - (f32)i;
            if (frac >= 1.0f) {
                frac -= 1.0f;
                i++;
            }
            sum += *(f32 *)((u8 *)t + (i << 4) + 28) * frac;
            if (max <= sum) return max;
        }
        for (i--; i >= 0; i--) {
            if (0.0f < *(f32 *)((u8 *)t + (i << 4) + 28)) {
                sum += *(f32 *)((u8 *)t + (i << 4) + 28);
                if (max <= sum) return max;
            }
        }
        if (0.0f < x) {
            sum += x;
            if (max <= sum) return max;
        }
        }
    }
    return sum;
}
/* localdecomp:end func_004746C8 */
