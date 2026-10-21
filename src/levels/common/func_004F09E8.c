#include "common.h"

/* localdecomp:start func_004F09E8 */
typedef int Q_4F09E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4F09E8;
typedef struct {
    u8 pad0[0x88];
    f32 x88;
    u8 pad8C[0xC];
    f32 x98;
    u8 pad9C[0x54];
    V_4F09E8 vF0;
    u8 pad100[0x40];
    V_4F09E8 v140;
    u8 pad150[0x20];
    f32 x170;
    u8 pad174[0x2C];
    f32 x1A0;
    u8 pad1A4[0xC];
    f32 x1B0;
    u8 pad1B4[0x4];
    s32 x1B8;
    u8 pad1BC[0x104];
    f32 x2C0;
    f32 x2C4;
    u8 pad2C8[0x70];
    f32 x338;
    u8 pad33C[0x4];
    f32 x340;
    f32 x344;
    u8 pad348[0x98];
    f32 x3E0;
    f32 x3E4;
    u8 pad3E8[0x5F8];
    V_4F09E8 v9E0;
    f32 x9F0;
    u8 pad9F4[0xA40];
    s16 h1434;
    u8 pad1436[0x2];
    f32 x1438;
    u8 pad143C[0x274];
    s32 x16B0;
    u8 pad16B4[0xF10];
    s32 x25C4;
    u8 pad25C8[0x270];
    f32 x2838;
} P_4F09E8;
typedef struct {
    u8 pad0[0x1D4];
    s32 x1D4;
} G_4F09E8;
extern P_4F09E8 D_001A4BE0;
extern G_4F09E8 *D_001D52FC;
extern V_4F09E8 D_001A4D20;
extern V_4F09E8 D_001A4CD0;
extern void func_004EAA78(s32, f32);
extern s32 func_0045D358(s32, s32, s32, s32);
extern void func_004EA628(void);
extern void func_004EF060(void);
extern void func_004EAFF8(s32, f32, f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_004EC780(f32, f32);
extern f32 func_0040BF68(V_4F09E8 *);
extern f32 func_0040BEF8(V_4F09E8 *, V_4F09E8 *);
extern f32 func_0040BF38(V_4F09E8 *);
extern void func_0040C0F0(V_4F09E8 *, V_4F09E8 *, f32);
extern f32 func_0040C490(f32, f32);
extern void func_004EB5D0(s32);
extern void func_0040BE90(V_4F09E8 *, V_4F09E8 *, f32);
void func_004F09E8(void) {
    V_4F09E8 v;
    V_4F09E8 w;
    V_4F09E8 u;
    V_4F09E8 a;
    V_4F09E8 b;
    f32 ang;
    f32 t;
    f32 spd;
    f32 lim;
    f32 len;
    V_4F09E8 *c;

    func_004EAA78(0, 1.0f);
    if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.x16B0 == 1 && func_0045D358(40, 2, 0, 0) != 0)) {
        func_004EA628();
        func_004EF060();
    } else {
        func_004EAFF8(0, 0.0199999996f, 0.200000003f, 0.061086528f);
    }
    if (D_001A4BE0.x25C4 == 19) {
        if (D_001A4BE0.x2838 < 0.200000003f) {
            D_001A4BE0.x1A0 = D_001A4BE0.x98;
        }
        D_001A4BE0.x1B0 = 0.400000006f;
    } else if (D_001A4BE0.x25C4 == 21) {
        D_001A4BE0.x1B0 = 0.0f;
    }
    ang = D_001A4BE0.x1A0;
    if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.x16B0 == 1 && func_0045D358(40, 2, 0, 0) != 0)) {
        ang = D_001A4BE0.x1438;
    }
    v.x = func_0040C3C8(ang) * (D_001A4BE0.x1B0 * 0.0983333364f);
    v.y = func_0040C3E0(ang) * (D_001A4BE0.x1B0 * 0.0983333364f);
    v.z = 0.0f;
    w = v;
    if (0.0f < D_001A4BE0.x9F0) {
        func_004EC780(0.699999988f, 0.0f);
        {
            Q_4F09E8 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(D_001A4BE0.v9E0));
            u = D_001A4BE0.v9E0;
            __asm__("sq $0,%0" : "=m"(D_001A4BE0.v9E0));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(q1));
        }
    }
    t = -(D_001A4BE0.vF0.x * v.x + D_001A4BE0.vF0.y * v.y);
    if (0.0f < t) {
        t /= func_0040BF68(&v);
        t /= func_0040BF68(&D_001A4BE0.vF0);
    }
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < 0.0f) {
        t = 0.0f;
    }
    spd = D_001A4BE0.x1B0 * 0.000680555589f;
    spd += t * 0.000555555569f;
    if (D_001D52FC->x1D4 != 0) {
        spd = 0.000305555557f;
    }
    if (D_001A4BE0.x25C4 == 19 && D_001A4BE0.x1B8 < 15 && D_001A4BE0.x170 < 0.0500000045f) {
        spd = 0.00305555575f;
    }
    if (0.0983333364f < D_001A4BE0.x170) {
        spd = 0.00361111108f;
    }
    if (0.0f < D_001A4BE0.x9F0) {
        t = -func_0040BEF8(&w, &u);
        {
            f32 l1 = func_0040BF38(&w);
            if (0.0f < l1) {
                t /= l1;
            }
        }
        {
            f32 l2 = func_0040BF68(&u);
            lim = (l2 - t) / l2 * 0.000833333354f;
        }
        if (D_001A4BE0.x2838 < 0.300000012f) {
            if (lim < 0.000833333354f) {
                lim = 0.000833333354f;
            }
        }
        if (spd < lim) {
            spd = lim;
        }
    }
    {
        Q_4F09E8 q1, q2;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(D_001A4D20));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q1));
    }
    a.z = 0.0f;
    if (spd < func_0040BF38(&a)) {
        func_0040C0F0(&a, &a, spd);
    }
    {
        Q_4F09E8 q1, q2;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(D_001A4D20));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(*(V_4F09E8 *)((u8 *)&D_001A4D20 - 0x50)) : "j"(q1));
    }
    if (0.0872664601f < ((P_4F09E8 *)((u8 *)&D_001A4D20 - 0x140))->x340) {
        f32 r, s;
        ang = func_0040C490(((P_4F09E8 *)((u8 *)&D_001A4D20 - 0x140))->x2C0, ((P_4F09E8 *)((u8 *)&D_001A4D20 - 0x140))->x2C4);
        r = ((P_4F09E8 *)((u8 *)&D_001A4D20 - 0x140))->x340 * 0.13333334f / 0.785398185f;
        s = ((P_4F09E8 *)((u8 *)&D_001A4D20 - 0x140))->x340 * 0.00236111111f / 0.785398185f;
        a.x = func_0040C3C8(ang) * r;
        a.y = func_0040C3E0(ang) * r;
        a.z = 0.0f;
        {
            Q_4F09E8 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(V_4F09E8 *)((u8 *)&D_001A4D20 - 0x50)));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(a));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
        }
        b.z = 0.0f;
        if (s < func_0040BF38(&b)) {
            func_0040C0F0(&b, &b, s);
        }
        {
            Q_4F09E8 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(V_4F09E8 *)((u8 *)&D_001A4D20 - 0x50)));
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(*(V_4F09E8 *)((u8 *)&D_001A4D20 - 0x50)) : "j"(q1));
        }
    }
    c = &D_001A4CD0;
    a = *c;
    a.z = 0.0f;
    ((P_4F09E8 *)((u8 *)&D_001A4CD0 - 0xF0))->x3E0 = func_0040BEF8(&a, &v);
    len = func_0040BF38(&v);
    if (0.0f < len) {
        ((P_4F09E8 *)((u8 *)&D_001A4CD0 - 0xF0))->x3E0 /= len * 0.0983333364f;
    }
    func_004EB5D0(0);
    if (((P_4F09E8 *)((u8 *)&D_001A4CD0 - 0xF0))->x3E4 < 0.0174532924f && 0.0872664601f < ((P_4F09E8 *)((u8 *)&D_001A4CD0 - 0xF0))->x344) {
        func_0040BE90(c, c, func_0040C3C8(((P_4F09E8 *)((u8 *)&D_001A4CD0 - 0xF0))->x344));
    }
    {
        f32 h = D_001A4BE0.x338;
        D_001A4BE0.x3E4 = D_001A4BE0.x344;
        if (__builtin_fabsf(D_001A4BE0.x88 - h) < 0.150000006f) {
            D_001A4BE0.x88 = h;
        }
    }
}
/* localdecomp:end func_004F09E8 */
