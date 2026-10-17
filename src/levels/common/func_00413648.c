#include "common.h"

extern int D_001EA740[];

void func_00413648(int a0, int a1)
{
    int x = 64;
    int y = 16;
    if (a0) x = a0;
    if (a1) y = a1;
    D_001EA740[35] = x;
    D_001EA740[36] = y;
}
