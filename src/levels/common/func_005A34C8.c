#include "common.h"

extern s32 D_001A4568[];
extern s32 D_00240578;
extern s32 D_0024057C;

void func_005A34C8(void)
{
    s32 v;

    if (D_001A4568[0] != 2) {
        D_00240578 = 4;
    } else if (D_0024057C & 4) {
        D_00240578 = 30;
    } else if (D_0024057C & 2) {
        D_00240578 = 29;
    }
    v = D_0024057C;
    if (v & 0x80) {
        D_00240578 = 24;
        D_0024057C = (v ^ 0x80) | 0x40;
    } else if (v & 0x100) {
        D_00240578 = 22;
        D_0024057C = (v ^ 0x100) | 0x40;
    }
}
