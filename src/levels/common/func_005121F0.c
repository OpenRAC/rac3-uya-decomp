#include "common.h"

/* localdecomp:start func_005121F0 */
extern u8 D_001DC100_g;
extern s32 func_0051DC38();
void func_005121F0(u8 *p, s32 f) {
    *(u8 **)(p + 8) = &D_001DC100_g;
    if (f & 1) func_0051DC38(p);
}
/* localdecomp:end func_005121F0 */
