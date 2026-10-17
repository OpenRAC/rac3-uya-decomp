#include "common.h"

extern s32 func_005119A0();

typedef struct { u8 pad0[0x20]; s32 *slots[12]; } S_003E1460_inner;
typedef struct { u8 pad0[4]; S_003E1460_inner *f4; } S_003E1460_outer;

s32 func_005119A0(S_003E1460_outer *arg0, u32 arg1, s32 *arg2) {
    s32 **slot;

    if (arg1 < 12) {
        { s32 **b = arg0->f4->slots; slot = &b[arg1]; }
        if (*slot == 0 || (**slot ^ 4) != 0) {
            *slot = arg2;
            return 1;
        }
    }
    return 0;
}
