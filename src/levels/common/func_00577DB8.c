#include "common.h"

/* localdecomp:start func_00577DB8 */
extern s32 D_0024B940[4];
extern s32 D_002578D0[][16];

void func_00577DB8(s32 i, s32 v) {
    s32 j;
    s32 n = D_0024B940[i];

    if (n < 16) {
        for (j = 0; j < n; j++) {
            if (v == D_002578D0[i][j]) {
                return;
            }
        }
        D_002578D0[i][D_0024B940[i]] = v;
        D_0024B940[i]++;
    }
}
/* localdecomp:end func_00577DB8 */
