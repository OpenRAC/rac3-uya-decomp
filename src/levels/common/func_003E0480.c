#include "common.h"

/* localdecomp:start func_003E0480 */
typedef int s128_3E0480 __attribute__((mode(TI)));

typedef struct M_003E0480 {
    u8 p0[0x10];
    s128_3E0480 x10;
    u8 p20[0x10];
    u8 x30;
    u8 x31;
    u8 p32[2];
    u16 x34;
    u8 p36[0x68 - 0x36];
    void *x68;
    u8 p6C[0xB8 - 0x6C];
    struct M_003E0480 *xB8;
    u8 pBC[4];
    u8 xC0[0x30];
    s128_3E0480 xF0;
} M_003E0480;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x10];
    M_003E0480 *x20[4];
    s32 x30[4];
    s32 x40[4];
} V_003E0480;

extern M_003E0480 *func_00435E70(s32, s32);
extern void func_0040BBA8(void *, s32, s32);
extern void func_00441FB8(M_003E0480 *, s32, s32);
extern s32 func_0044B550(M_003E0480 *);
extern void func_0040C638(void *, void *);
extern M_003E0480 **func_00445E80(M_003E0480 *);
extern void func_003E06D0(M_003E0480 *, V_003E0480 *);

s32 func_003E0480(M_003E0480 *m, s128_3E0480 *pos, s128_3E0480 *rot, M_003E0480 **list, s32 n) {
    M_003E0480 *o;
    V_003E0480 *v;
    M_003E0480 *e;
    M_003E0480 **l;
    s32 i;
    s32 j;

    o = func_00435E70(7721, 128);
    if (o != 0) {
        v = o->x68;
        func_0040BBA8(v, 0, 80);
        v->x8 = 0;
        func_00441FB8(o, 1, -1);
        o->xB8 = m;
        o->x30 = 255;
        o->x10 = *pos;
        v->x0 = m->x34;
        v->x4 = func_0044B550(m);
        m->x10 = *pos;
        m->xF0 = *rot;
        func_0040C638(m->xC0, &m->xF0);
        if (n >= 5) {
            n = 4;
        }
        m->x31 = 0;
        m->x34 |= 1;
        v->xC = n;
        for (i = 0; i < n; i++) {
            e = list[i];
            v->x20[i] = e;
            v->x30[i] = e->x34;
            v->x40[i] = func_0044B550(e);
            e->x31 = 0;
            e->x34 |= 1;
        }
        if (v->xC < 4) {
            l = func_00445E80(m);
            if (l != 0) {
                for (j = 0; j < 4; j++) {
                    if (l[j] != 0) {
                        e = l[j];
                        v->x20[v->xC] = e;
                        v->x30[v->xC] = e->x34;
                        v->x40[v->xC] = func_0044B550(e);
                        e->x31 = 0;
                        e->x34 |= 1;
                        if (++v->xC == 4) {
                            break;
                        }
                    }
                }
            }
        }
        func_003E06D0(o, v);
        return 1;
    }
    m->x10 = *pos;
    m->xF0 = *rot;
    func_0040C638(m->xC0, &m->xF0);
    m->x31 = 1;
    m->x34 &= ~1;
    return 0;
}
/* localdecomp:end func_003E0480 */
