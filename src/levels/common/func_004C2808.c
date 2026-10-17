#include "common.h"

extern void func_004C2808(void);

extern s32 D_001E1100;
extern s32 D_001E1104;
extern void func_004C2908();
extern void func_004C2A08();
extern s32 func_0011EB30();
extern void func_0011F9A8();
void func_004C2808(void) {
    if (D_001E1100 == 0 && D_001E1104 == 0) {
        volatile u32 *r = (volatile u32 *)0x1000E010;
        if ((*r & 0x20000) == 0) {
            *(u32 *)0x1000E010 = 0x20000;
        }
        D_001E1100 = func_0011EB30(1, func_004C2908, 0);
        D_001E1104 = func_0011EB30(0xF, func_004C2A08, 0);
        func_0011F9A8(1);
    }
}
