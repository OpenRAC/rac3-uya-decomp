#include "common.h"

s32 func_004D1998(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
