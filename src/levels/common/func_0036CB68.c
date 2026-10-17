#include "common.h"
extern s32 D_001E1D98;
extern void func_00437698(s32, s32, void *);
extern void func_0036CBC0(void *, s32, s32, f32, f32, f32, f32);
void func_0036CB68(s32 a0) {
    u8 buf[16];
    func_00437698(a0, 0, buf);
    func_0036CBC0(buf, 66, D_001E1D98 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
