#include "common.h"

extern s32 func_00359AD0(u8 *);
extern s32 func_00359BA0(u8 *);

s32 func_00354F28(u8 *obj) {
    s32 ret;
    if ((*(u8 **)(obj + 104))[95] != 0) {
        return func_00359AD0(obj);
    }
    ret = 0;
    if (obj[188] == 0) {
        ret = func_00359BA0(obj) != 0;
    }
    return ret;
}
