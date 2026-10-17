#include "common.h"

extern void func_00441FB8(u8 *, s32, s32);

void func_003B3C98(u8 *obj) {
    obj[48] = 255;
    func_00441FB8(obj, 1, -1);
}
