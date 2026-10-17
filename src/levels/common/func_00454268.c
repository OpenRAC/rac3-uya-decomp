#include "common.h"

extern s32 D_001DFD08[];
extern s32 D_001D678C;

void func_00454268(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        D_001DFD08[i - 4] = 0;
    }
    D_001D678C = 0;
}
