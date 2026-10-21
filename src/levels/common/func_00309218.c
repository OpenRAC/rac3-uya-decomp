#include "common.h"

/* localdecomp:start func_00309218 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 f[6];
    u8 b24;
    u8 pad25;
    s16 h26;
    u8 c[4];
    s128 q;
    s16 h48;
    s16 h50;
} Dst_309218;

typedef struct {
    u8 pad0[4];
    f32 f[6];
    s16 h28;
    s16 h30;
    u8 c[4];
    s16 h36;
    s16 h38;
    u8 pad40[4];
    Dst_309218 *dst;
    s128 q;
} Src_309218;

void func_00309218(u8 *moby) {
    Src_309218 *p = *(Src_309218 **)(moby + 104);

    if (p->f[0] != -1.0f) {
        p->dst->f[0] = p->f[0];
    }
    if (p->f[1] != -1.0f) {
        p->dst->f[1] = p->f[1];
    }
    if (p->f[2] != -1.0f) {
        p->dst->f[2] = p->f[2];
    }
    if (p->f[3] != -1.0f) {
        p->dst->f[3] = p->f[3];
    }
    if (p->f[4] != -1.0f) {
        p->dst->f[4] = p->f[4];
    }
    if (p->f[5] != -1.0f) {
        p->dst->f[5] = p->f[5];
    }
    if (p->h28 != -1) {
        p->dst->b24 = p->h28;
    }
    if (p->h30 != -1) {
        p->dst->h26 = p->h30;
    }
    if (p->c[0] != 0) {
        p->dst->c[0] = p->c[0];
    }
    if (p->c[1] != 0) {
        p->dst->c[1] = p->c[1];
    }
    if (p->c[2] != 0) {
        p->dst->c[2] = p->c[2];
    }
    if (p->c[3] != 0) {
        p->dst->c[3] = p->c[3];
    }
    if (p->h36 != -1) {
        p->dst->h48 = p->h36;
    }
    if (p->h38 != -1) {
        p->dst->h50 = p->h38;
    }
    if (*(f32 *)&p->q != -1.0f) {
        p->dst->q = p->q;
    }
}
/* localdecomp:end func_00309218 */
