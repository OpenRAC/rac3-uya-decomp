#include "common.h"

extern s32 func_0060DD48(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern s32 func_0060DD48(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001E1050;
extern s32 D_001E1038[2];
s32 *func_005E6F40(void) {
    if (D_001E1050 == 0) {
        func_0060DD48(D_001E1038, 0, 0, 0, 0, 0);
        D_001E1050 = 1;
    }
    return D_001E1038;
}
