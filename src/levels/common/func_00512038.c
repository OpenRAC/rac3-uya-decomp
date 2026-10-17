#include "common.h"
extern s32 func_00512028(s32);
extern void func_00512030(s32, s32);
s32 func_00512038(s32 a0) {
    if (func_00512028(a0) != 1) return 0;
    func_00512030(a0, 2);
    return 1;
}
