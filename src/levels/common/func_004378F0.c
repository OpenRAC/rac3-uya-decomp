#include "common.h"

extern u32 *D_001E10E8_003BDBA0;
extern u32 *D_001E0090_003BDBA0;
extern s32 D_001D4BB0_003BDBA0;
extern void func_0043E6E8();
extern void func_004C21C0();
void func_004378F0(void) {
    u32 *s0, *t;
    u32 c;
    c = 0x20000000;
    t = D_001E10E8_003BDBA0;
    s0 = t;
    t += 4;
    D_001E10E8_003BDBA0 = t;
    D_001E0090_003BDBA0[0] = c;
    D_001E0090_003BDBA0[1] = (u32)D_001E10E8_003BDBA0;
    D_001E0090_003BDBA0[2] = 0;
    D_001E0090_003BDBA0[3] = 0;
    func_0043E6E8(D_001D4BB0_003BDBA0);
    func_004C21C0();
    D_001E10E8_003BDBA0[0] = c;
    D_001E10E8_003BDBA0[1] = (u32)(D_001E0090_003BDBA0 + 4);
    D_001E10E8_003BDBA0[2] = 0;
    D_001E10E8_003BDBA0[3] = 0;
    D_001E10E8_003BDBA0 += 4;
    s0[0] = c;
    s0[1] = (u32)D_001E10E8_003BDBA0;
    s0[2] = 0;
    s0[3] = 0;
}
