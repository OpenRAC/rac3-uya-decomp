#include "common.h"

extern f32 D_001D6AF4;
extern s32 D_001D6AB0;
extern u8 D_001D6AA5;
extern s32 D_002E7260[];

void func_00430D10(void) {
    D_001D6AF4 = 1.0f;
    D_002E7260[8] = (s32)&D_001D6AB0;
    D_002E7260[12] = 1;
    D_001D6AA5 = 0;
}
