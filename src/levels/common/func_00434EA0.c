#include "common.h"

extern u8 D_00142CA0[];
extern s32 D_001D7B58[2];
extern s32 func_00434EA0();

extern u8 D_00142CA0[];
extern s32 D_001D7B58[2];
s32 func_00434EA0(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_00142CA0[D_001D7B58[i]] == 0) return 0;
    }
    return 1;
}
