#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00419530(s32 a, s32 b);
extern f32 func_003F0B08(f32 *v);
extern void func_00425278(u8 *m, s32 a, s32 b);
extern f32 func_00423CE8(void);
extern f32 func_003F1060(f32 a, f32 b);
extern f32 func_003F0B38(f32 *v);
extern void func_003F1208(u8 *a, u8 *b);
extern void func_003F0860(void *d, void *s, s32 n);
extern void func_0041C980(u8 *m);
extern s32 D_001DD410;

u8 *func_00358938(u8 *a0, u8 *a1, f32 *a2, s32 a3, f32 f) {
    u8 *m;
    u8 *v;

    m = func_00419530(5959, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(u8 **)(m + 184) = a0;
        m[32] = 0;
        v = *(u8 **)(m + 104);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u128_t *)(m + 16) = *(u128_t *)a1;
        *(u128_t *)(v + 16) = *(u128_t *)a2;
        *(f32 *)(v + 8) = func_003F0B08(a2);
        *(f32 *)(v + 4) = f;
        if (a3 != 0) {
            *(f32 *)(v + 4) = -f;
        }
        func_00425278(m, 1, -1);
        *(s32 *)v = 100;
        *(f32 *)(m + 240) = func_00423CE8();
        *(f32 *)(m + 248) = func_003F1060(a2[0], a2[1]);
        *(f32 *)(m + 244) = -func_003F1060(func_003F0B38(a2), a2[2]);
        func_003F1208(m + 192, m + 240);
        *(f32 *)(m + 44) = *(f32 *)(*(u8 **)(m + 36) + 36) + *(f32 *)(*(u8 **)(m + 36) + 36);
        func_003F0860(v + 48, &D_001DD410, 16);
        func_0041C980(m);
    }
    return m;
}
