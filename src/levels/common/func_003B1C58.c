#include "common.h"

/* localdecomp:start func_003B1C58 */
extern s32 D_001DE674;

void func_003B1C58(s32 a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 v = D_001DE674;
    s32 w = *(s32 *)(p + 80);
    *(s32 *)(p + 88) = v;
    D_001DE674 = a0;
    *(s32 *)(p + 84) = w;
}
/* localdecomp:end func_003B1C58 */
