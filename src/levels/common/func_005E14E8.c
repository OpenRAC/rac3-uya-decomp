#include "common.h"
extern s32 func_0060F870(void);
extern void func_005D4508(s32, s32);
extern void func_00619968(s32, s32);
extern void func_005D3EF8(s32, s32);
extern s32 func_005E1F08(s32);
extern void func_0060DE20(s32);
void func_005E14E8(void) {
    s32 p = func_0060F870();
    func_005D4508(p, 10);
    func_00619968(p, 0);
    func_005D3EF8(p, 0);
    func_0060DE20(func_005E1F08(p));
}
