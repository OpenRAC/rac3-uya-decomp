#include "common.h"

/* localdecomp:start func_003B8758 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003E45B8(u128_t *out, u128_t *v, f32 s);
extern f32 func_003E4620(u128_t *a, u128_t *b);
extern f32 func_003E4660(u128_t *a);

void func_003B8758(u128_t *p, u128_t *dir, u128_t *proj, u128_t *perp) {
    f32 d;
    if (func_003E4660(dir) <= 0.0f) {
        *proj = *p;
        __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(perp));
        return;
    }
    d = func_003E4620(dir, p);
    func_003E45B8(proj, dir, d / func_003E4620(dir, dir));
    __asm__ __volatile__(
        "lqc2 $vf1, 0x0(%0)\n"
        "lqc2 $vf2, 0x0(%1)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0x0(%2)\n"
        : : "r"(p), "r"(proj), "r"(perp) : "memory");
}
/* localdecomp:end func_003B8758 */
