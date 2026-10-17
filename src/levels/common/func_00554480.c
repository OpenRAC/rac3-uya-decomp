#include "common.h"
extern s32 D_002C2940[][4];
s32 func_00554480(s32 a0) {
    s32 *p = D_002C2940[a0];
    s32 i;
    for (i = 0; i < 4; i++, p++) {
        if (*p == 0) return 0;
    }
    return 1;
}
