#include "common.h"

/* localdecomp:start func_004665A0 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 v0;
    f32 f10;
    s16 h14;
    s16 h16;
    u8 b18;
    u8 pad19[3];
    s32 x1C;
} Q_4665A0;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    s128 v10;
    Q_4665A0 q;
} P_4665A0;

extern u8 *D_00221148[];
extern void *func_0045E438(s32);
extern s32 func_00445B88(f32, f32, f32, f32);
extern f32 func_004408C0(f32, f32);
extern s32 func_0013D3E0(void);

P_4665A0 *func_004665A0(s128 *pos, s128 *vel, u8 kind, s32 arg) {
    P_4665A0 *p;
    Q_4665A0 *q;
    f32 f;

    p = func_0045E438(42);
    if (p != 0) {
        p->v10 = *pos;
        q = &p->q;
        q->v0 = *vel;
        p->x4 = func_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        p->b1 = 0;
        p->b9 = 68;
        p->b3 = 68;
        f = func_004408C0(0.0f, 1.0f);
        q->f10 = f;
        p->b8 = f * 256.0f;
        p->b2 = D_00221148[0][func_0013D3E0() & 7];
        q->b18 = kind;
        q->h14 = 0;
        q->h16 = 0;
        if (kind < 5) {
            p->fC = func_004408C0(7000.0f, 10000.0f);
            p->hA = 18 - func_0013D3E0() % 15;
        } else {
            p->hA = 18;
            p->fC = 10000.0f;
        }
        q->x1C = arg;
    }
    return p;
}
/* localdecomp:end func_004665A0 */
