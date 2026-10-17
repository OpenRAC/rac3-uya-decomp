#include "common.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_426250;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q426250;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q426250 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P426250;
typedef struct {
    u8 pad0[16];
    s32 f10;
} V426250;
typedef struct {
    u8 pad0[36];
    V426250 *v;
    u8 pad28[152 - 40];
    s32 f98;
} A426250;
typedef struct {
    u8 pad0[596];
    f32 range;
    u8 pad258[636 - 600];
    s32 team;
} B426250;
extern P426250 *D_002494B0[];
extern s32 func_00517AF0(P426250 *p);
extern f32 func_0045C850(void *a, void *b);
extern s32 func_004242A8(void *a, void *b, f32 *c);
f32 *func_00426250(A426250 *a, B426250 *b, Vec4_426250 *src) {
    Vec4_426250 tmp;
    Vec4_426250 cp;
    f32 *best;
    f32 *pos;
    f32 bestd;
    f32 d;
    s32 i;
    s32 r;

    best = 0;
    bestd = b->range * b->range;
    for (i = 0; i < 8; i++) {
        if (D_002494B0[i] == 0) {
            continue;
        }
        if (D_002494B0[i]->team == b->team) {
            continue;
        }
        if (func_00517AF0(D_002494B0[i]) == 0) {
            continue;
        }
        pos = D_002494B0[i]->pos;
        if (D_002494B0[i]->q != 0) {
            pos = D_002494B0[i]->q->pos;
        }
        tmp.x = pos[0] * 0.0009765625f;
        tmp.y = pos[1] * 0.0009765625f;
        tmp.z = pos[2] * 0.0009765625f;
        tmp.w = 0.0f;
        d = func_0045C850(src, &tmp);
        if (d < bestd) {
            a->f98 = 0;
            cp = *src;
            r = func_004242A8(&cp, &tmp, pos);
            a->f98 = a->v->f10;
            if (r == 0) {
                bestd = d;
                best = pos;
            }
        }
    }
    return best;
}
