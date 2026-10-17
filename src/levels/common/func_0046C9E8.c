#include "common.h"
extern u32 D_001D545C[];
extern s32 D_002F1D70[];
extern s32 D_001EEA20[];
s32 func_0046C9E8(s32 a0) {
    u32 n;
    s32 i;
    n = D_001D545C[0];
    if (n >= 19) {
        return 0;
    }
    for (i = D_002F1D70[n]; i < D_002F1D70[n + 1]; i++) {
        if (D_001EEA20[i] == a0) {
            return i;
        }
    }
    return -1;
}
