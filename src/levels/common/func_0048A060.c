#include "common.h"

extern s32 func_0048A060(void);

extern s32 func_00511FE0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001E0978;
extern s32 D_001E0960[2];
extern void func_00488C28();
extern void func_00489FA8();
extern void func_00489D10();
extern void func_0048A020(void);
extern void func_0048A040();
s32 func_0048A060(void) {
    if (D_001E0978 == 0) {
        func_00511FE0(D_001E0960, (s32)func_00488C28, (s32)func_00489FA8, (s32)func_00489D10, (s32)func_0048A020, (s32)func_0048A040);
        D_001E0978 = 1;
    }
    return (s32)D_001E0960;
}
