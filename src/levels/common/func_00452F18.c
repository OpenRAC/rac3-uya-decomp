#include "common.h"

int func_00452F18(unsigned char *a0)
{
    if (!(a0[190] & 0x20)) {
        a0[190] |= 0x20;
        return 1;
    }
    return 0;
}
