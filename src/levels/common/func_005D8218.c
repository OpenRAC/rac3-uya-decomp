#include "common.h"
extern s32 D_001D7EF8[2];
extern s8 D_001D7F08[8];
extern s32 func_005D80D8(void);
extern s32 func_0060DD90(s32);
extern void func_0060F828(s32);
extern void func_0060ECA0(s32, s32);
void func_005D8218(s32 a0, s32 a1) {
    if (func_0060DD90(func_005D80D8()) == 1) {
        s32 *p;
        s8 *q;
        func_0060F828(a0);
        q = D_001D7F08;
        p = D_001D7EF8;
        p[a0] = a1;
        q[a0] = 0;
        func_0060ECA0(0x20001, 1);
    }
}
