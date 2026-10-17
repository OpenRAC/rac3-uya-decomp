#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v;
    u8 *o;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} S34BD48;

extern void func_003DFB58(S34BD48 *, S34BD48 *, f32);

void func_0034BD48(S34BD48 *s, u8 *o, Vec4 *pos, s32 a3, s32 a4, f32 f) {
    s->o = o;
    if (a3 != 0) {
        s->flags = 0x1000001;
        if (a4 != 0) {
            s->flags = 0x1020001;
        }
    } else {
        s->flags = 0x1010000;
    }
    s->f1C = f;
    s->i20 = 1;
    s->v.q = pos->q;
    func_003DFB58(s, s, 1.0f);
    s->v.f[3] = 5627.9248046875f;
    s->b18 = 3;
    s->b19 = 2;
    s->h1A = *(u16 *)(o + 170);
}
