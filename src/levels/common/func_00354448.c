#include "common.h"

extern int func_00436368(void *a0);
extern void func_00352508(float f, void *a0, void *a1);
extern void func_00425278(void *a0, int a1, int a2);
extern void func_00350C38(void *a0, void *a1, int a2, int a3, int t0);

int func_00354448(void *moby)
{
    char *pv = *(char **)((char *)moby + 104);

    if (func_00436368(moby)) {
        func_00352508(*(float *)(pv + 824), moby, pv);
        *(int *)(pv + 824) = 0;
        func_00425278(moby, 3, -1);
        return 1;
    }
    if (*(unsigned char *)((char *)moby + 32) == 15) {
        func_00425278(moby, 1, 5);
        func_00350C38(moby, pv, 2, 0, 10);
        return 1;
    }
    return 0;
}
