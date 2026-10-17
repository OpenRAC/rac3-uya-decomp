#include "common.h"

typedef int u128_46E4D8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xC];
    f32 fC;
    f32 f10;
    s16 h14;
    s16 h16;
    f32 f18;
    f32 f1C;
} Q_46E4D8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_46E4D8 v10;
    Q_46E4D8 q;
} P_46E4D8;
extern void *func_0045E438(s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern f32 func_00443140(void *, s32, s32, f32);
extern u8 *D_002212B0[];

P_46E4D8 *func_0046E4D8(u128_46E4D8 *a, u128_46E4D8 *b, s32 n) {
    P_46E4D8 *p = func_0045E438(102);
    Q_46E4D8 *q;
    u128_46E4D8 *v;
    if (p != 0) {
        p->b9 = 0x42;
        p->b3 = 0x44;
        p->b1 = 0;
        q = &p->q;
        v = &p->v10;
        p->b2 = *D_002212B0[0];
        p->fC = func_004408C0(0.03f, 0.175f) * 210000.0f;
        p->b8 = func_00440848(0xFF);
        p->hA = n;
        *v = *a;
        *(u128_46E4D8 *)q = *b;
        q->fC = func_004408C0(4.6f, 8.6f) * 0.00027777778f;
        q->f18 = p->fC + p->fC;
        q->h16 = func_00440878(0, 3);
        q->h14 = n / 2;
        q->f1C = func_00440978();
        q->f10 = func_00443140(v, 0, 0, 0.5f);
    }
    return p;
}
