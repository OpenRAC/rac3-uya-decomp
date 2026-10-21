#include "common.h"

/* localdecomp:start func_003763D8 */
typedef int Q_003763D8 __attribute__((mode(TI)));
extern s32 D_001E1C00[];
extern Q_003763D8 D_001E1B50[];
extern u8 D_001E1BF0[];
extern u8 D_001E1BE0[];
extern void func_0041CA08(void *, void *, f32);

s32 func_003763D8(Q_003763D8 *out) {
    Q_003763D8 *p;
    if (D_001E1C00[0] != 1) {
        *out = D_001E1B50[0];
        return 0;
    }
    p = out;
    __asm__ __volatile__(
        "lui $at, %%hi(D_001E1BF0)\n\t"
        "lqc2 $vf2, %%lo(D_001E1BF0)($at)\n\t"
        "lui $at, %%hi(D_001E1BE0)\n\t"
        "lqc2 $vf1, %%lo(D_001E1BE0)($at)\n\t"
        "vsub.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, 0x0(%0)"
        : "+r"(p) : : "memory");
    func_0041CA08(out, p, 1.0f);
    return 1;
}
/* localdecomp:end func_003763D8 */
