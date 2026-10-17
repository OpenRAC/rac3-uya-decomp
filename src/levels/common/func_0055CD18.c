#include "common.h"

extern s32 D_00242A94[];
extern s32 D_001D5A08;
extern void func_005A8630(void *);

void func_0055CD18(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    if (D_00242A94[0] != 0 && p != 0 && (*p)[9417] == D_001D5A08) {
        func_005A8630(a0);
        return;
    }
    *(u16 *)(a0 + 52) &= 0xFFBE;
}
