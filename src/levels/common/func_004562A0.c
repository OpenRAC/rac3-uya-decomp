#include "common.h"

/* localdecomp:start func_004562A0 */
extern u8 D_001E2EA0[];
extern s32 func_0040D0C0(void *);
extern f32 func_0040C018(void *, void *);

s32 func_004562A0(void *a0, f32 *out) {
    f32 d = 1048576.0f;
    s32 r;
    f32 t;

    r = func_0040D0C0(a0);
    if (r != -1) {
        t = func_0040C018(a0, D_001E2EA0);
        if (t < d) {
            d = t;
        }
    }
    if (out != 0) {
        *out = d;
    }
    return r;
}
/* localdecomp:end func_004562A0 */
