#include "common.h"

extern s32 D_001D4CE8_g;

typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
extern s32 D_00142438[];
extern u8 D_001D672D;
extern s32 D_001D4CE8_g;
void func_0042F380(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D672D != 0 || (*(s32 *)&D_001D4CEC_f & 0x12)) D_001D4CE8_g = 8;
}
