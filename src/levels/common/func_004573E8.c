#include "common.h"

extern s32 D_001D7DC8;
extern s32 D_001E02A0[];

s32 func_004573E8(void) {
    s32 v = D_001D7DC8;
    if (v != 0) {
        return D_001E02A0[v - 1];
    }
    return -2;
}
