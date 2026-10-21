#include "common.h"

typedef int s128_00473B38 __attribute__((mode(TI)));

typedef struct {
    s128_00473B38 v;
    s32 w10;
    s32 w14;
    s32 w18;
} Sub_00473B38;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    u8 padA[2];
    f32 fC;
    s128_00473B38 v10;
    Sub_00473B38 s20;
} S_00473B38;

extern s32 func_0013D3E0(void);
extern S_00473B38 *func_0046DF88(s32 type);
extern u8 *D_0021FD04[];

S_00473B38 *func_00473B38(s128_00473B38 *a0, s128_00473B38 *a1, s32 a2, s32 a3, f32 f) {
    S_00473B38 *q;
    Sub_00473B38 *s;

    q = func_0046DF88(0x1B);
    if (q != 0) {
        s = &q->s20;
        q->v10 = *a0;
        q->b8 = func_0013D3E0();
        q->b9 = 0x74;
        q->b3 = 0x48;
        q->fC = f;
        q->w4 = a2;
        q->b1 = 0;
        q->b2 = *D_0021FD04[0];
        s->w18 = a2 >> 24;
        q->s20.v = *a1;
        s->w10 = a3;
        s->w14 = a3;
    }
    return q;
}
