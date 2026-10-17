#include "common.h"

s32 func_00511E08(u8 *p) {
    u8 *q = *(u8 **)(p + 4);
    if (q != 0) {
        return *(s32 *)(q + 20);
    }
    return -1;
}
