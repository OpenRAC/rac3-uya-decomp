#include "common.h"

typedef int u128_471248 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[4];
    s16 h14;
    s16 h16;
    f32 f18;
    f32 f1C;
} Q_471248;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_471248 v10;
    Q_471248 q;
} P_471248;
extern void *func_0045E438(s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern u8 *D_002212FC[];

P_471248 *func_00471248(u128_471248 *a, u128_471248 *b, s32 n) {
    P_471248 *p = func_0045E438(0x79);
    Q_471248 *q;
    if (p != 0) {
        p->b9 = 0x42;
        p->b3 = func_00440848(4) ? 0x48 : 0x44;
        p->b1 = 0;
        q = &p->q;
        p->b2 = *D_002212FC[0];
        p->fC = func_004408C0(0.05f, 0.15f) * 210000.0f;
        p->b8 = func_00440848(0xFF);
        p->hA = n;
        p->v10 = *a;
        *(u128_471248 *)q = *b;
        q->fC = func_004408C0(0.6f, 2.6f) * 0.00027777778f;
        q->f18 = p->fC + p->fC;
        q->h16 = func_00440878(0, 3);
        q->h14 = n / 2;
        q->f1C = func_00440978();
    }
    return p;
}
