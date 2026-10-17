#include "common.h"
void func_003497C8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    s32 i;
    for (i = 2; i >= 0; i--) {
        p[4 + i] = 0;
    }
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}
