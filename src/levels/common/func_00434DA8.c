#include "common.h"

extern u8 D_001D5550[];
extern s32 func_00434D88();
s32 func_00434DA8(void) {
    s32 r = 0;
    if (D_001D5550[0] != 0) r = func_00434D88() != 0;
    return r;
}
