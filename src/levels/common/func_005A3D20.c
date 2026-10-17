#include "common.h"

extern s32 D_0024057C;
extern s32 D_00240578;
extern s32 D_001D4CEC;
extern s32 D_001A4568[];

void func_005A3D20(void) {
    s32 v = D_0024057C;

    if (v & 4) {
        D_00240578 = 30;
    }
    if (v & 2) {
        D_00240578 = 29;
    }
    if (v & 0x800) {
        D_00240578 = 12;
    }
    if (v & 0x80) {
        D_00240578 = 24;
        D_001D4CEC = (v ^ 0x80) | 0x40;
    } else if (v & 0x100) {
        D_00240578 = 22;
        D_001D4CEC = (v ^ 0x100) | 0x40;
    } else if (D_001A4568[0] != 2) {
        D_00240578 = 4;
    }
}
