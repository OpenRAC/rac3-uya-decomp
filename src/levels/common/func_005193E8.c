#include "common.h"

extern void func_005193E8(void *, s32, s32);

void func_005193E8(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
