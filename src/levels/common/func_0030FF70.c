#include "common.h"
typedef struct { u8 pad[0x30]; u8 x30; u8 x31; u8 x32; u8 pad33[0x48 - 0x33]; f32 x48; } O_30FF70;
extern f32 D_001E0154;
extern f32 D_001E0158;
void func_0030FF70(O_30FF70 *a0) {
    u32 m;
    D_001E0154 = 1.0f;
    m = a0->x30;
    if (m < a0->x31) {
        m = a0->x31;
    }
    if (m < a0->x32) {
        m = a0->x32;
    }
    if (m >= 128) {
        D_001E0154 *= (f32)(255 - m) * 0.0078125f;
    }
    D_001E0154 *= a0->x48 / D_001E0158;
}
