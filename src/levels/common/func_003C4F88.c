#include "common.h"
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern void func_00438430(s32);
void func_003C4F88(u8 *a0) {
    if (a0[176] != 255) {
        if (!(D_001BBC40[a0[176] + D_001D545C * 16] & 0x80)) {
            func_00438430(a0[176]);
        }
    }
}
