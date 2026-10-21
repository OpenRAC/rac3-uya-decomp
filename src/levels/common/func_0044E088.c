#include "common.h"

/* localdecomp:start func_0044E088 */
extern void func_0040C0F0(s32 a, s32 b, f32 x);

extern s32 D_001D673C[];
extern void func_0044DF40_003BFD10();
extern void func_0040C0F0(s32, s32, f32);
void func_0044E088(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D673C[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_0044DF40_003BFD10(a0, v, 0);
        func_0040C0F0((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_0044E088 */
