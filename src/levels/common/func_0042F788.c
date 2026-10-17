#include "common.h"

extern s32 D_001D4CE8_g;
extern s32 D_00142438[];

extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0042F788(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D4CEC_g & 0x12) D_001D4CE8_g = 15;
}
