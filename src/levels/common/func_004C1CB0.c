#include "common.h"

extern void func_004C1CB0();
extern s32 D_001E10F0;
extern s32 D_001D66A4;
extern s32 D_001E10F4;
extern s32 D_001D66A8;
extern s32 D_001DFBF0;
extern s32 D_001DFBF4;
extern s32 D_001DFBF8;

extern s32 D_001D66A4;
extern s32 D_001D66A8;
extern s32 D_001DFBF0;
extern s32 D_001DFBF4;
extern s32 D_001DFBF8;
extern u8 D_001E10E0_003A3C00[];
extern s32 D_001E10E8;
extern s32 D_001E10F0;
extern s32 D_001E10F4;

void func_004C1CB0(void) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_v1;

    temp_a2 = 1 - D_001E10F4;
    temp_t0 = *(s32 *)(D_001E10E0_003A3C00 + (temp_a2 * 4));
    temp_v1 = (temp_t0 + D_001E10F0) & 0xFFFFE000;
    D_001E10F4 = temp_a2;
    temp_a0 = temp_v1 - D_001D66A4;
    D_001E10E8 = temp_t0;
    D_001DFBF4 = temp_v1 - D_001D66A8;
    D_001DFBF8 = temp_a0 - 0x2000;
    D_001DFBF0 = temp_a0;
}
