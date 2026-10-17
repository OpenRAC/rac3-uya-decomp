#include "common.h"

extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
void func_00440B30(s32 a, f32 x, f32 y) {
    f32 p = func_00440978();
    f32 q = func_00440978();
    func_00440CF8(a, func_004408C0(x, y), p, q);
}
