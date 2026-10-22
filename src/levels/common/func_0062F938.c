#include "common.h"

/* localdecomp:start func_0062F938 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0058F7B8(f32 *, f32 *, u8 *);

void func_0062F938(u8 *o, f32 *v, s32 add, f32 x, f32 y, f32 z) {
    __asm__("sq $0, %0" : "=m"(*(u128_t *)v));
    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_0058F7B8(v, v, o + 0x20);
    if (add) {
        __asm__ __volatile__(
            "lqc2 $vf2, 0xA0(%1)\n"
            "lqc2 $vf1, 0(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(v), "r"(o) : "memory");
    }
}
/* localdecomp:end func_0062F938 */
