#include "common.h"

extern void func_004374C8();
extern s32 D_001E0000[];
extern s32 D_001E0040[];

extern s32 D_001E0000[];
extern s32 D_001E0040[];
void func_004374C8(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_001E0000[i] = 0;
        D_001E0040[i] = 0;
    }
}
