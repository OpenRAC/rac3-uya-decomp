#include "common.h"

void func_00359700(u8 **arr, s32 *n) {
    s32 i;
    for (i = 0; i < *n; i++) {
        u8 *o = arr[i];
        *(s32 *)(o + 152) = *(s32 *)(*(u8 **)(o + 36) + 16);
    }
    *n = 0;
}
