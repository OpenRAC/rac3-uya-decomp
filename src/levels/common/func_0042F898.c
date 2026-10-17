#include "common.h"

typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_00142430_00396890;
extern s32 D_001D4CEC_00396890;
extern s32 D_001D4CE8_00396890;
void func_0042F898(void) {
    S_396890 *s = &D_00142430_00396890;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CE8_00396890 = 0x14;
            D_001D4CEC_00396890 |= 0x40;
        } else {
            s->f148 = 0;
            s->f18 = 0;
            D_001D4CE8_00396890 = 0x1F;
        }
    }
}
