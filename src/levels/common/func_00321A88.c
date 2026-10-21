#include "common.h"

/* localdecomp:start func_00321A88 */
extern u8 *D_001E1838[];
extern f32 *func_00440728(u8 *);
s32 func_00321A88(u8 *a0) {
    u8 **q;
    f32 *p;
    s32 i;
    s32 j;

    for (i = 0, q = D_001E1838; i < 7; q++, i++) {
        p = func_00440728(a0);
        if (*q == a0) return 0;
        if (a0 == 0) return 0;
        if (a0[32] == 254) return 0;
        if (a0[32] == 253) return 0;
        if (p == 0) return 0;
        if (*p <= 0.0f) return 0;
        if (*(u16 *)(a0 + 52) & 2) return 0;
        if (a0[49] == 0) return 0;
    }
    for (j = 0; j < 7; j++) {
        if (D_001E1838[j] == 0) {
            D_001E1838[j] = a0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_00321A88 */
