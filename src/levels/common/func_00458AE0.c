#include "common.h"

/* localdecomp:start func_00458AE0 */
extern s32 D_0021F740[];
extern s32 func_00458B30(void *a0, s32 a1);
s32 func_00458AE0(void *a0, s32 a1) {
    s32 v;
    if (a1 == -1) return 0;
    v = D_0021F740[a1];
    if (v == 0) return 0;
    return func_00458B30(a0, v);
}
/* localdecomp:end func_00458AE0 */
