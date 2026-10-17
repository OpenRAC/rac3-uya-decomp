#include "common.h"

extern void func_0051C340(void *, s32, s16, s16, s32);

void func_0051C340(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
