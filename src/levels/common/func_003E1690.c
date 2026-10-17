#include "common.h"

extern void func_0044FEA8(f32 *, f32, f32);
extern s32 func_0044FC98(s32, s32);
extern void func_00477908(u8 *, s32, s32, s32, s32, f32 *, s32, f32, f32, f32);

void func_003E1690(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    s32 i;
    for (i = 0; i < 3; i++) {
        func_0044FEA8(v, 0.033333335f, 0.06666667f);
        func_00477908(a0 + 16, 20, 0xFF4265FE, 0, func_0044FC98(-120, 120), v, 0, 1.0f, 0.1f, 0.0f);
    }
}
