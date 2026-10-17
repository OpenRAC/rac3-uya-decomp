#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_0058FB48(Vec4 *, Vec4 *);
extern void func_0058FEA0(Vec4 *, Vec4 *, Vec4 *);
extern void func_005B6428(Vec4 *, Vec4 *);

void func_00630988(u8 *m, f32 x, f32 y, f32 z) {
    Vec4 v;
    Vec4 m1[4];
    Vec4 m2[4];

    v.f[0] = x;
    v.f[1] = y;
    v.f[2] = z;
    func_0058FB48(m1, &v);
    func_0058FB48(m2, (Vec4 *)(m + 176));
    func_0058FEA0(m2, m2, m1);
    func_005B6428(m2, (Vec4 *)(m + 176));
}
