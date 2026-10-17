#include "common.h"

extern u8 D_001A30B0[];
void func_004A6E88(u32 i) {
    if (i < 52) {
        u8 *e = D_001A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
