#include "common.h"
extern int D_001E1150[];
int func_0037B650(int a)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (D_001E1150[i] == a) {
            D_001E1150[i] = 0;
            return 1;
        }
    }
    return 0;
}
