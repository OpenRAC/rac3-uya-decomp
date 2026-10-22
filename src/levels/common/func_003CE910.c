#include "common.h"

typedef struct { u8 pad[0x1C]; u8 *f1C; } S_3CE910;
extern S_3CE910 *D_001DEA84;
extern f32 D_001DEBD0;
extern u8 *D_001E1D90[];

s32 func_003CE910(s32 arg0) {
    s16 *p;

    if (*(s16 *)(D_001E1D90[0] + 0x86) != 0x13) {
        return 1;
    }
    p = (s16 *)(*(u8 **)(*(u8 **)(D_001DEA84[arg0].f1C + 4) + 0x70) + 0x40);
    if (p[10] == 1 && D_001DEBD0 == 1.0f) {
        return 1;
    }
    return p[10] == 3;
}
