#include "common.h"

extern f32 func_0040BFE8(void *, void *);

u8 *func_00455FB8(u8 *me, u8 **list, s32 n, s32 *out) {
    s32 i;
    s32 j;
    u8 *o;
    u8 *best;
    f32 bestD;
    f32 d;

    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    bestD = 9999.0f;
    best = 0;
    for (j = 0; j < n; j++) {
        o = list[j];
        d = 0.0f;
        d += func_0040BFE8(me + 16, o + 16);
        if (__builtin_fabsf(*(f32 *)(o + 24) - *(f32 *)(me + 24)) > 3.0f) {
            d += 100.0f;
        }
        if (d < bestD) {
            best = o;
            bestD = d;
        }
    }
    return best;
}
