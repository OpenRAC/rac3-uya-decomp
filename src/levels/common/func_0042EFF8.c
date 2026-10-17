#include "common.h"

extern void func_0042EFF8(void);

typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_00395FF0[];
extern u8 D_001DFFA0_00395FF0;
extern s32 D_001D4CE8_g_00395FF0;
extern s32 D_001D4CE8_00395FF0;
extern volatile s32 D_001D4CEC_00395FF0;
extern s32 D_001DFF9C_g_00395FF0;
extern s32 D_001DFF9C;
extern void (*D_002E7428[])(void);
void func_0042EFF8(void) {
    S_395FF0 *s = D_00142430_00395FF0;
    s32 old;
    s32 v;
    if (s->f16C != 0 || (s->f8 == 2 && s->f10 != 0) || s->f24 > 0) {
        D_001DFFA0_00395FF0 = 1;
    }
    old = D_001D4CE8_g_00395FF0;
    v = D_001D4CEC_00395FF0;
    if (v & 0x80) {
        D_001D4CE8_00395FF0 = 0x18;
        D_001D4CEC_00395FF0 = (v & -129) | 0x40;
        v = D_001D4CEC_00395FF0;
    }
    if (v & 0x100) {
        D_001D4CE8_00395FF0 = 0x16;
        D_001D4CEC_00395FF0 = (v & -257) | 0x40;
    }
    D_002E7428[D_001D4CE8_00395FF0]();
    D_001DFF9C_g_00395FF0 = D_001DFF9C + 1;
    if (D_001D4CE8_00395FF0 != old) {
        D_001DFF9C = 0;
    }
}
