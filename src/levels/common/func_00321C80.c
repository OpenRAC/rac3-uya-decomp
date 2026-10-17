#include "common.h"

extern int D_001E1838[];

int func_00321C80(void) {
    int i;
    for (i = 0; i < 7; i++) {
        if (D_001E1838[i]) {
            return 1;
        }
    }
    return 0;
}
