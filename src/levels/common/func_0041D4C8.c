#include "common.h"

typedef struct {
    u8 pad0[0x40];
    s32 x40;
    s32 x44;
} D_002E79B0_t;
extern D_002E79B0_t D_002E79B0;

void func_0041D4C8(s32 a, s32 b) {
    D_002E79B0.x44 = b + 1;
    D_002E79B0.x40 = a;
}
