#include "common.h"

extern s32 func_00513928();
 
s32 func_00495180(u8 *p) {
    s32 r = 0;
    if (p[0] != 0) {
        p[0] = 0;
        func_00513928(*(s32 *)(p + 0x18));
        r = 1;
    }
    return r;
}
