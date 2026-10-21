#include "common.h"

/* localdecomp:start func_0031CD78 */
extern u8 *func_0031CF70(s32, s32, s32);

void func_0031CD78(u8 *a0, s32 a1, s32 a2) {
    u8 *r = func_0031CF70(a1, a2, *(s16 *)(a0 + 170) == 0xE9E);
    if (r != 0) {
        *(u8 **)(r + 184) = a0;
    }
}
/* localdecomp:end func_0031CD78 */
