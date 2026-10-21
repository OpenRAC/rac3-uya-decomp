#include "common.h"

/* localdecomp:start func_00376820 */
extern s32 D_001E1160[];
void func_00376820(s32 a0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (D_001E1160[i] == 0) {
            D_001E1160[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_00376820 */
