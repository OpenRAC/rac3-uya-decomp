#include "common.h"

extern void func_00424CF8(u8 *, s32, s32);

void func_003A52C0(u8 *obj) {
    if (obj != 0) {
        func_00424CF8(obj, obj[32], 1);
    }
}
