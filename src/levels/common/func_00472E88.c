#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_0040BFE8(Vec4 *a0, Vec4 *a1);
extern void func_0040BFB0(Vec4 *a0, Vec4 *a1);

void func_00472E88(Vec4 *a0, Vec4 *a1, f32 r) {
    Vec4 a;
    Vec4 b;
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    a.q = a0->q;
    b.q = a1->q;
    if (0.0f < r && __builtin_fabsf(pa->f[2] - pb->f[2]) < r) {
        func_0040BFE8(pa, pb);
    } else {
        func_0040BFB0(pa, pb);
    }
}
