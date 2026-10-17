#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z;
    f32 fC;
    u8 b10;
    u8 r;
    u8 g;
    u8 b;
    f32 f14;
    f32 f18;
    s16 h1C;
    s16 h1E;
} B_466F98;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    u128_t q10;
    B_466F98 s;
} P_466F98;

extern P_466F98 *func_0045E438(s32);
extern s32 func_00440848(s32);
extern u8 *D_002211C8[];

P_466F98 *func_00466F98(u128_t *a0, f32 *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16) {
    P_466F98 *p = func_0045E438(44);
    if (p) {
        B_466F98 *q;
        p->q10 = *a0;
        p->fC = f12;
        *(f32 *)((u8 *)p + 0x1C) = f16;
        p->b1 = 0;
        p->w4 = (a3 << 24) | a4;
        p->b9 = 68;
        p->b3 = 72;
        p->b8 = func_00440848(255);
        p->b2 = *D_002211C8[0];
        p->hA = a2;
        q = &p->s;
        q->x = a1[0];
        q->y = a1[1];
        q->z = a1[2];
        q->b10 = a5;
        q->f14 = f13;
        q->f18 = f14;
        q->g = a4 >> 8;
        q->r = a4;
        q->b = a4 >> 16;
        q->h1C = a2;
        q->h1E = a3;
        q->fC = f15;
    }
    return p;
}
