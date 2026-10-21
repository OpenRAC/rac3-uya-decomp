#include "common.h"

/* localdecomp:start func_00398940 */
extern u8 D_002A1A70[];
extern void func_003988D0(u8 *a0, u8 *a1);
extern void func_004076F8(u8 *a0, s32 a1, s32 a2);
extern void func_00407A60(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_00398940(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_003988D0(a0, buf);
            func_004076F8(buf, 0x103080, 0);
            func_00407A60(buf, D_002A1A70 + *(s32 *)(s0 + 44) * 64, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
/* localdecomp:end func_00398940 */
