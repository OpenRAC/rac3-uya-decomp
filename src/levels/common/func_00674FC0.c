#include "common.h"
extern u8 *D_001E07CC;
extern void func_0058F1B0(void *dst, void *src, s32 n);
s32 func_00674FC0(s32 a0, s32 a1, s32 a2, void *a3) {
    s32 buf[2];
    u8 *m;
    s32 *q;
    func_0058F1B0(buf, a3, 8);
    if (buf[0] >= 0) {
        m = D_001E07CC + (buf[0] << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            q = *(s32 **)(m + 104);
            if (q != 0 && *q == -1) {
                *q = buf[1];
            }
        }
    }
    return 8;
}
