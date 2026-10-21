#include "common.h"

/* localdecomp:start func_004A54A8 */
extern s32 D_001E2A40[];
extern f32 func_0040BFB0(void *, void *);
extern s32 func_004A53D0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_004A54A8(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_001E2A40;
    f = func_0040BFB0(a, b);
    func_004A53D0(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_004A54A8 */
