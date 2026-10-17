#include "common.h"

extern void func_0051C3F8(void *p, f32 value);

void func_0051C3F8(void *p, f32 value) {
    *(f32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x50) = value;
}
