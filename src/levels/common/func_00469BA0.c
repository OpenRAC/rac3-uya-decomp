#include "common.h"

typedef int u128_469BA0 __attribute__((mode(TI)));
typedef struct {
    f32 f0;
    f32 f4;
    s32 x8;
    f32 fC;
    f32 f10;
} Q_469BA0;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_469BA0 v10;
    Q_469BA0 q;
} P_469BA0;
extern void *func_0045E438(s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern s32 func_0013D3E0(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern u8 *D_00221220[];

P_469BA0 *func_00469BA0(u128_469BA0 *a, s32 color, f32 scale, f32 z) {
    P_469BA0 *p = func_0045E438(66);
    Q_469BA0 *q;
    f32 ang;
    f32 r;
    s32 c;

    if (p != 0) {
        p->v10 = *a;
        if (color == -1) {
            c = ((func_00440848(6) + 20) << 24) | 0x808080;
        } else {
            c = color;
        }
        p->x4 = c;
        p->b9 = 33;
        p->b3 = 72;
        p->b1 = 1;
        if (func_00440848(256) & 1) {
            p->b2 = D_00221220[0][0];
        } else {
            p->b2 = D_00221220[0][1];
        }
        p->b8 = func_0013D3E0();
        q = &p->q;
        p->hA = 4;
        p->fC = scale * 210000.0f;
        ang = func_00440978();
        r = func_004408C0(0.0015f, 0.0025f);
        q->f0 = func_0040C3C8(ang) * r;
        q->f4 = func_0040C3E0(ang) * r;
        q->x8 = 0;
        q->f10 = z;
    }
    return p;
}
