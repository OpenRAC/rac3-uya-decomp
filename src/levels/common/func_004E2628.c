#include "common.h"

/* localdecomp:start func_004E2628 */
extern float D_001A4E64[];
extern u8 D_001EAAA0[];
extern void func_0050D060(float *, s32, float, float, float);
extern s32 func_003F8448(float *, float *, s32, s32, s32);
extern float func_0040BFB0(float *, void *);
s32 func_004E2628(float *out, float a, float b) {
    float v1[4];
    float v2[4];
    func_0050D060(v1, 1, D_001A4E64[0] - 0.02f, 0.0f, a);
    func_0050D060(v2, 1, b, 0.0f, a);
    if (func_003F8448(v1, v2, 2, 0, 0)) {
        if (out) *out = func_0040BFB0(v1, D_001EAAA0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004E2628 */
