#include "common.h"

/* localdecomp:start func_00465D80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_465D80;
typedef int Q_465D80 __attribute__((mode(TI)));
typedef struct {
    V_465D80 v;
    f32 f10;
    s16 h14;
    s16 h16;
    u8 b18;
    u8 b19;
    u8 pad1A[2];
    s32 i1C;
} P_465D80;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u32 u4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    V_465D80 pos;
    P_465D80 p;
} O_465D80;
typedef struct {
    V_465D80 v;
    s32 i10;
    s32 i14;
    s32 pad18;
    f32 f1C;
    s32 i20;
} T_465D80;

extern u8 *D_00221148[];
extern V_465D80 D_001EAAC0[];
extern s32 func_0040BAC0(s16 *);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern O_465D80 *func_00465BB8(void *, void *, s32, s32, s32, s32);
extern s32 func_003F8448(void *, void *, s32, s32, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C260(void *, void *, void *);
extern void func_0045E580(O_465D80 *);

void func_00465D80(O_465D80 *obj) {
    V_465D80 vel;
    V_465D80 pos;
    T_465D80 t;
    V_465D80 d;
    P_465D80 *p;
    O_465D80 *r;
    Q_465D80 a, b;
    f32 rr, s, a3;
    s32 hit, id, k;
    u8 fl;

    p = &obj->p;
    if (obj->hA != 0 && func_0040BAC0(&obj->hA)) {
        p->b18 |= 0x88;
        rr = obj->fC / ((f32)p->b19 * 0.03125f * 900000.0f);
        obj->fC *= 0.8f;
        func_0040BE90(&vel, p, func_004408C0(0.5f, 0.7f));
        pos.x = obj->pos.x + func_004408C0(-rr, rr);
        pos.y = obj->pos.y + func_004408C0(-rr, rr);
        pos.z = obj->pos.z + func_004408C0(-rr, rr);
        vel.x += func_004408C0(-obj->p.v.x * 0.2f, obj->p.v.x * 0.2f);
        vel.y += func_004408C0(-p->v.y * 0.2f, p->v.y * 0.2f);
        vel.z += func_004408C0(-p->v.z * 0.2f, 0.0f);
        r = func_00465BB8(&pos, &vel, (p->b18 & 0x10) | 0x88, p->i1C, p->b19, 128);
        if (r) {
            r->hA = 2;
            r->fC = obj->fC;
        }
        func_0040BE90(p, p, func_004408C0(0.5f, 0.7f));
        obj->p.v.x += func_004408C0(-obj->p.v.x * 0.2f, obj->p.v.x * 0.2f);
        p->v.y += func_004408C0(-p->v.y * 0.2f, p->v.y * 0.2f);
        p->v.z += func_004408C0(-p->v.z * 0.2f, 0.0f);
        obj->pos.x += func_004408C0(-rr, rr);
        obj->pos.y += func_004408C0(-rr, rr);
        obj->pos.z += func_004408C0(-rr, rr);
    }
    hit = 0;
    k = obj->b2 - D_00221148[0][0];
    obj->b2 = D_00221148[0][(obj->hA + p->h16 + k) & 7];
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p->v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(a));
    if (p->h14 >= 4) {
        __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(obj->pos), "m"(p->v));
    } else {
        *(Q_465D80 *)&pos = *(Q_465D80 *)&obj->pos;
    }
    func_0040BE90(&t, &t, 0.01f);
    fl = p->b18;
    if (fl & 8) {
        if ((obj->u4 & 0xFF000000) == 0) {
            func_0045E580(obj);
            return;
        }
        p->b18 = fl | 8;
        if ((fl | 8) & 0x10) goto skip;
        hit = func_003F8448(&pos, &vel, 4, p->i1C, 0) != 0;
    } else {
        id = p->i1C;
        t.i14 = 0x10001;
        t.f1C = 1.0f;
        *(Q_465D80 *)&t.v = *(Q_465D80 *)&p->v;
        t.i10 = id;
        if (fl & 0x40) {
            __asm__("sq $0,%0" : "=m"(t.v));
        }
        t.i20 = 1;
        if (fl & 0x10) goto skip;
        hit = func_003F8448(&pos, &vel, 0, id, &t) != 0;
    }
skip:
    if (hit) {
        func_0040C0F0(&d, D_001EAAC0, 1.0f);
        func_0040C260(p, p, D_001EAAC0);
        func_0040BE90(p, p, 0.02f);
        func_0040C0F0(&d, D_001EAAC0, 0.055f);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001EAAC0[-2]));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(a));
        if (obj->fC < 200000.0f && !(p->b18 & 8)) {
            obj->fC = obj->fC + obj->fC;
        }
        p->b18 |= 8;
    } else {
        *(Q_465D80 *)&obj->pos = *(Q_465D80 *)&vel;
    }
    if (p->b18 & 8) {
        p->h16++;
        obj->fC -= ((f32)p->b19 * 0.03125f * 270000.0f - (f32)p->b19 * 0.03125f * 30000.0f) / 18.0f * 1.25f;
        if (obj->fC <= 0.0f) {
            func_0045E580(obj);
            return;
        }
    } else {
        obj->fC += ((f32)p->b19 * 0.03125f * 270000.0f - (f32)p->b19 * 0.03125f * 30000.0f) / 18.0f;
    }
    a3 = (f32)p->h14 / 18.0f * 0.0044444446f + 0.08f;
    if (a3 < 0.0f) a3 = 0.0f;
    if (0.08f < a3) a3 = 0.08f;
    if (p->b18 & 8) {
        a3 = a3 / ((f32)p->h16 / 7.0f + 1.0f);
    }
    obj->u4 = (obj->u4 & 0xFFFFFF) | ((s32)(a3 * 256.0f) << 24);
    p->v.z += 0.008f;
    if (p->h14 >= 26 || (p->b18 & 8)) {
        p->v.x *= 0.95f;
        p->v.y *= 0.95f;
    }
    s = -1.0f;
    if (p->b18 & 1) s = 1.0f;
    if (p->b18 & 8) {
        p->v.z += 0.008f;
        p->f10 += s * -0.01f / (f32)p->h16;
    } else {
        p->f10 += s * -0.01f;
    }
    if (p->f10 > 1.0f) p->f10 -= 1.0f;
    if (p->f10 < 0.0f) p->f10 += 1.0f;
    obj->b8 = p->f10 * 256.0f;
}
/* localdecomp:end func_00465D80 */
