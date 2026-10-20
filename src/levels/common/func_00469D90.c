#include "common.h"
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 v[3];
    s32 x0C;
    f32 x10;
    f32 x14;
    s16 x18;
    s16 x1A;
    s16 x1C;
} S_469D90_Q;
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    s32 x4;
    u8 x8;
    u8 x9;
    s16 xA;
    f32 xC;
    s128 x10;
    S_469D90_Q q;
} S_469D90;
extern u8 *D_00221224[];
extern S_469D90 *func_0045E438(s32);
extern s32 func_00440848(s32);
S_469D90 *func_00469D90(s32 a0, void *pos, s32 life, s32 mode, s32 color, f32 *vel, f32 f12, f32 f13) {
    S_469D90 *p;
    S_469D90_Q *q;
    p = func_0045E438(67);
    if (p) {
        p->x10 = *(s128 *)pos;
        q = &p->q;
        q->x0C = a0;
        q->x10 = f12;
        q->x14 = f13;
        p->x1 = 0;
        p->x4 = color | 0x409B9B00;
        p->x9 = 68;
        p->x3 = 72;
        p->xC = 52500.0f;
        p->x8 = func_00440848(255);
        q->x1C = mode;
        q->x18 = 0;
        if (mode == 0) {
            p->x2 = D_00221224[0][0];
        } else {
            p->x2 = D_00221224[0][1];
        }
        if (mode == 0) {
            q->x1A = 127.0f / (f32)life;
        }
        if (vel) {
            q->v[0] = vel[0];
            q->v[1] = vel[1];
            q->v[2] = vel[2];
        }
        p->xA = life;
    }
    return p;
}
