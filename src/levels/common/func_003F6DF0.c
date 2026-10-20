#include "common.h"
extern void func_0040C260(f32 *, f32 *, f32 *);
extern f32 func_0040BF38(f32 *);
extern f32 func_0040BEF8(f32 *, f32 *);
extern void func_004450C0(f32 *, f32, f32);
extern void func_0040C0F0(f32 *, f32 *, f32);
s32 func_003F6DF0(f32 *v, f32 *a, f32 *b, f32 scale, f32 min) {
    f32 len;
    f32 hi;
    func_0040C260(v, v, a);
    len = func_0040BF38(v);
    if (0.7f < func_0040BEF8(b, a)) {
        hi = len * scale;
        if (hi < min) {
            hi = min;
        }
        func_004450C0(&len, 0.0f, hi);
        func_0040C0F0(v, v, len);
    }
    return len != 0.0f;
}
