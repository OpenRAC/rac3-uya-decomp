#include "common.h"

int func_004435E8(int a0)
{
    int *p = *(int **)(a0 + 152);
    if (p != 0 && p[2] != 0) {
        return 1;
    }
    return 0;
}
