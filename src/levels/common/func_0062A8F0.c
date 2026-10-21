#include "common.h"

/* localdecomp:start func_0062A8F0 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0062FD90(u8 *, u8 *);
extern void func_0062FD10(u8 *, u8 *, u8 *, f32);
extern void func_0062FA50(u8 *, u8 *, u8 *, f32);

void func_0062A8F0(u8 *o, f32 dec) {
    u8 *v = o + 0x190;
    f32 len = func_0062FD90(o, v);
    f32 d;
    if (len > 0.001f) {
        func_0062FD10(o, v, v, 0.0f);
        d = len - dec;
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_0062FA50(o, v, v, d);
        __asm__ __volatile__(
            "lqc2 $vf1, 0x120(%0)\n"
            "lqc2 $vf2, 0x190(%1)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0x120(%2)\n"
            : : "r"(o), "r"(o), "r"(o) : "memory");
    } else {
        __asm__("sq $0, %0" : "=m"(*(u128_t *)(o + 0x190)));
    }
}
/* localdecomp:end func_0062A8F0 */
