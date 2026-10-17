#include "common.h"
extern s32 D_0021D940[];
extern void func_00461BD8(s32);
s32 func_00461B90(s32 i) {
    if (i != -1 && D_0021D940[i] != 0) {
        func_00461BD8(D_0021D940[i]);
        return 0;
    }
    return -1;
}
