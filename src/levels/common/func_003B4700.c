#include "common.h"

s32 func_003B4700(u8 *a) {
    return *(s32 *)(*(u8 **)(a + 0x68) + 0x44);
}
