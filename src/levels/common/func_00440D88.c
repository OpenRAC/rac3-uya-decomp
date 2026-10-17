#include "common.h"
typedef struct {
    u8 pad0[10];
    u8 bA;
    u8 padB;
    u8 bC;
    u8 bD;
    u8 padE[24 - 14];
    s32 w18;
    s32 w1C;
    u8 pad20[40 - 32];
    s32 w28;
    u8 pad2C[72 - 44];
    s32 a48[1];
} S_440D88;
extern u8 D_001FDC50[];
extern S_440D88 *D_001FD200[];
void func_00440D88(s32 a0, s32 a1) {
    S_440D88 *src;
    S_440D88 *dst;
    s32 i;
    if (a0 == a1) {
        return;
    }
    src = D_001FD200[D_001FDC50[a1]];
    dst = D_001FD200[D_001FDC50[a0]];
    dst->bC = src->bC;
    dst->bA = src->bA;
    dst->bD = src->bD;
    dst->w18 = src->w18;
    dst->w1C = src->w1C;
    dst->w28 = src->w28;
    for (i = 0; i < src->bC; i++) {
        dst->a48[i] = src->a48[i];
    }
}
