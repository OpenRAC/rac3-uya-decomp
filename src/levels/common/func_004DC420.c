#include "common.h"

extern s32 D_001A71A0[];
extern s32 D_001A5ED4[];
extern s32 D_001A5DE0[];

s32 func_004DC420(s32 a0) {
    if (a0 == 0 || a0 == 2 || a0 == 3 || a0 == 4 || a0 == 6) {
        return D_001A71A0[0];
    }
    if (a0 == 1) {
        return D_001A5ED4[0];
    }
    if (a0 == 7) {
        return D_001A5DE0[0];
    }
    return 0;
}
