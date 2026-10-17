#include "common.h"
extern u8 D_001D8058;
extern void func_00512AB0(s32, s32, s32);
extern s32 func_00475D20(s32);
extern s32 func_00512038(s32);
s32 func_004759A8(void) {
    if (D_001D8058 != 0) {
        func_00512AB0(0x10000, 1, 0);
        return func_00512038(func_00475D20(0));
    }
    return 0;
}
