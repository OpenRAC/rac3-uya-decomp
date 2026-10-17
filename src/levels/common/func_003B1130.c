#include "common.h"

extern void func_00441FB8(u8 *, s32, s32);

void func_003B1130(u8 *obj) {
    *(s32 *)(*(u8 **)(obj + 104) + 96) = 0;
    func_00441FB8(obj, 1, -1);
}
