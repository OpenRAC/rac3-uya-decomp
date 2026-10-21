#include "common.h"

/* localdecomp:start func_004A7368 */
extern u8 D_001A30B0[];
extern s32 func_004A6F58();

extern s32 D_001DFBEC;
extern s32 D_001D669C;
extern u8 D_001A30B0[];
extern s32 func_004A6F58();
s32 func_004A7368(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001DFBEC == 0) return -1;
    if (a >= D_001D669C) return -1;
    r = func_004A6F58(D_001DFBEC + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_001A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_004A7368 */
