#include "common.h"

typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_00395360;
extern u8 D_01FF7FF0[];
extern s32 func_0045C990();
s32 func_00428008(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    D_001D4B50_00395360 = p;
    *p = 0x60;
    func_0045C990((s32)D_001D4B50_00395360 + D_001D4B50_00395360[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
