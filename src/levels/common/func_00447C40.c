#include "common.h"
extern s32 func_00447CA0(u8 *a0);
s32 func_00447C40(u8 *a0) {
    if (a0 == 0) return 0;
    if (func_00447CA0(a0) != 0) return *(s16 *)(a0 + 0xAA) == 0x1F6;
    return 1;
}
