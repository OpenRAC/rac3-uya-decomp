#include "common.h"

/* localdecomp:start func_0046EE10 */
typedef int s128_46EE10 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 c;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    f32 f18;
    f32 f1C;
} S_46EE10p;
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
    s128_46EE10 v10;
    S_46EE10p p;
} S_46EE10;

extern S_46EE10 *func_0045E438(int);
extern int func_00440848(int);
extern int func_00440878(int, int);
extern f32 func_004408C0(f32, f32);
extern u8 *D_002212C4[];

/* The third argument is a byte value (stored to b3); retail reuses its variable for the particle record pointer. */
S_46EE10 *func_0046EE10(s128_46EE10 *src, f32 *pos, S_46EE10p *p, int a3, f32 scale) {
    S_46EE10 *s = func_0045E438(107);
    int v;

    if (s != 0) {
        s->v10 = *src;
        s->b3 = (int)p;
        s->b1 = 0;
        p = &s->p;
        s->b9 = 68;
        s->b8 = func_00440848(255);
        s->b2 = *D_002212C4[0];
        s->h10 = a3;
        p->x = pos[0];
        p->y = pos[1];
        p->z = pos[2];
        v = func_00440878(15, 11);
        p->c = (v << 16) + (v << 8) + v;
        p->b10 = func_00440878(1, 4);
        p->b11 = a3;
        p->b13 = 0;
        p->b12 = func_00440878(95, 127);
        p->f18 = func_004408C0(0.125f, 0.15f) * 0.5f * 210000.0f;
        p->f1C = func_004408C0(0.25f, 0.5f) * 210000.0f;
        p->b14 = scale * 128.0f;
        p->b15 = func_004408C0(0.9f, 1.1f) * 0.083333336f * 128.0f;
        p->b16 = func_004408C0(0.0f, 0.0125f) * 128.0f;
        p->b17 = 0;
        s->x4 = (p->b12 << 24) | 0x103080;
    }
    return s;
}
/* localdecomp:end func_0046EE10 */
