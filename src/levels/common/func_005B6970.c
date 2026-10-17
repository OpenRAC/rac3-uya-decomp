#include "common.h"

extern u8 *D_001E07CC;
extern u8 *D_001E07D4;

int func_005B6970(u8 *a0)
{
    u8 *p;
    if (a0 == 0) {
        return 0;
    }
    if (a0 < D_001E07CC || D_001E07D4 < a0) {
        return 0;
    }
    p = *(u8 **)(a0 + 36);
    if (p != 0 && p[70] == 9) {
        return 1;
    }
    return 0;
}
