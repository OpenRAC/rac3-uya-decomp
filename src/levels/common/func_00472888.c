#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

extern u8 D_001E2900[];
extern u8 D_001A4BE0[];
extern u8 *D_00221174[];
extern void func_004C6EC8(void *, void *);
extern u32 func_0040D020(f32, u32, u32);
extern f32 func_0040C490(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440878(s32, s32);
extern u8 *func_0046DCB8(Vec4 *, Vec4 *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);

/* localdecomp:start func_00472888 */
void func_00472888(u8 *o) {
    u8 *s;
    Vec4 pos;
    Vec4 vel;
    f32 ang;
    f32 a;
    u8 *r;
    s32 n;

    s = o + 32;
    func_004C6EC8(o + 16, o + 16);
    if (s[28] == 0) {
        *(u32 *)(o + 4) = func_0040D020((f32)*(s16 *)(o + 10) * *(f32 *)(s + 16), 0x4FBF2323, 0x4F202020);
    } else if (s[28] == 1) {
        if (*(f32 *)(o + 24) > *(f32 *)(s + 20)) {
            __asm__ __volatile__(
                "lqc2 $vf1, 16(%0)\n"
                "lqc2 $vf2, 32(%1)\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 16(%0)\n"
                : : "r"(o), "r"(o) : "memory");
            *(f32 *)(s + 8) -= *(f32 *)(s + 12);
        } else if (s[29] != 0) {
            u8 *g = D_001A4BE0;
            u8 *e = D_001E2900;
            ang = func_0040C490(*(f32 *)(g + 128) - *(f32 *)(e + 320),
                                *(f32 *)(g + 132) - *(f32 *)(e + 324));
            func_00440918(1.0f, 2.0f);
            pos.x = *(f32 *)(o + 16) + func_00440918(0.0f, 0.15f);
            pos.y = *(f32 *)(o + 20) + func_00440918(0.0f, 0.15f);
            pos.z = *(f32 *)(o + 24) + 0.1f;
            a = func_0040CEC8(ang, func_00440918(0.0f, -6.2831855f));
            vel.x = func_0040C3C8(a) * (1.0f / 30.0f);
            vel.y = func_0040C3E0(a) * (1.0f / 30.0f);
            vel.z = 0.0f;
            {
            Vec4 *pv = &vel;
            n = func_00440878(10, 30);
            r = func_0046DCB8(&pos, pv, n, 0x303030, func_00440878(-2, -4), 127, 0, 0, 189000.0f, 84000.0f, 0.0f);
            }
            if (r != 0) {
                r[2] = *D_00221174[0];
                r[3] = 72;
            }
            s[29] = 0;
        }
    } else if (s[28] == 2) {
        *(u32 *)(o + 4) = func_0040D020((f32)*(s16 *)(o + 10) * *(f32 *)(s + 16), 0x232323, 0x7F232323);
    }
    if (func_0040BAC0(o + 10) && s[28] == 0) {
        s[28] = 1;
        *(s16 *)(o + 10) = 300;
    } else if (func_0040BAC0(o + 10) && s[28] == 1) {
        s[28] = 2;
        *(s16 *)(o + 10) = 150;
        *(f32 *)(s + 16) = 1.0f / 150.0f;
    } else if (func_0040BAC0(o + 10) && s[28] == 2) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00472888 */
