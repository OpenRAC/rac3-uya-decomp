#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 D_001D673C;
extern u8 *func_00435E70(s32, s32);
extern void func_004475D0(u8 *);
extern void func_00438908(u8 *, s32, s32, s32);
extern f32 func_00440978(void);
extern void func_0044DF40(u8 *, Vec4 *, s32);
extern void func_0044E358(u8 *, Vec4 *, Vec4 *);
extern void func_00447748(u8 *, u8 *);
extern void func_00439610(u8 *);

u8 *func_003013B0(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13) {
    Vec4 v;
    Vec4 mt[3];
    u8 *m;
    u8 *pv;

    m = func_00435E70(775, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        func_004475D0(m);
        func_00438908(m, 40, 40, 70);
        m[48] = 255;
        *(s16 *)(m + 50) = 64;
        *(f32 *)(m + 44) *= scale;
        *(f32 *)pv = f13;
        pv[4] = type;
        *(u128_t *)(m + 16) = pos->q;
        *(f32 *)(m + 248) = func_00440978();
        if (dir->f[0] != 0.0f && dir->f[1] != 0.0f && dir->f[2] != 0.0f) {
            *(u128_t *)(m + 240) = dir->q;
        } else if (D_001D673C != 0) {
            func_0044DF40(m + 16, &v, 0);
            func_0044E358(m + 192, &v, mt);
            func_00447748(m + 192, m + 240);
        }
        func_00439610(m);
    }
    return m;
}
