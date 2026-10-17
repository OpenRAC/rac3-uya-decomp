#include "common.h"
extern s32 D_001E1150[];
s32 func_0037B618(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_001E1150[i] == 0) return 0;
    }
    return 1;
}
