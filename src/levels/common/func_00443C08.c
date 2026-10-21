#include "common.h"

/* localdecomp:start func_00443C08 */
extern s32 D_001E1118;
extern s32 D_001E111C;
extern f32 D_001E1128;
extern f32 D_001E112C;
extern f32 D_001E1120[];
extern s32 func_004C3198();
extern f32 func_0040BFE8();
f32 func_00443C08(f32 *p, void *out) {
    f32 t;
    if (D_001E1118 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_004C3198)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001E111C != 0) {
        if (__builtin_fabsf(p[2] - *(volatile f32 *)&D_001E1128) < 0.5f && func_0040BFE8(p, D_001E1120) < D_001E112C) {
            if (out != 0) {
                __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
            }
            return *(volatile f32 *)&D_001E1128;
        }
    }
    if (out != 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return p[2];
}
/* localdecomp:end func_00443C08 */
