#include "common.h"

/* localdecomp:start func_00460318 */
typedef int V128_00460318 __attribute__((mode(TI)));
typedef struct {
    V128_00460318 v0;
    s32 w10;
    s32 w14;
    s16 h18;
    s16 h1A;
    s32 w1C;
} Q_00460318;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    s32 wC;
    V128_00460318 v10;
    Q_00460318 q;
} Node_00460318;
extern u8 *D_00221128[];
extern Node_00460318 *func_0045E438(s32);
extern s32 func_0013D3E0(void);
Node_00460318 *func_00460318(V128_00460318 *a0, V128_00460318 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    Node_00460318 *p;
    Q_00460318 *q;
    p = func_0045E438(4);
    if (p != 0) {
        p->v10 = *a0;
        p->b9 = 0xA4;
        p->w4 = a2;
        if (a7 != 0) {
            p->b3 = 0x48;
        } else {
            p->b3 = 0x44;
        }
        p->b1 = 0;
        p->b2 = *D_00221128[0];
        p->b8 = func_0013D3E0();
        q = &p->q;
        p->wC = 0;
        p->v10 = *a0;
        q->v0 = *a1;
        p->hA = a4;
        q->w1C = a4;
        q->w10 = a2;
        q->w14 = a3;
        q->h18 = a6;
        q->h1A = a5;
    }
    return p;
}
/* localdecomp:end func_00460318 */
