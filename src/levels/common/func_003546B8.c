#include "common.h"
s32 func_003546B8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 2) {
        return *(s32 *)(p + 16);
    }
    return 0;
}
