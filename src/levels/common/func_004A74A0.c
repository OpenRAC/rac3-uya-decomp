#include "common.h"

/* localdecomp:start func_004A74A0 */
extern s32 D_001DFBE8;
extern u8 *D_001DFBEC;
extern u8 D_001A30B0[];
extern s32 func_004A6F58(u8 *, s32, s32, s32, s32);

s32 func_004A74A0(s32 idx, s32 a1, s32 a2, s32 a3)
{
    s32 r;
    u8 *e;

    if (idx >= D_001DFBE8 || idx == 0xFFFFFFFF) {
        return -1;
    }
    r = func_004A6F58(D_001DFBEC + idx * 32, a1, 0, a2 + 64, a3);
    if (r >= 0) {
        e = D_001A30B0 + r * 128;
        *(s32 *)(e + 256) = a2;
        *(s16 *)(e + 202) = idx;
    }
    return r;
}
/* localdecomp:end func_004A74A0 */
