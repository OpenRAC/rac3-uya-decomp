#include "common.h"

void func_0040C368(void) {
    __asm__ __volatile__(
        "pextlh $5, $5, $0\n"
        "psraw $5, $5, 16\n"
        "qmtc2.ni $5, $vf1\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
