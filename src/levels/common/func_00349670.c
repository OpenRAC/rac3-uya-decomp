#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 D_001DD058;
extern s32 D_001DD05C;
extern f32 D_001DD060;
extern s32 D_001DD064;
extern f32 D_001DD068;
extern f32 D_001DD06C;
extern f32 D_001DD070;
extern f32 D_001DD074;
extern f32 D_001DD0C8;
extern f32 func_0041F838(f32, f32);
extern s32 func_0041F7F0(s32, s32);
extern void func_003EC6B8(Vec4 *, Vec4 *, f32);
extern s32 func_003491E8(s32, s32);
extern void func_00444670(Vec4 *, Vec4 *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_00349670(u8 *m) {
    Vec4 v;
    Vec4 w;
    u8 *pv;
    s32 c;
    s32 r;

    pv = *(u8 **)(m + 104);
    *(f32 *)(pv + 28) += D_001DD068;
    while (*(f32 *)(pv + 28) > 1.0f) {
        *(f32 *)(pv + 28) -= 1.0f;
        v.q = *(u128_t *)(m + 16);
        v.f[0] += func_0041F838(-D_001DD0C8, 0.0f);
        v.f[2] += func_0041F838(-D_001DD06C, D_001DD06C);
        w.q = *(u128_t *)pv;
        func_003EC6B8(&w, &w, D_001DD074);
        c = func_003491E8(D_001DD058, D_001DD05C);
        r = func_0041F7F0(-4, 4);
        func_00444670(&v, &w, D_001DD064, D_001DD070, c, r, 128, 0, 0.0f, func_0041F838(-D_001DD060, D_001DD060), 0);
    }
}
