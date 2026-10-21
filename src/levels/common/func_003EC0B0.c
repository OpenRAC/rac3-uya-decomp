#include "common.h"

typedef int Q_003EC0B0 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003EC0B0;

typedef struct {
    u8 p0[0x84];
    s16 s84;
    u8 p86[0xE];
    s32 i94;
} O_003EC0B0;

typedef struct {
    u8 p0[0x20];
    s32 i20;
    s16 s24;
    s16 s26;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 p34[4];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
} S_003EC0B0;

typedef struct {
    f32 f0, f4, f8;
    u8 pC[8];
    f32 f14;
    f32 f18;
    S_003EC0B0 *p1C;
} T_003EC0B0;

typedef struct {
    u8 p0[0x40];
    V4_003EC0B0 v40;
    u8 p50[0x30];
    V4_003EC0B0 v80;
} U_003EC0B0;

typedef struct {
    u8 p0[2];
    s16 s2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 p1C[0xC];
    f32 f28;
    u8 p2C[0x14];
} B_003EC0B0;

typedef struct {
    V4_003EC0B0 v0;
    u8 p10[0x30];
    V4_003EC0B0 v40;
    V4_003EC0B0 v50;
    V4_003EC0B0 v60;
    u8 p70[0x40];
    V4_003EC0B0 vB0;
    u8 pC0[0x10];
    f32 fD0;
    u8 pD4[0x4C];
} C_003EC0B0;

typedef struct {
    V4_003EC0B0 v0;
    V4_003EC0B0 v10;
    u8 p20[0xC];
    f32 f2C;
    f32 f30;
    u8 p34[0x5C];
} A_003EC0B0;

typedef struct {
    u8 p0[0x20];
    V4_003EC0B0 v20;
    s32 i30;
} D_003EC0B0;

typedef struct {
    V4_003EC0B0 v0;
    u8 p10[0x10];
    B_003EC0B0 b;
    C_003EC0B0 c;
    A_003EC0B0 a;
    D_003EC0B0 d;
} X_003EC0B0;

typedef struct {
    u8 p0[0x30];
    V4_003EC0B0 q30;
    u8 p40[0x30];
    X_003EC0B0 *p70;
} P_003EC0B0;

typedef struct {
    u8 p0[0x50];
    P_003EC0B0 *p50;
    u8 p54[0xFC];
    U_003EC0B0 sub;
    u8 p1E0[0x280];
} E_003EC0B0;

typedef struct {
    u8 p0[0x80];
    V4_003EC0B0 v80;
    u8 p90[8];
    f32 f98;
    u8 p9C[0x1630];
    f32 f16CC;
} G_003EC0B0;

typedef struct {
    u8 p0[0x1A0];
    s32 f1A0;
} C1_003EC0B0;

extern E_003EC0B0 D_001E2AC0[];
extern T_003EC0B0 *D_001DF884;
extern C1_003EC0B0 *D_001D52FC;
extern s32 D_001DFBC8;
extern V4_003EC0B0 D_001A4C00;
extern V4_003EC0B0 D_001A6120;
extern s32 D_001A4E18[];
extern s32 func_003EBE48(O_003EC0B0 *);
extern void func_003E6C58(O_003EC0B0 *);
extern s32 func_003E6CA8(O_003EC0B0 *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_004109B0(void *, void *, f32, f32);
extern s32 func_0045E3B8(s32, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040CF10(f32, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BF38(void *);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_003E6D50(s32, s32, f32, f32);
extern void func_003E6FF0(s32);
extern void func_003E6DA8(s32, f32, f32);
extern void func_003E6DF0(s32, s32, f32, f32);
extern void func_003E6EC8(s32, f32);
extern void func_003E6F00(s32, s32);
extern void func_003E6E60(s32, f32, f32, f32);

/* localdecomp:start func_003EC0B0 */
void func_003EC0B0(O_003EC0B0 *obj)
{
    V4_003EC0B0 t0;
    V4_003EC0B0 t1;
    V4_003EC0B0 t2;
    V4_003EC0B0 t3;
    E_003EC0B0 *ent = &D_001E2AC0[obj->i94];
    S_003EC0B0 *s = D_001DF884[obj->s84].p1C;
    U_003EC0B0 *sub = &ent->sub;

    if (!func_003EBE48(obj)) {
        G_003EC0B0 *g;
        V4_003EC0B0 *p;
        Q_003EC0B0 x, y, z;
        if (s->i20 != 0) {
            s->s26 = 1;
        }
        s->i20 = 0;
        func_003E6C58(obj);
        p = &D_001A4C00;
        g = (G_003EC0B0 *)((u8 *)p - 0x20);
        func_0040C0F0(&t0, p, g->f16CC);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(g->v80));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(z));
        func_004109B0((u8 *)p + 0x1520, &t0, g->f98, 0.0f);
        return;
    }
    if (func_003E6CA8(obj) <= 0) {
        if (s->i20 != 0) {
            s->s26 = 1;
        }
        s->i20 = 0;
        return;
    }
    if ((D_001D52FC->f1A0 & func_0045E3B8(4, 0)) && D_001DFBC8 > 10) {
        G_003EC0B0 *g;
        V4_003EC0B0 *p;
        if (s->i20 != 0) {
            s->s26 = 1;
        }
        s->i20 = 0;
        func_003E6C58(obj);
        p = &D_001A6120;
        g = (G_003EC0B0 *)((u8 *)p - 0x1540);
        func_004109B0(p, &g->v80, g->f98, 0.0f);
        return;
    }
    if (s->i20 < 2) {
        f32 ang;
        f32 d;
        f32 a2;
        V4_003EC0B0 *q;
        P_003EC0B0 *pp;
        X_003EC0B0 *x;
        A_003EC0B0 *a;
        B_003EC0B0 *b;
        C_003EC0B0 *c;
        D_003EC0B0 *dd;
        Q_003EC0B0 va, vb, vr;

        if (s->f2C == 0.0f && s->f30 == 0.0f) {
            s->f2C = D_001DF884[obj->s84].f14;
            s->f30 = D_001DF884[obj->s84].f18;
        }
        ang = func_0040C490(sub->v40.x - D_001DF884[obj->s84].f0, sub->v40.y - D_001DF884[obj->s84].f4);
        if (func_0040CFB0(s->f30, ang) > 0.034906585f) {
            s->f44 = func_0040CF10(s->f30, ang);
        }
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(sub->v40));
        t0.x = D_001DF884[obj->s84].f0;
        t0.y = D_001DF884[obj->s84].f4;
        t0.z = D_001DF884[obj->s84].f8;
        t0.w = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(t0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(vr) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(vr));
        d = func_0040BEF8(&t1, &sub->v80);
        func_0040BE90(&t2, &sub->v80, d);
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(t1));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(t2));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(vr) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(t3) : "j"(vr));
        s->f38 = func_0040BF38(&t3);
        s->f3C = -d;
        a2 = s->f2C;
        if (__builtin_fabsf(a2) == 1.5707964f) {
            s->f40 = 0.0f;
        } else {
            f32 tn = func_0040C3E0(a2) / func_0040C3C8(a2);
            s->f40 = s->f3C - s->f38 * tn;
        }
        q = &sub->v80;
        pp = ent->p50;
        pp->q30 = t0;
        x = pp->p70;
        a = &x->a;
        b = &x->b;
        c = &x->c;
        dd = &x->d;
        a->f2C = s->f38;
        a->f30 = s->f3C;
        b->f28 = s->f44;
        c->fD0 = s->f40;
        func_0040BE90(&t2, q, -a->f30);
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(t2));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(sub->v40));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(vr) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(x->c.v50) : "j"(vr));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(x->c.v50));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(t0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(vr) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(x->a.v0) : "j"(vr));
        x->a.v10 = x->a.v0;
        func_0040BE90(&t2, q, -c->fD0);
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(sub->v40));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(t2));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(vr) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(x->c.v40) : "j"(vr));
        x->c.vB0 = x->c.v40;
        x->c.v60 = x->c.v0 = sub->v40;
        x->v0 = pp->q30;
        x->d.v20 = pp->q30;
        dd->i30 = 0;
        b->f14 = 0.0f;
        b->f4 = c->fD0;
        b->f8 = a->f30;
        b->s2 = 0;
        b->f18 = b->f14;
        b->f10 = b->f14;
        b->fC = b->f14;
    }
    s->i20++;
    if (s->i20 > 200) {
        s->i20 = 200;
    }
    if (s->f38 != 0.0f) {
        func_003E6D50(obj->i94, 0, s->f38, 0.003f);
        func_003E6FF0(obj->i94);
    }
    if (s->f3C != 0.0f) {
        func_003E6DA8(obj->i94, s->f3C, 0.003f);
    }
    if (s->f40 != 0.0f) {
        func_003E6DF0(obj->i94, 0, s->f40, 0.005f);
    }
    if (s->f28 != 0.0f) {
        func_003E6EC8(obj->i94, s->f28 * 0.017453292f);
    }
    if (s->s24 == 0) {
        func_003E6F00(obj->i94, 0);
    }
    if (s->f44 != 0.0f) {
        func_003E6E60(obj->i94, s->f44, 60.0f, 60.0f);
    }
    D_001A4E18[0] = 10;
}
/* localdecomp:end func_003EC0B0 */
