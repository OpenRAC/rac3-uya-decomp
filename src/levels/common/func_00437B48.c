#include "common.h"

extern int D_001E10E8_003BDBA0;
extern int D_001E00E4_003BDD68;
extern s32 D_001E00E0;
extern s32 D_001DFBF4_003BDD68;
extern s32 D_001D66A8_003BDD68;
extern void func_004A0B88();
extern void func_004A0830();
void func_00437B48(void) {
    u32 *s0, *t;
    u32 c;
    if (D_001E00E0 == 0) {
        ((u32 *)D_001E00E4_003BDD68)[0] = 0x10000000;
        ((u32 *)D_001E00E4_003BDD68)[1] = 0;
        ((u32 *)D_001E00E4_003BDD68)[2] = 0;
        ((u32 *)D_001E00E4_003BDD68)[3] = 0;
    } else {
        c = 0x20000000;
        t = ((u32 *)D_001E10E8_003BDBA0);
        s0 = t;
        t += 4;
        D_001E10E8_003BDBA0 = (int)t;
        ((u32 *)D_001E00E4_003BDD68)[0] = c;
        ((u32 *)D_001E00E4_003BDD68)[1] = D_001E10E8_003BDBA0;
        ((u32 *)D_001E00E4_003BDD68)[2] = 0;
        ((u32 *)D_001E00E4_003BDD68)[3] = 0;
        func_004A0B88(D_001DFBF4_003BDD68, D_001D66A8_003BDD68);
        func_004A0830(D_001DFBF4_003BDD68);
        ((u32 *)D_001E10E8_003BDBA0)[0] = c;
        ((u32 *)D_001E10E8_003BDBA0)[1] = D_001E00E4_003BDD68 + 0x10;
        ((u32 *)D_001E10E8_003BDBA0)[2] = 0;
        ((u32 *)D_001E10E8_003BDBA0)[3] = 0;
        D_001E10E8_003BDBA0 = (int)(((u32 *)D_001E10E8_003BDBA0) + 4);
        s0[0] = c;
        s0[1] = D_001E10E8_003BDBA0;
        s0[2] = 0;
        s0[3] = 0;
    }
}
