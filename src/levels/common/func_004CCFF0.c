#include "common.h"

extern u32 *func_004C8AE0(u8 *);

u32 func_004CCFF0(u8 *a0) {
    return *func_004C8AE0(a0 + 700) & 0xFF000000;
}
