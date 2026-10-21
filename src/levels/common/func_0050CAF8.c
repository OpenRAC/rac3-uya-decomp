#include "common.h"

/* localdecomp:start func_0050CAF8 */
typedef struct {
    u8 pad0[52];
    u16 flags;
} Obj_50CAF8;

typedef struct {
    Obj_50CAF8 *a;
    Obj_50CAF8 *b;
    Obj_50CAF8 *c;
    Obj_50CAF8 *d;
    u8 pad10[24];
    s32 f28;
    u8 pad2C[36];
} Ent_50CAF8;

typedef struct {
    u8 pad0[3064];
    Obj_50CAF8 *f0BF8;
    u8 pad0BFC[4608 - 3068];
    Ent_50CAF8 e[7];
    u8 pad1430[6692 - 5168];
    Obj_50CAF8 *f1A24;
    u8 pad1A28[9700 - 6696];
    u8 f25E4;
    u8 pad25E5[10];
    u8 f25EF;
    u8 f25F0;
    u8 pad25F1[10372 - 9713];
    s16 f2884;
} G_50CAF8;

extern G_50CAF8 D_001A4BE0;

void func_0050CAF8(void) {
    s32 i;

    D_001A4BE0.f0BF8->flags &= ~1;
    for (i = 0; i < 7; i++) {
        G_50CAF8 *g = (G_50CAF8 *)((u8 *)&D_001A4BE0 + i * 80);
        if (g->e[0].a != 0) {
            g->e[0].a->flags &= ~1;
        }
        if (g->e[0].b != 0) {
            g->e[0].b->flags &= ~1;
        }
        if (g->e[0].c != 0) {
            g->e[0].c->flags &= ~1;
        }
    }
    if (D_001A4BE0.e[3].d != 0) {
        D_001A4BE0.e[3].d->flags &= ~1;
    }
    if (D_001A4BE0.f25E4 == 1 && D_001A4BE0.f1A24 != 0) {
        D_001A4BE0.f1A24->flags &= ~1;
    }
    if (D_001A4BE0.f2884 != 0) {
        if (D_001A4BE0.e[3].a != 0) {
            D_001A4BE0.e[3].a->flags |= 0x41;
        }
        if (D_001A4BE0.e[3].b != 0) {
            D_001A4BE0.e[3].b->flags |= 0x41;
        }
        if (D_001A4BE0.e[3].d != 0) {
            D_001A4BE0.e[3].d->flags |= 0x41;
        }
    }
    if ((D_001A4BE0.f25EF != 0 && D_001A4BE0.e[0].f28 == 9) || D_001A4BE0.f25F0 != 0) {
        if (D_001A4BE0.e[0].a != 0) {
            D_001A4BE0.e[0].a->flags |= 0x41;
        }
    }
}
/* localdecomp:end func_0050CAF8 */
