#include "common.h"
extern s32 D_001D8590;
extern s32 D_001D858C;
extern f32 D_001D85B4;
extern f32 D_001D85B8;
extern f32 D_001D85BC;
extern f32 D_001D85C0;
extern void func_00512480(s32 a0, f32 a1, f32 a2);
void func_004822B8(void) {
    f32 b;
    if (D_001D8590 == 0) b = D_001D85BC; else b = D_001D85C0;
    func_00512480(0xE000B, D_001D85B4 + (f32)D_001D858C * D_001D85B8, b);
}
