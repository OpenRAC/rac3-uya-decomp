#include "common.h"

typedef struct { u8 pad[28]; u8 *p; } E_3EAB98;
extern E_3EAB98 *D_001DF884;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];
extern u8 *D_0021F740[];
extern s32 func_00440760(void *, s32, s32);
extern s32 func_00448D50(void *, s32);
extern s32 func_00448E00(void *, s32);
extern s32 func_004432C0(void *, u8 *, s32);

s32 func_003EAB98(u8 *m) {
    u8 *d = D_001DF884[*(s16 *)(m + 0x84)].p;
    u8 *p;

    if (*(s32 *)(d + 160) != -1) {
        if (D_001BBC40[D_001D545C][*(s32 *)(d + 160)] & 0x80) {
            return 0;
        }
    }
    if (*(s32 *)(d + 12) >= 0) {
        if (func_00440760(D_001A4C60, *(s32 *)(d + 12), 0)) {
            return 1;
        }
    } else if (*(s32 *)(d + 16) >= 0) {
        if (func_00448D50(D_001A4C60, *(s32 *)(d + 16))) {
            return 1;
        }
    } else if (*(s32 *)(d + 8) >= 0) {
        if (func_00448E00(D_001A4C60, *(s32 *)(d + 8))) {
            return 1;
        }
    } else if (*(s32 *)(d + 20) >= 0) {
        p = D_0021F740[*(s32 *)(d + 20)];
        if (func_004432C0(D_001A4C60, p + 16, *(s32 *)p)) {
            return 1;
        }
    } else {
        if (d[56] != 0 && d[57] == 0) {
            return 1;
        }
    }
    return 0;
}
