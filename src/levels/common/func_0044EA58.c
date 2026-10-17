#include "common.h"

extern f32 func_0044EA18(void *, void *);
extern f32 func_0040C3E0(f32);
extern void func_0040D020(void *, void *, f32);

void func_0044EA58(void *a0, void *a1, void *dst, void *arg) {
    f32 t = func_0040C3E0(func_0044EA18(a0, a1));
    func_0040D020(dst, arg, t * 0.5f + 0.5f);
}
