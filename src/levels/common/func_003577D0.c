#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00419530(s32 a, s32 b);
extern s32 func_0048A5B8(s32 a, s32 b, u8 *m);
extern void func_0041C980(u8 *m);
extern u8 D_001A30B0[];

u8 *func_003577D0(u8 *a0, u128_t *a1, u128_t *a2, u128_t *a3, s32 a4, s32 a5, f32 f) {
    u8 *m;
    u8 *v;
    s32 idx;
    u8 *e;

    m = func_00419530(5790, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        m[32] = 0;
        v = *(u8 **)(m + 104);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u128_t *)(m + 16) = *a2;
        *(u128_t *)(m + 240) = *a3;
        *(u8 **)(m + 184) = a0;
        *(u128_t *)v = *a1;
        *(u8 **)(v + 16) = a0;
        *(f32 *)(v + 20) = f;
        *(f32 *)(v + 32) = 0.15f;
        *(s32 *)(v + 44) = a4;
        *(s32 *)(v + 52) = a5;
        *(f32 *)(m + 44) = *(f32 *)(*(u8 **)(m + 36) + 36) + *(f32 *)(*(u8 **)(m + 36) + 36);
        idx = *(s32 *)(v + 48);
        if (idx == -1 || (e = D_001A30B0 + idx * 128, *(u8 **)(e + 220) != m) || e[208] == 0) {
            *(s32 *)(v + 48) = func_0048A5B8(0, 4, m);
        }
        *(s32 *)(v + 36) = 0;
        func_0041C980(m);
    }
    *(s32 *)(m + 152) = 0;
    return m;
}
