#include "common.h"

extern s32 D_001A5E58[];

s32 func_0053C788(char *a, s32 b) {
    char *p = *(char **)(a + 144);
    if (p != 0) {
        p[48] = 1;
        *(s32 *)(p + 60) = D_001A5E58[0];
        *(s32 *)(p + 64) = b;
        return 1;
    }
    return 0;
}
