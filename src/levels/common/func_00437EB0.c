#include "common.h"

extern void func_0040BD58();

extern u8 D_002BF5A0[];
extern s32 D_001DFBF0;
extern s32 D_001DFBF8;
extern void func_0011F0A0(s32);
extern void func_0040BD58(u32 *, s32, s32);
extern void func_0043E998();
void func_00437EB0(void) {
    func_0011F0A0(0);
    func_0040BD58((u32 *)0x70003800, (s32)D_002BF5A0, 0x800);
    func_0043E998(D_001DFBF0, D_001DFBF8);
}
