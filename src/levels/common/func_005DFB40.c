#include "common.h"

extern s32 *D_001D5A10;
extern s32 D_001D8268;
extern u8 D_001D826C;
extern s32 func_005E05E8(s32);
extern s32 func_0060DD90(s32);
extern void func_0060F828(s32);
extern void func_0060E900(s32, s32, s32);
extern void func_005DFB18(void);

void func_005DFB40(s32 arg0, s32 arg1) {
    if (func_0060DD90(func_005E05E8(0)) == 1) {
        func_0060F828((*D_001D5A10 < 2) ? 0 : 4);
        D_001D8268 = arg1;
        D_001D826C = 0;
        func_0060E900(0x40000, 1, 1);
    } else if (func_0060DD90(func_005E05E8(0)) == 2) {
        func_005DFB18();
    }
}
