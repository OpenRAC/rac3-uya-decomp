#include "common.h"

extern u8 D_001E1350[];
extern s32 D_001E1360[];
extern f32 D_001E1364[];
extern f32 D_001E1368[];
extern void func_0044E620(void *, s32, f32, f32);
void func_004D40C8(void) {
    func_0044E620(D_001E1350, D_001E1360[0], D_001E1364[0], D_001E1368[0]);
}
