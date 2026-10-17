#include "common.h"

extern void func_005130C8(int a, int b);

void func_004BD430(int *a0, int a1, int a2)
{
    while (a0[0] != 0) {
        if (a0[0] == a1) {
            a0[3] = a2;
            func_005130C8(a0[0], a2);
            return;
        }
        a0 += 12;
    }
}
