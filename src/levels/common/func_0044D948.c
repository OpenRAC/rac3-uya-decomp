#include "common.h"
extern u8 *D_001DFD00[];
extern void func_0044D878(u8 *a0, u8 *a1, s32 a2, s32 a3, u8 *t0, u8 *t1);
void func_0044D948(u8 *a0, s32 a1, s32 a2, s32 a3) {
    if (a3 != -1) {
        u8 *t = D_001DFD00[0] + (a3 << 7);
        func_0044D878(a0 + 16, a0 + 240, a1, a2, t + 48, t + 112);
    }
}
