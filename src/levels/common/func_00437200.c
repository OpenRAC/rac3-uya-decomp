#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
    s16 h8;
    s16 h10;
    s16 h12;
    s16 h14;
    unsigned long q[1];
} S_437200_B;

typedef struct {
    u8 pad0[28];
    S_437200_B *arr[1];
} S_437200_E;

typedef struct {
    u8 pad0[4];
    u8 idx[1];
} S_437200_I;

typedef struct {
    u8 pad0[8];
    u8 cnt;
    u8 pad9[19];
    S_437200_I *ix;
    u8 pad20[40];
    S_437200_E *arr[1];
} S_437200_H;

typedef struct {
    u8 pad0[8];
    u8 cnt;
} S_437200_C;

typedef struct {
    u8 pad0[20];
    S_437200_C *c;
    S_437200_H *h;
} S_437200_O;

extern void func_0040BBD0(void *, s32);
extern void func_0040BCB8(void *, void *, s32);
extern void func_0011F0A0(s32);

void func_00437200(S_437200_O *obj, s32 i, s32 j, S_437200_B *dest) {
    S_437200_B *src;
    s32 n;
    s32 m;
    s32 k;
    s32 n8;
    s32 m8;
    u16 t;
    s32 size;
    u8 *idx;
    unsigned long *sp;
    unsigned long *q;

    m = obj->h->cnt;
    n = obj->c->cnt;
    src = obj->h->arr[i]->arr[j];
    func_0040BBD0(dest, ((n + 3) * 8) & 0xFF0);
    n8 = n * 8;
    m8 = m * 8;
    dest->h6 = (n + src->h10 + src->h14 + 1) >> 1;
    dest->h8 = n8;
    t = src->h10;
    dest->h10 = t;
    dest->h12 = (t + n) * 8;
    dest->h14 = src->h14;
    {
        u8 *from = (u8 *)src + (m8 + 16);
        size = src->h6 * 16 - m8;
        if (size != 0) {
            func_0040BCB8((u8 *)dest + (n8 + 16), from, size);
        }
    }
    idx = obj->h->ix->idx;
    sp = src->q;
    for (k = 0; k < m; k++) {
        ((unsigned long *)dest)[*idx + 2] = *sp;
        idx++;
        sp++;
    }
    q = (unsigned long *)((u8 *)dest + dest->h6 * 16);
    if (*q == 0) {
        *q = 1;
    }
    func_0011F0A0(0);
}
