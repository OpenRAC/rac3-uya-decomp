#include "common.h"

extern s32 D_001DF9C4;
extern void func_004010D0(s32);

void func_004017F8(void) {
    D_001DF9C4 = 0x100FF;
    func_004010D0(0);
}
