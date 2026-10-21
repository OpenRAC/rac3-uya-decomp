#include "common.h"

/* localdecomp:start func_003E39E0 */
typedef int Q_3E39E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3E39E0;
typedef struct { u8 pad0[48]; f32 f48; } R_3E39E0;
typedef struct {
    V_3E39E0 pos;
    V_3E39E0 vel;
    u8 pad20[32];
    V_3E39E0 v40;
    V_3E39E0 v50;
    V_3E39E0 v60;
    u8 pad70[32];
    f32 sB[4];
    f32 sA[4];
    u8 padB0[32];
    f32 fD0;
    u8 padD4[36];
    u8 cnt;
    u8 flag;
    u8 padFA[2];
    f32 fFC;
    f32 f100;
    f32 f104;
    f32 f108;
    s16 max;
    u8 pad10E[2];
    f32 f110;
    u8 pad114[12];
    R_3E39E0 r;
} P_3E39E0;
typedef struct { u8 pad0[96]; P_3E39E0 p; } M_3E39E0;
typedef struct { u8 pad0[0x24C]; f32 f24C; f32 f250; f32 f254; } X_3E39E0;
typedef struct { u8 pad0[0x70]; union { M_3E39E0 *m; X_3E39E0 *xx; }; u8 pad74[0x20]; s32 idx; } O_3E39E0;
typedef struct { u8 pad0[0x50]; void *w50; } E_3E39E0;
typedef struct { u8 pad0[32]; V_3E39E0 a; V_3E39E0 b; } T_3E39E0;
typedef struct { u8 pad0[240]; s32 iF0; u8 padF4[16]; s32 i104; u8 pad108[35]; u8 b12B; } T2_3E39E0;

extern u8 D_001E2AC0[];
extern s32 D_001DF890[2];
extern V_3E39E0 D_001EAAA0;
extern void func_003E2238(O_3E39E0 *, V_3E39E0 *);
extern void func_003E2AE8(O_3E39E0 *);
extern void func_003E3130(O_3E39E0 *, V_3E39E0 *);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_003F13A8(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0040BAF0(u8 *);
extern void func_0040BE68(void *, void *, void *, f32);
extern void func_003E38B8(O_3E39E0 *, V_3E39E0 *);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern f32 func_0040BF38(void *);
extern void func_003E6DA8(s32, f32, f32);

#define V_ V_3E39E0
#define Q_ Q_3E39E0
static __inline__ void vaddA_3E39E0(V_ *out, V_ *a, V_ *b) {
    Q_ x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}

static __inline__ void vaddB_3E39E0(V_ *out, V_ *a, V_ *b) {
    Q_ x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}

static __inline__ void vsubA_3E39E0(V_ *out, V_ *a, V_ *b) {
    Q_ x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}

static __inline__ void vsubB_3E39E0(V_ *out, V_ *a, V_ *b) {
    Q_ x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}

void func_003E39E0(O_3E39E0 *obj) {
    V_ v0;
    V_ v10;
    V_ v20;
    V_ old;
    V_ A;
    V_ B;
    V_ C;
    V_ D;
    V_ E;
    V_ F;
    V_ G;
    V_ H;
    M_3E39E0 *m;
    P_3E39E0 *p;
    u8 *t;
    T_3E39E0 *q;
    T2_3E39E0 *t2;
    R_3E39E0 *r;
    V_ *tb;
    V_ *vel;
    V_ *v60;
    X_3E39E0 *xx;
    f32 zero;
    f32 f20;
    f32 f21;

    t = (u8 *)(obj->idx * 1120 + (s32)D_001E2AC0);
    m = obj->m;
    zero = 0.0f;
    r = &m->p.r;
    v60 = &m->p.v60;
    vel = &m->p.vel;
    p = &m->p;
    t2 = (T2_3E39E0 *)(t + 336);
    tb = (V_ *)(t + 144);
    q = (T_3E39E0 *)(t + 96);
    func_003E2238(obj, &v10);
    func_003E2AE8(obj);
    func_003E3130(obj, &v0);
    *vel = v0;
    old = m->p.pos;
    f20 = func_0040BEF8(tb, v60);
    func_0040BE90(&A, tb, f20);
    vsubB_3E39E0(&B, v60, &A);
    p->f110 = func_0040BFB0(&A, vel);
    A.x = func_003F13A8(&m->p.sA[0], A.x, p->vel.x, p->f104, p->f108, zero);
    A.y = func_003F13A8(&m->p.sA[1], A.y, p->vel.y, p->f104, p->f108, zero);
    A.z = func_003F13A8(&m->p.sA[2], A.z, p->vel.z, p->f104, p->f108, zero);
    B.x = func_003F13A8(&m->p.sB[0], B.x, p->pos.x, p->fFC, p->f100, zero);
    B.y = func_003F13A8(&m->p.sB[1], B.y, p->pos.y, p->fFC, p->f100, zero);
    B.z = func_003F13A8(&m->p.sB[2], B.z, p->pos.z, p->fFC, p->f100, zero);
    vaddB_3E39E0(&m->p.pos, &m->p.pos, vel);
    vaddA_3E39E0(v60, &B, &A);
    func_0040BE90(&C, t + 128, p->fD0);
    if (p->flag) {
        p->cnt++;
        if (p->max < p->cnt) {
            p->cnt = p->max;
        }
        func_0040BE68(&D, p, v60, (f32)p->cnt / (f32)p->max);
        vaddA_3E39E0(&m->p.v40, &C, &D);
    } else {
        func_0040BAF0(&m->p.cnt);
        func_0040BE68(&D, p, v60, (f32)p->cnt / (f32)p->max);
        vaddA_3E39E0(&m->p.v40, &C, &D);
    }
    func_003E38B8(obj, &C);
    if (t2->b12B == 2) {
        func_0040BE90(&C, &q->a, 2.25f);
    } else if (t2->b12B == 1) {
        func_0040BE90(&C, &q->a, 0.4f);
    } else if (t2->i104 == 17) {
        __asm__("sq $0,%0" : "=m"(C));
    } else {
        func_0040BE90(&C, &q->a, 0.5f);
    }
    vaddB_3E39E0(&D, &v10, &C);
    func_0040BE90(&C, &q->a, r->f48);
    vaddB_3E39E0(&p->v50, &C, &p->pos);
    xx = ((O_3E39E0 *)((E_3E39E0 *)(obj->idx * 1120 + (s32)D_001E2AC0))->w50)->xx;
    f20 = xx->f254 * xx->f24C * (xx->f250 - 1.0f) + 0.35f;
    func_0040BE90(&E, &q->a, 20.0f);
    vaddA_3E39E0(&E, &D, &E);
    if (func_003F8448(&D, &E, D_001DF890[obj->idx], t2->iF0, 0)) {
        F = D_001EAAA0;
    } else {
        F = E;
    }
    func_0040BE90(&E, &q->a, 20.0f);
    vsubA_3E39E0(&E, &D, &E);
    if (func_003F8448(&D, &E, D_001DF890[obj->idx], t2->iF0, 0)) {
        E = D_001EAAA0;
    }
    vsubA_3E39E0(&G, &E, &F);
    if (func_0040BF38(&G) < f20 + f20) {
        vaddB_3E39E0(&H, &F, &E);
        func_0040BE90(&H, &H, 0.5f);
        p->v50 = H;
        vsubB_3E39E0(&G, &H, &p->pos);
        func_003E6DA8(obj->idx, func_0040BEF8(&G, &q->a), 0.006f);
    } else {
        vsubA_3E39E0(&G, &F, &p->pos);
        if (func_0040BF38(&G) <= (f21 = r->f48) + f20) {
            func_0040BE90(&H, &q->a, f20);
            vsubB_3E39E0(&H, &F, &H);
            p->v50 = H;
            vsubB_3E39E0(&G, &H, &p->pos);
            func_003E6DA8(obj->idx, func_0040BEF8(&G, &q->a), 0.006f);
        } else {
            f20 = func_0040BEF8(p, &q->b);
            if (func_0040BEF8(&E, &q->b) < f20) {
                E = p->pos;
            }
            func_0040BE90(&C, &q->a, f21);
            vaddA_3E39E0(&p->v50, &C, &E);
        }
    }
}
#undef V_
#undef Q_
/* localdecomp:end func_003E39E0 */
