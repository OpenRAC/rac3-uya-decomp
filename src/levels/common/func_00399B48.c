#include "common.h"

extern void func_0042F238(u8 *o, s32 a, s32 b);

void func_00399B48(u8 *a) {
    if (a[32] == 0) {
        *(s32 *)(*(u8 **)(a + 104) + 8) = 0;
        func_0042F238(a, 4, -1);
    }
}
