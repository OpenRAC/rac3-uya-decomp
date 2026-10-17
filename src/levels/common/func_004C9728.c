#include "common.h"

extern void func_004101E0(s32, s32, s32, f32);
void func_004C9728(u8 *p) {
    func_004101E0(*(s32 *)(p + 0x38), -1, *(s32 *)(p + 0x28), **(f32 **)(p + 4));
}
