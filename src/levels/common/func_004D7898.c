#include "common.h"

u8 func_004D4548(void);
extern u32 D_001E009C;
extern u32 D_001E00A0;
extern void func_004397B0();

typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_001E6E00_003BBA50[];
extern u8 D_002513B8_003BBA50[];
extern u32 D_001E009C;
extern u32 D_001E00A0;
extern f32 D_001D98D0;
extern Q_3BBA50 *D_001E0EE8;
extern Q_3BBA50 *D_0023ACF0_003BBA50[];
extern void func_004397B0();
extern void func_004A7F50();
s32 func_004D7898(s32 a) {
    u32 p;
    s32 r;
    f32 f;
    Q_3BBA50 **pp;
    Q_3BBA50 *q;
    s32 i;
    Q_3BBA50 *g;
    r = 0;
    for (p = D_001E009C; p < D_001E00A0; p += 0x100) {
        func_004397B0(p);
    }
    D_002513B8_003BBA50[0x50] = func_004D4548();
    D_001E6E00_003BBA50->w54->b95 = 0xE8;
    D_001E6E00_003BBA50->w54->b62 = 0xFF;
    if (D_002513B8_003BBA50[0x51] != 0) {
        if (D_001E6E00_003BBA50->h40 - 0x50 < D_001E6E00_003BBA50->w34) {
            f = (f32)(D_001E6E00_003BBA50->h40 - D_001E6E00_003BBA50->w34 - 4) * 0.013157895f;
            if (f < 0.0f) f = 0.0f;
            D_001E6E00_003BBA50->w54->f2C = D_001E6E00_003BBA50->w54->w24->f24 * f;
            D_001D98D0 = f;
            g = *(Q_3BBA50 * volatile *)&D_001E0EE8;
            if (g != 0) {
                g->f2C = g->w24->f24 * f;
            }
            D_001E6E00_003BBA50->w54->b95 = (s32)(f * 232.0f);
            if (D_001E6E00_003BBA50->w54->hAA == 0xD54 && D_001E0EE8 == 0 && D_0023ACF0_003BBA50[0] != 0) {
                i = 0;
                do {
                    D_0023ACF0_003BBA50[i]->f2C = D_0023ACF0_003BBA50[i]->w24->f24 * f;
                    i++;
                } while (D_0023ACF0_003BBA50[i] != 0);
            }
        }
    }
    if (D_002513B8_003BBA50[0x50] != 0) {
        if (a != 0) r = D_002513B8_003BBA50[0x51] != 0;
    }
    func_004A7F50(D_001E6E00_003BBA50->w54, 1);
    return r;
}
