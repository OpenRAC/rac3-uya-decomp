#include "common.h"

typedef struct {
    u8 pad0[0x128];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x6AD - 0x174];
    u8 b6AD[0x7B0 - 0x6AD];
    s32 w7B0[1];
} S_645998;

typedef struct {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x2558 - 0x1A15];
    s32 *p2558;
} S_645998b;

extern S_645998 D_001A5E50[];

s32 func_00645998(S_645998b *a0) {
    S_645998 *s = D_001A5E50;
    s32 r = 0;
    if (s->w170 != 0) {
        return 1;
    }
    if (a0 != 0) {
        r = 1;
        if (a0->b1A14 == 0) {
            s32 d = s->w128 - s->w7B0[s->b6AD[*a0->p2558]];
            r = d < 151;
        }
    }
    return r;
}
