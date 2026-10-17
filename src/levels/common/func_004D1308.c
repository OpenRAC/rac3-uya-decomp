#include "common.h"

extern void func_004D0948(s32);

extern void func_004D0948(s32);
extern void func_0011EE30(s32);
s32 func_004D1308(u8 *p) {
    func_004D0948(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_0011EE30(*(s32 *)(p + 0x40));
    return 1;
}
