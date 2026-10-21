#include "common.h"

/* localdecomp:start func_0040C328 */
void func_0040C328(void) {
    __asm__ __volatile__(
        "pextlb $5, $0, $5\n"
        "pextlh $5, $0, $5\n"
        "qmtc2.ni $5, $vf1\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0040C328 */
