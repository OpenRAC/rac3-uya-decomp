#include "common.h"

typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_0041AA38;
extern s32 D_001DFDE0[4] __attribute__((section(".sdata")));
extern s32 *D_001DFDE8[4] __attribute__((section(".sdata")));
extern s32 D_001D68A0;
extern s32 D_001D680C;
extern s32 D_001D4C60[4] __attribute__((section(".sdata")));
extern s32 D_001D4C80[4] __attribute__((section(".sdata")));
extern u8 D_001425C0[];
extern S_38F310 D_002C5640_0038F310[];
extern D_0041AA38 D_002E5FC0[];
void func_0041AA38(s32 a) {
    s32 *p;
    s32 i;
    s32 v;
    s32 k;
    S_38F310 *t;
    D_001DFDE0[0] = 8;
    D_001DFDE8[0] = &D_001D68A0;
    D_001D680C = 0;
    p = a ? D_001D4C80 : D_001D4C60;
    for (i = 0; i < 8; i++) {
        k = D_001425C0[p[i]];
        t = D_002C5640_0038F310;
        v = t[k].h38;
        D_002E5FC0[i].w0 = v;
        D_002E5FC0[i].w18 = p[i];
    }
}
