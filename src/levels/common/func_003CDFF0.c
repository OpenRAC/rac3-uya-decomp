#include "common.h"

extern void func_003CE5D8(u8 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u16 func_0042DBA8(s32, s32);

void func_003CDFF0(u8 *m) {
    if (*(u16 *)(m + 150) == 0) {
        func_003CE5D8(m, 0, 10, 0.0f, 0.0f, 0.25f, -0.04f, 1.0f, -8.0f, 7.0f);
        *(u16 *)(m + 150) = func_0042DBA8(60, 400);
    }
    (*(u16 *)(m + 150))--;
}
