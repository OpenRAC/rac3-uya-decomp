#include "common.h"

/* localdecomp:start func_003FE4C0 */
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 func_003FE420(s32 a0, s32 a1);
s32 func_003FE4C0(s32 a0) {
    u8 s = D_00142692[0];
    s32 v;
    if (s != 0) {
        return 3;
    }
    v = 3 - func_003FE420(D_001D545C, a0) / 100;
    if (s < v) {
        return v;
    }
    return 1;
}
/* localdecomp:end func_003FE4C0 */
