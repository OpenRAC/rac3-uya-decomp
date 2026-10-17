#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_443;
typedef struct { V4_443 v; s32 a; s32 b; s32 pad; f32 f; s32 one; } S443;
void func_00443628(S443 *p, s32 a, s32 b, V4_443 *v, f32 f) {
    p->a = a;
    p->b = b;
    p->f = f;
    p->one = 1;
    p->v = *v;
}
