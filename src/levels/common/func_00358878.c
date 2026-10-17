#include "common.h"

extern u8 *D_001DF71C;
extern u32 D_00142BC8[];
extern u8 D_001E8DC0[];
extern void func_004231B8(void *, s32);
extern void func_003EB538(void *, s32);
extern s32 func_003EB690(void *);

s32 func_00358878(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)v;

    if (i != -1) {
        func_004231B8(D_001DF71C + (i << 8), 1);
    }
    if (!(D_00142BC8[0] & 0x200)) {
        func_003EB538(D_001E8DC0, 41);
        i = func_003EB690(D_001E8DC0);
        *(s32 *)(v + 0xD4) = 1;
        return i;
    }
}
