#include "common.h"

s32 func_004950A8(void *p, s32 x, s32 y) {
    return *(s32 *)((u8 *)p + 0xB0) + (*(s32 *)((u8 *)p + 0x14) * y + x) * 0x44;
}
