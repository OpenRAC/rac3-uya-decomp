#include "common.h"
typedef struct {
    u8 pad[0x15F0];
    f32 f15F0;
    u8 pad15F4[0x16D4 - 0x15F4];
    f32 f16D4;
    s32 w16D8;
} G_4C7588;
extern G_4C7588 D_001A4BE0;
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(u32, u32, f32);
s32 func_004C7588(f32 a, f32 b) {
    G_4C7588 *g = &D_001A4BE0;
    f32 f;
    u32 c;
    s32 r;
    g->w16D8++;
    if (g->w16D8 > 20) {
        g->w16D8 = 20;
    }
    f = func_0040CEC8(g->f16D4, b * 0.017453292f * 0.016666668f);
    g->f16D4 = f;
    c = (g->w16D8 * 5) << 24;
    r = func_0040D020(c | 0xFF0F, c | 0xFFFFFF, func_0040C3E0(f) * 0.5f + 0.5f);
    if (a < g->f15F0) {
        r = 0x600000FF;
    }
    return r;
}
