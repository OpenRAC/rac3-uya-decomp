#include "common.h"

extern void func_00412D40(s32);
extern void func_004035F8(s32, s32, s32, s32);
extern void func_004010D0(s32);
extern s16 D_001E118E[];
extern s32 D_001DF9C4;

void func_004C6C60(void) {
    func_00412D40(0);
    func_004035F8(0, 0, 0, 128);
    if (D_001E118E[0] != 0) {
        D_001DF9C4 = 0x100FF;
    } else {
        D_001DF9C4 = 112;
    }
    func_004010D0(0);
}
