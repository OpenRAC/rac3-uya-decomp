#include "common.h"

/* localdecomp:start func_0040D5C0 */
extern s32 *D_001D55C4[];
s32 func_0040D5C0(void) {
    s32 *p = D_001D55C4[0];
    s32 r = -1;
    if (p) r = p[-1];
    return r;
}
/* localdecomp:end func_0040D5C0 */
