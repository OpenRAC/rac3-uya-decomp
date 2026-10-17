#include "common.h"
extern u8 D_002393F0[];
s32 func_004B7618(u32 id, s32 a1, s32 a2, s32 a3) {
    u8 *e = 0;
    u32 idx = id >> 16;
    if (idx < 12) {
        u8 *p = D_002393F0 + idx * 96;
        if (p[0] != 0 && *(u16 *)(p + 4) == (id & 0xFFFF)) {
            e = p;
        }
    }
    if (e != 0) {
        *(s32 *)(e + 16) = a1;
        *(s32 *)(e + 20) = a2;
        *(s32 *)(e + 24) = a3;
        return 1;
    }
    return 0;
}
