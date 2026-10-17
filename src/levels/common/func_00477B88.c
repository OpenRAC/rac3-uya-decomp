#include "common.h"
extern u8 D_001D80A4;
extern void func_00512AB0(s32, s32, s32);
extern s32 func_00477DE8(s32);
extern s32 func_00512038(s32);
s32 func_00477B88(void) {
    if (D_001D80A4 != 0) {
        func_00512AB0(0x90000, 1, 0);
        return func_00512038(func_00477DE8(0));
    }
    return 0;
}
