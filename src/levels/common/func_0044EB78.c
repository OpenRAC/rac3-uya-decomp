#include "common.h"
extern u8 D_001D5473[];
extern void func_0044B5C8(s32 a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_0044EB78(s32 a0, u8 *a1, s32 a2, s32 a3, f32 f12) {
    if (D_001D5473[0] != 0) {
        *(f32 *)(a1 + 112) = f12;
    } else {
        *(f32 *)(a1 + 112) = 1.0f;
    }
    if (a3 != 0 && *(f32 *)(a1 + 112) != *(f32 *)(a1 + 32)) {
        func_0044B5C8(a0, a1, a2, a3, 0.03f, 0.3f);
    }
}
