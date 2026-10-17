#include "common.h"

extern s32 D_00142438[];

extern s32 D_00142438[];
extern s32 D_001D4CEC_003964E8;
extern s32 D_001D4CE8_003964E8;
void func_0042F4F0(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        D_001D4CE8_003964E8 = 4;
        return;
    }
    v = D_001D4CEC_003964E8;
    if (v & 0x806) {
        D_001D4CE8_003964E8 = 0xC;
        return;
    }
    if (v & 0x200) {
        D_001D4CE8_003964E8 = 0x1C;
    }
}
