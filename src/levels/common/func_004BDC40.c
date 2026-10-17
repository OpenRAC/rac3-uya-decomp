#include "common.h"
extern s32 D_001E0FB8[];
extern s32 D_001E0FBC[];
extern s32 D_001E0FC0[];
extern s32 D_001E0FC4[];
extern s32 D_001E0FC8[];
extern s32 D_001E0FCC[];
extern f32 D_001E0FDC[];
extern s32 D_001E0FE0[];
void func_004BDC40(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f) {
    D_001E0FB8[0] = a0;
    D_001E0FC0[0] = a2;
    D_001E0FC4[0] = a3;
    D_001E0FC8[0] = t0;
    D_001E0FCC[0] = t1;
    D_001E0FBC[0] = a1;
    D_001E0FDC[0] = f;
    D_001E0FE0[0] = 1;
}
