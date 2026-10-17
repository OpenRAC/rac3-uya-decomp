#include "common.h"

typedef int u128_00376398 __attribute__((mode(TI)));

extern s32 D_001E1C00[];
extern u128_00376398 D_001E1BF0[];
extern u128_00376398 D_001E1B40[];

s32 func_00376398(u128_00376398 *out) {
    if (D_001E1C00[0] != 1) {
        *out = D_001E1B40[0];
        return 0;
    }
    *out = D_001E1BF0[0];
    return 1;
}
