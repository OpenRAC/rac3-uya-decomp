#include "common.h"
extern void func_0040BB80_004C1AF0(s32);
void func_004C1AF0(u32 address) {
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0040BB80_004C1AF0(0x10);
    }
    *(volatile u32 *)0x10008020 = 0;
    *(volatile u32 *)0x10008030 = address & 0xFFFFFFF;
    *(volatile u32 *)0x10008000 = 0x145;
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0040BB80_004C1AF0(0x10);
    }
}
