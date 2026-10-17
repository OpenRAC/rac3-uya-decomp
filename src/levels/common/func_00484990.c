#include "common.h"

u8 *func_00484990(u8 *a0, s32 a1, s32 a2) {
    if (a2 < 4 && a1 < 5) {
        return a0 + a2 * 5 + a1;
    }
    return 0;
}
