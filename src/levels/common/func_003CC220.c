#include "common.h"

/* localdecomp:start func_003CC220 */
typedef struct M_3CC220 M_3CC220;

typedef struct {
    u8 pad0[0xB0];
    u8 bB0[0xC4 - 0xB0];
    M_3CC220 *tgt;
    u8 padC8[0xD4 - 0xC8];
    f32 fD4;
} V_3CC220;

struct M_3CC220 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3CC220 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
};

typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x30 - 0x1C];
} L_3CC220;

typedef struct {
    u8 pad0[0x18];
    M_3CC220 *m18;
} G_3CC220;

extern M_3CC220 *D_001EAA98[];
extern G_3CC220 D_001EAA80;
extern void func_0040C0F0(f32 *, void *, f32);
extern void func_00443628(L_3CC220 *, M_3CC220 *, int, f32 *, f32);
extern void func_004C76B8(void);
extern void func_004C76F0(void);
extern int func_003F8448(int, void *, int, M_3CC220 *, L_3CC220 *);
extern void func_00443840(M_3CC220 *, L_3CC220 *);
extern void func_003CC4F0(void *, int, int, int, M_3CC220 *, int);

void func_003CC220(M_3CC220 *m, int a1) {
    f32 buf[4];
    L_3CC220 l;
    void *pos = m->pos;
    V_3CC220 *v = m->vars;
    M_3CC220 *p;
    int r;

    func_0040C0F0(buf, v->bB0, 1.0f);
    func_00443628(&l, m, 0x410001, buf, v->fD4);
    l.b18 = 5;
    l.h1A = m->hAA;
    l.b19 = 3;
    func_004C76B8();
    r = func_003F8448(a1, pos, 16, m, &l);
    if (r != 0) {
        p = D_001EAA98[0];
        if (p != 0 && p->hAA == 6253 && p->b20 != 2 && p->b20 != 5) {
            p->b20 = 4;
        }
    }
    func_004C76F0();
    if (r == 0) {
        return;
    }
    if (D_001EAA80.m18 != 0) {
        if (D_001EAA80.m18 != v->tgt && (D_001EAA80.m18->h34 & 0x4000)) {
            func_0040C0F0(buf, v->bB0, 1.0f);
            func_00443628(&l, m, 0x410001, buf, v->fD4);
            l.b18 = 5;
            l.b19 = 3;
            l.h1A = m->hAA;
            func_00443840(D_001EAA80.m18, &l);
            func_003CC4F0(m->pos, 30, 10, 1, m, v->tgt != 0);
        }
        if (D_001EAA80.m18 != 0) {
            m->b20 = 2;
            return;
        }
    }
    func_003CC4F0(m->pos, 20, 5, 0, m, v->tgt != 0);
    m->b20 = 2;
}
/* localdecomp:end func_003CC220 */
