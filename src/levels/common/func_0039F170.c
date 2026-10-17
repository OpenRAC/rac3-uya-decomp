#include "common.h"
extern void func_004891A0(s32 a0, s32 a1, u8 *a2);
extern void func_00423710(u8 *a0, s32 a1, s32 a2);
void func_0039F170(u8 *a0) {
    func_004891A0(0, 0, a0);
    *(s32 *)(a0 + 184) = 0;
    func_00423710(a0, 0, 3);
    *(u16 *)(a0 + 52) &= ~0x20;
}
