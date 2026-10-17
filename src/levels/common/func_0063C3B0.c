#include "common.h"

extern void func_0063C1D8(u8 *, u8 *);

void func_0063C3B0(u8 *a0) {
    s32 i;
    u8 *p = a0 + 1888;

    *(s16 *)(a0 + 9378) = 0;
    for (i = 11; i >= 0; i--) {
        func_0063C1D8(a0, p);
        p += 176;
    }
}
