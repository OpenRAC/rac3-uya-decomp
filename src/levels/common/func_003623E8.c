#include "common.h"
extern s32 D_001DD7D0;
extern s32 D_0028F140[];
extern s32 D_0028F1E0[];
s32 func_003623E8(s32 *out) {
    s32 i;
    for (i = 0; i < D_001DD7D0; i++) {
        s32 v = D_0028F1E0[i];
        if (v != 0) {
            D_0028F1E0[i] = 0;
            *out = D_0028F140[i];
            D_0028F140[i] = 0;
            return v;
        }
    }
    return -1;
}
