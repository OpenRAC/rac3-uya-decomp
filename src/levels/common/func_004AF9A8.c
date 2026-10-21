#include "common.h"

/* localdecomp:start func_004AF9A8 */
typedef struct { u8 pad[20]; u16 h20; u16 h22; u8 pad2[7]; u8 b31; } E_004AF9A8;
extern s32 D_001EA9D4[];
extern u8 D_0023E880[];
extern E_004AF9A8 *D_001E0F54;
extern E_004AF9A8 *D_001E0F58;
extern s32 D_001E0F64;
extern u8 *D_001E0F88;
extern s32 D_001E0F7C;
extern s32 D_001E0F80;
extern s32 D_001E0F84;
void func_004AF9A8(void) {
    E_004AF9A8 *p;
    D_001E0F64 = D_001EA9D4[0];
    D_001E0F88 = D_0023E880;
    D_001E0F7C = 0;
    D_001E0F80 = 0;
    D_001E0F84 = 0;
    for (p = D_001E0F54; p != D_001E0F58; p++) {
        p->h22 = 0;
        p->h20 = 0xFFFF;
        p->b31 = 255;
    }
}
/* localdecomp:end func_004AF9A8 */
