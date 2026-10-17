#include "common.h"

void func_004C8AF8(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
