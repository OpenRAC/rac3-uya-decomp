#include "common.h"

extern void func_0011F0A0(s32);
extern void func_004C1FE8(s32, unsigned long);

extern void *D_001E0098_003BE260;
extern void func_004C1FE8(s32, unsigned long);
extern void func_0011F0A0(s32);
extern void func_00437F50(void);
extern void *func_0043EA78(s32, void *, s32, s32);
extern void func_00437F20(void);
void func_00438040(s32 a0, s32 a1) {
    func_004C1FE8(0x47, 0x5360B);
    func_0011F0A0(0);
    func_00437F50();
    D_001E0098_003BE260 = func_0043EA78(a0, D_001E0098_003BE260, a1, 0);
    func_00437F20();
    D_001E0098_003BE260 = (u8 *)D_001E0098_003BE260 - 0x10;
}
