#include "common.h"

extern f32 D_001D920C;
extern void func_00493658(void);
extern void func_00493940(void);
extern void func_00494288(void *, s32, s32, s32, s32, s32, f32, f32);

void func_004935C8(s32 a, s32 b) {
    func_00494288(func_00493658, a, b, 1, 0, 1, 1.0f, D_001D920C);
    func_00494288(func_00493940, a, b, 1, 2, 0, 1.0f, D_001D920C);
}
