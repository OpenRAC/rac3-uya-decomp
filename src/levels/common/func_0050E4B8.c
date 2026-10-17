#include "common.h"
extern u8 D_001A4BE0[];
extern s32 func_00473938(s32 a0, u8 *a1, u8 *a2, f32 f);
void func_0050E4B8(void) {
    u8 *p = D_001A4BE0;
    if (func_00473938(*(s16 *)(p + 10374), p + 128, p + 128, *(f32 *)(p + 644))) {
        *(s16 *)(p + 534) = 4;
    }
}
