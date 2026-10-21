#include "common.h"

/* localdecomp:start func_004A7530 */
extern s32 D_001D669C;
extern s32 D_001DFBE8;
extern u8 *D_001DFBEC;
extern u8 D_001A30B0[];
extern s32 func_004A6F58(u8 *, s32, s32, s32, s32);

s32 func_004A7530(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 idx;
    s32 r;
    u8 *p;

    if (a == 0xFFFFFFFF) {
        return -1;
    }
    idx = a * 4 + b * 2 + c + D_001D669C;
    if (idx >= D_001DFBE8) {
        return -1;
    }
    r = func_004A6F58(D_001DFBEC + idx * 32, d, e, 0, f);
    if (r >= 0) {
        p = D_001A30B0 + (r << 7);
        *(s32 *)(p + 220) = e;
        *(s16 *)(p + 202) = idx;
    }
    return r;
}
/* localdecomp:end func_004A7530 */
