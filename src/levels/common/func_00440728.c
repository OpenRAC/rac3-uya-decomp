#include "common.h"

s32 func_00440728(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
