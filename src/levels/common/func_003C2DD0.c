#include "common.h"

/* localdecomp:start func_003C2DD0 */
typedef struct {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 pad18[0x14];
    s16 f2C;
    s16 f2E;
    u8 pad30[0x1C];
    s32 f4C;
} D_3C2DD0;
typedef struct {
    u8 pad0[0x1C];
    D_3C2DD0 *p;
} E_3C2DD0;
typedef struct {
    u8 pad0[0x50];
    u8 *f50;
    u8 pad54[0x460 - 0x54];
} M_3C2DD0;
extern E_3C2DD0 *D_001DE204;
extern M_3C2DD0 D_001E1380[];
extern s32 D_001A71AC[];
extern s32 D_001A73EC[];
extern u8 D_001A4C60[];
extern s32 *D_0021C780[];
extern s32 func_004181C8(void *, s32, s32);
extern s32 func_00420480(void *, s32);
extern s32 func_00420530(void *, s32);
extern s32 func_0041AA18(void *, void *, s32);
s32 func_003C2DD0(u8 *o) {
    D_3C2DD0 *d = D_001DE204[*(s16 *)(o + 0x84)].p;
    s32 flag = 0;
    s32 *t;
    if (*(s16 *)(((M_3C2DD0 *)((u8 *)D_001E1380 + *(s32 *)(o + 0x94) * 0x460))->f50 + 0x86) != 0) {
        return 0;
    }
    if (d->f2C == 2 && D_001A71AC[0] == 0x1A && d->f2E > 0) {
        flag = 1;
    } else if (d->f2C == 4 && D_001A73EC[0] == 3) {
        flag = d->f2E > 0;
    }
    if (d->fC >= 0) {
        if (flag || func_004181C8(D_001A4C60, d->fC, 0)) {
            return 1;
        }
    }
    if (d->f4C >= 0) {
        if (flag || func_004181C8(D_001A4C60, d->f4C, 0)) {
            return 1;
        }
    }
    if (d->f10 >= 0) {
        if (flag || func_00420480(D_001A4C60, d->f10)) {
            return 1;
        }
    }
    if (d->f8 >= 0) {
        if (flag || func_00420530(D_001A4C60, d->f8)) {
            return 1;
        }
    }
    if (d->f14 >= 0) {
        if (flag || func_0041AA18(D_001A4C60, D_0021C780[d->f14] + 4, *D_0021C780[d->f14])) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003C2DD0 */
