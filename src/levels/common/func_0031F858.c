#include "common.h"

/* localdecomp:start func_0031F858 */
typedef int Q_31F858 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31F858;
typedef struct {
    V4_31F858 vel;
    u8 pad10[8];
    u8 b24[8];
    f32 f32_;
} S_31F858;
typedef struct M_31F858 {
    u8 pad0[16];
    V4_31F858 pos;
    u8 pad20[104 - 32];
    S_31F858 *s;
    u8 pad6C[170 - 108];
    s16 h170;
    u8 padAC[184 - 172];
    struct M_31F858 *p184;
} M_31F858;
typedef struct {
    u8 pad0[24];
    M_31F858 *hit;
    u8 pad1C[4];
    V4_31F858 q32;
    V4_31F858 q48;
    V4_31F858 v64;
} G_31F858;
extern G_31F858 D_001EAA80;
extern void func_0040BE90(void *, void *, f32);
extern s32 func_003F9498(f32, void *, s32, M_31F858 *);
extern s32 func_004A72A8(s32, s32, M_31F858 *, s32);
extern s32 func_003F8448(void *, void *, s32, M_31F858 *, s32);
extern void func_0040C260(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_0040BA90(void *);
extern f32 func_0040BF38(void *);
extern s32 func_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                         s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00436220(M_31F858 *);

void func_0031F858(M_31F858 *m) {
    S_31F858 *s = m->s;
    V4_31F858 old;
    V4_31F858 up;
    V4_31F858 t;
    Q_31F858 x, y, z;
    M_31F858 *h;
    V4_31F858 *po;
    G_31F858 *g;

    if (s == 0) {
        return;
    }
    po = &old;
    *po = m->pos;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m->pos));
    __asm__("vmr32.wxyz %0, vf0" : "=j"(z));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->vel));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(up) : "j"(z));
    __asm__("sqc2 %1, %0" : "=m"(m->pos) : "j"(y));
    func_0040BE90(&up, &up, 0.0030555557f);
    {
        Q_31F858 a, b;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(s->vel));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(up));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(s->vel) : "j"(a));
    }
    if (func_003F9498(0.1f, &m->pos, 0, m)) {
        func_004A72A8(2, 0, m, m->h170);
        g = &D_001EAA80;
        h = g->hit;
        if (h != 0) {
            if ((u16)(h->h170 - 4254) >= 2 && h != m->p184) {
                m->pos = g->q48;
                func_0040C260(s, s, &g->v64);
                s->vel.z += s->vel.z;
                func_0040BE90(s, s, 0.20833334f);
            }
        } else {
            m->pos = g->q48;
            func_0040C260(s, s, &g->v64);
            s->vel.z += s->vel.z;
            func_0040BE90(s, s, 0.20833334f);
        }
    } else if (func_003F8448(po, &m->pos, 16, m, 0)) {
        func_004A72A8(2, 0, m, m->h170);
        g = &D_001EAA80;
        h = g->hit;
        if (h != 0) {
            if ((u16)(h->h170 - 4254) >= 2 && h != m->p184) {
                m->pos = g->q48;
                func_0040C260(s, s, &g->v64);
                s->vel.z += s->vel.z;
                func_0040BE90(s, s, 0.20833334f);
            }
        } else {
            m->pos = g->q32;
            func_0040C0F0(&t, &g->v64, 0.1f);
            {
                Q_31F858 a, b;
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(m->pos));
                __asm__("lqc2 %0, %1" : "=j"(b) : "m"(t));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
                __asm__("sqc2 %1, %0" : "=m"(m->pos) : "j"(a));
            }
            func_0040C260(s, s, &g->v64);
            s->vel.z += s->vel.z;
            func_0040BE90(s, s, 0.20833334f);
        }
    }
    if (func_0040BA90(s->b24) || func_0040BF38(s) < 0.008333334f) {
        func_004A72A8(1, 0, m, m->h170);
        func_0032FE90(&m->pos, 1, 10, 10, 10, 10, 30, 0, 1.5f, 0.0f, s->f32_, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x10001, 0, 0x804020, 0x806040, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F804020, 0x28802020, 0xFF6020, 0);
        func_00436220(m);
    }
}
/* localdecomp:end func_0031F858 */
