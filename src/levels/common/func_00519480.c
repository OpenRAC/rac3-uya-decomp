#include "common.h"

extern void func_00519480(void *, f32, f32);

void func_00519480(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
