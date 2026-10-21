#include "common.h"

extern void func_0040BF20();

void func_0040BF20(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vopmula.xyz ACC, $vf2, $vf1\n"
        "vopmsub.xyz $vf3, $vf1, $vf2\n"
        "sqc2 $vf3, 0($4)\n"
    );
}
