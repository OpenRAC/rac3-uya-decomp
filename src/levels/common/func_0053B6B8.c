#include "common.h"

extern s16 D_00294038[][64];
extern u8 *D_0024C05C;

u8 *func_0053B6B8(s32 idx, s32 id) {
    s32 i;
    u8 *m;
    u8 *p;

    for (i = 1; i <= D_00294038[idx][0]; i++) {
        m = D_0024C05C + D_00294038[idx][i] * 256;
        p = *(u8 **)(m + 104);
        if (p != 0 && *(s16 *)(p + 126) == id) {
            return m;
        }
    }
    return 0;
}
