#include "common.h"
extern s32 D_001DAAE8;
extern char D_00337800[];
char *func_006646B0(s32 a0) {
    char *r = 0;
    if (a0 < D_001DAAE8) r = D_00337800 + a0 * 832;
    return r;
}
