#include "common.h"

extern u8 D_001D67CC;
extern f32 D_001D67D0;
extern f32 D_001E6DF0[];

s32 func_003FFFD8(void) {
    if (D_001D67CC != 0) {
        return 0;
    }
    D_001D67CC = 1;
    D_001D67D0 = D_001E6DF0[0];
    return 1;
}
