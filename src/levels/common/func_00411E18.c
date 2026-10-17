#include "common.h"

extern s32 D_001D4D08_0038CBD0;
extern s32 D_001D4D0C_0038CBD0;
extern void func_00411DA8(void);
void func_00411E18(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_0038CBD0 += dx; D_001D4D0C_0038CBD0 += dy; if (clamp) { s32 x = D_001D4D08_0038CBD0 >= 0 ? D_001D4D08_0038CBD0 : 0; s32 y = D_001D4D0C_0038CBD0 >= 0 ? D_001D4D0C_0038CBD0 : 0; D_001D4D08_0038CBD0 = x <= 3000 ? x : 3000; D_001D4D0C_0038CBD0 = y <= 450 ? y : 450; }
    func_00411DA8();
}
