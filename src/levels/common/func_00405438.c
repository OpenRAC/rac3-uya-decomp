#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 w16;
    s32 w20;
    u8 pad1[4];
    s32 w28;
    u16 h32;
    u16 h34;
    u16 h36;
    u16 h38;
    u8 pad2[8];
} S405438;

extern S405438 D_001E6FE0[];
extern s32 D_001DFA7C;

s32 func_00405438(s32 idx, u16 a, u16 b, u16 c, u16 d, s32 e, s32 f) {
    S405438 *s;
    s32 i;

    if (idx < 0) {
        for (i = 0; i < 32; i++) {
            if (!(D_001E6FE0[i].w28 & 5)) {
                idx = i;
            }
        }
        if (idx < 0) {
            return -1;
        }
    }
    D_001DFA7C++;
    s = &D_001E6FE0[idx];
    s->h32 = a;
    s->h34 = b;
    s->h36 = c;
    s->h38 = d;
    s->w20 = e;
    s->w28 = 5;
    s->w16 = f;
    return idx;
}
