#include "common.h"
typedef struct { u8 p0[0x64]; s32 col; s32 row; } V_54A2A0;
typedef struct { u8 p0[0x68]; V_54A2A0 *v; u8 p1[0x28]; u8 b94; } M_54A2A0;
extern s32 D_003BDE20[][24];
void func_0054A2A0(M_54A2A0 *m) {
    V_54A2A0 *v = m->v;
    if (v->col != -1) {
        m->b94 = v->col;
        D_003BDE20[v->row][v->col] = 0;
    }
}
