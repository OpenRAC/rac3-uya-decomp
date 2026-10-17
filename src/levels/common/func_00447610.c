#include "common.h"

extern s32 D_001D67B4;
extern s32 D_001EE428[];

void func_00447610(s32 a0) {
    s32 n = D_001D67B4;
    if (n < 64) {
        D_001D67B4 = n + 1;
        D_001EE428[n] = a0;
    }
}
