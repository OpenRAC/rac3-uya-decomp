#include "common.h"
extern u8 *D_001E009C[];
extern u8 *D_001E00A0[];
u8 *func_004A0230(s32 a0, s32 a1) {
    u8 *p;
    for (p = D_001E009C[0]; p != D_001E00A0[0]; p += 256) {
        if (*(s16 *)(p + 178) == a1) return p;
    }
    return 0;
}
