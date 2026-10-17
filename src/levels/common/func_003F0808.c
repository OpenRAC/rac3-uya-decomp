#include "common.h"
extern u8 *D_002495D0[];
extern s32 func_00415FA0(u8 *a0);
s32 func_003F0808(s32 a0) {
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 *p = D_002495D0[i];
        if (p != 0 && *(s32 *)(*(u8 **)(p + 104) + 4) == a0) {
            return func_00415FA0(p);
        }
    }
    return 0;
}
