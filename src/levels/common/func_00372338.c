#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00372338;
typedef struct {
    V4_00372338 v0;
    V4_00372338 v16;
    V4_00372338 v32;
    s32 w48;
    s32 w52;
    s32 w56;
    f32 f60;
} Q_00372338;
typedef struct {
    u8 pad0[16];
    V4_00372338 v16;
    u8 b32;
    u8 pad33[15];
    u8 b48;
    u8 b49;
    s16 h50;
    u8 pad52[4];
    unsigned long d56;
    u8 pad64[40];
    Q_00372338 *p104;
    u8 pad108[76];
    void *w184;
} O_00372338;
typedef struct {
    u8 pad0[56];
    unsigned long d56;
} S_00372338;
extern O_00372338 *func_00435E70(s32, s32);
/* localdecomp:start func_00372338 */
O_00372338 *func_00372338(S_00372338 *a, V4_00372338 b, V4_00372338 c, f32 d) {
    O_00372338 *p = func_00435E70(6249, 128);
    if (p != 0) {
        Q_00372338 *q;
        p->b48 = 255;
        p->h50 = 255;
        p->b49 = 1;
        p->b32 = 0;
        p->w184 = a;
        q = p->p104;
        p->d56 = a->d56;
        p->v16 = q->v0;
        q->v0 = b;
        q->v32 = c;
        q->f60 = d;
        q->w56 = 0;
        q->w52 = 0;
    }
    return p;
}
/* localdecomp:end func_00372338 */
