#include "common.h"

/* localdecomp:start func_00442B10 */
extern s32 D_001E00D8;
extern u8 *D_001E009C;
extern u16 *D_0021DEA0[];
extern u16 *D_001E028C;
extern s16 D_001E0290;
extern s8 *D_001E0294;
extern s8 *D_001E0294_00442B10;
extern s32 func_00442BF8(s8 **, s8 *);
s32 func_00442B10(s8 **out, s32 idx, s32 a, s32 b) {
    u16 *p;
    s32 v, w;
    if (idx < 0 || D_001E00D8 < idx) {
        *out = 0;
        return -1;
    }
    *out = 0;
    D_001E0294 = 0;
    p = D_0021DEA0[idx];
    D_001E028C = p;
    if (p == 0) {
        return -1;
    }
    v = *p & 0x7FFF;
    D_001E0290 = v;
    D_001E0294 = (s8 *)(D_001E009C + (v << 8));
    *out = D_001E0294;
    w = (u32)(s32)D_001E0294[0x20] >> 31;
    if (a == 0) {
        if (b != 0 || w != 0) {
            return func_00442BF8(out, D_001E0294_00442B10);
        }
    } else if (b != 0 && w == 0) {
        return func_00442BF8(out, D_001E0294_00442B10);
    }
    return 0;
}
/* localdecomp:end func_00442B10 */
