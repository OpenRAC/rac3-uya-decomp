#include "common.h"

extern s32 D_00142430_00396310[];
extern s32 D_001D4CE8_00396310;
extern s32 D_001D4CEC_00396310;
void func_0042F318(void) {
    s32 *s = D_00142430_00396310;
    D_001D4CEC_00396310 &= ~0x20;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_001D4CE8_00396310 = 7;
            return;
        }
        if (s[4]) {
            s[4] = 0;
            D_001D4CE8_00396310 = 0xB;
            return;
        }
        D_001D4CE8_00396310 = 0xB;
    }
}
