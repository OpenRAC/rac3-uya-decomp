#include "common.h"

extern s32 func_003F0638(u8 *);
extern void func_00425278(u8 *, s32, s32);

s32 func_003570F8(u8 *obj) {
    s32 ret;
    if (func_003F0638(*(u8 **)(obj + 104) + 816) == 0) {
        ret = 0;
    } else {
        func_00425278(obj, 28, -1);
        ret = 1;
    }
    return ret;
}
