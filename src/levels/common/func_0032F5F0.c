#include "common.h"

/* localdecomp:start func_0032F5F0 */
extern s32 D_00278A10[];
void func_0032F5F0(void) {
    s32 i;
    D_00278A10[138] = 5;
    D_00278A10[137] = 0;
    D_00278A10[136] = 0;
    for (i = 0; i < 64; i++) {
        D_00278A10[i] = 0;
        D_00278A10[i + 64] = 0;
    }
    for (i = 7; i >= 0; i--) {
        D_00278A10[i + 128] = 0;
    }
}
/* localdecomp:end func_0032F5F0 */
