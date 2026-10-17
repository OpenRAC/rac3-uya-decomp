#include "common.h"

extern u8 D_001E3050[];

u8 *func_003F1368(s32 a0, s32 a1) {
    u8 *p = D_001E3050 + a0 * 8448;
    s32 i;
    for (i = 0; i < 48; i++) {
        if (*(s16 *)(p + 134) == a1) {
            return p;
        }
        p += 176;
    }
    return 0;
}
