#include "common.h"

extern u8 D_0026E950[];
extern s32 D_0026DF00[];

void func_00421BD0(u8 *a0, s32 a1) {
    u8 b;
    *(s16 *)(a0 + 170) = a1;
    b = D_0026E950[(s16)a1];
    a0[34] = b;
    *(s32 *)(a0 + 36) = D_0026DF00[a0[34]];
}
