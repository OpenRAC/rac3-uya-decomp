#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern f32 func_0040BF38(void *v);
extern f32 func_0040C3E0(f32 f12);
extern void func_00448FB8(void *dst, void *src, f32 f12);
extern void func_0040C9F8(void *dst, void *a, void *b);

void func_003F6CD0(s32 arg0, s128 *pos, s128 *vel) {
    s128 v;
    f32 len;
    f32 a;
    f32 b;

    v = *vel;
    len = func_0040BF38(&v) * 0.5f;
    a = func_0040C3E0(0.01308997068554163f);
    b = func_0040C3E0(0.02617994137108326f);
    if (a < len) {
        len = a;
    }
    func_00448FB8(&v, &v, len);
    func_0040C9F8(pos, pos, &v);
    if (b < func_0040BF38(pos)) {
        func_00448FB8(pos, pos, b);
    }
}
