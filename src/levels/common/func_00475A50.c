#include "common.h"

extern void func_00475A50(s32);
extern s32 func_00512AB0(s32, s32, s32);

extern u8 D_001D8058;
extern s32 D_001D8050;
extern s32 func_00512AB0(s32, s32, s32);
void func_00475A50(s32 a) {
    if (D_001D8058 != 0) {
        D_001D8050 = a;
        func_00512AB0(0x10000, 1, a != 0);
    }
}
