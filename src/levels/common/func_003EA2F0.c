#include "common.h"

typedef int Q_3EA2F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3EA2F0;
typedef struct {
    Q_3EA2F0 v0;
    V_3EA2F0 v10;
    u8 b20;
    u8 b21;
    u8 pad22[0xAA - 0x22];
    s16 hAA;
    u8 padAC[0x100 - 0xAC];
} G_3EA2F0;
typedef struct { u8 pad0[0xF8]; f32 fF8; } K_3EA2F0;
typedef struct {
    u8 pad0[0x30];
    V_3EA2F0 v30;
    s32 f40;
    K_3EA2F0 *f44;
    f32 f48;
    f32 f4C;
} S_3EA2F0;
typedef struct { f32 f0; f32 f4; u8 pad8[8]; f32 f10; f32 f14; } R_3EA2F0;
typedef struct { f32 f0; f32 f4; } U_3EA2F0;
typedef struct {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20[0x20];
    S_3EA2F0 s40;
    u8 pad90[0xA0 - 0x90];
    R_3EA2F0 rA0;
    U_3EA2F0 uB8;
} P_3EA2F0;
typedef struct {
    u8 pad0[0x30];
    V_3EA2F0 v30;
    u8 pad40[0x70 - 0x40];
    P_3EA2F0 *f70;
    u8 pad74[0x94 - 0x74];
    s32 f94;
} M_3EA2F0;
typedef struct {
    u8 pad0[0x40];
    V_3EA2F0 v40;
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5C[0x100 - 0x5C];
    s32 f100;
    u8 pad104[0x138 - 0x104];
    G_3EA2F0 *f138;
    f32 f13C;
    f32 f140;
} T_3EA2F0;
typedef struct {
    u8 pad0[0x50];
    M_3EA2F0 *f50;
    u8 pad54[0x150 - 0x54];
    T_3EA2F0 t;
    u8 pad[0x460 - 0x150 - sizeof(T_3EA2F0)];
} E_3EA2F0;

extern E_3EA2F0 D_001E2AC0[];
extern s32 D_001D545C;
extern G_3EA2F0 *D_001E009C;
extern s16 *D_0021DEA0[];
extern f32 func_004450C0(f32 *, f32, f32);
extern f32 func_003F1438(f32, f32, f32, f32, f32, f32 *);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C0F0(V_3EA2F0 *, V_3EA2F0 *, f32);
extern f32 func_0040BEF8(V_3EA2F0 *, V_3EA2F0 *);
extern f32 func_0040BF38(V_3EA2F0 *);
extern f32 func_0040C490(f32, f32);
extern s32 func_0040BAC0(s16 *);

/* localdecomp:start func_003EA2F0 */
void func_003EA2F0(M_3EA2F0 *m) {
    V_3EA2F0 pos;
    P_3EA2F0 *p;
    E_3EA2F0 *e;
    R_3EA2F0 *r;
    S_3EA2F0 *s;
    T_3EA2F0 *t;
    U_3EA2F0 *u;
    f32 f;
    f32 a;
    f32 b;
    G_3EA2F0 *target;

    p = m->f70;
    e = &D_001E2AC0[m->f94];
    r = &p->rA0;
    s = &p->s40;
    t = &e->t;
    u = &p->uB8;
    if (t->f138 != 0 && t->f100 == 43) {
        f = t->f138->v10.z - t->v40.z;
        if (f > t->f140) {
            f = t->f140;
        } else if (f < 0.0f) {
            f = 0.0f;
        }
        f = f / t->f140;
        b = f + f;
        a = f + 3.65f;
    } else {
        a = 4.64f;
        b = 2.0f;
    }
    func_004450C0(&e->f50->f70->rA0.f0, a, 0.13333334f);
    func_004450C0(&e->f50->f70->rA0.f10, b, 0.06666667f);
    func_004450C0(&e->f50->f70->s40.f4C, b - 0.5f, 0.13333334f);
    if (t->f100 == 43) {
        if (!(D_001D545C == 14 || D_001D545C == 7 || D_001D545C == 9)
            || ((target = t->f138) != 0 && target->b21 == 255)) {
            u->f0 = func_003F1438(u->f0, t->f58, 0.00125f, 0.175f, 0.0f, &u->f4);
        } else {
            V_3EA2F0 diff;
            V_3EA2F0 dir;
            V_3EA2F0 facing;
            G_3EA2F0 *best;
            f32 bestDist;
            s16 *list;

            best = 0;
            bestDist = 1000.0f;
            list = D_0021DEA0[target->b21];
            if (list != 0) {
                do {
                    G_3EA2F0 *mob = &D_001E009C[*list & 0x7FFF];
                    if (mob != target && (mob->hAA == 803 || mob->hAA == 758 || mob->hAA == 6596)) {
                        Q_3EA2F0 x, y;
                        f32 dot;
                        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(mob->v10));
                        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(target->v10));
                        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
                        __asm__("sqc2 %1, %0" : "=m"(diff) : "j"(y));
                        func_0040C0F0(&dir, &diff, 1.0f);
                        facing.x = func_0040C3C8(t->f58);
                        facing.y = func_0040C3E0(t->f58);
                        facing.z = 0.0f;
                        dot = func_0040BEF8(&dir, &facing);
                        if (dot > 0.0f) {
                            f32 d = func_0040BF38(&diff) - dot * 10.0f;
                            if (d < bestDist) {
                                best = mob;
                                bestDist = d;
                            }
                        }
                    }
                } while (*list++ >= 0);
            }
            if (best != 0) {
                Q_3EA2F0 x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(best->v10));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(target->v10));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(diff) : "j"(x));
                {
                    f32 ang = func_0040C490(diff.x, diff.y);
                    u->f0 = func_003F1438(u->f0, ang, 0.00125f, 0.175f, 0.0f, &u->f4);
                }
            } else if (s->f40 == 1) {
                u->f0 = func_003F1438(u->f0, s->f44->fF8, 0.00125f, 0.175f, 0.0f, &u->f4);
            } else {
                u->f0 = func_003F1438(u->f0, t->f58, 0.00125f, 0.175f, 0.0f, &u->f4);
            }
        }
    } else if (t->f100 == 36) {
        if (s->f40 == 1) {
            u->f0 = func_003F1438(u->f0, s->f44->fF8, 0.00125f, 0.175f, 0.0f, &u->f4);
        } else {
            u->f0 = func_003F1438(u->f0, t->f58, 0.00125f, 0.175f, 0.0f, &u->f4);
        }
    }
    s->v30.x = func_0040C3C8(u->f0);
    s->v30.y = func_0040C3E0(u->f0);
    s->v30.z = 0.0f;
    s->v30.w = s->v30.z;
    func_0040C0F0(&pos, &s->v30, -r->f0);
    pos.z += r->f10;
    {
        Q_3EA2F0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t->v40));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
    }
    if (func_0040BAC0(&p->h1E)) {
        m->v30 = pos;
    } else {
        m->v30 = pos;
    }
}
/* localdecomp:end func_003EA2F0 */
