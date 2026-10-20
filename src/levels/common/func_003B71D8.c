#include "common.h"

extern u16 *D_0021DEA0[];
extern s32 D_001E00D8;
extern u8 *D_001E009C;

void func_003B71D8(u8 *a0, s32 a1) {
    u16 *p = D_0021DEA0[a0[33]];
    while (a0[33] != 255 && a0[33] <= D_001E00D8 && p != 0
           && (((s16 *)p)[-1] >= 0 || p == D_0021DEA0[a0[33]])) {
        u8 *m = D_001E009C + ((*p & 0x7FFF) << 8);
        if (m == 0) {
            return;
        }
        if (a1 == 0) {
            if ((m[52] ^ 1) & 1) {
                m[49] = 0;
                *(u16 *)(m + 52) |= 1;
            }
        } else {
            u16 h = *(u16 *)(m + 52);
            if (h & 1) {
                *(u16 *)(m + 52) = h & 0xFFFE;
                m[49] = 1;
            }
        }
        p++;
    }
}
