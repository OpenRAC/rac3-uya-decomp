#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
} Q_4629D8;
typedef struct {
    u8 b0, b1, b2, b3;
    u32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    Q_4629D8 q;
} P_4629D8;

extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(P_4629D8 *);

void func_004629D8(P_4629D8 *p) {
    Q_4629D8 *q = &p->q;
    f32 k = 0.013f;

    q->f4 += q->fC * k;
    if (q->f4 <= 0.0f || func_0040BAC0(&p->hA)) {
        func_0045E580(p);
        return;
    }
    if (0.22f <= q->f4) {
        q->fC = -q->fC;
        q->f4 = q->f4 + q->fC * k;
    }
    p->fC += 8190.0f;
    p->x4 = (p->x4 & 0xFFFFFF) | ((s32)(q->f4 * 255.0f) << 24);
    q->f8 += 0.012f;
    if (1.0f < q->f8) {
        q->f8 -= 1.0f;
    }
    p->b8 = (s32)(q->f8 * 255.0f);
    p->f18 -= 0.02f;
}
