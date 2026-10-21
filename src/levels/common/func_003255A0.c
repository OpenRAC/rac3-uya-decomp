#include "common.h"

/* localdecomp:start func_003255A0 */
int func_003255A0(char *a0, int a1) {
    int i;
    for (i = 0; i < 16; i++) {
        if (a1 == ((int *)(a0 + 288))[i]) {
            break;
        }
    }
    return i;
}
/* localdecomp:end func_003255A0 */
