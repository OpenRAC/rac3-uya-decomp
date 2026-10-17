#include "common.h"

extern s32 func_003FECA8();
void func_003FED80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    s32 var_4;
    s32 var_5;
    s32 var_6;

    if (fparg0 < 0.5f) {
        if (((s32 (*)())func_003FECA8)() == 0) {
            var_4 = arg3;
            var_5 = arg4;
            var_6 = arg5;
            goto block_5;
        }
    } else if (((s32 (*)())func_003FECA8)(arg3, arg4, arg5) == 0) {
        var_4 = arg0;
        var_5 = arg1;
        var_6 = arg2;
block_5:
        ((s32 (*)())func_003FECA8)(var_4, var_5, var_6);
    }
}
