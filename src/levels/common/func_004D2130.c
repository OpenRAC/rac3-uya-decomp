#include "common.h"

extern s32 func_0012C908(s32);
extern s32 func_0013B620(void);

extern void func_0013BC30(s32, void *, unsigned long);
extern void func_004A78D0();
extern void func_0011F0A0();
void func_004D2130(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_0013BC30(a, func_004A78D0, (u32)p);
    m = -1;
    do {
        func_0011F0A0(0);
        func_0012C908(0);
        ((s32 (*)(void))func_0013B620)();
    } while (*p == m);
}
