#include "common.h"

/* localdecomp:start func_004C57B0 */
extern s32 D_001E11C4[];
extern f32 D_001E11C0[];
extern f32 D_001E11C0_g;
extern s32 D_001E11C4_g;
f32 func_004C57B0(f32 dt) {
    f32 r = 0.0f;
    f32 t;
    if (D_001E11C4[0] != 0) return r;
    t = D_001E11C0_g - dt;
    D_001E11C0_g = t;
    if (t < r) {
        r = -t;
        D_001E11C0[0] = 0.0f;
    }
    D_001E11C4_g = 15;
    return r;
}
/* localdecomp:end func_004C57B0 */
