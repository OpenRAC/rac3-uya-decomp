#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_4FB8C8;

typedef union {
    s128 q;
    Vec_4FB8C8 v;
} Q_4FB8C8;

typedef struct {
    u8 pad0[28];
    s32 x28;
    f32 f32;
} Pvar_4FB8C8;

typedef struct {
    u8 pad0[16];
    s128 pos;
    u8 pad32[17];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[50];
    Pvar_4FB8C8 *pv;
} Moby_4FB8C8;

typedef struct {
    u8 pad0[128];
    s128 v128;
    u8 pad144[8];
    f32 f152;
    u8 pad156[374];
    s16 h530;
    u8 pad532[2108];
    Moby_4FB8C8 *target;
    u8 pad2644[4];
    f32 f2648;
    u8 pad2652[2];
    s16 h2654;
    u8 pad2656[7012];
    s32 x9668;
} Player_4FB8C8;

extern Player_4FB8C8 D_001A4BE0[];
extern Moby_4FB8C8 *D_001F0368[];
extern f32 func_0040BFB0(void *a, void *b);
extern f32 func_004E56A8(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern s32 func_00440760(void *v, s32 a, s32 b);
extern s32 func_003F8448(void *a, void *b, s32 c, s32 d, s32 e);

void func_004FB8C8(void) {
    Player_4FB8C8 *pl;
    Player_4FB8C8 *pe;
    Player_4FB8C8 *pk;
    Moby_4FB8C8 *m;
    Moby_4FB8C8 *best_m;
    Pvar_4FB8C8 *pv;
    f32 best;
    f32 d;
    f32 lim;
    f32 a2;
    f32 c;
    f32 a;
    f32 b;
    f32 score;
    s32 i;
    Q_4FB8C8 v0;
    Q_4FB8C8 v1;

    D_001A4BE0[0].h2654 = 0;
    if (D_001A4BE0[0].h530 != 0) {
        return;
    }
    best = 100000000.0f;
    best_m = 0;
    for (i = 0; i < 32; i++) {
        s32 flag;

        m = D_001F0368[i];
        if (m == 0) {
            break;
        }
        pv = m->pv;
        if (m->h52 & 1) {
            continue;
        }
        if (!(m->h52 & 0x1000)) {
            continue;
        }
        pl = D_001A4BE0;
        if (3.0f < ((Vec_4FB8C8 *)&pl->v128)->z - ((Vec_4FB8C8 *)&m->pos)->z) {
            continue;
        }
        d = func_0040BFB0(&pl->v128, &m->pos);
        if (pv->f32 != 0.0f && pv->f32 < d) {
            continue;
        }
        if (16.0f < d) {
            continue;
        }
        a = 1.2217305f;
        if (pl->x9668 == 44) {
            a = 1.5707964f;
        }
        b = 1.3962634f;
        if (pl->x9668 == 1 || pl->x9668 == 29) {
            b = 0.08726646f;
            a = b;
        }
        a2 = pv->f32;
        pk = D_001A4BE0;
        c = pk->f152;
        lim = 16.0f;
        if (a2 != 0.0f) {
            lim = a2;
        }
        score = func_004E56A8(c, lim, a, b, m, &flag);
        if (flag != 0) {
            continue;
        }
        if (m->b49 == 0) {
            score += 10.0f;
        }
        if (pv->x28 >= 0 && func_00440760(&pk->v128, pv->x28, 0)) {
            continue;
        }
        if (score < best) {
            best = score;
            best_m = m;
        }
    }
    pe = D_001A4BE0;
    pe->target = best_m;
    if (best_m != 0) {
        v0.q = pe->v128;
        v0.v.z += 0.5f;
        v1.q = best_m->pos;
        if (func_003F8448(&v0, &v1, 2, 0, 0) == 0) {
            pe->f2648 = best;
            pe->h2654 = 1;
        }
    }
}
