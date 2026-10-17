#include "common.h"

extern s32 func_00450DF8(u8 *, u8 *, s32, s32, s32);
extern void func_003D1930(u8 *, u8 *, s32);
extern void func_00454A08(u8 *, s32);

s32 func_003D1880(u8 *self, u8 *target) {
    s32 r = func_00450DF8(self, target + 112, 0, 0, 0);

    if (r != 0) {
        if ((u32)(r - 4) < 2) {
            func_003D1930(self, target, 1);
            return 0;
        }
    }
    if (target[94] != 0) {
        func_003D1930(self, target, 1);
        return 0;
    }
    if (target[62] == 2) {
        func_003D1930(self, target, 0);
        return 0;
    }
    func_00454A08(self, 3);
    return 1;
}
