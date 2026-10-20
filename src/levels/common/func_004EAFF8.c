#include "common.h"
typedef struct {
    u8 pad0[152];
    u8 f98[264];
    f32 f1A0;
    u8 f1A4[4];
    f32 f1A8;
    u8 pad1AC[5380];
    s32 f16B0;
    u8 pad16B4[3893];
    u8 f25E9;
    u8 pad25EA[10];
    u8 f25F4;
} G_004EAFF8;
extern G_004EAFF8 D_001A4BE0;
extern s32 func_0045D358(s32, s32, s32, s32);
extern void func_004EAF40(f32, f32, f32, s32);
extern f32 func_004455F0(void *, void *, f32, f32, f32, f32, s32);
void func_004EAFF8(f32 x, f32 y, f32 z, s32 a) {
    G_004EAFF8 *g;
    G_004EAFF8 *h;
    h = &D_001A4BE0;
    if (h->f16B0 == 1) {
        if (h->f25E9 != 0 || func_0045D358(40, 2, 0, 0) != 0) {
            x *= 3.0f;
            z *= 3.0f;
        }
    }
    g = &D_001A4BE0;
    if (g->f25F4 != 0) {
        func_004EAF40(x, y, z, a);
    } else {
        g->f1A8 = func_004455F0(g->f98, g->f1A4, g->f1A0, x, y, z, a);
    }
}
