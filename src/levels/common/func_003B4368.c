#include "common.h"
s32 func_003B4368(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 68) != 0) {
        return 0;
    }
    return *(s32 *)(p + 64);
}
