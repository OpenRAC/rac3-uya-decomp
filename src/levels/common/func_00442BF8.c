#include "common.h"
extern u8 *D_001E0294;
extern s32 D_001E00D8;
extern s16 *D_001E028C;
extern s16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern u16 D_001E0290;
s32 func_00442BF8(u8 **out, u8 *start, s32 a2, s32 a3) {
    s16 *p;
    s32 neg;
    s32 idx;
    *out = 0;
    if (start != D_001E0294) {
        if (D_001E00D8 < start[33]) {
            goto fail;
        }
        D_001E0294 = 0;
        D_001E028C = D_0021DEA0[start[33]];
        if (D_001E028C == 0) {
        fail:
            return -1;
        }
        D_001E028C = D_001E028C - 1;
        do {
            p = D_001E028C;
            D_001E028C = p + 1;
            idx = p[1] & 0x7FFF;
            D_001E0290 = idx;
            D_001E0294 = D_001E009C + (idx << 8);
            if (p[1] < 0) {
                goto fail;
            }
        } while (start != D_001E0294);
    } else if (*D_001E028C < 0) {
        goto fail;
    }
    do {
        p = D_001E028C;
        D_001E028C = p + 1;
        idx = p[1] & 0x7FFF;
        D_001E0290 = idx;
        D_001E0294 = D_001E009C + (idx << 8);
        *out = D_001E0294;
        neg = (s8)D_001E0294[32] < 0;
        if (!a2) {
            if (a3) {
                continue;
            }
            if (!neg) {
                goto ret0;
            }
        } else if (!a3 || neg) {
        ret0:
            return 0;
        }
    } while (*D_001E028C >= 0);
    *out = 0;
    return -1;
}
