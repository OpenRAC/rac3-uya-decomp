#include "common.h"

s32 func_003B4340(u8 *obj) {
    u8 *p = *(u8 **)(obj + 104);
    if (*(s32 *)(p + 68) != 0) {
        return 0;
    }
    return *(s32 *)(p + 64) == 0;
}
