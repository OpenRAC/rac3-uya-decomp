#include "common.h"

typedef int Q_35D9C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35D9C0;

typedef struct {
    V4_35D9C0 vel;
    u8 pad10[4];
    s32 timer;
    u8 pad18[4];
    s32 i28;
    u8 pad20[4];
    f32 f36;
    s32 i40;
} S_35D9C0;

typedef struct {
    u8 pad0[16];
    V4_35D9C0 pos;
    u8 state;
    u8 pad21[104 - 33];
    S_35D9C0 *s;
    u8 pad6C[170 - 108];
    u16 h170;
} M_35D9C0;

typedef struct {
    V4_35D9C0 v;
    u8 pad10[8];
    u8 b24;
    u8 b25;
    u16 h26;
    u8 pad1C[20];
} H_35D9C0;

typedef struct {
    u8 pad0[24];
    s32 hit;
    u8 pad1C[4];
    V4_35D9C0 q32;
} G_35D9C0;

typedef struct {
    u8 pad0[16];
    s32 i16;
} C_35D9C0;

typedef struct {
    u8 pad0[36];
    C_35D9C0 *p36;
    u8 pad28[152 - 40];
    s32 i152;
} P_35D9C0;

typedef struct {
    u8 pad0[128];
    V4_35D9C0 v128;
    u8 pad90[9664 - 144];
    P_35D9C0 *p;
} W_35D9C0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[238];
} T_35D9C0;

extern W_35D9C0 D_001A4BE0;
extern G_35D9C0 D_001EAA80;
extern u8 D_00142617[];
extern T_35D9C0 D_002C5640[];
extern s32 func_004C7670(void);
extern void func_004C6EC8(void *, void *);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_00443628(void *, void *, s32, void *, f32);
extern s32 func_003FB1D0(void *, s32, void *, void *, f32);
extern f32 func_0040C018(void *, void *);
extern void func_0035DDD0(void *);
extern s32 func_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                         s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00436220(void *);
extern s32 func_0040D0C0(void *, f32);
extern void func_0035E1D0(void);
extern void func_004026A0(void *, void *);
extern void func_0035E2F8(void *, void *, void *);

/* localdecomp:start func_0035D9C0 */
static __inline__ void vadd_35D9C0(V4_35D9C0 *a, V4_35D9C0 *b) {
    Q_35D9C0 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(x));
}


void func_0035D9C0(M_35D9C0 *m) {
    S_35D9C0 *s = m->s;
    V4_35D9C0 old;
    V4_35D9C0 t;
    H_35D9C0 h;
    G_35D9C0 *g;
    V4_35D9C0 *po;
    V4_35D9C0 *pq;

    switch (m->state) {
    case 0:
        po = &old;
        *po = m->pos;
        vadd_35D9C0(&m->pos, &s->vel);
        if (func_004C7670()) {
            func_004C6EC8(&m->pos, &m->pos);
        }
        if (m->pos.x < 2.0f || m->pos.x > 1021.0f ||
            m->pos.y < 2.0f || m->pos.y > 1021.0f ||
            m->pos.z < 2.0f || m->pos.z > 1021.0f) {
            func_00436220(m);
            return;
        }
        s->timer++;
        D_001A4BE0.p->i152 = 0;
        if (func_003F8448(po, &m->pos, 32, m, 0)) {
            g = &D_001EAA80;
            if (g->hit == 0 || g->hit != s->i28) {
                m->pos = g->q32;
                m->state = 1;
                pq = &g->q32;
                t = s->vel;
                func_0040BE90(&t, &t, 3.0f);
                t.w = 5627.925f;
                func_00443628(&h, m, s->i40, &t, s->f36);
                h.b24 = 0;
                h.b25 = 1;
                h.h26 = m->h170;
                if (g->hit != 0) {
                    if (g->hit != s->i28) {
                        func_003FB1D0(pq, 0, m, &h, 1.0f);
                    }
                } else {
                    func_003FB1D0(pq, 0, m, &h, 0.6f);
                }
            }
        }
        D_001A4BE0.p->i152 = D_001A4BE0.p->p36->i16;
        if (s->timer > 180) {
            func_00436220(m);
            return;
        }
        if (func_0040C018(&m->pos, &D_001A4BE0.v128) > 6400.0f) {
            func_00436220(m);
            return;
        }
        break;
    case 1:
        if (D_00142617[0][D_002C5640].unk1 >= 2) {
            func_0035DDD0(&m->pos);
        } else {
            func_0032FE90(&m->pos, 0, 5, 2, 2, 2, 2, 0, 0.2f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0xFF6430, 0);
        }
        func_00436220(m);
        return;
    }
    t = m->pos;
    t.w = 0.5f;
    if (func_0040D0C0(&t, 96.0f) > 0) {
        func_004026A0(func_0035E1D0, m);
        h.v = m->pos;
        func_0035E2F8(m, &h, &old);
    }
}
/* localdecomp:end func_0035D9C0 */
