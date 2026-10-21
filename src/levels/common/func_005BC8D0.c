#include "common.h"

/* localdecomp:start func_005BC8D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005BC8D0;
extern void func_0058F5B0(void *, void *, f32);
extern u8 *func_005B2378(void);

void func_005BC8D0(u8 *a0, V4_005BC8D0 *a1, u8 *a2) {
    if (a2 == 0) {
        a2 = func_005B2378();
        if (a2 == 0) {
            *a1 = *(V4_005BC8D0 *)(a0 + 0x10);
            return;
        }
    }
    func_0058F5B0(a1, a0 + 0xE0, *(f32 *)(a2 + 0x10));
    __asm__ __volatile__(
        "lqc2 $vf2, 0x10(%1)\n"
        "lqc2 $vf1, 0x0(%0)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0x0(%0)\n"
        : : "r"(a1), "r"(a0) : "memory");
}
/* localdecomp:end func_005BC8D0 */
