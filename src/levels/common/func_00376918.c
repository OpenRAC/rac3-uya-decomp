#include "common.h"
extern int D_001E1160[];
int func_00376918(int a)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (D_001E1160[i] == a) {
            D_001E1160[i] = 0;
            return 1;
        }
    }
    return 0;
}
