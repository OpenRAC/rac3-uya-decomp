#include "common.h"

void func_0051B7B0(void *, s32);

void func_0051B7B0(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
