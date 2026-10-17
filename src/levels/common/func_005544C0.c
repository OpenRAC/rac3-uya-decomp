#include "common.h"
extern s32 D_002C2940[];
s32 func_005544C0(s32 a0, s32 a1) {
    s32 i;
    s32 *p = &D_002C2940[a1 * 4];
    for (i = 0; i < 4; i++, p++) {
        if (*p == a0) {
            *p = 0;
            return 1;
        }
    }
    return 0;
}
