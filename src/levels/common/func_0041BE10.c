#include "common.h"

/* localdecomp:start func_0041BE10 */
extern s32 D_001D680C;

extern s32 D_001DFDE0[];
extern s32 D_001DFDE8[];
extern s32 D_001D6898;
extern s32 D_001D680C;
void func_0041BE10(u8 *p) {
    D_001DFDE0[0] = 4;
    D_001DFDE8[0] = (s32)&D_001D6898;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x1E;
    D_001D680C = 0;
}
/* localdecomp:end func_0041BE10 */
