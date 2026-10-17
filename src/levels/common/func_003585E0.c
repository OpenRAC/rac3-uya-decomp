#include "common.h"
extern s32 D_00142BC0[];
extern s32 D_001DDB20;
extern s32 D_001DDB24;
extern u8 D_001E8DC0[];
extern void func_003EB538(void *, s32);
extern s32 func_003EB690(void *);
void func_003585E0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    unsigned long t;
    D_001DDB20 = 0;
    D_001DDB24 = 0;
    t = D_00142BC0[0];
    if (!((t >> 3) & 1)) {
        func_003EB538(D_001E8DC0, 35);
        func_003EB690(D_001E8DC0);
        *(s32 *)(s1 + 212) = 1;
    }
}
