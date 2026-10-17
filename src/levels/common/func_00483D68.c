#include "common.h"
extern s32 D_001D8720;
s32 func_00483D68(s32 k) {
    s32 i;
    s32 *p = &D_001D8720;
    for (i = 0; i < 9; i++) {
        if (p[i] == k) return i;
    }
    return -1;
}
