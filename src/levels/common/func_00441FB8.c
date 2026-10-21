#include "common.h"

/* localdecomp:start func_00441FB8 */
void func_00441FB8(u8 *p, s32 a1, s32 a2) {
    u8 f = p[190];
    p[148] = p[32];
    p[32] = a1;
    *(s16 *)(p + 150) = 0;
    f &= 0xFE;
    p[190] = f;
    if (a2 != -1) {
        p[149] = a2;
        p[190] = f & 0xFD;
    }
}
/* localdecomp:end func_00441FB8 */
