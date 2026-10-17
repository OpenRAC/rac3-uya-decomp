#include "common.h"

extern f32 D_001D9208;
extern void func_00514D50(s32);
extern void func_005139B0(s32, s32);
extern void func_00494288(void *, s32, s32, s32, s32, s32, f32, f32);
extern void func_004935C8(void);
extern void func_00493CB0(void);

void func_00493518(s32 a0, s32 a1) {
    func_00514D50(0x47000C);
    func_00494288(func_004935C8, 0x47000C, a1, 0, 1, 0, D_001D9208, 1.0f);
    func_005139B0(a0, 0x47000C);
    func_00494288(func_00493CB0, a0, a1, 2, 1, 0, D_001D9208, 1.0f);
}
