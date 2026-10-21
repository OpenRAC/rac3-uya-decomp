#include "common.h"

/* localdecomp:start func_00420180 */
extern s32 func_004175C8(s32 i, s32 a);
extern void func_00416BF8(s32 i);

void func_00420180(s32 a0)
{
    s32 i;

    for (i = 0; i < 156; i++) {
        if (func_004175C8(i, a0) && i != 0) {
            func_00416BF8(i);
        }
    }
}
/* localdecomp:end func_00420180 */
