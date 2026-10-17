#include "common.h"

extern s32 D_001EAA40[];
extern s32 D_001DFD90;
extern s32 D_001DFD94;
void func_0041A068(void) {
    s32 a = D_001EAA40[0];
    D_001DFD90 = a;
    *(volatile s32 *)&D_001DFD94 = a + 0x64000;
}
