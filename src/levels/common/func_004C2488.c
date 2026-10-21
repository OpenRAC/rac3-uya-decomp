#include "common.h"

/* localdecomp:start func_004C2488 */
extern u32 *D_001E10E8;
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
void func_004C2488(s32 a0, s32 a1, s32 size) {
    s32 n;
    s32 dst = 0;
    s32 src = 0;
    n = (size + 0x3FFF) & ~0x3FFF;
    while (n > 0) {
        D_001E10E8[0] = 0x10000006;
        D_001E10E8[1] = 0;
        D_001E10E8[2] = 0;
        D_001E10E8[3] = 0x50000006;
        D_001E10E8 += 4;
        func_0012C9A0(D_001E10E8, (a1 + dst) >> 8, 1, 1, 0, 0, 64, 64);
        dst += 0x4000;
        n -= 0x4000;
        D_001E10E8 = (u32 *)((u8 *)D_001E10E8 + 0x60);
        D_001E10E8[0] = 0x30000300;
        D_001E10E8[1] = a0 + src;
        D_001E10E8[2] = 0;
        D_001E10E8[3] = 0x50000300;
        D_001E10E8 += 4;
        src += 0x3000;
    }
}
/* localdecomp:end func_004C2488 */
