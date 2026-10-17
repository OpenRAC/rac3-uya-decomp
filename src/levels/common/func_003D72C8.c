#include "common.h"
extern u8 *func_00447168(void);
u8 func_003D72C8(u8 *a0) {
    u8 *p;
    if (*(s32 *)(*(u8 **)(a0 + 104) + 372) != 0) {
        return 0;
    }
    p = func_00447168();
    if (p[13] != 255) {
        return p[13];
    }
    return 2;
}
