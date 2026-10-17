#include "common.h"
extern s32 D_001D7DD8;
extern s32 D_001D7DDC;
extern f32 D_001D7DD4;
extern f32 D_001D7DE0;
extern s32 D_001DFBC0[];
extern s32 D_001DFBC0_00458EC8[];
void func_00458EC8(void) {
    if (D_001D7DD8 != D_001DFBC0[0]) {
        if (D_001D7DDC != 0) {
            D_001D7DE0 = D_001D7DD4 / (f32)D_001D7DDC;
        } else {
            D_001D7DE0 = 0.0f;
        }
        D_001D7DDC = 0;
        D_001D7DD8 = D_001DFBC0_00458EC8[0];
        D_001D7DD4 = 0.0f;
    }
    *(volatile s32 *)0x10000010 = 129;
    *(volatile s32 *)0x10000000 = 0;
}
