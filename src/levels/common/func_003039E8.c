#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v0;
    u8 p10[0x28];
    s32 w56;
    void *src;
    f32 f64;
    u8 p44[4];
    s32 w72;
} V_3039E8;

typedef struct {
    u8 p0[0x10];
    s128 pos;
    u8 b32;
    u8 p21[0xF];
    u8 b48;
    u8 b49;
    s16 h50;
    u16 h52;
    u8 p36[2];
    unsigned long d56;
    u8 p40[0x28];
    V_3039E8 *pVar;
    u8 p6C[0x88];
    f32 f244;
    f32 f248;
} M_3039E8;

extern M_3039E8 *func_00435E70(s32 oClass, s32 flags);
extern f32 func_0040C490(f32 a, f32 b);
extern f32 func_0040BF68(f32 *v);
extern s32 func_00468338(M_3039E8 *m, s32 a, u32 color, s32 b, f32 x, f32 y);
extern void func_00439610(M_3039E8 *m);

M_3039E8 *func_003039E8(M_3039E8 *src, f32 *dir, s128 *pos, f32 f) {
    M_3039E8 *m = func_00435E70(934, 128);
    V_3039E8 *v;

    if (m != 0) {
        m->b48 = 255;
        m->h50 = 255;
        m->b49 = 1;
        m->b32 = 0;
        v = m->pVar;
        m->d56 = src->d56;
        m->pos = *pos;
        v->v0 = *(s128 *)dir;
        v->w56 = 240;
        v->src = src;
        v->f64 = f;
        m->f248 = func_0040C490(dir[0], dir[1]);
        m->f244 = -func_0040C490(func_0040BF68(dir), dir[2]);
        v->w72 = func_00468338(m, -1, 0xF0208080, 96, 0.1f, 0.01f);
        func_00439610(m);
        m->b49 = 0;
        m->h52 |= 1;
    }
    return m;
}
