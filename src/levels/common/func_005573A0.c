#include "common.h"
extern s32 D_001DFB28;
s32 func_005573A0(s32 a0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if ((&D_001DFB28)[i] == a0) return 1;
    }
    return 0;
}
