#include "common.h"

void func_0040C960(void) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0($5)\n"
        "lqc2 $vf5, 16($5)\n"
        "lqc2 $vf6, 32($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf1x\n"
        "vmadday.xyzw ACC, $vf5, $vf1y\n"
        "vmaddz.xyzw $vf1, $vf6, $vf1z\n"
        "vmulax.xyzw ACC, $vf4, $vf2x\n"
        "vmadday.xyzw ACC, $vf5, $vf2y\n"
        "vmaddz.xyzw $vf2, $vf6, $vf2z\n"
        "vmulax.xyzw ACC, $vf4, $vf3x\n"
        "vmadday.xyzw ACC, $vf5, $vf3y\n"
        "vmaddz.xyzw $vf3, $vf6, $vf3z\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
