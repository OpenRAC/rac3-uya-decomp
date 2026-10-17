#include "common.h"
int func_00414130(char *a) {
    int i;
    for (i = 0; i < 5; i++) {
        if (((int *)(a + 112))[i] != 0) {
            return 0;
        }
    }
    return 1;
}
