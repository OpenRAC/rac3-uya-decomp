#include "common.h"

extern void func_003B1C58(void);
extern void func_00441FB8(u8 *, s32, s32);

void func_003B4908(u8 *obj)
{
    u8 *vars = *(u8 **)(obj + 104);

    if (*(s32 *)(vars + 80) != 0 && *(s32 *)(vars + 84) == 0) {
        func_003B1C58();
    }
    if (*(s32 *)(vars + 196) < *(s32 *)(vars + 192)) {
        func_00441FB8(obj, 3, -1);
    } else if (obj[32] == 4) {
        obj[188] = 1;
    } else {
        func_00441FB8(obj, 1, -1);
    }
}
