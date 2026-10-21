#include "common.h"

/* localdecomp:start func_0046F288 */
typedef int s128_46F288 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    f32 v[3];
    u8 b28;
    u8 b29;
    u8 b30;
    u8 b31;
} S_46F288p;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 x4;
    u8 b8;
    u8 b9;
    s16 h10;
    u8 pad[4];
    s128_46F288 v10;
    S_46F288p p;
} S_46F288;

extern S_46F288 *func_0045E438(int);
extern int func_00440848(int);
extern int func_00440878(int, int);
extern f32 func_004408C0(f32, f32);
extern u8 *D_002212C8[];

S_46F288 *func_0046F288(s128_46F288 *src, f32 *pos, f32 *vec, int a3, int a4, u8 a5, u8 a6, u8 a7, f32 scale, u8 a8, u8 a9)
{
    S_46F288 *s = func_0045E438(108);
    S_46F288p *p;
    int lo;
    f32 *v;
    int hi;

    if (s != 0) {
        s->v10 = *src;
        s->b3 = a3;
        s->b1 = 0;
        p = &s->p;
        s->b9 = 68;
        s->b8 = func_00440848(255);
        s->b2 = *D_002212C8[0];
        s->h10 = a4;
        p->x = pos[0];
        p->y = pos[1];
        p->z = pos[2];
        v = p->v;
        v[0] = vec[0];
        v[1] = vec[1];
        v[2] = vec[2];
        lo = func_00440878(0, 11);
        if ((u32)(a9 - 1) < 14) {
            hi = a9;
        } else {
            hi = func_00440878(0, 15);
        }
        p->b12 = lo | (hi << 4);
        p->b13 = func_00440878(1, 4) << 4;
        p->b14 = a4;
        if (a5 == 0) {
            p->b30 = func_004408C0(0.3f, 0.5f) * 128.0f;
        } else {
            p->b30 = a5;
        }
        if (a6 == 0) {
            p->b31 = func_004408C0(1.0f, 2.0f) * 128.0f;
        } else {
            p->b31 = a6;
        }
        if (a7 == 0) {
            p->b28 = func_004408C0(0.9f, 1.1f) * 0.083333336f * 128.0f;
        } else {
            p->b28 = a7;
        }
        if (a8 == 0) {
            p->b29 = func_004408C0(0.0f, 0.0125f) * 128.0f;
        } else {
            p->b29 = a8;
        }
        p->b15 = scale * 128.0f;
        s->x4 = ((hi + 112) << 24) | 0x103080;
    }
    return s;
}
/* localdecomp:end func_0046F288 */
