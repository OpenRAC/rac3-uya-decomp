#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3A7DE8;
extern s32 D_001A71A0[];
extern f32 D_001E9020[];
extern s32 func_003CCB88(V_3A7DE8 *, V_3A7DE8 *, s32, s32, s32);
f32 func_003A7DE8(V_3A7DE8 *p, f32 h) {
    V_3A7DE8 t;
    f32 z;
    t = *p;
    t.z = t.z - h;
    z = p->z;
    if (func_003CCB88(p, &t, 0, D_001A71A0[0], 0)) {
        z = D_001E9020[2];
    }
    return z;
}
