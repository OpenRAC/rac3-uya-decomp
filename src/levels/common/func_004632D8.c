#include "common.h"

/* localdecomp:start func_004632D8 */
typedef int V128_004632D8 __attribute__((mode(TI)));
typedef struct {
    V128_004632D8 v0;
    s32 w10;
    s32 w14;
    s16 h18;
    s16 h1A;
    f32 f1C;
} Q_004632D8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V128_004632D8 v10;
    Q_004632D8 q;
} Node_004632D8;
extern u8 *D_00221170[];
extern Node_004632D8 *func_0045E438(s32);
extern s32 func_0013D3E0(void);
void func_004632D8(V128_004632D8 *a0, V128_004632D8 *a1, s32 a2, s32 a3, s32 a4, f32 f12) {
    Node_004632D8 *p;
    Q_004632D8 *q;
    p = func_0045E438(0x16);
    if (p != 0) {
        p->w4 = a2;
        p->fC = f12 * 0.2f;
        p->b1 = 0;
        p->b9 = 0x74;
        p->b3 = 0x44;
        p->b8 = func_0013D3E0();
        q = &p->q;
        p->b2 = *D_00221170[0];
        p->hA = a4;
        q->h18 = a4;
        q->f1C = (f12 - p->fC) / (f32)a4;
        q->w10 = a2;
        q->w14 = a3;
        q->v0 = *a1;
        p->v10 = *a0;
        ((f32 *)q)[3] = 0.00034444444f;
    }
}
/* localdecomp:end func_004632D8 */
