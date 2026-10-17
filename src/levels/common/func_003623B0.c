#include "common.h"
extern s32 D_001DD7D0;
extern s32 D_0028F1E0[];
s32 func_003623B0(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_001DD7D0; i++) {
        if (D_0028F1E0[i] != 0) n++;
    }
    return n;
}
