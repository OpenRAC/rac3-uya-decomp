#include "common.h"

/* localdecomp:start func_00469378 */
typedef int V128_00469378 __attribute__((mode(TI)));
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
} Sub_00469378;
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
    V128_00469378 v10;
    Sub_00469378 s;
} Node_00469378;
extern u8 *D_00221210[];
extern f32 D_001D7F38;
extern Node_00469378 *func_0045E438(s32);
extern s32 func_00440848(s32);
Node_00469378 *func_00469378(V128_00469378 *a0, s32 a1, s32 a2, s32 a3) {
    Node_00469378 *p;
    Sub_00469378 *q;
    p = func_0045E438(0x3E);
    if (p != 0) {
        p->v10 = *a0;
        p->fC = 30000.0f;
        q = &p->s;
        p->w4 = 0x7F7F4040;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b1 = 0;
        D_001D7F38 = 30000.0f;
        p->b8 = func_00440848(0xFF);
        q->b2 = a2;
        q->b3 = a3;
        if (a2 >= 2) {
            a2 = 0;
        }
        p->b2 = D_00221210[0][a2];
        p->hA = a1;
        q->h0 = (s32)(127.0f / (f32)a1);
    }
    return p;
}
/* localdecomp:end func_00469378 */
