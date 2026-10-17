#include "common.h"
extern s16 *D_0021DEA0[];
extern u8 *D_001E009C;
void func_00442AA8(s32 a0, s32 a1) {
    s16 *p = D_0021DEA0[a0];
    if (p) {
        s16 *q = p;
        do {
            (D_001E009C + (*q & 0x7FFF) * 256)[188] = a1;
        } while (*q++ >= 0);
    }
}
