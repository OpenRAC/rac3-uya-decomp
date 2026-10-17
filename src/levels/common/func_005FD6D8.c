#include "common.h"

extern u8 *D_002C2940[];

void func_005FD6D8(void)
{
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            u8 *p = D_002C2940[i * 4 + j];
            if (p != 0) {
                *(int *)(p + 152) = 0;
            }
        }
    }
}
