#include "common.h"

s32 func_0034C020(u8 *obj) {
    s32 *p;
    if (!(*(u16 *)(obj + 52) & 0x20)) {
        return 0;
    }
    p = *(s32 **)(obj + 104);
    return *p;
}
