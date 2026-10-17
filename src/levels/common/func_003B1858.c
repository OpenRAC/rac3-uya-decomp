#include "common.h"
extern s32 D_001DE670;
extern s32 D_001DE674;
extern s32 D_001DE678;
extern s32 D_001DE67C;
extern s32 D_001DE680;
extern s32 D_001DE684;
extern s32 D_001DE688;
extern void func_00441FB8(u8 *, s32, s32);
void func_003B1858(u8 *a0) {
    D_001DE670 = 0;
    D_001DE674 = 0;
    D_001DE678 = 0;
    D_001DE67C = 0;
    D_001DE680 = 0;
    D_001DE684 = 0;
    D_001DE688 = 0;
    a0[48] = 255;
    func_00441FB8(a0, 1, -1);
}
