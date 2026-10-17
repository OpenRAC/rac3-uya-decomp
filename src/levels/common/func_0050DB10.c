#include "common.h"
extern u8 D_001A4BE0[];
extern void func_004FC518(s32, s32);
void func_0050DB10(void) {
    u8 *p = D_001A4BE0;
    if (*(f32 *)(p + 368) < 0.045f || *(s32 *)(p + 9668) == 105) {
        func_004FC518(0, 1);
    } else {
        func_004FC518(3, 1);
    }
}
