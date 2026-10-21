#include "common.h"

/* localdecomp:start func_00669978 */
typedef struct { s32 a; s32 b; s32 c; s32 d; } Sub_00669978;
typedef struct { s32 x0; s32 x4; Sub_00669978 s; } S_00669978;
extern s32 D_001A5E58[];

s32 func_00669978(s32 a0, s32 a1, s32 a2, s32 a3, S_00669978 *t0) {
    Sub_00669978 *q;
    if (t0 == 0) {
        return -1;
    }
    q = &t0->s;
    t0->x4 = D_001A5E58[0];
    q->a = a0;
    q->b = a1;
    q->d = a3;
    q->c = a2;
    return 0x18;
}
/* localdecomp:end func_00669978 */
