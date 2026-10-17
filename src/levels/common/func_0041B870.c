#include "common.h"
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[288];
    s32 f128;
    u8 pad12C[68];
    s32 f170;
    u8 pad174[1632];
    u8 f7D4;
} S_41B870;
extern S_41B870 D_001A5E50;
extern u8 *D_002487DC;
extern s32 D_00240754;
extern void func_0014AD08(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 *t1);
void func_0041B870(u8 *a0, s32 a1) {
    s32 buf[2];
    S_41B870 *g = &D_001A5E50;
    s32 *p = *(s32 **)(a0 + 104);
    *p = g->f128 + a1;
    buf[0] = ((a0 - D_002487DC) >> 8) & 0xFF;
    buf[1] = *p;
    if (g->f170 == 0) {
        func_0014AD08(g->f7D4 | 0x40, g->f4, -1, D_00240754, 8, buf);
    }
}
