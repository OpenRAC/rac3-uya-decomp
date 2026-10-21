#include "common.h"

/* localdecomp:start func_0041EE90 */
extern void func_0011F0A0(s32);
extern void func_0041EE90(s32, s32, s32, s32, s32, s32);

extern u32 *D_001E10E8_00393120;
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, s32);
void func_0041EE90(s32 a0, s32 a1, s32 a2, s32 d, s32 e, s32 f) {
    u32 tmp[24];
    u32 *buf;
    s32 c, m;
    c = (1 << d) >> 6;
    m = 1 << (d + e - 4);
    if (c <= 0) c = 1;
    if (f == 0) {
        D_001E10E8_00393120[0] = 0x10000006;
        D_001E10E8_00393120[1] = 0;
        D_001E10E8_00393120[2] = 0;
        D_001E10E8_00393120[3] = 0x50000006;
        buf = D_001E10E8_00393120 + 4;
        D_001E10E8_00393120 = (u32 *)((u8 *)D_001E10E8_00393120 + 0x70);
    } else {
        buf = tmp;
    }
    func_0012C9A0(buf, a1, c, a2, 0, 0, 1 << d, 1 << e);
    if (f == 0) {
        D_001E10E8_00393120[0] = m | 0x30000000;
        D_001E10E8_00393120[1] = a0;
        D_001E10E8_00393120[2] = 0;
        D_001E10E8_00393120[3] = m | 0x50000000;
        D_001E10E8_00393120 += 4;
    } else {
        func_0011F0A0(0);
        func_0012CCC8(buf, a0);
    }
}
/* localdecomp:end func_0041EE90 */
