#include "common.h"

typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 f18; u8 p1A[2]; s32 f1C; s32 f20; u8 p24[0x138]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_142430_00396680;
extern S_142430_00396680 D_00142430;
extern s32 D_001D4CEC_g;
extern s32 D_001D4CEC[4] __attribute__((section(".sdata")));
extern s32 D_001D4CE8[4] __attribute__((section(".sdata")));
extern void (*D_001D759C)(void);
extern s32 D_001D7588;
void func_0042F688(void) {
    s32 c;
    s32 a;
    s32 u;
    s32 w;
    a = D_00142430.f15C;
    if (a == 2 && D_00142430.f164 < 0) {
        if (D_00142430.f16C != 0) {
            u = D_001D4CEC_g;
            c = 0x18; D_001D4CE8[0] = c; D_001D4CEC_g = u | 0x40;
            goto cb;
        }
        if (D_00142430.f8 != a) {
            D_001D4CE8[0] = 4;
        } else {
            a = D_00142430.f18;
            if (a == -2) {
                if (D_00142430.fC + D_00142430.f20 >= 0x258) {
                    u = D_001D4CEC[0];
                    c = 0x18; D_001D4CE8[0] = c; D_001D4CEC_g = u | 0x40;
                } else {
                    D_001D4CE8[0] = 0x15;
                }
            } else if (a < -1) {
            } else if (a != -1) {
                D_001D4CE8[0] = 0x12;
            } else {
                w = D_001D4CEC[0];
                if (w & 0x1000) {
                    s32 t = *(u16 *)&D_001D7588;
                    D_001D7588 = a;
                    D_00142430.f18 = t;
                    D_001D4CEC[0] = w & ~0x1000;
                }
                D_001D4CE8[0] = 0x12;
            }
        }
cb:
        if (D_001D759C != 0) {
            D_001D759C();
            D_001D759C = 0;
        }
    }
}
