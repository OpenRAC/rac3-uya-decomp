#include "common.h"

extern void func_00354820(void *, s32, s32, void *, f32);

void func_00354758(u8 *a) {
    u8 *v = *(u8 **)(a + 104);
    func_00354820(a + 16, *(s32 *)(v + 64), *(s32 *)(v + 68), a, *(f32 *)(a + 44) * 90.0f);
}
