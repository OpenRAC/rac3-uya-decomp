#include "common.h"

void func_0040C9F8(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vaddw.xyz $vf9, $vf0, $vf0w\n"
        "vmul.w $vf3, $vf2, $vf1\n"
        "vmul.xyz $vf4, $vf2, $vf1\n"
        "vmulw.xyz $vf5, $vf2, $vf1w\n"
        "vmulw.xyz $vf6, $vf1, $vf2w\n"
        "vopmula.xyz ACC, $vf1, $vf2\n"
        "vopmsub.xyz $vf7, $vf2, $vf1\n"
        "vadday.x ACC, $vf4, $vf4y\n"
        "vmaddz.x $vf4, $vf9, $vf4z\n"
        "vadd.xyz $vf8, $vf5, $vf6\n"
        "vadd.xyz $vf8, $vf8, $vf7\n"
        "vsubx.w $vf8, $vf3, $vf4x\n"
        "sqc2 $vf8, 0($4)\n"
    );
}
