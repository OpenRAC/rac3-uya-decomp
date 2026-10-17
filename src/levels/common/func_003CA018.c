#include "common.h"

s32 func_003CA018(u8 *a) {
    u8 t = a[32];
    s32 r = 0;
    if (t == 28 || a == 0 || t == 254 || t == 253) {
        r = 1;
    }
    return r;
}
