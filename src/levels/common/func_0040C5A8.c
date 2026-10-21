#include "common.h"

/* localdecomp:start func_0040C5A8 */
void func_0040C5A8(void) {
    __asm__ __volatile__(
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmr32.xyzw $vf3, $vf0\n"
        "vaddw.x $vf1, $vf1, $vf0w\n"
        "vaddw.y $vf2, $vf2, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_0040C5A8 */
