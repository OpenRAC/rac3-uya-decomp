#include "common.h"
extern s32 D_001E1160[];
s32 func_00376858(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (D_001E1160[i] == 0) return 0;
    }
    return 1;
}
