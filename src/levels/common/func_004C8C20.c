#include "common.h"

void func_004C8C20(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
