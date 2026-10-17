#include "common.h"

extern u8 *D_001E009C[];

u8 *func_003B1C38(u8 *a0) {
    return D_001E009C[0] + (**(s32 **)(a0 + 104) << 8);
}
