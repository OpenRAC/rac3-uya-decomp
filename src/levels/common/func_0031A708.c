#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 D_001A4BE0[];
extern s32 D_001DF71C;

extern void func_003C0D80(Vec4 *a, Vec4 *b, u8 *moby, f32 f);
extern void func_004B76F8(s32 a, s32 b, u8 *moby);
extern void func_004140C0(u8 *moby, s32 a, s32 b);

void func_0031A708(u8 *moby) {
    Vec4 a;
    Vec4 b;
    s32 *pvars = *(s32 **)(moby + 104);
    u8 *base;
    if (moby[32] != 0) {
        return;
    }
    a.q = 0;
    b.q = 0;
    a.f[2] = 1.0f;
    a.f[3] = 1.0f;
    b.f[1] = 1.0f;
    b.f[3] = 1.0f;
    func_003C0D80(&a, &b, moby, 15.0f);
    func_004B76F8(5, 154, moby);
    base = D_001A4BE0;
    *(s32 *)(base + 6912) = D_001DF71C + (pvars[0] << 8);
    *(s32 *)(base + 6916) = 0;
    *(s32 *)(base + 6920) = 0;
    func_004140C0(moby, 1, -1);
}
