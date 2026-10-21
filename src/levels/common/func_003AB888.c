#include "common.h"

/* localdecomp:start func_003AB888 */
typedef int Q_3AB888 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AB888;
typedef struct { V4_3AB888 r[3]; } M3_3AB888;

typedef struct {
    s32 a;
    s32 idx;
    u8 pad8[16];
} E_3AB888;

typedef struct {
    u8 pad0[8];
    s32 n;
    E_3AB888 *list;
    u8 pad10[0x1C - 0x10];
    f32 f1C;
    f32 f20;
    s32 i24;
    f32 f28;
    f32 f2C;
} C_3AB888;

typedef struct {
    u8 pad0[0x60];
    V4_3AB888 v60;
    u8 pad70[0x10];
} T_3AB888;

typedef struct {
    u8 pad0[0x44];
    s16 h44;
    u8 pad46[0x64 - 0x46];
    void *p64;
    C_3AB888 *cfg;
    u8 pad6C[4];
    V4_3AB888 pos;
    u8 pad80[0x20];
    T_3AB888 tab[23];
    u8 padC20[0x40];
    s32 iC60;
    u8 padC64[0xCE0 - 0xC64];
    s32 iCE0;
    u8 padCE4[8];
    s32 iCEC;
    u8 padCF0[0xD90 - 0xCF0];
    u8 xD90[16];
} K_3AB888;

typedef struct {
    u8 pad0[0x10];
    V4_3AB888 pos;
    u8 b20;
    u8 pad21[0x95 - 0x21];
    u8 b95;
    u8 pad96[0xC0 - 0x96];
    M3_3AB888 mC0;
    u8 padF0[8];
    f32 fF8;
} O_3AB888;

extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_0040BA90(void *);
extern void func_0044B5C8(void *, void *, s32, f32, f32);
extern void func_00442038(void *, s32);
extern f32 func_0040BF68(void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C920(void *, void *);
extern void func_00437698(void *, s32, void *);
extern f32 func_0040C490(f32, f32);
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_00447748(void *, void *);
extern void func_003AB820(void *, void *, void *, void *);

void func_003AB888(O_3AB888 *o, K_3AB888 *c)
{
    V4_3AB888 dir;
    V4_3AB888 v10;
    V4_3AB888 d20;
    V4_3AB888 v30;
    V4_3AB888 d40;
    V4_3AB888 d50;
    V4_3AB888 v60;
    M3_3AB888 m70;
    M3_3AB888 mA0;
    M3_3AB888 mD0;
    V4_3AB888 v100;
    C_3AB888 *cfg = c->cfg;
    E_3AB888 *e;
    T_3AB888 *t;
    s32 i;
    f32 ang;
    f32 f;
    f32 len;
    f32 g;

    if (cfg->n == 0) {
        return;
    }
    ang = func_0040CEC8(o->fF8, cfg->f1C);
    dir.x = func_0040C3C8(ang);
    dir.y = func_0040C3E0(ang);
    dir.z = 0.0f;
    func_0040C2D0(&v10, c->xD90, &o->mC0);
    {
        Q_3AB888 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v10));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(v10) : "j"(z));
    }
    {
        Q_3AB888 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v10));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d40) : "j"(z));
    }
    d50 = d40;
    d50.z = 0.0f;
    func_0040C0F0(&d50, &d50, 1.0f);
    if (o->b20 < 2 || c->iCE0 == 0
        || (c->iCEC <= 0 && (o->b95 == 3 || c->h44 != 1
                             || d50.x * dir.x + d50.y * dir.y < cfg->f20))) {
        func_0040BA90(&c->iC60);
        if (c->iC60 < cfg->i24) {
            c->iC60 = cfg->i24;
        }
        e = cfg->list;
        for (i = 0; i < cfg->n; i++) {
            t = &c->tab[e->idx];
            __asm__("sq $0,%0" : "=m"(t->v60));
            func_0044B5C8(c->p64, t, e->a, 0.03f, 0.3f);
            e++;
        }
        return;
    }
    if (o->b95 == 3) {
        func_0040BA90(&c->iC60);
        if (c->iC60 < cfg->i24) {
            c->iC60 = cfg->i24;
        }
    } else if (func_0040BA90(&c->iC60) != 0 && o->b95 != 2) {
        func_00442038(o, 2);
    }
    len = func_0040BF68(&d40);
    if (len < cfg->f28 * 0.5f + cfg->f2C) {
        f = cfg->f2C - len;
    } else {
        f = cfg->f28 * -0.5f;
    }
    if (c->iCEC > 0) {
        g = (f32)c->iCEC / (f32)c->iCE0;
        g = f + cfg->f28 * (1.0f - g);
    } else {
        g = f;
    }
    func_0040BE90(&v100, &d50, g);
    {
        Q_3AB888 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v100));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(c->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(v60) : "j"(z));
    }
    func_0040C920(&mD0, &o->mC0);
    __asm__("sq $0,%0" : "=m"(v30));
    e = cfg->list;
    for (i = 0; i < cfg->n; i++) {
        V4_3AB888 *u;
        t = &c->tab[e->idx];
        func_00437698(c->p64, e->a, &v10);
        u = &t->v60;
        {
            Q_3AB888 x, y, z;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v60));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v10));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(d20) : "j"(z));
        }
        v30.y = -func_0040C490(func_0040BF68(&d20), d20.z);
        v30.z = func_0040C490(d20.x, d20.y);
        func_0040C638(&m70, &v30);
        func_0040C960(&mA0, &mD0, &m70);
        func_00447748(&mA0, u);
        func_003AB820(o, c, e, u);
        func_0044B5C8(c->p64, t, e->a, 0.03f, 0.3f);
        e++;
    }
}
/* localdecomp:end func_003AB888 */
