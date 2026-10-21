#include "common.h"

void func_0040CBA0(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
        "sqc2 $vf0, 48($5)\n"
    );
}
