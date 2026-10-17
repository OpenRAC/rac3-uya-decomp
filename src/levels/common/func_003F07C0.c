#include "common.h"
extern u8 *D_002495D0[];
s32 func_003F07C0(s32 id) {
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 *m = D_002495D0[i];
        if (m != 0) {
            s32 *v = *(s32 **)(m + 104);
            if (v[1] == id) {
                return v[0];
            }
        }
    }
    return 0;
}
