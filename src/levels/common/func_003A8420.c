#include "common.h"

typedef int Q_3A8420 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A8420;

typedef struct {
    V4_3A8420 v0;
    u8 pad10[8];
    u8 m18[8];
    f32 f20;
    u8 pad24[4];
    f32 f28;
} P_3A8420;

typedef struct O_3A8420 {
    u8 pad0[0x10];
    V4_3A8420 pos;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    P_3A8420 *pVar;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
    u8 padAC[0xB8 - 0xAC];
    struct O_3A8420 *wB8;
} O_3A8420;

typedef struct {
    u8 pad0[0x18];
    O_3A8420 *m18;
    u8 pad1C[4];
    V4_3A8420 v20;
    V4_3A8420 v30;
    V4_3A8420 v40;
} D_3A8420;

extern D_3A8420 D_001E8A80;
extern O_3A8420 *D_001E8A98[];
extern void func_003EF100(V4_3A8420 *, V4_3A8420 *, f32);
extern s32 func_003DD2B8(V4_3A8420 *, s32, O_3A8420 *, f32);
extern void func_003EF510(V4_3A8420 *, V4_3A8420 *, V4_3A8420 *);
extern void func_004243F8(O_3A8420 *, s32, s32);
extern void func_004A95B0(void);
extern void func_004A95E8(void);
extern s32 func_003DC268(V4_3A8420 *, V4_3A8420 *, s32, O_3A8420 *, s32);
extern void func_003EF3A0(V4_3A8420 *, V4_3A8420 *, f32);
extern s32 func_003EECD0(void *);
extern f32 func_003EF1A8(V4_3A8420 *);
extern void func_0032E2C8(V4_3A8420 *, s32, s32, s32, s32, s32, s32, s32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32);
extern void func_00418A60(O_3A8420 *);

static inline void copy_3A8420(V4_3A8420 *d, V4_3A8420 *s) {
    *d = *s;
}

void func_003A8420(O_3A8420 *o) {
    P_3A8420 *p;
    V4_3A8420 old;
    V4_3A8420 axis;
    V4_3A8420 off;
    D_3A8420 *d;
    D_3A8420 *e;
    s32 hit;

    p = o->pVar;
    if (p == 0) {
        return;
    }
    copy_3A8420(&old, &o->pos);
    {
        Q_3A8420 u, a, b, r;

        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->pos));
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(u));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p->v0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(r));
        __asm__("sqc2 %1, %0" : "=m"(axis) : "j"(u));
    }
    func_003EF100(&axis, &axis, p->f28 * 0.00027777778f);
    {
        Q_3A8420 a, b, r;

        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p->v0));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(axis));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(p->v0) : "j"(r));
    }
    if (func_003DD2B8(&o->pos, 0, o, 0.1f)) {
        d = &D_001E8A80;
        if (d->m18 != 0) {
            if (d->m18 != o->wB8) {
                o->pos = d->v30;
                func_003EF510(&p->v0, &p->v0, &d->v40);
                p->v0.z += p->v0.z;
                func_003EF100(&p->v0, &p->v0, 0.20833334f);
                o->pos = d->v20;
                func_004243F8(o, 1, -1);
            }
        } else {
            o->pos = d->v30;
            func_003EF510(&p->v0, &p->v0, &d->v40);
            p->v0.z += p->v0.z;
            func_003EF100(&p->v0, &p->v0, 0.20833334f);
            o->pos = d->v20;
            o->pos.z += 0.5f;
            func_004243F8(o, 1, -1);
        }
    } else {
        func_004A95B0();
        hit = func_003DC268(&old, &o->pos, 0x10, o, 0);
        if (hit && D_001E8A98[0] && D_001E8A98[0]->hAA == 0x186D
            && D_001E8A98[0]->b20 != 2 && D_001E8A98[0]->b20 != 5) {
            D_001E8A98[0]->b20 = 4;
        }
        func_004A95E8();
        if (hit) {
            e = &D_001E8A80;
            if (e->m18 != 0) {
                if (e->m18 != o->wB8) {
                    o->pos = e->v30;
                    func_003EF510(&p->v0, &p->v0, &e->v40);
                    p->v0.z += p->v0.z;
                    func_003EF100(&p->v0, &p->v0, 0.20833334f);
                    o->pos = e->v20;
                    func_004243F8(o, 1, -1);
                }
            } else {
                o->pos = e->v20;
                func_003EF3A0(&off, &e->v40, 0.1f);
                {
                    Q_3A8420 a, b, r;

                    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(off));
                    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->pos));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(b), "j"(a));
                    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(r));
                }
                func_003EF510(&p->v0, &p->v0, &e->v40);
                p->v0.z += p->v0.z;
                func_003EF100(&p->v0, &p->v0, 0.20833334f);
                o->pos = e->v20;
                o->pos.z += 0.5f;
                func_004243F8(o, 1, -1);
            }
        }
    }
    if (func_003EECD0(p->m18) || func_003EF1A8(&p->v0) < 0.008333334f) {
        func_0032E2C8(&o->pos, 1, 10, 10, 10, 10, 30, 0,
                      0, 1, 0, 0, 0, 0, 0x10001, 0, 0x804020,
                      0x806040, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F804020, 0x28802020, 0xFF6020, 0,
                      1.5f, 0.0f, p->f20, 2.0f);
        func_00418A60(o);
    }
}
