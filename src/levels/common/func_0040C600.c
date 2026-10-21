#include "common.h"

void func_0040C600(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf5\n"
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmulx.xyzw $vf3, $vf0, $vf0x\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddx.x $vf1, $vf1, $vf5x\n"
        "vaddx.y $vf2, $vf2, $vf5x\n"
        "vaddx.z $vf3, $vf3, $vf5x\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
        "sqc2 $vf4, 48($4)\n"
    );
}
