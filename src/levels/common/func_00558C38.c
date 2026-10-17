#include "common.h"
typedef struct { u8 p0[0x14C]; u8 b14C; u8 p14D; s16 h14E; } V_558C38;
typedef struct { u8 p0[0x68]; V_558C38 *w68; } M_558C38;
void func_00558C38(M_558C38 *m) {
    V_558C38 *v = m->w68;
    if (v->b14C == 1) {
        v->h14E++;
        if (v->h14E > 300) {
            v->b14C = 0;
            v->h14E = 0;
        }
    }
}
