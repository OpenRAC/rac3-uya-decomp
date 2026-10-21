#include "common.h"

/* localdecomp:start func_004D09B8 */
void func_004D09B8(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
/* localdecomp:end func_004D09B8 */
