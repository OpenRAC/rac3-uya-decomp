#include "common.h"

/* localdecomp:start func_0046BBE8 */
typedef int Q_46BBE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46BBE8;
typedef struct {
    V4_46BBE8 v;
    f32 f16;
    s16 h20;
    s16 h22;
    u8 b24;
    u8 pad25[3];
    s32 w28;
} Q2_46BBE8;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u32 w4;
    u8 b8;
    u8 pad9;
    s16 h10;
    f32 f12;
    V4_46BBE8 pos;
    Q2_46BBE8 q;
} P_46BBE8;
typedef struct {
    u8 pad0[10];
    s16 h10;
    f32 f12;
} R_46BBE8;
typedef struct {
    V4_46BBE8 v;
    s32 w16;
    s32 w20;
    s32 pad24;
    f32 f28;
    s32 w32;
} L_46BBE8;
extern u8 *D_00221260[];
extern s32 func_0040BAC0(s16 *);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern R_46BBE8 *func_0046BA78(void *, void *, s32, s32);
extern s32 func_00440848(s32);
extern s32 func_003F8448(void *, void *, s32, s32, void *);
extern void func_0045E580(void *);
void func_0046BBE8(P_46BBE8 *p) {
    Q2_46BBE8 *q = &p->q;
    V4_46BBE8 a;
    V4_46BBE8 b;
    L_46BBE8 l;
    s32 hit;
    f32 spread;
    f32 f;
    f32 dir;
    R_46BBE8 *r;
    Q_46BBE8 x, y;

    if (p->h10 != 0 && func_0040BAC0(&p->h10) != 0) {
        q->b24 |= 0x88;
        spread = p->f12 / 900000.0f;
        p->f12 = p->f12 * 0.8f;
        func_0040BE90(&a, q, func_004408C0(0.5f, 0.7f));
        b.x = p->pos.x + func_004408C0(-spread, spread);
        b.y = p->pos.y + func_004408C0(-spread, spread);
        b.z = p->pos.z + func_004408C0(-spread, spread);
        a.x += func_004408C0(-q->v.x * 0.2f, q->v.x * 0.2f);
        a.y += func_004408C0(-q->v.y * 0.2f, q->v.y * 0.2f);
        a.z += func_004408C0(-q->v.z * 0.2f, 0.0f);
        r = func_0046BA78(&b, &a, 0x88, q->w28);
        if (r) {
            r->h10 = 2;
            r->f12 = p->f12;
        }
        func_0040BE90(q, q, func_004408C0(0.5f, 0.7f));
        q->v.x += func_004408C0(-q->v.x * 0.2f, q->v.x * 0.2f);
        q->v.y += func_004408C0(-q->v.y * 0.2f, q->v.y * 0.2f);
        q->v.z += func_004408C0(-q->v.z * 0.2f, 0.0f);
        p->pos.x += func_004408C0(-spread, spread);
        p->pos.y += func_004408C0(-spread, spread);
        p->pos.z += func_004408C0(-spread, spread);
    }
    hit = 0;
    {
        s32 d = p->b2 - D_00221260[0][0];
        p->b2 = D_00221260[0][(p->h10 + q->h22 + d) & 7];
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q->v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    if (q->h20 >= 4) {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    } else {
        b = p->pos;
    }
    func_0040BE90(&l, &l, 0.01f);
    if (q->b24 & 8) {
        if (!(p->w4 & 0xFF000000)) {
            func_0045E580(p);
            return;
        }
        q->b24 |= 8;
        if (!func_00440848(3)) {
            hit = func_003F8448(&b, &a, 0, q->w28, 0) != 0;
        }
    } else {
        l.w16 = q->w28;
        l.f28 = 1.0f;
        l.v = q->v;
        l.w20 = 1;
        l.w32 = 1;
        if (!func_00440848(3)) {
            hit = func_003F8448(&b, &a, 0, q->w28, &l) != 0;
        }
    }
    if (hit) {
        q->b24 |= 8;
    } else {
        p->pos = a;
    }
    if (q->b24 & 8) {
        q->h22++;
        p->f12 -= 18055.5546875f;
        if (p->f12 <= 0.0f) {
            func_0045E580(p);
            return;
        }
    } else {
        p->f12 += 14444.4443359375f;
    }
    f = (f32)q->h20 / 18.0f * 0.0044444446f + 0.08f;
    if (f < 0.0f) {
        f = 0.0f;
    }
    if (0.08f < f) {
        f = 0.08f;
    }
    if (q->b24 & 8) {
        f = f / ((f32)q->h22 / 7.0f + 1.0f);
    }
    p->w4 = (p->w4 & 0xFFFFFF) | ((s32)(f * 256.0f) << 24);
    q->v.z += 0.0002f;
    if (q->h20 >= 26 || (q->b24 & 8)) {
        q->v.x *= 0.95f;
        q->v.y *= 0.95f;
    }
    dir = -1.0f;
    if (q->b24 & 1) {
        dir = 1.0f;
    }
    if (q->b24 & 8) {
        q->v.z += 0.0002f;
        q->f16 += dir * -0.01f / (f32)q->h22;
    } else {
        q->f16 += dir * -0.01f;
    }
    if (q->f16 > 1.0f) {
        q->f16 -= 1.0f;
    }
    if (q->f16 < 0.0f) {
        q->f16 += 1.0f;
    }
    p->b8 = (s32)(q->f16 * 256.0f);
}
/* localdecomp:end func_0046BBE8 */
