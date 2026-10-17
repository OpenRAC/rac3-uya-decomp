#include "common.h"

extern s32 D_001DD8AC __attribute__((section(".sdata")));
extern s32 D_001DF2C0;
extern void func_003DFE30(f32);
extern void func_00350098(u8 *);
extern void func_004140C0(u8 *, s32, s32);
extern void func_003512E0(u8 *);

void func_0034FFE0(u8 *self) {
    u8 *v = *(u8 **)(self + 104);

    func_003DFE30((f32)(D_001DF2C0 % D_001DD8AC) / (f32)D_001DD8AC * 6.2831855f);
    if (self[32] == 0) {
        func_00350098(self);
        func_004140C0(self, 1, -1);
    }
    if (self[32] == 1) {
        (*(s32 *)(v + 28))++;
        func_003512E0(self);
    }
}
