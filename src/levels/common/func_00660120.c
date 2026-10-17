#include "common.h"

extern u8 *D_001DAAE0;
extern u8 *D_001DAAE4;

u8 *func_00660120(void) {
    u8 *p = D_001DAAE0;
    D_001DAAE0 = *(u8 **)(p + 88);
    *(u8 **)(p + 88) = D_001DAAE4;
    D_001DAAE4 = p;
    return p;
}
