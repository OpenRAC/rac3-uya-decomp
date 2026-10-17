#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 D_001A4EC0[];
extern u8 *func_00435E70(s32, s32);
extern void func_0040C0F0(u8 *, Vec4 *, f32);
extern void func_0040BF20(u8 *, u8 *, u8 *);

u8 *func_003A7568(u8 *parent, Vec4 *a1, Vec4 *a2, f32 scale)
{
    Vec4 pos;
    Vec4 rot;
    u8 *m;
    Vec4 *rp = &rot;

    pos = *a1;
    rot = *a2;
    m = func_00435E70(6387, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        m[32] = 0;
        *(u8 **)(m + 184) = parent;
        *(u128_t *)(m + 16) = pos.q;
        *(u16 *)(m + 52) |= 0x100;
        *(f32 *)(*(u8 **)(m + 104) + 16) = scale;
        *(f32 *)(m + 28) = scale;
        if (rp->f[0] != 0.0f || rp->f[1] != 0.0f || rp->f[2] != 0.0f) {
            func_0040C0F0(m + 192, rp, 1.0f);
            func_0040BF20(m + 208, m + 192, D_001A4EC0);
            func_0040C0F0(m + 208, (Vec4 *)(m + 208), 1.0f);
            func_0040BF20(m + 224, m + 208, m + 192);
        } else {
            *(u128_t *)(m + 192) = *(u128_t *)(parent + 192);
            *(u128_t *)(m + 208) = *(u128_t *)(parent + 208);
            *(u128_t *)(m + 224) = *(u128_t *)(parent + 224);
        }
    }
    return m;
}
