#include "common.h"

typedef struct { u8 p0[0x26C]; s32 w26C; u8 p270[0xCE]; u8 b33E; } X_3F0868;
typedef struct { u8 p0[0x68]; X_3F0868 *w68; } C_3F0868;
typedef struct { u8 p0[0x2FC]; s32 n; u8 p300[0x10]; C_3F0868 *list[1]; } S_3F0868;
typedef struct { u8 p0[0x68]; S_3F0868 *w68; } M_3F0868;

void func_003F0868(M_3F0868 *m, s32 v) {
    S_3F0868 *s = m->w68;
    s32 i;
    for (i = 0; i < s->n; i++) {
        X_3F0868 *x = s->list[i]->w68;
        x->w26C = v;
        x->b33E = 1;
    }
}
