#include "common.h"

s32 func_00354AB0(u8 *obj) {
    s32 r = 0;
    u8 c;
    if ((u32)(obj[66] - 11) < 3 || (c = obj[67], c == 12) || c == 13 || c == 11) r = 1;
    return r;
}
