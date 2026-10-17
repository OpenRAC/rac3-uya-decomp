#include "common.h"
extern u8 D_001A4BE0[];
void func_003C6A68(void) {
    u8 *p = D_001A4BE0;
    s32 v = 2;
    *(s32 *)(p + 568) = v;
    *(s16 *)(p + 546) = v;
}
