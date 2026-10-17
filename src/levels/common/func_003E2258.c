#include "common.h"
extern void func_00437F58(u8 *a0, s32 a1, u8 *a2);
extern void func_00408B30(u8 *a0, s32 a1, s32 a2);
extern void func_00408E98(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_003E2258(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_00437F58(a0, 0, buf);
            func_00408B30(buf, 0x103080, 0);
            func_00408E98(buf, s0 + 64, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
