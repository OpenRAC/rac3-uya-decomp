#include "common.h"

s32 a1;
s32 a2;

void func_004C9158(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
