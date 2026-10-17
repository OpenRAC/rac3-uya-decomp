#include "common.h"
extern u8 D_00142731[];
s32 func_0034BB98(void) {
    s32 v = D_00142731[0];
    s32 n = 0;
    while (v != 0) {
        n += v % 2;
        v >>= 1;
    }
    return n;
}
