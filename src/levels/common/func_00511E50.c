#include "common.h"

extern s32 func_0051DC60(s32 *);
s32 func_00511E50(s32 *a0, s32 a1) {
    u8 *t;
    if (func_0051DC60(a0) != 0) {
        return 0;
    }
    t = (u8 *)a0[1];
    if (t != 0 && (u32)a1 < 8 && *(s32 *)(t + (a1 << 2)) != 0) {
        *(s32 *)(t + 0x14) = a1;
        return 1;
    }
    return 0;
}
