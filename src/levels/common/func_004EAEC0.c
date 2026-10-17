#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern Vec4 D_001A4C70[4];
extern void func_0040C658(Vec4 *, Vec4 *);
extern void func_0040C9B0(Vec4 *, Vec4 *, Vec4 *);
extern void func_00447748(Vec4 *, Vec4 *);

void func_004EAEC0(f32 x, f32 y, f32 z) {
    Vec4 v;
    Vec4 m1[4];
    Vec4 m2[4];

    v.f[0] = x;
    v.f[1] = y;
    v.f[2] = z;
    func_0040C658(m1, &v);
    func_0040C658(m2, D_001A4C70);
    func_0040C9B0(m2, m2, m1);
    func_00447748(m2, D_001A4C70);
}
