#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 p0[0x24];
    f32 f24;
} C_4DCFC8;

typedef struct {
    u8 p0[0x10];
    s128 pos;
    u8 p20[4];
    C_4DCFC8 *cls;
    u8 p28[4];
    f32 f2C;
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 p36[0x42];
    s32 w78;
    u8 p7C[0x44];
    u8 mC0[0x30];
    s128 vF0;
} M_4DCFC8;

typedef struct {
    u8 p0[0x80];
    s128 v80;
    s128 v90;
    u8 pA0[0x1984];
    M_4DCFC8 *moby;
    f32 phase;
    u8 p1A2C[0x894];
    s128 v22C0;
    u8 p22D0[0x2F0];
    M_4DCFC8 *p25C0;
    u8 p25C4[0x2E4];
    s16 timer;
    s16 type;
    s32 col;
} G_4DCFC8;

extern G_4DCFC8 D_001A4BE0;
extern u8 D_001D5470;

extern M_4DCFC8 *func_00435E70(s32, s32);
extern void func_00439610(M_4DCFC8 *);
extern void func_00437698(M_4DCFC8 *, s32, s128 *);
extern void func_004DF4A0(void);
extern void func_00437600(M_4DCFC8 *, s32, s128 *);
extern void func_0040C8C0(u8 *, s128 *);
extern void func_004450C0(f32 *, f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_0040BAC0(s16 *);
extern void func_004A7200(s32, s32, M_4DCFC8 *);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(s32, s32, f32);

void func_004DCFC8(void) {
    G_4DCFC8 *g;
    G_4DCFC8 *h;
    G_4DCFC8 *k;
    G_4DCFC8 *q;
    G_4DCFC8 *r;
    M_4DCFC8 *m;
    s32 c0;
    s32 c1;
    s32 c;
    f32 s;
    s128 v[1];
    s128 mtx[4];

    g = &D_001A4BE0;
    if (g->moby == 0) {
        m = func_00435E70(1204, 128);
        g->moby = m;
        if (m != 0) {
            m->w78 = 0x801432D7;
            g->col = 0x301432D7;
            g->moby->pos = g->v80;
            g->moby->vF0 = g->v90;
            g->moby->h32 = 64;
            g->moby->b31 = 1;
            g->moby->b30 = 0;
            g->moby->h34 = 0;
            g->moby->f2C *= 1.7f;
            g->moby->h34 |= 0x10;
            func_00439610(g->moby);
        }
    }
    h = &D_001A4BE0;
    if ((((u8 *)h->p25C0)[0x34] ^ 1) & 1) {
        func_00437698(h->p25C0, 7, v);
        h->v22C0 = v[0];
        func_004DF4A0();
        if (h->moby != 0) {
            func_00437600(h->p25C0, 7, mtx);
            h->moby->pos = mtx[3];
            func_0040C8C0(h->moby->mC0, mtx);
            func_00439610(h->moby);
            s = 1.7f;
            if (D_001D5470) {
                s = 3.1f;
            }
            if (h->timer) {
                s *= 1.4f;
            }
            func_004450C0(&h->moby->f2C, h->moby->cls->f24 * s, 0.02f);
        }
    }
    k = &D_001A4BE0;
    c0 = 0x281414C8;
    c1 = 0x1E00004B;
    k->phase = func_0040CEC8(k->phase, 0.049450997f);
    if (func_0040BAC0(&k->timer) == 0) {
        k->phase = func_0040CEC8(k->phase, 0.20362175f);
        switch (k->type) {
        case 1:
            c0 = 0x2814C814;
            c1 = 0x1E004B00;
            break;
        case 2:
            c0 = 0x2814C8C8;
            c1 = 0x1E004B4B;
            break;
        case 3:
            c0 = 0x323232FA;
            c1 = 0x1E000078;
            break;
        case 4:
            c0 = 0x28F01414;
            c1 = 0x1E4B0000;
            break;
        }
        q = &D_001A4BE0;
        if (q->timer >= 50 && (q->timer & 1)) {
            func_004A7200(q->type + 16, 0, q->p25C0);
        }
    }
    r = &D_001A4BE0;
    c = func_0040D020(c0, c1, func_0040C3E0(r->phase) * 0.5f + 0.5f);
    if (r->moby != 0) {
        r->moby->w78 = func_0040D020(r->moby->w78, c, 0.1f);
    }
    r->col = func_0040D020(r->col, c, 0.1f);
}
