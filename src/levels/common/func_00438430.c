#include "common.h"
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
void func_00438430(s32 a0) {
    if (a0 != 255) {
        D_001BBC40[D_001D545C][a0] |= 0x80;
    }
}
