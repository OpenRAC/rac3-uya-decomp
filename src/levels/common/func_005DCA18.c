#include "common.h"

extern u8 D_0024C5F0[];
extern u8 D_0024C5E8[];
extern s32 D_001D81C0[2];
extern u8 D_001D81D0[8];
extern s32 func_005DDD68(void);
extern s32 func_0060DD90(s32);
extern void func_005DC8B0(void);
extern void func_005DC830(void);

void func_005DCA18(s32 idx, s32 a1) {
    if (func_0060DD90(func_005DDD68()) == 1) {
        if (D_0024C5F0[idx] != 0 || D_0024C5E8[idx] != 0) {
            D_001D81C0[idx] = a1;
            D_001D81D0[idx] = 0;
            func_005DC8B0();
        } else {
            func_005DC830();
        }
    }
}
