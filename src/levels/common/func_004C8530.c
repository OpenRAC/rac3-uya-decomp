#include "common.h"

extern s32 func_0051DC38();
extern u8 D_001DB1F0[];
void func_004C8530(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001DB1F0;
    if (f & 1) func_0051DC38(p);
}
