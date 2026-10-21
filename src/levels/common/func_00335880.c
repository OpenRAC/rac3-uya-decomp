#include "common.h"

/* localdecomp:start func_00335880 */
int func_00335880(u8 *a0, int a1) {
    int *p = *(int **)(a0 + 104);
    if (a0[149] || a1 == -1) {
        p[28] = -1;
        return 0;
    }
    p[28] = a1;
    a0[149] = 1;
    return 1;
}
/* localdecomp:end func_00335880 */
