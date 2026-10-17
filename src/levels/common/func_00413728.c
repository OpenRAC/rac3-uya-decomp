#include "common.h"

extern s32 D_001EA780[];
extern s32 func_00457270(s32);
extern void func_0013C1D0(s32);
extern void func_0045BFD0(void);
extern void func_0013B620(void);
extern void func_0045D318(s32);

void func_00413728(void) {
    if (func_00457270(3) == 0) {
        func_0013C1D0(77);
        func_0045BFD0();
        func_0013B620();
    }
    func_0045D318(0);
    D_001EA780[0] = 0;
}
