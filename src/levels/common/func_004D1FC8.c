#include "common.h"

extern s32 func_004D1FC8(void *);

s32 func_004D1FC8(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
