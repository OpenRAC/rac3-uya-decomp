#include "common.h"

extern void func_00124920(void);
extern void func_00124970(void);

extern void func_00124920(void);
extern void func_00124970(void);
void func_004D0948(s32 a) {
    func_00124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_00124970();
}
