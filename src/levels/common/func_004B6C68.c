#include "common.h"

extern s32 D_001D6690[];
extern s32 D_001D6694[];

s32 func_004B6C68(void) {
    s32 r = 0;
    if (D_001D6690[0] == 2 || D_001D6694[0] == 2) {
        r = 1;
    }
    return r;
}
