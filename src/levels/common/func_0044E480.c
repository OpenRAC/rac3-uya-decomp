#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
extern void func_0044DC18(s32, Vec4 *, Vec4 *, s32);
extern f32 func_0040C490(f32, f32);
f32 func_0044E480(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    t = *a1;
    func_0044DC18(a0, &t, &t, a2);
    return func_0040C490(t.v[0], t.v[1]);
}
