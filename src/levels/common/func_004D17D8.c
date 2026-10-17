#include "common.h"

extern s32 func_004D17D8(s32, s32, s32, s32, s32, s32, s32, s32);
s32 *arg1;
s32 *arg2;
s32 *arg3;
s32 *arg4;

extern void func_004D1940(void *);
extern s32 func_004D1D38();
extern s32 func_004D1D60();
extern s32 func_004D1D90();
extern s32 func_004D1DB8();
extern s32 func_004D1DE0();
extern void func_004D09E0_003ACED0(s32, s32, s32, s32, s32, s32);
extern void func_001350A8(void);
extern void func_00135D08(s32, s32, void *, s32);
s32 func_004D17D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_001350A8();
    func_00135D08(arg0, 0, &func_004D1D38, 0);
    func_00135D08(arg0, 1, &func_004D1D60, 0);
    func_00135D08(arg0, 2, &func_004D1D90, 0);
    func_00135D08(arg0, 3, &func_004D1DB8, 0);
    func_00135D08(arg0, 5, &func_004D1DE0, 0);
    func_004D1940((void *)arg0);
    func_004D09E0_003ACED0(arg0 + 0x48, arg3, arg4, arg5, arg6, arg7);
    return 1;
}
