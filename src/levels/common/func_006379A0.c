#include "common.h"
void func_006379A0(u8 *a0, s32 a1, s32 a2, s32 a3) {
    s16 *p = (s16 *)(a0 + 9200);
    s32 i;
    for (i = 0; i < 2; i++, p += 4) {
        if (p[0] == 0) {
            p[0] = 1;
            p[3] = a3;
            p[2] = a2;
            p[1] = a1;
            return;
        }
    }
}
