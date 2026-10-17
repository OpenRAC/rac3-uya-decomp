#include "common.h"

extern s32 D_001E1F9C[];
extern void func_0038BA90(u8 *, s32, s32, f32, f32, f32, f32);

void func_0038BA40(u8 *obj) {
    func_0038BA90(obj + 16, 66, D_001E1F9C[0] * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
