#include "common.h"

extern f32 D_001E11C0;
extern s32 D_001E11C4;

void func_004C5830(s32 n) {
    if (n == 7) {
        D_001E11C0 = 750.0f;
    } else if (n == 6) {
        D_001E11C0 = 675.0f;
    } else if (n == 5) {
        D_001E11C0 = 600.0f;
    } else if (n == 4) {
        D_001E11C0 = 525.0f;
    } else if (n == 3) {
        D_001E11C0 = 450.0f;
    } else if (n == 2) {
        D_001E11C0 = 375.0f;
    } else if (n == 1) {
        D_001E11C0 = 300.0f;
    } else {
        D_001E11C0 = 225.0f;
    }
    D_001E11C4 = 0;
}
