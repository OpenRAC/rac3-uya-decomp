#include "common.h"

s32 func_00354B48(u8 *obj) {
    s32 ret = 0;
    if (obj[66] == 11 || obj[66] == 7 || obj[66] == 14 ||
        obj[67] == 11 || obj[67] == 7 || obj[67] == 14) {
        ret = 1;
    }
    return ret;
}
