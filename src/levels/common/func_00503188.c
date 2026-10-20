#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 D_001A4BE0[];
extern f32 D_001EAAA0[];
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_003F8448(Vec4 *, Vec4 *, s32, s32, s32);

s32 func_00503188(void) {
    u8 *g = D_001A4BE0;
    Vec4 from;
    Vec4 to;
    f32 diff;

    if (g[9716] == 2) {
        return 0;
    }
    if (*(f32 *)(g + 372) < *(f32 *)(g + 644) / 20.0f) {
        return 0;
    }
    if (func_0040CFB0(func_0040C490(*(f32 *)(g + 272), *(f32 *)(g + 276)), *(f32 *)(g + 152)) > 0.5235988f) {
        return 0;
    }
    from.q = *(u128_t *)(g + 128);
    from.f[0] += func_0040C3C8(*(f32 *)(g + 152)) * (*(f32 *)(g + 644) * 0.75f);
    from.f[1] += func_0040C3E0(*(f32 *)(g + 152)) * (*(f32 *)(g + 644) * 0.75f);
    to.q = from.q;
    from.f[2] += 0.495f;
    to.f[2] -= 1.0f;
    if (func_003F8448(&from, &to, 2, *(s32 *)(g + 9664), 0) == 0) {
        return 0;
    }
    diff = D_001EAAA0[2] - *(f32 *)(g + 136);
    if (diff < 0.395f && diff > -1.0f) {
        return 1;
    }
    return 0;
}
