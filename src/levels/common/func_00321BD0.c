#include "common.h"
extern s32 D_001E1850[];
void func_00321BD0(void) {
    s32 i;
    for (i = 6; i >= 0; i--) {
        D_001E1850[i - 6] = 0;
    }
}
