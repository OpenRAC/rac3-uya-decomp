#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;
extern f32 D_001DEA04;
extern f32 D_001DEA08;
extern f32 D_001DEA0C;
extern f32 D_001DEA10;
extern void func_003DF8F8(Vec4 *, void *, f32);
extern void func_0041F7B0(f32, f32, f32, f32, u8 *, s32, Vec4 *, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
void func_003A0010(u8 *a0) {
    Vec4 v;
    func_003DF8F8(&v, *(void **)(a0 + 104), 0.75f);
    func_0041F7B0(D_001DEA04, D_001DEA08, D_001DEA0C, D_001DEA10, a0, 7, &v, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
}
