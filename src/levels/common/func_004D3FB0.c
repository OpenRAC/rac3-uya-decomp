#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 pos;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 f1C;
} E_004D3FB0;

typedef struct {
    u8 pad0[56];
    s32 idx;
    u8 pad3C[40];
    u8 *tab;
} S_001E6E00;

typedef struct {
    u8 pad0[320];
    s128 pos;
    u8 pad150[16];
    f32 m[3][4];
} S_004D3FB0;

extern S_001E6E00 D_001E6E00;
extern f32 D_001E76B0[];
extern u8 D_001E2A40[];
extern void func_003FFAC8(void);
extern void func_0012FF40(f32 *);
extern void func_00130088(f32 *, f32 *, f32);
extern void func_00130130(f32 *, f32 *, f32);
extern void func_0012FFE0(f32 *, f32 *, f32);

s32 func_004D3FB0(void)
{
    f32 mtx[16];
    E_004D3FB0 *e;
    s32 r;
    f32 *rot;
    S_004D3FB0 *c;
    s128 *pp;

    e = (E_004D3FB0 *)(D_001E6E00.tab + D_001E6E00.idx * 32);
    rot = &e->rx;
    r = ((u8 *)e)[12] != 0;
    D_001E76B0[0] = rot[3];
    func_003FFAC8();
    pp = (s128 *)D_001E2A40;
    *pp = e->pos;
    func_0012FF40(mtx);
    func_00130088(mtx, mtx, rot[0]);
    func_00130130(mtx, mtx, rot[1]);
    func_0012FFE0(mtx, mtx, rot[2]);
    c = (S_004D3FB0 *)(D_001E2A40 - 320);
    c->m[0][0] = -mtx[8];
    c->m[1][0] = -mtx[0];
    c->m[2][0] = mtx[4];
    c->m[0][1] = -mtx[9];
    c->m[1][1] = -mtx[1];
    c->m[2][1] = mtx[5];
    c->m[0][2] = -mtx[10];
    c->m[1][2] = -mtx[2];
    c->m[2][2] = mtx[6];
    return r;
}
