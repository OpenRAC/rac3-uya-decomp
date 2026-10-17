#include "common.h"

typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_00142430_00396BC0;
extern s32 D_001D4CEC_00396BC0;
extern s32 D_001D4CE8_00396BC0;
void func_0042FBC8(void) {
    S_396BC0 *s = &D_00142430_00396BC0;
    D_001D4CEC_00396BC0 &= ~4;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CEC_00396BC0 |= 0x40;
            D_001D4CE8_00396BC0 = 0x16;
        } else {
            D_001D4CE8_00396BC0 = s->f15C;
        }
    }
}
