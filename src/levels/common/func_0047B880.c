#include "common.h"

/* localdecomp:start func_0047B880 */
extern s32 func_0047B880(s32);

extern s32 D_001E06B0_003B6050[];
extern s32 D_001E06B4_003B6050[];
s32 func_0047B880(s32 arg0) {
    s32 i = 0;
    s32 c1 = 0x4F000;
    s32 *q = D_001E06B4_003B6050;
    s32 *p = D_001E06B0_003B6050;
    do {
        i++;
        if (p[0] == arg0) return (q[0] & 1) ? c1 : 0x12C00;
        q += 2;
        p += 2;
    } while (i < 7);
    return -1;
}
/* localdecomp:end func_0047B880 */
