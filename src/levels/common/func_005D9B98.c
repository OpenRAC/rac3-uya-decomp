#include "common.h"

extern u8 D_0024C510[];
extern u8 D_0024C518[];

s32 func_005D9B98(s32 a0) {
    s32 r = 0;
    if (D_0024C510[a0] != 0 || D_0024C518[a0] != 0) {
        r = 1;
    }
    return r;
}
