#include "common.h"

extern s32 func_0051C398();

s32 func_0051C398(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
