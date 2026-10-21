#include "common.h"

/* localdecomp:start func_00445BF0 */
void func_00445BF0(s32 *a0, s32 *a1, s32 *a2, s32 a3) {
    s32 t;
    if (a3 & 1) {
        t = *a0;
        *a0 = *a1;
        *a1 = t;
    }
    if (a3 & 2) {
        t = *a1;
        *a1 = *a2;
        *a2 = t;
    }
    if (a3 & 4) {
        t = *a2;
        *a2 = *a0;
        *a0 = t;
    }
}
/* localdecomp:end func_00445BF0 */
