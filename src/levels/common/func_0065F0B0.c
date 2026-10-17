#include "common.h"

typedef struct {
    u8 pad0[0x4C];
    s32 w4C;
    u8 pad50[8];
    s32 a[3];
    s32 b[3];
    s32 c[3];
} S_65F0B0_T;

typedef struct {
    u8 pad0[4];
    S_65F0B0_T *t;
} S_65F0B0_P;

typedef struct {
    u8 pad0[0x2544];
    s32 idx;
    u8 pad2548[0x10];
    S_65F0B0_P *p;
} S_65F0B0;

typedef struct {
    u8 pad0[0x128];
    s32 w128;
} S_65F0B0_G;

extern s32 D_001A5A50[][8];
extern s32 D_001A5AB0[][8];
extern s32 D_001A5B10[][8];
extern S_65F0B0_G D_001A5E50;

void func_0065F0B0(S_65F0B0 *self) {
    S_65F0B0_T *t = self->p->t;
    s32 idx = self->idx;
    s32 k;
    s32 v;
    for (k = 0; k < 3; k++) {
        t->a[k] = D_001A5A50[k][idx];
        t->b[k] = D_001A5AB0[k][idx];
        t->c[k] = D_001A5B10[k][idx];
    }
    v = D_001A5E50.w128;
    if (t->w4C < v - 1200) {
        t->w4C = v;
    }
}
