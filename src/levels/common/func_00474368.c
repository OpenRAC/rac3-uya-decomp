#include "common.h"

/* localdecomp:start func_00474368 */
typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s32 count;
    s32 ready;
    s32 pad[2];
} PathHeader;

extern PathHeader *D_0021F740[];
extern f32 func_0040BFB0(Vec4 *, Vec4 *);

void func_00474368(s32 idx, s32 force) {
    PathHeader *p;
    Vec4 *pts;
    s32 i;

    if (idx == -1) return;
    p = D_0021F740[idx];
    if (p->ready != 0 && force == 0) return;
    pts = (Vec4 *)p;
    for (i = 0; i < p->count - 1; i++) {
        *(f32 *)((s32)p + (i << 4) + 28) = func_0040BFB0(&pts[i + 1], &pts[(i + 1) % p->count + 1]);
    }
    p->ready = 1;
}
/* localdecomp:end func_00474368 */
