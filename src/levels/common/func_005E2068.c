#include "common.h"
extern s32 func_005D3EE8(s32);
extern s32 func_005E1F08(s32);
extern s32 func_0060DD90(s32);
extern void func_005D3EF8(s32, s32);
extern void func_0060F828(s32);
extern void func_0060FA10(s32);
s32 func_005E2068(s32 a0) {
    if (func_005D3EE8(a0) != 0) {
        return 0;
    }
    if (func_0060DD90(func_005E1F08(a0)) != 0) {
        return 0;
    }
    func_005D3EF8(a0, 1);
    func_0060F828(a0);
    func_0060FA10(func_005E1F08(a0));
    return 1;
}
