#include "common.h"

typedef int Q_3EA090 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3EA090;
typedef struct { Q_3EA090 v0; V_3EA090 v10; } G_3EA090;
typedef struct { Q_3EA090 m[4]; } X_3EA090;
typedef struct {
    u8 pad0[0xF0];
    s32 fF0;
    u8 padF4[0x100 - 0xF4];
    s32 f100;
    u8 pad104[0x138 - 0x104];
    G_3EA090 *f138;
    f32 f13C;
} T_3EA090;
typedef struct {
    u8 pad0[0x54];
    X_3EA090 *f54;
    u8 pad58[0x150 - 0x58];
    T_3EA090 t;
    u8 pad[0x2A0 - 0x150 - sizeof(T_3EA090)];
    s16 h2A0;
    u8 b2A2;
    u8 b2A3;
    u8 pad2A4[0x324 - 0x2A4];
    s32 f324;
    u8 pad328[0x460 - 0x328];
} E_3EA090;
typedef struct { s32 f0; f32 f4; f32 f8; s32 fC; } W_3EA090;
typedef struct {
    u8 pad0[0x30];
    V_3EA090 v30;
    s32 f40;
    s32 f44;
    f32 f48;
    f32 f4C;
    u8 pad50[8];
    f32 f58;
    f32 f5C;
} S_3EA090;
typedef struct { f32 f0; f32 f4; u8 pad8[8]; f32 f10; f32 f14; } R_3EA090;
typedef struct { f32 f0; s32 f4; G_3EA090 *f8; } U_3EA090;
typedef struct {
    Q_3EA090 q0;
    f32 f10;
    f32 f14;
    s32 f18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x10];
    W_3EA090 w30;
    S_3EA090 s40;
    R_3EA090 rA0;
    U_3EA090 uB8;
} P_3EA090;
typedef struct {
    Q_3EA090 v0;
    Q_3EA090 v10;
    Q_3EA090 v20;
    V_3EA090 v30;
    Q_3EA090 v40;
    u8 pad50[0x20];
    P_3EA090 *f70;
    u8 pad74[0x7E - 0x74];
    s16 h7E;
    u8 pad80[0x94 - 0x80];
    s32 f94;
} M_3EA090;

extern E_3EA090 D_001E2AC0[];
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C0F0(V_3EA090 *, V_3EA090 *, f32);
extern f32 func_0040C490(f32, f32);

/* localdecomp:start func_003EA090 */
void func_003EA090(M_3EA090 *m) {
    E_3EA090 *e;
    T_3EA090 *t;
    P_3EA090 *pv;
    S_3EA090 *s;
    R_3EA090 *r;
    W_3EA090 *w;
    P_3EA090 *p2;
    P_3EA090 *p3;
    U_3EA090 *u;

    e = &D_001E2AC0[m->f94];
    pv = m->f70;
    s = &pv->s40;
    t = &e->t;
    s->f4C = 1.5f;
    s->f48 = 0.20943952f;
    s->f58 = 0.0017453292f;
    s->f5C = -0.0043633231f;
    s->f40 = 0;
    s->f44 = t->fF0;
    r = &m->f70->rA0;
    r->f0 = 4.64f;
    r->f4 = 0.5f;
    r->f10 = 2.0f;
    r->f14 = 0.05f;
    p3 = m->f70;
    __asm__("sq $0,%0" : "=m"(p3->q0));
    p3->f10 = 0.01f;
    p3->f14 = 0.3f;
    p3->h1E = 120;
    p3->h1C = 0;
    p3->f18 = 0;
    w = &m->f70->w30;
    w->f4 = 0.02f;
    w->f8 = 0.2f;
    w->fC = 0;
    w->f0 = 0;
    p2 = m->f70;
    u = &p2->uB8;
    u->f4 = 0;
    m->v30 = *(V_3EA090 *)&e->f54->m[3];
    m->v0 = e->f54->m[0];
    m->v10 = e->f54->m[1];
    m->v20 = e->f54->m[2];
    m->v40 = m->v0;
    m->h7E = 0;
    if ((u32)(t->f100 - 43) < 2) {
        p2->uB8.f0 = t->f13C;
        u->f8 = t->f138;
        s->v30.x = func_0040C3C8(p2->uB8.f0);
        s->v30.y = func_0040C3E0(p2->uB8.f0);
        s->v30.z = 0.0f;
    } else {
        Q_3EA090 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m->v30));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t->f138->v10));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pv->s40.v30) : "j"(x));
        s->v30.z = 0.0f;
        s->v30.w = 0.0f;
        func_0040C0F0(&pv->s40.v30, &pv->s40.v30, 1.0f);
        p2->uB8.f0 = func_0040C490(s->v30.x, s->v30.y);
        u->f8 = t->f138;
    }
    e->b2A3 = 2;
    e->h2A0 = 1;
    { E_3EA090 *e2 = &D_001E2AC0[m->f94]; e2->f324 = 60; }
}
/* localdecomp:end func_003EA090 */
