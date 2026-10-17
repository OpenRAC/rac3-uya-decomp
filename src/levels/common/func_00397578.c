#include "common.h"

typedef struct { u8 pad[60]; u16 flags; } T_0023A780;
typedef struct { u8 pad[29]; u8 idx; u8 pad2[2]; } E_001E08D4;
typedef struct { u8 pad[16]; s32 v; u8 pad2[48]; u16 f; } C_00397578;
typedef struct { u8 pad[36]; C_00397578 *c; u8 pad2[12]; u16 f; u8 pad3[98]; s32 v; u8 pad4[100]; } M_00397578;
typedef struct { u8 pad[1224]; s32 a; s32 b; } O_00397578;
typedef struct { u8 pad[104]; O_00397578 *o; } S_00397578;

extern u16 **D_001D6764;
extern E_001E08D4 *D_001E08D4;
extern T_0023A780 *D_0023A780[];
extern u16 *D_0021C6A0[];
extern M_00397578 *D_001DFA1C;
extern s32 D_001DFA58;

void func_00397578(S_00397578 *self)
{
    O_00397578 *o = self->o;
    u16 *p;
    E_001E08D4 *e;
    M_00397578 *m;

    if (o->a != -1) {
        E_001E08D4 *base;
        p = D_001D6764[o->a];
        base = D_001E08D4;
        while (p != 0 && (((s16 *)p)[-1] >= 0 || p == D_001D6764[o->a]) && (e = &base[*p & 0x7fff]) != 0) {
            T_0023A780 *t;
            s32 x;
            p++;
            t = D_0023A780[e->idx];
            x = t->flags;
            t->flags = x & ~1;
        }
    }
    if (o->b != -1) {
        u16 *q = D_0021C6A0[o->b];
        while ((o->b & 0xff) != 0xff && o->b <= D_001DFA58 && q != 0
               && (((s16 *)q)[-1] >= 0 || q == D_0021C6A0[o->b])) {
            m = (M_00397578 *)((u8 *)D_001DFA1C + ((*q & 0x7fff) << 8));
            if (m == 0) break;
            q++;
            m->f &= 0xffbe;
            m->f |= m->c->f & 0x1000;
            m->v = m->c->v;
        }
    }
}
