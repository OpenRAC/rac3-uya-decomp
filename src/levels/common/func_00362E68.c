#include "common.h"

typedef struct S_362E68c { u8 pad0[0x46]; u8 x46; } S_362E68c;
typedef struct S_362E68m {
    u8 pad0[0x10];
    f32 x10[4];
    u8 x20;
    u8 pad21[3];
    S_362E68c *x24;
    struct S_362E68m *x28;
} S_362E68m;

extern S_362E68m *D_001E00A8;
extern f32 D_0028E4B0[];
extern f32 func_0040BFB0(f32 *, f32 *);
extern f32 func_004408C0(f32, f32);
extern void func_002F8D80(S_362E68m *, f32, f32, s32, s32);

void func_00362E68(s32 a0) {
    S_362E68m *m;
    f32 *t;
    f32 x;

    for (m = D_001E00A8; m != 0; m = m->x28) {
        t = D_0028E4B0;
        if (func_0040BFB0(m->x10, t) < 2.5f
            || func_0040BFB0(m->x10, t - 12) < 1.7f
            || func_0040BFB0(m->x10, t - 20) < 1.4f
            || func_0040BFB0(m->x10, t - 28) < 1.2f) {
            if (m != 0 && m->x24 != 0 && m->x24->x46 == 19 && m->x20 == 3) {
                x = func_004408C0(-5.0f, 5.0f) * 0.017453292f;
                func_002F8D80(m, x, func_004408C0(0.0f, 5.0f) * 0.017453292f, a0, 1);
            }
        }
    }
}
