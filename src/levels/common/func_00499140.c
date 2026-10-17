#include "common.h"
extern s32 func_00513928();
extern s32 D_001D949C;
extern void func_004998F0(void);
extern s32 func_0045CA60(s32);
void func_00499140(void) {
    func_00513928(0x10);
    func_00513928(0x11);
    if (D_001D949C != 0) {
        func_00513928(0x14);
    }
    func_004998F0();
    func_0045CA60(1);
}
