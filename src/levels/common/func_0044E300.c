#include "common.h"
extern s32 D_001D6740[];
extern u8 D_001DFCD0[];
extern u8 D_001D6750[];
extern f32 func_0040BFB0(void *, void *);
f32 func_0044E300(void *a0) {
    if (D_001D6740[0] != 0) {
        return 100.0f - func_0040BFB0(a0, D_001D6750);
    }
    return func_0040BFB0(a0, D_001DFCD0);
}
