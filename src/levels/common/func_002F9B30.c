#include "common.h"

/* localdecomp:start func_002F9B30 */
typedef int Q_2F9B30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2F9B30;
typedef struct {
    V4_2F9B30 v0;
    u8 pad10[4];
    s32 i14;
    s32 i18;
    s32 i1C;
} P_2F9B30;
typedef struct {
    u8 pad0[16];
    V4_2F9B30 v10;
    u8 pad20[72];
    P_2F9B30 *p68;
    u8 pad6C[62];
    u16 hAA;
    u8 padAC[16];
    u8 bBC;
} O_2F9B30;
typedef struct {
    u8 pad0[100];
    void *p64;
    u8 pad68[66];
    s16 hAA;
} M_2F9B30;
typedef struct {
    u8 pad0[24];
    M_2F9B30 *p18;
    s32 i1C;
    V4_2F9B30 v20;
    u8 pad30[16];
    V4_2F9B30 v40;
} G_2F9B30;
typedef struct {
    V4_2F9B30 v0;
    void *p10;
    u32 f14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} R_2F9B30;
extern G_2F9B30 D_001EAA80;
extern V4_2F9B30 D_001EAAA0;
extern M_2F9B30 *D_001A71A0[];
extern void *D_001D9EA0;
extern s32 D_001E1110;
extern s32 D_001E1118;
extern void func_004C4AD8(s32, void *, s32);
extern void func_004C6EC8(void *, void *);
extern void func_004C6FD8(void *, void *);
extern void func_004C4190(void *, void *, f32);
extern void func_002FB318(void *);
extern void func_0040C140(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, void *);
extern s32 func_003FC730(void);
extern void func_004C2BF8(s32, s32, s32, f32, f32, f32, f32);
extern u8 *func_00301508(void *, s32, f32, f32);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440878(s32, s32);
extern s32 func_00440848(s32);
extern void func_00465410(void *, void *, s32, s32);
extern void func_0040C260(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_0040BA90(void *);
extern void func_004C4AB8(s32);
extern void func_002FA220(void *, void *, void *);
void func_002F9B30(O_2F9B30 *o) {
    P_2F9B30 *p = o->p68;
    V4_2F9B30 old;
    V4_2F9B30 a;
    V4_2F9B30 b;
    R_2F9B30 r;
    V4_2F9B30 d;
    V4_2F9B30 e;
    Q_2F9B30 x, y, z;
    u8 *s;
    s32 i;
    s32 n;
    f32 ang;
    f32 rad;

    *(Q_2F9B30 *)&a = 0;
    *(Q_2F9B30 *)&b = 0;
    a.z = 0.0333333351f;
    old = o->v10;
    b.z = 1.0f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(z));
    func_004C4AD8(p->i1C, p, 0);
    func_004C6EC8(&o->v10, &o->v10);
    func_004C6FD8(p, p);
    func_004C4190(&o->v10, p, 0.00305555575f);
    func_002FB318(o);
    r.p10 = o;
    r.f14 = 0x1030000;
    if (p->i18 < 290) {
        r.f14 = 0x1030001;
    }
    r.f1C = 1.0f;
    r.i20 = 1;
    r.v0 = p->v0;
    func_0040C140(&r.v0, &r.v0, 1.0f);
    r.v0.z = 1.0f;
    r.v0.w = 5627.9248f;
    r.b18 = 2;
    r.h1A = o->hAA;
    r.b19 = 1;
    if (func_003F8448(&old, &o->v10, 16, o, &r) != 0) {
        if (func_003FC730() == 0 && p->v0.z < 0.0f) {
            func_004C2BF8(D_001E1110, D_001E1118, 1, o->v10.x, o->v10.y, 0.5f, -0.35f);
            __asm__("sq $0,%0" : "=m"(p->v0));
            p->i14 = 1;
            p->v0.z = -0.0250000022f;
            d.x = o->v10.x;
            d.y = o->v10.y;
            d.z = D_001EAAA0.z;
            s = func_00301508(&d, 3, 2.0f, 1.025f);
            if (s != 0) {
                s[35] = 112;
            }
            for (i = 0; i < 16; i++) {
                ang = func_00440978();
                rad = func_004408C0(0.0f, 0.0500000045f);
                e.x = func_0040C3C8(ang) * rad;
                e.y = func_0040C3E0(ang) * rad;
                e.z = func_004408C0(0.0500000045f, 0.108333342f);
                n = func_00440878(90, 120);
                func_00465410(&d, &e, func_00440848(2), n);
            }
        } else {
            if (D_001EAA80.p18 != 0) {
                if ((D_001EAA80.p18 != D_001A71A0[0] && D_001EAA80.p18->hAA != 192) || p->i18 < 290) {
                    if (D_001EAA80.p18->p64 != D_001D9EA0 || D_001EAA80.p18->hAA == 822) {
                        o->bBC = 1;
                o->v10 = D_001EAA80.v20;
                func_0040C260(&a, p, &D_001EAA80.v40);
                func_0040C0F0(&a, &a, 0.0333333351f);
                func_0040C0F0(&b, &D_001EAA80.v40, 1.0f);
                    }
                }
            } else if (D_001EAA80.i1C > 0) {
                o->bBC = 1;
                o->v10 = D_001EAA80.v20;
                func_0040C260(&a, p, &D_001EAA80.v40);
                func_0040C0F0(&a, &a, 0.0333333351f);
                func_0040C0F0(&b, &D_001EAA80.v40, 1.0f);
            }
        }
    } else if (func_0040BA90(&p->i18) != 0) {
        o->bBC = 1;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(z));
    }
    if (o->bBC != 0) {
        func_004C4AB8(p->i1C);
        func_002FA220(o, &a, &b);
    }
}
/* localdecomp:end func_002F9B30 */
