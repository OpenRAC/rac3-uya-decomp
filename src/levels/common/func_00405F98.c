#include "common.h"

extern u8 D_001E2C00[];

s32 func_00405F98(u8 *obj) {
    u8 *e = (u8 *)(*(s32 *)(obj + 148) * 1120 + (s32)D_001E2C00);
    return *(s32 *)(e + 588) == 0x1D;
}
