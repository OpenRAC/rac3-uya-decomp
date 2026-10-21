#include "common.h"

void func_0040C658(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        "sqc2 $vf23, 48($4)\n"
    );
}
