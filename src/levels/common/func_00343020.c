#include "common.h"

/* localdecomp:start func_00343020 */
extern u8 D_001A30B0[];
extern void func_004A6E88(s32);
void func_00343020(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    s32 i = *(s32 *)(s0 + 12);
    if (i != -1) {
        u8 *e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == a0 && e[208] != 0) {
            func_004A6E88(i);
        }
    }
    *(s32 *)(s0 + 12) = -1;
}
/* localdecomp:end func_00343020 */
