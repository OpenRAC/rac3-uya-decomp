#include "common.h"

/* localdecomp:start func_003E4788 */
s32 func_003E4788(void *a, void *b, f32 r) {
    long v;
    __asm__ __volatile__(
        ".set noat\n"
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "mfc1 $at, %3\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "qmtc2.ni $at, $vf4\n"
        "vaddw.xyz $vf3, $vf0, $vf0w\n"
        "vmul.x $vf4, $vf4, $vf4\n"
        "vmul.xyz $vf1, $vf1, $vf1\n"
        "vadday.x ACC, $vf1, $vf1y\n"
        "vmaddaz.x ACC, $vf3, $vf1z\n"
        "vmsubx.x $vf1, $vf3, $vf4x\n"
        "qmfc2.ni %0, $vf1\n"
        "dsll32 %0, %0, 0\n"
        "nop\n"
        ".set at\n"
        : "=r"(v) : "r"(a), "r"(b), "f"(r));
    return v < 1;
}
/* localdecomp:end func_003E4788 */
