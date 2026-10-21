#include "common.h"

/* localdecomp:start func_003C4690 */
typedef int s128_3C4690 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    s32 w16;
    u8 pad14[0x44 - 0x14];
    u16 h68;
} C_3C4690;

typedef struct M_3C4690 M_3C4690;

typedef struct {
    u8 pad0[0x50];
    s32 w80;
    u8 pad54[0x550 - 0x54];
    M_3C4690 *p1360;
} V_3C4690;

struct M_3C4690 {
    u8 pad0[0x10];
    s128_3C4690 pos;
    u8 pad20[0x20 - 0x20];
    u8 b32;
    u8 pad21[0x24 - 0x21];
    C_3C4690 *p36;
    u8 pad28[0x31 - 0x28];
    u8 b49;
    u8 pad32[0x34 - 0x32];
    u16 h52;
    u8 pad36[0x68 - 0x36];
    V_3C4690 *p104;
    u8 pad6C[0x98 - 0x6C];
    s32 w152;
    u8 pad9C[0xC0 - 0x9C];
    u8 v192[0x30];
    u8 v240[8];
    f32 f248;
    u8 padFC[0x100 - 0xFC];
};

typedef struct {
    u8 pad0[0x102];
    u8 b258;
    u8 pad103[0x108 - 0x103];
    s32 w264;
} A_3C4690;

extern s16 *D_0021DEA0[];
extern M_3C4690 *D_001E009C;
extern s32 D_001E00D8;
extern void func_003C4C60(s32 a0, s32 idx, s128_3C4690 *vec, f32 *f);
extern void func_0040C638(void *a, void *b);
extern void func_0044CB08(M_3C4690 *a, M_3C4690 *b, s32 c, s32 d);

void func_003C4690(s32 a0, A_3C4690 *a1) {
    s128_3C4690 vec;
    f32 fl;
    s32 idx = 0;
    s16 *p = D_0021DEA0[a1->w264];
    M_3C4690 *m;
    M_3C4690 *o;
    M_3C4690 *n;
    V_3C4690 *v;
    C_3C4690 *c;
    C_3C4690 *c2;

    for (; (a1->w264 & 0xFF) != 255 && a1->w264 <= D_001E00D8 && p != 0
           && (p[-1] >= 0 || p == D_0021DEA0[a1->w264]); idx++, p++) {
        m = &D_001E009C[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        if (m->b32 == 254) {
            continue;
        }
        if (m->b32 == 253) {
            continue;
        }
        {
            m->h52 &= ~2;
            v = m->p104;
            func_003C4C60(a0, idx, &vec, &fl);
            m->pos = vec;
            m->f248 = fl;
            if (v->w80 != -1) {
                o = &D_001E009C[v->w80];
                o->pos = vec;
                o->f248 = fl;
                if ((o->h52 & 2) || o->b49 == 0 || (o->h52 & 0x80)) {
                    n = o->p104->p1360;
                    o->h52 &= ~0x43;
                    c = o->p36;
                    o->h52 |= c->h68 & 0x1000;
                    o->w152 = c->w16;
                    o->h52 &= ~0x80;
                    func_0040C638(m->v192, m->v240);
                    func_0040C638(o->v192, o->v240);
                    if (n != 0) {
                        n->h52 &= ~0x41;
                        c2 = n->p36;
                        n->h52 |= c2->h68 & 0x1000;
                        n->w152 = c2->w16;
                        n->h52 &= ~0x80;
                        func_0044CB08(o, n, 0, 0);
                    }
                }
            }
        }
    }
    a1->b258 = 1;
}
/* localdecomp:end func_003C4690 */
