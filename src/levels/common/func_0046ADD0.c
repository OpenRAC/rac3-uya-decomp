#include "common.h"
extern s32 D_001D7F68;
extern void func_00442D70(u8 *, s32);
extern s32 func_0040BAC0(u8 *);
extern void func_0045E580(u8 *);
void func_0046ADD0(u8 *a0) {
    func_00442D70(a0 + 4, D_001D7F68);
    if (func_0040BAC0(a0 + 10)) {
        func_0045E580(a0);
    }
}
