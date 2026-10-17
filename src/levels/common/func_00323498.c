#include "common.h"

extern void func_0041A5D8(u8 *, s32, s32);

void func_00323498(u8 *a0) {
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        func_0041A5D8(a0 + 16, 0x305080, 1);
    }
}
