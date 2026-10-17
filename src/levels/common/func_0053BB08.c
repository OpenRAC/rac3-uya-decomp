#include "common.h"

extern void func_0058F5B0(void *, void *, f32);
extern f32 func_0058F3C0(void *, void *);
extern void func_0053BA50(void *, void *, f32);

void func_0053BB08(u8 *a0) {
    f32 v[4];
    u8 *p = *(u8 **)(a0 + 104);
    func_0058F5B0(v, p + 32, 1.0f);
    func_0053BA50(a0, p, -func_0058F3C0(p, v));
}
