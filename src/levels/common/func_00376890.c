#include "common.h"
extern u8 *D_001E1160[];
extern s32 func_00440848(s32 a0);
s32 func_00376890(void) {
    s32 i;
    u8 *e;
    i = func_00440848(4);
    e = D_001E1160[i];
    if (e != 0) {
        e[32] = 3;
        D_001E1160[i] = 0;
        return 1;
    }
    for (i = 0; i < 6; i++) {
        e = D_001E1160[i];
        if (e != 0) {
            e[32] = 3;
            D_001E1160[i] = 0;
            return 1;
        }
    }
    return 0;
}
