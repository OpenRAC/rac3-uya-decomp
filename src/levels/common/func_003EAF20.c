#include "common.h"

/* localdecomp:start func_003EAF20 */
typedef int Q_3EAF20 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, len;
} N_3EAF20;

typedef struct {
    s32 n;
    u8 pad4[12];
    N_3EAF20 e[1];
} Path_3EAF20;

typedef struct {
    u8 pad0[32];
    s32 i32;
    s32 i36;
    u8 pad28[16];
    u8 b56;
    u8 pad39;
    s16 h58;
    f32 f60;
    u8 pad40;
    u8 b65;
    u8 pad42[2];
    u8 b68;
    u8 pad45;
    s16 h70;
    s32 i72;
    u8 pad4C[20];
    f32 a96[8];
    s32 a128[8];
} T_3EAF20;

typedef struct {
    u8 pad0[28];
    T_3EAF20 *t;
} E_3EAF20;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    f32 f16;
    s16 h20;
    s16 h22;
} S_3EAF20;

typedef struct {
    u8 pad0[48];
    f32 f48;
} R_3EAF20;

typedef struct {
    f32 f0;
    f32 f4;
    u8 pad8[8];
    Q_3EAF20 q16;
} K_3EAF20;

typedef struct {
    K_3EAF20 k0;
    K_3EAF20 k32;
    S_3EAF20 s64;
    R_3EAF20 r88;
} P_3EAF20;

typedef struct {
    Q_3EAF20 q0;
    Q_3EAF20 q16;
    Q_3EAF20 q32;
    Q_3EAF20 q48;
} M_3EAF20;

typedef struct {
    Q_3EAF20 q0;
    Q_3EAF20 q16;
    Q_3EAF20 q32;
    Q_3EAF20 q48;
    u8 pad40[48];
    P_3EAF20 *p112;
    u8 pad74[16];
    s16 h132;
    u8 pad86[14];
    s32 i148;
} O_3EAF20;

typedef struct {
    u8 pad0[84];
    M_3EAF20 *m;
    u8 pad58[1120 - 88];
} G_3EAF20;

typedef struct {
    u8 pad0[176];
    f32 f176;
} W_3EAF20;

extern E_3EAF20 *D_001DF884;
extern W_3EAF20 D_001E7600[];
extern N_3EAF20 *D_0021F740[];
extern G_3EAF20 D_001E2AC0[];
extern u8 D_001D667B;
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFB0(void *, void *);
extern void func_004FC518(s32, s32);

void func_003EAF20(O_3EAF20 *obj) {
    T_3EAF20 *t;
    S_3EAF20 *s;
    R_3EAF20 *m;
    N_3EAF20 *path;
    N_3EAF20 *path2;
    G_3EAF20 *g;
    K_3EAF20 *k;
    P_3EAF20 *pp;
    s32 i;
    s32 k2;
    s32 j;
    s32 cnt;
    f32 f;
    f32 d;

    t = D_001DF884[obj->h132].t;
    t->b56 = 1;
    s = &obj->p112->s64;
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = 0;
    s->f12 = 0;
    s->f16 = 0;
    s->h20 = 0;
    if (t->i72 != 0 || t->h70 != -1) {
        s->h22 = (t->h70 == -1 || t->i72 < t->h70) ? t->i72 : t->h70;
    } else {
        s->h22 = t->h58;
    }
    m = &obj->p112->r88;
    for (j = 0; j < 8; j++) {
        t->a96[j] = 0;
        t->a128[j] = -1;
    }
    cnt = 0;
    f = func_0040C490(1.0f, D_001E7600->f176);
    m->f48 = f + f;
    if (t->b68 == 0) {
        if (t->i32 >= 0) {
            path = D_0021F740[t->i32];
            for (i = 0; i < *(s32 *)path; i++) {
                f = *(f32 *)((u8 *)path + (i << 4) + 28);
                if (0.0f < f) {
                    t->a96[cnt] = f;
                    if (180.0f < f) {
                        t->a96[cnt] = m->f48 * 57.2957764f;
                    }
                    t->a128[cnt] = i;
                    cnt++;
                }
                d = func_0040BFB0(&path[i + 1], &path[(i + 1) % *(s32 *)path + 1]);
                *(f32 *)((u8 *)path + (i << 4) + 28) = d;
                if (i < *(s32 *)path - 1) {
                    s->f8 += d;
                }
            }
        }
        D_001D667B = 1;
    }
    if (t->h58 > 0) {
        t->f60 = s->f8 / (f32)t->h58 * 60.0f;
    }
    if (t->i36 >= 0) {
        path2 = D_0021F740[t->i36];
        for (k2 = 0; k2 < *(s32 *)path2; k2++) {
            d = func_0040BFB0(&path2[k2 + 1], &path2[(k2 + 1) % *(s32 *)path2 + 1]);
            *(f32 *)((u8 *)path2 + (k2 << 4) + 28) = d;
            if (k2 < *(s32 *)path2 - 1) {
                s->f12 += d;
            }
        }
    }
    k = &obj->p112->k0;
    __asm__("sq $0, %0" : "=m"(k->q16));
    k->f0 = 0.03f;
    k->f4 = 0.2f;
    pp = obj->p112;
    __asm__("sq $0, %0" : "=m"(pp->k32.q16));
    pp->k32.f4 = 0.2f;
    pp->k32.f0 = 0.03f;
    g = &D_001E2AC0[obj->i148];
    obj->q48 = g->m->q48;
    obj->q0 = g->m->q0;
    obj->q16 = g->m->q16;
    obj->q32 = g->m->q32;
    if (t->b65 == 0) {
        func_004FC518(116, 1);
    }
    t->b68 = 1;
}
/* localdecomp:end func_003EAF20 */
