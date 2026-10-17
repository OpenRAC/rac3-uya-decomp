#include "common.h"

extern s32 D_001E0000[];
extern s32 D_001E0040[];
s32 func_00437470(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_001E0000[i] == 0 || D_001E0000[i] == x) {
            D_001E0000[i] = x;
            D_001E0040[i] = 0;
            return i;
        }
    }
    return -1;
}
