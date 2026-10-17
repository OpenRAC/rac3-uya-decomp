#include "common.h"

extern s32 *func_00490930();

extern s32 D_001E0B6C;
extern s32 D_001E0B60;
extern u8 *D_001E0B64[];
extern s32 D_001E0B68[];
extern u8 D_001D8F98[];
s32 *func_00490930(void) {
    if (D_001E0B6C == 0) { D_001E0B64[0] = D_001D8F98; D_001E0B60 = 1; D_001E0B6C = 1; D_001E0B68[0] = 0; }
    return &D_001E0B60;
}
