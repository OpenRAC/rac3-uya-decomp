#include "common.h"

/* localdecomp:start func_003D9008 */
typedef int Q_3D9008 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D9008;
typedef struct {
    u8 pad0[0x30];
    s32 x30;
} M_3D9008;
typedef struct {
    u8 pad0[0x46];
    u8 x46;
} C_3D9008;
typedef struct {
    u8 pad0[0x10];
    V_3D9008 pos;
    u8 pad20[0x4];
    C_3D9008 *x24;
    u8 pad28[0xC];
    u16 x34;
    u8 pad36[0x32];
    M_3D9008 *x68;
    u8 pad6C[0x3E];
    s16 xAA;
} O_3D9008;
typedef struct {
    V_3D9008 v;
    u8 pad10[0x8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x4];
    s32 x20;
} __attribute__((aligned(16))) H_3D9008;
typedef struct {
    u8 pad0[0x6C];
    f32 x6C;
    u8 pad70[0x80];
} T_3D9008;
typedef struct {
    u8 pad0[0x140];
    f32 x140;
    f32 x144;
} G_3D9008;
extern G_3D9008 D_001E2900;
extern s32 D_001DB02C;
extern s32 D_001DDBF0;
extern s32 D_001E24B0;
extern O_3D9008 *D_001EEB00[];
extern u8 D_001425C0[];
extern T_3D9008 D_002C5640[];
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_004632D8(void *, void *, u32, u32, s32, f32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0046E4D8(void *, void *, s32);
extern void func_003D46A8(void *, s32, s32, s32, s32, f32, f32);
extern void func_00300250(void *, void *, void *);
extern s32 func_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004A7200(s32, s32, void *);
extern s32 func_003FB1D0(void *, s32, void *, s32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00443628(void *, void *, s32, void *, f32);
extern void func_00443840(void *, void *);
extern void func_00421FE0(s32);
extern void func_00436220(void *);
static __inline__ void polar_3D9008(V_3D9008 *v, f32 ang, f32 len) {
    v->x = func_0040C3C8(ang) * len;
    v->y = func_0040C3E0(ang) * len;
    v->z = 0.0f;
}
void func_003D9008(O_3D9008 *o) {
    V_3D9008 a;
    V_3D9008 b;
    H_3D9008 c;
    M_3D9008 *m;
    s32 i, j, k, n;

    m = o->x68;
    for (i = 0; i < 30; i++) {
        f32 r, s;
        r = func_004408C0(0.0f, 0.370000005f);
        s = func_00440978();
        func_00440CF8(&b, r, s, func_00440978());
        b.z += func_004408C0(0.349999994f, 0.600000024f);
        {
            Q_3D9008 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
        }
        r = func_004408C0(0.00250000018f, 0.0200000014f);
        s = func_00440978();
        func_00440CF8(&a, r, s, func_00440978());
        func_004632D8(&b, &a, 0x4F7F7F7F, 0x00202020, func_00440878(30, 57), 150000.0f);
    }
    for (i = 0; i < 50; i++) {
        f32 ang, spd;
        ang = func_0040C490(D_001E2900.x140 - o->pos.x, D_001E2900.x144 - o->pos.y);
        func_00440918(1.0f, 2.0f);
        a.x = o->pos.x + func_00440918(0.0f, 0.150000006f);
        a.y = o->pos.y + func_00440918(0.0f, 0.150000006f);
        a.z = o->pos.z + func_00440918(0.0f, 0.150000006f);
        spd = func_004408C0(3.0f, 7.0f);
        polar_3D9008(&b, func_0040CEC8(ang, func_00440918(0.0f, 2.61799383f)), spd * 0.0166666675f);
        b.z = func_004408C0(5.0f, 10.0f) * 0.0166666675f;
        func_0046E4D8(&a, &b, 170);
    }
    func_003D46A8(o, 78, 79, 10, 1, 1.5f, 1.20000005f);
    for (i = 0; i < 10; i++) {
        f32 r, s;
        r = func_004408C0(0.0f, 0.349999994f);
        s = func_00440978();
        func_00440CF8(&b, r, s, func_00440978());
        b.z += 0.25f;
        {
            Q_3D9008 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
        }
        func_00440CF8(&a, func_004408C0(0.0500000045f, 0.100000009f), func_00440978(), 1.22173047f);
        a.z = func_004408C0(3.0f, 5.0f) * 0.0166666675f;
        func_00300250(o, &b, &a);
    }
    func_0032FE90(&o->pos, 1, 25, 20, 20, 20, 45, 2, 0.800000011f, 0.0f, 0.0f, 0.0f,
                  0, 1, 1, 0, 0, 0, 0x10000, D_001DB02C, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_004A7200(3, 0, o);
    n = func_003FB1D0(&o->pos, 0, o, 0, 3.0f);
    for (j = 0; j < n; j++) {
        O_3D9008 *p = D_001EEB00[j];
        if (p->x24->x46 == 5 || (p->x34 & 0x4000)) {
            V_3D9008 *pa = &a;
            {
                Q_3D9008 q1, q2;
                __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(o->pos));
                __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(p->pos));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(q2) : "j"(q1));
                __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q2));
            }
            func_0040C0F0(pa, pa, 1.0f);
            func_0040C0F0(&c, &c, 1.0f);
            func_00443628(&c, o, 0x1010000, pa, ((T_3D9008 *)(D_001425C0[143] * 240 + (s32)D_002C5640))->x6C * 0.2f);
            c.x20 = 1;
            c.v = a;
            c.v.w = 5627.9248f;
            c.b18 = 5;
            c.b19 = 3;
            c.h1A = p->xAA;
            func_00443840(p, &c);
        }
    }
    if (m->x30 != -1) {
        func_00421FE0(m->x30);
        m->x30 = -1;
    }
    D_001DDBF0 = 1;
    D_001E24B0 = 60;
    func_00436220(o);
}
/* localdecomp:end func_003D9008 */
