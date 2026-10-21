#include "common.h"

/* localdecomp:start func_00490890 */
extern u8 D_001D54B0[];

int func_00490890(void) {
    int n = 0;
    int i;
    for (i = 0; i < 32; i++) {
        if (D_001D54B0[i]) {
            n++;
        }
    }
    return n;
}
/* localdecomp:end func_00490890 */
