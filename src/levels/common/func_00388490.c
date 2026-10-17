#include "common.h"
extern s32 D_001E1F20[];
extern void func_00388508(u8 *a0, s32 a1, s32 a2, f32 f12, f32 f13, f32 f14, f32 f15);
void func_00388490(u8 *a0) {
    func_00388508(*(u8 **)(a0 + 104) + 16, 66, D_001E1F20[0] * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
