#include "common.h"

extern void func_0051B900(void *p, f32, f32);

void func_0051B900(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
