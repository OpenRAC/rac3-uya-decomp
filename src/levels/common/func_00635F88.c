#include "common.h"

extern void func_0058F358(void *, void *, f32);

void func_00635F88(u8 *a0, f32 s) {
    func_0058F358(a0 + 320, a0 + 320, s);
    func_0058F358(a0 + 336, a0 + 336, s);
    func_0058F358(a0 + 288, a0 + 288, s);
    func_0058F358(a0 + 400, a0 + 400, s);
    *(f32 *)(a0 + 4020) *= s;
}
