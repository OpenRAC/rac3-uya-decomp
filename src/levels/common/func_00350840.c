#include "common.h"

typedef int u128_350840 __attribute__((mode(TI)));

typedef struct {
    s32 w[4];
} S_350840_V;

typedef struct {
    u8 pad0[0x310];
    u128_350840 hist[32];
    S_350840_V slots[64];
    s32 w910;
    s32 w914;
    s32 w918;
} S_350840_Vars;

typedef struct {
    u8 pad0[0x68];
    S_350840_Vars *vars;
} S_350840_Pv;

typedef struct {
    u8 pad0[0x10];
    u128_350840 pos;
    u8 pad20[0x98];
    S_350840_Pv *pv;
} S_350840;

extern void func_0041B730(S_350840_V *, S_350840_V *);

void func_00350840(S_350840 *self) {
    S_350840_Vars *v = self->pv->vars;
    S_350840_V z;
    v->w910 = 0;
    v->w914 = (v->w914 + 1) % 30;
    if (v->w918 < 30) {
        v->w918++;
    }
    z.w[0] = 0;
    z.w[1] = 0;
    z.w[2] = 0;
    z.w[3] = 0;
    func_0041B730(&v->slots[v->w914], &z);
    *(v->hist + v->w914) = self->pos;
}
