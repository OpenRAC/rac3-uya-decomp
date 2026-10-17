#include "common.h"

extern u8 *func_003252E8();

s32 func_00326F08(void) {
    return *(s32 *)(*(u8 **)(func_003252E8() + 104) + 64);
}
