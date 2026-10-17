#include "common.h"

void func_004A78E8(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (p[0x10] == 1) {
                p[0x10] = 2;
            }
        } else {
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x40) = 0;
    p[0x10] = 0;
        }
    }
}
