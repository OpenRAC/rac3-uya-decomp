#include "common.h"

/* localdecomp:start func_003E9350 */
typedef struct { u8 pad[0x24C]; s32 x24C; u8 pad250[0x2A0 - 0x250]; s16 x2A0; u8 pad2A2; u8 x2A3; u8 pad2A4[0x2B8 - 0x2A4]; f32 x2B8; f32 x2BC; f32 x2C0; u8 pad2C4[4]; f32 x2C8; f32 x2CC; u8 pad2D0[1120 - 0x2D0]; } E_3E9350;
typedef struct { u8 pad[0x7E]; s16 x7E; u8 pad80[0x94 - 0x80]; s32 x94; } O_3E9350;
extern E_3E9350 D_001E2AC0[];
void func_003E9350(O_3E9350 *a0) {
    E_3E9350 *e = &D_001E2AC0[a0->x94];
    if (e->x24C == 81 || e->x24C == 4) {
        return;
    }
    if (e->x2A0 == 0) {
        e->x2A3 = 0;
        a0->x7E = 2;
        D_001E2AC0[a0->x94].x2C8 = 0.018f;
        D_001E2AC0[a0->x94].x2B8 = 0.018f;
        D_001E2AC0[a0->x94].x2CC = 0.25f;
        D_001E2AC0[a0->x94].x2BC = 0.25f;
        e->x2C0 = 0.5f;
    } else {
        e->x2A0 = 0;
        a0->x7E = 4;
    }
}
/* localdecomp:end func_003E9350 */
