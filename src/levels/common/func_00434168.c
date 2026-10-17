#include "common.h"
extern s32 D_001A5FC0[];
extern s32 D_001A6C00[];
extern void func_00474F30(u8 *a0);
extern s32 func_0053D850(u8 *a0, s32 a1, s32 a2);
extern void func_0047F900(u8 *a0, s32 a1, s32 a2);
void func_00434168(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        if (D_001A5FC0[0] != 0 || D_001A6C00[0] == 0) {
            func_00474F30(a0);
        } else {
            func_0053D850(a0, -1, 1);
            a0[48] = 16;
            *(s16 *)(s1 + 30) = 160;
            *(s16 *)(s1 + 28) = -3;
            func_0047F900(a0, 1, -1);
        }
    }
}
