#include "common.h"

extern s32 D_001D4CEC_g;
extern s32 func_00430060();

extern s32 D_001D4CEC_g;
extern s32 D_001D7588;
s32 func_00430060(u32 a) {
    if (a >= 4) return 0;
    D_001D7588 = a;
    D_001D4CEC_g |= 0x1000;
    return 1;
}
