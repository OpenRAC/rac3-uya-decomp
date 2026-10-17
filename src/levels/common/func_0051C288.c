#include "common.h"

void func_0051C288(u8 *p) {
    u8 *q;
    s32 v;
    (*(u8 **)(p + 0x2C))[0x59] = 0;
    q = *(u8 **)(p + 0x2C);
    v = 0;
    if (*(u16 *)(q + 0x48) & 8) v = *(u16 *)(q + 0x4C);
    *(s16 *)(q + 0x56) = v;
    (*(u8 **)(p + 0x2C))[0x5A] = 0;
    *(s32 *)(*(u8 **)(p + 0x2C) + 0x40) = 0;
}
