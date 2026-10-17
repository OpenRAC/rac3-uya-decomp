#include "common.h"
extern int D_001E2280[];
int func_003C15E0(int a)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (D_001E2280[i] == 0) {
            D_001E2280[i] = a;
            return i;
        }
    }
    return -1;
}
