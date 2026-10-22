#include "common.h"

typedef int Q_003B8E88 __attribute__((mode(TI)));

extern f32 func_0041C8F0(void *a, void *b);
extern f32 func_00452500(void *a, s32 b, s32 c, f32 f);
extern f32 func_00452680(void *a);
extern s32 D_001D545C;
extern Q_003B8E88 D_001D66B0[];

void func_003B8E88(u8 *a0, u8 *a1) {
    void *p;
    f32 d;
    f32 lim;
    f32 v;
    s32 k;

    p = a0 + 0x10;
    if (func_0041C8F0(p, a1 + 0x90) < 0.001f) {
        return;
    }
    if (*(f32 *)(a0 + 0xF0) == 3.1415927f) {
        d = *(f32 *)(a0 + 0x18) - func_00452680(p) - *(f32 *)(a1 + 8);
    } else {
        d = func_00452500(p, 0, 0, 0.5f) - *(f32 *)(a0 + 0x18) - *(f32 *)(a1 + 8);
    }
    lim = 3.0f;
    if (d > lim) {
        d = lim;
    } else {
        lim = -3.0f;
        if (d < lim) {
            d = lim;
        }
    }
    v = d * (1024.0f / *(f32 *)(a0 + 0x2C));
    k = D_001D545C;
    *(f32 *)(a1 + 0xC) = v;
    *(f32 *)(a1 + 0x88) = v;
    if (k == 0xB) {
        *(f32 *)(a1 + 0x88) = 0.0f;
        *(Q_003B8E88 *)(a1 + 0x70) = D_001D66B0[0];
    }
    *(Q_003B8E88 *)(a1 + 0x90) = *(Q_003B8E88 *)(a0 + 0x10);
}
