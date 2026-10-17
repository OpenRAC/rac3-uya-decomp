#include "common.h"

extern void func_00397728(u8 *, s32, s32);

void func_003976D8(u8 *obj) {
    func_00397728(obj, 0, -1);
    func_00397728(obj, 1, 1);
    *(f32 *)(obj + 20) = 325.0f;
}
