#include "common.h"

/* localdecomp:start func_00457248 */
extern s32 D_001D7DB8;

void func_00457248(void) {
    s32 v = D_001D7DB8 - 1;
    D_001D7DB8 = v;
    if (v < 0) {
        D_001D7DB8 = 0;
    }
}
/* localdecomp:end func_00457248 */
