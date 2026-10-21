#include "common.h"

extern void func_0040C2F8();

void func_0040C2F8(void) {
    __asm__ __volatile__(
        "lqc2 $vf5, 0($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "lqc2 $vf4, 48($6)\n"
        "nop\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf6, $vf4, $vf5w\n"
        "sqc2 $vf6, 0($4)\n"
    );
}
