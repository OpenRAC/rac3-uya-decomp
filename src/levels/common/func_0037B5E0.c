#include "common.h"

/* localdecomp:start func_0037B5E0 */
extern s32 D_001E1150[];
void func_0037B5E0(s32 a0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_001E1150[i] == 0) {
            D_001E1150[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_0037B5E0 */
