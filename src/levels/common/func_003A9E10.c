#include "common.h"

/* localdecomp:start func_003A9E10 */
void func_003A9E10(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a0 + 104);
    s16 v = *(s16 *)(p + 52);
    if (v >= 2) *(s32 *)a1 = v;
    if (p[68] != 0) *(float *)(a1 + 24) = (float)p[68];
}
/* localdecomp:end func_003A9E10 */
