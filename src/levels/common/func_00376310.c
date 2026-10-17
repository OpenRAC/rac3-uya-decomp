#include "common.h"

extern s32 D_001E1B24[];
extern s32 D_001E1C00[];
extern s32 D_001E1BD0;

s32 func_00376310(s32 id) {
    if (id != D_001E1B24[0]) return 0;
    if (D_001E1C00[0] != 1) return 0;
    if (D_001E1BD0 < 9) return 0;
    return 1;
}
