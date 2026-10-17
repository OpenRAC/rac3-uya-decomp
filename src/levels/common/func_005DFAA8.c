#include "common.h"
extern s32 *D_002412A0;
extern void func_0060F828(s32);
extern s32 func_005E05E8(s32);
extern s32 func_0060DD90(s32);
extern void func_0060E900(s32, s32, s32);
extern void func_0060DDA0(s32);
void func_005DFAA8(void) {
    func_0060F828(*D_002412A0 < 2 ? 0 : 4);
    if (func_0060DD90(func_005E05E8(0)) == 1) {
        func_0060E900(0x40000, 1, 0);
        func_0060DDA0(func_005E05E8(0));
    }
}
