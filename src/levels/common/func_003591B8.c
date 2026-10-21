#include "common.h"

typedef int Q_3591B8 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_3591B8;
typedef struct {
    u8 pad0[0x30];
    V_3591B8 pos;
    u8 pad40[0x40];
} P_3591B8;
typedef struct {
    u8 pad0[0x70];
    s32 i70;
    s32 i74;
    u8 pad78[0x8];
} A_3591B8;
typedef struct {
    s32 a, b, c, d;
} B_3591B8;
typedef struct {
    s32 i0;
    s32 i4;
    s32 i8;
    s32 iC;
    s32 i10;
    s32 i14;
    s32 i18;
    s32 i1C;
    s32 i20;
    u8 pad24[0x8];
    s32 i2C;
    s32 i30;
    s32 i34;
    s32 i38;
    u8 pad3C[0x4];
    u32 i40;
    u32 i44;
    s32 i48;
    s32 i4C;
} S_3591B8;

extern s32 D_001D545C;
extern P_3591B8 *D_001DFF00;
extern u8 D_001BBC40[][16];
extern u8 D_001BBB18[][8];
extern u8 *func_003B9818(u8 *);
extern u8 *func_003B96E0(u8 *);
extern void func_004B6470(u8 *, s32);
extern void func_0041CA08(V_3591B8 *, V_3591B8 *, f32);
extern void func_0045D440(void *, V_3591B8 *, s32);
extern void func_0041C7F8(V_3591B8 *, V_3591B8 *, V_3591B8 *);
extern void func_0041C768(V_3591B8 *, void *, f32);
extern void func_003782C8(s32);
extern s32 func_00378010(V_3591B8 *);
extern void func_004513D8(u8 *, s32, s32);

void func_003591B8(u8 *o, S_3591B8 *s) {
    V_3591B8 a, b, c;
    Q_3591B8 x, y;
    u8 *m;
    s32 i;
    A_3591B8 *ap;
    s32 *q;
    P_3591B8 *p;
    f32 f;

    o[0x30] = 0x20;
    *(s16 *)(o + 0x32) = 0x20;
    s->i0 = 0;
    s->i4 = 0;
    s->i8 = 0;
    s->i30 = 0;
    if (s->i14 >= 2) {
        s->i14 = 1;
    } else if (s->i14 < 0) {
        s->i14 = 0;
    }
    if (s->iC != -1 || s->i10 != s->iC) {
        s->i18 = s->i14;
    } else {
        s->i18 = 1;
    }
    s->i2C = 0;
    {
        A_3591B8 *pa;
        s32 *p3 = (s32 *)((u8 *)s + 0x11C);
        s32 *p2 = (s32 *)((u8 *)s + 0x118);
        s32 *p1 = (s32 *)((u8 *)s + 0x114);
        s32 *p0 = (s32 *)((u8 *)s + 0x110);
        s32 n;
        pa = (A_3591B8 *)s;
        for (n = 3; n >= 0; n--) {
            pa->i74 = 0;
            pa->i70 = 0;
            *p0 = 0;
            *p1 = 0;
            *p2 = 0;
            *p3 = 0;
            pa = (A_3591B8 *)((u8 *)pa + 0x30);
            p0 += 4;
            p1 += 4;
            p2 += 4;
            p3 += 4;
        }
    }
    s->i40 = 0xFFFFFFFF;
    s->i44 = 0xFFFFFFFF;
    m = 0;
    if (s->i20 != -1) {
        if (s->i20 != 0) {
            m = func_003B9818(o);
        } else {
            m = func_003B96E0(o);
        }
    }
    o[0x30] = 0xFE;
    if (D_001D545C == 11) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
    }
    if (s->i48 != 0 && m != 0) {
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_004B6470(m, 1);
    }
    {
    s32 k = s->i4C;
    if (k != -1) {
        P_3591B8 *e = &D_001DFF00[k];
        *(u16 *)(o + 0x34) |= 0x100;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3591B8 *)(o + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        func_0041CA08(&a, &a, 1.0f);
        func_0045D440(o + 0x10, &b, 1);
        func_0041CA08(&b, &b, 1.0f);
        func_0041C7F8(&c, &a, &b);
        func_0041CA08(&c, &c, 1.0f);
        *(V_3591B8 *)(o + 0xC0) = a;
        *(V_3591B8 *)(o + 0xD0) = c;
        *(V_3591B8 *)(o + 0xE0) = b;
    }
    }
    if (s->i1C != 0) {
        if ((o[0xB0] != 0xFF && (D_001BBC40[D_001D545C][o[0xB0]] & 0x80)) ||
            (s->i34 != -1 && D_001BBB18[D_001D545C][s->i34] != 0)) {
            s->i18 = s->i14 ^ 1;
            s->i2C = 0;
            if (s->i1C != 0) {
                s->iC = -1;
                s->i10 = -1;
            }
            i = s->i38;
            if (i != -1) {
                p = &D_001DFF00[i];
                a = p->pos;
                func_0041C768(&b, p, D_001D545C == 11 ? 80.0f : 40.0f);
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
                func_0041CA08(&c, &c, 1.0f);
                if (s->i4 != 0) {
                    func_003782C8(s->i4);
                }
                s->i4 = func_00378010(&a);
                *(V_3591B8 *)((u8 *)s + 0x150) = c;
                *(s32 *)((u8 *)s + 0x110) = 4;
            }
        }
    }
    func_004513D8(o, 1, -1);
}
