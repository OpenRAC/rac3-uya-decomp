#include "common.h"

extern s32 D_001E10F0;
extern s32 D_001D66A4;
extern void func_004C1C00(void);

extern s32 D_001E10F4;
extern s32 D_001E10E0[];
extern s32 D_001E10F0;
extern s32 D_001D66A4;
extern s32 D_001D66A8;
extern s32 D_001DFBF0;
extern s32 D_001DFBF4;
extern s32 D_001DFBF8;
void func_004C1C00(void) {
    u32 t = (D_001E10E0[D_001E10F4] + D_001E10F0) & 0xFFFFE000;
    s32 a = t - D_001D66A4;
    D_001DFBF4 = t - D_001D66A8;
    D_001DFBF8 = a - 0x2000;
    D_001DFBF0 = a;
}
