#include "common.h"

void func_0040BE48(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vabs.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
