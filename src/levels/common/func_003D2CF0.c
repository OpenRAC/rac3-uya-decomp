#include "common.h"
extern s32 D_001E23E0[];
void func_003D2CF0(s32 a0) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (D_001E23E0[i] == a0) {
            D_001E23E0[i] = 0;
            return;
        }
    }
}
