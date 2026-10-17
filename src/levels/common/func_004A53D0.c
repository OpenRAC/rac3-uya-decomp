#include "common.h"

typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
s32 func_004A53D0(f32 *op, void *c, f32 x, f32 lo, f32 hi) {
    S_39EA60 *o = (S_39EA60 *)op;
    s32 a = o->f8;
    f32 t;
    if ((o->f19 & 1) || c != 0) {
        if (x <= lo) return o->fC;
        if (hi <= x) return a;
        t = hi - x;
        return a + (s32)((t * t * (f32)(o->fC - a)) / ((hi - lo) * (hi - lo)));
    }
    if (x <= lo) return o->fC;
    if (!(hi <= x)) return a + (s32)(((hi - x) * (f32)(o->fC - a)) / (hi - lo));
    return a;
}
