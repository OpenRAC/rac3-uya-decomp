#include "common.h"

extern s32 D_001D98D8[2];
s32 func_004ABE68(s32 k) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_001D98D8[i] == k) return i;
    }
    return -1;
}
