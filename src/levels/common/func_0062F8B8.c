#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern f32 func_0058F430(Vec4 *);
extern void func_0058F7B8(Vec4 *, Vec4 *, u8 *);
extern f32 func_0058F980(f32, f32);

f32 func_0062F8B8(u8 *m, Vec4 *v) {
    Vec4 t;

    switch (m[6662]) {
    case 0:
        return func_0058F980(v->f[2], func_0058F430(v));
    case 1:
    case 2:
        t.q = v->q;
        func_0058F7B8(&t, &t, m + 96);
        return func_0058F980(t.f[2], func_0058F430(&t));
    }
    return 0.0f;
}
