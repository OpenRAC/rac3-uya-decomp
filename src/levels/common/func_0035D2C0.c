#include "common.h"

/* localdecomp:start func_0035D2C0 */
typedef int Q_35D2C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35D2C0;

typedef struct {
    V4_35D2C0 vel;
    u8 pad10[0x24 - 0x10];
    s32 i24;
    s32 i28;
    s32 p2C;
} S_35D2C0;

typedef struct {
    u8 pad0[0x10];
    V4_35D2C0 pos;
    u8 pad20[0x68 - 0x20];
    S_35D2C0 *s;
} M_35D2C0;

typedef struct {
    u8 pad0[0x1C];
    s32 i1C;
    u8 pad20[8];
    f32 f28;
} G_35D2C0;

extern G_35D2C0 D_001EAA80;
extern s32 D_001EAA9C[];
extern f32 D_001EAAA0[];
extern void func_004C4AD8(s32, void *, s32);
extern void func_004C4190(void *, void *, f32);
extern s32 func_003F9498(void *, s32, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern s32 func_003FC730(void);
extern u8 *func_00301508(void *, s32, f32, f32);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440878(s32, s32);
extern s32 func_00440848(s32);
extern void func_00465410(void *, void *, s32, s32);
extern void func_00441FB8(void *, s32, s32);
extern s32 func_0040BA90(void *);
extern f32 func_0040BF38(void *);

void func_0035D2C0(M_35D2C0 *m)
{
    V4_35D2C0 old;
    V4_35D2C0 a;
    V4_35D2C0 b;
    S_35D2C0 *s;
    V4_35D2C0 *pos = &m->pos;
    u32 r;
    u8 *p;
    s32 i, t;
    f32 ang, rr;

    old = m->pos;
    s = m->s;
    func_004C4AD8(s->p2C, s, 0);
    func_004C4190(pos, s, 0.0030555557f);
    {
        Q_35D2C0 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->vel));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m->pos) : "j"(z));
    }
    if (func_003F9498(pos, 16, m, 0.1f) != 0) {
        r = func_003FC730();
        if (r < 2 || r == 11) {

            __asm__("sq $0,%0" : "=m"(s->vel));
            s->i24 = 1;
            s->vel.z = -0.025000002f;
            a.x = m->pos.x;
            a.y = m->pos.y;
            a.z = D_001EAAA0[2];
            p = func_00301508(&a, 3, 2.0f, 1.025f);
            if (p != 0) {
                p[0x23] = 0x70;
            }
            for (i = 0; i < 16; i++) {
                ang = func_00440978();
                rr = func_004408C0(0.0f, 0.050000004f);
                b.x = func_0040C3C8(ang) * rr;
                b.y = func_0040C3E0(ang) * rr;
                b.z = func_004408C0(0.050000004f, 0.10833334f);
                t = func_00440878(90, 120);
                func_00465410(&a, &b, func_00440848(2), t);
            }

            func_00441FB8(m, 1, -1);
        } else if (D_001EAA9C[0] > 0) {
            func_00441FB8(m, 2, -1);
        }
    } else if (func_003F8448(&old, pos, 16, m, 0) != 0) {
        if (func_003FC730() == 0 && s->vel.z < 0.0f) {

            __asm__("sq $0,%0" : "=m"(s->vel));
            s->i24 = 1;
            s->vel.z = -0.025000002f;
            a.x = m->pos.x;
            a.y = m->pos.y;
            a.z = D_001EAA80.f28;
            p = func_00301508(&a, 3, 2.0f, 1.025f);
            if (p != 0) {
                p[0x23] = 0x70;
            }
            for (i = 0; i < 16; i++) {
                ang = func_00440978();
                rr = func_004408C0(0.0f, 0.050000004f);
                b.x = func_0040C3C8(ang) * rr;
                b.y = func_0040C3E0(ang) * rr;
                b.z = func_004408C0(0.050000004f, 0.10833334f);
                t = func_00440878(90, 120);
                func_00465410(&a, &b, func_00440848(2), t);
            }

            func_00441FB8(m, 1, -1);
        }
        if (D_001EAA80.i1C > 0) {
            func_00441FB8(m, 2, -1);
        }
    }
    if (func_0040BA90(&s->i28) != 0 || func_0040BF38(s) < 0.008333334f) {
        func_00441FB8(m, 2, -1);
    }
}
/* localdecomp:end func_0035D2C0 */
