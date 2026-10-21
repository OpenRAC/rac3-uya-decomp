#include "common.h"

/* localdecomp:start func_004A6D20 */
extern u8 D_001A30B0[];

int func_004A6D20(int a0, int a1)
{
    if (a1 >= 0) {
        u8 *p = D_001A30B0 + a1 * 128;
        if (*(int *)(p + 220) == a0) {
            u8 b = p[208];
            if ((u32)(b - 1) < 2 || b == 7) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_004A6D20 */
