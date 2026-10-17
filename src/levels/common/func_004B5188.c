#include "common.h"

extern s32 D_001D4D40;

extern s32 D_001425AC[];
extern s16 D_0016C5A8[];
extern s32 D_001D4D40;
extern void func_00417DA0(s32, s32);
void func_004B5188(void) {
    D_001D4D40 = 1;
    D_0016C5A8[0] = 1;
    D_001425AC[0] = 1;
    func_00417DA0(1, 1);
}
