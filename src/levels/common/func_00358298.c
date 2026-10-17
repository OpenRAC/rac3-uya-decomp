#include "common.h"
extern s32 D_00142BC0[];
extern u8 D_001E8DC0[];
extern void func_003EB538(void *, s32);
extern s32 func_003EB690(void *);
void func_00358298(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    unsigned long t;
    *(s32 *)(s1 + 164) = 0;
    t = D_00142BC0[0];
    if (!((t >> 1) & 1)) {
        func_003EB538(D_001E8DC0, 33);
        func_003EB690(D_001E8DC0);
        *(s32 *)(s1 + 212) = 1;
    }
}
