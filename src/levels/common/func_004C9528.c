#include "common.h"

typedef struct { f32 *p0; f32 *p4; u8 p8[4]; u32 *pC; f32 *p10; u8 p14[0x14]; f32 *p28; } S_62E8;
extern u8 D_001DB20C_003A62E8;
extern u32 D_001DB210_003A62E8;
extern s32 func_0041D880();
extern void func_0041DD68();
void func_004C9528(S_62E8 *a) {
    u32 loc[4];
    if (*a->p10 != 0.0f) {
        if (D_001DB20C_003A62E8 != 0) {
            *a->pC = (*a->pC & 0xFF000000) | (D_001DB210_003A62E8 & 0xFFFFFF);
        }
        loc[0] = *a->pC;
        loc[1] = *a->pC;
        loc[2] = *a->pC;
        loc[3] = *a->pC;
        func_0041DD68(func_0041D880((s32)a->p28[0], (s32)a->p28[1]), (s32)a->p0[0], (s32)a->p0[1], (s32)a->p4[0], (s32)a->p4[1], loc);
    }
}
