#include "common.h"

extern void func_004C2898();
extern s32 D_001E1100;
extern s32 D_001E1104;

extern s32 D_001E1100;
extern s32 D_001E1104;
extern void func_0011EB50(s32, s32);
extern void func_0011F940(s32);
void func_004C2898(void) {
    if (*(volatile u32 *)0x1000E010 & 0x20000) {
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_0011EB50(1, D_001E1100);
    func_0011EB50(15, D_001E1104);
    func_0011F940(1);
    D_001E1100 = 0;
    D_001E1104 = 0;
}
