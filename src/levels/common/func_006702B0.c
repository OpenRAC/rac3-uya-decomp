#include "common.h"
void func_006702B0(u8 *a0, s32 a1) {
    s32 i;
    s32 c = 255;
    *(s32 *)(a0 + 872) = a1;
    for (i = 9; i >= 0; i--) a0[66 + i * 80] = c;
    *(s16 *)(a0 + 876) = 0;
}
