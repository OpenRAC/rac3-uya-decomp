#include "common.h"

extern s32 func_00435F30(u8 *, s32);

s32 func_003A20D8(u8 *obj, s32 sel) {
    u8 *p = *(u8 **)(obj + 104);
    s32 id;
    if (sel != 0) {
        id = *(s32 *)(p + 752);
    } else {
        id = *(s32 *)(p + 728);
    }
    if (id != -1) {
        if (func_00435F30(p + 544, id) != 0) {
            return 1;
        }
    }
    return 0;
}
