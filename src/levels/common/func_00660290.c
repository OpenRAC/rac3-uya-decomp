#include "common.h"

typedef struct {
    u32 lo : 13;
    u32 hi : 19;
    s32 w4;
    u8 pad8[0x4C - 0x8];
    s32 w4C;
} S_660290;

typedef struct {
    u8 pad0[0x128];
    s32 w128;
} S_660290b;

extern S_660290b D_001A5E50;

void func_00660290(S_660290 *a0, s32 a1, s32 a2) {
    s32 t = D_001A5E50.w128;
    a0->w4 = t;
    if (a2 > 0) {
        a0->hi = D_001A5E50.w128 + a1 + a2 - t;
    } else {
        a0->hi = 0;
    }
    a0->w4C = D_001A5E50.w128 + a1;
}
