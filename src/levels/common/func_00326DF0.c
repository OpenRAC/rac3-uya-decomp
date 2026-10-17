#include "common.h"

extern u8 *func_003252E8();

void func_00326DF0(s32 i, u8 v) {
    *(u8 *)(*(s32 *)(func_003252E8() + 104) + i + 816) = v;
}
