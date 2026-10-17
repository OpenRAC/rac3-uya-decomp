#include "common.h"
extern u8 D_001D80CD;
extern void func_00512AB0(s32, s32, s32);
extern s32 func_00478B18(s32);
extern s32 func_00512038(s32);
s32 func_004780F8(void) {
    if (D_001D80CD != 0) {
        func_00512AB0(0x20000, 1, 0);
        return func_00512038(func_00478B18(0));
    }
    return 0;
}
