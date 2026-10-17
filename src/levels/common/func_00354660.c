#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0x31 - 0x20];
    u8 b31;
    u8 pad32[0x6F - 0x32];
    u8 b6F;
} S_354660;

extern f32 D_001E2780[];
extern f32 func_004056F0(f32 *a0, f32 *a1);
extern void func_0043CE90(S_354660 *a0);

void func_00354660(S_354660 *a0) {
    if (a0->b31 != 0) {
        if (func_004056F0(D_001E2780, a0->v10) < 576.0f) {
            func_0043CE90(a0);
            a0->b6F = 22;
        }
    }
}
