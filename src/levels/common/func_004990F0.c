#include "common.h"
extern u8 *D_001D52FC;
extern s32 func_00494DD0(s32 a0);
extern void func_00495868(s32 a0, s32 a1);
extern void func_004999A0(void);
extern void func_00499930(s32 a0);
void func_004990F0(s32 a0) {
    func_00495868(func_00494DD0(0), *(s32 *)(D_001D52FC + 452));
    func_004999A0();
    func_00499930(a0);
}
