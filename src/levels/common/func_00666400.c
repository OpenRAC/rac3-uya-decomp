#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern Vec4 D_0025F860;
extern s32 func_0057F278(Vec4 *, Vec4 *, s32, s32, s32);

void func_00666400(s32 arg0, Vec4 *arg1)
{
    Vec4 a;
    Vec4 b;

    a.q = arg1->q;
    b.q = a.q;
    b.f[2] -= 10.0f;
    a.f[2] += 10.0f;
    if (func_0057F278(&a, &b, 4, arg0, 0)) {
        arg1->q = D_0025F860.q;
    } else {
        arg1->q = b.q;
    }
}
