#include "common.h"

u8 func_004CB720(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
