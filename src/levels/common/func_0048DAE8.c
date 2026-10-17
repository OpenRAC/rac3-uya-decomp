#include "common.h"
extern s32 D_00143950[];
extern void func_004A7368(s32, s32, s32);
void func_0048DAE8(s32 a0) {
    if (a0 & 0x8000) {
        s32 v = D_00143950[4] - 30;
        D_00143950[4] = (v < 0) ? 0 : v;
    } else if (a0 & 0x2000) {
        s32 v = D_00143950[4] + 30;
        D_00143950[4] = (v > 1024) ? 1024 : v;
    }
    func_004A7368(3, 0, 0);
}
