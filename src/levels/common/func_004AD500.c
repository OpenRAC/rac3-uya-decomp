#include "common.h"

extern s32 func_004AD500();
extern s32 D_001D4B00;
extern s32 D_001D4B34;
extern s32 D_001D4B30;

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern E_3A3128 D_0023B360_3A3128[];
extern s32 func_0011F1E0();
s32 func_004AD500(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 cur = D_001D4B30;
    s32 v[4];
    s32 r;
    if (D_001D4B04 - (cur - D_001D4B00) < a2 * 16) return -1;
    if (D_001D4B34 == 0x40) return -2;
    v[0] = a0;
    v[1] = cur;
    v[2] = a1 << 4;
    v[3] = 0;
    func_0011F1E0(v, 1);
    r = D_001D4B34++;
    ((E_3A3128 *)((u8 *)D_0023B360_3A3128 + r * 16))->f0 = D_001D4B30;
    D_0023B360_3A3128[r].f4 = a2;
    D_0023B360_3A3128[r].f8 = a3;
    *(volatile s32 *)&D_001D4B30 = D_001D4B30 + a2 * 16;
    return r;
}
