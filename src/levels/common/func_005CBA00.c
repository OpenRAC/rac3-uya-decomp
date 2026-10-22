#include "common.h"

/* localdecomp:start func_005CBA00 */
extern s32 func_0058EFB8(void *);
extern void func_005C2288(void *);

void func_005CBA00(u8 *a0) {
    u8 *s = a0 + 0x20;
    u8 *t;
    if (*(s32 *)(s + 0x10) == 1) {
        t = *(u8 **)(s + 0x14);
        if (t != 0) {
            __asm__ __volatile__(
                "lqc2 $vf1, 0x10(%0)\n"
                "lqc2 $vf2, 0x20(%1)\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0x10(%1)\n"
                : : "r"(t), "r"(a0) : "memory");
        }
    }
    if (func_0058EFB8(a0 + 0xA)) {
        func_005C2288(a0);
    }
}
/* localdecomp:end func_005CBA00 */
