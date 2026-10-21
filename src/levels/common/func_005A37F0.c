#include "common.h"
extern s32 D_001A4568[];
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern s32 D_00240578;
void func_005A37F0(void) {
    if (D_001A4568[0] != 2) {
        D_001D4CE8 = 4;
        return;
    }
    if (D_001D4CEC & 0x806) D_00240578 = 12;
}
