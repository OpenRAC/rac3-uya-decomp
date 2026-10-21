#include "common.h"

/* localdecomp:start func_004ED860 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_4ED860;
typedef struct {
    f32 f0;
    f32 f4;
    s32 w8;
} K_4ED860;
typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x14 - 0x8];
    K_4ED860 *p14;
    s32 w18;
    s32 w1C;
    f32 f20;
} S_4ED860;
typedef struct {
    u8 pad0[0xF0];
    V4_4ED860 vF0;
    u8 pad100[0x1B8 - 0x100];
    s32 w1B8;
    u8 pad1BC[0x400 - 0x1BC];
    S_4ED860 s400;
    u8 pad424[0x46C - 0x424];
    u8 b46C;
    u8 b46D;
    u8 b46E;
    u8 pad46F;
    f32 f470;
    u8 pad474[4];
    f32 f478;
    s16 h47C;
    u8 pad47E[2];
    f32 f480;
    f32 f484;
    u8 pad488[0x4D8 - 0x488];
    f32 f4D8;
    f32 f4DC;
    u8 pad4E0[0x4E8 - 0x4E0];
    s16 h4E8;
    u8 pad4EA[0x4F0 - 0x4EA];
    f32 f4F0;
    u8 pad4F4[0x25C0 - 0x4F4];
    s32 w25C0;
    s32 w25C4;
    u8 pad25C8[0x279C - 0x25C8];
    s32 w279C;
    u8 pad27A0[0x2884 - 0x27A0];
    s16 h2884;
} G_4ED860;
typedef struct {
    u8 pad0[0x50];
    u8 b50;
    u8 pad51[0x5C - 0x51];
    s32 w5C;
    u8 pad60[0x80 - 0x60];
} E_4ED860;
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xDC - 0xD1];
    s32 wDC;
} F_4ED860;
typedef struct {
    u8 pad0[0x1A0];
    s32 w1A0;
} P_4ED860;

extern G_4ED860 D_001A4BE0;
extern V4_4ED860 D_001A4C60;
extern V4_4ED860 D_001A4CD0;
extern u8 D_00142CA2[];
extern E_4ED860 D_001A30B0[];
extern P_4ED860 *D_001D52FC;

extern void func_0050D530(void *, void *, f32);
extern void func_0050CF30(void *, void *, f32);
extern f32 func_0050D4D8(void *);
extern s32 func_004E5470(s32);
extern void func_004F1110(s32, s32, s32);
extern void func_004A6E88(s32);
extern void func_0050D110(void *, f32, f32, f32, s32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern void func_004450C0(f32 *, f32, f32);
extern s32 func_0045E3B8(s32, s32);
extern void func_0050D2A8(void *, void *, f32);

void func_004ED860(void) {
    V4_4ED860 diff;
    V4_4ED860 b;
    V4_4ED860 a;
    f32 len;
    s32 st;

    st = D_001A4BE0.w25C4;
    if (!(st == 27 && D_001A4BE0.w1B8 < 4) && !(st == 72 && D_001A4BE0.w1B8 < 13)) {
        if (D_001A4BE0.w1B8 < D_001A4BE0.h47C) {
            func_0050D530(&D_001A4BE0.vF0, &D_001A4BE0.vF0, 0.0f);
            func_0050CF30(&D_001A4BE0.vF0, &D_001A4BE0.vF0, 0.013333334f);
        } else if (D_001A4BE0.b46C != 0) {
            func_0050D530(&D_001A4BE0.vF0, &D_001A4BE0.vF0, 0.0f);
            func_0050CF30(&D_001A4BE0.vF0, &D_001A4BE0.vF0, 0.015000001f);
        } else {
            f32 l;
            func_0050CF30(&D_001A4BE0.vF0, &D_001A4BE0.vF0, D_001A4BE0.f4F0);
            l = func_0050D4D8(&D_001A4BE0.vF0);
            if (l < -D_001A4BE0.f470) {
                l = -D_001A4BE0.f470;
            }
            func_0050D530(&D_001A4BE0.vF0, &D_001A4BE0.vF0, l);
        }
    }
    if (D_001A4BE0.w25C4 == 14) {
        f32 spd = 0.116666675f;
        s32 flag = 0;
        f32 dist;
        V4_4ED860 *p;
        if (D_00142CA2[0] != 0 && D_001A4BE0.h2884 == 0) {
            flag = func_004E5470(3) == 3;
        }
        p = &D_001A4C60;
        __asm__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(diff) : "m"(D_001A4C60), "m"(p[59]));
        dist = func_0050D4D8(&diff);
        if (flag) {
            G_4ED860 *g = (G_4ED860 *)((u8 *)p - 0x80);
            if (g->b46E == 0) {
                func_004F1110(4, g->w25C0, 13);
            } else {
                s32 id = g->w279C;
                if (id != -1 && ((F_4ED860 *)&D_001A30B0[id])->wDC == g->w25C0 && ((F_4ED860 *)&D_001A30B0[id])->bD0 != 0) {
                    func_004A6E88(id);
                }
                D_001A4BE0.w279C = -1;
            }
        }
        func_0050D110(&a, 0.0f, 0.0f, 1.0f, 1);
        func_0050D110(&b, 0.0f, 0.0f, 2.7f, 1);
        if (func_003F8448(&a, &b, 2, 0, 0) == 0) {
            if (2.8f < dist) {
                spd *= 0.47f;
            } else if (2.2f < dist) {
                spd *= 0.7f;
            }
        } else {
            if (2.1f < dist) {
                spd *= 0.45f;
            } else if (1.7f < dist) {
                spd *= 0.7f;
            }
        }
        spd *= 1.25f;
        if (D_001A4BE0.w1B8 < 8) {
            len = func_0050D4D8(&D_001A4BE0.vF0);
            if (len < spd) {
                func_004450C0(&len, spd, 0.041666668f);
            }
            func_0050D530(&D_001A4BE0.vF0, &D_001A4BE0.vF0, len);
        }
        return;
    }
    {
        s32 z = 0;
        S_4ED860 *s;
        if (D_001A4BE0.f480 == 0.0f && D_001A4BE0.f484 == 0.0f) {
            z = 1;
        }
        if ((D_001D52FC->w1A0 & func_0045E3B8(64, 0)) != 0 || z != 0 || D_001A4BE0.w25C4 == 18) {
            if (D_001A4BE0.f478 < D_001A4BE0.f4DC && !(D_001A4BE0.h4E8 < D_001A4BE0.w1B8)) {
                D_001A4BE0.f478 = D_001A4BE0.f478 + (D_001A4BE0.f4DC - D_001A4BE0.f4D8) / (f32)D_001A4BE0.h4E8;
                if (D_001A4BE0.f4DC < D_001A4BE0.f478) {
                    D_001A4BE0.f478 = D_001A4BE0.f4DC;
                }
                {
                    f32 v;
                    v = (D_001A4BE0.f478 + D_001A4BE0.f478) * D_001A4BE0.f4F0;
                    __asm__("sqrt.s %0, %1" : "=f"(v) : "f"(v));
                    D_001A4BE0.f480 += v - D_001A4BE0.f484 - D_001A4BE0.f480;
                }
            }
        }
        if (!(D_001A4BE0.w1B8 < D_001A4BE0.h47C) && 0.0f < D_001A4BE0.f480) {
            func_0050D2A8(&D_001A4BE0.vF0, &D_001A4BE0.vF0, D_001A4BE0.f480);
            D_001A4BE0.f484 = D_001A4BE0.f484 + D_001A4BE0.f480;
            D_001A4BE0.f480 = 0.0f;
        }
        if (D_001A4BE0.b46D == 0) {
            return;
        }
        if (D_001A4BE0.w1B8 < D_001A4BE0.s400.w0 || !(D_001A4BE0.w1B8 < D_001A4BE0.s400.w4)) {
            return;
        }
        s = &D_001A4BE0.s400;
        s->w1C++;
        while (s->w18 == -1 || !(s->w1C < s->p14[s->w18].w8)) {
            s->w18++;
            s->w1C = 0;
            if (s->p14[s->w18].f0 != -999999.0f) {
                s->f20 = s->p14[s->w18].f0 * 0.00027777778f;
            }
        }
        if (s->w1C > 0) {
            s->f20 += s->p14[s->w18].f4 * 0.00027777778f;
        }
        func_0050D2A8(&D_001A4CD0, &D_001A4CD0, s->f20);
    }
}
/* localdecomp:end func_004ED860 */
