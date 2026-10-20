#include "common.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    u8 bE;
    u8 bF;
} E_3F0118;

extern E_3F0118 D_001E2500[][8];

s32 func_003F0118(E_3F0118 *src, u8 *a1) {
    s32 idx = 0;
    s32 n;
    s32 cnt;
    s32 i;

    if (a1 != 0) {
        if (a1[1367] == 255) {
            return 0;
        }
        idx = a1[1356] * 4 + a1[1367];
    }
    for (n = 0; n < 8 && src[n].b0 != 255; n++) {
    }
    cnt = 0;
    for (i = 0; i < 8 && cnt < n; i++) {
        if (D_001E2500[idx][i].b0 == 0) {
            cnt++;
        }
    }
    if (cnt != n) {
        return -1;
    }
    for (cnt = 0; cnt < n; cnt++) {
        for (i = 0; i < 8; i++) {
            if (D_001E2500[idx][i].b0 == 0) {
                break;
            }
        }
        if (i < 8) {
            D_001E2500[idx][i].b0 = src[cnt].b0;
            D_001E2500[idx][i].b1 = src[cnt].b1;
            D_001E2500[idx][i].b2 = src[cnt].b2;
            D_001E2500[idx][i].b3 = src[cnt].b3;
            D_001E2500[idx][i].h4 = src[cnt].h4;
            D_001E2500[idx][i].h6 = src[cnt].h6;
            D_001E2500[idx][i].h8 = src[cnt].h8;
            D_001E2500[idx][i].hA = src[cnt].hA;
            D_001E2500[idx][i].hC = src[cnt].hC;
            D_001E2500[idx][i].bE = src[cnt].bE - src[cnt].bF;
            D_001E2500[idx][i].bF = src[cnt].bF;
            if (D_001E2500[idx][i].hA + D_001E2500[idx][i].hC == 0) {
                D_001E2500[idx][i].hA++;
            }
        }
    }
    return i;
}
