#include "common.h"

extern s32 func_004D8DF0(s32 *, s32);
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];

extern s32 func_004D8DF0();
extern void func_004DB390(void);
extern void func_004DB4D0(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
void func_004DB5C0(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634 = func_004D8DF0(spv, 0x40000);
    D_001D5628 = func_004D8DF0(spv, 0x40000);
    D_001D5630 = D_001A1ED4[0];
    func_004DB390();
    func_004DB4D0();
    D_001D55EC |= 2;
}
