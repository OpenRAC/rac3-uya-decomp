#include "common.h"

extern void func_003D0910(s32);
extern s32 func_0050FF18(void);
extern void func_003F3918(s32, s32);
extern u8 *D_001E2B10[];

void func_003CF260(s32 a0, u8 *a1) {
    func_003D0910(a0);
    if (func_0050FF18()) return;
    if (*(s16 *)(D_001E2B10[0] + 134)) return;
    func_003F3918(0, 1);
    a1[177] = 1;
}
