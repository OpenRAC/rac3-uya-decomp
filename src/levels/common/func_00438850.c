#include "common.h"

extern s32 D_0021DEA0[];

s32 func_00438850(s32 a0) {
    if (a0 == 255) {
        return 1;
    }
    return D_0021DEA0[a0] == 0;
}
