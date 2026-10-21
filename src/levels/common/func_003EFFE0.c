#include "common.h"

/* localdecomp:start func_003EFFE0 */
extern int D_002BF4E0[];
extern int func_003F0118(int);
int func_003EFFE0(unsigned int a)
{
    int r;
    if (a >= 98) {
        r = -1;
    } else {
        r = func_003F0118(D_002BF4E0[a]);
    }
    return r;
}
/* localdecomp:end func_003EFFE0 */
