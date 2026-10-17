#include "common.h"
s32 func_0062F190(char *a0, s32 a1) {
    char *p = a0 + a1 * 80;
    s32 x = (*(s32 *)(p + 1140) == 2) ? *(s32 *)(p + 1144) : -1;
    return x == 14 || x == 15;
}
