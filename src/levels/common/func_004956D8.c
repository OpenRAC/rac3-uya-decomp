#include "common.h"

/* localdecomp:start func_004956D8 */
extern s32 func_004950C8(void *, s32, s32);
extern s32 func_00513278(s32, s32);

void func_004956D8(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 i;

    for (i = 0; i < *(s32 *)(arg0 + 16) + 2; i++) {
        func_00513278(func_004950C8(arg0, arg1, i), arg2);
    }
}
/* localdecomp:end func_004956D8 */
