#include "common.h"
extern void func_0044DB68(s32 a0, f32 *a1, f32 f12, f32 f13, f32 f14);
extern void func_003D41E8(s32 a0, f32 *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2,
                          f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);
void func_003D46A8(s32 a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13) {
    f32 v[4];
    func_0044DB68(a0, v, 0.35f, 0.0f, f13);
    func_003D41E8(a0, v, a3, 1, a1, a2, 1, 0.2f, 1.0f, 0.0033333336f, f12, 0.0f);
}
