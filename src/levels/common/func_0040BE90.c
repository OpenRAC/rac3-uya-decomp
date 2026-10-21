#include "common.h"

extern void func_0040BE90(f32 *, void *, f32);

void func_0040BE90(f32 * p0, void * p1, f32 p2) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyz $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
