#include "common.h"

/* localdecomp:start func_003B8D10 */
typedef int Q_3B8D10 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    s32 i4;
    f32 f8;
    u8 padC[0x94];
    s32 iA0;
} Vars_3B8D10;

typedef struct {
    u8 pad0[0x10];
    Q_3B8D10 q10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 pad36[2];
    long d38;
    u8 pad40[0x28];
    Vars_3B8D10 *vars;
    u8 pad6C[0x4C];
    void *parent;
    u8 padBC[4];
    u8 vC0[0x30];
    union {
        Q_3B8D10 q;
        f32 f[4];
    } vF0;
} Moby_3B8D10;

extern Moby_3B8D10 *func_004452B0(s32, s32);
extern void func_00375B60(Moby_3B8D10 *, Vars_3B8D10 *, void *, void *, s32);
extern void func_003B8E10(Moby_3B8D10 *, Vars_3B8D10 *);
extern void func_0041CF50(void *, void *);

Moby_3B8D10 *func_003B8D10(Moby_3B8D10 *self) {
    Vars_3B8D10 *pv;
    Vars_3B8D10 *v;
    Moby_3B8D10 *m;
    void *rp;

    pv = self->vars;
    m = func_004452B0(0x192F, 0xC0);
    if (m != 0) {
        m->parent = self;
        v = m->vars;
        m->b30 = self->b30;
        m->h32 = self->h32;
        m->b31 = self->b31;
        m->b20 = 1;
        m->d38 = self->d38;
        m->q10 = self->q10;
        func_00375B60(m, v, (u8 *)v + 4, (u8 *)v + 0x10, 0);
        func_003B8E10(m, v);
        rp = &m->vF0;
        __asm__("sq $0,%0" : "=m"(m->vF0.q));
        m->vF0.f[2] = *(f32 *)((u8 *)self + 0xF8);
        if (pv->i4 < 0) {
            m->vF0.f[0] = 3.1415927f;
            v->f8 = -v->f8;
        }
        func_0041CF50(m->vC0, rp);
        m->h34 |= 0x104;
        v->iA0 = 0;
    }
    return m;
}
/* localdecomp:end func_003B8D10 */
