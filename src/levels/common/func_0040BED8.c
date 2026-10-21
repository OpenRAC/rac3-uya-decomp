#include "common.h"

/* localdecomp:start func_0040BED8 */
void func_0040BED8(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vdiv Q, $vf0w, $vf2x\n"
        "vwaitq\n"
        "vmulq.xyz $vf1, $vf1, Q\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0040BED8 */
