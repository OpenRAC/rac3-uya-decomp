#include "common.h"

extern f32 D_001D923C;
extern void func_00493D40(void);
extern void func_00493E40(void);
extern void func_00494288(void *, s32, s32, s32, s32, s32, f32, f32);

void func_00493CB0(s32 a, s32 b) {
    func_00494288(func_00493D40, a, b, 1, 0, 1, 1.0f, D_001D923C);
    func_00494288(func_00493E40, a, b, 1, 2, 1, 1.0f, D_001D923C);
}
