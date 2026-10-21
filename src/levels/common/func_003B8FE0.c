#include "common.h"

/* localdecomp:start func_003B8FE0 */
typedef int Q_3B8FE0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    u8 v4[0xC];
    u8 v10[0x78];
    f32 f88;
    u8 pad8C[0x14];
    s32 iA0;
} Vars_3B8FE0;

typedef struct Moby_3B8FE0 {
    u8 pad0[8];
    f32 f8;
    f32 fC;
    Q_3B8FE0 q10;
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x32];
    Vars_3B8FE0 *vars;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x48];
    struct Moby_3B8FE0 *parent;
    u8 padBC[4];
    f32 fC0;
    f32 fC4;
    u8 padC8[0x28];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} Moby_3B8FE0;

extern u8 D_001E28C0[];
extern s32 func_004626E8(void *);
extern s32 func_004B6920(s32, s32, void *, s32);
extern f32 func_0041CDA8(f32, f32);
extern void func_0041CF50(void *, void *);
extern void func_00375BC0(void *, void *, void *, s32, s32);
extern void func_003B9348(void *, void *);
extern void func_00448A30(void *);
extern f32 func_0041C8F0(void *, void *);
extern void func_004536F0(void *);

void func_003B8FE0(Moby_3B8FE0 *m) {
    Vars_3B8FE0 *v;
    f32 t;

    v = m->vars;
    if (m->h34 & 0x80) {
        return;
    }
    if (m->b20 == 0) {
        v->iA0 = 0;
    }
    if (func_004626E8(m->parent) != 0) {
        if (v->iA0 == 0) {
            func_004B6920(0, 0, m, 0x1931);
            v->iA0 = 1;
        }
    } else {
        v->iA0 = 0;
    }
    m->q10 = m->parent->q10;
    if (m->fF8 != func_0041CDA8(m->parent->fC0, m->parent->fC4)) {
        m->fF8 = func_0041CDA8(m->parent->fC0, m->parent->fC4);
        func_0041CF50((u8 *)m + 0xC0, &m->fF0);
    }
    func_00375BC0(v, v->v4, v->v10, 0, func_004626E8(m->parent));
    func_003B9348(m, v);
    func_00448A30(m);
    if (v->f88 != 0.0f) {
        t = v->f88 / 5000.0f * 1024.0f;
        m->fC += __builtin_fabsf(t) * 0.55f;
        if (m->fF0 == 3.1415927f) {
            t = -t;
        }
        m->f8 += t * 0.5f;
    }
    if (m->b31 != 0) {
        if (func_0041C8F0(D_001E28C0, &m->q10) < 576.0f) {
            func_004536F0(m);
            m->b6F = 0x16;
        }
    }
}
/* localdecomp:end func_003B8FE0 */
