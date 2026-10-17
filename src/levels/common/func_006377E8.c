#include "common.h"

extern void func_005F0CE0(s32, s32, s32);

void func_006377E8(u8 *a0, s32 a1, s32 a2) {
    func_005F0CE0(a1, a2, *(s32 *)(a0 + 9508));
}
