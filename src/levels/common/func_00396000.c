#include "common.h"

extern s32 D_001DE338[2];

s32 *func_00396000(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 12;
        return D_001DE338;
    }
    return 0;
}
