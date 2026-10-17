#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_0040C9B0(s32 a, s32 b);
extern void func_004237A0(u8 *m, s32 a);
extern void func_004193D8(u8 *m, s32 a);
extern void func_0040FF68(u8 *m);
extern f32 func_004170F0(f32 a, f32 b);
extern f32 func_003E4FC0(f32 a);
extern void func_00418738(u8 *m, s32 a, s32 b);

u8 *func_003AA7E8(u128_t *a0, u128_t *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 scale, f32 f1, f32 f2, f32 f3) {
    u8 *m;
    u8 *v;

    m = func_0040C9B0(6948, 80);
    if (m != 0) {
        func_004237A0(m, 0);
        if (a2 >= 0) {
            func_004193D8(m, a2);
        }
        *(u128_t *)(m + 16) = *a0;
        func_0040FF68(m);
        *(u16 *)(m + 52) &= ~5;
        *(f32 *)(m + 244) = func_003E4FC0(func_004170F0(0.0f, 6.2831855f));
        v = *(u8 **)(m + 104);
        *(f32 *)(m + 44) = scale * *(f32 *)(*(u8 **)(m + 36) + 36);
        *(u128_t *)v = *a1;
        *(s32 *)(v + 16) = a3;
        *(f32 *)(v + 24) = f1;
        *(s32 *)(v + 28) = a4;
        *(s32 *)(v + 32) = a5;
        *(f32 *)(v + 36) = f2;
        *(f32 *)(v + 40) = f3;
        *(s32 *)(v + 60) = -1;
        *(s32 *)(m + 152) = 0;
        func_00418738(m, 0, -1);
        return m;
    }
    return 0;
}
