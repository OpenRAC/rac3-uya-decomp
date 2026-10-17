#include "common.h"
extern u8 D_001A30B0[];
extern void func_004A6E88(s32 a0);
void func_003C5670(s32 unused, u8 *s) {
    s32 idx;
    u8 *e;

    *(s32 *)(s + 1652) = 0;
    idx = *(s32 *)(s + 160);
    *(s32 *)(s + 1684) = 0;
    *(s32 *)(s + 1704) = 0;
    *(s32 *)(s + 176) = 0;
    if (idx != -1) {
        e = D_001A30B0 + idx * 128;
        if (*(s32 *)(e + 220) == *(s32 *)(s + 76) && e[208] != 0) {
            func_004A6E88(idx);
        }
    }
    *(s32 *)(s + 160) = -1;
}
