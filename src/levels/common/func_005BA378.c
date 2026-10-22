#include "common.h"

/* localdecomp:start func_005BA378 */
extern s32 D_00242B3C[];
extern void func_0058F358(void *, void *, f32);

void func_005BA378(s32 a0, void *v, s32 keep) {
    if (D_00242B3C[0] == 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory");
    }
    if (keep == 0) {
        func_0058F358(v, v, -1.0f);
    }
}
/* localdecomp:end func_005BA378 */
