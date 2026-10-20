#include "common.h"

extern void func_0040BE68(f32 *, f32 *, f32 *, f32);
extern void func_0040BE90(f32 *, f32 *, f32);
extern f32 D_001DFAE0[];
extern f32 D_001DFAE4[];
extern f32 D_001DFAE8[];

void func_00408B60(f32 *dir, f32 *a, f32 *b, f32 *p, f32 lo, f32 hi) {
    s32 i;
    f32 va[4];
    f32 vb[4];
    f32 t;

    for (i = 0; i < 4; i++) {
        func_0040BE68(va, a, b, p[i * 2]);
        t = p[i * 2 + 1] - 0.5f;
        func_0040BE90(vb, dir, (lo + (hi - lo) * p[i * 2]) * (t + t));
        D_001DFAE0[i * 3] = va[0] + vb[0];
        D_001DFAE4[i * 3] = va[1] + vb[1];
        D_001DFAE8[i * 3] = va[2] + vb[2];
    }
}
