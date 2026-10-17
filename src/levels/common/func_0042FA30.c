#include "common.h"

typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x170]; s32 f17C; } S_142430_396A28;
extern S_142430_396A28 D_00142430_00396A28;
extern s32 D_001D4CE8_00396A28;
extern s32 D_001D4CEC_00396A28;
void func_0042FA30(void) {
    s32 f = D_001D4CEC_00396A28;
    if (f & 4) D_001D4CE8_00396A28 = 0x1E;
    if (f & 2) D_001D4CE8_00396A28 = 0x1D;
    if (f & 0x800) D_001D4CE8_00396A28 = 0xC;
    if (f & 0x80) {
        D_001D4CE8_00396A28 = 0x18;
        D_001D4CEC_00396A28 = (f ^ 0x80) | 0x40;
        return;
    }
    if (f & 0x100) {
        D_001D4CE8_00396A28 = 0x16;
        D_001D4CEC_00396A28 = (f ^ 0x100) | 0x40;
        return;
    }
    if (D_00142430_00396A28.f8 != 2) {
        D_001D4CE8_00396A28 = 4;
        return;
    }
    if (D_00142430_00396A28.f17C) D_001D4CE8_00396A28 = 1;
}
