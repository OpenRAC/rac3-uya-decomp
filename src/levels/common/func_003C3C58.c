#include "common.h"
extern void func_00417E58(u8 *a0, s32 a1, u8 *a2);
extern void func_003E9428(u8 *a0, s32 a1, s32 a2);
extern void func_003E9790(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_003C3C58(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_00417E58(a0, 0, buf);
            func_003E9428(buf, 0x103080, 0);
            func_003E9790(buf, s0 + 48, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
