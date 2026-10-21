#include "common.h"

/* localdecomp:start func_0042B6F0 */
extern s32 *D_001D8D80[];
extern s32 D_001D545C[];
s32 func_0042B6F0(s32 a0) {
    s32 idx = -1;
    s32 i;
    for (i = 0; i < 60; i++) {
        if (D_001D8D80[0][i] == a0) {
            idx = i;
            break;
        }
    }
    if (D_001D8D80[0][idx] == 1 && D_001D545C[0] != 1) {
        idx = -1;
    }
    if (D_001D8D80[0][idx] == 11) {
        return -1;
    }
    return idx;
}
/* localdecomp:end func_0042B6F0 */
